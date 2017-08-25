#if _MSC_VER >=1600
#pragma execution_character_set("utf-8")
#endif
#include "FaultParameter.h"
#include "ui_FaultParameter.h"
#include "qteditorfactory.h"
#include "qttreepropertybrowser.h"
#include "qtbuttonpropertybrowser.h"
#include "qtgroupboxpropertybrowser.h"

FaultParameter::FaultParameter(QWidget *parent) :
QDialog(parent),
    ui(new Ui::FaultParameter)
{
    ui->setupUi(this);
    WinInI();
}

FaultParameter::FaultParameter(FaultParametervalue &Value, QWidget *parent):
QDialog(parent),
    ui(new Ui::FaultParameter)
{
    ui->setupUi(this);
    WinInI();
    m_data=&Value;
    StarTimeManager->setValue(StarTime,m_data->startime);
    LengthManager->setValue(Length,m_data->lenth);
    FaultTypeManager->setValue(FaultType,m_data->type-1);
    SatNoManager->setValue(SatNo,m_data->SatNO);
    ValueManager->setValue(m_Value,m_data->value);


}

FaultParameter::~FaultParameter()
{
    delete ui;
}

void FaultParameter::OkSlot()
{
    m_data->startime=StarTimeManager->value(StarTime);
    m_data->lenth= LengthManager->value(Length);
    m_data->type=FaultTypeManager->value(FaultType)+1;
    m_data->SatNO=SatNoManager->value(SatNo);
    m_data->value=ValueManager->value(m_Value);
	this->accept();
}

void FaultParameter::CloseSlot()
{
    this->close();
}

void FaultParameter::WinInI()
{
    this->setWindowTitle(tr("故障参数设置"));
    StarTimeManager=new QtIntPropertyManager(this);
    LengthManager=new QtIntPropertyManager(this);
    FaultTypeManager=new QtEnumPropertyManager(this);
    SatNoManager=new QtIntPropertyManager(this);
    ValueManager=new QtDoublePropertyManager(this);
    FalseAlarmRateManager=new QtDoublePropertyManager(this);
    MissedRateManager=new QtDoublePropertyManager(this);
    NoiseStandardDeviationManager=new QtDoublePropertyManager(this);
    QtGroupPropertyManager *Fault = new QtGroupPropertyManager(this);
    QtProperty *itemFault=Fault->addProperty(tr("故障参数设置"));
    StarTime=StarTimeManager->addProperty(tr("开始时间"));
    itemFault->addSubProperty(StarTime);
    Length=LengthManager->addProperty(tr("故障时长"));
    itemFault->addSubProperty(Length);
    FaultType=FaultTypeManager->addProperty(tr("故障类型"));
    QStringList enumNames;
    enumNames << tr("阶跃故障") << tr("斜坡故障");
    FaultTypeManager->setEnumNames(FaultType, enumNames);
    itemFault->addSubProperty(FaultType);
    m_Value=ValueManager->addProperty(tr("故障幅值"));
    itemFault->addSubProperty(m_Value);
    m_FalseAlarmRate=FalseAlarmRateManager->addProperty(tr("误警率"));
    FalseAlarmRateManager->setMaximum(m_FalseAlarmRate,10);
    FalseAlarmRateManager->setMinimum(m_FalseAlarmRate,1);
    itemFault->addSubProperty(m_FalseAlarmRate);
    m_MissedRate=MissedRateManager->addProperty(tr("漏检率"));
    MissedRateManager->setMinimum(m_MissedRate,1);
    MissedRateManager->setMaximum(m_MissedRate,10);
    itemFault->addSubProperty(m_MissedRate);
    m_NoiseStandardDeviation=NoiseStandardDeviationManager->addProperty(tr("噪声标准差"));
    NoiseStandardDeviationManager->setMaximum(m_NoiseStandardDeviation,33.3);
    NoiseStandardDeviationManager->setMinimum(m_NoiseStandardDeviation,0);
    itemFault->addSubProperty(m_NoiseStandardDeviation);
    SatNo=SatNoManager->addProperty(tr("故障卫星号"));
    SatNoManager->setMaximum(SatNo,12);
    SatNoManager->setMinimum(SatNo,1);
    itemFault->addSubProperty(SatNo);
    QtDoubleSpinBoxFactory *spinBoxFactory = new QtDoubleSpinBoxFactory(this);
    QtSpinBoxFactory *IntFactory=new QtSpinBoxFactory(this);
    QtEnumEditorFactory *comboBoxFactory = new QtEnumEditorFactory(this);
    QtAbstractPropertyBrowser *FaultBrowser = new QtGroupBoxPropertyBrowser();
    FaultBrowser->setFactoryForManager(ValueManager,spinBoxFactory);
    FaultBrowser->setFactoryForManager(FalseAlarmRateManager,spinBoxFactory);
    FaultBrowser->setFactoryForManager(MissedRateManager,spinBoxFactory);
    FaultBrowser->setFactoryForManager(NoiseStandardDeviationManager,spinBoxFactory);
    FaultBrowser->setFactoryForManager(SatNoManager,IntFactory);
    FaultBrowser->setFactoryForManager(StarTimeManager,IntFactory);

    FaultBrowser->setFactoryForManager(LengthManager,IntFactory);
    FaultBrowser->setFactoryForManager(FaultTypeManager,comboBoxFactory);
    FaultBrowser->addProperty(itemFault);
    pushbuttonClose=new QPushButton(this);
    pushbuttonClose->setText(tr("取消"));
    pushbuttonOk=new QPushButton(this);
    pushbuttonOk->setText(tr("确定"));
    connect(pushbuttonClose,SIGNAL(clicked()),this,SLOT(CloseSlot()));
    connect(pushbuttonOk,SIGNAL(clicked()),this,SLOT(OkSlot()));
    QHBoxLayout * bottonlayout=new QHBoxLayout;
    bottonlayout->addStretch(1);
    bottonlayout->addWidget(pushbuttonOk);
    bottonlayout->addWidget(pushbuttonClose);
    QVBoxLayout *mainlayout=new QVBoxLayout(this);
    mainlayout->addWidget(FaultBrowser);
    mainlayout->addLayout(bottonlayout);
}
