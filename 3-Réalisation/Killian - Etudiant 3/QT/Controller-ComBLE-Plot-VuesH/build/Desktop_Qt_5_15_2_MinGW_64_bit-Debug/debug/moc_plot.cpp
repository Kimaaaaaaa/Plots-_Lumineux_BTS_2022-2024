/****************************************************************************
** Meta object code from reading C++ file 'plot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../plot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Plot_t {
    QByteArrayData data[18];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Plot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Plot_t qt_meta_stringdata_Plot = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Plot"
QT_MOC_LITERAL(1, 5, 9), // "tempsRecu"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 5), // "Plot*"
QT_MOC_LITERAL(4, 22, 10), // "nomChanged"
QT_MOC_LITERAL(5, 33, 17), // "nvBatterieChanged"
QT_MOC_LITERAL(6, 51, 15), // "selectedChanged"
QT_MOC_LITERAL(7, 67, 9), // "idChanged"
QT_MOC_LITERAL(8, 77, 20), // "selectedPlotsChanged"
QT_MOC_LITERAL(9, 98, 2), // "id"
QT_MOC_LITERAL(10, 101, 38), // "characteristicReactiontimeVal..."
QT_MOC_LITERAL(11, 140, 12), // "reactionTime"
QT_MOC_LITERAL(12, 153, 7), // "standBy"
QT_MOC_LITERAL(13, 161, 12), // "writeTimeout"
QT_MOC_LITERAL(14, 174, 26), // "handleCharacteristicChange"
QT_MOC_LITERAL(15, 201, 10), // "nvBatterie"
QT_MOC_LITERAL(16, 212, 3), // "nom"
QT_MOC_LITERAL(17, 216, 8) // "selected"

    },
    "Plot\0tempsRecu\0\0Plot*\0nomChanged\0"
    "nvBatterieChanged\0selectedChanged\0"
    "idChanged\0selectedPlotsChanged\0id\0"
    "characteristicReactiontimeValueChanged\0"
    "reactionTime\0standBy\0writeTimeout\0"
    "handleCharacteristicChange\0nvBatterie\0"
    "nom\0selected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Plot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       4,   80, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    0,   67,    2, 0x06 /* Public */,
       5,    0,   68,    2, 0x06 /* Public */,
       6,    0,   69,    2, 0x06 /* Public */,
       7,    0,   70,    2, 0x06 /* Public */,
       8,    1,   71,    2, 0x06 /* Public */,
      10,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   77,    2, 0x0a /* Public */,
      13,    0,   78,    2, 0x0a /* Public */,
      14,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QByteArray,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      15, QMetaType::Int, 0x00495001,
      16, QMetaType::QString, 0x00495001,
      17, QMetaType::Bool, 0x00495103,
       9, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       2,
       1,
       3,
       4,

       0        // eod
};

void Plot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Plot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tempsRecu((*reinterpret_cast< Plot*(*)>(_a[1]))); break;
        case 1: _t->nomChanged(); break;
        case 2: _t->nvBatterieChanged(); break;
        case 3: _t->selectedChanged(); break;
        case 4: _t->idChanged(); break;
        case 5: _t->selectedPlotsChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 6: _t->characteristicReactiontimeValueChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->standBy(); break;
        case 8: _t->writeTimeout(); break;
        case 9: _t->handleCharacteristicChange(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Plot* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Plot::*)(Plot * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plot::tempsRecu)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Plot::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plot::nomChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Plot::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plot::nvBatterieChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Plot::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plot::selectedChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Plot::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plot::idChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Plot::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plot::selectedPlotsChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Plot::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plot::characteristicReactiontimeValueChanged)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Plot *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getNvBatterie(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getNom(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getSelected(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getId(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Plot *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setSelected(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Plot::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Plot.data,
    qt_meta_data_Plot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Plot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Plot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Plot.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Plot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Plot::tempsRecu(Plot * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Plot::nomChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Plot::nvBatterieChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Plot::selectedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Plot::idChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Plot::selectedPlotsChanged(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Plot::characteristicReactiontimeValueChanged(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
