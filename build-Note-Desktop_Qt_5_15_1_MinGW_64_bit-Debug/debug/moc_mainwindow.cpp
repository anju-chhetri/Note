/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Note/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "show_information"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 15), // "return_richText"
QT_MOC_LITERAL(4, 45, 8), // "MarkDown"
QT_MOC_LITERAL(5, 54, 4), // "HTML"
QT_MOC_LITERAL(6, 59, 9), // "plainText"
QT_MOC_LITERAL(7, 69, 17), // "close_application"
QT_MOC_LITERAL(8, 87, 5), // "about"
QT_MOC_LITERAL(9, 93, 18), // "text_color_changed"
QT_MOC_LITERAL(10, 112, 9), // "find_text"
QT_MOC_LITERAL(11, 122, 9), // "copy_text"
QT_MOC_LITERAL(12, 132, 8), // "cut_text"
QT_MOC_LITERAL(13, 141, 10), // "paste_text"
QT_MOC_LITERAL(14, 152, 9), // "redo_text"
QT_MOC_LITERAL(15, 162, 9), // "undo_text"
QT_MOC_LITERAL(16, 172, 9), // "save_file"
QT_MOC_LITERAL(17, 182, 13), // "check_save_as"
QT_MOC_LITERAL(18, 196, 10), // "check_open"
QT_MOC_LITERAL(19, 207, 8), // "new_file"
QT_MOC_LITERAL(20, 216, 11), // "change_font"
QT_MOC_LITERAL(21, 228, 19) // "call_increase_count"

    },
    "MainWindow\0show_information\0\0"
    "return_richText\0MarkDown\0HTML\0plainText\0"
    "close_application\0about\0text_color_changed\0"
    "find_text\0copy_text\0cut_text\0paste_text\0"
    "redo_text\0undo_text\0save_file\0"
    "check_save_as\0check_open\0new_file\0"
    "change_font\0call_increase_count"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x0a /* Public */,
       3,    0,  115,    2, 0x0a /* Public */,
       4,    0,  116,    2, 0x0a /* Public */,
       5,    0,  117,    2, 0x0a /* Public */,
       6,    0,  118,    2, 0x0a /* Public */,
       7,    0,  119,    2, 0x0a /* Public */,
       8,    0,  120,    2, 0x0a /* Public */,
       9,    0,  121,    2, 0x0a /* Public */,
      10,    0,  122,    2, 0x0a /* Public */,
      11,    0,  123,    2, 0x0a /* Public */,
      12,    0,  124,    2, 0x0a /* Public */,
      13,    0,  125,    2, 0x0a /* Public */,
      14,    0,  126,    2, 0x0a /* Public */,
      15,    0,  127,    2, 0x0a /* Public */,
      16,    0,  128,    2, 0x0a /* Public */,
      17,    0,  129,    2, 0x0a /* Public */,
      18,    0,  130,    2, 0x0a /* Public */,
      19,    0,  131,    2, 0x0a /* Public */,
      20,    0,  132,    2, 0x0a /* Public */,
      21,    0,  133,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->show_information(); break;
        case 1: _t->return_richText(); break;
        case 2: _t->MarkDown(); break;
        case 3: _t->HTML(); break;
        case 4: _t->plainText(); break;
        case 5: _t->close_application(); break;
        case 6: _t->about(); break;
        case 7: _t->text_color_changed(); break;
        case 8: _t->find_text(); break;
        case 9: _t->copy_text(); break;
        case 10: _t->cut_text(); break;
        case 11: _t->paste_text(); break;
        case 12: _t->redo_text(); break;
        case 13: _t->undo_text(); break;
        case 14: _t->save_file(); break;
        case 15: _t->check_save_as(); break;
        case 16: _t->check_open(); break;
        case 17: _t->new_file(); break;
        case 18: _t->change_font(); break;
        case 19: _t->call_increase_count(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
