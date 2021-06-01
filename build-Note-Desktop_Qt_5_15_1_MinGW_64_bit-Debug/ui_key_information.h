/********************************************************************************
** Form generated from reading UI file 'key_information.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEY_INFORMATION_H
#define UI_KEY_INFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Key_information
{
public:

    void setupUi(QWidget *Key_information)
    {
        if (Key_information->objectName().isEmpty())
            Key_information->setObjectName(QString::fromUtf8("Key_information"));
        Key_information->resize(400, 300);

        retranslateUi(Key_information);

        QMetaObject::connectSlotsByName(Key_information);
    } // setupUi

    void retranslateUi(QWidget *Key_information)
    {
        Key_information->setWindowTitle(QCoreApplication::translate("Key_information", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Key_information: public Ui_Key_information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEY_INFORMATION_H
