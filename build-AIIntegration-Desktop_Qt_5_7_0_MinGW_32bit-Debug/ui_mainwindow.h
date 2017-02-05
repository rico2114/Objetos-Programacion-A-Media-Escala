/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *textEdit_2;
    QLabel *label_5;
    QTextEdit *textEdit_3;
    QLabel *label_6;
    QTextEdit *textEdit_4;
    QLabel *label_7;
    QTextEdit *textEdit_5;
    QLabel *label_8;
    QTextEdit *textEdit_6;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QTextEdit *textEdit_7;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(742, 510);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 90, 141, 51));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(230, 50, 281, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 10, 311, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 150, 171, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(310, 180, 121, 16));
        QFont font;
        font.setFamily(QStringLiteral("Sitka Text"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 220, 121, 16));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(130, 220, 71, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 260, 201, 16));
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(210, 260, 41, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 300, 201, 16));
        textEdit_4 = new QTextEdit(centralWidget);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(210, 300, 41, 20));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 340, 211, 16));
        textEdit_5 = new QTextEdit(centralWidget);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(220, 340, 51, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 380, 131, 16));
        textEdit_6 = new QTextEdit(centralWidget);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));
        textEdit_6->setGeometry(QRect(140, 380, 131, 20));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 420, 71, 31));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(476, 220, 71, 20));
        textEdit_7 = new QTextEdit(centralWidget);
        textEdit_7->setObjectName(QStringLiteral("textEdit_7"));
        textEdit_7->setGeometry(QRect(540, 220, 131, 21));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(560, 260, 71, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 742, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Reconocer imagen", 0));
        label->setText(QApplication::translate("MainWindow", "Ingrese la direccion de la imagen que desea intentar reconocer:", 0));
        label_2->setText(QApplication::translate("MainWindow", "                     Empty", 0));
        label_3->setText(QApplication::translate("MainWindow", "Entrenamiento", 0));
        label_4->setText(QApplication::translate("MainWindow", "Cantidad de iteraciones: ", 0));
        label_5->setText(QApplication::translate("MainWindow", "Digite el numero inicial de entrenamiento:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Digite el numero final de entrenamiento: ", 0));
        label_7->setText(QApplication::translate("MainWindow", "Digite la cantidad de muestras a entrenar:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Digite el archivo de salida: ", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Entrenar", 0));
        label_9->setText(QApplication::translate("MainWindow", "Cargar red:", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Cargar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
