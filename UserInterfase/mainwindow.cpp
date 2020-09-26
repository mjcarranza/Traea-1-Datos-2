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
    C.Client();/* With this number the server knows what does the client want to do */
    string opc = "2";
    char option[10];
    char Origin[100];
    char Destination[100];
    char Weight[100];
    string array[4];

    QString NodoOrig = ui->NodoOrig->text(); /* Obtains the name of the oigin node */
    QString NodoDest = ui->NodoDest->text(); /* Obtains the name of the destination node */
    QString ValorArist = ui->AristValor->text(); //* Obtains the value for the new arist */

    /* Passing form qstring to string */
    string textOrig = NodoOrig.toUtf8().constData();
    string textDest = NodoDest.toUtf8().constData();
    string txtPeso = ValorArist.toUtf8().constData();

    /* Passing from string to char */
    strcpy(Origin,textOrig.c_str());
    strcpy(Destination,textDest.c_str());
    strcpy(Weight,txtPeso.c_str());
    strcpy(option,opc.c_str());

    /* Sending the array to the server */
    C.SendString(option);
    C.SendString(Origin);
    C.SendString(Destination);
    C.SendString(Weight);
    QMessageBox::information(this,tr("INFORMACION"),tr("ARISTA INSERTADA")); /* Chart shows info about the arista */
}

void MainWindow::on_INodoBtn_clicked()
{
    Cliente C; /* Client`s class object */
    C.Client();
    string opc = "1"; /* With this number the server knows what does the client want to do */
    char option[10];
    char Node[100];

    QString NombreNodo = ui->NombreNodo->text();  /* Obtains the name for the new node */
    string strtext = NombreNodo.toUtf8().constData(); /* Passing form qstring to string */

    /* Passing from string to char */
    strcpy(option,opc.c_str());
    strcpy(Node,strtext.c_str());

    /* Sending the array to the server */
    C.SendString(option);
    C.SendString(Node);
    QMessageBox::information(this,tr("INFORMACION"),tr("NODO INSERTADO")); /* Chart shows info about the new node */
}









