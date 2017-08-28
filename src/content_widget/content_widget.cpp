#if _MSC_VER >=1600
#pragma execution_character_set("utf-8")
#endif
#include <QLabel>
#include <QEvent>
#include <QPainter>
#include <QSplitter>
#include <QHBoxLayout>
#include <QPushButton>
#include <QToolButton>
#include "content_widget.h"
#include "qteditorfactory.h"
#include "qttreepropertybrowser.h"
#include "qtbuttonpropertybrowser.h"
#include "qtgroupboxpropertybrowser.h"
#include <QMdiSubWindow>


ContentWidget::ContentWidget(QWidget *parent)
    : QWidget(parent)
{
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(Qt::white));
    setPalette(palette);
    setAutoFillBackground(true);

    main_splitter = new QSplitter();
    main_splitter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    main_splitter->setOrientation(Qt::Horizontal);
    main_splitter->setHandleWidth(1);
    main_splitter->setStyleSheet("QSplitter::handle{background:lightgray;}");

    this->initLeft();
    this->initRight();
    this->initRightTop();
    this->initRightCenter();
    this->initRightBottom();

    right_splitter->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    right_splitter->setOrientation(Qt::Vertical);
    right_splitter->setHandleWidth(1);
    right_splitter->setStyleSheet("QSplitter::handle{background:lightgray;}");

    right_top_widget->setFixedSize(220, 46);
    right_bottom_widget->setFixedSize(220, 46);
    right_splitter->addWidget(right_top_widget);
    right_splitter->addWidget(right_center_widget);
    right_splitter->addWidget(right_bottom_widget);
	
	main_splitter->addWidget(right_splitter);
    main_splitter->addWidget(left_widget);
    

    //禁止拖动
    for(int i = 0; i<right_splitter->count();i++)
    {
        QSplitterHandle *handle = right_splitter->handle(i);
        handle->setEnabled(false);
    }

    for(int i = 0; i<main_splitter->count();i++)
    {
        QSplitterHandle *handle = main_splitter->handle(i);
        handle->setEnabled(false);
    }

    QHBoxLayout *main_layout = new QHBoxLayout();
    main_layout->addWidget(main_splitter);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(0, 0, 0, 0);

    setLayout(main_layout);

    this->translateLanguage();
}

void ContentWidget::initLeft()
{
    left_widget = new QWidget();
	int w_width = 850;
	int w_height = 500;
    left_widget->resize(w_width, w_height);
	m_deviation = new DeviationInformation(this);
	m_dopfrom = new DopFrom(this);
	m_skyplot = new Skyplot(this);
	m_receiverLocation = new ReceiverLocationForm(this);
	m_faultDetectionForm = new FaultDetectionForm(this);
	m_detetionResultForm = new DetectionResultForm(this);

	QMdiSubWindow *deviation = new QMdiSubWindow(this);
	deviation->setWidget(m_deviation);
	QMdiSubWindow *dopform = new QMdiSubWindow(this);
	dopform->setWidget(m_dopfrom);
	QMdiSubWindow *skyplot = new QMdiSubWindow(this);
	skyplot->setWidget(m_skyplot);
	QMdiSubWindow *receiverLocation = new QMdiSubWindow(this);
	receiverLocation->setWidget(m_receiverLocation);
	QMdiSubWindow *faultDetection = new QMdiSubWindow(this);
	faultDetection->setWidget(m_faultDetectionForm);
	QMdiSubWindow *detetionResultForm = new QMdiSubWindow(this);
	detetionResultForm->setWidget(m_detetionResultForm);
	
	QGridLayout *main_layout = new QGridLayout();

	main_layout->addWidget(skyplot,0,0,1,1);
	main_layout->addWidget(dopform,0,1, 1, 1);
	main_layout->addWidget(receiverLocation,0,2,1,1);
	main_layout->addWidget(faultDetection,1,0, 1, 1);
	main_layout->addWidget(detetionResultForm, 1, 1, 1, 1);
	main_layout->addWidget(deviation, 1, 2, 1, 1);

	////行比 1：1
	//main_layout->setRowStretch(0, 1);
	//main_layout->setRowStretch(1, 1);
	////列比 1:1:1
	//main_layout->setColumnStretch(0, 1);
	//main_layout->setColumnStretch(1, 1);
	//main_layout->setColumnStretch(2, 2);
	
	left_widget->setLayout(main_layout);

}

