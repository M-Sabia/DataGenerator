/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewList;
    QAction *actionUpdateList;
    QAction *actionDeleteList;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *bouton1;
    QPushButton *bouton6;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget1;
    QListWidget *listWidget2;
    QListWidget *listWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit1;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *bouton2;
    QPushButton *bouton3;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(450, 400);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:#fff;"));
        MainWindow->setTabShape(QTabWidget::Triangular);
        actionNewList = new QAction(MainWindow);
        actionNewList->setObjectName(QString::fromUtf8("actionNewList"));
        actionUpdateList = new QAction(MainWindow);
        actionUpdateList->setObjectName(QString::fromUtf8("actionUpdateList"));
        actionDeleteList = new QAction(MainWindow);
        actionDeleteList->setObjectName(QString::fromUtf8("actionDeleteList"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 0);
        bouton1 = new QPushButton(centralWidget);
        bouton1->setObjectName(QString::fromUtf8("bouton1"));
        bouton1->setMinimumSize(QSize(300, 0));
        bouton1->setAutoFillBackground(false);
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

        horizontalLayout_4->addWidget(bouton1);

        bouton6 = new QPushButton(centralWidget);
        bouton6->setObjectName(QString::fromUtf8("bouton6"));
        bouton6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_4->addWidget(bouton6);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        listWidget1 = new QListWidget(centralWidget);
        listWidget1->setObjectName(QString::fromUtf8("listWidget1"));
        listWidget1->setStyleSheet(QString::fromUtf8("background-color:#fff;\n"
"border:1px solid #ccc;"));

        horizontalLayout_2->addWidget(listWidget1);

        listWidget2 = new QListWidget(centralWidget);
        listWidget2->setObjectName(QString::fromUtf8("listWidget2"));
        listWidget2->setStyleSheet(QString::fromUtf8("background-color:#fff;\n"
"border:1px solid #ccc;"));

        horizontalLayout_2->addWidget(listWidget2);

        listWidget3 = new QListWidget(centralWidget);
        listWidget3->setObjectName(QString::fromUtf8("listWidget3"));
        listWidget3->setStyleSheet(QString::fromUtf8("background-color:#fff;\n"
"border:1px solid #ccc;"));

        horizontalLayout_2->addWidget(listWidget3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        lineEdit1 = new QLineEdit(centralWidget);
        lineEdit1->setObjectName(QString::fromUtf8("lineEdit1"));
        lineEdit1->setMinimumSize(QSize(0, 22));

        horizontalLayout_3->addWidget(lineEdit1);

        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(100, 22));
        comboBox->setStyleSheet(QString::fromUtf8("background-color:#fff;\n"
"border:1px solid #ccc;"));

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        bouton2 = new QPushButton(centralWidget);
        bouton2->setObjectName(QString::fromUtf8("bouton2"));
        bouton2->setMinimumSize(QSize(0, 0));
        bouton2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(bouton2);

        bouton3 = new QPushButton(centralWidget);
        bouton3->setObjectName(QString::fromUtf8("bouton3"));
        bouton3->setMinimumSize(QSize(0, 0));
        bouton3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(bouton3);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 450, 21));
        menuBar->setStyleSheet(QString::fromUtf8("QMenuBar {\n"
"color: white;\n"
"font-size: 12px;\n"
"font-weight: 400;\n"
"background: #34495e;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"color: white;\n"
"font-size: 12px;\n"
"font-weight: 400;\n"
"background: #34495e;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"background: #1C2E40;\n"
"color: white;\n"
"}"));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuMenu->setStyleSheet(QString::fromUtf8("QMenu {\n"
"color: white;\n"
"font-size: 12px;\n"
"font-weight: 400;\n"
"background: #34495e;\n"
"}\n"
"\n"
"QMenu::item {\n"
"color: white;\n"
"font-size: 12px;\n"
"font-weight: 400;\n"
"background: #34495e;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"background: #1C2E40;\n"
"color: white;\n"
"}"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setEnabled(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setEnabled(false);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionNewList);
        menuMenu->addAction(actionUpdateList);
        menuMenu->addAction(actionDeleteList);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DataGenerator", nullptr));
        actionNewList->setText(QApplication::translate("MainWindow", "Cr\303\251er une liste...", nullptr));
        actionUpdateList->setText(QApplication::translate("MainWindow", "Modifier une liste...", nullptr));
        actionDeleteList->setText(QApplication::translate("MainWindow", "Supprimer une liste...", nullptr));
        bouton1->setText(QApplication::translate("MainWindow", "Ouvrir un fichier...", nullptr));
        bouton6->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        lineEdit1->setPlaceholderText(QApplication::translate("MainWindow", "Nombre de ligne", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "Oracle", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "MySQL", nullptr));

        bouton2->setText(QApplication::translate("MainWindow", "G\303\251n\303\251rer les valeurs al\303\251atoires", nullptr));
        bouton3->setText(QApplication::translate("MainWindow", "Sauvegarder le fichier SQL", nullptr));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
