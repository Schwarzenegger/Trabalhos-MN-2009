/****************************************************************************
** Meta object code from reading C++ file 'janelaP.hpp'
**
** Created: Wed Oct 21 14:56:31 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "janelaP.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'janelaP.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JanelaP[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      22,    8,    8,    8, 0x08,
      33,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_JanelaP[] = {
    "JanelaP\0\0textoMudou()\0calcular()\0"
    "atualizarCirc()\0"
};

const QMetaObject JanelaP::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_JanelaP,
      qt_meta_data_JanelaP, 0 }
};

const QMetaObject *JanelaP::metaObject() const
{
    return &staticMetaObject;
}

void *JanelaP::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JanelaP))
        return static_cast<void*>(const_cast< JanelaP*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int JanelaP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: textoMudou(); break;
        case 1: calcular(); break;
        case 2: atualizarCirc(); break;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
