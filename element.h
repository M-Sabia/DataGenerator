#ifndef ELEMENT_H
#define ELEMENT_H

using namespace std;

class Element
{
    public:
        Element();
        explicit Element(QString nom);
        Element(const Element &source);
        ~Element();

        Element& operator=(const Element& source);

        int getActif() const;
        QString getTexte() const;

        void remplirElement(const int &typeDonnee, const int &id, const int &valMaxSec, const QStringList *contenuFichier);

    private:
        static unsigned long compteur;
        int actif;
        QString texte;
};

#endif // ELEMENT_H
