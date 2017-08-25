#ifndef GLONASSCHANGE_H
#define GLONASSCHANGE_H

#include <QDialog>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "datatype.h"
#include "qtpropertybrowser.h"
#include "qtpropertymanager.h"
namespace Ui {
class FaultParameter;
}

class FaultParameter : public QDialog
{
    Q_OBJECT

public:
    explicit FaultParameter(QWidget *parent = 0);
    FaultParameter(FaultParametervalue &Value,QWidget *parent = 0);
    ~FaultParameter();
private slots:
    void OkSlot();
    void CloseSlot();

private:
    Ui::FaultParameter *ui;
    void WinInI();
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


#endif // GLONASSCHANGE_H
