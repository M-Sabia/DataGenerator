#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QListWidget>
#include <QList>
#include "element.h"
#include "champ.h"
#include "table.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogpivot.h"
#include "ui_dialogpivot.h"

DialogPivot::DialogPivot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPivot)
{
    ui->setupUi(this);

    QObject::connect(ui->bouton1, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->listWidget1, SIGNAL(itemClicked(QListWidgetItem*)), parent, SLOT(valMaxFromItem(QListWidgetItem*)));
}

DialogPivot::~DialogPivot()
{
    delete ui;
}

void DialogPivot::setListeTable(QList<Table*> *listeTable)
{
    this->listeTable = listeTable;
}

void DialogPivot::afficheListe()
{
    for(Table *table : *listeTable)
    {
        ui->listWidget1->addItem(table->getNom());
    }
}
