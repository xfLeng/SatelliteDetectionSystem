#ifndef SKYPLOT_H
#define SKYPLOT_H

#include <QDialog>
#include <QGraphicsview>
#include<QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>
#include <math.h>
#include <QFont>
#include <QWidget>
#include <QOpenGLWidget>
#include<QPainter>
#include "star.h"
#include "drawsky.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QObject>
#include <QEvent>
#include <QPixmap>
#include <QGraphicsItemGroup>
#include <Qlist>
#include "ConstData.h"
#include "datatype.h"
#include "SimDataType.h"
#include <QResizeEvent>
#include <QDebug>


namespace Ui {
class Skyplot;
}
/***************
 * 绘制星空图的一个类
 * 功能：绘制星空图
******************/
class Skyplot : public QDialog
{
    Q_OBJECT

public:
    explicit Skyplot(QWidget *parent = 0);
    ~Skyplot();
    void closeEvent(QCloseEvent *event);
    void changeEvent(QEvent *event);
    void resizeEvent(QResizeEvent *event);
Q_SIGNALS:
    void sendcs();
public Q_SLOTS:
    void updatedata(const QVariant &test);//更新数据的槽
private slots:
    void on_BDS_cek_clicked(bool checked);

    void on_GPS_cek_clicked(bool checked);

    void on_GLS_cek_clicked(bool checked);

    void on_GAO_cek_clicked(bool checked);

private:
    /*
    * @功能:初始化窗体
    * @参数:无
    * @返回值:无
    */
    void initWindow();
    /*
    * @功能:绘制星空图
    * @参数:无
    * @返回值:无
    */
    void drawSkyMap();
    /*
    * @功能:创建卫星
    * @参数:无
    * @返回值:无
    */
    void createSat(const ObsData &obs );
    /*
    * @功能:将卫星图元添加到相对应的容器中
    * @参数:无
    * @返回值:无
    */
    void addItemToScene(const ObsData &data, QList<QGraphicsItem *> &list, star::SatStyle type);
    /*
    * @功能:从scene中清除掉item
    * @参数:QList<QGraphicsItem*>
    * @返回值:无
    */
    void removeItemFromScene(QList<QGraphicsItem *> &list);

private:
    Ui::Skyplot *ui;
    QList<QGraphicsItem*> m_skyitem;//用于存放地图的图元
    //QList<QGraphicsItem*> m_bditem;//存放北斗图元（每增加一个圆就将其存在该容器中而且将里面）
    //QList<QGraphicsItem*> m_gpsitem;//存放Gps图元
    //QList<QGraphicsItem*> m_glonassitem;//存放Glonass图元
    //QList<QGraphicsItem*> m_galileoitem;//存放Galileo图元
	QList<QGraphicsItem*>m_sateliteitem;
	
    int m_bdstyle;//图中北斗图元的状态 0不存在 1 存在
    int m_gpsstyle;//图中gps图元的状态 0不存在 1 存在
    int m_glonassstyle;//图中glonass图元的状态 0不存在 1 存在
    int m_galileostyle;//图中galileo图元的状态 0不存在 1 存在
    QGraphicsScene *m_scene;
    QGraphicsItemGroup *m_group;
   /* ObsData m_BD2SatStatus;
    ObsData m_GPSSatStatus;
    ObsData m_GALSatStatus;
    ObsData m_GLOSatStatus;*/
	ObsData m_SatSatStatus;
    double m_x;//用于返回中心点的x坐标
    double m_y;//用于返回中心点的y坐标
    int m_r;//用于获得界面赤道的半径
	//bool skysize;
};

#endif // SKYPLOT_H
