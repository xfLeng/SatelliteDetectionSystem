/********************************************************************************
** Form generated from reading UI file 'ReceiverLocationForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVERLOCATIONFORM_H
#define UI_RECEIVERLOCATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReceiverLocationForm
{
public:

    void setupUi(QWidget *ReceiverLocationForm)
    {
        if (ReceiverLocationForm->objectName().isEmpty())
            ReceiverLocationForm->setObjectName(QStringLiteral("ReceiverLocationForm"));
        ReceiverLocationForm->resize(155, 80);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ReceiverLocationForm->sizePolicy().hasHeightForWidth());
        ReceiverLocationForm->setSizePolicy(sizePolicy);

        retranslateUi(ReceiverLocationForm);

        QMetaObject::connectSlotsByName(ReceiverLocationForm);
    } // setupUi

    void retranslateUi(QWidget *ReceiverLocationForm)
    {
        ReceiverLocationForm->setWindowTitle(QApplication::translate("ReceiverLocationForm", "\350\275\250\350\277\271\345\233\276", 0));
    } // retranslateUi

};

namespace Ui {
    class ReceiverLocationForm: public Ui_ReceiverLocationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVERLOCATIONFORM_H
