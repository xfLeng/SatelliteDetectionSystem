/********************************************************************************
** Form generated from reading UI file 'DopFrom.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOPFROM_H
#define UI_DOPFROM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DopFrom
{
public:

    void setupUi(QWidget *DopFrom)
    {
        if (DopFrom->objectName().isEmpty())
            DopFrom->setObjectName(QStringLiteral("DopFrom"));
        DopFrom->resize(400, 300);

        retranslateUi(DopFrom);

        QMetaObject::connectSlotsByName(DopFrom);
    } // setupUi

    void retranslateUi(QWidget *DopFrom)
    {
        DopFrom->setWindowTitle(QApplication::translate("DopFrom", "DopFrom", 0));
    } // retranslateUi

};

namespace Ui {
    class DopFrom: public Ui_DopFrom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOPFROM_H
