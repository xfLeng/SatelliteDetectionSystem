#ifndef DRAWSKY_H
#define DRAWSKY_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPen>
#include <math.h>

/***************
 * 在相对应的位置绘制纬线
 * 和方位的 一个类
 *
********************/
class drawsky : public QGraphicsItem
{
public:
    drawsky(int x);
      QRectF boundingRect() const;  //限定图元的区域范围
      double returncenterx();
      double returncentery();
      int returnr();
  protected:
      void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);//用于Item的重新绘制

private:
        int w;
        int midradius;
      int radius;                          //底图圆半径
      int radiusTemp;                      //用来画里面两个圈的临时半径

};

#endif // DRAWSKY_H
