#include <QtWidgets>
#include <QProcess>
#include <math.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string>
#include "button.h"
#include "calculator.h"
#include <vector>
#include <stdexcept>

using namespace std;
double result = 0.0;

QString evaluate;
Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    /*!
     * \brief Intialisaation
     */


    display = new QLineEdit("");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignLeft);
    display->setMaxLength(100);

    display1 = new QLineEdit("");
    display1->setReadOnly(true);
    display1->setAlignment(Qt::AlignLeft);
    display1->setMaxLength(60);

    display2 = new QLineEdit("");
    display2->setReadOnly(true);
    display2->setAlignment(Qt::AlignLeft);
    display2->setMaxLength(100);

    QFont font = display->font();
    font.setPointSize(font.pointSize() +1);
    QFont font1 = display1->font();
    font1.setPointSize(font.pointSize() + 1);
    display->setFont(font);
    display1->setFont(font1);
    display2->setFont(font);

    for (int i = 0; i < NumDigitButtons; ++i)
    {
        digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));
    }
    /*!
     * \brief buttons for decimal
     */
    Button *pointButton = createButton(tr("."), SLOT(pointClicked()));


    /*!
     * \brief buttons for backspace, clear and clear all
     */
    Button *backspaceButton = createButton(tr("⌫"), SLOT(backspaceClicked()));
    Button *clearAllButton = createButton(tr("Tout effacer"), SLOT(clearAll()));

    /*!
     * \brief simple functions
     * 1) division
     * 2) times
     * 3) minus
     * 4) plus
     * 5) remainder
     */
    Button *divisionButton = createButton(tr("/"), SLOT(unaryOperatorClicked()));
    Button *timesButton = createButton(tr("*"), SLOT(unaryOperatorClicked()));
    Button *minusButton = createButton(tr("-"), SLOT(unaryOperatorClicked()));
    Button *plusButton = createButton(tr("+"), SLOT(unaryOperatorClicked()));
    Button *remainderButton = createButton(tr("%"), SLOT(unaryOperatorClicked()));

    /*!
     * \brief advance functions
     * 1) sqaureroot
     * 2) power

     */
    Button *squareRootButton = createButton(tr("√x"), SLOT(unaryOperatorClicked()));
    Button *powerButton = createButton(tr("x^y"), SLOT(unaryOperatorClicked()));


    /*!
     * \brief trignometric functions
     * 1) sin
     * 2) cos
     * 3) tan
     */
    Button *sinButton = createButton(tr("sin"), SLOT(unaryOperatorClicked()));
    Button *tanButton = createButton(tr("tan"), SLOT(unaryOperatorClicked()));
    Button *cosButton = createButton(tr("cos"), SLOT(unaryOperatorClicked()));
    Button *sinhButton = createButton(tr("sinh"), SLOT(unaryOperatorClicked()));
    Button *coshButton = createButton(tr("cosh"), SLOT(unaryOperatorClicked()));
    Button *tanhButton = createButton(tr("tanh"), SLOT(unaryOperatorClicked()));
    Button *arccosButton = createButton(tr("arccos"), SLOT(unaryOperatorClicked()));
    Button *arcsinButton = createButton(tr("arcsin"), SLOT(unaryOperatorClicked()));
    Button *arctanButton = createButton(tr("arctan"), SLOT(unaryOperatorClicked()));
    Button *racinecubiqueButton = createButton(tr("rc"), SLOT(unaryOperatorClicked()));
    Button *nButton = createButton(tr("OU"), SLOT(unaryOperatorClicked()));
    Button *etButton = createButton(tr("ET"), SLOT(unaryOperatorClicked()));

    Button *xorButton = createButton(tr("XOR"), SLOT(unaryOperatorClicked()));
    Button *norButton = createButton(tr("NOR"), SLOT(unaryOperatorClicked()));
    Button *notButton = createButton(tr("NOT"), SLOT(unaryOperatorClicked()));
    Button *nandButton = createButton(tr("NAND"), SLOT(unaryOperatorClicked()));
    Button *vabButton = createButton(tr("|-x|"), SLOT(unaryOperatorClicked()));

    /*!
     * \brief logrithmic
     * 1) log to the base 10
     * 2) log to base e
     */
    Button *logButton = createButton(tr("log2"), SLOT(unaryOperatorClicked()));
    Button *logpButton = createButton(tr("log10"), SLOT(unaryOperatorClicked()));

    Button *lnButton = createButton(tr("ln"), SLOT(unaryOperatorClicked()));

    /*!
     * \brief brackets
     */
    Button *rightbracketButton = createButton(tr(")"), SLOT(unaryOperatorClicked()));
    Button *leftbracketButton = createButton(tr("("), SLOT(unaryOperatorClicked()));

    /*!
     * \brief random functions
     */
    Button *exponentialButton = createButton(tr("e^x"), SLOT(unaryOperatorClicked()));
    Button *supButton = createButton(tr("<"), SLOT(unaryOperatorClicked()));
    Button *infButton = createButton(tr(">"), SLOT(unaryOperatorClicked()));

    /*!
     * \brief exit
     */
    QPushButton *quitButton = new QPushButton(tr("Valider"));

    /*!
     * \brief writeButton
     * convert digits to words
     */


    /*!
     * \brief geneBoutton
     */
    Button *a_Button = createButton(tr("Ga"), SLOT(unaryOperatorClicked()));
    Button *b_Button = createButton(tr("Gb"), SLOT(unaryOperatorClicked()));
    Button *c_Button = createButton(tr("Gc"), SLOT(unaryOperatorClicked()));
    Button *d_Button = createButton(tr("Gd"), SLOT(unaryOperatorClicked()));
    Button *w_Button = createButton(tr("Gw"), SLOT(unaryOperatorClicked()));
    Button *x_Button = createButton(tr("Gx"), SLOT(unaryOperatorClicked()));
    Button *y_Button = createButton(tr("Gy"), SLOT(unaryOperatorClicked()));
    Button *z_Button = createButton(tr("Gz"), SLOT(unaryOperatorClicked()));


    QGridLayout *mainLayout = new QGridLayout;
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
    mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
