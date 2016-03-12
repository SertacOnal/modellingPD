/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "openFileRight"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "openVideo"
QT_MOC_LITERAL(4, 36, 4), // "Play"
QT_MOC_LITERAL(5, 41, 5), // "Pause"
QT_MOC_LITERAL(6, 47, 14), // "ForwardRelease"
QT_MOC_LITERAL(7, 62, 14), // "ReverseRelease"
QT_MOC_LITERAL(8, 77, 14), // "timelineChange"
QT_MOC_LITERAL(9, 92, 18), // "deactivateControls"
QT_MOC_LITERAL(10, 111, 16), // "activateControls"
QT_MOC_LITERAL(11, 128, 7), // "gotoSec"
QT_MOC_LITERAL(12, 136, 10), // "initialize"
QT_MOC_LITERAL(13, 147, 7), // "uiSetup"
QT_MOC_LITERAL(14, 155, 14), // "radio0Selected"
QT_MOC_LITERAL(15, 170, 14), // "radio1Selected"
QT_MOC_LITERAL(16, 185, 14), // "radio2Selected"
QT_MOC_LITERAL(17, 200, 14), // "radio3Selected"
QT_MOC_LITERAL(18, 215, 10), // "closeEvent"
QT_MOC_LITERAL(19, 226, 12), // "QCloseEvent*"
QT_MOC_LITERAL(20, 239, 5), // "event"
QT_MOC_LITERAL(21, 245, 14), // "handleRotation"
QT_MOC_LITERAL(22, 260, 12), // "restRotation"
QT_MOC_LITERAL(23, 273, 7) // "Animate"

    },
    "MainWindow\0openFileRight\0\0openVideo\0"
    "Play\0Pause\0ForwardRelease\0ReverseRelease\0"
    "timelineChange\0deactivateControls\0"
    "activateControls\0gotoSec\0initialize\0"
    "uiSetup\0radio0Selected\0radio1Selected\0"
    "radio2Selected\0radio3Selected\0closeEvent\0"
    "QCloseEvent*\0event\0handleRotation\0"
    "restRotation\0Animate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x08 /* Private */,
       3,    0,  115,    2, 0x08 /* Private */,
       4,    0,  116,    2, 0x08 /* Private */,
       5,    0,  117,    2, 0x08 /* Private */,
       6,    0,  118,    2, 0x08 /* Private */,
       7,    0,  119,    2, 0x08 /* Private */,
       8,    0,  120,    2, 0x08 /* Private */,
       9,    0,  121,    2, 0x08 /* Private */,
      10,    0,  122,    2, 0x08 /* Private */,
      11,    0,  123,    2, 0x08 /* Private */,
      12,    0,  124,    2, 0x08 /* Private */,
      13,    0,  125,    2, 0x08 /* Private */,
      14,    0,  126,    2, 0x08 /* Private */,
      15,    0,  127,    2, 0x08 /* Private */,
      16,    0,  128,    2, 0x08 /* Private */,
      17,    0,  129,    2, 0x08 /* Private */,
      18,    1,  130,    2, 0x08 /* Private */,
      21,    0,  133,    2, 0x08 /* Private */,
      22,    0,  134,    2, 0x08 /* Private */,
      23,    0,  135,    2, 0x08 /* Private */,

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
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->openFileRight(); break;
        case 1: _t->openVideo(); break;
        case 2: _t->Play(); break;
        case 3: _t->Pause(); break;
        case 4: _t->ForwardRelease(); break;
        case 5: _t->ReverseRelease(); break;
        case 6: _t->timelineChange(); break;
        case 7: _t->deactivateControls(); break;
        case 8: _t->activateControls(); break;
        case 9: _t->gotoSec(); break;
        case 10: _t->initialize(); break;
        case 11: _t->uiSetup(); break;
        case 12: _t->radio0Selected(); break;
        case 13: _t->radio1Selected(); break;
        case 14: _t->radio2Selected(); break;
        case 15: _t->radio3Selected(); break;
        case 16: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 17: _t->handleRotation(); break;
        case 18: _t->restRotation(); break;
        case 19: _t->Animate(); break;
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
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
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
QT_END_MOC_NAMESPACE
