#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cliente.h"
#include "QMessageBox"
#include "QString"
#include "QDebug"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_IAristaBtn_clicked()
{
    Cliente C; // objeto de la clase cliente
    C.Client();
    string opc; // identificador para que el servidor sepa lo que debe hacer
    opc = "2";

    QString NodoOrig = ui->NodoOrig->text(); // se obtiene el texto del cuadro correspondiente de la interfaz
    QString NodoDest = ui->NodoDest->text(); // se obtiene el texto del cuadro correspondiente de la interfaz
    QString ValorArist = ui->AristValor->text(); // se obtiene el texto del cuadro correspondiente de la interfaz
    string textOrig = NodoOrig.toUtf8().constData();// pasando de qstring a std string
    string textDest = NodoDest.toUtf8().constData();// pasando de qstring a std string
    string txtPeso = ValorArist.toUtf8().constData();// pasando de qstring a std string

    //C.EnviarString(textOrig, textDest, txtPeso, opc); // enviando el string convertido al cliente para pasarlo al servidor
    QMessageBox::information(this,tr("INFORMACION"),tr("ARISTA INSERTADA"));// se muestra informacion de que se inserto el arista
}

void MainWindow::on_INodoBtn_clicked()
{
    Cliente C; // objeto de la clase cliente
    C.Client();
    string opc; // identificador para que el servidor sepa lo que debe hacer
    opc = "1";
    string array[2];

    QString NombreNodo = ui->NombreNodo->text(); // se obtiene el texto del cuadro correspondiente de la interfaz
    std::string strtext = NombreNodo.toUtf8().constData(); // pasando de qstring a std string
    array[0] = opc;
    array[1] = strtext;
    C.EnviarString(array); // enviando el string convertido al cliente para pasarlo al servidor
    QMessageBox::information(this,tr("INFORMACION"),tr("NODO INSERTADO")); // se muestra informacion de que se inserto el nodo
}









