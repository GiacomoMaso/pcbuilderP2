#include <QApplication>
#include <QPushButton>
#include "controller.h"
#include "mainwindow.h"
#include "gpu.h"
#include "case.h"
#include "componente.h"
#include "item.h"
#include "smartptr.h"
#include "contenitore.h"
#include "Magazzino.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller app;


    return QApplication::exec();

}
