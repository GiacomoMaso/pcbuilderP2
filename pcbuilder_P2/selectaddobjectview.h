#ifndef SELECTADDOBJECTVIEW_H
#define SELECTADDOBJECTVIEW_H
#include <QWidget>
#include <QtWidgets>

class SelectAddObjectView: public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout* v_layout;
    QGridLayout* grid_layout;
    QPushButton* gpu_button, *cpu_button, *psu_button, *ram_button, *rom_button, *case_button, *schedamadre_button;
    QLabel* title;
public:
    SelectAddObjectView();
    void set_style();
public slots:
    void richiesta_add_ogg_gpu();
    void richiesta_add_ogg_cpu();
    void richiesta_add_ogg_psu();
    void richiesta_add_ogg_ram();
    void richiesta_add_ogg_rom();
    void richiesta_add_ogg_case();
    void richiesta_add_ogg_schedamadre();
signals:
    void signal_tipo_ogg_add(std::string);
};

#endif // SELECTADDOBJECTVIEW_H