#else
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
#endif

    mainLayout->addWidget(display, 0, 0, 1, 15);
    mainLayout->addWidget(backspaceButton, 1, 0, 1, 3);
    mainLayout->addWidget(clearAllButton, 1, 3, 1, 3);
    mainLayout->addWidget(quitButton, 1, 11, 1, 1);
    QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(valide()));

    /*!
     * Display the numbers
     */
    for (int i = 1; i < NumDigitButtons; ++i)
    {
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 1;
        mainLayout->addWidget(digitButtons[i], row, column);
    }

    /*!
     * Display of all the funtions on calculator gui
     */

    mainLayout->addWidget(squareRootButton, 2, 0);
    mainLayout->addWidget(powerButton, 3, 0);
    mainLayout->addWidget(rightbracketButton, 4, 0);
    mainLayout->addWidget(leftbracketButton, 5, 0);


    mainLayout->addWidget(digitButtons[0], 5, 1);
    mainLayout->addWidget(pointButton, 5, 2);
    mainLayout->addWidget(remainderButton, 5, 3);

    mainLayout->addWidget(a_Button, 2, 4);
    mainLayout->addWidget(b_Button, 3, 4);
    mainLayout->addWidget(c_Button, 4, 4);
    mainLayout->addWidget(d_Button, 5, 4);



    mainLayout->addWidget(w_Button, 2, 5);
    mainLayout->addWidget(x_Button, 3, 5);
    mainLayout->addWidget(y_Button, 4, 5);
    mainLayout->addWidget(z_Button, 5, 5);

    mainLayout->addWidget(exponentialButton, 1, 6);
    mainLayout->addWidget(divisionButton, 2, 6);
    mainLayout->addWidget(timesButton, 3, 6);
    mainLayout->addWidget(minusButton, 4, 6);
    mainLayout->addWidget(plusButton, 5, 6);

    mainLayout->addWidget(tanButton, 4, 7);
    mainLayout->addWidget(sinButton, 2, 7);
    mainLayout->addWidget(cosButton, 3, 7);
    mainLayout->addWidget(logButton, 5, 7);
    mainLayout->addWidget(lnButton, 1, 7);

    mainLayout->addWidget(etButton, 1, 8);
    mainLayout->addWidget(sinhButton, 2, 8);
    mainLayout->addWidget(coshButton, 3, 8);
    mainLayout->addWidget(tanhButton, 4, 8);
    mainLayout->addWidget(logpButton, 5, 8);

    mainLayout->addWidget(nButton, 1, 9);
    mainLayout->addWidget(arcsinButton, 2, 9);
    mainLayout->addWidget(arccosButton, 3, 9);
    mainLayout->addWidget(arctanButton, 4, 9);
    mainLayout->addWidget(vabButton, 5, 9);


    mainLayout->addWidget(racinecubiqueButton, 1, 10);
    mainLayout->addWidget(norButton, 2, 10);
    mainLayout->addWidget(xorButton, 3, 10);
    mainLayout->addWidget(notButton, 4, 10);
    mainLayout->addWidget(nandButton, 5, 10);


    mainLayout->addWidget(supButton, 2,11);
    mainLayout->addWidget(infButton, 3,11);







    setLayout(mainLayout);

    setWindowTitle(tr("Clavier Visuel"));

    //this->setStyleSheet("background-color: blue;");



}

