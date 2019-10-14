/********************************************************************************
** Form generated from reading UI file 'choicelistdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOICELISTDIALOG_H
#define UI_CHOICELISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChoiceListDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *ChoiceListDialog)
    {
        if (ChoiceListDialog->objectName().isEmpty())
            ChoiceListDialog->setObjectName(QString::fromUtf8("ChoiceListDialog"));
        ChoiceListDialog->resize(200, 300);
        verticalLayoutWidget = new QWidget(ChoiceListDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 181, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(verticalLayoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

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

        verticalLayout->addWidget(pushButton);


        retranslateUi(ChoiceListDialog);

        QMetaObject::connectSlotsByName(ChoiceListDialog);
    } // setupUi

    void retranslateUi(QDialog *ChoiceListDialog)
    {
        ChoiceListDialog->setWindowTitle(QApplication::translate("ChoiceListDialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("ChoiceListDialog", "Valider!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChoiceListDialog: public Ui_ChoiceListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOICELISTDIALOG_H
