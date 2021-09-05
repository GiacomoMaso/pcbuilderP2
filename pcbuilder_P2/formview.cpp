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
    set_style();

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
        varianteLineEdit=new QLineEdit();
        vramLineEdit=new QLineEdit();
        gpuClockLineEdit=new QLineEdit();
        typeRamLineEdit=new QLineEdit();
        marcaLineEdit->setMinimumSize(600,30);
        modelloLineEdit->setMinimumSize(600,30);
        priceLineEdit->setMinimumSize(600,30);
        varianteLineEdit->setMinimumSize(600,30);
        vramLineEdit->setMinimumSize(600,30);
        gpuClockLineEdit->setMinimumSize(600,30);
        typeRamLineEdit->setMinimumSize(600,30);
        vramLineEdit->setValidator(val_maggiore_0);
        gpuClockLineEdit->setValidator(val_maggiore_0);
        priceLineEdit->setValidator(val_maggiore_0);
        marcaLineEdit->setPlaceholderText("Inserire Marca Prodotto");
        modelloLineEdit->setPlaceholderText("Inserire Modello Prodotto");
        priceLineEdit->setPlaceholderText("Inserire il prezzo");
        varianteLineEdit->setPlaceholderText("Inserire Variante");
        vramLineEdit->setPlaceholderText("Inserire Vram in Gb");
        gpuClockLineEdit->setPlaceholderText("Inserire clock in MHz");
        typeRamLineEdit->setPlaceholderText("Inserire tipo della ram");
        form_layout->addRow(tr("&Marca: "),marcaLineEdit);
        form_layout->addRow(tr("&Modello: "),modelloLineEdit);
        form_layout->addRow(tr("&Prezzo: "),priceLineEdit);
        form_layout->addRow(tr("&Variante: "),varianteLineEdit);
        form_layout->addRow(tr("&Vram: "),vramLineEdit);
        form_layout->addRow(tr("&Clock: "),gpuClockLineEdit);
        form_layout->addRow(tr("&Tipo ram: "),typeRamLineEdit);


    }

    else if(x=="Cpu"){
        marcaLineEdit=new QLineEdit();
        modelloLineEdit= new QLineEdit();
        priceLineEdit= new QLineEdit();
        serieLineEdit=new QLineEdit();
        cpuGhzLineEdit=new QLineEdit();
        cpuCoreNumberLineEdit=new QLineEdit();
        intelAMDLineEdit=new QLineEdit();
        socketLineEdit=new QLineEdit();
        marcaLineEdit->setPlaceholderText("Inserire Marca Prodotto");
        modelloLineEdit->setPlaceholderText("Inserire Modello Prodotto");
        priceLineEdit->setPlaceholderText("Inserire il prezzo");
        serieLineEdit->setPlaceholderText("Inserie serie processore");
        cpuGhzLineEdit->setPlaceholderText("Inserire ghz processore");
        cpuCoreNumberLineEdit->setPlaceholderText("inserire numero core processore");
        intelAMDLineEdit->setPlaceholderText("Inserire se amd o intel");
        socketLineEdit->setPlaceholderText("Inserire tipo di socket");
        priceLineEdit->setValidator(val_maggiore_0);
        cpuGhzLineEdit->setValidator(val_maggiore_0);
        cpuCoreNumberLineEdit->setValidator(val_maggiore_0);

        form_layout->addRow(tr("&Marca: "),marcaLineEdit);
        form_layout->addRow(tr("&Modello: "),modelloLineEdit);
        form_layout->addRow(tr("&Prezzo: "),priceLineEdit);
        form_layout->addRow(tr("&Serie: "),serieLineEdit);
        form_layout->addRow(tr("&GHZ: "),cpuGhzLineEdit);
        form_layout->addRow(tr("&Numero di core: "),cpuCoreNumberLineEdit);
        form_layout->addRow(tr("&Intel/AMD: "),intelAMDLineEdit);
        form_layout->addRow(tr("&Socket: "),socketLineEdit);



    }

    else if(x=="Psu"){
        marcaLineEdit=new QLineEdit();
        modelloLineEdit= new QLineEdit();
        priceLineEdit= new QLineEdit();
        wattLineEdit=new QLineEdit();
        ratingLineEdit=new QLineEdit();
        modularitaLineEdit=new QLineEdit();
        priceLineEdit->setValidator(val_maggiore_0);
        wattLineEdit->setValidator(val_maggiore_0);
        ratingLineEdit->setValidator(new QIntValidator(0,100,this));
        marcaLineEdit->setPlaceholderText("Inserire Marca Prodotto");
        modelloLineEdit->setPlaceholderText("Inserire Modello Prodotto");
        priceLineEdit->setPlaceholderText("Inserire il prezzo");
        wattLineEdit->setPlaceholderText("Inserire i watt del alimentatore");
        ratingLineEdit->setPlaceholderText("inserire in rating da 0 a 100 dell'alimentatore");
        modularitaLineEdit->setPlaceholderText("Inserire la modularità se presente");

        form_layout->addRow(tr("&Marca: "),marcaLineEdit);
        form_layout->addRow(tr("&Modello: "),modelloLineEdit);
        form_layout->addRow(tr("&Prezzo: "),priceLineEdit);
        form_layout->addRow(tr("&Watt: "),wattLineEdit);
        form_layout->addRow(tr("&Rating: "),ratingLineEdit);
        form_layout->addRow(tr("&Modularità: "),modularitaLineEdit);
    }

    else if(x=="Case"){
        marcaLineEdit=new QLineEdit();
        modelloLineEdit= new QLineEdit();
        priceLineEdit= new QLineEdit();
        caseDimLineEdit=new QLineEdit();
        mbSupportedLineEdit=new QLineEdit();
        priceLineEdit->setValidator(val_maggiore_0);
        marcaLineEdit->setPlaceholderText("Inserire Marca Prodotto");
        modelloLineEdit->setPlaceholderText("Inserire Modello Prodotto");
        priceLineEdit->setPlaceholderText("Inserire il prezzo");
        caseDimLineEdit->setPlaceholderText("Inserire dimensione case es. FullTower");
        mbSupportedLineEdit->setPlaceholderText("Inserire scheda madre supportata es ATX");

        form_layout->addRow(tr("&Marca: "),marcaLineEdit);
        form_layout->addRow(tr("&Modello: "),modelloLineEdit);
        form_layout->addRow(tr("&Prezzo: "),priceLineEdit);
        form_layout->addRow(tr("&Dimensioni Case: "),caseDimLineEdit);
        form_layout->addRow(tr("&Mb supportata: "),mbSupportedLineEdit);

    }

    else if(x=="SchedaMadre"){
        marcaLineEdit=new QLineEdit();
        modelloLineEdit= new QLineEdit();
        priceLineEdit= new QLineEdit();
        grandezzaLineEdit=new QLineEdit();
        socketMbLineEdit=new QLineEdit();
        sataPortLineEdit=new QLineEdit();
        nvmePortLineEdit=new QLineEdit();

        priceLineEdit->setValidator(val_maggiore_0);
        sataPortLineEdit->setValidator(val_maggiore_0);
        nvmePortLineEdit->setValidator(val_maggiore_0);


        marcaLineEdit->setPlaceholderText("Inserire Marca Prodotto");
        modelloLineEdit->setPlaceholderText("Inserire Modello Prodotto");
        priceLineEdit->setPlaceholderText("Inserire il prezzo");
        grandezzaLineEdit->setPlaceholderText("Inserire formato schedamadre es. ATX");
        socketMbLineEdit->setPlaceholderText("Inserire tipo socket accettato dalla scheda madre");
        nvmePortLineEdit->setPlaceholderText("Inserire numero nvme port");

        form_layout->addRow(tr("&Marca: "),marcaLineEdit);
        form_layout->addRow(tr("&Modello: "),modelloLineEdit);
        form_layout->addRow(tr("&Prezzo: "),priceLineEdit);
        form_layout->addRow(tr("&Formato: "),grandezzaLineEdit);
        form_layout->addRow(tr("&Socket accettato: "),socketMbLineEdit);
        form_layout->addRow(tr("&N Sata port: "),sataPortLineEdit);
        form_layout->addRow(tr("&N NVME port: "),nvmePortLineEdit);


    }

    else if(x=="Ram"){
        marcaLineEdit=new QLineEdit();
        modelloLineEdit= new QLineEdit();
        priceLineEdit= new QLineEdit();
        typeMemoryLineEdit=new QLineEdit();
        capacityLineEdit=new QLineEdit();
        clockLineEdit= new QLineEdit();
        latencyLineEdit=new QLineEdit();
        numPerPaccoLineEdit=new QLineEdit();

        priceLineEdit->setValidator(val_maggiore_0);
        capacityLineEdit->setValidator(val_maggiore_0);
        clockLineEdit->setValidator(val_maggiore_0);
        latencyLineEdit->setValidator(val_maggiore_0);
        numPerPaccoLineEdit->setValidator(val_maggiore_0);



        marcaLineEdit->setPlaceholderText("Inserire Marca Prodotto");
        modelloLineEdit->setPlaceholderText("Inserire Modello Prodotto");
        priceLineEdit->setPlaceholderText("Inserire il prezzo");
        typeMemoryLineEdit->setPlaceholderText("Inserire il tipo di memoria");
        capacityLineEdit->setPlaceholderText("Inserire la capacità della RAM");
        clockLineEdit->setPlaceholderText("Inserire il clock delle RAM");
        latencyLineEdit->setPlaceholderText("Inserire la Latenza es CL16");
        numPerPaccoLineEdit->setPlaceholderText("Inserire il numero di RAM presenti nel pacco");



        form_layout->addRow(tr("&Marca: "),marcaLineEdit);
        form_layout->addRow(tr("&Modello: "),modelloLineEdit);
        form_layout->addRow(tr("&Prezzo: "),priceLineEdit);
        form_layout->addRow(tr("&Tipo memoria: "),typeMemoryLineEdit);
        form_layout->addRow(tr("&Capacità: "),capacityLineEdit);
        form_layout->addRow(tr("&Clock: "),clockLineEdit);
        form_layout->addRow(tr("&Latency: "),latencyLineEdit);
        form_layout->addRow(tr("&Numero per Pacco: "),numPerPaccoLineEdit);



    }


    else if(x=="Rom"){
        marcaLineEdit=new QLineEdit();
        modelloLineEdit= new QLineEdit();
        priceLineEdit= new QLineEdit();
        typeMemoryLineEdit=new QLineEdit();
        capacityLineEdit=new QLineEdit();
        mbWriteLineEdit=new QLineEdit();
        mbReadLineEdit= new QLineEdit();
        sizeLineEdit= new QLineEdit();

        priceLineEdit->setValidator(val_maggiore_0);
        capacityLineEdit->setValidator(val_maggiore_0);
        mbWriteLineEdit->setValidator(double_maggiore_0);
        mbReadLineEdit->setValidator(double_maggiore_0);

        marcaLineEdit->setPlaceholderText("Inserire Marca Prodotto");
        modelloLineEdit->setPlaceholderText("Inserire Modello Prodotto");
        priceLineEdit->setPlaceholderText("Inserire il prezzo");
        typeMemoryLineEdit->setPlaceholderText("Inserire il tipo di memoria");
        capacityLineEdit->setPlaceholderText("Inserire la capacità della RAM");
        mbWriteLineEdit->setPlaceholderText("Inserire Mb/s in scrittura");
        mbReadLineEdit->setPlaceholderText("Inserire Mb/s in lettura");
        sizeLineEdit->setPlaceholderText("Inserire grandezza memoria");



        form_layout->addRow(tr("&Marca: "),marcaLineEdit);
        form_layout->addRow(tr("&Modello: "),modelloLineEdit);
        form_layout->addRow(tr("&Prezzo: "),priceLineEdit);
        form_layout->addRow(tr("&Tipo memoria: "),typeMemoryLineEdit);
        form_layout->addRow(tr("&Capacità: "),capacityLineEdit);
        form_layout->addRow(tr("&MbWrite "),mbWriteLineEdit);
        form_layout->addRow(tr("&MbRead: "),mbReadLineEdit);
        form_layout->addRow(tr("&Formato: "),sizeLineEdit);



    }



//    form_layout->addRow(tr("&Email:"), quantitaLineEdit);
//    form_layout->addRow(tr("&Age:"), marcaLineEdit);
}

void FormView::set_style () {
    QFile styleFile(":/style_folder/style.css");
       if(styleFile.open(QIODevice::ReadOnly))
       {
           QTextStream textStream(&styleFile);
           QString styleSheet = textStream.readAll();
           styleFile.close();
           setStyleSheet(styleSheet);
       }
    qDebug()<<"CIAO"<<styleFile.open(QIODevice::ReadOnly);

}

void FormView::salva_elemento(){
    if(nameLineEdit->text()=="" || quantitaLineEdit->text()=="" || marcaLineEdit->text()=="" || modelloLineEdit->text()=="" || priceLineEdit->text()==""){
        QMessageBox error;
        error.critical(this,"Mancano alcuni campi", "Per favore compilare tutto il form");
    }

    if(tipo_ogg=="Gpu"){
        if(varianteLineEdit->text()=="" || vramLineEdit->text()=="" || gpuClockLineEdit->text()=="" ||typeRamLineEdit->text()==""){
            QMessageBox error;
            error.critical(this,"Mancano alcuni campi", "Per favore compilare tutto il form");}
    }
}