/*
 * impression
 */
void Calculator::digitClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    int digitValue = clickedButton->text().toInt();
    if (display->text() == "0" && digitValue == 0.0)
        return;
    display->setText(display->text() + QString::number(digitValue));
    evaluate=evaluate+QString::number(digitValue);
}

/*
 * contiens toutes les operations
 */
void Calculator::unaryOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();

    QString tempx ;
    QString tempy ;
    QString tempi = display->text();


    if (clickedOperator == tr("√x"))
    {
        tempx = "fa(";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("x^y"))
    {
        tempx = "^";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("Ga"))
    {
        tempx = "a";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("Gb"))
    {
        tempx = "b";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("Gc"))
    {
        tempx = "c";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("Gd"))
    {
        tempx = "d";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("Gw"))
    {
        tempx = "w";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("Gx"))
    {
        tempx = "x";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("Gy"))
    {
        tempx = "y";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("Gz"))
    {
        tempx = "z";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("sin"))
    {
        tempx = "fsin(";
        display->setText(tempi+tempx);
        tempy= "s";
        evaluate = evaluate+tempy;
    }
    else if (clickedOperator == tr("sinh"))
    {
        tempx = "fsinh(";
        display->setText(tempi+tempx);
        tempy= "s";
        evaluate = evaluate+tempy;
    }
    else if (clickedOperator == tr("cosh"))
        {
            tempx = "fcosh(";
            display->setText(tempi+tempx);
            tempy= "s";
            evaluate = evaluate+tempy;
        }
    else if (clickedOperator == tr("arccos"))
        {
            tempx = "farccos(";
            display->setText(tempi+tempx);
            tempy= "s";
            evaluate = evaluate+tempy;
        }
    else if (clickedOperator == tr("arcsin"))
        {
            tempx = "farcsin(";
            display->setText(tempi+tempx);
            tempy= "s";
            evaluate = evaluate+tempy;
        }
    else if (clickedOperator == tr("arctan"))
        {
            tempx = "farctan(";
            display->setText(tempi+tempx);
            tempy= "s";
            evaluate = evaluate+tempy;
        }
    else if (clickedOperator == tr("cos"))
    {
        tempx = "fcos(";
        display->setText(tempi+tempx);
        tempy = "c";
        evaluate = evaluate+tempy;
    }
    else if (clickedOperator == tr("tan"))
    {
        tempx = "ftan(";
        display->setText(tempi+tempx);
        tempy = "t";
        evaluate = evaluate+tempy;
    }
    else if (clickedOperator == tr("tanh"))
    {
        tempx = "ftanh(";
        display->setText(tempi+tempx);
        tempy = "t";
        evaluate = evaluate+tempy;
    }
    else if (clickedOperator == tr("e^x"))
    {
        tempx = "fe(";
        display->setText(tempi+tempx);
        tempy = "e";
        evaluate = evaluate+tempy;
    }
    else if (clickedOperator == tr("ln"))
    {
        tempx = "fln(";
        display->setText(tempi+tempx);
        tempy="l";
        evaluate = evaluate+tempy;
    }
    else if (clickedOperator == tr("log2"))
    {
        tempx = "flog(";
        display->setText(tempi+tempx);
        tempy="1/l(10)*l";
        evaluate = evaluate+tempy;
    }
    else if (clickedOperator == tr("log10"))
    {
        tempx = "flogx(";
        display->setText(tempi+tempx);
        tempy="1/l(10)*l";
        evaluate = evaluate+tempy;
    }
    else if (clickedOperator == tr("+"))
    {
        tempx = "+";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("-"))
    {
        tempx = "-";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("*"))
    {
        tempx = "*";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("/"))
    {
        tempx = "/";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("%"))
    {
        tempx = "%";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("("))
    {
        tempx = "(";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr(")"))
    {
        tempx = ")";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("<"))
    {
        tempx = "<(";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr(">"))
    {
        tempx = ">(";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("rc"))
    {
        tempx = "frc(";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("XOR"))
    {
        tempx = "fx|";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("NOT"))
    {
        tempx = "f~";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("NAND"))
    {
        tempx = "f~&";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("NOR"))
    {
        tempx = "f~|";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("OU"))
    {
        tempx = "|";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("ET"))
    {
        tempx = "&";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }
    else if (clickedOperator == tr("|-x|"))
    {
        tempx = "fav";
        display->setText(tempi+tempx);
        evaluate = evaluate+tempx;
    }


    waitingForOperand = true;
}





