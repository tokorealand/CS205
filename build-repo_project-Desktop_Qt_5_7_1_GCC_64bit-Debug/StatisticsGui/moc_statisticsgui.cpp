/****************************************************************************
** Meta object code from reading C++ file 'statisticsgui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../repo_project/StatisticsGui/statisticsgui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statisticsgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StatisticsGui_t {
    QByteArrayData data[10];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StatisticsGui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StatisticsGui_t qt_meta_stringdata_StatisticsGui = {
    {
QT_MOC_LITERAL(0, 0, 13), // "StatisticsGui"
QT_MOC_LITERAL(1, 14, 21), // "on_calcbutton_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 21), // "on_doneButton_clicked"
QT_MOC_LITERAL(4, 59, 23), // "on_yearSelect_activated"
QT_MOC_LITERAL(5, 83, 4), // "arg1"
QT_MOC_LITERAL(6, 88, 27), // "on_semesterSelect_activated"
QT_MOC_LITERAL(7, 116, 24), // "on_classSelect_activated"
QT_MOC_LITERAL(8, 141, 26), // "on_sectionSelect_activated"
QT_MOC_LITERAL(9, 168, 22) // "on_labSelect_activated"

    },
    "StatisticsGui\0on_calcbutton_clicked\0"
    "\0on_doneButton_clicked\0on_yearSelect_activated\0"
    "arg1\0on_semesterSelect_activated\0"
    "on_classSelect_activated\0"
    "on_sectionSelect_activated\0"
    "on_labSelect_activated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StatisticsGui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       7,    1,   57,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
       9,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void StatisticsGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StatisticsGui *_t = static_cast<StatisticsGui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_calcbutton_clicked(); break;
        case 1: _t->on_doneButton_clicked(); break;
        case 2: _t->on_yearSelect_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_semesterSelect_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_classSelect_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_sectionSelect_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_labSelect_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject StatisticsGui::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StatisticsGui.data,
      qt_meta_data_StatisticsGui,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StatisticsGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StatisticsGui::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StatisticsGui.stringdata0))
        return static_cast<void*>(const_cast< StatisticsGui*>(this));
    return QWidget::qt_metacast(_clname);
}

int StatisticsGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