void ContentWidget::initRight()
{
    right_splitter = new QSplitter();
    //right_splitter->resize(250, 500);
}

void ContentWidget::initRightTop()
{
    right_top_widget = new QWidget();
    open_file = new QPushButton();
	constant_file = new QPushButton();
	//----------------打开文件------------------------
	open_file->setFixedSize(100, 40);
	open_file->setStyleSheet("QPushButton{color:green; border-image:url(:/contentWidget/btn_bag);}"
                                "QPushButton:hover{color:rgb(110, 190, 10);}");
    QFont font = open_file->font();
	font.setBold(true);
	font.setPointSize(10);
	open_file->setFont(font);
	//----------------实时连接------------------------
	constant_file->setFixedSize(100, 40);
	constant_file->setStyleSheet("QPushButton{color:green; border-image:url(:/contentWidget/btn_bag);}"
		"QPushButton:hover{color:rgb(110, 190, 10);}");
	constant_file->setFont(font);

    QHBoxLayout *rightTop_layout = new QHBoxLayout();
	rightTop_layout->addWidget(open_file);
	rightTop_layout->addWidget(constant_file);
	rightTop_layout->addStretch();
	rightTop_layout->setContentsMargins(8, 0, 8, 0);
	  
    right_top_widget->setLayout(rightTop_layout);
}

void ContentWidget::initRightCenter()
{
    right_center_widget = new QWidget();

	StarTimeManager = new QtIntPropertyManager(this);
	LengthManager = new QtIntPropertyManager(this);
	FaultTypeManager = new QtEnumPropertyManager(this);
	SatNoManager = new QtIntPropertyManager(this);
	ValueManager = new QtDoublePropertyManager(this);
	FalseAlarmRateManager = new QtDoublePropertyManager(this);
	MissedRateManager = new QtDoublePropertyManager(this);
	NoiseStandardDeviationManager = new QtDoublePropertyManager(this);
	QtGroupPropertyManager *Fault = new QtGroupPropertyManager(this);

	QtProperty *itemFault = Fault->addProperty(tr("故障参数设置"));
	StarTime = StarTimeManager->addProperty(tr("开始时间"));
	itemFault->addSubProperty(StarTime);
	Length = LengthManager->addProperty(tr("故障时长"));
	itemFault->addSubProperty(Length);
	FaultType = FaultTypeManager->addProperty(tr("故障类型"));
	QStringList enumNames;
	enumNames << tr("阶跃故障") << tr("斜坡故障");
	FaultTypeManager->setEnumNames(FaultType, enumNames);
	itemFault->addSubProperty(FaultType);
	m_Value = ValueManager->addProperty(tr("故障幅值"));
	itemFault->addSubProperty(m_Value);
	m_FalseAlarmRate = FalseAlarmRateManager->addProperty(tr("误警率"));
	FalseAlarmRateManager->setMaximum(m_FalseAlarmRate, 10);
	FalseAlarmRateManager->setMinimum(m_FalseAlarmRate, 1);
	itemFault->addSubProperty(m_FalseAlarmRate);
	m_MissedRate = MissedRateManager->addProperty(tr("漏检率"));
	MissedRateManager->setMinimum(m_MissedRate, 1);
	MissedRateManager->setMaximum(m_MissedRate, 10);
	itemFault->addSubProperty(m_MissedRate);
	m_NoiseStandardDeviation = NoiseStandardDeviationManager->addProperty(tr("噪声标准差"));
	NoiseStandardDeviationManager->setMaximum(m_NoiseStandardDeviation, 33.3);
	NoiseStandardDeviationManager->setMinimum(m_NoiseStandardDeviation, 0);
	itemFault->addSubProperty(m_NoiseStandardDeviation);
	SatNo = SatNoManager->addProperty(tr("故障卫星号"));
	SatNoManager->setMaximum(SatNo, 12);
	SatNoManager->setMinimum(SatNo, 1);
	itemFault->addSubProperty(SatNo);

	QtDoubleSpinBoxFactory *spinBoxFactory = new QtDoubleSpinBoxFactory(this);
	QtSpinBoxFactory *IntFactory = new QtSpinBoxFactory(this);
	QtEnumEditorFactory *comboBoxFactory = new QtEnumEditorFactory(this);
	QtAbstractPropertyBrowser *FaultBrowser = new QtGroupBoxPropertyBrowser();
	FaultBrowser->setFactoryForManager(ValueManager, spinBoxFactory);
	FaultBrowser->setFactoryForManager(FalseAlarmRateManager, spinBoxFactory);
	FaultBrowser->setFactoryForManager(MissedRateManager, spinBoxFactory);
	FaultBrowser->setFactoryForManager(NoiseStandardDeviationManager, spinBoxFactory);
	FaultBrowser->setFactoryForManager(SatNoManager, IntFactory);
	FaultBrowser->setFactoryForManager(StarTimeManager, IntFactory);
	FaultBrowser->setFactoryForManager(LengthManager, IntFactory);
	FaultBrowser->setFactoryForManager(FaultTypeManager, comboBoxFactory);
	FaultBrowser->addProperty(itemFault);

	pushbuttonClose = new QPushButton(this);
	pushbuttonClose->setText(tr("取消"));
	pushbuttonOk = new QPushButton(this);
	pushbuttonOk->setText(tr("确定"));
	pushbuttonOk->isLeftToRight();
	connect(pushbuttonClose, SIGNAL(clicked()), this, SLOT(CloseSlot()));
	connect(pushbuttonOk, SIGNAL(clicked()), this, SLOT(OkSlot()));
	QHBoxLayout * bottonlayout = new QHBoxLayout;
	bottonlayout->addStretch(1);
	bottonlayout->addWidget(pushbuttonOk);
	bottonlayout->addSpacing(5);
	bottonlayout->addWidget(pushbuttonClose);

	QVBoxLayout *mainlayout = new QVBoxLayout(this);
	mainlayout->setSpacing(0);
	mainlayout->setContentsMargins(0, 0, 0, 0);

	mainlayout->addWidget(FaultBrowser);
	mainlayout->addLayout(bottonlayout);
	mainlayout->addStretch(1);

    right_center_widget->setLayout(mainlayout);

	FaultParametervalue value;
	m_data = &value;
	StarTimeManager->setValue(StarTime, m_data->startime);
	LengthManager->setValue(Length, m_data->lenth);
	FaultTypeManager->setValue(FaultType, m_data->type - 1);
	SatNoManager->setValue(SatNo, m_data->SatNO);
	ValueManager->setValue(m_Value, m_data->value);
}

