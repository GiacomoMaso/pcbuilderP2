#include "viewsingleitem.h"

ViewSingleItem::ViewSingleItem(QWidget* parent) : QWidget(parent), list_layout(new QVBoxLayout(this))
{
    setMinimumSize(800, 600);

    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    set_style();
    setAttribute(Qt::WA_DeleteOnClose);


}

void ViewSingleItem::load_view_item(QStringList *x){
    setWindowTitle(x->at(0).mid(6));

    for(auto it=x->begin(); it!=x->end(); it++){
        QLabel* label=new QLabel(this);
        label->setObjectName("item_view_label");
        label->setText(*it);
        list_layout->addWidget(label);
    }


}

void ViewSingleItem::set_style () {
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

void ViewSingleItem::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}
