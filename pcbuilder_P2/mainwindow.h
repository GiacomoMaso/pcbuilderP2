#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QBoxLayout>
#include <QPushButton>
#include <QMainWindow>

#include "listamagazzinoview.h"

class Mainwindow : public QMainWindow{
    Q_OBJECT
private:
    Mainwindow* view;
    ListaMagazzinoView* prova;
    QPushButton* view_obj, * add_obj, * delete_obj;
    QListWidget* magazzino_list;


public:
    Mainwindow(QWidget  *parent = nullptr);



 signals:
  void visualizzaComponentiPressed();
  void start_list_view();

public slots :
  void openSubview();



};

#endif // MAINWINDOW_H
