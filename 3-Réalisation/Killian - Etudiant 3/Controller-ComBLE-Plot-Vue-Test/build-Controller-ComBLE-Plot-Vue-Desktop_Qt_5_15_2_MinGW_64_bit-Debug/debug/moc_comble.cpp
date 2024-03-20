/****************************************************************************
** Meta object code from reading C++ file 'comble.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../comble.h"
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
    QByteArrayData data[30];
    char stringdata0[474];
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
QT_MOC_LITERAL(17, 261, 13), // "startScanning"
QT_MOC_LITERAL(18, 275, 12), // "stopScanning"
QT_MOC_LITERAL(19, 288, 13), // "deviceDetecte"
QT_MOC_LITERAL(20, 302, 4), // "info"
QT_MOC_LITERAL(21, 307, 18), // "terminerScanDevice"
QT_MOC_LITERAL(22, 326, 12), // "scanServices"
QT_MOC_LITERAL(23, 339, 21), // "QLowEnergyController*"
QT_MOC_LITERAL(24, 361, 10), // "controller"
QT_MOC_LITERAL(25, 372, 19), // "serviceStateChanged"
QT_MOC_LITERAL(26, 392, 31), // "QLowEnergyService::ServiceState"
QT_MOC_LITERAL(27, 424, 8), // "newState"
QT_MOC_LITERAL(28, 433, 31), // "lireValeurCharacteristicBattery"
QT_MOC_LITERAL(29, 465, 8) // "scanning"

    },
    "ComBLE\0deviceDiscovered\0\0QBluetoothDeviceInfo\0"
    "deviceInfo\0scanningChanged\0"
    "deviceScanFinished\0deviceScannerCleared\0"
    "characteristicValueChanged\0"
    "QLowEnergyCharacteristic\0characteristic\0"
    "value\0characteristicValuesReady\0values\0"
    "serviceDetecte\0QLowEnergyService*\0"
    "service\0startScanning\0stopScanning\0"
    "deviceDetecte\0info\0terminerScanDevice\0"
    "scanServices\0QLowEnergyController*\0"
    "controller\0serviceStateChanged\0"
    "QLowEnergyService::ServiceState\0"
    "newState\0lireValeurCharacteristicBattery\0"
    "scanning"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ComBLE[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       1,  116, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    0,   88,    2, 0x06 /* Public */,
       7,    0,   89,    2, 0x06 /* Public */,
       8,    2,   90,    2, 0x06 /* Public */,
      12,    1,   95,    2, 0x06 /* Public */,
      14,    1,   98,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,  101,    2, 0x0a /* Public */,
      18,    0,  102,    2, 0x0a /* Public */,
      19,    1,  103,    2, 0x0a /* Public */,
      21,    0,  106,    2, 0x0a /* Public */,
      22,    1,  107,    2, 0x0a /* Public */,
      25,    1,  110,    2, 0x0a /* Public */,
      28,    1,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QByteArray,   10,   11,
    QMetaType::Void, QMetaType::QByteArrayList,   13,
    QMetaType::Void, 0x80000000 | 15,   16,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   20,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, 0x80000000 | 15,   16,

 // properties: name, type, flags
      29, QMetaType::Bool, 0x00495001,

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
        case 7: _t->startScanning(); break;
        case 8: _t->stopScanning(); break;
        case 9: _t->deviceDetecte((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 10: _t->terminerScanDevice(); break;
        case 11: _t->scanServices((*reinterpret_cast< QLowEnergyController*(*)>(_a[1]))); break;
        case 12: _t->serviceStateChanged((*reinterpret_cast< QLowEnergyService::ServiceState(*)>(_a[1]))); break;
        case 13: _t->lireValeurCharacteristicBattery((*reinterpret_cast< QLowEnergyService*(*)>(_a[1]))); break;
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
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyController* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        case 13:
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
