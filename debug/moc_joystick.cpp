/****************************************************************************
** Meta object code from reading C++ file 'joystick.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../test/joystick.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'joystick.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Joystick_t {
    QByteArrayData data[19];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Joystick_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Joystick_t qt_meta_stringdata_Joystick = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Joystick"
QT_MOC_LITERAL(1, 9, 18), // "computeFieldSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 19), // "changeMagnetsSignal"
QT_MOC_LITERAL(4, 49, 16), // "changeRollSignal"
QT_MOC_LITERAL(5, 66, 12), // "leftXchanged"
QT_MOC_LITERAL(6, 79, 5), // "value"
QT_MOC_LITERAL(7, 85, 12), // "leftYchanged"
QT_MOC_LITERAL(8, 98, 13), // "rightXchanged"
QT_MOC_LITERAL(9, 112, 13), // "rightYchanged"
QT_MOC_LITERAL(10, 126, 14), // "buttonAchanged"
QT_MOC_LITERAL(11, 141, 7), // "pressed"
QT_MOC_LITERAL(12, 149, 14), // "buttonBchanged"
QT_MOC_LITERAL(13, 164, 14), // "buttonXchanged"
QT_MOC_LITERAL(14, 179, 14), // "buttonYchanged"
QT_MOC_LITERAL(15, 194, 15), // "buttonL1changed"
QT_MOC_LITERAL(16, 210, 15), // "buttonR1changed"
QT_MOC_LITERAL(17, 226, 15), // "buttonL2changed"
QT_MOC_LITERAL(18, 242, 15) // "buttonR2changed"

    },
    "Joystick\0computeFieldSignal\0\0"
    "changeMagnetsSignal\0changeRollSignal\0"
    "leftXchanged\0value\0leftYchanged\0"
    "rightXchanged\0rightYchanged\0buttonAchanged\0"
    "pressed\0buttonBchanged\0buttonXchanged\0"
    "buttonYchanged\0buttonL1changed\0"
    "buttonR1changed\0buttonL2changed\0"
    "buttonR2changed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Joystick[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    1,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   94,    2, 0x08 /* Private */,
       7,    1,   97,    2, 0x08 /* Private */,
       8,    1,  100,    2, 0x08 /* Private */,
       9,    1,  103,    2, 0x08 /* Private */,
      10,    1,  106,    2, 0x08 /* Private */,
      12,    1,  109,    2, 0x08 /* Private */,
      13,    1,  112,    2, 0x08 /* Private */,
      14,    1,  115,    2, 0x08 /* Private */,
      15,    1,  118,    2, 0x08 /* Private */,
      16,    1,  121,    2, 0x08 /* Private */,
      17,    1,  124,    2, 0x08 /* Private */,
      18,    1,  127,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,

       0        // eod
};

void Joystick::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Joystick *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->computeFieldSignal(); break;
        case 1: _t->changeMagnetsSignal(); break;
        case 2: _t->changeRollSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->leftXchanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->leftYchanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->rightXchanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->rightYchanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->buttonAchanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->buttonBchanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->buttonXchanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->buttonYchanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->buttonL1changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->buttonR1changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->buttonL2changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->buttonR2changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Joystick::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Joystick::computeFieldSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Joystick::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Joystick::changeMagnetsSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Joystick::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Joystick::changeRollSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Joystick::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Joystick.data,
    qt_meta_data_Joystick,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Joystick::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Joystick::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Joystick.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Joystick::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Joystick::computeFieldSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Joystick::changeMagnetsSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Joystick::changeRollSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
