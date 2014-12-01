/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Sep 28 17:00:18 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      25,   11,   11,   11, 0x0a,
      41,   11,   11,   11, 0x0a,
      56,   52,   11,   11, 0x0a,
      88,   84,   11,   11, 0x0a,
     112,   11,   11,   11, 0x0a,
     128,   11,   11,   11, 0x0a,
     142,   11,   11,   11, 0x0a,
     164,   52,   11,   11, 0x0a,
     190,   11,   11,   11, 0x0a,
     215,   11,   11,   11, 0x0a,
     229,   84,   11,   11, 0x0a,
     256,   84,   11,   11, 0x0a,
     300,  290,   11,   11, 0x0a,
     342,   11,   11,   11, 0x0a,
     363,   11,   11,   11, 0x0a,
     381,   11,   11,   11, 0x0a,
     393,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0newProject()\0newSubProject()\0"
    "newPaper()\0ind\0projectClicked(QModelIndex)\0"
    "str\0projectClicked(QString)\0deleteProject()\0"
    "addNewPaper()\0projectEntryChanged()\0"
    "paperClicked(QModelIndex)\0"
    "removePaperfromProject()\0deletePaper()\0"
    "addPapertoProject(QString)\0"
    "addPapertoProjectfromBox(QString)\0"
    "ind1,ind2\0paperDataChanged(QModelIndex,QModelIndex)\0"
    "printProjectBibtex()\0showJournalAbbv()\0"
    "openPaper()\0editPaper()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->newProject(); break;
        case 1: _t->newSubProject(); break;
        case 2: _t->newPaper(); break;
        case 3: _t->projectClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 4: _t->projectClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->deleteProject(); break;
        case 6: _t->addNewPaper(); break;
        case 7: _t->projectEntryChanged(); break;
        case 8: _t->paperClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 9: _t->removePaperfromProject(); break;
        case 10: _t->deletePaper(); break;
        case 11: _t->addPapertoProject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->addPapertoProjectfromBox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->paperDataChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 14: _t->printProjectBibtex(); break;
        case 15: _t->showJournalAbbv(); break;
        case 16: _t->openPaper(); break;
        case 17: _t->editPaper(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
