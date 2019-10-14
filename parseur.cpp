#include <QString>
#include <QTextStream>
#include <QList>
#include <QFile>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDebug>
#include "element.h"
#include "champ.h"
#include "table.h"
#include "parseur.h"

using namespace std;

Parseur::Parseur()
{
    readDataFile();

    createRgx.setPattern("(CREATE\\s{1,}TABLE)+\\s{1,}");
    tableOneRgx.setPattern("CREATE\\s{1,}TABLE\\s{1,}(IF\\s{1,}NOT\\s{1,}EXISTS\\s{1,})*([A-zÀ-ÿ0-9\"`|A-zÀ-ÿ0-9\"`\\.]+)");
    tableTwoRgx.setPattern("\"[A-zÀ-ÿ0-9]+\"\\.\"([A-zÀ-ÿ0-9]+)\"");
    fieldRgx.setPattern("([A-zÀ-ÿ0-9\"`]+)\\s{1,}(" + data + ")+(\\W|$)+");
    primaryKeyRgx.setPattern("PRIMARY\\s{1,}KEY\\s{1,}\\(+([`\"]*\\w+[`\"]*)+\\)");
    foreignKeyRgx.setPattern("FOREIGN\\s{1,}KEY\\s{1,}\\(+([`\"]*\\w+[`\"]*)+\\)\\s{1,}REFERENCES\\s{1,}([`\"]*\\w+[`\"]*)+\\s{0,}\\(+([`\"]*\\w+[`\"]*)+\\)");
    alterRgx.setPattern("ALTER\\s{1,}TABLE\\s{1,}\\(*([`\"]*\\w+[`\"]*)+\\)*");
}

Parseur::~Parseur()
{
}

void Parseur::readDataFile()
{
    QFile fichier("Data\\DataTypes.data");
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);

    while(!flux.atEnd())
    {
        data += flux.readLine();
    }
}

void Parseur::removePonc(QString &phrase)
{
    if(phrase.contains("\""))
        phrase.remove(QChar('"'));
    else if(phrase.contains("`"))
        phrase.remove(QChar('`'));
}

int Parseur::isATable(const QString &phrase)
{
    return phrase.contains(createRgx);
}

QString Parseur::findTableName(const QString &phrase)
{
    QRegularExpressionMatch matchOne;
    QRegularExpressionMatch matchTwo;
    QString nomTable;

    matchOne = tableOneRgx.match(phrase,0);

    if(matchOne.hasMatch())
    {
        matchTwo = tableTwoRgx.match(matchOne.captured(2));

        if(matchTwo.hasMatch())
        {
            nomTable = matchTwo.captured(1);
        }
        else
        {
            nomTable = matchOne.captured(2);
        }

        removePonc(nomTable);
    }

    return nomTable;
}

QString Parseur::findFieldName(const QString &phrase)
{
    QRegularExpressionMatch match;
    QString nomChamp;

    match = fieldRgx.match(phrase,0);

    if(match.hasMatch())
    {
        nomChamp = match.captured(1);
        removePonc(nomChamp);
    }

    return nomChamp;
}

QString Parseur::findFieldType(const QString &phrase)
{
    QRegularExpressionMatch match;
    QString type;

    match = fieldRgx.match(phrase,0);

    if(match.hasMatch())
    {
        type = match.captured(2);
    }

    //qDebug() << type;

    return type;
}

int Parseur::findFieldSize(const QString &phrase)
{
    QString nombreTexte;
    int debut = 0;
    int fin = 0;

    debut = phrase.lastIndexOf('(',-1);
    fin = phrase.lastIndexOf(')',-1);

    for(int i = debut+1 ; i <= fin-1 ; i++)
    {
        nombreTexte.push_back(phrase[i]);
    }

    return nombreTexte.toInt();
}

void Parseur::findPrimaryKey(const QString &ligne, QList<Table*> &listeTable)
{
    if(primaryKeyRgx.match(ligne,0).hasMatch())
    {
        QString nomTable = findTableName(ligne);
        QString primaryKey = primaryKeyRgx.match(ligne,0).captured(1);

        removePonc(nomTable);
        removePonc(primaryKey);

        for(Table *tab : listeTable)
        {
            if(tab->getNom() == nomTable)
            {
                for(Champ *champ : tab->getListeChamp())
                {
                    if(champ->getNom() == primaryKey)
                    {
                        champ->setTypeDonnee(0);
                        champ->setNomTypeDonnee("Cle primaire");
                    }
                }
            }
        }

        qDebug() << nomTable << " " << primaryKey;
    }
}

void Parseur::findForeignKey(const QString &ligne, QList<Table*> &listeTable)
{
    if(foreignKeyRgx.match(ligne,0).hasMatch())
    {
        QString nomTable;
        QString tableCleSec;
        QString foreignKey;
        QRegularExpressionMatchIterator it = foreignKeyRgx.globalMatch(ligne,0);

        if(alterRgx.match(ligne,0).hasMatch())
        {
            nomTable = alterRgx.match(ligne,0).captured(1);
        }
        else
        {
            nomTable = findTableName(ligne);
        }

        removePonc(nomTable);

        while(it.hasNext())
        {
            QRegularExpressionMatch match = it.next();
            tableCleSec = match.captured(2);
            foreignKey = match.captured(3);

            removePonc(foreignKey);

            for(Table *tab : listeTable)
            {
                if(tab->getNom() == nomTable)
                {
                    for(Champ *champ : tab->getListeChamp())
                    {
                        if(champ->getNom() == foreignKey)
                        {
                            champ->setTypeDonnee(1);
                            champ->setNomTypeDonnee("Cle secondaire");
                            champ->setTableCleSec(tableCleSec);
                        }
                    }
                }
            }

            qDebug() << nomTable << " -> " << tableCleSec << "(" << foreignKey << ")";
        }
    }
}

int Parseur::parsing(QString &nomFichier, QList<Table*> &listeTable)
{
    QFile fichier(nomFichier);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    QString ligne;

    while(!flux.atEnd())
    {
        ligne += flux.read(1);

        if(ligne[ligne.size()-1] == ";")
        {
            if(isATable(ligne))
            {
                Table *nvTab = new Table();
                nvTab->setNom(findTableName(ligne));

                QRegularExpressionMatchIterator it = fieldRgx.globalMatch(ligne);

                while(it.hasNext())
                {
                    QRegularExpressionMatch match = it.next();

                    if(match.hasMatch())
                    {
                        Champ *nvChamp = new Champ();

                        nvChamp->setNom(findFieldName(match.captured(0)));
                        nvChamp->setTypeChamp(findFieldType(match.captured(0)));
                        nvChamp->setTailleChamp(findFieldSize(match.captured(0)));

                        nvTab->colonnePlus();
                        nvTab->ajouterChamp(nvChamp);
                    }
                }

                listeTable.push_back(nvTab);
            }

            findPrimaryKey(ligne, listeTable);
            findForeignKey(ligne, listeTable);

            ligne = "";
        }
    }

    fichier.close();
    return 1;
}
