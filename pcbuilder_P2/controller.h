#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <iostream>
#include "mainwindow.h"
#include "gpu.h"
#include "case.h"
#include "componente.h"
#include "item.h"
#include "smartptr.h"
#include "contenitore.h"
#include "Magazzino.h"



class Controller : public QObject
{
private:
    Magazzino* m;
    Mainwindow* view;

public:
    Controller();
    void prova();
};

#endif // CONTROLLER_H
