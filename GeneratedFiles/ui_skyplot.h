/********************************************************************************
** Form generated from reading UI file 'skyplot.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKYPLOT_H
#define UI_SKYPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Skyplot
{
public:
    QGraphicsView *graphicsView;
    QCheckBox *GAO_cek;
    QCheckBox *GPS_cek;
    QCheckBox *BDS_cek;
    QCheckBox *GLS_cek;

    void setupUi(QDialog *Skyplot)
    {
        if (Skyplot->objectName().isEmpty())
            Skyplot->setObjectName(QStringLiteral("Skyplot"));
        Skyplot->resize(420, 443);
        graphicsView = new QGraphicsView(Skyplot);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 30, 401, 401));
        GAO_cek = new QCheckBox(Skyplot);
        GAO_cek->setObjectName(QStringLiteral("GAO_cek"));
        GAO_cek->setGeometry(QRect(270, 0, 71, 16));
        GPS_cek = new QCheckBox(Skyplot);
        GPS_cek->setObjectName(QStringLiteral("GPS_cek"));
        GPS_cek->setGeometry(QRect(90, 0, 71, 16));
        BDS_cek = new QCheckBox(Skyplot);
        BDS_cek->setObjectName(QStringLiteral("BDS_cek"));
        BDS_cek->setGeometry(QRect(10, 0, 71, 16));
        GLS_cek = new QCheckBox(Skyplot);
        GLS_cek->setObjectName(QStringLiteral("GLS_cek"));
        GLS_cek->setGeometry(QRect(180, 0, 71, 16));

        retranslateUi(Skyplot);

        QMetaObject::connectSlotsByName(Skyplot);
    } // setupUi

    void retranslateUi(QDialog *Skyplot)
    {
        Skyplot->setWindowTitle(QApplication::translate("Skyplot", "Skyplot", 0));
        GAO_cek->setText(QApplication::translate("Skyplot", "Galileo", 0));
        GPS_cek->setText(QApplication::translate("Skyplot", "GPS", 0));
        BDS_cek->setText(QApplication::translate("Skyplot", "BD2", 0));
        GLS_cek->setText(QApplication::translate("Skyplot", "GLONASS", 0));
    } // retranslateUi

};

namespace Ui {
    class Skyplot: public Ui_Skyplot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKYPLOT_H
