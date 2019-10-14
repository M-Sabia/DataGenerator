#include <iterator>
#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QListWidget>
#include <QList>
#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QSet>
#include "element.h"
#include "champ.h"
#include "table.h"
#include "parseur.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogpivot.h"
#include "editlistdialog.h"
#include "choicelistdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    valCharRgx("CHARACTER VARYING|CHARACTER|CHAR|TEXT|VARCHAR2|VARCHAR"),
    dateRgx("(\\d{2})/(\\d{2})/(\\d{4})")
{
    ui->setupUi(this);
    //ui->menuBar->hide();
    ui->statusBar->hide();
    ui->mainToolBar->hide();
    tabActu = nullptr;
    champActu = nullptr;
    setAcceptDrops(true);
    valGen = false;

    QDir dir("Liste");

    if(dir.isReadable())
    {
        QFileInfoList files = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);
        foreach (QFileInfo file, files){ nomFichier << file.fileName(); }

        chargementFichier();
    }
    else
    {
        QMessageBox::warning(this, "Vérification...", "Le dossier \"Liste\" est introuvable");
        exit(EXIT_FAILURE);
    }

    QObject::connect(ui->actionNewList, SIGNAL(triggered(bool)), this, SLOT(openNewListDialog()));
    QObject::connect(ui->actionUpdateList, SIGNAL(triggered(bool)), this, SLOT(openEditListDialog()));
    QObject::connect(ui->actionDeleteList, SIGNAL(triggered(bool)), this, SLOT(openDeleteListDialog()));
}

MainWindow::~MainWindow()
{
    for(Table *tab : listeTable) {delete tab;}

    for(QString nom : mapListeFichier.keys())
    {
        delete mapListeFichier.value(nom);
        mapListeFichier.remove(nom);
    }

    delete ui;
}

void MainWindow::triPriorite(Table *tabOri, Table *tabSec)
{
    if(tabSec == nullptr)
    {
        for(Table* table : listeTable)
        {
            for(Champ* champ : table->getListeChamp())
            {
                if(champ->getTypeDonnee() == 1)
                {
                    table->nivTtmtDown();
                    tabSec = Table::findTable(listeTable, champ->getTableCleSec());

                    if(tabSec != table)
                        triPriorite(table, tabSec);
                }
            }
        }
    }
    else
    {
        for(Champ* champ : tabSec->getListeChamp())
        {
            if(champ->getTypeDonnee() == 1)
            {
                tabOri->nivTtmtDown();
                tabSec = Table::findTable(listeTable, champ->getTableCleSec());

                if(tabSec != tabOri)
                    triPriorite(tabOri, tabSec);
            }
        }
    }
}

void MainWindow::ordonner()
{
    QList<Table*>::iterator itTab;
    QList<Table*>::iterator itTab2;

    for(itTab = listeTable.begin() ; itTab != listeTable.end() ; ++itTab)
    {
        for(itTab2 = itTab ; itTab2 != listeTable.end() ; ++itTab2)
        {
            if((**itTab) > (**itTab2))
            {
                listeTable.swap(distance(listeTable.begin(), itTab), distance(listeTable.begin(), itTab2));
                itTab = listeTable.begin();
            }
        }
    }
}

QVector<int> MainWindow::patternType(QList<Champ*> &liste)
{
    QString txt;
    QVector<int> listeType;

    for(Champ *champ : liste)
    {
        if(champ->getTypeChamp().toUpper().contains(valCharRgx))
        {
            txt = champ->getListeElement().at(0)->getTexte();

            if(txt != "null")
            {
                listeType.push_back(1);
            }
        }
        else if(champ->getTypeChamp().toUpper() == "DATE")
        {
            if(ui->comboBox->currentText() == "Oracle")
            {
                listeType.push_back(2);
            }
            else if(ui->comboBox->currentText() == "MySQL")
            {
                listeType.push_back(3);
            }
        }
        else
        {
            listeType.push_back(0);
        }
    }

    return listeType;
}

