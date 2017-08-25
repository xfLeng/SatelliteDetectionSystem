#if _MSC_VER >=1600
#pragma execution_character_set("utf-8")
#endif

#include "skyplot.h"
#include "ui_skyplot.h"


Skyplot::Skyplot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Skyplot)
{
	//skysize = false;
    ui->setupUi(this);
	
    initWindow();
	//skysize = true;
}

Skyplot::~Skyplot()
{
    delete ui;
}

/*****************
 * 窗体变化事件用来处理窗体变化
*******************/
void Skyplot::changeEvent(QEvent *event)
{
   if(event->type() == QEvent::WindowStateChange)
   {


        drawSkyMap();
		createSat(m_SatSatStatus);
        m_scene->setSceneRect(((ui->graphicsView->width() -2 * m_r ) / 8),
                              ((ui->graphicsView->height() - 2 * m_r) / 4),
                              2 * m_r,
                              2 * m_r);//用于固定位置
	
        //this->layout()->invalidate();
		//this->repaint();
    }
	//this->repaint();
}

void Skyplot::on_BDS_cek_clicked(bool checked)//bd的槽
{
  /*  if(checked)
    {
        addItemToScene(m_BD2SatStatus, m_bditem, star::SatStyle::bd2);
    }
    else
    {
        removeItemFromScene(m_bditem);
    }*/
}

void Skyplot::on_GPS_cek_clicked(bool checked)//gps的槽
{
   /* if(checked)
    {
        addItemToScene(m_GPSSatStatus, m_gpsitem, star::SatStyle::gps);
    }
    else
    {
        removeItemFromScene(m_gpsitem);
    }*/
}

void Skyplot::on_GLS_cek_clicked(bool checked)//galonass的槽
{
   /* if(checked)
    {
        addItemToScene(m_GLOSatStatus, m_glonassitem, star::SatStyle::glonass);
    }
    else
    {
        removeItemFromScene(m_glonassitem);
    }*/
}

void Skyplot::on_GAO_cek_clicked(bool checked)//galileo的槽
{
    /*if(checked)
    {
        addItemToScene(m_GALSatStatus, m_galileoitem, star::SatStyle::galileo);
    }
    else
    {
        removeItemFromScene(m_galileoitem);
    }*/
}

void Skyplot::updatedata(const QVariant &t)//数据更新接收
{
    ObsData test = t.value<ObsData>();
    /***********************将不同卫星系统数据归类*******************************/
	if (test.AntId == 1)
	{
		switch (test.FreqID)
		{
		case 1:
			ui->BDS_cek->setChecked(true);
			ui->GPS_cek->setChecked(false);
			ui->GLS_cek->setChecked(false);
		
			break;
		case 3:
			ui->BDS_cek->setChecked(true);
			ui->GPS_cek->setChecked(false);
			ui->GLS_cek->setChecked(false);
			
			break;
		case 4:
			ui->GPS_cek->setChecked(true);
			ui->BDS_cek->setChecked(false);
			ui->GLS_cek->setChecked(false);
			
			break;
		case 7:
			ui->GPS_cek->setChecked(false);
			ui->BDS_cek->setChecked(false);
			ui->GLS_cek->setChecked(true);
			
			break;
		}
		m_SatSatStatus = test;
		createSat(m_SatSatStatus);
	}

   

}

/**************窗体大小变化事件***************/
void Skyplot::resizeEvent(QResizeEvent *)
{
    /*this->layout()->invalidate();*/
	this->repaint();
}

void Skyplot::closeEvent(QCloseEvent *)
{
    this->setVisible(false);
    emit sendcs();
}

/*
* @功能:初始化窗体
* @参数:无
* @返回值:无
*/
void Skyplot::initWindow()
{
   /* memset(&m_BD2SatStatus, 0, sizeof(ObsData));
    memset(&m_GPSSatStatus, 0, sizeof(ObsData));
    memset(&m_GALSatStatus, 0, sizeof(ObsData));
    memset(&m_GLOSatStatus, 0, sizeof(ObsData));*/

	//????
	memset(&m_SatSatStatus, 0, sizeof(ObsData));

    m_bdstyle = 0;
    m_gpsstyle = 0;
    m_glonassstyle = 0;
    m_galileostyle = 0;
    m_scene = new QGraphicsScene();
    drawSkyMap();
    ui->graphicsView->setScene(m_scene);
    /************布局****************************/
    QVBoxLayout *mainlayout = new QVBoxLayout(this);//主布局
    QHBoxLayout *cheklayout = new QHBoxLayout;//最上面选择按钮的布局
    cheklayout->addWidget(ui->BDS_cek);
    cheklayout->addWidget(ui->GPS_cek);
    cheklayout->addWidget(ui->GLS_cek);
    cheklayout->addWidget(ui->GAO_cek);
    cheklayout->addStretch(1);
    mainlayout->addLayout(cheklayout,1);
    mainlayout->addWidget(ui->graphicsView,1);
    /************设置右上角窗体按钮和名字与图标***************************/
    Qt::WindowFlags flag = Qt::Dialog;
    flag |= Qt::WindowMaximizeButtonHint;//放大
    flag |= Qt::WindowCloseButtonHint;//关闭
    flag |= Qt::WindowMinimizeButtonHint;//缩小
    setWindowFlags(flag);
    setWindowTitle(tr("星空图"));
    QColor color[4];
    color[0] = QColor(0,0,255,100);//将定义的颜色加入颜色数组
    color[1] = QColor(0,255,0,100);
    color[2] = QColor(0,255,255,100);
    color[3] = QColor(255,0,255,100);
    /*************设置ck中字的颜色*******************/
    QPalette pa;
    pa.setColor(QPalette::WindowText, color[0]);//设置label中的颜色
    ui->BDS_cek->setPalette(pa);
    pa.setColor(QPalette::WindowText, color[1]);
    ui->GPS_cek->setPalette(pa);
    pa.setColor(QPalette::WindowText, color[2]);
    ui->GLS_cek->setPalette(pa);
    pa.setColor(QPalette::WindowText, color[3]);
    ui->GAO_cek->setPalette(pa);
    ui->graphicsView->setAlignment(Qt::AlignCenter);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt:: ScrollBarAlwaysOff);
    ui->graphicsView->setScene(m_scene);
  /*  ui->BDS_cek->setChecked(true);
    ui->GPS_cek->setChecked(true);*/
	ui->BDS_cek->setEnabled(false);
	ui->GPS_cek->setEnabled(false);
	ui->GLS_cek->setEnabled(false);
	ui->GAO_cek->setVisible(false);

}

