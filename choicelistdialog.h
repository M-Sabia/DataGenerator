#ifndef CHOICELISTDIALOG_H
#define CHOICELISTDIALOG_H

#include <QDialog>

namespace Ui {
class ChoiceListDialog;
}

class ChoiceListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChoiceListDialog(QWidget *parent = 0);
    ~ChoiceListDialog();

    void setMapListeFichier(QMap<QString, QStringList *> *mapListeFichier);

private slots:
    void on_pushButton_clicked();

signals:
    void nomList(QString nom);

private:
    Ui::ChoiceListDialog *ui;
    QMap<QString,QStringList*> *mapListeFichier;
};

#endif // CHOICELISTDIALOG_H