void ContentWidget::initRightBottom()
{
    right_bottom_widget = new QWidget();
	start_button = new QPushButton();
	pause_button = new QPushButton();

	QFont font = open_file->font();
	font.setBold(true);
	font.setPointSize(10);

	start_button->setFixedSize(100, 40);
	start_button->setStyleSheet("QPushButton{color:green; border-image:url(:/contentWidget/login);}"
		"QPushButton:hover{color:rgb(110, 190, 10);}");
	start_button->setFont(font);

	pause_button->setFixedSize(100, 40);
	pause_button->setStyleSheet("QPushButton{color:green; border-image:url(:/contentWidget/login);}"
		"QPushButton:hover{color:rgb(110, 190, 10);}");
	pause_button->setFont(font);

	QHBoxLayout *bottom_layout = new QHBoxLayout();
	bottom_layout->addWidget(start_button);
	bottom_layout->addWidget(pause_button);
	bottom_layout->addStretch();
	bottom_layout->setContentsMargins(8, 0,8, 0);

    right_bottom_widget->setLayout(bottom_layout);
}

void ContentWidget::translateLanguage()
{
	open_file->setText(tr("文件导入"));
	constant_file->setText(tr("UDP连接"));
	
	start_button->setText(tr("开始"));
	pause_button->setText(tr("暂停"));
}

void ContentWidget::OkSlot()
{
	m_data->startime = StarTimeManager->value(StarTime);
	m_data->lenth = LengthManager->value(Length);
	m_data->type = FaultTypeManager->value(FaultType) + 1;
	m_data->SatNO = SatNoManager->value(SatNo);
	m_data->value = ValueManager->value(m_Value);
}

void ContentWidget::CloseSlot() {
	StarTimeManager->setValue(StarTime, 0);
	LengthManager->setValue(Length, 0);
	FaultTypeManager->setValue(FaultType, 0);
	SatNoManager->setValue(SatNo, 0.0);
	ValueManager->setValue(m_Value, 1);
}

