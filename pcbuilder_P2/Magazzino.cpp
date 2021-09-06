#include "Magazzino.h"

//Magazzino::Magazzino(const Smartptr<Item>& p) : lista_ogg(new contenitore<Smartptr<Item>>(p)) {}

Magazzino::Magazzino() : lista_ogg(nullptr)  {
    load_database();
}

void Magazzino::add_compoenente (const Smartptr<Item>& p) {lista_ogg->add_coda(p);}

void Magazzino::filtroCpu() {

    for( contenitore<Smartptr<Item>>::Const_iteratore it=lista_ogg->inizio(); it!=lista_ogg->fine(); it++){
        Item* provv=*it;
        if(dynamic_cast<Cpu*>(provv)){
            if(lista_filtrata) {
                lista_filtrata->add_coda(provv);
            }
            else{
                lista_filtrata=new contenitore<Item*>(provv);
            }
        }

    }


//    for( contenitore<Item*>::Const_iteratore it=lista_filtrata->inizio(); it!=lista_filtrata->fine() ; it++){
//            std::cout<<(*it)->get_name()<<std::endl;
//    }

}


void Magazzino::filtroGpu() {

    for( contenitore<Smartptr<Item>>::Const_iteratore it=lista_ogg->inizio(); it!=lista_ogg->fine(); it++){
        Item* provv=*it;
        if(dynamic_cast<Gpu*>(provv)){
            if(lista_filtrata) {
                lista_filtrata->add_coda(provv);
            }
            else{
                lista_filtrata=new contenitore<Item*>(provv);
            }
        }

    }


//    for( contenitore<Item*>::Const_iteratore it=lista_filtrata->inizio(); it!=lista_filtrata->fine() ; it++){
//            std::cout<<(*it)->get_name()<<std::endl;
//    }

}

void Magazzino::filtroCase() {

    for( contenitore<Smartptr<Item>>::Const_iteratore it=lista_ogg->inizio(); it!=lista_ogg->fine(); it++){
        Item* provv=*it;
        if(dynamic_cast<Case*>(provv)){
            if(lista_filtrata) {
                lista_filtrata->add_coda(provv);
            }
            else{
                lista_filtrata=new contenitore<Item*>(provv);
            }
        }
    }


//    for( contenitore<Item*>::Const_iteratore it=lista_filtrata->inizio(); it!=lista_filtrata->fine() ; it++){
//            std::cout<<(*it)->get_name()<<std::endl;
//    }

}

void Magazzino::filtroSchedaMadre() {

    for( contenitore<Smartptr<Item>>::Const_iteratore it=lista_ogg->inizio(); it!=lista_ogg->fine(); it++){
        Item* provv=*it;
        if(dynamic_cast<SchedaMadre*>(provv)){
            if(lista_filtrata) {
                lista_filtrata->add_coda(provv);
            }
            else{
                lista_filtrata=new contenitore<Item*>(provv);
            }
        }
    }


    for( contenitore<Item*>::Const_iteratore it=lista_filtrata->inizio(); it!=lista_filtrata->fine() ; it++){
            std::cout<<(*it)->get_name()<<std::endl;
    }

}


void Magazzino::filtroPsu() {

    for( contenitore<Smartptr<Item>>::Const_iteratore it=lista_ogg->inizio(); it!=lista_ogg->fine(); it++){
        Item* provv=*it;
        if(dynamic_cast<Psu*>(provv)){
            if(lista_filtrata) {
                lista_filtrata->add_coda(provv);
            }
            else{
                lista_filtrata=new contenitore<Item*>(provv);
            }
        }
    }


    for( contenitore<Item*>::Const_iteratore it=lista_filtrata->inizio(); it!=lista_filtrata->fine() ; it++){
            std::cout<<(*it)->get_name()<<std::endl;
    }

}


contenitore<Item*>* Magazzino::get_filtro() {
    return lista_filtrata;
}

contenitore<Smartptr<Item>>* Magazzino::get_lista() {
    return lista_ogg;
}

