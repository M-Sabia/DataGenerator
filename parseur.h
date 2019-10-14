#ifndef PARSEUR_H
#define PARSEUR_H

using namespace std;

class Parseur
{
    public:
        Parseur();
        ~Parseur();

        void readDataFile();
        void removePonc(QString &phrase);
        int isATable(const QString &phrase);
        QString findTableName(const QString &phrase);
        QString findFieldName(const QString &phrase);
        QString findFieldType(const QString &phrase);
        int findFieldSize(const QString &phrase);
        void findPrimaryKey(const QString &ligne, QList<Table*> &listeTable);
        void findForeignKey(const QString &ligne, QList<Table*> &listeTable);
        int parsing(QString &nomFichier, QList<Table*> &listeTable);

    private:
        QRegularExpression createRgx;
        QRegularExpression tableOneRgx;
        QRegularExpression tableTwoRgx;
        QRegularExpression fieldRgx;
        QRegularExpression primaryKeyRgx;
        QRegularExpression foreignKeyRgx;
        QRegularExpression alterRgx;
        QString data;
};

#endif // PARSEUR_H
