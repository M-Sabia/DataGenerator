#include <QString>
#include <QList>
#include <QDebug>
#include "element.h"
#include "aleatoire.h"

using namespace std;

unsigned long Element::compteur = 0;

Element::Element() : actif(1), texte("null")
{
    compteur++;
}

Element::Element(QString nom) : actif(1), texte(nom)
{
    compteur++;
}

Element::Element(const Element &source)
{
    if(&source == this) return;

    actif = source.actif;
    texte = source.texte;
}

Element::~Element()
{
    compteur--;
}

Element& Element::operator=(const Element& source)
{
    if(&source != this)
    {
        actif = source.actif;
        texte = source.texte;
    }

    return(*this);
}

int Element::getActif() const
{
    return actif;
}

QString Element::getTexte() const
{
    return texte;
}

void Element::remplirElement(const int &typeDonnee, const int &id, const int &valMaxSec, const QStringList *contenuFichier)
{
    switch(typeDonnee)
    {
        //Cle primaire
        case 0:
            texte.sprintf("%d", id+1);
        break;
        //Cle secondaire
        case 1:
            texte.sprintf("%d", (rand() % valMaxSec)+1);
        break;
        //Neant
        case 2:

        break;
        //Aleatoire
        default:
            aleatoire(texte, contenuFichier);
        break;
    }
}
