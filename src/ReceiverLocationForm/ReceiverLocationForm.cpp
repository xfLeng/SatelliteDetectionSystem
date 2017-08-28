#pragma execution_character_set("utf-8")
#include "ReceiverLocationForm.h"
#include "ui_ReceiverLocationForm.h"
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
#include <math.h>

ReceiverLocationForm::ReceiverLocationForm(QWidget *parent): 
	QWidget(parent),
	ui(new Ui::ReceiverLocationForm)
{
	ui->setupUi(this);
	WinIni();
}

ReceiverLocationForm::~ReceiverLocationForm()
{
	delete ui;
}

void ReceiverLocationForm::WinIni()
{
	m_ReceiverLocationPlot = new QwtPlot(this);
	m_ReceiverLocationPlot->setTitle("轨迹图");
	m_ReceiverLocationPlot->setCanvasBackground(Qt::white);
	m_ReceiverLocationPlot->insertLegend(new QwtLegend());
	m_ReceiverLocationPlot->plotLayout()->setAlignCanvasToScales(true);//让坐标轴相互连接起来

	QwtScaleDraw *scaleDraw = new QwtScaleDraw();//坐标轴的绘画
	scaleDraw->enableComponent(QwtAbstractScaleDraw::Backbone, true);//刻度主干
	scaleDraw->setTickLength(QwtScaleDiv::MinorTick, 0);//刻度线
	scaleDraw->setTickLength(QwtScaleDiv::MediumTick, 0);
	scaleDraw->setTickLength(QwtScaleDiv::MajorTick, 0);
	scaleDraw->setPenWidth(1);
	QwtScaleDraw *scaleDraw2 = new QwtScaleDraw();
	scaleDraw2->enableComponent(QwtAbstractScaleDraw::Backbone, true);//刻度主干
	scaleDraw2->setTickLength(QwtScaleDiv::MinorTick, 0);//刻度线s
	scaleDraw2->setTickLength(QwtScaleDiv::MediumTick, 0);
	scaleDraw2->setTickLength(QwtScaleDiv::MajorTick, 0);
	scaleDraw2->setPenWidth(1);

	m_ReceiverLocationPlot->setAxisScaleDraw(QwtPlot::xBottom, scaleDraw);
	m_ReceiverLocationPlot->setAxisScaleDraw(QwtPlot::yLeft, scaleDraw2);
	m_ReceiverLocationPlot->setAxisAutoScale(QwtPlot::xBottom, true);  //设置X轴（底部）自动伸缩
	m_ReceiverLocationPlot->setAxisAutoScale(QwtPlot::yLeft, true);    //设置y轴（左侧）自动伸缩
	m_ReceiverLocationPlot->setAxisScale(QwtPlot::yLeft, 0.0, 1000.0, 200);   //设置y轴的坐标，范围：0-1000，步长：200
	m_ReceiverLocationPlot->setAxisScale(QwtPlot::xBottom, 0.0, 1000.0, 200); //设置x轴的坐标，范围：0-1000，步长：200
	m_ReceiverLocationPlot->setAxisTitle(QwtPlot::yLeft, "差值");           //设置x轴坐标轴标题
	m_ReceiverLocationPlot->setAxisTitle(QwtPlot::xBottom, tr("周内秒"));   //设置y轴坐标轴标题

	m_XCurve = new QwtPlotCurve();  //X轴曲线
	m_XCurve->setTitle("X轴");
	m_XCurve->setStyle(QwtPlotCurve::Lines);
	m_XCurve->setPen(Qt::blue, 2);
	m_XCurve->attach(m_ReceiverLocationPlot);
	m_YCurve = new QwtPlotCurve();  //y轴曲线
	m_YCurve->setTitle("Y轴");
	m_YCurve->setStyle(QwtPlotCurve::Lines);
	m_YCurve->setPen(Qt::green,2);
	m_YCurve->attach(m_ReceiverLocationPlot);
	m_ZCurve = new QwtPlotCurve();  //z轴曲线
	m_ZCurve->setTitle("Z轴");
	m_ZCurve->setStyle(QwtPlotCurve::Lines);
	m_ZCurve->setPen(Qt::red,2);
	m_ZCurve->attach(m_ReceiverLocationPlot);

	QwtPlotGrid *grid = new QwtPlotGrid();
	grid->attach(m_ReceiverLocationPlot);
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(m_ReceiverLocationPlot);
}