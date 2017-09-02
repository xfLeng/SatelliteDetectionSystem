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
#include <QFileDialog>
#include <QMessageBox>


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
	//m_deviation = new DeviationInformation(this);
	m_dopfrom = new DopFrom(this);
	m_skyplot = new Skyplot(this);
	m_receiverLocation = new ReceiverLocationForm(this);
	m_faultDetectionForm = new FaultDetectionForm(this);
	m_detetionResultForm = new DetectionResultForm(this);
	m_HPLForm = new HPLForm(this);


	//QMdiSubWindow *deviation = new QMdiSubWindow(this);
	//deviation->setWidget(m_deviation);
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
	QMdiSubWindow *HPLForm = new QMdiSubWindow(this);
	HPLForm->setWidget(m_HPLForm);
	
	QGridLayout *main_layout = new QGridLayout();

	main_layout->addWidget(skyplot,0,0,1,1);
	main_layout->addWidget(dopform,0,1, 1, 1);
	main_layout->addWidget(receiverLocation,0,2,1,1);
	main_layout->addWidget(faultDetection,1,0, 1, 1);
	main_layout->addWidget(detetionResultForm, 1, 1, 1, 1);
	main_layout->addWidget(HPLForm, 1, 2, 1, 1);

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

	connect(open_file,SIGNAL(clicked()),this,SLOT(openFile()));

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
	right_bottom_widget->setFixedSize(220, 80);
	QFont font = open_file->font();
	font.setBold(true);
	font.setPointSize(10);
	
	start_pause_btn = new QToolButton(this);
	stop_btn = new QToolButton(this);
	start_pause_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	QPixmap start_mixmap(":/toolWidget/Start");
	start_pause_btn->setIcon(start_mixmap);
	start_pause_btn->setIconSize(start_mixmap.size());
	//start_pause_btn->setFixedSize(start_mixmap.width()+50, start_mixmap.height()+35);
	start_pause_btn->setStyleSheet("QToolButton{background:transparent;}"
		"QToolButton:hover{border-radius:5px; border:1px solid rgb(210, 225, 230);}");
	stop_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	QPixmap stop_pixmap(":/toolWidget/Stop");
	stop_btn->setIcon(stop_pixmap);
	stop_btn->setIconSize(stop_pixmap.size());
	//stop_btn->setFixedSize(stop_pixmap.width()+50,stop_pixmap.height()+35);
	stop_btn->setStyleSheet("QToolButton{background:transparent;}"
		"QToolButton:hover{border-radius:5px; border:1px solid rgb(210, 225, 230);}");
	connect(start_pause_btn, SIGNAL(clicked()), this, SLOT(startPause()));
	connect(stop_btn, SIGNAL(clicked()), this, SLOT(stop()));

	/*QHBoxLayout *bottom_layout = new QHBoxLayout();
	bottom_layout->addWidget(start_pause_btn);
	bottom_layout->addWidget(stop_btn);
	bottom_layout->addStretch();
	bottom_layout->setContentsMargins(8, 0,8, 0);*/
	QGridLayout *bottom_layout = new QGridLayout();
	bottom_layout->addWidget(start_pause_btn,0,0);
	bottom_layout->addWidget(stop_btn, 0, 1);
	bottom_layout->setSpacing(0);
	bottom_layout->setContentsMargins(10, 0, 10, 3);

    right_bottom_widget->setLayout(bottom_layout);
}

