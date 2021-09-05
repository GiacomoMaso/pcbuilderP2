#ifndef FORMVIEW_H
#define FORMVIEW_H
#include <QtWidgets>
#include <iostream>


class FormView : public QDialog
{
    Q_OBJECT
private:
    std::string tipo_ogg;
    QVBoxLayout* v_layout;
    QFormLayout* form_layout;
    QHBoxLayout* h_layout;
    QPushButton* return_button, *save_element_button;
    QLineEdit * nameLineEdit,*quantitaLineEdit, *marcaLineEdit, *modelloLineEdit, *priceLineEdit, *varianteLineEdit, *vramLineEdit, *gpuClockLineEdit, *typeRamLineEdit,
    *serieLineEdit, *cpuGhzLineEdit, *cpuCoreNumberLineEdit, *intelAMDLineEdit, *socketLineEdit, *caseDimLineEdit, *mbSupportedLineEdit, *wattLineEdit, *ratingLineEdit, *modularitaLineEdit,
    *typeMemoryLineEdit, *capacityLineEdit, *clockLineEdit, *latencyLineEdit, *numPerPaccoLineEdit, *mbWriteLineEdit, *mbReadLineEdit, *sizeLineEdit, *grandezzaLineEdit, *socketMbLineEdit,
    *sataPortLineEdit, *nvmePortLineEdit;
    QIntValidator* val_maggiore_0;
    QDoubleValidator* double_maggiore_0;
//    QLabel* nome_l, *quantita_l, *marca_l, *modello_l, price_l;

public:
    FormView(QWidget* parent=nullptr);
    void build_form(std::string);
    void set_style();

public slots:
    void salva_elemento();
};

#endif // FORMVIEW_H
