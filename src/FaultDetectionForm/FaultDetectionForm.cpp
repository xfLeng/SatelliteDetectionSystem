#pragma execution_character_set("utf-8")
#include "FaultDetectionForm.h"
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


FaultDetectionForm::FaultDetectionForm(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::FaultDetectionForm)
{
	ui->setupUi(this);
	WinIni();
}

FaultDetectionForm::~FaultDetectionForm()
{
	delete ui;
}
void FaultDetectionForm::WinIni() 
{
	m_FaultDetectionPlot = new QwtPlot(this);
	//m_FaultDetectionPlot->setTitle("卫星故障检测");
	m_FaultDetectionPlot->setCanvasBackground(Qt::white);
	m_FaultDetectionPlot->insertLegend(new QwtLegend());
	m_FaultDetectionPlot->plotLayout()->setAlignCanvasToScales(true);//让坐标轴相互连接起来

	QwtScaleDraw *scaleDraw = new QwtScaleDraw();//坐标轴的绘画
	scaleDraw->enableComponent(QwtAbstractScaleDraw::Backbone, true);//刻度主干
	scaleDraw->setTickLength(QwtScaleDiv::MinorTick, 0);//刻度线
	scaleDraw->setTickLength(QwtScaleDiv::MediumTick, 0);
	scaleDraw->setTickLength(QwtScaleDiv::MajorTick, 0);
	scaleDraw->setPenWidth(1);

	m_FaultDetectionPlot->setAxisScaleDraw(QwtPlot::xBottom, scaleDraw);
	m_FaultDetectionPlot->setAxisAutoScale(QwtPlot::xBottom, true);  //设置X轴（底部）自动伸缩
	m_FaultDetectionPlot->setAxisAutoScale(QwtPlot::yLeft, true);    //设置y轴（左侧）自动伸缩
	m_FaultDetectionPlot->setAxisScale(QwtPlot::xBottom, 0.0, 1000.0, 200); //设置x轴的坐标，范围：0-1000，步长：200
	m_FaultDetectionPlot->setAxisTitle(QwtPlot::xBottom, tr("周内秒"));   //设置y轴坐标轴标题

	statisticalDetection = new QwtPlotCurve();  //统计检测量
	statisticalDetection->setTitle("检测量");
	statisticalDetection->setStyle(QwtPlotCurve::Lines);
	statisticalDetection->setPen(Qt::blue, 2);
	statisticalDetection->attach(m_FaultDetectionPlot);
	detectionThreshold = new QwtPlotCurve();  //检测门限
	detectionThreshold->setTitle("门限值");
	detectionThreshold->setStyle(QwtPlotCurve::Lines);
	detectionThreshold->setPen(Qt::red, 2);
	detectionThreshold->attach(m_FaultDetectionPlot);

	QwtPlotGrid *grid = new QwtPlotGrid();
	grid->attach(m_FaultDetectionPlot);
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(m_FaultDetectionPlot);
}
