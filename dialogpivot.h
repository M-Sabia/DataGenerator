#ifndef DIALOGPIVOT_H
#define DIALOGPIVOT_H

#include <QDialog>
#include "element.h"
#include "champ.h"
#include "table.h"

using namespace std;

namespace Ui {
class DialogPivot;
}

class DialogPivot : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPivot(QWidget *parent = 0);
    ~DialogPivot();

    void setListeTable(QList<Table*> *listeTable);

    void afficheListe();

private:
    Ui::DialogPivot *ui;
    QList<Table*> *listeTable;
};

#endif // DIALOGPIVOT_H
