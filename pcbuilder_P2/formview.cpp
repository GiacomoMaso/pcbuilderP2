#include "formview.h"

FormView::FormView(QWidget* parent) : QDialog(parent),v_layout(new QVBoxLayout(this)),form_layout(new QFormLayout()),h_layout(new QHBoxLayout()), val_maggiore_0(new QIntValidator(this)), double_maggiore_0(new QDoubleValidator(this)), return_button(new QPushButton("Indietro",this)), save_element_button(new QPushButton("Salva Elemento",this))
{

    setMinimumSize(800, 600);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    val_maggiore_0->setBottom(0);
    double_maggiore_0->setBottom(0);
    h_layout->addWidget(return_button);
    h_layout->addWidget(save_element_button);
    return_button->setMaximumSize(250,50);
    save_element_button->setMaximumSize(250,50);
    return_button->setMinimumSize(250,50);
    save_element_button->setMinimumSize(250,50);
    qDebug() << "parent is "<< form_layout->parent();
    v_layout->addLayout(form_layout);
    qDebug() << "parent is "<< form_layout->parent();
    v_layout->addLayout(h_layout);
    setAttribute(Qt::WA_DeleteOnClose);
//    set_style();

    connect(save_element_button, SIGNAL(clicked()), this, SLOT(salva_elemento()));

}


