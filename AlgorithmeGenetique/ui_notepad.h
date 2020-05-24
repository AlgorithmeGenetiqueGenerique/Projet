/********************************************************************************
** Form generated from reading UI file 'notepad.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_notepad
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave_as;
    QAction *actionPrint;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionSave;
    QAction *actionSelectFont;
    QAction *actionsetFontItalic;
    QAction *actionsetFontUnderline;
    QAction *actionBold;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *notepad)
    {
        if (notepad->objectName().isEmpty())
            notepad->setObjectName(QString::fromUtf8("notepad"));
        notepad->resize(530, 407);
        actionNew = new QAction(notepad);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(notepad);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave_as = new QAction(notepad);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgs/images/save_as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon2);
        actionPrint = new QAction(notepad);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imgs/images/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon3);
        actionExit = new QAction(notepad);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imgs/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon4);
        actionCopy = new QAction(notepad);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imgs/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon5);
        actionPaste = new QAction(notepad);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/imgs/images/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon6);
        actionCut = new QAction(notepad);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/imgs/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon7);
        actionUndo = new QAction(notepad);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/imgs/images/edit_undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/imgs/images/edit_undo.png"), QSize(), QIcon::Normal, QIcon::On);
        actionUndo->setIcon(icon8);
        actionRedo = new QAction(notepad);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/imgs/images/edit_redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon9);
        actionSave = new QAction(notepad);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/imgs/images/save.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave->setIcon(icon10);
        actionSelectFont = new QAction(notepad);
        actionSelectFont->setObjectName(QString::fromUtf8("actionSelectFont"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/font.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectFont->setIcon(icon11);
        actionsetFontItalic = new QAction(notepad);
        actionsetFontItalic->setObjectName(QString::fromUtf8("actionsetFontItalic"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsetFontItalic->setIcon(icon12);
        actionsetFontUnderline = new QAction(notepad);
        actionsetFontUnderline->setObjectName(QString::fromUtf8("actionsetFontUnderline"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsetFontUnderline->setIcon(icon13);
        actionBold = new QAction(notepad);
        actionBold->setObjectName(QString::fromUtf8("actionBold"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBold->setIcon(icon14);
        centralwidget = new QWidget(notepad);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 511, 351));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        notepad->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(notepad);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        notepad->setStatusBar(statusbar);
        toolBar = new QToolBar(notepad);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        notepad->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSelectFont);
        toolBar->addAction(actionsetFontUnderline);
        toolBar->addAction(actionBold);
        toolBar->addAction(actionsetFontItalic);
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionCut);
        toolBar->addAction(actionPaste);
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionSave_as);
        toolBar->addAction(actionPrint);
        toolBar->addAction(actionExit);

        retranslateUi(notepad);

        QMetaObject::connectSlotsByName(notepad);
    } // setupUi

    void retranslateUi(QMainWindow *notepad)
    {
        notepad->setWindowTitle(QApplication::translate("notepad", "Notepad", nullptr));
        actionNew->setText(QApplication::translate("notepad", "nouveau", nullptr));
        actionOpen->setText(QApplication::translate("notepad", "Ouvrir", nullptr));
        actionSave_as->setText(QApplication::translate("notepad", "Sauvegarder sous", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave_as->setToolTip(QApplication::translate("notepad", "Sauvegarder sous", nullptr));
#endif // QT_NO_TOOLTIP
        actionPrint->setText(QApplication::translate("notepad", "Imprimer", nullptr));
        actionExit->setText(QApplication::translate("notepad", "Exit", nullptr));
        actionCopy->setText(QApplication::translate("notepad", "Copier", nullptr));
        actionPaste->setText(QApplication::translate("notepad", "Coller", nullptr));
        actionCut->setText(QApplication::translate("notepad", "Couper", nullptr));
        actionUndo->setText(QApplication::translate("notepad", "Annuler", nullptr));
        actionRedo->setText(QApplication::translate("notepad", "Retour", nullptr));
        actionSave->setText(QApplication::translate("notepad", "Sauvegarder", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("notepad", "Sauvegarder", nullptr));
#endif // QT_NO_TOOLTIP
        actionSelectFont->setText(QApplication::translate("notepad", "Police", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSelectFont->setToolTip(QApplication::translate("notepad", "Police", nullptr));
#endif // QT_NO_TOOLTIP
        actionsetFontItalic->setText(QApplication::translate("notepad", "Italique", nullptr));
#ifndef QT_NO_TOOLTIP
        actionsetFontItalic->setToolTip(QApplication::translate("notepad", "Italique", nullptr));
#endif // QT_NO_TOOLTIP
        actionsetFontUnderline->setText(QApplication::translate("notepad", "Souligner", nullptr));
#ifndef QT_NO_TOOLTIP
        actionsetFontUnderline->setToolTip(QApplication::translate("notepad", "Souligner", nullptr));
#endif // QT_NO_TOOLTIP
        actionBold->setText(QApplication::translate("notepad", "Gras", nullptr));
#ifndef QT_NO_TOOLTIP
        actionBold->setToolTip(QApplication::translate("notepad", "Gras", nullptr));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("notepad", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class notepad: public Ui_notepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
