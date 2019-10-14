#include "choicelistdialog.h"
#include "ui_choicelistdialog.h"

ChoiceListDialog::ChoiceListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoiceListDialog)
{
    ui->setupUi(this);
}

ChoiceListDialog::~ChoiceListDialog()
{
    delete ui;
}

void ChoiceListDialog::setMapListeFichier(QMap<QString,QStringList*> *mapListeFichier)
{
    this->mapListeFichier = mapListeFichier;

    for(QString nom : mapListeFichier->keys())
    {
        ui->listWidget->addItem(nom.left(nom.indexOf('.',0)));
    }
}

void ChoiceListDialog::on_pushButton_clicked()
{
    emit nomList(ui->listWidget->currentItem()->text());
    this->close();
}
