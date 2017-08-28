/********************************************************************************
** Form generated from reading UI file 'HPLForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPLFORM_H
#define UI_HPLFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HPLForm
{
public:

    void setupUi(QWidget *HPLForm)
    {
        if (HPLForm->objectName().isEmpty())
            HPLForm->setObjectName(QStringLiteral("HPLForm"));
        HPLForm->resize(400, 300);

        retranslateUi(HPLForm);

        QMetaObject::connectSlotsByName(HPLForm);
    } // setupUi

    void retranslateUi(QWidget *HPLForm)
    {
        HPLForm->setWindowTitle(QApplication::translate("HPLForm", "HPL", 0));
    } // retranslateUi

};

namespace Ui {
    class HPLForm: public Ui_HPLForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPLFORM_H
