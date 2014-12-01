/****************************************************************************
** Meta object code from reading C++ file 'newpaper.h'
**
** Created: Sun Sep 28 17:00:19 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "newpaper.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newpaper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewPaper[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      22,    9,    9,    9, 0x0a,
      41,   37,    9,    9, 0x0a,
      63,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NewPaper[] = {
    "NewPaper\0\0okClicked()\0showJournals()\0"
    "str\0entryChanged(QString)\0addPdf()\0"
};

void NewPaper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewPaper *_t = static_cast<NewPaper *>(_o);
        switch (_id) {
        case 0: _t->okClicked(); break;
        case 1: _t->showJournals(); break;
        case 2: _t->entryChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->addPdf(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NewPaper::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NewPaper::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewPaper,
      qt_meta_data_NewPaper, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewPaper::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewPaper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewPaper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewPaper))
        return static_cast<void*>(const_cast< NewPaper*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewPaper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
