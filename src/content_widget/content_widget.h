#ifndef CONTENTWIDGET_H
#define CONTENTWIDGET_H

#include <QWidget>

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

private:
    void initLeft();
    void initRightTop();
    void initRightCenter();
    void initRightBottom();
    void initRight();

private:
    QSplitter *main_splitter;

    QWidget *left_widget;
    QLabel *label;
    QLabel *suggest_label;
    QLabel *system_safe_label;
    QPushButton *power_button; //立即体检按钮

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
};

#endif // CONTENTWIDGET_H
