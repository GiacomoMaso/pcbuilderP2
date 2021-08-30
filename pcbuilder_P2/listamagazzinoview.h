#ifndef LISTAMAGAZZINOVIEW_H
#define LISTAMAGAZZINOVIEW_H

#include<iostream>
#include<QPushButton>
#include<QtWidgets>
#include <QListWidget>
#include <QBoxLayout>




class ListaMagazzinoView :  public QWidget {
    Q_OBJECT

private:
QListWidget* magazzino_list;

public:
     ListaMagazzinoView(QWidget* p=nullptr);
     void loadMagazzinoview(QStringList* x);
protected:
     void closeEvent(QCloseEvent *event);
signals:
     void closing();

};
#endif // LISTAMAGAZZINOVIEW_H