QString MainWindow::insertGenerator(Table *table)
{
    QString tempo;
    QTextStream stream(&tempo);

    stream << "insert into " << table->getNom() << "(";

    for(Champ* champ : table->getListeChamp())
    {
        if(champ == table->getListeChamp().back())
            stream << champ->getNom() << ")" << endl;
        else
            stream << champ->getNom() << ",";
    }

    return tempo;
}

QString MainWindow::valuesGenerator(QList<Champ*> &liste, int const& ligne, const QVector<int> &listeType)
{
    int i = 0;
    QString txt;
    QString tempo;
    QTextStream stream(&tempo);

    stream << "values(";

    for(Champ *champ : liste)
    {
        txt = champ->getListeElement().at(ligne)->getTexte();

        switch(listeType[i])
        {
            case 0:
                stream << txt;
            break;

            case 1:
                stream << "'" << txt << "'";
            break;

            case 2:
                stream << "to_date('" << txt << "','DD/MM/YYYY')";
            break;

            case 3:
                QRegularExpressionMatch matchOne = dateRgx.match(txt,0);
                stream << "'" << matchOne.captured(3) << "-" << matchOne.captured(2) << "-" << matchOne.captured(1) << "'";
            break;
        }

        if(champ != liste.back())
            stream << ",";

        i++;
    }

    stream << ");" << endl;

    return tempo;
}

void MainWindow::chargementFichier()
{
    QFile fichier;

    for(int i = 0 ; i < nomFichier.size() ; ++i)
    {
        fichier.setFileName("Liste\\" + nomFichier[i]);
        fichier.open(QIODevice::ReadOnly | QIODevice::Text);

        QTextStream flux(&fichier);

        QStringList *stringList = new QStringList();

        while(!flux.atEnd())
        {
            stringList->push_back(flux.readLine());
        }

        mapListeFichier.insert(nomFichier[i], stringList);

        fichier.close();
    }
}

bool MainWindow::verifGenValeur()
{
    for(Table *tab : listeTable)
    {
        for(Champ *champ : tab->getListeChamp())
        {
            if(champ->getTypeDonnee() == 999)
            {
                return false;
            }
        }
    }

    return true;
}

void MainWindow::clearValGen()
{
    for(Table *table : listeTable)
    {
        for(Champ *champ : table->getListeChamp())
        {
            if(champ->getListeElement().size() != 0)
            {
                for(Element *elem : champ->getListeElement())
                {
                    delete elem;
                }

                champ->getListeElement().clear();
            }
        }
    }
}

void MainWindow::valMaxFromItem(QListWidgetItem *current)
{
    QString nomTable = current->text();

    champActu->setTableCleSec(nomTable);
}

void MainWindow::openNewListDialog()
{
    QStringList *newList = new QStringList();

    EditListDialog *editDialog = new EditListDialog(this);
    editDialog->setMapListeFichier(&mapListeFichier);
    editDialog->setList(newList);
    editDialog->exec();

    if(listeTable.count() != 0)
        on_listWidget2_clicked();
}

void MainWindow::openEditListDialog()
{
    ChoiceListDialog *choiceDialog = new ChoiceListDialog(this);

    QObject::connect(choiceDialog, SIGNAL(nomList(QString)), this, SLOT(editList(QString)));

    choiceDialog->setMapListeFichier(&mapListeFichier);
    choiceDialog->exec();
}

void MainWindow::editList(const QString &nom)
{
    QStringList *list = mapListeFichier.value(nom + ".liste");

    EditListDialog *editDialog = new EditListDialog(this);
    editDialog->setMapListeFichier(&mapListeFichier);
    editDialog->setList(list);
    editDialog->setNomListe(nom);
    editDialog->hiddenLineEdit();
    editDialog->setModeEdition(true);
    editDialog->exec();
}

