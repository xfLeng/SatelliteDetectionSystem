#if _MSC_VER >=1600
#pragma execution_character_set("utf-8")
#endif

#include "star.h"

star::star(double x1,double y1)
{
    color[0]=QColor(0,0,255,100);//将定义的颜色加入颜色数组bd颜色
    color[1]=QColor(0,255,0,100);//gps颜色
    color[2]=QColor(0,255,255,100);//glonass颜色
    color[3]=QColor(255,0,255,100);//galileo颜色
    setAcceptHoverEvents(true);
    lx=x1;
    ly=y1;

    Azimuth=0;
    Elevation=0;
    Pseudorange=0;
    Carrier=0;
    posx=0;
    posy=0;
    posz=0;
    speed=0;

}
/*****************
 * 作用用于绘制卫星
**************/
void star::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //painter.setRenderHint(QPainter::Antialiasing,true);
    painter->setRenderHint(QPainter::Antialiasing,true);
    painter->setBrush(QBrush(color[starstyle]));
    painter->setPen(QPen(color[starstyle],Qt::NoPen));
    painter->drawEllipse(boundingRect());
    painter->setPen(QPen(Qt::white,1));
    painter->drawText(boundingRect(),starno,QTextOption(Qt::AlignCenter));
    //QString t=QString::number(10);
}
QRectF star::boundingRect()const
{
    return QRectF(lx-10,ly-10,20,20);
}
/*****************
 * 作用用于显示卫星
 * 信息
**************/
void star::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    QString str="";
    str+=QObject::tr("卫星编号：");
    str+=QString::number(starsno)+"\n";
    str+=QObject::tr(" 方位角：");
    str+=QString::number(Azimuth)+"°"+"\n";
    //QString("1")setText(QString("%1").arg((l.at(n).Pseudorange[0]*LightSpeed),0,'f',10));

    //str+=QString::number(Geolg);
    //str+="\n";
    str+=QObject::tr(" 俯仰角：");
    str+=QString::number(Elevation)+"°"+"\n";
    str+=QObject::tr("   伪距：");
    str+=QString("%1").arg(Pseudorange,0,'f',3)+"m"+"\n";
    //QString("%1").arg(Pseudorange,0,'f',10);
    str+=QObject::tr("   载波：");
    str+=QString::number(Carrier)+"mrad"+"\n";
    str+=QObject::tr("位置（X）：");
    str+=QString("%1").arg(posx,0,'f',3)+"m"+"\n";
    //QString("%1").arg(posx,0,'f',10)
    str+=QObject::tr("位置（Y）：");
    str+=QString("%1").arg(posy,0,'f',3)+"m"+"\n";
    //QString("%1").arg(posy,0,'f',10)
    str+=QObject::tr("位置（Z）：");
    str+=QString("%1").arg(posz,0,'f',3)+"m"+"\n";
    //QString("%1").arg(posz,0,'f',10)
    str+=QObject::tr("   速度：");
    str+=QString::number(speed)+"m/s"+"\n";
    //QWidget *wt=new QWidget();
    //str+=QString::number(Geolt);
    //str+="\n";
    //const QPoint &pos, const QString &text, QWidget *w, const QRect &rect, int msecShowTime
    //QToolTip::showText(QCursor::pos(),str,wt,QRect(QCursor::pos(),QSize(20,20)),500000000);
    QToolTip::showText(QCursor::pos(),str);
}
/***********************
 * 功能：设置卫星编号
 * 参数：no 卫星编号
*************************/
void star::setstarno(int no)
{
    starno=QString::number(no);
    starsno=starno.toInt();
}
/****************
 * 功能：设置卫星参数

*********************/
void star::setvalue(int starid,double Azimuth, double Elevation, double Pseudorange, double  Carrier, double posx, double posy, double posz, double speed)
{
    this->starno=starid;
    this->Azimuth=Azimuth;
    this->Elevation=Elevation;
    this->Pseudorange=Pseudorange;
    this->Carrier=Carrier;
    this->posx=posx;
    this->posy=posy;
    this->posz=posz;
    this->speed=speed;
}
void star::setstarstyle(int style)
{
    starstyle=style;
}