/*
* @功能:绘制星空图
* @参数:无
* @返回值:无
*/
void Skyplot::drawSkyMap()
{
    int i;
    i = ui->graphicsView->width();
    if(i > ui->graphicsView->height())
    {
        i = ui->graphicsView->height();
    }
    if(m_skyitem.size() >0)
    {
        removeItemFromScene(m_skyitem);
    }
    drawsky *sky = new drawsky(i);
    m_skyitem << sky;
    m_x = sky->returncenterx();//获得星空图中的中心坐标x
    m_y = sky->returncentery();//获得星空图中的中心坐标y
    m_r = sky->returnr();//获得星空图的半径
    m_scene->addItem(sky);
   // update();
}

void Skyplot::createSat(const ObsData &obs)
{
    /*****************将卫星图元添加到相对应的容器中***********************/
    /********************根据选择将图元添加到场景******************************/
	if (obs.FreqID != 0)
	{
		star::SatStyle type;
		if (ui->BDS_cek->isChecked())
		{
			type = star::SatStyle::bd2;
		}
		if (ui->GPS_cek->isChecked())
		{

			type = star::SatStyle::gps;
		}
		if (ui->GLS_cek->isChecked())
		{

			type = star::SatStyle::glonass;
		}
		if (ui->GAO_cek->isChecked())
		{

			type = star::SatStyle::galileo;
		}
		addItemToScene(obs, m_sateliteitem, type);


	}
	
}

void Skyplot::addItemToScene(const ObsData &data, QList<QGraphicsItem *> &list, star::SatStyle type)
{
    removeItemFromScene(list);
    for (int n = 0; n < data.SatCnt; n++)
    {
        star *star1 = new star(m_x, m_y);
        switch (type)
        {
        case star::SatStyle::bd2:
            star1->setstarstyle(star::SatStyle::bd2);
            break;
        case star::SatStyle::gps:
            star1->setstarstyle(star::SatStyle::gps);
            break;
        case star::SatStyle::glonass:
            star1->setstarstyle(star::SatStyle::glonass);
            break;
        case star::SatStyle::galileo:
            star1->setstarstyle(star::SatStyle::galileo);
            break;
        }

        list << star1;
        star1->setvalue(data.SatObs[n].SatID, data.SatObs[n].Azimuth, data.SatObs[n].Elevation,
                (data.SatObs[n].Pseudorange[0])*LightSpeed, data.SatObs[n].Carrier,
                data.SatObs[n].SatPos[0], data.SatObs[n].SatPos[1], data.SatObs[n].SatPos[2],
                sqrt((pow(data.SatObs[n].SatVel[0], 2) + pow(data.SatObs[n].SatVel[1], 2) + pow(data.SatObs[n].SatVel[2], 2))));
        star1->setstarno(data.SatObs[n].SatID);
        /**************根据卫星俯仰角计算其在星空图中的位置****************/
        double angle = data.SatObs[n].Azimuth + 90.0;
        angle = (angle / 180.0) * PI;  //转换为弧度
        double l = m_r *((90 - data.SatObs[n].Elevation) / 90.0);       //卫星位置距星空图中心的距离
        if (data.SatObs[n].Elevation < 0) //不绘制俯仰角小于0度的卫星
        {
            continue;
        }
        double x1 = -l*cos(angle);
        double y1 = -l*sin(angle);
        star1->setPos(x1, y1);
    }

    for (int i = 0; i < list.size(); ++i)
    {
        m_scene->addItem(list.at(i));
    }
	ui->graphicsView->setScene(m_scene);//更新界面
	ui->graphicsView->update();
	
}

void Skyplot::removeItemFromScene(QList<QGraphicsItem *> &list)
{
    for (int i = 0; i < list.size(); ++i)
    {
        m_scene->removeItem(list.at(i));
    }
	qDeleteAll(list);
    list.clear();
}
