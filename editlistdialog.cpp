#include "iostream"
#include "QTextStream"
#include <QFile>
#include <QMessageBox>
#include "editlistdialog.h"
#include "ui_editlistdialog.h"

EditListDialog::EditListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditListDialog), modeEdition(false)
{
    ui->setupUi(this);

    //QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
    //QObject::connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(findList(QString)));
}

EditListDialog::~EditListDialog()
{
    delete ui;
}

void EditListDialog::setMapListeFichier(QMap<QString,QStringList*> *mapListeFichier)
{
    this->mapListeFichier = mapListeFichier;
}

void EditListDialog::setList(QStringList *list)
{
    this->list = list;

    QString tempo;
    QTextStream stream(&tempo);
    bool firstIteration = true;

    for(QString ligne : *list)
    {
        if(firstIteration)
            firstIteration = false;
        else
            stream << endl;

        stream << ligne;
    }

    this->ui->plainTextEdit->setPlainText(tempo);
}

void EditListDialog::on_pushButton_clicked()
{
    int choix = 0;

    QFile fichier;
    fichier.setFileName("Liste\\" + this->ui->lineEdit->text() + ".liste");

    if(fichier.exists() && !modeEdition)
    {
        QMessageBox msgBox;
        msgBox.setText("Une liste du même nom existe déja.");
        msgBox.setInformativeText("Voulez vous la remplacer ?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        msgBox.setButtonText(QMessageBox::Yes, tr("Oui"));
        msgBox.setButtonText(QMessageBox::No, tr("Non"));
        choix = msgBox.exec();
    }

    if(choix == QMessageBox::Yes || !fichier.exists() || modeEdition)
    {
        QString plainTextEditContents = ui->plainTextEdit->toPlainText();
        (*this->list) = plainTextEditContents.split("\n");

        mapListeFichier->insert(this->ui->lineEdit->text() + ".liste", list);

        fichier.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream flux(&fichier);

        flux << plainTextEditContents;

        fichier.close();
        this->close();
    }
    else
    {
        fichier.close();
    }
}

void EditListDialog::findList(QString nomList)
{
    this->ui->plainTextEdit->clear();

    QStringList *list = mapListeFichier->value(nomList + ".liste");

    if(list != nullptr)
    {
        setList(list);
    }
}

void EditListDialog::hiddenLineEdit()
{
    this->ui->lineEdit->setDisabled(true);
}

void EditListDialog::setNomListe(const QString &nom)
{
    this->nomListe = nom;
    this->ui->lineEdit->setText(getNomListe());
}

void EditListDialog::setModeEdition(bool b)
{
    this->modeEdition = b;
}

QString EditListDialog::getNomListe()
{
    return nomListe;
}

bool EditListDialog::getModeEdition()
{
    return modeEdition;
}
