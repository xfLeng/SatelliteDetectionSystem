#include <QLabel>
#include <QHBoxLayout>
#include <QSignalMapper>

#include "title_widget.h"
#include "../tool_button/tool_button.h"
#include <QtDebug>
#include <QString>
#pragma execution_character_set("utf-8")

TitleWidget::TitleWidget(QWidget *parent)
    : QWidget(parent)
{
    version_title = new QLabel();
    skin_button = new PushButton();
    min_button = new PushButton();
    max_button = new PushButton();
    close_button = new PushButton();
    version_title->setStyleSheet("color:white;");

    //设置图片
    skin_button->loadPixmap(":/sysButton/skin_button");
    min_button->loadPixmap(":/sysButton/min_button");
    max_button->loadPixmap(":/sysButton/max_button");
    close_button->loadPixmap(":/sysButton/close_button");

    connect(skin_button, SIGNAL(clicked()), this, SIGNAL(showSkin()));
    connect(min_button, SIGNAL(clicked()), this, SIGNAL(showMin()));
    connect(max_button, SIGNAL(clicked()), this, SIGNAL(showMax()));
    connect(close_button, SIGNAL(clicked()), this, SIGNAL(closeWidget()));

    QHBoxLayout *title_layout = new QHBoxLayout();
    title_layout->addWidget(version_title,0,Qt::AlignVCenter);
    title_layout->addStretch();
    title_layout->addWidget(skin_button, 0, Qt::AlignTop);
    title_layout->addWidget(min_button, 0, Qt::AlignTop);
    title_layout->addWidget(max_button, 0, Qt::AlignTop);
    title_layout->addWidget(close_button, 0, Qt::AlignTop);
    title_layout->setSpacing(0);
    title_layout->setContentsMargins(0, 0, 5, 0);
    version_title->setContentsMargins(15, 0, 0, 0);
    skin_button->setContentsMargins(0, 0, 10, 0);


    QStringList string_list;
    string_list<<":/toolWidget/tiJian"<<":/toolWidget/muMa"<<":/toolWidget/louDong";

    QHBoxLayout *button_layout = new QHBoxLayout();

    QSignalMapper *signal_mapper = new QSignalMapper(this);
    for(int i=0; i<string_list.size(); i++)
    {
        ToolButton *tool_button = new ToolButton(string_list.at(i));
        button_list.append(tool_button);
        connect(tool_button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
        signal_mapper->setMapping(tool_button, QString::number(i, 10));
        button_layout->addWidget(tool_button, 0, Qt::AlignBottom);
    }
    connect(signal_mapper, SIGNAL(mapped(QString)), this, SLOT(turnPage(QString)));

	QHBoxLayout *switch_layout = new QHBoxLayout();
	start_pause_btn = new QToolButton();
	stop_btn = new QToolButton();
	start_pause_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	stop_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

	QPixmap start_pause_pixmap(":/toolWidget/Start");
	start_pause_btn->setIcon(start_pause_pixmap);
	start_pause_btn->setIconSize(start_pause_pixmap.size());
	start_pause_btn->setFixedSize(start_pause_pixmap.width() + 25, start_pause_pixmap.height() + 25);

	QPixmap stop_pixmap(":/toolWidget/Stop");
	stop_btn->setIcon(stop_pixmap);
	stop_btn->setIconSize(stop_pixmap.size());
	stop_btn->setFixedSize(stop_pixmap.width() + 25, stop_pixmap.height() + 25);
	stop_btn->setStyleSheet("background:transparent;");
	button_layout->addWidget(start_pause_btn,0,Qt::AlignBottom);
	button_layout->addWidget(stop_btn,0,Qt::AlignBottom);
	start_pause_btn->setStyleSheet("background:transparent;");

	connect(start_pause_btn, SIGNAL(clicked()), this, SLOT(startPause()));
	connect(stop_btn, SIGNAL(clicked()), this, SLOT(stop()));

	start_pause_btn->setToolTip(tr("开始"));
	stop_btn->setToolTip(tr("结束"));
	
    button_layout->addStretch();
    button_layout->setSpacing(8);
    button_layout->setContentsMargins(15, 0, 0, 0);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addLayout(title_layout);
    main_layout->addLayout(button_layout);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(0, 0, 0, 0);

    this->translateLanguage();

    setLayout(main_layout);
    setFixedHeight(100);
    is_move = false;
}

void TitleWidget::translateLanguage()
{
    version_title->setText(tr("卫星检测系统"));
    skin_button->setToolTip(tr("换肤"));
    min_button->setToolTip(tr("最小化"));
    max_button->setToolTip(tr("最大化"));
    close_button->setToolTip(tr("关闭"));

    button_list.at(0)->setText(tr("RAIM"));
    button_list.at(1)->setText(tr("HIGH"));
    button_list.at(2)->setText(tr("优化HIGH"));

}

void TitleWidget::mousePressEvent(QMouseEvent *e)
{
    press_point = e->pos();
    is_move = true;
}

void TitleWidget::mouseMoveEvent(QMouseEvent *e)
{
    if((e->buttons() == Qt::LeftButton) && is_move)
    {
        static QWidget* parent_widget = this->parentWidget();
        QPoint parent_point = parent_widget->pos();
        parent_point.setX(parent_point.x() + e->x() - press_point.x());
        parent_point.setY(parent_point.y() + e->y() - press_point.y());
        parent_widget->move(parent_point);
    }
}

void TitleWidget::mouseReleaseEvent(QMouseEvent *)
{
    if(is_move)
    {
        is_move = false;
    }
}

void TitleWidget::mouseDoubleClickEvent(QMouseEvent *)
{
    emit showMax();
}

void TitleWidget::turnPage(QString current_page)
{
    bool ok;
    int current_index = current_page.toInt(&ok, 10);

    for(int i=0; i<button_list.count(); i++)
    {
        ToolButton *tool_button = button_list.at(i);
        if(current_index == i)
        {
            tool_button->setMousePress(true);
        }
        else
        {
            tool_button->setMousePress(false);
        }
    }
}

void TitleWidget::startPause() {
	QString toolTipName= start_pause_btn->toolTip();
	if (toolTipName=="开始") {
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

void TitleWidget::stop() {
	QString toolTipName = start_pause_btn->toolTip();
	if (toolTipName == "暂停") {
		start_pause_btn->setToolTip(tr("开始"));
		QPixmap start_pause_pixmap(":/toolWidget/Start");
		start_pause_btn->setIcon(start_pause_pixmap);
		start_pause_btn->setIconSize(start_pause_pixmap.size());
		start_pause_btn->setFixedSize(start_pause_pixmap.width() + 25, start_pause_pixmap.height() + 25);
	}

}