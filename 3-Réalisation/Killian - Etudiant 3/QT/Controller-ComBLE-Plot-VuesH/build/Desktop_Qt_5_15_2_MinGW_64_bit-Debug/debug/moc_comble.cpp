/****************************************************************************
** Meta object code from reading C++ file 'comble.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../comble.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comble.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ComBLE_t {
    QByteArrayData data[33];
    char stringdata0[517];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ComBLE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ComBLE_t qt_meta_stringdata_ComBLE = {
    {
QT_MOC_LITERAL(0, 0, 6), // "ComBLE"
QT_MOC_LITERAL(1, 7, 16), // "deviceDiscovered"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(4, 46, 10), // "deviceInfo"
QT_MOC_LITERAL(5, 57, 15), // "scanningChanged"
QT_MOC_LITERAL(6, 73, 18), // "deviceScanFinished"
QT_MOC_LITERAL(7, 92, 20), // "deviceScannerCleared"
QT_MOC_LITERAL(8, 113, 26), // "characteristicValueChanged"
QT_MOC_LITERAL(9, 140, 24), // "QLowEnergyCharacteristic"
QT_MOC_LITERAL(10, 165, 14), // "characteristic"
QT_MOC_LITERAL(11, 180, 5), // "value"
QT_MOC_LITERAL(12, 186, 25), // "characteristicValuesReady"
QT_MOC_LITERAL(13, 212, 6), // "values"
QT_MOC_LITERAL(14, 219, 14), // "serviceDetecte"
QT_MOC_LITERAL(15, 234, 18), // "QLowEnergyService*"
QT_MOC_LITERAL(16, 253, 7), // "service"
QT_MOC_LITERAL(17, 261, 11), // "batterieLue"
QT_MOC_LITERAL(18, 273, 8), // "newValue"
QT_MOC_LITERAL(19, 282, 9), // "valeurLue"
QT_MOC_LITERAL(20, 292, 19), // "QLowEnergyService*&"
QT_MOC_LITERAL(21, 312, 10), // "plotAppuye"
QT_MOC_LITERAL(22, 323, 13), // "startScanning"
QT_MOC_LITERAL(23, 337, 12), // "stopScanning"
QT_MOC_LITERAL(24, 350, 13), // "deviceDetecte"
QT_MOC_LITERAL(25, 364, 4), // "info"
QT_MOC_LITERAL(26, 369, 18), // "terminerScanDevice"
QT_MOC_LITERAL(27, 388, 19), // "serviceStateChanged"
QT_MOC_LITERAL(28, 408, 31), // "QLowEnergyService::ServiceState"
QT_MOC_LITERAL(29, 440, 8), // "newState"
QT_MOC_LITERAL(30, 449, 28), // "onCharacteristicValueChanged"
QT_MOC_LITERAL(31, 478, 29), // "recupererValeurCharacteristic"
QT_MOC_LITERAL(32, 508, 8) // "scanning"

    },
    "ComBLE\0deviceDiscovered\0\0QBluetoothDeviceInfo\0"
    "deviceInfo\0scanningChanged\0"
    "deviceScanFinished\0deviceScannerCleared\0"
    "characteristicValueChanged\0"
    "QLowEnergyCharacteristic\0characteristic\0"
    "value\0characteristicValuesReady\0values\0"
    "serviceDetecte\0QLowEnergyService*\0"
    "service\0batterieLue\0newValue\0valeurLue\0"
    "QLowEnergyService*&\0plotAppuye\0"
    "startScanning\0stopScanning\0deviceDetecte\0"
    "info\0terminerScanDevice\0serviceStateChanged\0"
    "QLowEnergyService::ServiceState\0"
    "newState\0onCharacteristicValueChanged\0"
    "recupererValeurCharacteristic\0scanning"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ComBLE[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       1,  146, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       5,    0,  102,    2, 0x06 /* Public */,
       6,    0,  103,    2, 0x06 /* Public */,
       7,    0,  104,    2, 0x06 /* Public */,
       8,    2,  105,    2, 0x06 /* Public */,
      12,    1,  110,    2, 0x06 /* Public */,
      14,    1,  113,    2, 0x06 /* Public */,
      17,    2,  116,    2, 0x06 /* Public */,
      19,    2,  121,    2, 0x06 /* Public */,
      21,    1,  126,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    0,  129,    2, 0x0a /* Public */,
      23,    0,  130,    2, 0x0a /* Public */,
      24,    1,  131,    2, 0x0a /* Public */,
      26,    0,  134,    2, 0x0a /* Public */,
      27,    1,  135,    2, 0x0a /* Public */,
      30,    2,  138,    2, 0x0a /* Public */,
      31,    1,  143,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QByteArray,   10,   11,
    QMetaType::Void, QMetaType::QByteArrayList,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 15, QMetaType::QByteArray,   16,   18,
    QMetaType::Void, 0x80000000 | 20, QMetaType::QByteArray,   16,   11,
    QMetaType::Void, QMetaType::QByteArray,   18,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   25,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QByteArray,   10,   18,
    QMetaType::QByteArrayList, 0x80000000 | 15,   16,

 // properties: name, type, flags
      32, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       1,

       0        // eod
};

