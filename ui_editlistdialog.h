/********************************************************************************
** Form generated from reading UI file 'editlistdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITLISTDIALOG_H
#define UI_EDITLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditListDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QComboBox *comboBox;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *EditListDialog)
    {
        if (EditListDialog->objectName().isEmpty())
            EditListDialog->setObjectName(QString::fromUtf8("EditListDialog"));
        EditListDialog->resize(400, 500);
        EditListDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 239, 239);"));
        verticalLayoutWidget = new QWidget(EditListDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 381, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: #FFF;"));

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(100, 0));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: #FFF;"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        plainTextEdit = new QPlainTextEdit(verticalLayoutWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: #FFF;"));

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"padding:4px;\n"
"border:solid;\n"
"color: white;\n"
"font-size: 12px;\n"
"font-weight: 400;\n"
"background: #34495e;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background: #2D3F51;\n"
"color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: #1C2E40;\n"
"color: white;\n"
"}"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"padding:4px;\n"
"border:solid;\n"
"color: white;\n"
"font-size: 12px;\n"
"font-weight: 400;\n"
"background: #34495e;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background: #2D3F51;\n"
"color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: #1C2E40;\n"
"color: white;\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(EditListDialog);

        QMetaObject::connectSlotsByName(EditListDialog);
    } // setupUi

    void retranslateUi(QDialog *EditListDialog)
    {
        EditListDialog->setWindowTitle(QApplication::translate("EditListDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("EditListDialog", "Nom de la liste : ", nullptr));
        label_2->setText(QApplication::translate("EditListDialog", "Type de liste :", nullptr));
        comboBox->setItemText(0, QApplication::translate("EditListDialog", "Alphanum\303\251rique", nullptr));
        comboBox->setItemText(1, QApplication::translate("EditListDialog", "Num\303\251rique", nullptr));
        comboBox->setItemText(2, QApplication::translate("EditListDialog", "Date", nullptr));
        comboBox->setItemText(3, QApplication::translate("EditListDialog", "Autre", nullptr));

        pushButton->setText(QApplication::translate("EditListDialog", "Enregistrer", nullptr));
        pushButton_2->setText(QApplication::translate("EditListDialog", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditListDialog: public Ui_EditListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITLISTDIALOG_H
