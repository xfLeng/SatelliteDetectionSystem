#pragma execution_character_set("utf-8")
#include "DetectionResultForm.h"
#include "ui_DetectionResultForm.h"
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

DetectionResultForm::DetectionResultForm(QWidget *parent): 
	QWidget(parent),
	ui(new Ui::DetectionResultForm)
{
	ui->setupUi(this);
	WinIni();
}

DetectionResultForm::~DetectionResultForm()
{
	delete ui;
}
void DetectionResultForm::WinIni()
{
	m_DetectionResult = new QwtPlot(this);
	m_DetectionResult->setCanvasBackground(Qt::white);
	m_DetectionResult->insertLegend(new QwtLegend());
	m_DetectionResult->plotLayout()->setAlignCanvasToScales(true);//让坐标轴相互连接起来

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

	m_DetectionResult->setAxisScaleDraw(QwtPlot::xBottom, scaleDraw);
	m_DetectionResult->setAxisScaleDraw(QwtPlot::yLeft, scaleDraw2);
	m_DetectionResult->setAxisAutoScale(QwtPlot::xBottom, true);  //设置X轴（底部）自动伸缩
	m_DetectionResult->setAxisAutoScale(QwtPlot::yLeft, true);    //设置y轴（左侧）自动伸缩
	m_DetectionResult->setAxisScale(QwtPlot::yLeft, 0.0, 1000.0, 200);   //设置y轴的坐标，范围：0-1000，步长：200
	m_DetectionResult->setAxisScale(QwtPlot::xBottom, 0.0, 1000.0, 200); //设置x轴的坐标，范围：0-1000，步长：200
	m_DetectionResult->setAxisTitle(QwtPlot::yLeft, "卫星号");           //设置x轴坐标轴标题
	m_DetectionResult->setAxisTitle(QwtPlot::xBottom, tr("周内秒"));   //设置y轴坐标轴标题

	detectionValue = new QwtPlotCurve();  //检测门限
	detectionValue->setTitle("故障星");
	detectionValue->setStyle(QwtPlotCurve::Lines);
	detectionValue->setPen(Qt::red, 2);
	detectionValue->attach(m_DetectionResult);
	faultSatellite = new QwtPlotCurve();  //统计检测量
	faultSatellite->setTitle("检测值");
	faultSatellite->setStyle(QwtPlotCurve::Lines);
	faultSatellite->setPen(Qt::blue, 2);
	faultSatellite->attach(m_DetectionResult);
	

	QwtPlotGrid *grid = new QwtPlotGrid();
	grid->attach(m_DetectionResult);
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(m_DetectionResult);
}