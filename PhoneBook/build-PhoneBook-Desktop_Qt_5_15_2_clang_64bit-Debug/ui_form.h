/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QLineEdit *addressLine;
    QLabel *label_6;
    QPushButton *editButton;
    QLineEdit *phonenumberLine;
    QLineEdit *searchLine;
    QPushButton *cancelButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QPushButton *addButton;
    QPushButton *removeButton;
    QLineEdit *emailLine;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_2;
    QPushButton *submitButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *nameButton;
    QPushButton *phonenumberButton;
    QPushButton *emailButton;
    QPushButton *addressButton;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *nameLine;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(580, 350);
        Form->setMinimumSize(QSize(580, 350));
        Form->setMaximumSize(QSize(580, 350));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        addressLine = new QLineEdit(Form);
        addressLine->setObjectName(QString::fromUtf8("addressLine"));

        gridLayout->addWidget(addressLine, 4, 1, 1, 1);

        label_6 = new QLabel(Form);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        editButton = new QPushButton(Form);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        gridLayout->addWidget(editButton, 4, 2, 1, 1);

        phonenumberLine = new QLineEdit(Form);
        phonenumberLine->setObjectName(QString::fromUtf8("phonenumberLine"));

        gridLayout->addWidget(phonenumberLine, 1, 1, 1, 1);

        searchLine = new QLineEdit(Form);
        searchLine->setObjectName(QString::fromUtf8("searchLine"));

        gridLayout->addWidget(searchLine, 7, 1, 1, 1);

        cancelButton = new QPushButton(Form);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout->addWidget(cancelButton, 3, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        previousButton = new QPushButton(Form);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));

        horizontalLayout->addWidget(previousButton);

        nextButton = new QPushButton(Form);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        horizontalLayout->addWidget(nextButton);


        gridLayout->addLayout(horizontalLayout, 5, 1, 1, 1);

        label_4 = new QLabel(Form);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        saveButton = new QPushButton(Form);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout_3->addWidget(saveButton);

        loadButton = new QPushButton(Form);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));

        horizontalLayout_3->addWidget(loadButton);


        gridLayout->addLayout(horizontalLayout_3, 10, 1, 1, 1);

        addButton = new QPushButton(Form);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 0, 2, 1, 1);

        removeButton = new QPushButton(Form);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        gridLayout->addWidget(removeButton, 5, 2, 1, 1);

        emailLine = new QLineEdit(Form);
        emailLine->setObjectName(QString::fromUtf8("emailLine"));

        gridLayout->addWidget(emailLine, 3, 1, 1, 1);

        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_7 = new QLabel(Form);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 9, 1, 1, 1);

        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        submitButton = new QPushButton(Form);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));

        gridLayout->addWidget(submitButton, 1, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        nameButton = new QPushButton(Form);
        nameButton->setObjectName(QString::fromUtf8("nameButton"));

        horizontalLayout_2->addWidget(nameButton);

        phonenumberButton = new QPushButton(Form);
        phonenumberButton->setObjectName(QString::fromUtf8("phonenumberButton"));

        horizontalLayout_2->addWidget(phonenumberButton);

        emailButton = new QPushButton(Form);
        emailButton->setObjectName(QString::fromUtf8("emailButton"));

        horizontalLayout_2->addWidget(emailButton);

        addressButton = new QPushButton(Form);
        addressButton->setObjectName(QString::fromUtf8("addressButton"));

        horizontalLayout_2->addWidget(addressButton);


        gridLayout->addLayout(horizontalLayout_2, 8, 1, 1, 1);

        label_3 = new QLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_5 = new QLabel(Form);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 6, 1, 1, 1);

        nameLine = new QLineEdit(Form);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));

        gridLayout->addWidget(nameLine, 0, 1, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label_6->setText(QCoreApplication::translate("Form", "Search by:", nullptr));
        editButton->setText(QCoreApplication::translate("Form", "Edit", nullptr));
        cancelButton->setText(QCoreApplication::translate("Form", "Cancel", nullptr));
        previousButton->setText(QCoreApplication::translate("Form", "<- Previous", nullptr));
        nextButton->setText(QCoreApplication::translate("Form", "Next ->", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "Address:", nullptr));
        saveButton->setText(QCoreApplication::translate("Form", "Save...", nullptr));
        loadButton->setText(QCoreApplication::translate("Form", "Load...", nullptr));
        addButton->setText(QCoreApplication::translate("Form", "Add", nullptr));
        removeButton->setText(QCoreApplication::translate("Form", "Remove", nullptr));
        label->setText(QCoreApplication::translate("Form", "Name:", nullptr));
        label_7->setText(QString());
        label_2->setText(QCoreApplication::translate("Form", "Phonenumber:", nullptr));
        submitButton->setText(QCoreApplication::translate("Form", "Submit", nullptr));
        nameButton->setText(QCoreApplication::translate("Form", "Name", nullptr));
        phonenumberButton->setText(QCoreApplication::translate("Form", "Phonenumber", nullptr));
        emailButton->setText(QCoreApplication::translate("Form", "Email", nullptr));
        addressButton->setText(QCoreApplication::translate("Form", "Address", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "Email:", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
