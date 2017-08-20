#include <QLabel>
#include <QEvent>
#include <QPainter>
#include <QSplitter>
#include <QHBoxLayout>
#include <QPushButton>
#include <QToolButton>

#include "content_widget.h"
#pragma execution_character_set("utf-8")

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

    right_top_widget->setFixedSize(220, 60);
    right_bottom_widget->setFixedSize(220, 60);
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
    label = new QLabel();
    suggest_label = new QLabel();
    system_safe_label = new QLabel();
    power_button = new QPushButton();

    left_widget->resize(850, 500);

    QPixmap label_pixmap(":/contentWidget/computer");
    label->setPixmap(label_pixmap);
    label->setFixedSize(label_pixmap.size());

    QFont suggest_font = suggest_label->font();
    suggest_font.setPointSize(12);
    suggest_font.setBold(true);
    suggest_label->setFont(suggest_font);
    suggest_label->setStyleSheet("color:gray;");

    QFont system_safe_font = system_safe_label->font();
    system_safe_font.setBold(true);
    system_safe_label->setFont(system_safe_font);
    system_safe_label->setStyleSheet("color:gray;");

    QPixmap pixmap(":/contentWidget/power");
    power_button->setIcon(pixmap);
    power_button->setIconSize(pixmap.size());
    power_button->setFixedSize(180, 70);
    power_button->setStyleSheet("QPushButton{border-radius:5px; background:rgb(110, 190, 10); color:white;}"
                                "QPushButton:hover{background:rgb(140, 220, 35);}");
    QFont power_font = power_button->font();
    power_font.setPointSize(16);
    power_button->setFont(power_font);

    QVBoxLayout *v_layout = new QVBoxLayout();
    v_layout->addWidget(suggest_label);
    v_layout->addWidget(system_safe_label);
    v_layout->addStretch();
    v_layout->setSpacing(15);
    v_layout->setContentsMargins(0, 20, 0, 0);

    QHBoxLayout *h_layout = new QHBoxLayout();
    h_layout->addWidget(label, 0, Qt::AlignTop);
    h_layout->addLayout(v_layout);
    h_layout->addStretch();
    h_layout->setSpacing(20);
    h_layout->setContentsMargins(30, 20, 0, 0);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addLayout(h_layout);
    main_layout->addWidget(power_button, 0, Qt::AlignCenter);
    main_layout->addStretch();
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(0, 0, 0, 0);

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
	open_file->setFixedSize(120, 40);
	open_file->setStyleSheet("QPushButton{color:green; border-image:url(:/contentWidget/login);}"
                                "QPushButton:hover{color:rgb(110, 190, 10);}");
    QFont font = open_file->font();
	font.setBold(true);
	font.setPointSize(10);
	open_file->setFont(font);
	//----------------实时连接------------------------
	constant_file->setFixedSize(120, 40);
	constant_file->setStyleSheet("QPushButton{color:green; border-image:url(:/contentWidget/login);}"
		"QPushButton:hover{color:rgb(110, 190, 10);}");
	constant_file->setFont(font);

    QHBoxLayout *rightTop_layout = new QHBoxLayout();
	rightTop_layout->addWidget(open_file);
	rightTop_layout->addWidget(constant_file);
	rightTop_layout->addStretch();
	rightTop_layout->setContentsMargins(15, 0, 0, 0);

    right_top_widget->setLayout(rightTop_layout);
}

void ContentWidget::initRightCenter()
{
    right_center_widget = new QWidget();
   

    QHBoxLayout *h_layout = new QHBoxLayout();
    h_layout->setSpacing(0);
    h_layout->setContentsMargins(0, 0, 0, 0);

    right_center_widget->setLayout(h_layout);
}

void ContentWidget::initRightBottom()
{
    right_bottom_widget = new QWidget();
	start_button = new QPushButton();
	pause_button = new QPushButton();

	QFont font = open_file->font();
	font.setBold(true);
	font.setPointSize(10);

	start_button->setFixedSize(120, 40);
	start_button->setStyleSheet("QPushButton{color:green; border-image:url(:/contentWidget/login);}"
		"QPushButton:hover{color:rgb(110, 190, 10);}");
	start_button->setFont(font);

	pause_button->setFixedSize(120, 40);
	pause_button->setStyleSheet("QPushButton{color:green; border-image:url(:/contentWidget/login);}"
		"QPushButton:hover{color:rgb(110, 190, 10);}");
	pause_button->setFont(font);

	QHBoxLayout *bottom_layout = new QHBoxLayout();
	bottom_layout->addWidget(start_button);
	bottom_layout->addWidget(pause_button);
	bottom_layout->addStretch();
	bottom_layout->setContentsMargins(15, 0, 0, 0);

    right_bottom_widget->setLayout(bottom_layout);
}

void ContentWidget::translateLanguage()
{
    suggest_label->setText(tr("suggest"));
    system_safe_label->setText(tr("system safe"));
    power_button->setText(tr("power"));

	open_file->setText(tr("打开文件"));
	constant_file->setText(tr("实时连接"));
	
	start_button->setText(tr("开始"));
	pause_button->setText(tr("暂停"));
}
