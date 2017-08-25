#if _MSC_VER >=1600
#pragma execution_character_set("utf-8")
#endif

#include "drawsky.h"

drawsky::drawsky(int x)
{

    w=x-30;
    radius=w/2;
    //底图圆半径
    midradius=radius-8;
    radius=radius-18;

}
QRectF drawsky::boundingRect()const
{
    return QRectF(0,0,w,w);
}
/***************************
 * 作用：绘制星空图中的纬线和经线
 * 以及方向
***********************/
void drawsky::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing,true);//反锯齿
    painter->setPen(QPen(Qt::black,2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
    painter->drawEllipse((boundingRect().width()-midradius*2)/2,(boundingRect().width()-midradius*2)/2,midradius*2,midradius*2);
    painter->drawText(midradius+4,4,"N");
    painter->drawText(midradius+4,(midradius+8)*2+2,"S");
    painter->drawText(-7,midradius+8+4,"W");
    painter->drawText((midradius+8)*2+2,midradius+8+4,"E");
    painter->translate(midradius+8,midradius+8);
    painter->setPen(QPen(Qt::black,2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
    for (int i = 0; i < 12; ++i) {
        painter->setRenderHint(QPainter::Antialiasing,true);
        painter->drawLine(-midradius,0,-midradius+4,0);
        painter->rotate(30.0);
    }

    painter->translate(-(midradius+8),-(midradius+8));
    painter->drawEllipse((boundingRect().width()-radius*2)/2,(boundingRect().width()-radius*2)/2,radius*2,radius*2);//绘制0度圆

    painter->setPen(QPen(Qt::black,1,Qt::DotLine,Qt::RoundCap,Qt::RoundJoin));
    //radiusTemp=(int)(radius*cos(30*M_PI/180));
    radiusTemp=(int)((radius/3)*2);
    painter->drawEllipse((boundingRect().width()-radiusTemp*2)/2,(boundingRect().width()-radiusTemp*2)/2,radiusTemp*2,radiusTemp*2);//绘制30度圆
    radiusTemp=(int)(radius/3);
    painter->drawEllipse((boundingRect().width()-radiusTemp*2)/2,(boundingRect().width()-radiusTemp*2)/2,radiusTemp*2,radiusTemp*2);//绘制60度圆
    painter->drawLine(radius+18,18,radius+18,(radius)*2+18);
    painter->drawLine(18,radius+18,radius*2+18,radius+18);
    painter->setPen(QPen(Qt::black,2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));



}
/***************************
 * 作用：返回中心点的x坐标
***********************/
double drawsky::returncenterx()
{
    double i;
    i=boundingRect().left()+midradius+8;
    return i;
}
/***************************
 * 作用：返回中心点的y坐标
***********************/
double drawsky::returncentery()
{
    double i;
    i=boundingRect().top()+midradius+8;
    return i;
}
/***************************
 * 作用：返回界面赤道的半径
***********************/
int drawsky::returnr()
{
    return (midradius-10);
}
