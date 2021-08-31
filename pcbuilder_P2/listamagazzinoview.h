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
    QListView* magazzino_list;
    QStringListModel* list_model;
    QPushButton* aggiungi, *elimina;
    QComboBox* filter_box;


public:
     ListaMagazzinoView(QWidget* p=nullptr);
     void loadMagazzinoview(QStringList* x);
protected:
     void closeEvent(QCloseEvent *event);
signals:
     void closing();

};
#endif // LISTAMAGAZZINOVIEW_H
