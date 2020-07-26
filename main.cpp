#include "principal.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //objeto para manejar las traducciones
    QTranslator traducion;
    //solicitando un idioma
    QStringList idiomas;
    idiomas << "Ruso" << "Español";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                           "Idioma",
                                           "seleccione un idioma",
                                           idiomas);
    //dependiendo del ideoma seleccionado cargar el archivo de traduccion
    if (idiomaSeleccionado == "Ruso"){
        traducion.load(":/Calculadora_ru_RU.qm");
    }
    //si es diferente de español se instala la traduccion en toda la aplicacion
    if(idiomaSeleccionado != "Español"){
        a.installTranslator(&traducion);
    }
    //muestra la ventana principal
    Principal w;
    w.show();
    return a.exec();
}
