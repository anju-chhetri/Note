#include "mainwindow.h"
#include <QApplication>
#include <QString>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    if(argc>1){
        QString path_file=argv[argc-1];
        path_file.replace("\\","/");
        w.open_file(path_file);
    }


    return a.exec();
}
