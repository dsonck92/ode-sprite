#include "spriterenderer.h"

#include <QPainter>


SpriteRenderer::SpriteRenderer(QWidget *parent) :
    QWidget(parent)
{
    intActiveExpression = 0;
    boolShowGuides = false;
}

void SpriteRenderer::showGuides(bool show)
{
    boolShowGuides = show;
    update();
}

void SpriteRenderer::setXOffset(int offset)
{
    ptOffset.setX(offset);
    update();
}

void SpriteRenderer::setYOffset(int offset)
{
    ptOffset.setY(offset);
    update();
}

void SpriteRenderer::setXCenter(int offset)
{
    ptCenter.setX(offset);
    update();
}

void SpriteRenderer::setYCenter(int offset)
{
    ptCenter.setY(offset);
    update();
}

void SpriteRenderer::setExpression(int expression)
{
    intActiveExpression = expression;
    update();
}

void SpriteRenderer::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    QPoint topleft = QPoint((width() - texture.width()/2)/2,(height() - texture.height())/2);

    p.drawPixmap(QRect(topleft,QSize(texture.width()/2,texture.height())),texture,QRect(texture.width()/2,0,texture.width()/2,texture.height()));

    QPoint exprTopleft = topleft + (ptCenter - ptOffset);
    QSize exprSize = QSize(texture.width()/4,texture.width()/4);
    QPoint exprSource = QPoint(exprSize.width()*(intActiveExpression%2),exprSize.height()*(intActiveExpression/2));

    p.drawPixmap(QRect(exprTopleft,exprSize),texture,QRect(exprSource,exprSize));

    exprTopleft = QPoint(0,exprSize.height());
    QSize zoom = exprSize * 4;

    p.drawPixmap(QRect(exprTopleft,zoom),texture,QRect(QPoint(texture.width()/2,0)+(ptCenter-ptOffset),exprSize));
    p.drawPixmap(QRect(exprTopleft,zoom),texture,QRect(exprSource,exprSize));

    if(boolShowGuides)
    {
        p.drawLine(QPointF(ptCenter.x()+topleft.x(),exprSize.height()),QPointF(ptCenter.x()+topleft.x(),height()-texture.height()));

        p.drawLine(QPointF(0,ptCenter.y()+topleft.y()),QPointF(width(),ptCenter.y()+topleft.y()));

        p.drawLine(QPointF(0,ptOffset.y()),QPointF(width(),ptOffset.y()));
    }
    int I;
    for(I = 0;I<8;I++)
    {
        exprTopleft = QPoint(exprSize.width()*I,0);
        exprSource = QPoint(exprSize.width()*(I%2),exprSize.height()*(I/2));

        p.drawPixmap(QRect(exprTopleft,exprSize),texture,QRect(exprSource,exprSize));
        if(boolShowGuides)p.drawLine(QPointF(ptOffset.x()+exprTopleft.x(),0),QPointF(ptOffset.x()+exprTopleft.x(),exprSize.height()));

        if(I == intActiveExpression)
        {
            p.drawRect(QRect(exprTopleft,exprSize));
        }

        topleft = QPoint((texture.width()*I/2),(height() - texture.height()));

        p.drawPixmap(QRect(topleft,QSize(texture.width()/2,texture.height())),texture,QRect(texture.width()/2,0,texture.width()/2,texture.height()));

        exprTopleft = topleft + (ptCenter - ptOffset);

        p.drawPixmap(QRect(exprTopleft,exprSize),texture,QRect(exprSource,exprSize));

    }


}

void SpriteRenderer::loadImage(QString path)
{
    texture = QPixmap(path);
    update();
}
