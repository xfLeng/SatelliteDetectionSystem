#ifndef SYSYTEMTRAY_H
#define SYSYTEMTRAY_H

#include <QSystemTrayIcon>


class QMenu;
class QAction;

class SystemTray : public QSystemTrayIcon
{
	Q_OBJECT

public:
	explicit SystemTray(QWidget *parent = 0);
	~SystemTray();
	void translateLanguage();
	QWidget *main_weidget;
private:
	void createAction();

private:
	QMenu *tray_menu; //托盘菜单
	QAction *action_open; //打开主面板
	QAction *action_logout; //退出

};

#endif //SYSYTEMTRAY_H
