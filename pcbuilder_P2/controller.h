#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "Magazzino.h"
#include "mainwindow.h"


class Controller : public QObject
{
private:
    Magazzino* m;
    Mainwindow* view;

public:
    Controller();
};

#endif // CONTROLLER_H
