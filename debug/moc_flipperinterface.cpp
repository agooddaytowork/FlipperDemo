/****************************************************************************
** Meta object code from reading C++ file 'flipperinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../flipperinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flipperinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_flipperinterface_t {
    QByteArrayData data[16];
    char stringdata0[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_flipperinterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_flipperinterface_t qt_meta_stringdata_flipperinterface = {
    {
QT_MOC_LITERAL(0, 0, 16), // "flipperinterface"
QT_MOC_LITERAL(1, 17, 22), // "flipperServerConnected"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 25), // "flipperServerNotConnected"
QT_MOC_LITERAL(4, 67, 28), // "SIG_flipper_readMeasureValue"
QT_MOC_LITERAL(5, 96, 16), // "SIG_Measurevalue"
QT_MOC_LITERAL(6, 113, 6), // "chanel"
QT_MOC_LITERAL(7, 120, 3), // "val"
QT_MOC_LITERAL(8, 124, 24), // "SIG_sendPushNotification"
QT_MOC_LITERAL(9, 149, 25), // "SIG_sendEmailNotification"
QT_MOC_LITERAL(10, 175, 7), // "subject"
QT_MOC_LITERAL(11, 183, 5), // "start"
QT_MOC_LITERAL(12, 189, 10), // "readPacket"
QT_MOC_LITERAL(13, 200, 27), // "flipper_S_ConnectedtoServer"
QT_MOC_LITERAL(14, 228, 26), // "SLOT_flipper_serverTimeout"
QT_MOC_LITERAL(15, 255, 21) // "taskGetMeasuredValues"

    },
    "flipperinterface\0flipperServerConnected\0"
    "\0flipperServerNotConnected\0"
    "SIG_flipper_readMeasureValue\0"
    "SIG_Measurevalue\0chanel\0val\0"
    "SIG_sendPushNotification\0"
    "SIG_sendEmailNotification\0subject\0"
    "start\0readPacket\0flipper_S_ConnectedtoServer\0"
    "SLOT_flipper_serverTimeout\0"
    "taskGetMeasuredValues"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_flipperinterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    2,   72,    2, 0x06 /* Public */,
       8,    2,   77,    2, 0x06 /* Public */,
       9,    2,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   87,    2, 0x0a /* Public */,
      12,    0,   88,    2, 0x0a /* Public */,
      13,    0,   89,    2, 0x0a /* Public */,
      14,    0,   90,    2, 0x0a /* Public */,
      15,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Double,   10,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void flipperinterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        flipperinterface *_t = static_cast<flipperinterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->flipperServerConnected(); break;
        case 1: _t->flipperServerNotConnected(); break;
        case 2: _t->SIG_flipper_readMeasureValue(); break;
        case 3: _t->SIG_Measurevalue((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2]))); break;
        case 4: _t->SIG_sendPushNotification((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2]))); break;
        case 5: _t->SIG_sendEmailNotification((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2]))); break;
        case 6: _t->start(); break;
        case 7: _t->readPacket(); break;
        case 8: _t->flipper_S_ConnectedtoServer(); break;
        case 9: _t->SLOT_flipper_serverTimeout(); break;
        case 10: _t->taskGetMeasuredValues(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (flipperinterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&flipperinterface::flipperServerConnected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (flipperinterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&flipperinterface::flipperServerNotConnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (flipperinterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&flipperinterface::SIG_flipper_readMeasureValue)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (flipperinterface::*_t)(const int & , const double & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&flipperinterface::SIG_Measurevalue)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (flipperinterface::*_t)(const int & , const double & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&flipperinterface::SIG_sendPushNotification)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (flipperinterface::*_t)(const QString & , const double & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&flipperinterface::SIG_sendEmailNotification)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject flipperinterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_flipperinterface.data,
      qt_meta_data_flipperinterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *flipperinterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *flipperinterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_flipperinterface.stringdata0))
        return static_cast<void*>(const_cast< flipperinterface*>(this));
    return QObject::qt_metacast(_clname);
}

int flipperinterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void flipperinterface::flipperServerConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void flipperinterface::flipperServerNotConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void flipperinterface::SIG_flipper_readMeasureValue()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void flipperinterface::SIG_Measurevalue(const int & _t1, const double & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void flipperinterface::SIG_sendPushNotification(const int & _t1, const double & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void flipperinterface::SIG_sendEmailNotification(const QString & _t1, const double & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
