#ifndef DEVIATIONINFORMATION
#define DEVIATIONINFORMATION

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "qtpropertybrowser.h"
#include "qtpropertymanager.h"

namespace Ui {
class DeviationInformation;
}

class DeviationInformation : public QWidget
{
    Q_OBJECT

public:
    explicit DeviationInformation(QWidget *parent = 0);
    ~DeviationInformation();
public slots:
    void SetValue(int wnsec,int gpssec,double x,double y,double z,double hdop,double vdop,double gdop);
private:
    Ui::DeviationInformation *ui;
    void WinIni();
    QtProperty *WnSec;
    QtProperty *GPSSec;
    QtProperty *X;
    QtProperty *Y;
    QtProperty *Z;
    QtProperty *HDOP;
    QtProperty *VDOP;
    QtProperty *GDOP;

    QtIntPropertyManager *WnSecManager;
    QtIntPropertyManager *GPSSecManager;
    QtDoublePropertyManager *xManager;
    QtDoublePropertyManager *yManager;
    QtDoublePropertyManager *zManager;
    QtDoublePropertyManager *GDOPManager;
    QtDoublePropertyManager *VDOPManager;
    QtDoublePropertyManager *HDOPManager;





};

#endif // DEVIATIONINFORMATION
