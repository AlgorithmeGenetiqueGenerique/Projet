#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include <QWidget>
using namespace std;

class QLineEdit;

class Button;

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent);
    QString getEvaluation();

private slots:
    void digitClicked();
    void valide();
    void unaryOperatorClicked();
    void equalClicked();
    void writeClicked();
    void pointClicked();
    void backspaceClicked();
    void clearAll();



private:
    Button *createButton(const QString &text, const char *member);
    void abortOperation();

    QString pendingAdditiveOperator;
    QString pendingMultiplicativeOperator;
    bool waitingForOperand;

    QLineEdit *display;
    QLineEdit *display1;
    QLineEdit *display2;

    enum { NumDigitButtons = 10 };
    Button *digitButtons[NumDigitButtons];
};

#endif
