#include <QApplication>
#include <QPushButton>
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller app;
    return QApplication::exec();

}
