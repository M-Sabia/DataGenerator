#include <QString>
#include <QList>
#include "element.h"
#include "champ.h"

using namespace std;

unsigned long Champ::compteur = 0;

Champ::Champ() : actif(1), typeDonnee(999), tailleChamp(0), valMaxSec(0)
{
    compteur++;
}

Champ::Champ(QString nom, QString typeChamp, QString nomTypeDonnee, int typeDonnee, int tailleChamp)
{
    actif = 1;
    this->nom = nom;
    this->typeChamp = typeChamp;
    this->nomTypeDonnee = nomTypeDonnee;
    this->typeDonnee = typeDonnee;
    this->tailleChamp = tailleChamp;
    this->valMaxSec = 0;
    compteur++;
}

Champ::Champ(const Champ &source)
{
    if(&source == this) return;

    actif = source.actif;
    nom = source.nom;
    typeChamp = source.typeChamp;
    typeDonnee = source.typeDonnee;
    nomTypeDonnee = source.nomTypeDonnee;
    tailleChamp = source.tailleChamp;
    valMaxSec = source.valMaxSec;
    tableCleSec = source.tableCleSec;
    listeElement = source.listeElement;
}

Champ::~Champ()
{
    compteur--;
    for(Element *elem : listeElement)
    {
        delete elem;
    }
}

Champ& Champ::operator=(const Champ& source)
{
    if(&source != this)
    {
        actif = source.actif;
        nom = source.nom;
        typeChamp = source.typeChamp;
        nomTypeDonnee = source.nomTypeDonnee;
        typeDonnee = source.typeDonnee;
        tailleChamp = source.tailleChamp;
        valMaxSec = source.valMaxSec;
        tableCleSec = source.tableCleSec;
        listeElement = source.listeElement;
    }

    return(*this);
}

bool Champ::operator==(const Champ& src) const
{
    return (this->nom == src.nom && this->typeChamp == src.typeChamp &&
    this->typeDonnee == src.typeDonnee && this->nomTypeDonnee == src.nomTypeDonnee &&
    this->tailleChamp == src.tailleChamp);
}

bool Champ::operator!=(const Champ& src) const
{
    return !(*this == src);
}

void Champ::setActif(const int &valeur)
{
    this->actif = valeur;
}

void Champ::setNom(const QString &nom)
{
    this->nom = nom;
}

void Champ::setTypeChamp(const QString &nom)
{
    this->typeChamp = nom;
}

void Champ::setNomTypeDonnee(const QString &nom)
{
    this->nomTypeDonnee = nom;
}

void Champ::setTypeDonnee(const int &valeur)
{
    this->typeDonnee = valeur;
}

void Champ::setTailleChamp(const int &valeur)
{
    this->tailleChamp = valeur;
}

void Champ::setValMaxSec(const int &valeur)
{
    valMaxSec = valeur;
}

void Champ::setTableCleSec(QString nom)
{
    tableCleSec = nom;
}

void Champ::setListeElement(const QList<Element*> &liste)
{
    this->listeElement = liste;
}

int Champ::getActif() const
{
    return actif;
}

QString Champ::getNom() const
{
    return nom;
}

QString Champ::getTypeChamp() const
{
    return typeChamp;
}

QString Champ::getNomTypeDonnee() const
{
    return nomTypeDonnee;
}

int Champ::getTypeDonnee() const
{
    return typeDonnee;
}

int Champ::getTailleChamp() const
{
    return tailleChamp;
}

int Champ::getValMaxSec() const
{
    return valMaxSec;
}

QString Champ::getTableCleSec() const
{
    return tableCleSec;
}

QList<Element*> &Champ::getListeElement()
{
    return listeElement;
}

void Champ::ajouterElement(Element *nvElem)
{
    listeElement.push_back(nvElem);
}

Champ* Champ::findChamp(QList<Champ*> &liste, QString nomChamp)
{
    for(Champ *champ : liste)
    {
        if(champ->getNom() == nomChamp)
        {
            return champ;
        }
    }

    return nullptr;
}
