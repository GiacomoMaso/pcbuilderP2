#ifndef VIEWSINGLEITEM_H
#define VIEWSINGLEITEM_H
#include <QWidget>
#include <QtWidgets>
#include <QSize>




class ViewSingleItem : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout* list_layout;


public:
    ViewSingleItem(QWidget* parent=nullptr);
    void load_view_item(QStringList*);
    void set_style();
};

#endif // VIEWSINGLEITEM_H
