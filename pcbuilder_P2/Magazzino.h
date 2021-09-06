#ifndef MAGAZZINO_H
#define MAGAZZINO_H
#include "contenitore.h"
//#include "item.h"
#include "smartptr.h"
#include "cpu.h"
#include "gpu.h"
#include "psu.h"
#include "schedamadre.h"
#include "case.h"
#include "memoria.h"
#include "ram.h"
#include "rom.h"

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
//#include <QFileInfo>
#include <QDebug>
#include <QStringList>
#include <QString>

class Magazzino {
private:
    contenitore<Smartptr<Item>> *lista_ogg;
    contenitore<Item*> *lista_filtrata;

public:
    //Magazzino(const Smartptr<Item>&);
    Magazzino();

    void add_compoenente (const Smartptr<Item>&);
    void filtroMarca(std::string);
    bool delete_by_name(std::string);
    bool add_item(QStringList*);
    unsigned int get_quantita_item(std::string) const;
    void filtroCpu();
    contenitore<Item*>* get_filtro();
    contenitore<Smartptr<Item>>* get_lista();
    QStringList* get_lista_view();
    QStringList* get_item_to_view(std::string) const;
    void filtroGpu();
    void filtroCase();
    void filtroSchedaMadre();
    void filtroPsu();
    void load_database();

//    void filtroPrezzo();

};

#endif // MAGAZZINO_H
