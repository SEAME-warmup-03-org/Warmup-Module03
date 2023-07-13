#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QWidget>
#include "contactlist.h"
#include "ui_form.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
QT_END_NAMESPACE

class PhoneBook : public QWidget
{
    Q_OBJECT

public:
    PhoneBook(QWidget *parent = nullptr);
    enum Mode {NavigationMode, AddingMode, EditingMode};

private slots:
    void on_addButton_clicked();
    void on_submitButton_clicked();
    void on_cancelButton_clicked();
    void on_editButton_clicked();
    void on_removeButton_clicked();
    void on_previousButton_clicked();
    void on_nextButton_clicked();
    void on_nameButton_clicked();
    void on_phonenumberButton_clicked();
    void on_emailButton_clicked();
    void on_addressButton_clicked();
    void on_saveButton_clicked();
    void on_loadButton_clicked();

private:
    Ui::Form ui;

    void updateInterface(Mode mode);

    ContactList contactList;

    QString oldName;
    QString oldPhonenumber;
    QString oldEmail;
    QString oldAddress;

    Mode currentMode;
};

#endif
