/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[398];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 31), // "on_actionLoad_New_Lab_triggered"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 31), // "on_actionAdd_Students_triggered"
QT_MOC_LITERAL(4, 76, 26), // "on_actionComment_triggered"
QT_MOC_LITERAL(5, 103, 24), // "on_displayButton_clicked"
QT_MOC_LITERAL(6, 128, 27), // "on_actionLoad_Lab_triggered"
QT_MOC_LITERAL(7, 156, 31), // "click_lab_in_existing_labs_menu"
QT_MOC_LITERAL(8, 188, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 210, 26), // "on_classlist_doubleClicked"
QT_MOC_LITERAL(10, 237, 5), // "index"
QT_MOC_LITERAL(11, 243, 28), // "on_sectionlist_doubleClicked"
QT_MOC_LITERAL(12, 272, 28), // "on_studentlist_doubleClicked"
QT_MOC_LITERAL(13, 301, 24), // "on_lablist_doubleClicked"
QT_MOC_LITERAL(14, 326, 24), // "on_disjava_doubleClicked"
QT_MOC_LITERAL(15, 351, 18), // "on_years_activated"
QT_MOC_LITERAL(16, 370, 4), // "arg1"
QT_MOC_LITERAL(17, 375, 22) // "on_semesters_activated"

    },
    "MainWindow\0on_actionLoad_New_Lab_triggered\0"
    "\0on_actionAdd_Students_triggered\0"
    "on_actionComment_triggered\0"
    "on_displayButton_clicked\0"
    "on_actionLoad_Lab_triggered\0"
    "click_lab_in_existing_labs_menu\0"
    "on_pushButton_clicked\0on_classlist_doubleClicked\0"
    "index\0on_sectionlist_doubleClicked\0"
    "on_studentlist_doubleClicked\0"
    "on_lablist_doubleClicked\0"
    "on_disjava_doubleClicked\0on_years_activated\0"
    "arg1\0on_semesters_activated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    1,   91,    2, 0x08 /* Private */,
      11,    1,   94,    2, 0x08 /* Private */,
      12,    1,   97,    2, 0x08 /* Private */,
      13,    1,  100,    2, 0x08 /* Private */,
      14,    1,  103,    2, 0x08 /* Private */,
      15,    1,  106,    2, 0x08 /* Private */,
      17,    1,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   10,
    QMetaType::Void, QMetaType::QModelIndex,   10,
    QMetaType::Void, QMetaType::QModelIndex,   10,
    QMetaType::Void, QMetaType::QModelIndex,   10,
    QMetaType::Void, QMetaType::QModelIndex,   10,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionLoad_New_Lab_triggered(); break;
        case 1: _t->on_actionAdd_Students_triggered(); break;
        case 2: _t->on_actionComment_triggered(); break;
        case 3: _t->on_displayButton_clicked(); break;
        case 4: _t->on_actionLoad_Lab_triggered(); break;
        case 5: _t->click_lab_in_existing_labs_menu(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_classlist_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_sectionlist_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->on_studentlist_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_lablist_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->on_disjava_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 12: _t->on_years_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_semesters_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
