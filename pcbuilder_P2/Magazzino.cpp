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

void Magazzino::load_database() {          //da fare delete sui puntatori
    QFile file("/Users/giacomomason/Documents/GitHub/pcbuilderP2/pcbuilder_P2/database.xml");


    file.open(QIODevice::ReadOnly);
    QXmlStreamReader reader(&file);

    if (reader.readNextStartElement()) {
            if (reader.name() == "Magazzino"){

                while(reader.readNextStartElement()){

                      if(reader.name() == "Gpu"){
                        std::string nome;
                        unsigned int quantità;
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
                            else if(reader.name() == "quantità"){
                                 quantità=reader.readElementText().toInt();
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
                       Gpu* provv=new Gpu(nome,quantità,marca,modello,price,realese_date,variante,vram,gpu_clock,type_ram);
                       Smartptr<Item> obj(provv);
                       if(lista_ogg) add_compoenente(obj);
                       else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}
                    }
                     else if(reader.name() == "Cpu"){
                          std::string nome;
                          unsigned int quantità;
                          std::string marca;
                          std::string modello;
                          unsigned int price;
                          unsigned int realese_date;
                          std::string serie;
                          unsigned int ghz; //potrebbe essere anche double
                          unsigned int core_number;
                          std::string intel_AMD;
                          std::string socket;
                         while(reader.readNextStartElement()){

                              if(reader.name() == "nome"){
                                   nome=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "quantità"){
                                   quantità=reader.readElementText().toInt();
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
                                   ghz=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "core_number"){
                                   core_number=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "intel_AMD"){
                                   intel_AMD=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "socket"){
                                   socket=reader.readElementText().toStdString();
                              }

                         }

                         Cpu* provv=new Cpu(nome,quantità,marca,modello,price,realese_date,serie,ghz,core_number,intel_AMD,socket);
                         Smartptr<Item> obj(provv);
                         add_compoenente(obj);
                         if(lista_ogg) add_compoenente(obj);
                         else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}
                      }

                     else if(reader.name() == "Psu"){
                          std::string nome;
                          unsigned int quantità;
                          std::string marca;
                          std::string modello;
                          unsigned int price;
                          unsigned int realese_date;
                          unsigned int watt;
                          unsigned int rating;
                          std::string modularità;

                         while(reader.readNextStartElement()){

                              if(reader.name() == "nome"){
                                   nome=reader.readElementText().toStdString();
                              }
                              else if(reader.name() == "quantità"){
                                   quantità=reader.readElementText().toInt();
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
                                   rating=reader.readElementText().toInt();
                              }
                              else if(reader.name() == "modularità"){
                                   modularità=reader.readElementText().toStdString();
                              }


                         }

                         Psu* provv=new Psu(nome,quantità,marca,modello,price,realese_date,watt,rating,modularità);
                         Smartptr<Item> obj(provv);
                         if(lista_ogg) add_compoenente(obj);
                         else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}


                      }

                     else if(reader.name() == "SchedaMadre"){
                          std::string nome;
                          unsigned int quantità;
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
                              else if(reader.name() == "quantità"){
                                   quantità=reader.readElementText().toInt();
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

                         SchedaMadre* provv=new SchedaMadre(nome,quantità,marca,modello,price,realese_date,grandezza,socket_mb, sata_port, nvme_port);
                         Smartptr<Item> obj(provv);
                         add_compoenente(obj);
                         if(lista_ogg) add_compoenente(obj);
                         else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}
                      }

                     else if(reader.name() == "Case"){
                          std::string nome;
                          unsigned int quantità;
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
                              else if(reader.name() == "quantità"){
                                   quantità=reader.readElementText().toInt();
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

                         Case* provv=new Case(nome,quantità,marca,modello,price,realese_date,case_dim,mb_supported);
                         Smartptr<Item> obj(provv);
                         add_compoenente(obj);
                         if(lista_ogg) add_compoenente(obj);
                         else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}
                      }

                      else if(reader.name() == "Ram"){
                           std::string nome;
                           unsigned int quantità;
                           std::string marca;
                           std::string modello;
                           unsigned int price;
                           unsigned int realese_date;
                           std::string type_memory;
                           unsigned int capacity;
                           unsigned int clock;
                           unsigned int latency;
                           unsigned int num_per_pacco;


                          while(reader.readNextStartElement()){

                               if(reader.name() == "nome"){
                                    nome=reader.readElementText().toStdString();
                               }
                               else if(reader.name() == "quantità"){
                                    quantità=reader.readElementText().toInt();
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
                               else if(reader.name() == "num_per_pacco"){
                                    num_per_pacco=reader.readElementText().toInt();
                               }


                          }

                          Ram* provv=new Ram(nome,quantità,marca,modello,price,realese_date,type_memory,capacity,clock,latency,num_per_pacco);
                          Smartptr<Item> obj(provv);
                          add_compoenente(obj);
                          if(lista_ogg) add_compoenente(obj);
                          else{lista_ogg=new contenitore<Smartptr<Item>>(obj);}
                       }

                      else if(reader.name() == "Rom"){
                           std::string nome;
                           unsigned int quantità;
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
                               else if(reader.name() == "quantità"){
                                    quantità=reader.readElementText().toInt();
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

                               else if(reader.name() == "double"){
                                    size=reader.readElementText().toDouble(); // idem
                               }



                          }

                          Rom* provv=new Rom(nome,quantità,marca,modello,price,realese_date,type_memory,capacity,mb_write,mb_read, size);
                          Smartptr<Item> obj(provv);
                          add_compoenente(obj);
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