void ContentWidget::translateLanguage()
{
	open_file->setText(tr("文件导入"));
	constant_file->setText(tr("UDP连接"));
	start_pause_btn->setText("开始");
	stop_btn->setText("暂停");
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

void ContentWidget::startPause() {
	QString toolTipName = start_pause_btn->toolTip();
	if (toolTipName == "开始") {
		start_pause_btn->setToolTip(tr("暂停"));
		QPixmap start_pause_pixmap(":/toolWidget/Pause");
		start_pause_btn->setIcon(start_pause_pixmap);
		start_pause_btn->setIconSize(start_pause_pixmap.size());
		start_pause_btn->setFixedSize(start_pause_pixmap.width() + 25, start_pause_pixmap.height() + 25);
	}
	else {
		start_pause_btn->setToolTip(tr("开始"));
		QPixmap start_pause_pixmap(":/toolWidget/Start");
		start_pause_btn->setIcon(start_pause_pixmap);
		start_pause_btn->setIconSize(start_pause_pixmap.size());
		start_pause_btn->setFixedSize(start_pause_pixmap.width() + 25, start_pause_pixmap.height() + 25);
	}
}

void ContentWidget::stop() {
	QString toolTipName = start_pause_btn->toolTip();
	if (toolTipName == "暂停") {
		start_pause_btn->setToolTip(tr("开始"));
		QPixmap start_pause_pixmap(":/toolWidget/Start");
		start_pause_btn->setIcon(start_pause_pixmap);
		start_pause_btn->setIconSize(start_pause_pixmap.size());
		start_pause_btn->setFixedSize(start_pause_pixmap.width() + 25, start_pause_pixmap.height() + 25);
	}
}

void ContentWidget::openFile() {
	QFileDialog *fileDialog = new QFileDialog(this); 
    fileDialog->setWindowTitle(tr("打开文件")); 
	fileDialog->setGeometry(10, 30, 300, 200);//设置文件对话框的显示位置
    fileDialog->setDirectory("."); //设置文件对话框打开时初始打开的位置
	QStringList filters;
	filters << "*.txt";
    fileDialog->setNameFilters(filters); //设置文件类型过滤器
    if(fileDialog->exec() == QDialog::Accepted) { 
		QString path = fileDialog->selectedFiles()[0]; //获取文件路径
        //QMessageBox::information(NULL, tr("Path"), tr("You selected ") + path);

		int i, j, k, iCnt, iLen, bid, iRtn;
		QString  tStr, tStrA[50], sTrkFile;
		int  iDatColA[12];
		int  iAllCnt, iRdDatCnt, iDatDisTime = 100;
		struct TUserTrackRec lUserTrajA[2];
		double  l_last_acc[3], l_last_jek[3];
		__int64  iDataBDT;
		QFile file(path);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			return;
		}

		QStringList *TempList = new QStringList();
		while (!file.atEnd()) {
			QByteArray line = file.readLine();
			QString str(line);
			str = str.replace(QString("\n"), QString(""));
			TempList->append(str);
			qDebug() << str;
		}
		iDatColA[0] = 3;
		iDatColA[1] = 4;
		iDatColA[2] = 5;
		iDatColA[3] = 6;
		iDatColA[4] = 7;
		iDatColA[5] = 8;
		iDatColA[6] = 9;
		iDatColA[7] = 10;
		iDatColA[8] = 11;
		iDatColA[9] = 12;
		iDatColA[10] = 13;
		iDatColA[11] = 14;
		for (i = 0;i<12;i++)
		{
			if (iDatColA[i]<0 || iDatColA[i]>40)
				iDatColA[i] = 49;
		}
		iCnt = TempList->count() - 1;//9389
		iDataBDT = 0;
		iRdDatCnt = 0;
		iAllCnt = 5000;
		if (iCnt<iAllCnt)
			iAllCnt = iCnt;
		for (i = 0;i<iAllCnt;i++)
		{
			tStr = TempList->value(iRdDatCnt) + ' ';
			for (j = 0;j<50;j++)
				tStrA[j] = "";
			iLen = tStr.length();       //245
			bid = 0;
			for (j = 0;j<iLen;j++)
			{
				if (tStr[j + 1] != ' ' && tStr[j + 1] != '\t')
				{
					tStrA[bid] = tStrA[bid] + tStr[j + 1];
				}else
				{
					if (tStrA[bid] != "")
						bid++;
				}
			}

			tStrA[49] = "0"; //用于未用参数转换

			lTrkTransAry[iRdDatCnt].dCMDID = 0x0A5A5A05;
			lTrkTransAry[iRdDatCnt].dMsgLEN = sizeof(struct TUDPTrackTransRec);
			lTrkTransAry[iRdDatCnt].dMsgNo = 1;

			lTrkTransAry[iRdDatCnt].dTrackBDT = tStrA[0].toFloat();//iDataBDT;
			lTrkTransAry[iRdDatCnt].dTrackID = iRdDatCnt;
			lTrkTransAry[iRdDatCnt].dbeSimTime = 0;
			lTrkTransAry[iRdDatCnt].dUserPosX = tStrA[iDatColA[0]].toFloat(); //用户位置X
			lTrkTransAry[iRdDatCnt].dUserPosY = tStrA[iDatColA[1]].toFloat(); //用户位置Y
			lTrkTransAry[iRdDatCnt].dUserPosZ = tStrA[iDatColA[2]].toFloat(); //用户位置Z

			lTrkTransAry[iRdDatCnt].dUserVelX = tStrA[iDatColA[3]].toFloat(); //用户速度X
			lTrkTransAry[iRdDatCnt].dUserVelY = tStrA[iDatColA[4]].toFloat(); //用户速度Y
			lTrkTransAry[iRdDatCnt].dUserVelZ = tStrA[iDatColA[5]].toFloat(); //用户速度Z

			lTrkTransAry[iRdDatCnt].dUserAccX = 0; //用户加速度X
			lTrkTransAry[iRdDatCnt].dUserAccY = 0; //用户加速度Y
			lTrkTransAry[iRdDatCnt].dUserAccZ = 0; //用户加速度Z

			lTrkTransAry[iRdDatCnt].dUserJekX = 0; //用户加加速度X
			lTrkTransAry[iRdDatCnt].dUserJekY = 0;//用户加加速度Y
			lTrkTransAry[iRdDatCnt].dUserJekZ = 0;//用户加加速度Z
			iRdDatCnt++;
			iDataBDT = iDataBDT + iDatDisTime;
		}
		QMessageBox::information(NULL, tr("提示"), tr("数据装载完成！"));
		delete TempList;
		glTrkDataID = 0;
		open_file->setEnabled(false);
     }
}

void ContentWidget::constantFile() {
	
}

