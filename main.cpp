#include "spriteviewer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpriteVIewer w;
    w.show();

    return a.exec();
}
