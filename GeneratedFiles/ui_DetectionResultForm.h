/********************************************************************************
** Form generated from reading UI file 'DetectionResultForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTIONRESULTFORM_H
#define UI_DETECTIONRESULTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectionResultForm
{
public:

    void setupUi(QWidget *DetectionResultForm)
    {
        if (DetectionResultForm->objectName().isEmpty())
            DetectionResultForm->setObjectName(QStringLiteral("DetectionResultForm"));
        DetectionResultForm->resize(155, 80);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DetectionResultForm->sizePolicy().hasHeightForWidth());
        DetectionResultForm->setSizePolicy(sizePolicy);

        retranslateUi(DetectionResultForm);

        QMetaObject::connectSlotsByName(DetectionResultForm);
    } // setupUi

    void retranslateUi(QWidget *DetectionResultForm)
    {
        DetectionResultForm->setWindowTitle(QApplication::translate("DetectionResultForm", "\345\215\253\346\230\237\346\225\205\351\232\234\346\243\200\346\265\213\347\273\223\346\236\234", 0));
    } // retranslateUi

};

namespace Ui {
    class DetectionResultForm: public Ui_DetectionResultForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTIONRESULTFORM_H
