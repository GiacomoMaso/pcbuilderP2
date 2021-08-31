#include "listamagazzinoview.h"

ListaMagazzinoView::ListaMagazzinoView(QWidget* parent) : QWidget(parent), magazzino_list(new QListView(this)), aggiungi(new QPushButton("Aggiungi",this)), elimina(new QPushButton("Elimina",this)), filter_box(new QComboBox(this)), list_model(new QStringListModel(this))
{
    setWindowTitle("Prodotti presenti nel magazzino");
    setMinimumSize(800, 600);
    aggiungi->setMinimumSize(200,50);
    elimina->setMinimumSize(200,50);
    filter_box->setMinimumSize(200,50);
// filter_box->lineEdit()->setPlaceholderText("filtro");
    QStringList List=(QStringList() <<"Tutti Gli Elementi"<< "Cpu" << "Gpu" << "Ram"<<"Rom"<<"Psu"<<"Scheda Madre");

    filter_box->addItems(List);
    magazzino_list->setModel(list_model);






   QVBoxLayout* layout= new QVBoxLayout;
   QHBoxLayout* button_layout= new QHBoxLayout;
    button_layout->addWidget(aggiungi);
    button_layout->addWidget(elimina);
    button_layout->addWidget(filter_box);
    layout->addWidget(magazzino_list);
    layout->addLayout(button_layout);

    setLayout(layout);


}

void ListaMagazzinoView::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}

void ListaMagazzinoView::loadMagazzinoview(QStringList* x) {
//    for(auto it=x->begin(); it!=x->end(); it++){
//        magazzino_list->addItem(*it);
//    }
    list_model->setStringList(*x);
}
