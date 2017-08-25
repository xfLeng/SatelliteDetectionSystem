/********************************************************************************
** Form generated from reading UI file 'DeviationInformation.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVIATIONINFORMATION_H
#define UI_DEVIATIONINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviationInformation
{
public:

    void setupUi(QWidget *DeviationInformation)
    {
        if (DeviationInformation->objectName().isEmpty())
            DeviationInformation->setObjectName(QStringLiteral("DeviationInformation"));
        DeviationInformation->resize(400, 300);

        retranslateUi(DeviationInformation);

        QMetaObject::connectSlotsByName(DeviationInformation);
    } // setupUi

    void retranslateUi(QWidget *DeviationInformation)
    {
        DeviationInformation->setWindowTitle(QApplication::translate("DeviationInformation", "DeviationInformation", 0));
    } // retranslateUi

};

namespace Ui {
    class DeviationInformation: public Ui_DeviationInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVIATIONINFORMATION_H
