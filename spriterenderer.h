#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include <QWidget>

class SpriteRenderer : public QWidget
{
    Q_OBJECT

    QPoint ptCenter, ptOffset;

    QPixmap texture;

    int intActiveExpression;

    bool boolShowGuides;

public:
    explicit SpriteRenderer(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);

signals:

public slots:
    void setXOffset(int offset);
    void setYOffset(int offset);

    void setXCenter(int offset);
    void setYCenter(int offset);

    void setExpression(int expression);

    void loadImage(QString path);

    void showGuides(bool show);
};

#endif // SPRITERENDERER_H
