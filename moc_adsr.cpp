/****************************************************************************
** Meta object code from reading C++ file 'adsr.hpp'
**
** Created: Sun Dec 20 22:48:21 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "adsr.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adsr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ADSR[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      15,    6,    5,    5, 0x05,
      36,    6,    5,    5, 0x05,
      56,    6,    5,    5, 0x05,
      78,    6,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
     106,  100,    5,    5, 0x0a,
     123,  100,    5,    5, 0x0a,
     139,  100,    5,    5, 0x0a,
     157,  100,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ADSR[] = {
    "ADSR\0\0newValue\0attackChanged(float)\0"
    "decayChanged(float)\0sustainChanged(float)\0"
    "releaseChanged(float)\0value\0"
    "setAttack(float)\0setDecay(float)\0"
    "setSustain(float)\0setRelease(float)\0"
};

const QMetaObject ADSR::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ADSR,
      qt_meta_data_ADSR, 0 }
};

const QMetaObject *ADSR::metaObject() const
{
    return &staticMetaObject;
}

void *ADSR::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ADSR))
        return static_cast<void*>(const_cast< ADSR*>(this));
    return QObject::qt_metacast(_clname);
}

int ADSR::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: attackChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: decayChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: sustainChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: releaseChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: setAttack((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: setDecay((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: setSustain((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 7: setRelease((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ADSR::attackChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ADSR::decayChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ADSR::sustainChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ADSR::releaseChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
