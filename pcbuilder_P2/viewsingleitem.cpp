#include "viewsingleitem.h"

ViewSingleItem::ViewSingleItem(QWidget* parent) : QWidget(parent)
{
    setMinimumSize(800, 600);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

}
