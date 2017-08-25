#ifndef STAR_H
#define STAR_H
#include <QGraphicsItem>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QBrush>
#include <QPen>
#include <QToolTip>
#include <math.h>
#include <QString>
#include <QWidget>
#include <QObject>
/************
* 在相对应的位置绘制卫星和标号的
* 一个类
*
**************/
class star :public QGraphicsItem
{
public:
	explicit star(double x1, double y1);//卫星系统的类型
	QRectF boundingRect() const;  //限定图元的区域范围
	void hoverEnterEvent(QGraphicsSceneHoverEvent *event);//鼠标放在上显示卫星相关信息
	void setstarno(int no);//设置卫星号
	void setstarstyle(int style);//设置卫星系统类型
	enum SatStyle//卫星系统类型
	{
		bd2 = 0,
		gps,
		glonass,
		galileo
	};
	void setvalue(int starid, double Azimuth, double Elevation, double Pseudorange,
		double Carrier, double posx, double posy, double posz, double speed);//用于设置弹出窗体的卫星参数

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);//用于Item的重新绘制
	private slots:
	void uppos();//更新卫星的位置
private:
	double lx = 0;//坐标
	double ly = 0;
	QString starno;
	QColor color[4];//卫星系统颜色数组
	int starstyle = 0;//卫星系统类型：0.bd,1.gps，2.glonass，3.galileo
	int starsno;//卫星号
	double Azimuth;//方位角
	double  Elevation;//俯仰角
	double Pseudorange;//伪距
	double Carrier;//载波
	double posx;//位置X
	double posy;//位置Y
	double posz;//位置Z
	double speed;//速度
};

#endif // STAR_H
