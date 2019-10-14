#ifndef EDITLISTDIALOG_H
#define EDITLISTDIALOG_H

#include <QDialog>

namespace Ui {
class EditListDialog;
}

class EditListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditListDialog(QWidget *parent = 0);
    ~EditListDialog();

    void setMapListeFichier(QMap<QString, QStringList *> *mapListeFichier);
    void setList(QStringList *list);

    void setNomListe(const QString &nom);
    void setModeEdition(bool b);
    QString getNomListe();
    bool getModeEdition();
    void hiddenLineEdit();

private slots:
    void on_pushButton_clicked();
    void findList(QString nomList);

private:
    Ui::EditListDialog *ui;
    QString nomListe;
    QMap<QString,QStringList*> *mapListeFichier;
    QStringList *list;
    bool modeEdition;
};

#endif // EDITLISTDIALOG_H
