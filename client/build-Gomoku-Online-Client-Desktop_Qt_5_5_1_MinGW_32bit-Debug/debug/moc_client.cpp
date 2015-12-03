/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gomoku-Online-Client/client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_client_t {
    QByteArrayData data[16];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client_t qt_meta_stringdata_client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "client"
QT_MOC_LITERAL(1, 7, 8), // "on_login"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 16), // "on_refresh_rooms"
QT_MOC_LITERAL(4, 34, 4), // "data"
QT_MOC_LITERAL(5, 39, 18), // "on_refresh_players"
QT_MOC_LITERAL(6, 58, 7), // "on_join"
QT_MOC_LITERAL(7, 66, 3), // "rid"
QT_MOC_LITERAL(8, 70, 13), // "on_close_game"
QT_MOC_LITERAL(9, 84, 14), // "on_create_room"
QT_MOC_LITERAL(10, 99, 13), // "on_start_game"
QT_MOC_LITERAL(11, 113, 9), // "connected"
QT_MOC_LITERAL(12, 123, 12), // "disconnected"
QT_MOC_LITERAL(13, 136, 21), // "sendMessageJSONObject"
QT_MOC_LITERAL(14, 158, 7), // "message"
QT_MOC_LITERAL(15, 166, 11) // "readMessage"

    },
    "client\0on_login\0\0on_refresh_rooms\0"
    "data\0on_refresh_players\0on_join\0rid\0"
    "on_close_game\0on_create_room\0on_start_game\0"
    "connected\0disconnected\0sendMessageJSONObject\0"
    "message\0readMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,
       5,    1,   73,    2, 0x06 /* Public */,
       6,    1,   76,    2, 0x06 /* Public */,
       8,    0,   79,    2, 0x06 /* Public */,
       9,    1,   80,    2, 0x06 /* Public */,
      10,    0,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   84,    2, 0x0a /* Public */,
      12,    0,   85,    2, 0x0a /* Public */,
      13,    1,   86,    2, 0x0a /* Public */,
      15,    0,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonArray,    4,
    QMetaType::Void, QMetaType::QJsonArray,    4,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,   14,
    QMetaType::Void,

       0        // eod
};

void client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        client *_t = static_cast<client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_login(); break;
        case 1: _t->on_refresh_rooms((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 2: _t->on_refresh_players((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 3: _t->on_join((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_close_game(); break;
        case 5: _t->on_create_room((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_start_game(); break;
        case 7: _t->connected(); break;
        case 8: _t->disconnected(); break;
        case 9: _t->sendMessageJSONObject((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 10: _t->readMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::on_login)) {
                *result = 0;
            }
        }
        {
            typedef void (client::*_t)(QJsonArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::on_refresh_rooms)) {
                *result = 1;
            }
        }
        {
            typedef void (client::*_t)(QJsonArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::on_refresh_players)) {
                *result = 2;
            }
        }
        {
            typedef void (client::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::on_join)) {
                *result = 3;
            }
        }
        {
            typedef void (client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::on_close_game)) {
                *result = 4;
            }
        }
        {
            typedef void (client::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::on_create_room)) {
                *result = 5;
            }
        }
        {
            typedef void (client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::on_start_game)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject client::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_client.data,
      qt_meta_data_client,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_client.stringdata0))
        return static_cast<void*>(const_cast< client*>(this));
    return QObject::qt_metacast(_clname);
}

int client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void client::on_login()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void client::on_refresh_rooms(QJsonArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void client::on_refresh_players(QJsonArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void client::on_join(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void client::on_close_game()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void client::on_create_room(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void client::on_start_game()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
