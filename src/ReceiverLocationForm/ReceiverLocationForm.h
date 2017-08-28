#pragma once

#include <QWidget>
#include "ReceiverLocationForm.h"
#include <qwt_plot_curve.h>
#include <qwt_plot.h>


namespace Ui {
	class ReceiverLocationForm;
}

class ReceiverLocationForm : public QWidget
{
	Q_OBJECT

public:
	explicit ReceiverLocationForm(QWidget *parent = 0);
	~ReceiverLocationForm();

private:
	Ui::ReceiverLocationForm *ui;
	void WinIni();

	QwtPlot *m_ReceiverLocationPlot;
	QwtPlotCurve *m_XCurve;  //X÷·«˙œﬂ
	QwtPlotCurve *m_YCurve;  //y÷·«˙œﬂ
	QwtPlotCurve *m_ZCurve;  //z÷·«˙œﬂ

};
