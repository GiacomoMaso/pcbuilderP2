#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QBoxLayout>
#include <QPushButton>

class Mainwindow : public QWidget{
    Q_OBJECT
private:
    Mainwindow* view;

public:
    Mainwindow(QWidget  *p = nullptr);
};

#endif // MAINWINDOW_H