void ComBLE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ComBLE *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deviceDiscovered((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 1: _t->scanningChanged(); break;
        case 2: _t->deviceScanFinished(); break;
        case 3: _t->deviceScannerCleared(); break;
        case 4: _t->characteristicValueChanged((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 5: _t->characteristicValuesReady((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        case 6: _t->serviceDetecte((*reinterpret_cast< QLowEnergyService*(*)>(_a[1]))); break;
        case 7: _t->batterieLue((*reinterpret_cast< QLowEnergyService*(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 8: _t->valeurLue((*reinterpret_cast< QLowEnergyService*(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 9: _t->plotAppuye((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 10: _t->startScanning(); break;
        case 11: _t->stopScanning(); break;
        case 12: _t->deviceDetecte((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 13: _t->terminerScanDevice(); break;
        case 14: _t->serviceStateChanged((*reinterpret_cast< QLowEnergyService::ServiceState(*)>(_a[1]))); break;
        case 15: _t->onCharacteristicValueChanged((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 16: { QList<QByteArray> _r = _t->recupererValeurCharacteristic((*reinterpret_cast< QLowEnergyService*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QByteArray>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyCharacteristic >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyCharacteristic >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ComBLE::*)(const QBluetoothDeviceInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComBLE::deviceDiscovered)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ComBLE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComBLE::scanningChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ComBLE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComBLE::deviceScanFinished)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ComBLE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComBLE::deviceScannerCleared)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ComBLE::*)(const QLowEnergyCharacteristic & , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComBLE::characteristicValueChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ComBLE::*)(const QList<QByteArray> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComBLE::characteristicValuesReady)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ComBLE::*)(QLowEnergyService * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComBLE::serviceDetecte)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ComBLE::*)(QLowEnergyService * , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComBLE::batterieLue)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ComBLE::*)(QLowEnergyService * & , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComBLE::valeurLue)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ComBLE::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComBLE::plotAppuye)) {
                *result = 9;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ComBLE *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isScanning(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ComBLE::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ComBLE.data,
    qt_meta_data_ComBLE,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ComBLE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ComBLE::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ComBLE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ComBLE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ComBLE::deviceDiscovered(const QBluetoothDeviceInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ComBLE::scanningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ComBLE::deviceScanFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ComBLE::deviceScannerCleared()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ComBLE::characteristicValueChanged(const QLowEnergyCharacteristic & _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ComBLE::characteristicValuesReady(const QList<QByteArray> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ComBLE::serviceDetecte(QLowEnergyService * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ComBLE::batterieLue(QLowEnergyService * _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ComBLE::valeurLue(QLowEnergyService * & _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ComBLE::plotAppuye(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