void Magazzino::load_database() {
//    QFile file("/Users/giacomomason/Documents/GitHub/pcbuilderP2/pcbuilder_P2/database.xml");
      QFile file(":/database.xml");

    file.open(QIODevice::ReadOnly);
    QXmlStreamReader reader(&file);

    if (reader.readNextStartElement()) {
            if (reader.name() == "Magazzino"){

                while(reader.readNextStartElement()){

                      if(reader.name() == "Gpu"){
                        std::string nome;
                        unsigned int quantita;
                        std::string marca;
                        std::string modello;
                        unsigned int price;
                        unsigned int realese_date;
                        std::string variante;
                        unsigned int vram;
                        unsigned int gpu_clock;
                        std::string type_ram;
                       while(reader.readNextStartElement()){

                            if(reader.name() == "nome"){
                                 nome=reader.readElementText().toStdString();
                            }
                            else if(reader.name() == "quantita"){
                                 quantita=reader.readElementText().toInt();
                            }
                            else if(reader.name() == "marca"){
                                 marca=reader.readElementText().toStdString();
                            }
                            else if(reader.name() == "modello"){
                                 modello=reader.readElementText().toStdString();
                            }
                            else if(reader.name() == "price"){
                                 price=reader.readElementText().toInt();
                            }
                            else if(reader.name() == "realese_date"){
                                 realese_date=reader.readElementText().toInt();
                            }
                            else if(reader.name() == "variante"){
                                 variante=reader.readElementText().toStdString();
                            }
                            else if(reader.name() == "vram"){
                                 vram=reader.readElementText().toInt();
                            }
                            else if(reader.name() == "gpu_clock"){
                                 gpu_clock=reader.readElementText().toInt();
                            }
                            else if(reader.name() == "type_ram"){
                                 type_ram=reader.readElementText().toStdString();
                            }


                       }
                       Gpu* provv=new Gpu(nome,quantita,marca,modello,price,realese_date,variante,vram,gpu_clock,type_ram);
                       Smartptr<Item> obj(provv);
                       if(lista_ogg) add_compoenente(obj);
                       else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}
                    }
                     else if(reader.name() == "Cpu"){
                          std::string nome;
                          unsigned int quantita;
                          std::string marca;
                          std::string modello;
                          unsigned int price;
                          unsigned int realese_date;
                          std::string serie;
                          double ghz;
                          unsigned int core_number;
                          std::string intel_AMD;
                          std::string socket;
                         while(reader.readNextStartElement()){

                              if(reader.name() == "nome"){
                                   nome=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "quantita"){
                                   quantita=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "marca"){
                                   marca=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "modello"){
                                   modello=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "price"){
                                   price=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "realese_date"){
                                   realese_date=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "serie"){
                                   serie=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "ghz"){
                                   ghz=reader.readElementText().toDouble();
                              }
                              else if(reader.name() == "core_number"){
                                   core_number=reader.readElementText().toInt();
                              }

                              else if(reader.name() == "socket"){
                                   socket=reader.readElementText().toStdString();
                              }

                         }

                         Cpu* provv=new Cpu(nome,quantita,marca,modello,price,realese_date,serie,ghz,core_number,socket);
                         Smartptr<Item> obj(provv);
                         if(lista_ogg) add_compoenente(obj);
                         else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}
                      }

                     else if(reader.name() == "Psu"){
                          std::string nome;
                          unsigned int quantita;
                          std::string marca;
                          std::string modello;
                          unsigned int price;
                          unsigned int realese_date;
                          unsigned int watt;
                          std::string rating;
                          std::string modularita;

                         while(reader.readNextStartElement()){

                              if(reader.name() == "nome"){
                                   nome=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "quantita"){
                                   quantita=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "marca"){
                                   marca=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "modello"){
                                   modello=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "price"){
                                   price=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "realese_date"){
                                   realese_date=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "watt"){
                                   watt=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "rating"){
                                   rating=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "modularita"){
                                   modularita=reader.readElementText().toStdString();
                              }


                         }

                         Psu* provv=new Psu(nome,quantita,marca,modello,price,realese_date,watt,rating,modularita);
                         Smartptr<Item> obj(provv);
                         if(lista_ogg) add_compoenente(obj);
                         else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}


                      }

                     else if(reader.name() == "SchedaMadre"){
                          std::string nome;
                          unsigned int quantita;
                          std::string marca;
                          std::string modello;
                          unsigned int price;
                          unsigned int realese_date;
                          std::string grandezza;
                          std::string socket_mb;
                          unsigned int sata_port;
                          unsigned int nvme_port;


                         while(reader.readNextStartElement()){

                              if(reader.name() == "nome"){
                                   nome=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "quantita"){
                                   quantita=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "marca"){
                                   marca=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "modello"){
                                   modello=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "price"){
                                   price=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "realese_date"){
                                   realese_date=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "grandezza"){
                                   grandezza=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "socket_mb"){
                                   socket_mb=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "sata_port"){
                                   sata_port=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "nvme_port"){
                                   nvme_port=reader.readElementText().toInt();
                              }


                         }

                         SchedaMadre* provv=new SchedaMadre(nome,quantita,marca,modello,price,realese_date,grandezza,socket_mb, sata_port, nvme_port);
                         Smartptr<Item> obj(provv);
                         if(lista_ogg) add_compoenente(obj);
                         else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}

                      }

                     else if(reader.name() == "Case"){
                          std::string nome;
                          unsigned int quantita;
                          std::string marca;
                          std::string modello;
                          unsigned int price;
                          unsigned int realese_date;
                          std::string case_dim;
                          std::string mb_supported;


                         while(reader.readNextStartElement()){

                              if(reader.name() == "nome"){
                                   nome=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "quantita"){
                                   quantita=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "marca"){
                                   marca=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "modello"){
                                   modello=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "price"){
                                   price=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "realese_date"){
                                   realese_date=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "case_dim"){
                                   case_dim=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "mb_supported"){
                                   mb_supported=reader.readElementText().toStdString();
                              }


                         }

                         Case* provv=new Case(nome,quantita,marca,modello,price,realese_date,case_dim,mb_supported);
                         Smartptr<Item> obj(provv);
                         if(lista_ogg) add_compoenente(obj);
                         else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}
                      }

                      else if(reader.name() == "Ram"){
                           std::string nome;
                           unsigned int quantita;
                           std::string marca;
                           std::string modello;
                           unsigned int price;
                           unsigned int realese_date;
                           std::string type_memory;
                           unsigned int capacity;
                           unsigned int clock;
                           unsigned int latency;
//                           unsigned int num_per_pacco;


                          while(reader.readNextStartElement()){

                               if(reader.name() == "nome"){
                                    nome=reader.readElementText().toStdString();
                               }
                               else if(reader.name() == "quantita"){
                                    quantita=reader.readElementText().toInt();
                               }
                               else if(reader.name() == "marca"){
                                    marca=reader.readElementText().toStdString();
                               }
                               else if(reader.name() == "modello"){
                                    modello=reader.readElementText().toStdString();
                               }
                               else if(reader.name() == "price"){
                                    price=reader.readElementText().toInt();
                               }
                               else if(reader.name() == "realese_date"){
                                    realese_date=reader.readElementText().toInt();
                               }
                               else if(reader.name() == "type_memory"){
                                    type_memory=reader.readElementText().toStdString();
                               }
                               else if(reader.name() == "capacity"){
                                    capacity=reader.readElementText().toInt();
                               }
                               else if(reader.name() == "clock"){
                                    clock=reader.readElementText().toInt();
                               }
                               else if(reader.name() == "latency"){
                                    latency=reader.readElementText().toInt();
                               }
//                               else if(reader.name() == "num_per_pacco"){
//                                    num_per_pacco=reader.readElementText().toInt();
//                               }


                          }

                          Ram* provv=new Ram(nome,quantita,marca,modello,price,realese_date,type_memory,capacity,clock,latency);
                          Smartptr<Item> obj(provv);
                          if(lista_ogg) add_compoenente(obj);
                          else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}
                       }

                      else if(reader.name() == "Rom"){
                           std::string nome;
                           unsigned int quantita;
                           std::string marca;
                           std::string modello;
                           unsigned int price;
                           unsigned int realese_date;
                           std::string type_memory;
                           unsigned int capacity;
                           double mb_write;
                           double mb_read;
                           double size;


                          while(reader.readNextStartElement()){

                               if(reader.name() == "nome"){
                                    nome=reader.readElementText().toStdString();
                               }
                               else if(reader.name() == "quantita"){
                                    quantita=reader.readElementText().toInt();
                               }
                               else if(reader.name() == "marca"){
                                    marca=reader.readElementText().toStdString();
                               }
                               else if(reader.name() == "modello"){
                                    modello=reader.readElementText().toStdString();
                               }
                               else if(reader.name() == "price"){
                                    price=reader.readElementText().toInt();
                               }
                               else if(reader.name() == "realese_date"){
                                    realese_date=reader.readElementText().toInt();
                               }
                               else if(reader.name() == "type_memory"){
                                    type_memory=reader.readElementText().toStdString();
                               }
                               else if(reader.name() == "capacity"){
                                    capacity=reader.readElementText().toInt();
                               }
                               else if(reader.name() == "mb_write"){
                                    mb_write=reader.readElementText().toDouble();  // da vedere se toDouble() funziona
                               }
                               else if(reader.name() == "mb_read"){
                                    mb_read=reader.readElementText().toDouble(); // idem
                               }

                               else if(reader.name() == "size"){
                                    size=reader.readElementText().toDouble(); // idem
                               }



                          }

                          Rom* provv=new Rom(nome,quantita,marca,modello,price,realese_date,type_memory,capacity,mb_write,mb_read, size);
                          Smartptr<Item> obj(provv);
                          if(lista_ogg) add_compoenente(obj);
                          else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}
                       }
                  }

             }
      }

    contenitore<Smartptr<Item>>* prova=get_lista();
    for(contenitore<Smartptr<Item>>::Iteratore it=prova->begin(); it !=prova->end(); it++){
        std::cout<<(*it)->get_name()<<std::endl;}

}