void MainWindow::openDeleteListDialog()
{
    if(this->listeTable.count() == 0)
    {
        ChoiceListDialog *choiceDialog = new ChoiceListDialog(this);

        QObject::connect(choiceDialog, SIGNAL(nomList(QString)), this, SLOT(deleteList(QString)));

        choiceDialog->setMapListeFichier(&mapListeFichier);
        choiceDialog->exec();
    }
    else
    {
        QMessageBox::information(this, "Suppression impossible", "Impossible de supprimer une liste lorsque des tables sont chargées");
    }
}

void MainWindow::deleteList(const QString &nom)
{
    QStringList *list = mapListeFichier.value(nom + ".liste");

    if(list != nullptr)
    {
        delete list;
        mapListeFichier.remove(nom + ".liste");
        QFile::remove("Liste\\" + nom + ".liste");
    }

    if(listeTable.count() != 0)
        on_listWidget2_clicked();
}

void MainWindow::findAndReplaceDuplicates()
{
    QSet<QString> set;
    QString strTemp;
    QStringList *contenuFichier = nullptr;
    QList<Element*>::iterator itElem;
    bool checkPrimaryKey = false;
    int nombreLigne = ui->lineEdit1->text().toInt();

    for(Table *table : listeTable)
    {
        for(Champ *champ : table->getListeChamp())
        {
            if(champ->getTypeDonnee() == 0)
                checkPrimaryKey = true;
        }

        if(checkPrimaryKey == false)
        {
            for(int i = 0 ; i < nombreLigne ; ++i)
            {
                for(Champ *champ : table->getListeChamp())
                {
                    if(champ->getTypeDonnee() == 1)
                    {
                        itElem = champ->getListeElement().begin();
                        advance(itElem,i);

                        strTemp += (*itElem)->getTexte();
                    }
                }

                while(set.contains(strTemp))
                {
                    strTemp.clear();

                    for(Champ *champ : table->getListeChamp())
                    {
                        contenuFichier = mapListeFichier.value(champ->getNomTypeDonnee() + ".liste");

                        if(champ->getTypeDonnee() == 1)
                        {
                            itElem = champ->getListeElement().begin();
                            advance(itElem,i);

                            (*itElem)->remplirElement(champ->getTypeDonnee(), i, nombreLigne, contenuFichier);
                            strTemp += (*itElem)->getTexte();
                        }
                    }
                }

                set.insert(strTemp);
                strTemp.clear();
            }
        }

        checkPrimaryKey = false;
    }
}

void MainWindow::on_bouton1_clicked()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "SQL (*.sql)");

    ui->listWidget1->clear();

    parseur.parsing(fichier, listeTable);

    for(Table *table : listeTable)
    {
        ui->listWidget1->addItem(table->getNom());
    }
}

int MainWindow::on_bouton2_clicked()
{
    QStringList *contenuFichier = nullptr;

    int nombreLigne = ui->lineEdit1->text().toInt();

    if(listeTable.size() == 0)
    {
        QMessageBox::information(this, "Aucune table", "Aucune table à remplir !");
    }
    else if(nombreLigne == 0)
    {
        QMessageBox::warning(this, "Taille de la table...", "Choisissez une taille pour toutes les tables.");
        return 1;
    }
    else if(verifGenValeur())
    {
        clearValGen();
        triPriorite();
        ordonner();

        for(Table *table : listeTable)
        {
            //qDebug() << table->getNom() << table->getNivTtmt();

            for(Champ *champ : table->getListeChamp())
            {
                contenuFichier = mapListeFichier.value(champ->getNomTypeDonnee() + ".liste");

                for(int i = 0 ; i < nombreLigne ; ++i)
                {
                    Element *nvElem = new Element();

                    nvElem->remplirElement(champ->getTypeDonnee(), i, nombreLigne, contenuFichier);

                    champ->ajouterElement(nvElem);
                }
            }
        }

        findAndReplaceDuplicates();
        valGen = true;

        QMessageBox::information(this, "Génération aléatoire", "Travail terminé !");
    }
    else
    {
        QMessageBox::information(this, "Champ incomplet", "Tous les champs ne sont pas remplis !");
    }

    return 0;
}

