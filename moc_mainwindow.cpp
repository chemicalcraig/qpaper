/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x0a,
      43,   11,   11,   11, 0x0a,
      56,   11,   11,   11, 0x0a,
      72,   11,   11,   11, 0x0a,
      83,   12,   11,   11, 0x0a,
     115,  111,   11,   11, 0x0a,
     139,  111,   11,   11, 0x0a,
     168,   11,   11,   11, 0x0a,
     184,   11,   11,   11, 0x0a,
     198,   11,   11,   11, 0x0a,
     211,   11,   11,   11, 0x0a,
     233,   12,   11,   11, 0x0a,
     268,  259,   11,   11, 0x0a,
     299,   11,   11,   11, 0x0a,
     324,   11,   11,   11, 0x0a,
     344,  338,   11,   11, 0x0a,
     374,  368,   11,   11, 0x0a,
     405,  111,   11,   11, 0x0a,
     449,  439,   11,   11, 0x0a,
     491,   11,   11,   11, 0x0a,
     512,   11,   11,   11, 0x0a,
     530,   11,   11,   11, 0x0a,
     542,   11,   11,   11, 0x0a,
     554,   11,   11,   11, 0x0a,
     577,   11,   11,   11, 0x0a,
     587,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0ind\0headerClicked(QModelIndex)\0"
    "newProject()\0newSubProject()\0newPaper()\0"
    "projectClicked(QModelIndex)\0str\0"
    "projectClicked(QString)\0"
    "projectClickedBooks(QString)\0"
    "deleteProject()\0addNewPaper()\0"
    "addNewBook()\0projectEntryChanged()\0"
    "paperClicked(QModelIndex)\0ind,mult\0"
    "paperClicked(QModelIndex,bool)\0"
    "removePaperfromProject()\0deletePaper()\0"
    "nproj\0addPaperstoProject(int)\0n,str\0"
    "addPapertoProject(int,QString)\0"
    "addPapertoProjectfromBox(QString)\0"
    "ind1,ind2\0paperDataChanged(QModelIndex,QModelIndex)\0"
    "printProjectBibtex()\0showJournalAbbv()\0"
    "openPaper()\0editPaper()\0editPaper(QModelIndex)\0"
    "viewBib()\0switchView()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->headerClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->newProject(); break;
        case 2: _t->newSubProject(); break;
        case 3: _t->newPaper(); break;
        case 4: _t->projectClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: _t->projectClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->projectClickedBooks((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->deleteProject(); break;
        case 8: _t->addNewPaper(); break;
        case 9: _t->addNewBook(); break;
        case 10: _t->projectEntryChanged(); break;
        case 11: _t->paperClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 12: _t->paperClicked((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->removePaperfromProject(); break;
        case 14: _t->deletePaper(); break;
        case 15: _t->addPaperstoProject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->addPapertoProject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 17: _t->addPapertoProjectfromBox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->paperDataChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 19: _t->printProjectBibtex(); break;
        case 20: _t->showJournalAbbv(); break;
        case 21: _t->openPaper(); break;
        case 22: _t->editPaper(); break;
        case 23: _t->editPaper((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 24: _t->viewBib(); break;
        case 25: _t->switchView(); break;
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
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