QStringList* Magazzino::get_lista_view(){
    QStringList* list=new QStringList();
    QString obj;
    for(auto it=lista_ogg->begin(); it!=lista_ogg->end(); it++){
        obj=QString::fromStdString((*it)->get_name());
        list->push_back(obj);

    }
    return list;
}

bool Magazzino::delete_by_name(std::string x){

    bool empty=false;
    for(auto it=lista_ogg->begin(); it!=lista_ogg->end(); it++){

        if((*it)->get_name()==x){
            if((*it)->get_quantita()>1) {
                (*it)->removeOneItem();

            }
            else { empty=lista_ogg->delete_node(it);
            }
        }
    }

    if(empty){
        delete lista_ogg;
        lista_ogg=nullptr;
    }

    return empty;

//    for(auto it=lista_ogg->begin(); it!=lista_ogg->end(); it++){
//        std::cout<<(*it)->get_name()<<std::endl;
//    }
}

QStringList* Magazzino::get_item_to_view(std::string x) const{
    QStringList* list_field=new QStringList();
    QString field;

    for(contenitore<Smartptr<Item>>::Const_iteratore it=lista_ogg->inizio(); it!=lista_ogg->fine(); it++){
        if((*it)->get_name()==x){
            Item* p=*it;
            field="Nome: "+QString::fromStdString(p->get_name());
            list_field->push_back(field);
            field="Quantità: "+QString::number(p->get_quantita());
            list_field->push_back(field);
            if(dynamic_cast<Gpu*>(p)){
                Gpu* p_gpu=dynamic_cast<Gpu*>(p);
                field="Marca: "+QString::fromStdString(p_gpu->get_marca());
                list_field->push_back(field);
                field="Modello: "+QString::fromStdString(p_gpu->get_modello());
                list_field->push_back(field);
                field="Prezzo: "+QString::number(p_gpu->get_price());
                list_field->push_back(field);
                field="Data di Rilascio: "+QString::number(p_gpu->get_realese_date());
                list_field->push_back(field);
                field="Variante: "+QString::fromStdString(p_gpu->get_variante());
                list_field->push_back(field);
                field="Vram: "+QString::number(p_gpu->get_vram());
                list_field->push_back(field);
                field="Clock: "+QString::number(p_gpu->get_gpu_clock())+" Mhz";
                list_field->push_back(field);
                field="Tipologia ram:"+QString::fromStdString(p_gpu->get_type_ram());
                list_field->push_back(field);

            }
            else if(dynamic_cast<Cpu*>(p)){
                Cpu* p_cpu=dynamic_cast<Cpu*>(p);
                field="Marca: "+QString::fromStdString(p_cpu->get_marca());
                list_field->push_back(field);
                field="Modello: "+QString::fromStdString(p_cpu->get_modello());
                list_field->push_back(field);
                field="Prezzo: "+QString::number(p_cpu->get_price());
                list_field->push_back(field);
                field="Data di rilascio: "+QString::number(p_cpu->get_realese_date());
                list_field->push_back(field);
                field="Serie: "+QString::fromStdString(p_cpu->get_serie());
                list_field->push_back(field);
                field="Cpu ghz: "+QString::number(p_cpu->get_ghz())+" Ghz";
                list_field->push_back(field);
                field="Numero di core: "+QString::number(p_cpu->get_core_number());
                list_field->push_back(field);
//                field="Intel/AMD: "+QString::fromStdString(p_cpu->get_intel_AMD());
                list_field->push_back(field);
                field="Socket in cui va inserito: "+QString::fromStdString(p_cpu->get_socket());
                list_field->push_back(field);



            }
            else if(dynamic_cast<Psu*>(p)){
                Psu* p_psu=dynamic_cast<Psu*>(p);
                field="Marca: "+QString::fromStdString(p_psu->get_marca());
                list_field->push_back(field);
                field="Modello: "+QString::fromStdString(p_psu->get_modello());
                list_field->push_back(field);
                field="Prezzo: "+QString::number(p_psu->get_price());
                list_field->push_back(field);
                field="Data di rilascio: "+QString::number(p_psu->get_realese_date());
                list_field->push_back(field);
                field="Watt: "+QString::number(p_psu->get_watt())+ "W";
                list_field->push_back(field);
                field="Rating: "+QString::fromStdString(p_psu->get_rating());
                list_field->push_back(field);
                field="Modularità: "+QString::fromStdString(p_psu->get_mod());
                list_field->push_back(field);



            }

            else if(dynamic_cast<SchedaMadre*>(p)){
                SchedaMadre* p_mb=dynamic_cast<SchedaMadre*>(p);
                field="Marca: "+QString::fromStdString(p_mb->get_marca());
                list_field->push_back(field);
                field="Modello: "+QString::fromStdString(p_mb->get_modello());
                list_field->push_back(field);
                std::cout<<field.toStdString()<<std::endl;
                field="Prezzo: "+QString::number(p_mb->get_price());
                list_field->push_back(field);
                std::cout<<field.toStdString()<<std::endl;
                field="Data di rilascio: "+QString::number(p_mb->get_realese_date());
                list_field->push_back(field);
                std::cout<<field.toStdString()<<std::endl;
                field="Formato: "+QString::fromStdString(p_mb->get_grandezza());
                list_field->push_back(field);
                std::cout<<field.toStdString()<<std::endl;
                field="Socket: "+QString::fromStdString(p_mb->get_socket_mb());
                list_field->push_back(field);
                std::cout<<field.toStdString()<<std::endl;
                field="Numero porte Sata: "+QString::number(p_mb->get_sata_port());
                list_field->push_back(field);
                std::cout<<field.toStdString()<<std::endl;
                field="Numero slot NVME: "+QString::number(p_mb->get_nvme_port());
                list_field->push_back(field);
                std::cout<<field.toStdString()<<std::endl;

            }

            else if(dynamic_cast<Case*>(p)){
                Case* p_case=dynamic_cast<Case*>(p);
                field="Marca: "+QString::fromStdString(p_case->get_marca());
                list_field->push_back(field);
                field="Modello: "+QString::fromStdString(p_case->get_modello());
                list_field->push_back(field);
                field="Prezzo: "+QString::number(p_case->get_price());
                list_field->push_back(field);
                field="Data di rilascio: "+QString::number(p_case->get_realese_date());
                list_field->push_back(field);
                field="Dimensione case: "+QString::fromStdString(p_case->get_case_dim());
                list_field->push_back(field);
                field="Formato scheda madre supportata: "+QString::fromStdString(p_case->get_mb_supported());
                list_field->push_back(field);

            }

            else if(dynamic_cast<Ram*>(p)){
                Ram* p_ram=dynamic_cast<Ram*>(p);
                field="Marca: "+QString::fromStdString(p_ram->get_marca());
                list_field->push_back(field);
                field="Modello: "+QString::fromStdString(p_ram->get_modello());
                list_field->push_back(field);
                field="Prezzo: "+QString::number(p_ram->get_price());
                list_field->push_back(field);
                field="Data di rilascio: "+QString::number(p_ram->get_realese_date());
                list_field->push_back(field);
                field="Tipo memoria: "+QString::fromStdString(p_ram->get_type_memory());
                list_field->push_back(field);
                field="Capacità: "+QString::number(p_ram->get_capacity());
                list_field->push_back(field);
                field="Clock: "+QString::number(p_ram->get_clock())+ "Mhz";
                list_field->push_back(field);
                field="Latenza: CL"+QString::number(p_ram->get_latency());
                list_field->push_back(field);

            }

            else if(dynamic_cast<Rom*>(p)){
                Rom* p_rom=dynamic_cast<Rom*>(p);
                field="Marca: "+QString::fromStdString(p_rom->get_marca());
                list_field->push_back(field);
                field="Modello: "+QString::fromStdString(p_rom->get_modello());
                list_field->push_back(field);
                field="Prezzo: "+QString::number(p_rom->get_price());
                list_field->push_back(field);
                field="Data di rilascio: "+QString::number(p_rom->get_realese_date());
                list_field->push_back(field);
                field="Tipo di memoria: "+QString::fromStdString(p_rom->get_type_memory());
                list_field->push_back(field);
                field="Capacità: "+QString::number(p_rom->get_capacity());
                list_field->push_back(field);
                field="Velocità scrittura: "+QString::number(p_rom->get_mb_write())+"Mb/s";
                list_field->push_back(field);
                field="Velocità in lettura: "+QString::number(p_rom->get_mb_read())+"Mb/s";
                list_field->push_back(field);
                field="Size: "+QString::number(p_rom->get_size());
                list_field->push_back(field);

            }

            field="Product score: "+QString::number((*it)->product_score());
            list_field->push_back(field);

        }
    }

    for ( const auto& i : *list_field  )
    {
        qDebug()<<i;
    }

    return list_field;
}

