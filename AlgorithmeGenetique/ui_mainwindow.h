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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QToolButton *toolButton_Sauvgarder;
    QToolButton *toolButton_Charger;
    QToolButton *toolButton_Aide;
    QPushButton *pushButton_Lancer;
    QLabel *label;
    QSpinBox *spinBox;
    QSpinBox *spinBox_3;
    QComboBox *comboBox;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QSpinBox *spinBox_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QSpinBox *spinBox_4;
    QLabel *label_10;
    QSpinBox *spinBox_5;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(693, 470);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        toolButton_Sauvgarder = new QToolButton(centralWidget);
        toolButton_Sauvgarder->setObjectName(QString::fromUtf8("toolButton_Sauvgarder"));
        toolButton_Sauvgarder->setGeometry(QRect(40, 0, 111, 21));
        toolButton_Charger = new QToolButton(centralWidget);
        toolButton_Charger->setObjectName(QString::fromUtf8("toolButton_Charger"));
        toolButton_Charger->setGeometry(QRect(260, 0, 101, 21));
        toolButton_Aide = new QToolButton(centralWidget);
        toolButton_Aide->setObjectName(QString::fromUtf8("toolButton_Aide"));
        toolButton_Aide->setGeometry(QRect(430, 0, 71, 21));
        pushButton_Lancer = new QPushButton(centralWidget);
        pushButton_Lancer->setObjectName(QString::fromUtf8("pushButton_Lancer"));
        pushButton_Lancer->setGeometry(QRect(610, 420, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 40, 211, 21));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(130, 140, 42, 22));
        spinBox_3 = new QSpinBox(centralWidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(540, 130, 42, 22));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(130, 260, 91, 31));
        doubleSpinBox = new QDoubleSpinBox(centralWidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(320, 210, 62, 22));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(16, 140, 81, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 140, 71, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(420, 140, 101, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 260, 91, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 210, 101, 16));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(300, 140, 69, 22));
        spinBox_2 = new QSpinBox(centralWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(540, 150, 42, 22));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(590, 130, 47, 13));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(590, 150, 47, 13));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 210, 111, 16));
        spinBox_4 = new QSpinBox(centralWidget);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(130, 210, 42, 22));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(420, 210, 111, 16));
        spinBox_5 = new QSpinBox(centralWidget);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setGeometry(QRect(540, 210, 42, 22));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        toolButton_Sauvgarder->setText(QApplication::translate("MainWindow", "Sauvgarder", nullptr));
        toolButton_Charger->setText(QApplication::translate("MainWindow", "Charger", nullptr));
        toolButton_Aide->setText(QApplication::translate("MainWindow", "Aide", nullptr));
        pushButton_Lancer->setText(QApplication::translate("MainWindow", "Lancer ", nullptr));
        label->setText(QApplication::translate("MainWindow", "      MODELISATION DE PROBLEME", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "Selection 1", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Selection 2", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "Selection 3", nullptr));

        label_2->setText(QApplication::translate("MainWindow", "Nombre de gene", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Type de gene", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Interval des genes", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Type de selection", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Taux de croisement ", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("MainWindow", "Entier", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("MainWindow", "Real", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("MainWindow", "Booleen", nullptr));

        label_7->setText(QApplication::translate("MainWindow", "Minimum", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Maximum", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Taille de la population", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Taux de mutation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
