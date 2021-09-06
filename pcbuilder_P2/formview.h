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
    QIntValidator* val_maggiore_0;
    QDoubleValidator* double_maggiore_0;
    QPushButton* return_button, *save_element_button;
    QLineEdit * nameLineEdit,*quantitaLineEdit, *marcaLineEdit, *modelloLineEdit, *priceLineEdit,*realeseDateLineEdit, *varianteLineEdit, *vramLineEdit, *gpuClockLineEdit, *typeRamLineEdit,
    *serieLineEdit, *cpuGhzLineEdit, *cpuCoreNumberLineEdit, /**intelAMDLineEdit,*/ *socketLineEdit, *caseDimLineEdit, *mbSupportedLineEdit, *wattLineEdit, *ratingLineEdit, *modularitaLineEdit,
    *typeMemoryLineEdit, *capacityLineEdit, *clockLineEdit, *latencyLineEdit, /**numPerPaccoLineEdit,*/ *mbWriteLineEdit, *mbReadLineEdit, *sizeLineEdit, *grandezzaLineEdit, *socketMbLineEdit,
    *sataPortLineEdit, *nvmePortLineEdit;

//    QLabel* nome_l, *quantita_l, *marca_l, *modello_l, price_l;
protected:
     void closeEvent(QCloseEvent *event);

public:
    FormView(QWidget* parent=nullptr);
    void build_form(std::string);
//    void set_style();

public slots:
    void salva_elemento();
signals:
    void add_item(QStringList*);
    void closing();

};

#endif // FORMVIEW_H
