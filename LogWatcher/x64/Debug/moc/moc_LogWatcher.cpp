/****************************************************************************
** Meta object code from reading C++ file 'LogWatcher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../LogWatcher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LogWatcher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogWatcher__LogWatcher_t {
    QByteArrayData data[16];
    char stringdata0[346];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogWatcher__LogWatcher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogWatcher__LogWatcher_t qt_meta_stringdata_LogWatcher__LogWatcher = {
    {
QT_MOC_LITERAL(0, 0, 22), // "LogWatcher::LogWatcher"
QT_MOC_LITERAL(1, 23, 25), // "on_pushButtonOpen_clicked"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 14), // "appendFileData"
QT_MOC_LITERAL(4, 65, 30), // "on_tabWidget_tabCloseReguested"
QT_MOC_LITERAL(5, 96, 5), // "index"
QT_MOC_LITERAL(6, 102, 36), // "on_tabWidget_tabCloseRegueste..."
QT_MOC_LITERAL(7, 139, 25), // "on_pushButtonNext_clicked"
QT_MOC_LITERAL(8, 165, 30), // "on_pushButtonIntellect_clicked"
QT_MOC_LITERAL(9, 196, 31), // "on_pushButtonOpenSearch_clicked"
QT_MOC_LITERAL(10, 228, 29), // "on_pushButtonEditData_clicked"
QT_MOC_LITERAL(11, 258, 27), // "on_pushButtonAnalyz_clicked"
QT_MOC_LITERAL(12, 286, 16), // "slotCreateRecord"
QT_MOC_LITERAL(13, 303, 14), // "slotFindRecord"
QT_MOC_LITERAL(14, 318, 23), // "slotCustomMenuRequested"
QT_MOC_LITERAL(15, 342, 3) // "pos"

    },
    "LogWatcher::LogWatcher\0on_pushButtonOpen_clicked\0"
    "\0appendFileData\0on_tabWidget_tabCloseReguested\0"
    "index\0on_tabWidget_tabCloseReguestedSearch\0"
    "on_pushButtonNext_clicked\0"
    "on_pushButtonIntellect_clicked\0"
    "on_pushButtonOpenSearch_clicked\0"
    "on_pushButtonEditData_clicked\0"
    "on_pushButtonAnalyz_clicked\0"
    "slotCreateRecord\0slotFindRecord\0"
    "slotCustomMenuRequested\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogWatcher__LogWatcher[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    1,   75,    2, 0x08 /* Private */,
       4,    1,   78,    2, 0x08 /* Private */,
       6,    1,   81,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    1,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   15,

       0        // eod
};

void LogWatcher::LogWatcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LogWatcher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonOpen_clicked(); break;
        case 1: _t->appendFileData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_tabWidget_tabCloseReguested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_tabWidget_tabCloseReguestedSearch((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pushButtonNext_clicked(); break;
        case 5: _t->on_pushButtonIntellect_clicked(); break;
        case 6: _t->on_pushButtonOpenSearch_clicked(); break;
        case 7: _t->on_pushButtonEditData_clicked(); break;
        case 8: _t->on_pushButtonAnalyz_clicked(); break;
        case 9: _t->slotCreateRecord(); break;
        case 10: _t->slotFindRecord(); break;
        case 11: _t->slotCustomMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LogWatcher::LogWatcher::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_LogWatcher__LogWatcher.data,
    qt_meta_data_LogWatcher__LogWatcher,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LogWatcher::LogWatcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogWatcher::LogWatcher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LogWatcher__LogWatcher.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int LogWatcher::LogWatcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
