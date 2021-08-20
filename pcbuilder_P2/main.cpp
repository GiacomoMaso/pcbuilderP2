#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton hello("hello word");
    hello.show();
    return QApplication::exec();

}
