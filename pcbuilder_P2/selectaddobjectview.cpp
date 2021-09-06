#include "selectaddobjectview.h"

SelectAddObjectView::SelectAddObjectView() : v_layout(new QVBoxLayout(this)),grid_layout(new QGridLayout()),  gpu_button(new QPushButton("Gpu",this)), cpu_button(new QPushButton("Cpu",this)), psu_button(new QPushButton("Alimentatore",this)), ram_button(new QPushButton("Ram",this)), rom_button(new QPushButton("Rom",this)), case_button(new QPushButton("Case",this)), schedamadre_button(new QPushButton("Scheda Madre",this)), title(new QLabel(this))
{
    setMinimumSize(800, 600);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    QString s_title="Seleziona il tipo di oggetto da aggiungere al magazzino";

    title->setText(s_title);
    title->setObjectName("select_item_label");
    title->setMaximumHeight(40);
    title->setAlignment(Qt::AlignCenter);
    gpu_button->setMinimumSize(150,100);
    gpu_button->setMaximumSize(150,100);
    cpu_button->setMinimumSize(150,100);
    cpu_button->setMaximumSize(150,100);
    psu_button->setMinimumSize(150,100);
    psu_button->setMaximumSize(150,100);
    ram_button->setMinimumSize(150,100);
    ram_button->setMaximumSize(150,100);
    rom_button->setMinimumSize(150,100);
    rom_button->setMaximumSize(150,100);
    case_button->setMinimumSize(150,100);
    case_button->setMaximumSize(150,100);
    schedamadre_button->setMinimumSize(150,100);
    schedamadre_button->setMaximumSize(150,100);
    grid_layout->addWidget(gpu_button,1,1);
    grid_layout->addWidget(cpu_button,1,2);
    grid_layout->addWidget(psu_button,1,3);
    grid_layout->addWidget(ram_button,2,1);
    grid_layout->addWidget(rom_button,2,2);
    grid_layout->addWidget(case_button,2,3);
    grid_layout->addWidget(schedamadre_button,3,2);

    v_layout->addWidget(title, Qt::AlignCenter);
    v_layout->addLayout(grid_layout);
//    qDebug() << "parent is "<< gpu_button->parent();

    set_style();

    connect(gpu_button, SIGNAL(clicked()), this, SLOT(richiesta_add_ogg_gpu()));
    connect(cpu_button, SIGNAL(clicked()), this, SLOT(richiesta_add_ogg_cpu()));
    connect(psu_button, SIGNAL(clicked()), this, SLOT(richiesta_add_ogg_psu()));
    connect(ram_button, SIGNAL(clicked()), this, SLOT(richiesta_add_ogg_ram()));
    connect(rom_button, SIGNAL(clicked()), this, SLOT(richiesta_add_ogg_rom()));
    connect(case_button, SIGNAL(clicked()), this, SLOT(richiesta_add_ogg_case()));
    connect(schedamadre_button, SIGNAL(clicked()), this, SLOT(richiesta_add_ogg_schedamadre()));


}

void SelectAddObjectView::set_style () {
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

void SelectAddObjectView::richiesta_add_ogg_gpu(){
    emit signal_tipo_ogg_add("Gpu");
}

void SelectAddObjectView::richiesta_add_ogg_cpu(){
    emit signal_tipo_ogg_add("Cpu");
}

void SelectAddObjectView::richiesta_add_ogg_psu(){
    emit signal_tipo_ogg_add("Psu");
}


void SelectAddObjectView::richiesta_add_ogg_ram(){
    emit signal_tipo_ogg_add("Ram");
}

void SelectAddObjectView::richiesta_add_ogg_rom(){
    emit signal_tipo_ogg_add("Rom");
}

void SelectAddObjectView::richiesta_add_ogg_case(){
    emit signal_tipo_ogg_add("Case");
}

void SelectAddObjectView::richiesta_add_ogg_schedamadre(){
    emit signal_tipo_ogg_add("SchedaMadre");
}

void SelectAddObjectView::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}
