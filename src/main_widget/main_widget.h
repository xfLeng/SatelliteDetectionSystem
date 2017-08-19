#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "../skin_widget/skin_widget.h"
#include "../system_tray/system_tray.h"
#include "../title_widget/title_widget.h"
#include "../content_widget/content_widget.h"

#include <QSystemTrayIcon>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

protected:
    void paintEvent(QPaintEvent *);

public slots:
    void showWidget();

private slots:
    void showMax();
    void showSkinWidget();
    void showMainMenu();
    void changeSkin(QString skin_name);
    void iconIsActived(QSystemTrayIcon::ActivationReason reason);

private:
    QRect location;
    TitleWidget *title_widget; //标题栏
    ContentWidget *content_widget; //主界面内容
    SystemTray *system_tray; //托盘项
    QString skin_name;//主窗口背景图片的名称
    SkinWidget *skin_widget; //显示皮肤界面

};

#endif // MAINWIDGET_H
