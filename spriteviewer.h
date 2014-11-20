#ifndef SPRITEVIEWER_H
#define SPRITEVIEWER_H

#include <QWidget>

namespace Ui {
class SpriteVIewer;
}

class SpriteVIewer : public QWidget
{
    Q_OBJECT

public:
    explicit SpriteVIewer(QWidget *parent = 0);
    ~SpriteVIewer();

private:
    Ui::SpriteVIewer *ui;

public slots:
    void openFile();

};

#endif // SPRITEVIEWER_H