void MainWindow::on_bouton3_clicked()
{
    QVector<int> listeType;

    if(valGen == true)
    {
        int nombreLigne = ui->lineEdit1->text().toInt();

        QList<Champ*> listeChamp;
        QString insertString;

        QString nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "SQL files (*.sql)");
        QFile fichier(nomFichier);

        fichier.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream flux(&fichier);

        for(Table *table : listeTable)
        {
            listeChamp = table->getListeChamp();
            insertString = insertGenerator(table);
            listeType = patternType(listeChamp);

            for(int i = 0 ; i < nombreLigne ; ++i)
            {
                flux << insertString;
                flux << valuesGenerator(listeChamp,i,listeType);
            }

            flux << endl;
        }

        fichier.close();
        QMessageBox::information(this, "Enregistrement", "Enregistrement terminé !");
    }
    else
    {
        QMessageBox::information(this, "Génération incomplète", "Veuillez d'abord généré des valeurs aléatoires !");
    }
}

void MainWindow::on_bouton6_clicked()
{
    tabActu = nullptr;
    champActu = nullptr;

    for(Table *table : listeTable)
    {
        delete table;
    }

    listeTable.clear();

    ui->listWidget1->clear();
    ui->listWidget2->clear();
    ui->listWidget3->clear();

    ui->lineEdit1->clear();

    valGen = false;
}

void MainWindow::on_listWidget1_clicked()
{
    QString nomTable = ui->listWidget1->currentItem()->text();
    Table *tabActu = Table::findTable(listeTable,nomTable);

    ui->listWidget2->clear();
    ui->listWidget3->clear();

    for(Champ *champ : tabActu->getListeChamp())
    {
        ui->listWidget2->addItem(champ->getNom());
    }

    this->tabActu = tabActu;
}

void MainWindow::on_listWidget2_clicked()
{
    ui->listWidget3->clear();
    ui->listWidget3->addItem("Cle primaire");
    ui->listWidget3->addItem("Cle secondaire");
    ui->listWidget3->addItem("Neant");

    for(QString nom : mapListeFichier.keys())
    {
        ui->listWidget3->addItem(nom.left(nom.indexOf('.',0)));
    }

    this->champActu = Champ::findChamp(tabActu->getListeChamp(), ui->listWidget2->currentItem()->text());

    if(this->champActu != nullptr)
    {
        if(this->champActu->getTypeDonnee() != 999)
        {
            for(int i = 0 ; i < ui->listWidget3->count() ; ++i)
            {
                if(ui->listWidget3->item(i)->text() == champActu->getNomTypeDonnee())
                {
                    ui->listWidget3->item(i)->setSelected(true);
                    ui->listWidget3->setFocus();
                }
            }
        }
    }
}

void MainWindow::on_listWidget3_clicked()
{
    champActu->setTypeDonnee(ui->listWidget3->currentRow());
    champActu->setNomTypeDonnee(ui->listWidget3->currentItem()->text());

    /*
    if(ui->listWidget3->currentRow() == 1)
    {
        DialogPivot *diaPivot = new DialogPivot(this);
        diaPivot->setListeTable(&listeTable);
        diaPivot->afficheListe();
        diaPivot->exec();
    }
    */
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->text().contains(QRegularExpression(".SQL|.sql")))
        event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QString fichier = QUrl(event->mimeData()->text()).toLocalFile();

    ui->listWidget1->clear();

    parseur.parsing(fichier, listeTable);

    for(Table *table : listeTable)
    {
        ui->listWidget1->addItem(table->getNom());
    }
}
