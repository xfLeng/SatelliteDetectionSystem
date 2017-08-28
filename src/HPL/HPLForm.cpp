#pragma execution_character_set("utf-8")
#include "HPLForm.h"
#include "ui_HPLForm.h"
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


HPLForm::HPLForm(QWidget *parent): 
	QWidget(parent),
	ui(new Ui::HPLForm)
{
	ui->setupUi(this);
	WinIni();
}

HPLForm::~HPLForm()
{
	delete ui;
}

void HPLForm::WinIni()
{
	m_HPL = new QwtPlot(this);
	m_HPL->setCanvasBackground(Qt::white);
	m_HPL->insertLegend(new QwtLegend());
	m_HPL->plotLayout()->setAlignCanvasToScales(true);//让坐标轴相互连接起来

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

	m_HPL->setAxisScaleDraw(QwtPlot::xBottom, scaleDraw);
	m_HPL->setAxisScaleDraw(QwtPlot::yLeft, scaleDraw2);
	m_HPL->setAxisAutoScale(QwtPlot::xBottom, true);  //设置X轴（底部）自动伸缩
	m_HPL->setAxisAutoScale(QwtPlot::yLeft, true);    //设置y轴（左侧）自动伸缩
	m_HPL->setAxisScale(QwtPlot::yLeft, 0.0, 1000.0, 200);   //设置y轴的坐标，范围：0-1000，步长：200
	m_HPL->setAxisScale(QwtPlot::xBottom, 0.0, 1000.0, 200); //设置x轴的坐标，范围：0-1000，步长：200
	m_HPL->setAxisTitle(QwtPlot::yLeft, "HPL值");           //设置x轴坐标轴标题
	m_HPL->setAxisTitle(QwtPlot::xBottom, tr("周内秒"));   //设置y轴坐标轴标题

	HPL = new QwtPlotCurve();  //检测门限
	HPL->setTitle("HPL");
	HPL->setStyle(QwtPlotCurve::Lines);
	HPL->setPen(Qt::red, 2);
	HPL->attach(m_HPL);


	QwtPlotGrid *grid = new QwtPlotGrid();
	grid->attach(m_HPL);
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(m_HPL);
}