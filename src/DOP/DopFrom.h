#ifndef DOPFROM_H
#define DOPFROM_H

#include <QWidget>
#include <qwt_plot_curve.h>
#include <qwt_plot.h>


namespace Ui {
class DopFrom;
}

class DopFrom : public QWidget
{
    Q_OBJECT

public:
    explicit DopFrom(QWidget *parent = 0);
    ~DopFrom();
public slots:
    void setHDop(double hdopvalue,int time);
    void setVDop(double vdopvalue,int time);
    void setTDop(double tdopvalue,int time);
    void setPDop(double pdopvalue,int time);
    void setGDop(double gdopvalue,int time);
    void setDop(double hdopvalue,double vdopvalue,double tdopvalue,double pdopvalue,double gdopvalue,int time);
    void Clearall();

private:
    Ui::DopFrom *ui;
     QwtPlot *m_DopPlot;
     QwtPlotCurve *m_HDopCurve;
     QwtPlotCurve *m_VDopCurve;
     QwtPlotCurve *m_TDopCurve;
     QwtPlotCurve *m_PDopCurve;
     QwtPlotCurve *m_GDopCurve;

     QPolygonF m_HDoplist;
     QPolygonF m_VDoplist;
     QPolygonF m_TDoplist;
     QPolygonF m_PDoplist;
     QPolygonF m_GDoplist;
    void WinIni();
};

#endif // DOPFROM_H
