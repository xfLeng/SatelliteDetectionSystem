#pragma once

#include <QWidget>
#include "HPLForm.h"
#include <qwt_plot_curve.h>
#include <qwt_plot.h>

namespace Ui {
	class HPLForm;
}

class HPLForm : public QWidget
{
	Q_OBJECT

public:
	HPLForm(QWidget *parent = 0);
	~HPLForm();

private:
	Ui::HPLForm *ui;
	void WinIni();

	QwtPlot *m_HPL;
	QwtPlotCurve *HPL;
};
