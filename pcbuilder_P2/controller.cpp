#include "controller.h"

Controller::Controller() : view( new Mainwindow())
{
    view->show();
}
