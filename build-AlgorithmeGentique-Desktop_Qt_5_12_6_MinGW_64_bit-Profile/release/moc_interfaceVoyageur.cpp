/****************************************************************************
** Meta object code from reading C++ file 'interfaceVoyageur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../samy chien/AlgorithmeGenetique/VoyageurDeCommerce/interfaceVoyageur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interfaceVoyageur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_voyageurDeCommerceInterface_t {
    QByteArrayData data[9];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_voyageurDeCommerceInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_voyageurDeCommerceInterface_t qt_meta_stringdata_voyageurDeCommerceInterface = {
    {
QT_MOC_LITERAL(0, 0, 27), // "voyageurDeCommerceInterface"
QT_MOC_LITERAL(1, 28, 11), // "creerGraphe"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 20), // "gestionConfiguration"
QT_MOC_LITERAL(4, 62, 6), // "valeur"
QT_MOC_LITERAL(5, 69, 13), // "quatreSommets"
QT_MOC_LITERAL(6, 83, 13), // "retourAccueil"
QT_MOC_LITERAL(7, 97, 12), // "afficherAide"
QT_MOC_LITERAL(8, 110, 6) // "lancer"

    },
    "voyageurDeCommerceInterface\0creerGraphe\0"
    "\0gestionConfiguration\0valeur\0quatreSommets\0"
    "retourAccueil\0afficherAide\0lancer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_voyageurDeCommerceInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,
       5,    0,   48,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void voyageurDeCommerceInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<voyageurDeCommerceInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->creerGraphe(); break;
        case 1: _t->gestionConfiguration((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->quatreSommets(); break;
        case 3: _t->retourAccueil(); break;
        case 4: _t->afficherAide(); break;
        case 5: _t->lancer(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject voyageurDeCommerceInterface::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_voyageurDeCommerceInterface.data,
    qt_meta_data_voyageurDeCommerceInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *voyageurDeCommerceInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *voyageurDeCommerceInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_voyageurDeCommerceInterface.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int voyageurDeCommerceInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
