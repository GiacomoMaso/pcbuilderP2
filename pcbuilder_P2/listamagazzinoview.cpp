#include "listamagazzinoview.h"

ListaMagazzinoView::ListaMagazzinoView(QWidget* parent) : QWidget(parent), magazzino_list(new QListWidget(this)), aggiungi_button(new QPushButton("Aggiungi",this)), elimina_button(new QPushButton("Elimina",this)), filter_box(new QComboBox(this))/*, list_model(new QStringListModel(this))*/
{
    setWindowTitle("Prodotti presenti nel magazzino");
    setMinimumSize(800, 600);
    aggiungi_button->setMinimumSize(200,50);
    elimina_button->setMinimumSize(200,50);
    filter_box->setMinimumSize(200,50);
// filter_box->lineEdit()->setPlaceholderText("filtro");
    QStringList List=(QStringList() <<"Tutti gli elementi"<< "Cpu" << "Gpu" << "Ram"<<"Rom"<<"Psu"<<"Scheda Madre");

    filter_box->addItems(List);
//    magazzino_list->setModel(list_model);


   QVBoxLayout* layout= new QVBoxLayout;
   QHBoxLayout* button_layout= new QHBoxLayout;
    button_layout->addWidget(aggiungi_button);
    button_layout->addWidget(elimina_button);
    button_layout->addWidget(filter_box);
    layout->addWidget(magazzino_list);
    layout->addLayout(button_layout);
    setLayout(layout);


    connect(elimina_button, SIGNAL(clicked()), this, SLOT(richiesta_elimina_obj()));
    connect(magazzino_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(item_selected(QListWidgetItem*)));



}

void ListaMagazzinoView::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}

void ListaMagazzinoView::loadMagazzinoview(QStringList* x) {
    for(auto it=x->begin(); it!=x->end(); it++){
        magazzino_list->addItem(*it);
    }
//    list_model->setStringList(*x);
}

void ListaMagazzinoView::richiesta_elimina_obj() {
    if(magazzino_list->count()!=0){
    QListWidgetItem* provv=magazzino_list->currentItem();
    std::string obj_to_delete=provv->text().toStdString();
    delete provv;
    emit delete_obj_to_controller(obj_to_delete);
    }
}

void ListaMagazzinoView::item_selected(QListWidgetItem* provv){
    provv=magazzino_list->currentItem();
    std::string obj_to_view=provv->text().toStdString();
    emit item_to_view(obj_to_view);
}
