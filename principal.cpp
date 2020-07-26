#include "principal.h"
#include "ui_principal.h"
#include <QMessageBox>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_cmdCalcular_clicked()
{
    const double num1 = ui->inNum1->value();
    const double num2 = ui->inNum2->value();
    double resultado = 0.0;
    switch (ui->inOperacion->currentIndex()) {
    case 0:
        resultado = num1 + num2;
        break;
    case 1:
        resultado = num1 - num2;
        break;
    case 2:
        resultado = num1 * num2;
        break;
    case 3:
        resultado = num1 / num2;
        break;
    }
    QMessageBox::information(this,
                             tr("Resultado"),
                             tr("El resultado es: %1").arg(resultado));
}
