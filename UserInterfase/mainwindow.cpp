/* Libraries */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cliente.h"
#include "QMessageBox"
#include "QString"
#include "QDebug"

/* Creating a new user interface */
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

/* Method for button to add a new arist to the graph */
void MainWindow::on_IAristaBtn_clicked()
{
    Cliente C; /* Client`s class object */
    C.Client();
    string opc; /* With this number the server knows what does the client want to do */
    opc = "2";
    string array[4];

    QString NodoOrig = ui->NodoOrig->text(); /* Obtains the name of the oigin node */
    QString NodoDest = ui->NodoDest->text(); /* Obtains the name of the destination node */
    QString ValorArist = ui->AristValor->text(); //* Obtains the value for the new arist */

    /* Passing form qstring to string */
    string textOrig = NodoOrig.toUtf8().constData();
    string textDest = NodoDest.toUtf8().constData();
    string txtPeso = ValorArist.toUtf8().constData();

    /* Adding data to the array that will be sent*/
    array[0] = opc;
    array[0] = textOrig;
    array[0] = textDest;
    array[0] = txtPeso;

    /* Sending the array to the server */
    C.SendString(array);
    QMessageBox::information(this,tr("INFORMACION"),tr("ARISTA INSERTADA")); /* Chart shows info about the arista */
}

void MainWindow::on_INodoBtn_clicked()
{
    Cliente C; /* Client`s class object */
    C.Client();
    string opc; /* With this number the server knows what does the client want to do */
    opc = "1";
    string array[2];

    QString NombreNodo = ui->NombreNodo->text();  /* Obtains the name for the new node */
    std::string strtext = NombreNodo.toUtf8().constData(); /* Passing form qstring to string */

    /* Adding data to the array that will be sent*/
    array[0] = opc;
    array[1] = strtext;

    /* Sending the array to the server */
    C.SendString(array);
    QMessageBox::information(this,tr("INFORMACION"),tr("NODO INSERTADO")); /* Chart shows info about the new node */
}









