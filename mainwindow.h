#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMap>
#include "element.h"
#include "champ.h"
#include "table.h"
#include "parseur.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void triPriorite(Table *tabOri = nullptr, Table *tabSec = nullptr);
    void ordonner();
    QVector<int> patternType(QList<Champ*> &liste);
    QString insertGenerator(Table *table);
    QString valuesGenerator(QList<Champ*> &liste, int const& ligne, const QVector<int> &listeType);
    void chargementFichier();
    bool verifGenValeur();
    void clearValGen();
    void findAndReplaceDuplicates();

public slots:
    void valMaxFromItem(QListWidgetItem *current);
    void openNewListDialog();
    void openEditListDialog();
    void openDeleteListDialog();
    void editList(const QString &nom);
    void deleteList(const QString &nom);

private slots:
    void on_bouton1_clicked();
    int on_bouton2_clicked();
    void on_bouton3_clicked();
    void on_bouton6_clicked();
    void on_listWidget1_clicked();
    void on_listWidget2_clicked();
    void on_listWidget3_clicked();
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private:
    Ui::MainWindow *ui;
    QMap<QString,QStringList*> mapListeFichier;
    QList<Table*> listeTable;
    QStringList nomFichier;
    Parseur parseur;
    Table *tabActu;
    Champ *champActu;
    bool valGen;

    const QRegularExpression valCharRgx;
    const QRegularExpression dateRgx;
};

#endif // MAINWINDOW_H
