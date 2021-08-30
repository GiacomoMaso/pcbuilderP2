#include "listamagazzinoview.h"

ListaMagazzinoView::ListaMagazzinoView(QWidget* parent) : QWidget(parent), magazzino_list(new QListWidget(this))
{
    setWindowTitle("Prodotti presenti nel magazzino");
    setMinimumSize(800, 600);

   QVBoxLayout* layout= new QVBoxLayout;
    layout->addWidget(magazzino_list);
    setLayout(layout);


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
}
