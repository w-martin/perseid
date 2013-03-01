#include <QtGui/QApplication>
#include "perseid.hpp"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    perseid foo;
    foo.show();
    return app.exec();
}

