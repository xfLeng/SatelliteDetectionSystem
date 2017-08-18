#include <QApplication>

#include "src/main_widget/main_widget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWidget main_widget;
    main_widget.showWidget();

	//
    return app.exec();
}