/*!
 * \brief Calculator::pointClicked
 * include a decimal
 */
void Calculator::pointClicked()
{
    display->setText(display->text() + tr("."));
    evaluate=evaluate+".";

}

/*!
 * \brief Calculator::backspaceClicked
 * delete a digit or operation that is printed on screen ( similar to backspace )
 */
void Calculator::backspaceClicked()
{
    QString text = display->text();
    text.chop(1);
    if (text.isEmpty())
    {
        text = "0";
        waitingForOperand = true;
    }
    display->setText(text);
    evaluate.chop(1);
}

/*!
 * \brief Calculator::clearAll
 * clear everything and every data
 */
void Calculator::clearAll()
{
    display->setText("");
    display1->setText("");
    display2->setText("");
    waitingForOperand = true;
    result =0;
    evaluate ="";
}

/*!
 * \brief Calculator::createButton
 * \param text
 * \param member
 * create the button
 */
Button *Calculator::createButton(const QString &text, const char *member)
{
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

/*!
 * \brief Calculator::abortOperation
 * abort operation
 */
void Calculator::abortOperation()
{
    clearAll();
    display->setText(tr("####"));
}

/*!
 * \brief Calculator::quit
 * quit button in calculator
 */
void Calculator::valide()
{
    QMessageBox messageBox;
    messageBox.setWindowTitle(tr("Clavier visuel"));
    messageBox.setText(tr("Voulez vous valider  ?"));
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);
    if (messageBox.exec() == QMessageBox::Yes)
        this->close();
}

void Calculator::equalClicked()
{

}

void Calculator::writeClicked()
{

}

QString Calculator::getEvaluation()
{
    return display->text();
}
    