bool Magazzino::add_item(QStringList* list){
    bool check_name=true;
    std::string nome=list->at(1).toStdString();
    if(lista_ogg){
        std::cout<<"prova list"<<std::endl;
        for(contenitore<Smartptr<Item>>::Iteratore it=lista_ogg->begin(); it !=lista_ogg->end(); it++){
            if(nome==(*it)->get_name()){
                (*it)->addQuantita(list->at(2).toInt()); // check  const int su item
                check_name=false;
                std::cout<<"quantità: "<<(*it)->get_quantita()<<std::endl;
            }
        }
     }

    if(check_name==true){

        unsigned int quantita=list->at(2).toInt();
        std::string marca=list->at(3).toStdString();
        std::string modello=list->at(4).toStdString();
        unsigned int price=list->at(5).toInt();
        unsigned int realese_date=list->at(6).toInt();


        if(list->at(0).toStdString()=="Gpu"){
            std::string variante=list->at(7).toStdString();
            unsigned int vram=list->at(8).toInt();
            unsigned int gpu_clock=list->at(9).toInt();
            std::string type_ram=list->at(10).toStdString();

            Gpu* provv=new Gpu(nome,quantita,marca,modello,price,realese_date,variante,vram,gpu_clock,type_ram);
            Smartptr<Item> obj(provv);
            if(lista_ogg) add_compoenente(obj);
            else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}

        }
        else  if(list->at(0).toStdString()=="Cpu"){
            std::string serie=list->at(7).toStdString();
            double ghz=list->at(8).toInt(); //potrebbe essere anche double
            unsigned int core_number=list->at(9).toInt();
//            std::string intel_AMD=list->at(10).toStdString();
            std::string socket=list->at(10).toStdString();

            Cpu* provv=new Cpu(nome,quantita,marca,modello,price,realese_date,serie,ghz,core_number,socket);
            Smartptr<Item> obj(provv);
            if(lista_ogg) add_compoenente(obj);
            else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}

        }

        else  if(list->at(0).toStdString()=="Psu"){
            unsigned int watt=list->at(7).toInt();
            std::string rating=list->at(8).toStdString();
            std::string modularita=list->at(9).toStdString();

            Psu* provv=new Psu(nome,quantita,marca,modello,price,realese_date,watt,rating,modularita);
            Smartptr<Item> obj(provv);
            if(lista_ogg) add_compoenente(obj);
            else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}

        }


        else if(list->at(0).toStdString()=="Case"){
            std::string case_dim=list->at(7).toStdString();
            std::string mb_supported=list->at(8).toStdString();

            Case* provv=new Case(nome,quantita,marca,modello,price,realese_date,case_dim,mb_supported);
            Smartptr<Item> obj(provv);
            if(lista_ogg) add_compoenente(obj);
            else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}

        }

        else  if(list->at(0).toStdString()=="Ram"){
            std::string type_memory=list->at(7).toStdString();
            unsigned int capacity=list->at(8).toInt();
            unsigned int clock=list->at(9).toInt();
            unsigned int latency=list->at(10).toInt();
//            unsigned int num_per_pacco=list->at(11).toInt();

            Ram* provv=new Ram(nome,quantita,marca,modello,price,realese_date,type_memory,capacity,clock,latency);
            Smartptr<Item> obj(provv);
            if(lista_ogg) add_compoenente(obj);
            else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}

        }

        else  if(list->at(0).toStdString()=="Rom"){
            std::string type_memory=list->at(7).toStdString();
            unsigned int capacity=list->at(8).toInt();
            double mb_write=list->at(9).toDouble();
            double mb_read=list->at(10).toDouble();
            double size=list->at(11).toDouble();


            Rom* provv=new Rom(nome,quantita,marca,modello,price,realese_date,type_memory,capacity,mb_write,mb_read, size);
            Smartptr<Item> obj(provv);
            if(lista_ogg) add_compoenente(obj);
            else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}

        }


//        contenitore<Smartptr<Item>>* prova=get_lista();
//        for(contenitore<Smartptr<Item>>::Iteratore it=prova->begin(); it !=prova->end(); it++){
//            std::cout<<(*it)->get_name()<<std::endl;}
    }

    return check_name;
}

unsigned int Magazzino::get_quantita_item(std::string x) const{
    unsigned int quantita=0;
    for(contenitore<Smartptr<Item>>::Const_iteratore it=lista_ogg->inizio(); it !=lista_ogg->fine(); it++){
           if(x==(*it)->get_name()){
               quantita=(*it)->get_quantita();
               return quantita;
            }
    }

    return quantita;
}


