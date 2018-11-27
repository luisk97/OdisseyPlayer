#include "mainwindow.h"
#include <QApplication>
#include "singleton.h"

int main(int argc, char *argv[])
{   
    //Aqui establece conexion con el servidor
    Singleton::connectToServer("192.168.43.63", 8000);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
