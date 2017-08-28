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

class QLabel;
class QSplitter;
class QPushButton;
class QToolButton;
class QProgressBar;

class ContentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ContentWidget(QWidget *parent = 0);
    void translateLanguage();
	ContentWidget(FaultParametervalue &Value, QWidget *parent = 0);

private:
    void initLeft();
    void initRightTop();
    void initRightCenter();
    void initRightBottom();
    void initRight();

private slots:
	void OkSlot();
	void CloseSlot();

private:
    QSplitter *main_splitter;

    QWidget *left_widget;
	DeviationInformation *m_deviation;
	DopFrom *m_dopfrom;
	Skyplot *m_skyplot;
	ReceiverLocationForm *m_receiverLocation;
	FaultDetectionForm *m_faultDetectionForm;


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
	QPushButton *start_button;
	QPushButton *pause_button;

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
};

#endif // CONTENTWIDGET_H
