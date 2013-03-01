#include <QtGui/QApplication>
#include "perseid.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    perseid foo;
    foo.show();
    return app.exec();
}

