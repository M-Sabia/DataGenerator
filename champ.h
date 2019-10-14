#ifndef CHAMP_H
#define CHAMP_H

using namespace std;

class Champ
{
    public:
        Champ();
        Champ(QString nom, QString typeChamp, QString nomTypeDonnee, int typeDonnee, int tailleChamp);
        Champ(const Champ &source);
        ~Champ();

        Champ& operator=(const Champ& source);
        bool operator==(const Champ& src) const;
        bool operator!=(const Champ& src) const;

        void setActif(const int &valeur);
        void setNom(const QString &nom);
        void setTypeChamp(const QString &nom);
        void setNomTypeDonnee(const QString &nom);
        void setTypeDonnee(const int &valeur);
        void setTailleChamp(const int &valeur);
        void setValMaxSec(const int &valeur);
        void setTableCleSec(QString nom);
        void setListeElement(const QList<Element*> &liste);

        int getActif() const;
        QString getNom() const;
        QString getTypeChamp() const;
        QString getNomTypeDonnee() const;
        int getTypeDonnee() const;
        int getTailleChamp() const;
        int getValMaxSec() const;
        QString getTableCleSec() const;
        QList<Element*> &getListeElement();

        void ajouterElement(Element *nvElem);
        static Champ* findChamp(QList<Champ*> &liste, QString nomChamp);

    private:
        static unsigned long compteur;
        int actif;
        QString nom;
        QString typeChamp;
        QString nomTypeDonnee;
        int typeDonnee;
        int tailleChamp;
        int valMaxSec;
        QString tableCleSec;
        QList<Element*> listeElement;
};

#endif // CHAMP_H
