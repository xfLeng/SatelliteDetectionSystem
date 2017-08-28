#pragma once

#include <QWidget>
#include "DetectionResultForm.h"
#include <qwt_plot_curve.h>
#include <qwt_plot.h>

namespace Ui {
	class DetectionResultForm;
}

class DetectionResultForm : public QWidget
{
	Q_OBJECT

public:
	explicit DetectionResultForm(QWidget *parent = 0);
	~DetectionResultForm();

private:
	Ui::DetectionResultForm *ui;
	void WinIni();

	QwtPlot *m_DetectionResult;
	QwtPlotCurve *faultSatellite;
	QwtPlotCurve *detectionValue;
};
