#include <QString>
#include <QList>
#include <QDebug>
#include "element.h"
#include "champ.h"
#include "table.h"

using namespace std;

unsigned long Table::compteur = 0;

Table::Table() : actif(1), ligne(0), colonne(0), pivot(0), nivTtmt(0)
{
    compteur++;
}

Table::Table(QString nom, int nbLigne, int pivot)
{
    actif = 1;
    colonne = 0;
    nivTtmt = 0;
    this->pivot = pivot;
    this->nom = nom;
    this->ligne = nbLigne;
    compteur++;
}

Table::Table(const Table &source)
{
    if(&source == this) return;

    actif = source.actif;
    ligne = source.ligne;
    colonne = source.colonne;
    pivot = source.pivot;
    nom = source.nom;
    nivTtmt = source.nivTtmt;
    listeChamp = source.listeChamp;
}

Table::~Table()
{
    compteur--;
    for(Champ *champ : listeChamp)
    {
        delete champ;
    }
}

Table& Table::operator=(const Table& source)
{
    if(&source != this)
    {
        actif = source.actif;
        ligne = source.ligne;
        colonne = source.colonne;
        pivot = source.pivot;
        nom = source.nom;
        nivTtmt = source.nivTtmt;
        listeChamp = source.listeChamp;
    }

    return(*this);
}

bool Table::operator<(Table const& source) const
{
    return (this->nivTtmt < source.nivTtmt);
}

bool Table::operator>(Table const& source) const
{
    return (this->nivTtmt > source.nivTtmt);
}

bool Table::operator<=(Table const& source) const
{
    return (this->nivTtmt < source.nivTtmt || this->nivTtmt == source.nivTtmt);
}

bool Table::operator>=(Table const& source) const
{
    return (this->nivTtmt > source.nivTtmt || this->nivTtmt == source.nivTtmt);
}

void Table::setActif(const int &valeur)
{
    this->actif = valeur;
}

void Table::setLigne(const int &valeur)
{
    this->ligne = valeur;
}

void Table::setColonne(const int &valeur)
{
    this->colonne = valeur;
}

void Table::setPivot(const int &valeur)
{
    this->pivot = valeur;
}

void Table::setNom(const QString &nom)
{
    this->nom = nom;
}

void Table::setListeChamp(const QList<Champ*> &liste)
{
    this->listeChamp = liste;
}

int Table::getActif() const
{
    return actif;
}

int Table::getLigne() const
{
    return ligne;
}

int Table::getColonne() const
{
    return colonne;
}

int Table::getPivot() const
{
    return pivot;
}

int Table::getNivTtmt() const
{
    return nivTtmt;
}

QString Table::getNom() const
{
    return nom;
}

QList<Champ*> &Table::getListeChamp()
{
    return listeChamp;
}

void Table::nivTtmtDown()
{
    nivTtmt++;
}

void Table::colonnePlus()
{
    colonne++;
}

void Table::ajouterChamp(Champ *nvChamp)
{
    listeChamp.push_back(nvChamp);
}

Table* Table::findTable(QList<Table*> &liste, const QString &nomTable)
{
    for(Table *table : liste)
    {
        if(table->getNom() == nomTable)
        {
            return table;
        }
    }

    return nullptr;
}
