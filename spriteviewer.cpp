#include "spriteviewer.h"
#include "ui_spriteviewer.h"

#include <QFileDialog>

SpriteVIewer::SpriteVIewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpriteVIewer)
{
    ui->setupUi(this);
}

SpriteVIewer::~SpriteVIewer()
{
    delete ui;
}

void SpriteVIewer::openFile()
{
    QString filename = QFileDialog::getOpenFileName(this,"Select sprite texture",QString(),"Images (*.png *.bmp *.jpg)");

    if(!filename.isNull())
    {
        ui->fileName->setText(filename);

        ui->view->loadImage(filename);
    }
}
