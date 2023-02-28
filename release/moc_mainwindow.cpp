/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../pole_zero_response_plotter/mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[38];
    char stringdata0[11];
    char stringdata1[5];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[21];
    char stringdata5[13];
    char stringdata6[2];
    char stringdata7[23];
    char stringdata8[23];
    char stringdata9[20];
    char stringdata10[19];
    char stringdata11[22];
    char stringdata12[28];
    char stringdata13[6];
    char stringdata14[34];
    char stringdata15[22];
    char stringdata16[12];
    char stringdata17[14];
    char stringdata18[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 4),  // "draw"
        QT_MOC_LITERAL(16, 0),  // ""
        QT_MOC_LITERAL(17, 15),  // "get_coordinates"
        QT_MOC_LITERAL(33, 20),  // "QList<QList<double>>"
        QT_MOC_LITERAL(54, 12),  // "QMouseEvent*"
        QT_MOC_LITERAL(67, 1),  // "e"
        QT_MOC_LITERAL(69, 22),  // "on_clearButton_clicked"
        QT_MOC_LITERAL(92, 22),  // "on_planeButton_clicked"
        QT_MOC_LITERAL(115, 19),  // "mousePlotPressEvent"
        QT_MOC_LITERAL(135, 18),  // "mousePlotMoveEvent"
        QT_MOC_LITERAL(154, 21),  // "mousePlotReleaseEvent"
        QT_MOC_LITERAL(176, 27),  // "on_sliderScale_valueChanged"
        QT_MOC_LITERAL(204, 5),  // "value"
        QT_MOC_LITERAL(210, 33),  // "on_sliderSensitivity_valueCha..."
        QT_MOC_LITERAL(244, 21),  // "on_typeButton_clicked"
        QT_MOC_LITERAL(266, 11),  // "resizeEvent"
        QT_MOC_LITERAL(278, 13),  // "QResizeEvent*"
        QT_MOC_LITERAL(292, 5)   // "event"
    },
    "MainWindow",
    "draw",
    "",
    "get_coordinates",
    "QList<QList<double>>",
    "QMouseEvent*",
    "e",
    "on_clearButton_clicked",
    "on_planeButton_clicked",
    "mousePlotPressEvent",
    "mousePlotMoveEvent",
    "mousePlotReleaseEvent",
    "on_sliderScale_valueChanged",
    "value",
    "on_sliderSensitivity_valueChanged",
    "on_typeButton_clicked",
    "resizeEvent",
    "QResizeEvent*",
    "event"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    1,   81,    2, 0x08,    2 /* Private */,
       7,    0,   84,    2, 0x08,    4 /* Private */,
       8,    0,   85,    2, 0x08,    5 /* Private */,
       9,    1,   86,    2, 0x08,    6 /* Private */,
      10,    1,   89,    2, 0x08,    8 /* Private */,
      11,    1,   92,    2, 0x08,   10 /* Private */,
      12,    1,   95,    2, 0x08,   12 /* Private */,
      14,    1,   98,    2, 0x08,   14 /* Private */,
      15,    0,  101,    2, 0x08,   16 /* Private */,
      16,    1,  102,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 4, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'draw'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_coordinates'
        QtPrivate::TypeAndForceComplete<QVector<QVector<double>>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>,
        // method 'on_clearButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_planeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mousePlotPressEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>,
        // method 'mousePlotMoveEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>,
        // method 'mousePlotReleaseEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>,
        // method 'on_sliderScale_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_sliderSensitivity_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_typeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resizeEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->draw(); break;
        case 1: { QList<QList<double>> _r = _t->get_coordinates((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QList<double>>*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->on_clearButton_clicked(); break;
        case 3: _t->on_planeButton_clicked(); break;
        case 4: _t->mousePlotPressEvent((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 5: _t->mousePlotMoveEvent((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 6: _t->mousePlotReleaseEvent((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 7: _t->on_sliderScale_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_sliderSensitivity_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_typeButton_clicked(); break;
        case 10: _t->resizeEvent((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        default: ;
        }
    }
}

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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
