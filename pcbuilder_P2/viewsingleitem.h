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
protected:
     void closeEvent(QCloseEvent *event);


public:
    ViewSingleItem(QWidget* parent=nullptr);
    void load_view_item(QStringList*);
    void set_style();
signals:
    void closing();
};

#endif // VIEWSINGLEITEM_H
