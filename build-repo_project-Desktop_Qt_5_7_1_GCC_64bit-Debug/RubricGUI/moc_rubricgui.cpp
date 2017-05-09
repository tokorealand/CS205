/****************************************************************************
** Meta object code from reading C++ file 'rubricgui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../repo_project/RubricGUI/rubricgui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rubricgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RubricGUI_t {
    QByteArrayData data[14];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RubricGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RubricGUI_t qt_meta_stringdata_RubricGUI = {
    {
QT_MOC_LITERAL(0, 0, 9), // "RubricGUI"
QT_MOC_LITERAL(1, 10, 23), // "on_yearSelect_activated"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 4), // "arg1"
QT_MOC_LITERAL(4, 40, 27), // "on_semesterSelect_activated"
QT_MOC_LITERAL(5, 68, 24), // "on_classSelect_activated"
QT_MOC_LITERAL(6, 93, 23), // "on_createRubric_clicked"
QT_MOC_LITERAL(7, 117, 21), // "on_addSection_clicked"
QT_MOC_LITERAL(8, 139, 25), // "on_rubricSelect_activated"
QT_MOC_LITERAL(9, 165, 5), // "index"
QT_MOC_LITERAL(10, 171, 32), // "on_rubricsectionSelect_activated"
QT_MOC_LITERAL(11, 204, 23), // "on_deleteRubric_clicked"
QT_MOC_LITERAL(12, 228, 24), // "on_removeSection_clicked"
QT_MOC_LITERAL(13, 253, 21) // "on_doneButton_clicked"

    },
    "RubricGUI\0on_yearSelect_activated\0\0"
    "arg1\0on_semesterSelect_activated\0"
    "on_classSelect_activated\0"
    "on_createRubric_clicked\0on_addSection_clicked\0"
    "on_rubricSelect_activated\0index\0"
    "on_rubricsectionSelect_activated\0"
    "on_deleteRubric_clicked\0"
    "on_removeSection_clicked\0on_doneButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RubricGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    1,   67,    2, 0x08 /* Private */,
       5,    1,   70,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    1,   75,    2, 0x08 /* Private */,
      10,    1,   78,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,
      12,    0,   82,    2, 0x08 /* Private */,
      13,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RubricGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RubricGUI *_t = static_cast<RubricGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_yearSelect_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_semesterSelect_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_classSelect_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_createRubric_clicked(); break;
        case 4: _t->on_addSection_clicked(); break;
        case 5: _t->on_rubricSelect_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_rubricsectionSelect_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_deleteRubric_clicked(); break;
        case 8: _t->on_removeSection_clicked(); break;
        case 9: _t->on_doneButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject RubricGUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RubricGUI.data,
      qt_meta_data_RubricGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RubricGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RubricGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RubricGUI.stringdata0))
        return static_cast<void*>(const_cast< RubricGUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int RubricGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
