/********************************************************************************
** Form generated from reading UI file 'dialogpivot.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPIVOT_H
#define UI_DIALOGPIVOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogPivot
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget1;
    QPushButton *bouton1;

    void setupUi(QDialog *DialogPivot)
    {
        if (DialogPivot->objectName().isEmpty())
            DialogPivot->setObjectName(QString::fromUtf8("DialogPivot"));
        DialogPivot->resize(222, 210);
        verticalLayout = new QVBoxLayout(DialogPivot);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(DialogPivot);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        font.setUnderline(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        listWidget1 = new QListWidget(DialogPivot);
        listWidget1->setObjectName(QString::fromUtf8("listWidget1"));
        listWidget1->setStyleSheet(QString::fromUtf8("background-color:#fff;\n"
"border:1px solid #ccc;"));

        verticalLayout->addWidget(listWidget1);

        bouton1 = new QPushButton(DialogPivot);
        bouton1->setObjectName(QString::fromUtf8("bouton1"));
        bouton1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout->addWidget(bouton1);


        retranslateUi(DialogPivot);

        QMetaObject::connectSlotsByName(DialogPivot);
    } // setupUi

    void retranslateUi(QDialog *DialogPivot)
    {
        DialogPivot->setWindowTitle(QApplication::translate("DialogPivot", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogPivot", "Choisissez une table pour la cl\303\251 secondaire", nullptr));
        bouton1->setText(QApplication::translate("DialogPivot", "Valider!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogPivot: public Ui_DialogPivot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPIVOT_H
