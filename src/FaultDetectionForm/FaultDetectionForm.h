#pragma once

#include <QWidget>
#include "ui_FaultDetectionForm.h"
#include <qwt_plot_curve.h>
#include <qwt_plot.h>


namespace Ui {
	class FaultDetectionForm;
}

class FaultDetectionForm : public QWidget
{
	Q_OBJECT

public:
	FaultDetectionForm(QWidget *parent = Q_NULLPTR);
	~FaultDetectionForm();


private:
	Ui::FaultDetectionForm *ui;
	void WinIni();

	QwtPlot *m_FaultDetectionPlot;
	QwtPlotCurve *statisticalDetection;
	QwtPlotCurve *detectionThreshold;
};
