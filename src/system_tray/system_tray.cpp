#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QSystemTrayIcon>

#include "../main_widget/main_widget.h"
#include "system_tray.h"
#pragma execution_character_set("utf-8")

SystemTray::SystemTray(QWidget *parent)
    : QSystemTrayIcon(parent)
{
	main_weidget = parent;
    this->createAction();
    this->translateLanguage();
}

SystemTray::~SystemTray()
{

}

void SystemTray::translateLanguage()
{
    //放在托盘图标上时候显示
    this->setToolTip(tr("卫星检测系统"));

    action_open->setText(tr("打开主面板"));
    action_logout->setText(tr("退出"));
}

void SystemTray::createAction()
{
    this->setIcon(QIcon(":/img/safe"));

    tray_menu = new QMenu();
    action_open = new QAction(this);
    action_logout = new QAction(this);

    //添加菜单项
    tray_menu->addAction(action_open);
    tray_menu->addAction(action_logout);

    //设置信号连接
    /*QObject::connect(action_quit, SIGNAL(triggered(bool)), this, SIGNAL(logoutWidget()));
    QObject::connect(action_setting, SIGNAL(triggered(bool)), this, SIGNAL(setUp()));
    QObject::connect(action_about, SIGNAL(triggered(bool)), this, SIGNAL(aboutUs()));
    QObject::connect(action_login_home, SIGNAL(triggered(bool)), MenuAction::getInstance(), SLOT(openLoginHome()));
    QObject::connect(action_help, SIGNAL(triggered(bool)), MenuAction::getInstance(), SLOT(openHelpMe()));
    QObject::connect(action_check_update, SIGNAL(triggered(bool)), MenuAction::getInstance(), SLOT(openCheckUpdate()));*/

	//connect(action_open, SIGNAL(triggered()), qApp, SLOT(showWidget()));
	connect(action_open, SIGNAL(triggered(bool)), main_weidget, SLOT(showWidget()));
    connect(action_logout, SIGNAL(triggered()), qApp, SLOT(quit()));
    this->setContextMenu(tray_menu);
}
