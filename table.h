#ifndef TABLE_H
#define TABLE_H

using namespace std;

class Table
{
    public:
        Table();
        Table(QString nom, int nbLigne, int pivot);
        Table(const Table &source);
        ~Table();

        Table& operator=(const Table& source);
        bool operator<(Table const& source) const;
        bool operator>(Table const& source) const;
        bool operator<=(Table const& source) const;
        bool operator>=(Table const& source) const;

        void setActif(const int &valeur);
        void setLigne(const int &valeur);
        void setColonne(const int &valeur);
        void setPivot(const int &valeur);
        void setNom(const QString &nom);
        void setListeChamp(const QList<Champ*> &liste);

        int getActif() const;
        int getLigne() const;
        int getColonne() const;
        int getPivot() const;
        int getNivTtmt() const;
        QString getNom() const;
        QList<Champ*> &getListeChamp();

        void nivTtmtDown();
        void colonnePlus();
        void ajouterChamp(Champ *nvChamp);
        static Table* findTable(QList<Table*> &liste, const QString &nomTable);

    private:
        static unsigned long compteur;
        int actif;
        int ligne;
        int colonne;
        int pivot;
        int nivTtmt;
        QString nom;
        QList<Champ*> listeChamp;
};

#endif // TABLE_H