void FormView::build_form(std::string x){
//    if(form_layout) {
//        delete form_layout;
//    }
    tipo_ogg=x;

    nameLineEdit=new QLineEdit();
    quantitaLineEdit=new QLineEdit();
    nameLineEdit->setPlaceholderText("Inserire Nome");
    quantitaLineEdit->setPlaceholderText("Inserire la quantità");
    quantitaLineEdit->setValidator(val_maggiore_0);
    nameLineEdit->setMinimumSize(600,30);
    quantitaLineEdit->setMinimumSize(600,30);


    form_layout->addRow(tr("&Nome: "), nameLineEdit);
    form_layout->addRow(tr("&Quantità: "),quantitaLineEdit);
//    qDebug() << "parent is "<< nameLineEdit->parent();

    if(x=="Gpu"){
        marcaLineEdit=new QLineEdit();
        modelloLineEdit= new QLineEdit();
        priceLineEdit= new QLineEdit();
        realeseDateLineEdit=new QLineEdit();
        varianteLineEdit=new QLineEdit();
        vramLineEdit=new QLineEdit();
        gpuClockLineEdit=new QLineEdit();
        typeRamLineEdit=new QLineEdit();
        marcaLineEdit->setMinimumSize(600,30);
        modelloLineEdit->setMinimumSize(600,30);
        priceLineEdit->setMinimumSize(600,30);
        realeseDateLineEdit->setMinimumSize(600,30);
        varianteLineEdit->setMinimumSize(600,30);
        vramLineEdit->setMinimumSize(600,30);
        gpuClockLineEdit->setMinimumSize(600,30);
        typeRamLineEdit->setMinimumSize(600,30);
        realeseDateLineEdit->setValidator(new QIntValidator(1960,2020,this));
        vramLineEdit->setValidator(val_maggiore_0);
        gpuClockLineEdit->setValidator(val_maggiore_0);
        priceLineEdit->setValidator(val_maggiore_0);
        marcaLineEdit->setPlaceholderText("Inserire Marca Prodotto");
        modelloLineEdit->setPlaceholderText("Inserire Modello Prodotto");
        priceLineEdit->setPlaceholderText("Inserire il prezzo");
        realeseDateLineEdit->setPlaceholderText("Inserire anno di rilascio");
        varianteLineEdit->setPlaceholderText("Inserire Variante");
        vramLineEdit->setPlaceholderText("Inserire Vram in Gb");
        gpuClockLineEdit->setPlaceholderText("Inserire clock in MHz");
        typeRamLineEdit->setPlaceholderText("Inserire tipo della ram");
        form_layout->addRow(tr("&Marca: "),marcaLineEdit);
        form_layout->addRow(tr("&Modello: "),modelloLineEdit);
        form_layout->addRow(tr("&Prezzo: "),priceLineEdit);
        form_layout->addRow(tr("&Data rilascio: "),realeseDateLineEdit);
        form_layout->addRow(tr("&Variante: "),varianteLineEdit);
        form_layout->addRow(tr("&Vram: "),vramLineEdit);
        form_layout->addRow(tr("&Clock: "),gpuClockLineEdit);
        form_layout->addRow(tr("&Tipo ram: "),typeRamLineEdit);


    }

    else if(x=="Cpu"){
        marcaLineEdit=new QLineEdit();
        modelloLineEdit= new QLineEdit();
        priceLineEdit= new QLineEdit();
        realeseDateLineEdit=new QLineEdit();
        serieLineEdit=new QLineEdit();
        cpuGhzLineEdit=new QLineEdit();
        cpuCoreNumberLineEdit=new QLineEdit();
//        intelAMDLineEdit=new QLineEdit();
        socketLineEdit=new QLineEdit();
        marcaLineEdit->setMinimumSize(600,30);
        modelloLineEdit->setMinimumSize(600,30);
        priceLineEdit->setMinimumSize(600,30);
        realeseDateLineEdit->setMinimumSize(600,30);
        serieLineEdit->setMinimumSize(600,30);
        cpuGhzLineEdit->setMinimumSize(600,30);
        cpuCoreNumberLineEdit->setMinimumSize(600,30);
//        intelAMDLineEdit->setMinimumSize(600,30);
        socketLineEdit->setMinimumSize(600,30);
        marcaLineEdit->setPlaceholderText("Inserire Marca Prodotto");
        modelloLineEdit->setPlaceholderText("Inserire Modello Prodotto");
        priceLineEdit->setPlaceholderText("Inserire il prezzo");
        realeseDateLineEdit->setPlaceholderText("Inserire anno di rilascio");
        serieLineEdit->setPlaceholderText("Inserie serie processore");
        cpuGhzLineEdit->setPlaceholderText("Inserire ghz processore");
        cpuCoreNumberLineEdit->setPlaceholderText("inserire numero core processore");
//        intelAMDLineEdit->setPlaceholderText("Inserire se amd o intel");
        socketLineEdit->setPlaceholderText("Inserire tipo di socket");
        priceLineEdit->setValidator(val_maggiore_0);
        realeseDateLineEdit->setValidator(new QIntValidator(1960,2020,this));
        cpuGhzLineEdit->setValidator(double_maggiore_0);
        cpuCoreNumberLineEdit->setValidator(val_maggiore_0);

        form_layout->addRow(tr("&Marca: "),marcaLineEdit);
        form_layout->addRow(tr("&Modello: "),modelloLineEdit);
        form_layout->addRow(tr("&Prezzo: "),priceLineEdit);
        form_layout->addRow(tr("&Data rilascio: "),realeseDateLineEdit);
        form_layout->addRow(tr("&Serie: "),serieLineEdit);
        form_layout->addRow(tr("&GHZ: "),cpuGhzLineEdit);
        form_layout->addRow(tr("&Numero di core: "),cpuCoreNumberLineEdit);
//        form_layout->addRow(tr("&Intel/AMD: "),intelAMDLineEdit);
        form_layout->addRow(tr("&Socket: "),socketLineEdit);



    }

    else if(x=="Psu"){
        marcaLineEdit=new QLineEdit();
        modelloLineEdit= new QLineEdit();
        priceLineEdit= new QLineEdit();
        realeseDateLineEdit=new QLineEdit();
        wattLineEdit=new QLineEdit();
        ratingLineEdit=new QLineEdit();
        modularitaLineEdit=new QLineEdit();
        marcaLineEdit->setMinimumSize(600,30);
        modelloLineEdit->setMinimumSize(600,30);
        priceLineEdit->setMinimumSize(600,30);
        realeseDateLineEdit->setMinimumSize(600,30);
        wattLineEdit->setMinimumSize(600,30);
        ratingLineEdit->setMinimumSize(600,30);
        modularitaLineEdit->setMinimumSize(600,30);

        realeseDateLineEdit->setValidator(new QIntValidator(1960,2020,this));
        wattLineEdit->setValidator(val_maggiore_0);
        marcaLineEdit->setPlaceholderText("Inserire Marca Prodotto");
        modelloLineEdit->setPlaceholderText("Inserire Modello Prodotto");
        priceLineEdit->setPlaceholderText("Inserire il prezzo");
        realeseDateLineEdit->setPlaceholderText("Inserire anno di rilascio");
        wattLineEdit->setPlaceholderText("Inserire i watt del alimentatore");
        ratingLineEdit->setPlaceholderText("inserire il rating dell'alimentatore esBronze ");
        modularitaLineEdit->setPlaceholderText("Inserire la modularità se presente");

        form_layout->addRow(tr("&Marca: "),marcaLineEdit);
        form_layout->addRow(tr("&Modello: "),modelloLineEdit);
        form_layout->addRow(tr("&Prezzo: "),priceLineEdit);
        form_layout->addRow(tr("&Data rilascio: "),realeseDateLineEdit);
        form_layout->addRow(tr("&Watt: "),wattLineEdit);
        form_layout->addRow(tr("&Rating: "),ratingLineEdit);
        form_layout->addRow(tr("&Modularità: "),modularitaLineEdit);
    }

    else if(x=="Case"){
        marcaLineEdit=new QLineEdit();
        modelloLineEdit= new QLineEdit();
        priceLineEdit= new QLineEdit();
        realeseDateLineEdit=new QLineEdit();
        caseDimLineEdit=new QLineEdit();
        mbSupportedLineEdit=new QLineEdit();
        marcaLineEdit->setMinimumSize(600,30);
        modelloLineEdit->setMinimumSize(600,30);
        priceLineEdit->setMinimumSize(600,30);
        realeseDateLineEdit->setMinimumSize(600,30);
        mbSupportedLineEdit->setMinimumSize(600,30);
        caseDimLineEdit->setMinimumSize(600,30);
        priceLineEdit->setValidator(val_maggiore_0);
        realeseDateLineEdit->setValidator(new QIntValidator(1960,2020,this));
        marcaLineEdit->setPlaceholderText("Inserire Marca Prodotto");
        modelloLineEdit->setPlaceholderText("Inserire Modello Prodotto");
        priceLineEdit->setPlaceholderText("Inserire il prezzo");
        realeseDateLineEdit->setPlaceholderText("Inserire anno di rilascio");
        caseDimLineEdit->setPlaceholderText("Inserire dimensione case es. FullTower");
        mbSupportedLineEdit->setPlaceholderText("Inserire scheda madre supportata es ATX");

        form_layout->addRow(tr("&Marca: "),marcaLineEdit);
        form_layout->addRow(tr("&Modello: "),modelloLineEdit);
        form_layout->addRow(tr("&Prezzo: "),priceLineEdit);
        form_layout->addRow(tr("&Data rilascio: "),realeseDateLineEdit);
        form_layout->addRow(tr("&Dimensioni Case: "),caseDimLineEdit);
        form_layout->addRow(tr("&Mb supportata: "),mbSupportedLineEdit);

    }

    else if(x=="SchedaMadre"){
        marcaLineEdit=new QLineEdit();
        modelloLineEdit= new QLineEdit();
        priceLineEdit= new QLineEdit();
        realeseDateLineEdit=new QLineEdit();
        grandezzaLineEdit=new QLineEdit();
        socketMbLineEdit=new QLineEdit();
        sataPortLineEdit=new QLineEdit();
        nvmePortLineEdit=new QLineEdit();
        marcaLineEdit->setMinimumSize(600,30);
        modelloLineEdit->setMinimumSize(600,30);
        priceLineEdit->setMinimumSize(600,30);
        realeseDateLineEdit->setMinimumSize(600,30);
        grandezzaLineEdit->setMinimumSize(600,30);
        socketMbLineEdit->setMinimumSize(600,30);
        sataPortLineEdit->setMinimumSize(600,30);
        nvmePortLineEdit->setMinimumSize(600,30);

        priceLineEdit->setValidator(val_maggiore_0);
        realeseDateLineEdit->setValidator(new QIntValidator(1960,2020,this));
        sataPortLineEdit->setValidator(val_maggiore_0);
        nvmePortLineEdit->setValidator(val_maggiore_0);


        marcaLineEdit->setPlaceholderText("Inserire Marca Prodotto");
        modelloLineEdit->setPlaceholderText("Inserire Modello Prodotto");
        priceLineEdit->setPlaceholderText("Inserire il prezzo");
        realeseDateLineEdit->setPlaceholderText("Inserire anno di rilascio");
        grandezzaLineEdit->setPlaceholderText("Inserire formato schedamadre es. ATX");
        socketMbLineEdit->setPlaceholderText("Inserire tipo socket accettato dalla scheda madre");
        nvmePortLineEdit->setPlaceholderText("Inserire numero nvme port");

        form_layout->addRow(tr("&Marca: "),marcaLineEdit);
        form_layout->addRow(tr("&Modello: "),modelloLineEdit);
        form_layout->addRow(tr("&Prezzo: "),priceLineEdit);
        form_layout->addRow(tr("&Data rilascio: "),realeseDateLineEdit);
        form_layout->addRow(tr("&Formato: "),grandezzaLineEdit);
        form_layout->addRow(tr("&Socket accettato: "),socketMbLineEdit);
        form_layout->addRow(tr("&N Sata port: "),sataPortLineEdit);
        form_layout->addRow(tr("&N NVME port: "),nvmePortLineEdit);


    }

    else if(x=="Ram"){
        marcaLineEdit=new QLineEdit();
        modelloLineEdit= new QLineEdit();
        priceLineEdit= new QLineEdit();
        realeseDateLineEdit=new QLineEdit();
        typeMemoryLineEdit=new QLineEdit();
        capacityLineEdit=new QLineEdit();
        clockLineEdit= new QLineEdit();
        latencyLineEdit=new QLineEdit();
//        numPerPaccoLineEdit=new QLineEdit();
        marcaLineEdit->setMinimumSize(600,30);
        modelloLineEdit->setMinimumSize(600,30);
        priceLineEdit->setMinimumSize(600,30);
        realeseDateLineEdit->setMinimumSize(600,30);
        typeMemoryLineEdit->setMinimumSize(600,30);
        capacityLineEdit->setMinimumSize(600,30);
        clockLineEdit->setMinimumSize(600,30);
        latencyLineEdit->setMinimumSize(600,30);
//        numPerPaccoLineEdit->setMinimumSize(600,30);

        priceLineEdit->setValidator(val_maggiore_0);
        realeseDateLineEdit->setValidator(new QIntValidator(1960,2020,this));
        capacityLineEdit->setValidator(val_maggiore_0);
        clockLineEdit->setValidator(val_maggiore_0);
        latencyLineEdit->setValidator(val_maggiore_0);
//        numPerPaccoLineEdit->setValidator(val_maggiore_0);



        marcaLineEdit->setPlaceholderText("Inserire Marca Prodotto");
        modelloLineEdit->setPlaceholderText("Inserire Modello Prodotto");
        priceLineEdit->setPlaceholderText("Inserire il prezzo");
        realeseDateLineEdit->setPlaceholderText("Inserire anno di rilascio");
        typeMemoryLineEdit->setPlaceholderText("Inserire il tipo di memoria");
        capacityLineEdit->setPlaceholderText("Inserire la capacità della RAM");
        clockLineEdit->setPlaceholderText("Inserire il clock delle RAM");
        latencyLineEdit->setPlaceholderText("Inserire la Latenza es CL16");
//        numPerPaccoLineEdit->setPlaceholderText("Inserire il numero di RAM presenti nel pacco");



        form_layout->addRow(tr("&Marca: "),marcaLineEdit);
        form_layout->addRow(tr("&Modello: "),modelloLineEdit);
        form_layout->addRow(tr("&Prezzo: "),priceLineEdit);
        form_layout->addRow(tr("&Data rilascio: "),realeseDateLineEdit);
        form_layout->addRow(tr("&Tipo memoria: "),typeMemoryLineEdit);
        form_layout->addRow(tr("&Capacità: "),capacityLineEdit);
        form_layout->addRow(tr("&Clock: "),clockLineEdit);
        form_layout->addRow(tr("&Latency: "),latencyLineEdit);
//        form_layout->addRow(tr("&Numero per Pacco: "),numPerPaccoLineEdit);



    }


    else if(x=="Rom"){
        marcaLineEdit=new QLineEdit();
        modelloLineEdit= new QLineEdit();
        priceLineEdit= new QLineEdit();
        realeseDateLineEdit=new QLineEdit();
        typeMemoryLineEdit=new QLineEdit();
        capacityLineEdit=new QLineEdit();
        mbWriteLineEdit=new QLineEdit();
        mbReadLineEdit= new QLineEdit();
        sizeLineEdit= new QLineEdit();
        marcaLineEdit->setMinimumSize(600,30);
        modelloLineEdit->setMinimumSize(600,30);
        priceLineEdit->setMinimumSize(600,30);
        realeseDateLineEdit->setMinimumSize(600,30);
        typeMemoryLineEdit->setMinimumSize(600,30);
        capacityLineEdit->setMinimumSize(600,30);
        mbWriteLineEdit->setMinimumSize(600,30);
        mbReadLineEdit->setMinimumSize(600,30);
        sizeLineEdit->setMinimumSize(600,30);

        priceLineEdit->setValidator(val_maggiore_0);
        realeseDateLineEdit->setValidator(new QIntValidator(1960,2020,this));
        capacityLineEdit->setValidator(val_maggiore_0);
        mbWriteLineEdit->setValidator(double_maggiore_0);
        mbReadLineEdit->setValidator(double_maggiore_0);

        marcaLineEdit->setPlaceholderText("Inserire Marca Prodotto");
        modelloLineEdit->setPlaceholderText("Inserire Modello Prodotto");
        priceLineEdit->setPlaceholderText("Inserire il prezzo");
        realeseDateLineEdit->setPlaceholderText("Inserire anno di rilascio");
        typeMemoryLineEdit->setPlaceholderText("Inserire il tipo di memoria");
        capacityLineEdit->setPlaceholderText("Inserire la capacità della RAM");
        mbWriteLineEdit->setPlaceholderText("Inserire Mb/s in scrittura");
        mbReadLineEdit->setPlaceholderText("Inserire Mb/s in lettura");
        sizeLineEdit->setPlaceholderText("Inserire grandezza memoria");



        form_layout->addRow(tr("&Marca: "),marcaLineEdit);
        form_layout->addRow(tr("&Modello: "),modelloLineEdit);
        form_layout->addRow(tr("&Prezzo: "),priceLineEdit);
        form_layout->addRow(tr("&Data rilascio: "),realeseDateLineEdit);
        form_layout->addRow(tr("&Tipo memoria: "),typeMemoryLineEdit);
        form_layout->addRow(tr("&Capacità: "),capacityLineEdit);
        form_layout->addRow(tr("&MbWrite "),mbWriteLineEdit);
        form_layout->addRow(tr("&MbRead: "),mbReadLineEdit);
        form_layout->addRow(tr("&Formato: "),sizeLineEdit);



    }



//    form_layout->addRow(tr("&Email:"), quantitaLineEdit);
//    form_layout->addRow(tr("&Age:"), marcaLineEdit);
}

