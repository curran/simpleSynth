/****************************************************************************
** Meta object code from reading C++ file 'synth.hpp'
**
** Created: Wed Jan 13 18:52:11 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "synth.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'synth.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Synth[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      16,    7,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   37,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Synth[] = {
    "Synth\0\0newValue\0volumeChanged(float)\0"
    "value\0setVolume(float)\0"
};

const QMetaObject Synth::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Synth,
      qt_meta_data_Synth, 0 }
};

const QMetaObject *Synth::metaObject() const
{
    return &staticMetaObject;
}

void *Synth::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Synth))
        return static_cast<void*>(const_cast< Synth*>(this));
    return QObject::qt_metacast(_clname);
}

int Synth::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: volumeChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: setVolume((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Synth::volumeChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
