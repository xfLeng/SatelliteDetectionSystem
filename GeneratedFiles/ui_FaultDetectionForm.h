/********************************************************************************
** Form generated from reading UI file 'FaultDetectionForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAULTDETECTIONFORM_H
#define UI_FAULTDETECTIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaultDetectionForm
{
public:

    void setupUi(QWidget *FaultDetectionForm)
    {
        if (FaultDetectionForm->objectName().isEmpty())
            FaultDetectionForm->setObjectName(QStringLiteral("FaultDetectionForm"));
        FaultDetectionForm->resize(155, 80);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FaultDetectionForm->sizePolicy().hasHeightForWidth());
        FaultDetectionForm->setSizePolicy(sizePolicy);

        retranslateUi(FaultDetectionForm);

        QMetaObject::connectSlotsByName(FaultDetectionForm);
    } // setupUi

    void retranslateUi(QWidget *FaultDetectionForm)
    {
        FaultDetectionForm->setWindowTitle(QApplication::translate("FaultDetectionForm", "\345\215\253\346\230\237\346\225\205\351\232\234\346\243\200\346\265\213", 0));
    } // retranslateUi

};

namespace Ui {
    class FaultDetectionForm: public Ui_FaultDetectionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAULTDETECTIONFORM_H