//void FormView::set_style () {
//    QFile styleFile(":/style_folder/style.css");
//       if(styleFile.open(QIODevice::ReadOnly))
//       {
//           QTextStream textStream(&styleFile);
//           QString styleSheet = textStream.readAll();
//           styleFile.close();
//           setStyleSheet(styleSheet);
//       }
//    qDebug()<<"CIAO"<<styleFile.open(QIODevice::ReadOnly);

//}

void FormView::salva_elemento(){


    if(tipo_ogg=="Gpu"){
        if(nameLineEdit->text()=="" || quantitaLineEdit->text()=="" || marcaLineEdit->text()=="" || modelloLineEdit->text()=="" || priceLineEdit->text()==""|| realeseDateLineEdit->text()=="" || varianteLineEdit->text()=="" || vramLineEdit->text()=="" || gpuClockLineEdit->text()=="" ||typeRamLineEdit->text()==""){
            QMessageBox error;
            error.critical(this,"Mancano alcuni campi", "Per favore compilare tutto il form");}
        else {
            QStringList* list=new QStringList();
            list->push_back(QString::fromStdString(tipo_ogg));
            list->push_back(nameLineEdit->text());
            list->push_back(quantitaLineEdit->text());
            list->push_back(marcaLineEdit->text());
            list->push_back(modelloLineEdit->text());
            list->push_back(priceLineEdit->text());
            list->push_back(realeseDateLineEdit->text());
            list->push_back(varianteLineEdit->text());
            list->push_back(vramLineEdit->text());
            list->push_back(gpuClockLineEdit->text());
            list->push_back(typeRamLineEdit->text());

            emit add_item(list);
        }
    }

    else if(tipo_ogg=="Cpu"){
        if(nameLineEdit->text()=="" || quantitaLineEdit->text()=="" || marcaLineEdit->text()=="" || modelloLineEdit->text()=="" || priceLineEdit->text()==""|| realeseDateLineEdit->text()=="" || serieLineEdit->text()=="" || cpuGhzLineEdit->text()=="" || cpuCoreNumberLineEdit->text()=="" ||socketLineEdit->text()=="") {
            QMessageBox error;
            error.critical(this,"Mancano alcuni campi", "Per favore compilare tutto il form");}
        else{
            QStringList* list=new QStringList();
            list->push_back(QString::fromStdString(tipo_ogg));
            list->push_back(nameLineEdit->text());
            list->push_back(quantitaLineEdit->text());
            list->push_back(marcaLineEdit->text());
            list->push_back(modelloLineEdit->text());
            list->push_back(priceLineEdit->text());
            list->push_back(realeseDateLineEdit->text());
            list->push_back(serieLineEdit->text());
            list->push_back(cpuGhzLineEdit->text());
            list->push_back(cpuCoreNumberLineEdit->text());
//            list->push_back(intelAMDLineEdit->text());
            list->push_back(socketLineEdit->text());

            emit add_item(list);

        }
    }

    else if(tipo_ogg=="Psu"){
        if(nameLineEdit->text()=="" || quantitaLineEdit->text()=="" || marcaLineEdit->text()=="" || modelloLineEdit->text()=="" || priceLineEdit->text()==""|| realeseDateLineEdit->text()=="" || wattLineEdit->text()=="" || ratingLineEdit->text()=="" || modularitaLineEdit->text()==""){
            QMessageBox error;
            error.critical(this,"Mancano alcuni campi", "Per favore compilare tutto il form");}
        else{
            QStringList* list=new QStringList();
            list->push_back(QString::fromStdString(tipo_ogg));
            list->push_back(nameLineEdit->text());
            list->push_back(quantitaLineEdit->text());
            list->push_back(marcaLineEdit->text());
            list->push_back(modelloLineEdit->text());
            list->push_back(priceLineEdit->text());
            list->push_back(realeseDateLineEdit->text());
            list->push_back(wattLineEdit->text());
            list->push_back(ratingLineEdit->text());
            list->push_back(modularitaLineEdit->text());

            emit add_item(list);

        }
    }

    else if(tipo_ogg=="Case"){
        if(nameLineEdit->text()=="" || quantitaLineEdit->text()=="" || marcaLineEdit->text()=="" || modelloLineEdit->text()=="" || priceLineEdit->text()==""|| realeseDateLineEdit->text()=="" || caseDimLineEdit->text()=="" || mbSupportedLineEdit->text()==""){
            QMessageBox error;
            error.critical(this,"Mancano alcuni campi", "Per favore compilare tutto il form");}
        else{
            QStringList* list=new QStringList();
            list->push_back(QString::fromStdString(tipo_ogg));
            list->push_back(nameLineEdit->text());
            list->push_back(quantitaLineEdit->text());
            list->push_back(marcaLineEdit->text());
            list->push_back(modelloLineEdit->text());
            list->push_back(priceLineEdit->text());
            list->push_back(realeseDateLineEdit->text());
            list->push_back(caseDimLineEdit->text());
            list->push_back(mbSupportedLineEdit->text());


            emit add_item(list);

        }
    }

    else if(tipo_ogg=="Ram"){
        if(nameLineEdit->text()=="" || quantitaLineEdit->text()=="" || marcaLineEdit->text()=="" || modelloLineEdit->text()=="" || priceLineEdit->text()==""|| realeseDateLineEdit->text()=="" || typeMemoryLineEdit->text()=="" || capacityLineEdit->text()=="" || clockLineEdit->text()=="" || latencyLineEdit->text()=="" ){
            QMessageBox error;
            error.critical(this,"Mancano alcuni campi", "Per favore compilare tutto il form");}
        else{
            QStringList* list=new QStringList();
            list->push_back(QString::fromStdString(tipo_ogg));
            list->push_back(nameLineEdit->text());
            list->push_back(quantitaLineEdit->text());
            list->push_back(marcaLineEdit->text());
            list->push_back(modelloLineEdit->text());
            list->push_back(priceLineEdit->text());
            list->push_back(realeseDateLineEdit->text());
            list->push_back(typeMemoryLineEdit->text());
            list->push_back(capacityLineEdit->text());
            list->push_back(clockLineEdit->text());
            list->push_back(latencyLineEdit->text());
//            list->push_back(numPerPaccoLineEdit->text());
            list->push_back(capacityLineEdit->text());


            emit add_item(list);

        }
    }

    else if(tipo_ogg=="Rom"){
        if(nameLineEdit->text()=="" || quantitaLineEdit->text()=="" || marcaLineEdit->text()=="" || modelloLineEdit->text()=="" || priceLineEdit->text()==""|| realeseDateLineEdit->text()=="" || typeMemoryLineEdit->text()=="" || capacityLineEdit->text()=="" || mbWriteLineEdit->text()=="" || mbReadLineEdit->text()=="" || sizeLineEdit->text()==""){
            QMessageBox error;
            error.critical(this,"Mancano alcuni campi", "Per favore compilare tutto il form");}
        else{
            QStringList* list=new QStringList();
            list->push_back(QString::fromStdString(tipo_ogg));
            list->push_back(nameLineEdit->text());
            list->push_back(quantitaLineEdit->text());
            list->push_back(marcaLineEdit->text());
            list->push_back(modelloLineEdit->text());
            list->push_back(priceLineEdit->text());
            list->push_back(realeseDateLineEdit->text());
            list->push_back(typeMemoryLineEdit->text());
            list->push_back(capacityLineEdit->text());
            list->push_back(mbWriteLineEdit->text());
            list->push_back(mbReadLineEdit->text());
            list->push_back(sizeLineEdit->text());




            emit add_item(list);

        }
    }

    else if(tipo_ogg=="SchedaMadre"){
        if(nameLineEdit->text()=="" || quantitaLineEdit->text()=="" || marcaLineEdit->text()=="" || modelloLineEdit->text()=="" || priceLineEdit->text()==""|| realeseDateLineEdit->text()=="" || grandezzaLineEdit->text()=="" || socketMbLineEdit->text()=="" || sataPortLineEdit->text()=="" || nvmePortLineEdit->text()==""){
            QMessageBox error;
            error.critical(this,"Mancano alcuni campi", "Per favore compilare tutto il form");}
        else{
            QStringList* list=new QStringList();
            list->push_back(QString::fromStdString(tipo_ogg));
            list->push_back(nameLineEdit->text());
            list->push_back(quantitaLineEdit->text());
            list->push_back(marcaLineEdit->text());
            list->push_back(modelloLineEdit->text());
            list->push_back(priceLineEdit->text());
            list->push_back(realeseDateLineEdit->text());
            list->push_back(grandezzaLineEdit->text());
            list->push_back(socketMbLineEdit->text());
            list->push_back(sataPortLineEdit->text());
            list->push_back(nvmePortLineEdit->text());


            emit add_item(list);

        }
    }
}

void FormView::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}


