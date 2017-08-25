#if _MSC_VER >=1600
#pragma execution_character_set("utf-8")
#endif
#include "DopFrom.h"
#include "ui_DopFrom.h"
#include <qlayout.h>
#include <qwt_plot.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_canvas.h>
#include <qwt_scale_draw.h>
#include <qwt_legend.h>
#include <qwt_point_data.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_layout.h>
#include <qwt_text.h>
#include <qwt_symbol.h>
#include <qwt_math.h>
#include <QVBoxLayout>
#include <math.h>


DopFrom::DopFrom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DopFrom)
{
    ui->setupUi(this);
    WinIni();
}

DopFrom::~DopFrom()
{
    delete ui;
}

void DopFrom::setHDop(double hdopvalue, int time)
{
    double midtime=time;
    midtime=midtime/100.0;
    m_HDoplist<<QPointF(midtime,hdopvalue);
    m_HDopCurve->setSamples(m_HDoplist);
    m_DopPlot->replot();

}

void DopFrom::setVDop(double vdopvalue, int time)
{
    double midtime=time;
    midtime=midtime/100.0;
    m_VDoplist<<QPointF(midtime,vdopvalue);
    m_VDopCurve->setSamples(m_VDoplist);
    m_DopPlot->replot();
}

void DopFrom::setTDop(double tdopvalue, int time)
{
    double midtime=time;
    midtime=midtime/100.0;
    m_TDoplist<<QPointF(midtime,tdopvalue);
    m_TDopCurve->setSamples(m_TDoplist);
    m_DopPlot->replot();
}

void DopFrom::setPDop(double pdopvalue, int time)
{
    double midtime=time;
    midtime=midtime/100.0;
    m_PDoplist<<QPointF(midtime,pdopvalue);
    m_PDopCurve->setSamples(m_PDoplist);
    m_DopPlot->replot();
}

void DopFrom::setGDop(double gdopvalue, int time)
{
    double midtime=time;
    midtime=midtime/100.0;
    m_GDoplist<<QPointF(midtime,gdopvalue);
    m_GDopCurve->setSamples(m_GDoplist);
    m_DopPlot->replot();
}

void DopFrom::setDop(double hdopvalue, double vdopvalue, double tdopvalue, double pdopvalue, double gdopvalue, int time)
{
    double midtime=time;
    midtime=midtime/100.0;
    m_HDoplist<<QPointF(midtime,hdopvalue);
    m_HDopCurve->setSamples(m_HDoplist);
    m_VDoplist<<QPointF(midtime,vdopvalue);
    m_VDopCurve->setSamples(m_VDoplist);
    m_TDoplist<<QPointF(midtime,tdopvalue);
    m_TDopCurve->setSamples(m_TDoplist);
    m_PDoplist<<QPointF(midtime,pdopvalue);
    m_PDopCurve->setSamples(m_PDoplist);
    m_GDoplist<<QPointF(midtime,gdopvalue);
    m_GDopCurve->setSamples(m_GDoplist);
    m_DopPlot->replot();

}

void DopFrom::Clearall()
{
    m_HDoplist.clear();
    m_HDopCurve->setSamples(m_HDoplist);
    m_VDoplist.clear();
    m_VDopCurve->setSamples(m_VDoplist);
    m_TDoplist.clear();
    m_TDopCurve->setSamples(m_TDoplist);
    m_PDoplist.clear();
    m_PDopCurve->setSamples(m_PDoplist);
    m_GDoplist.clear();
    m_GDopCurve->setSamples(m_GDoplist);
    m_DopPlot->replot();
}
void DopFrom:: WinIni()
{
    m_DopPlot=new QwtPlot(this);
    m_DopPlot->setTitle( "DOP" );
    m_DopPlot->setCanvasBackground( Qt::white );
    m_DopPlot->insertLegend( new QwtLegend() );
    m_DopPlot->plotLayout()->setAlignCanvasToScales(true);//让坐标轴相互连接起来
    QwtScaleDraw *scaleDraw = new QwtScaleDraw();//坐标轴的绘画
    scaleDraw->enableComponent( QwtAbstractScaleDraw::Backbone, true );//刻度主干
    scaleDraw->setTickLength( QwtScaleDiv::MinorTick, 0);//刻度线
    scaleDraw->setTickLength( QwtScaleDiv::MediumTick, 0 );
    scaleDraw->setTickLength( QwtScaleDiv::MajorTick, 0 );
    scaleDraw->setPenWidth(1);
    QwtScaleDraw *scaleDraw2 = new QwtScaleDraw();
    scaleDraw2->enableComponent( QwtAbstractScaleDraw::Backbone, true );//刻度主干
    scaleDraw2->setTickLength( QwtScaleDiv::MinorTick, 0);//刻度线
    scaleDraw2->setTickLength( QwtScaleDiv::MediumTick, 0 );
    scaleDraw2->setTickLength( QwtScaleDiv::MajorTick, 0 );
    scaleDraw2->setPenWidth(1);

    m_DopPlot->setAxisScaleDraw(QwtPlot::xBottom,scaleDraw);
    m_DopPlot->setAxisScaleDraw(QwtPlot::yLeft,scaleDraw2);
    m_DopPlot->setAxisAutoScale (QwtPlot::xBottom, true);
    m_DopPlot->setAxisAutoScale (QwtPlot::yLeft, true);
    m_DopPlot->setAxisScale( QwtPlot::yLeft, 0.0, 5.0 ,0.5);
    m_DopPlot->setAxisScale( QwtPlot::xBottom, 0.0, 6048.0 ,1000.0);
    m_DopPlot->setAxisTitle(QwtPlot::yLeft, "DOP");
    m_DopPlot->setAxisTitle(QwtPlot::xBottom,tr("周内秒"));
    m_HDopCurve = new QwtPlotCurve();
    m_HDopCurve->setTitle( "HDOP" );
    m_HDopCurve->setStyle(QwtPlotCurve::Lines);
    m_HDopCurve->setPen( Qt::blue,2);
    m_HDopCurve->attach(m_DopPlot);
    m_VDopCurve = new QwtPlotCurve();
    m_VDopCurve->setTitle( "VDOP" );
    m_VDopCurve->setStyle(QwtPlotCurve::Lines);
    m_VDopCurve->setPen( Qt::green,2);
    m_VDopCurve->attach(m_DopPlot);
    m_TDopCurve = new QwtPlotCurve();
    m_TDopCurve->setTitle( "TDOP" );
    m_TDopCurve->setStyle(QwtPlotCurve::Lines);
    m_TDopCurve->setPen( Qt::cyan,2);
    m_TDopCurve->attach(m_DopPlot);
    m_PDopCurve = new QwtPlotCurve();
    m_PDopCurve->setTitle( "PDOP" );
    m_PDopCurve->setStyle(QwtPlotCurve::Lines);
    m_PDopCurve->setPen( Qt::red,2);
    m_PDopCurve->attach(m_DopPlot);
    m_GDopCurve = new QwtPlotCurve();
    m_GDopCurve->setTitle( "GDOP" );
    m_GDopCurve->setStyle(QwtPlotCurve::Lines);
    m_GDopCurve->setPen( Qt::yellow,2);
    m_GDopCurve->attach(m_DopPlot);
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->attach( m_DopPlot );
    QVBoxLayout *mlayout=new QVBoxLayout(this);
    mlayout->addWidget(m_DopPlot);


}
