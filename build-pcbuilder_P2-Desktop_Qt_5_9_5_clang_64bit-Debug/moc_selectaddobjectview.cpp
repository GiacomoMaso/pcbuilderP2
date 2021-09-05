/****************************************************************************
** Meta object code from reading C++ file 'selectaddobjectview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pcbuilder_P2/selectaddobjectview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectaddobjectview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SelectAddObjectView_t {
    QByteArrayData data[11];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelectAddObjectView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelectAddObjectView_t qt_meta_stringdata_SelectAddObjectView = {
    {
QT_MOC_LITERAL(0, 0, 19), // "SelectAddObjectView"
QT_MOC_LITERAL(1, 20, 19), // "signal_tipo_ogg_add"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 11), // "std::string"
QT_MOC_LITERAL(4, 53, 21), // "richiesta_add_ogg_gpu"
QT_MOC_LITERAL(5, 75, 21), // "richiesta_add_ogg_cpu"
QT_MOC_LITERAL(6, 97, 21), // "richiesta_add_ogg_psu"
QT_MOC_LITERAL(7, 119, 21), // "richiesta_add_ogg_ram"
QT_MOC_LITERAL(8, 141, 21), // "richiesta_add_ogg_rom"
QT_MOC_LITERAL(9, 163, 22), // "richiesta_add_ogg_case"
QT_MOC_LITERAL(10, 186, 29) // "richiesta_add_ogg_schedamadre"

    },
    "SelectAddObjectView\0signal_tipo_ogg_add\0"
    "\0std::string\0richiesta_add_ogg_gpu\0"
    "richiesta_add_ogg_cpu\0richiesta_add_ogg_psu\0"
    "richiesta_add_ogg_ram\0richiesta_add_ogg_rom\0"
    "richiesta_add_ogg_case\0"
    "richiesta_add_ogg_schedamadre"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectAddObjectView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x0a /* Public */,
       9,    0,   62,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SelectAddObjectView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectAddObjectView *_t = static_cast<SelectAddObjectView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_tipo_ogg_add((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->richiesta_add_ogg_gpu(); break;
        case 2: _t->richiesta_add_ogg_cpu(); break;
        case 3: _t->richiesta_add_ogg_psu(); break;
        case 4: _t->richiesta_add_ogg_ram(); break;
        case 5: _t->richiesta_add_ogg_rom(); break;
        case 6: _t->richiesta_add_ogg_case(); break;
        case 7: _t->richiesta_add_ogg_schedamadre(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SelectAddObjectView::*_t)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SelectAddObjectView::signal_tipo_ogg_add)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SelectAddObjectView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SelectAddObjectView.data,
      qt_meta_data_SelectAddObjectView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SelectAddObjectView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectAddObjectView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SelectAddObjectView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SelectAddObjectView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SelectAddObjectView::signal_tipo_ogg_add(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
