/********************************************************************************
** Form generated from reading UI file 'notepad.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
            notepad->setObjectName(QStringLiteral("notepad"));
        notepad->resize(530, 407);
        actionNew = new QAction(notepad);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imgs/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(notepad);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imgs/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave_as = new QAction(notepad);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/imgs/images/save_as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon2);
        actionPrint = new QAction(notepad);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/imgs/images/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon3);
        actionExit = new QAction(notepad);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/imgs/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon4);
        actionCopy = new QAction(notepad);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/imgs/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon5);
        actionPaste = new QAction(notepad);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/imgs/images/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon6);
        actionCut = new QAction(notepad);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/imgs/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon7);
        actionUndo = new QAction(notepad);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/imgs/images/edit_undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QStringLiteral(":/imgs/images/edit_undo.png"), QSize(), QIcon::Normal, QIcon::On);
        actionUndo->setIcon(icon8);
        actionRedo = new QAction(notepad);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/imgs/images/edit_redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon9);
        actionSave = new QAction(notepad);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/imgs/images/save.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave->setIcon(icon10);
        actionSelectFont = new QAction(notepad);
        actionSelectFont->setObjectName(QStringLiteral("actionSelectFont"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/font.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectFont->setIcon(icon11);
        actionsetFontItalic = new QAction(notepad);
        actionsetFontItalic->setObjectName(QStringLiteral("actionsetFontItalic"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsetFontItalic->setIcon(icon12);
        actionsetFontUnderline = new QAction(notepad);
        actionsetFontUnderline->setObjectName(QStringLiteral("actionsetFontUnderline"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/images/underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsetFontUnderline->setIcon(icon13);
        actionBold = new QAction(notepad);
        actionBold->setObjectName(QStringLiteral("actionBold"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBold->setIcon(icon14);
        centralwidget = new QWidget(notepad);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 511, 351));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        notepad->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(notepad);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        notepad->setStatusBar(statusbar);
        toolBar = new QToolBar(notepad);
        toolBar->setObjectName(QStringLiteral("toolBar"));
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
        notepad->setWindowTitle(QApplication::translate("notepad", "Notepad", Q_NULLPTR));
        actionNew->setText(QApplication::translate("notepad", "nouveau", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("notepad", "Ouvrir", Q_NULLPTR));
        actionSave_as->setText(QApplication::translate("notepad", "Sauvegarder sous", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSave_as->setToolTip(QApplication::translate("notepad", "Sauvegarder sous", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionPrint->setText(QApplication::translate("notepad", "Imprimer", Q_NULLPTR));
        actionExit->setText(QApplication::translate("notepad", "Exit", Q_NULLPTR));
        actionCopy->setText(QApplication::translate("notepad", "Copier", Q_NULLPTR));
        actionPaste->setText(QApplication::translate("notepad", "Coller", Q_NULLPTR));
        actionCut->setText(QApplication::translate("notepad", "Couper", Q_NULLPTR));
        actionUndo->setText(QApplication::translate("notepad", "Annuler", Q_NULLPTR));
        actionRedo->setText(QApplication::translate("notepad", "Retour", Q_NULLPTR));
        actionSave->setText(QApplication::translate("notepad", "Sauvegarder", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("notepad", "Sauvegarder", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionSelectFont->setText(QApplication::translate("notepad", "Police", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSelectFont->setToolTip(QApplication::translate("notepad", "Police", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionsetFontItalic->setText(QApplication::translate("notepad", "Italique", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionsetFontItalic->setToolTip(QApplication::translate("notepad", "Italique", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionsetFontUnderline->setText(QApplication::translate("notepad", "Souligner", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionsetFontUnderline->setToolTip(QApplication::translate("notepad", "Souligner", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionBold->setText(QApplication::translate("notepad", "Gras", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionBold->setToolTip(QApplication::translate("notepad", "Gras", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("notepad", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class notepad: public Ui_notepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
