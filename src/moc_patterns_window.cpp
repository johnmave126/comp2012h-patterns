/****************************************************************************
** PatternsMainWindow meta object code from reading C++ file 'patterns_window.h'
**
** Created by Qt MOC ($Id: qt/moc_yacc.cpp   3.3.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/patterns_window.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *PatternsMainWindow::className() const
{
    return "PatternsMainWindow";
}

QMetaObject *PatternsMainWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PatternsMainWindow( "PatternsMainWindow", &PatternsMainWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PatternsMainWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PatternsMainWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PatternsMainWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PatternsMainWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PatternsMainWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUMethod slot_0 = {"OnLoadFile", 0, 0 };
    static const QUMethod slot_1 = {"OnLoadBrute", 0, 0 };
    static const QUMethod slot_2 = {"OnLoadFast", 0, 0 };
    static const QUMethod slot_3 = {"OnExit", 0, 0 };
    static const QUMethod slot_4 = {"ShowAbout", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "OnLoadFile()", &slot_0, QMetaData::Public },
	{ "OnLoadBrute()", &slot_1, QMetaData::Public },
	{ "OnLoadFast()", &slot_2, QMetaData::Public },
	{ "OnExit()", &slot_3, QMetaData::Public },
	{ "ShowAbout()", &slot_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"PatternsMainWindow", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PatternsMainWindow.setMetaObject( metaObj );
    return metaObj;
}

void* PatternsMainWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PatternsMainWindow" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool PatternsMainWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: OnLoadFile(); break;
    case 1: OnLoadBrute(); break;
    case 2: OnLoadFast(); break;
    case 3: OnExit(); break;
    case 4: ShowAbout(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PatternsMainWindow::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PatternsMainWindow::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool PatternsMainWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
