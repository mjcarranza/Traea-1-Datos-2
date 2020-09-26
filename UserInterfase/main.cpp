/* Libraries */
#include "mainwindow.h"
#include "cliente.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    /* Client`s class object */
    Cliente C;

    /*  Initializing client class */
    C.Client();

    /* Creating user interface*/
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
