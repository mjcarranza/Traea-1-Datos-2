#include "mainwindow.h"
#include "cliente.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // Client class object
    Cliente C;
    // Initializing client class
    C.Client();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
