#if _MSC_VER >=1600
#pragma execution_character_set("utf-8")
#endif
#include "DeviationInformation.h"
#include "ui_DeviationInformation.h"
#include "qteditorfactory.h"
#include "qttreepropertybrowser.h"
#include "qtbuttonpropertybrowser.h"
#include "qtgroupboxpropertybrowser.h"
#include <QDebug>

DeviationInformation::DeviationInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviationInformation)
{
    ui->setupUi(this);
    WinIni();
}

DeviationInformation::~DeviationInformation()
{
    delete ui;
}

void DeviationInformation::SetValue(int wnsec, int gpssec, double x, double y, double z, double hdop, double vdop, double gdop)
{
    WnSecManager->setValue(WnSec,wnsec);
    GPSSecManager->setValue(GPSSec,gpssec);
    xManager->setValue(X,x);
    yManager->setValue(Y,y);
    zManager->setValue(Z,x);
    GDOPManager->setValue(GDOP,gdop);
    VDOPManager->setValue(VDOP,vdop);
    HDOPManager->setValue(HDOP,hdop);

}

void DeviationInformation::WinIni()
{

    WnSecManager = new QtIntPropertyManager(this);
    GPSSecManager=new QtIntPropertyManager(this);
    xManager=new QtDoublePropertyManager(this);
    yManager=new QtDoublePropertyManager(this);
    zManager=new QtDoublePropertyManager(this);
    GDOPManager=new QtDoublePropertyManager(this);
    VDOPManager=new QtDoublePropertyManager(this);
    HDOPManager=new QtDoublePropertyManager(this);
           
	QtGroupPropertyManager *WnManage = new QtGroupPropertyManager(this);
	QtGroupPropertyManager *GpsManage = new QtGroupPropertyManager(this);
	QtGroupPropertyManager *TriaxialPositionerr = new QtGroupPropertyManager(this);
	QtGroupPropertyManager *DOP = new QtGroupPropertyManager(this);

	QtProperty *WnProperty = WnManage->addProperty(tr("周内秒"));
    QtProperty *GpsProperty=GpsManage->addProperty(tr("GPST"));
    QtProperty *itemTruaxual=TriaxialPositionerr->addProperty(tr("三轴定位因子"));
	QtProperty *itemdop = DOP->addProperty(tr("精度因子"));

    WnSec= WnSecManager->addProperty(tr("当前周内秒"));
    WnProperty->addSubProperty(WnSec);

    GPSSec = GPSSecManager->addProperty(tr("GPS时间"));
    GpsProperty->addSubProperty(GPSSec);

    X = xManager->addProperty("X");
    itemTruaxual->addSubProperty(X);
    Y = yManager->addProperty("Y");
    itemTruaxual->addSubProperty(Y);
    Z = zManager->addProperty("Z");
    itemTruaxual->addSubProperty(Z);

    GDOP = GDOPManager->addProperty("GDOP");
    itemdop->addSubProperty(GDOP);
    VDOP = VDOPManager->addProperty("VDOP");
    itemdop->addSubProperty(VDOP);
    HDOP = HDOPManager->addProperty("HDOP");
    itemdop->addSubProperty(HDOP);

    QtDoubleSpinBoxFactory *spinBoxFactory = new QtDoubleSpinBoxFactory(this);
    QtSpinBoxFactory *IntFactory=new QtSpinBoxFactory(this);

    QtAbstractPropertyBrowser *DOPBrowser = new QtGroupBoxPropertyBrowser();
    DOPBrowser->setFactoryForManager(GDOPManager, spinBoxFactory);
    DOPBrowser->setFactoryForManager(VDOPManager, spinBoxFactory);
    DOPBrowser->setFactoryForManager(HDOPManager, spinBoxFactory);
    DOPBrowser->addProperty(itemdop);

    QtAbstractPropertyBrowser *TriaxialPositionerrBrowser=new QtGroupBoxPropertyBrowser();
    TriaxialPositionerrBrowser->setFactoryForManager(xManager,spinBoxFactory);
    TriaxialPositionerrBrowser->setFactoryForManager(yManager,spinBoxFactory);
    TriaxialPositionerrBrowser->setFactoryForManager(zManager,spinBoxFactory);
    TriaxialPositionerrBrowser->addProperty(itemTruaxual);

    QtAbstractPropertyBrowser *WnSecBrowser=new QtGroupBoxPropertyBrowser();
    WnSecBrowser->setFactoryForManager(WnSecManager,IntFactory);
    WnSecBrowser->addProperty(WnProperty);

    QtAbstractPropertyBrowser *GPSSecBrowser=new QtGroupBoxPropertyBrowser();
    GPSSecBrowser->setFactoryForManager(GPSSecManager,IntFactory);
    GPSSecBrowser->addProperty(GpsProperty);

    QGridLayout *midlayout=new QGridLayout(this);
    midlayout->addWidget(WnSecBrowser,0,0);
    midlayout->addWidget(GPSSecBrowser,0,1);
    midlayout->addWidget(TriaxialPositionerrBrowser,1,0);
    midlayout->addWidget(DOPBrowser,1,1);

   // QVBoxLayout *Mainlayout=new QVBoxLayout(this);
   // Mainlayout->addLayout(midlayout);




}
