#include <ctime>
#include <QString>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QDebug>

using namespace std;

void aleatoire(QString &mot, const int &type, const QString &nomFichier)
{
    QString ligne;
    static int oldType = 0;
    static int nbMots = 0;
    int nbAleatoire = 0;

    QFile fichier("Liste\\" + nomFichier);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);

    if(type != oldType)
    {
        nbMots = 0;

        while(!flux.atEnd())
        {
            ligne = flux.readLine();
            nbMots++;
        }

        oldType = type;
    }

    nbAleatoire = (qrand() % nbMots)+1;

    flux.flush();
    flux.seek(0);

    for(int i = 0 ; i < nbAleatoire ; i++)
    {
        ligne = flux.readLine();
    }

    mot = ligne;

    fichier.close();
}

void aleatoire(QString &mot, const QStringList *listeFichier)
{
    int nbAleatoire = (qrand() % listeFichier->size());
    mot = (*listeFichier)[nbAleatoire];
}
