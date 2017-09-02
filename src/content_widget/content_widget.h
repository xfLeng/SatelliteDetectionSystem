 #ifndef CONTENTWIDGET_H
#define CONTENTWIDGET_H

#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "datatype.h"
#include "qtpropertybrowser.h"
#include "qtpropertymanager.h"
#include "./DeviationInformation/DeviationInformation.h"
#include "./DOP/DopFrom.h"
#include "./sky/skyplot.h"
#include "./ReceiverLocationForm/ReceiverLocationForm.h"
#include "./FaultDetectionForm/FaultDetectionForm.h"
#include "./FaultDetectionResult/DetectionResultForm.h"
#include "./HPL/HPLForm.h"

class QLabel;
class QSplitter;
class QPushButton;
class QToolButton;
class QProgressBar;

struct TCMDParaHdrRec
{
	unsigned int CMDID;
	unsigned int MsgLEN;
	unsigned int MsgNo;
	unsigned int CMDPara;
};
//用户轨迹参数
struct TUserTrackRec
{
	long long iTrackBDT;//轨迹时间 ms

	unsigned int iTrackID;   //轨迹数据序号
	float    fbeSimTime; //预推时间ms

	double   dUserPosX; //用户位置X
	double   dUserPosY; //用户位置Y
	double   dUserPosZ; //用户位置Z

	double   dUserVelX; //用户速度X
	double   dUserVelY; //用户速度Y
	double   dUserVelZ; //用户速度Z

	double   dUserAccX; //用户加速度X
	double   dUserAccY; //用户加速度Y
	double   dUserAccZ; //用户加速度Z

	double   dUserJekX; //用户加加速度X
	double   dUserJekY; //用户加加速度Y
	double   dUserJekZ; //用户加加速度Z
};
//用户轨迹参数传输--传输命令码0x0A5A5A05
struct TUserTrkTransRec
{
	struct TCMDParaHdrRec  sCmdHdr;
	struct TUserTrackRec   sUserTrk;
};
struct TUDPTrackTransRec
{
	double   dCMDID;
	double   dMsgLEN;
	double   dMsgNo;
	double   dCMDPara;

	double   dTrackBDT;//轨迹时间 ms

	double   dTrackID;   //轨迹数据序号
	double   dbeSimTime; //预推时间ms

	double   dUserPosX; //用户位置X
	double   dUserPosY; //用户位置Y
	double   dUserPosZ; //用户位置Z

	double   dUserVelX; //用户速度X
	double   dUserVelY; //用户速度Y
	double   dUserVelZ; //用户速度Z

	double   dUserAccX; //用户加速度X
	double   dUserAccY; //用户加速度Y
	double   dUserAccZ; //用户加速度Z

	double   dUserJekX; //用户加加速度X
	double   dUserJekY; //用户加加速度Y
	double   dUserJekZ; //用户加加速度Z

};


class ContentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ContentWidget(QWidget *parent = 0);
    void translateLanguage();
	ContentWidget(FaultParametervalue &Value, QWidget *parent = 0);

/**
*私有函数
*/
private:
    void initLeft();
    void initRightTop();
    void initRightCenter();
    void initRightBottom();
    void initRight();
	void DrawSkyForm();   //绘制星空图

/**
*私有槽函数
*/
private slots:
	void OkSlot();
	void CloseSlot();
	void startPause();  //开始-暂停槽函数
	void stop();        //结束按钮
	void openFile();
	void constantFile();

private:
    QSplitter *main_splitter;

    QWidget *left_widget;
	DeviationInformation *m_deviation;
	DopFrom *m_dopfrom;
	Skyplot *m_skyplot;
	ReceiverLocationForm *m_receiverLocation;
	FaultDetectionForm *m_faultDetectionForm;
	DetectionResultForm *m_detetionResultForm;
	HPLForm *m_HPLForm;


    QSplitter *right_splitter;
    QWidget *right_widget;
    QWidget *right_top_widget;
    QLabel *name_label;
    QToolButton *menu_button;
    QProgressBar *progress_bar;
    QToolButton *grade_button;

    QPushButton *open_file; //读取现有文件
	QPushButton *constant_file; //实时文件

    QWidget *right_center_widget;

    QWidget *right_bottom_widget;
	QToolButton *start_pause_btn;  //运行+暂停
	QToolButton *stop_btn;         //结束

	QtProperty *StarTime;
	QtProperty *Length;
	QtProperty *FaultType;
	QtProperty *SatNo;
	QtProperty *m_Value;
	QtProperty *m_FalseAlarmRate;
	QtProperty *m_MissedRate;
	QtProperty *m_NoiseStandardDeviation;

	QtIntPropertyManager *StarTimeManager;
	QtIntPropertyManager *LengthManager;
	QtEnumPropertyManager *FaultTypeManager;
	QtIntPropertyManager *SatNoManager;
	QtDoublePropertyManager *ValueManager;
	QtDoublePropertyManager *FalseAlarmRateManager;
	QtDoublePropertyManager *MissedRateManager;
	QtDoublePropertyManager *NoiseStandardDeviationManager;
	QPushButton *pushbuttonClose;
	QPushButton *pushbuttonOk;
	FaultParametervalue *m_data;

	int glTrkDataID, glSndTimerLen, glOneTimeCnt, glDataIncCnt;
	struct TUDPTrackTransRec lTrkTransAry[5000];//100ms一个点
	QDateTime  glCurrDTime;
	int glSimStepCnt;
	FILE  *fpTrkLog;
	char glTcpDatBuf[32768];
	QString glsLogDatPathDir;
	//TFileStream  *pFileTrjWrPtr[RNSSMDLCNT];
	int  fGnssNewLogSimData(char * pData); //返回<0表示存储失败,=0表示不再转发,=1表示转发
	void fGnssNewLogDatOver();//结束数据存储
	bool glbIfRuning;
};


#endif // CONTENTWIDGET_H
