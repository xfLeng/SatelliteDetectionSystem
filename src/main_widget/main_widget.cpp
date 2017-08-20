#include "main_widget.h"

#include <QVBoxLayout>
#include <QApplication>
#include <QDesktopWidget>

#include "../util/util.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
    setMinimumSize(900, 600);
    setWindowIcon(QIcon(":/img/safe.ico"));
    setWindowFlags(Qt::FramelessWindowHint);
    location = this->geometry();

    bool is_read = Util::readInit(QString("./user.ini"), QString("skin"), skin_name);
    if(is_read)
    {
        if(skin_name.isEmpty())
        {
            skin_name = QString(":/skin/17_big");
        }
    }
    else
    {
        skin_name = QString(":/skin/17_big");
    }

    title_widget = new TitleWidget();
    content_widget = new ContentWidget();
    skin_widget = new SkinWidget(this);
    system_tray = new SystemTray(this);

    QVBoxLayout *center_layout = new QVBoxLayout();
    center_layout->addWidget(content_widget);
    center_layout->setSpacing(0);
    center_layout->setContentsMargins(1, 0, 1, 1);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addWidget(title_widget);
    main_layout->addLayout(center_layout);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(0, 0, 0, 0);

    setLayout(main_layout);

    connect(title_widget, SIGNAL(showSkin()), this, SLOT(showSkinWidget()));
    connect(title_widget, SIGNAL(showMainMenu()), this, SLOT(showMainMenu()));
    connect(title_widget, SIGNAL(showMax()), this, SLOT(showMax()));
    connect(title_widget, SIGNAL(showMin()), this, SLOT(showMinimized()));
    connect(title_widget, SIGNAL(closeWidget()), this, SLOT(hide()));
  
    connect(skin_widget, SIGNAL(changeSkin(QString)), this, SLOT(changeSkin(QString)));

    connect(system_tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconIsActived(QSystemTrayIcon::ActivationReason)));

    system_tray->show();
}

MainWidget::~MainWidget()
{

}

void MainWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap(skin_name));

    QPainter painter2(this);
    painter2.setPen(Qt::gray);
    static const QPointF points[4] = {QPointF(0, 100), QPointF(0, this->height()-1), QPointF(this->width()-1, this->height()-1), QPointF(this->width()-1, 100)};
    painter2.drawPolyline(points, 4);
}

void MainWidget::showMax()
{
    static bool is_max=false;
    if(is_max)
    {
        this->setGeometry(location);
    }
    else
    {
        //获取当前界面的位置
        location = this->geometry();
        this->setGeometry(QApplication::desktop()->availableGeometry());
    }
    is_max = !is_max;
}

void MainWidget::showSkinWidget()
{
    skin_widget->show();
}

void MainWidget::showMainMenu()
{
    //设置主菜单出现的位置
    QPoint p = rect().topRight();
    p.setX(p.x() - 150);
    p.setY(p.y() + 22);
}

void MainWidget::iconIsActived(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    //点击托盘图标之后松开
    case QSystemTrayIcon::Trigger:
    {
        showWidget();
        break;
    }
        //双击托盘图标
    case QSystemTrayIcon::DoubleClick:
    {
        showWidget();
        break;
    }
    default:
        break;
    }
}

void MainWidget::showWidget()
{
    this->showNormal();
    this->raise();
    this->activateWindow();
    title_widget->turnPage(0);
}

void MainWidget::changeSkin(QString skin_name)
{
    Util::writeInit(QString("./user.ini"), QString("skin"), skin_name);
    this->skin_name = skin_name;
    update();
}
