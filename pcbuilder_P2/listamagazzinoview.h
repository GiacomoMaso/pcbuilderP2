#ifndef LISTAMAGAZZINOVIEW_H
#define LISTAMAGAZZINOVIEW_H

#include<iostream>
//#include<QPushButton>
#include<QtWidgets>
#include <QDebug>
#include <QListWidget>
//#include <QBoxLayout>




class ListaMagazzinoView :  public QWidget {
    Q_OBJECT

private:
    QListWidget* magazzino_list;
    QStringListModel* list_model;
    QPushButton* aggiungi_button, *elimina_button;
    QComboBox* filter_box;
protected:
     void closeEvent(QCloseEvent *event);
public:
     ListaMagazzinoView(QWidget* p=nullptr);
     void loadMagazzinoview(QStringList* x);
     ~ListaMagazzinoView() =default;
public slots:
     void richiesta_elimina_obj();
     void item_selected(QListWidgetItem*);
signals:
     void closing();
     void delete_obj_to_controller(std::string );
     void item_to_view(std::string);

};
#endif // LISTAMAGAZZINOVIEW_H
