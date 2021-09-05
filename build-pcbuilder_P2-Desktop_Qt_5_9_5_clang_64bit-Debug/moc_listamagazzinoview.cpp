/****************************************************************************
** Meta object code from reading C++ file 'listamagazzinoview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pcbuilder_P2/listamagazzinoview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listamagazzinoview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ListaMagazzinoView_t {
    QByteArrayData data[9];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ListaMagazzinoView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ListaMagazzinoView_t qt_meta_stringdata_ListaMagazzinoView = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ListaMagazzinoView"
QT_MOC_LITERAL(1, 19, 7), // "closing"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 24), // "delete_obj_to_controller"
QT_MOC_LITERAL(4, 53, 11), // "std::string"
QT_MOC_LITERAL(5, 65, 12), // "item_to_view"
QT_MOC_LITERAL(6, 78, 21), // "richiesta_elimina_obj"
QT_MOC_LITERAL(7, 100, 13), // "item_selected"
QT_MOC_LITERAL(8, 114, 16) // "QListWidgetItem*"

    },
    "ListaMagazzinoView\0closing\0\0"
    "delete_obj_to_controller\0std::string\0"
    "item_to_view\0richiesta_elimina_obj\0"
    "item_selected\0QListWidgetItem*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListaMagazzinoView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,
       5,    1,   43,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   46,    2, 0x0a /* Public */,
       7,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,

       0        // eod
};

void ListaMagazzinoView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ListaMagazzinoView *_t = static_cast<ListaMagazzinoView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closing(); break;
        case 1: _t->delete_obj_to_controller((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->item_to_view((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->richiesta_elimina_obj(); break;
        case 4: _t->item_selected((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ListaMagazzinoView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListaMagazzinoView::closing)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ListaMagazzinoView::*_t)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListaMagazzinoView::delete_obj_to_controller)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ListaMagazzinoView::*_t)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListaMagazzinoView::item_to_view)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ListaMagazzinoView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ListaMagazzinoView.data,
      qt_meta_data_ListaMagazzinoView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ListaMagazzinoView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListaMagazzinoView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ListaMagazzinoView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ListaMagazzinoView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ListaMagazzinoView::closing()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ListaMagazzinoView::delete_obj_to_controller(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ListaMagazzinoView::item_to_view(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
