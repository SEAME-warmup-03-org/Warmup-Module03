#include <QtWidgets>
#include "phonebook.h"

PhoneBook::PhoneBook(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    ui.nameLine->setReadOnly(true);
    ui.phonenumberLine->setReadOnly(true);
    ui.emailLine->setReadOnly(true);
    ui.addressLine->setReadOnly(true);
    ui.searchLine->setReadOnly(false);

    ui.addButton->setEnabled(true);
    ui.submitButton->setEnabled(false);
    ui.cancelButton->setEnabled(false);
    ui.editButton->setEnabled(false);
    ui.removeButton->setEnabled(false);

    ui.nextButton->setEnabled(false);
    ui.previousButton->setEnabled(false);

    ui.nameButton->setEnabled(false);
    ui.phonenumberButton->setEnabled(false);
    ui.emailButton->setEnabled(false);
    ui.addressButton->setEnabled(false);

    ui.saveButton->setEnabled(false);
    ui.loadButton->setEnabled(true);

    setWindowTitle(tr("Phone Book"));
}

void PhoneBook::on_addButton_clicked()
{
    oldName = ui.nameLine->text();
    oldPhonenumber = ui.phonenumberLine->text();
    oldEmail = ui.emailLine->text();
    oldAddress = ui.addressLine->text();

    ui.nameLine->clear();
    ui.phonenumberLine->clear();
    ui.emailLine->clear();
    ui.addressLine->clear();

    updateInterface(AddingMode);
}

void PhoneBook::on_submitButton_clicked()
{
    QString name = ui.nameLine->text();
    QString phonenumber = ui.phonenumberLine->text();
    QString email = ui.emailLine->text();
    QString address = ui.addressLine->text();

    if(name.isEmpty() || phonenumber.isEmpty() || email.isEmpty() || address.isEmpty())
    {
        QMessageBox::information(this, tr("Empty Field"),
            tr("Please enter the information."));
        return;
    }

    bool flag = false;
    for(int i = 0; i < phonenumber.size(); i++)
    {
        if(!phonenumber[i].isDigit())
        {
            flag = true;
            break;
        }
    }
    if(flag)
    {
        QMessageBox::information(this, tr("Not A Number"),
            tr("Please enter phonenumber again."));
        return;
    }

    if(currentMode == AddingMode)
    {
        if(contactList.phonenumberSearch(phonenumber) == -1)
        {
            contactList.add(name, phonenumber, email, address);
            QMessageBox::information(this, tr("Add Successful"),
                tr("\"%1\" has been added to your phone book.").arg(name));
        }
        else
        {
            QMessageBox::information(this, tr("Add Unsuccessful"),
                tr("Sorry, Phonenumber \"%1\" is already in your phone book.").arg(phonenumber));
        }
    }
    else if(currentMode == EditingMode)
    {
        if(oldPhonenumber != phonenumber)
        {
            if(contactList.phonenumberSearch(phonenumber) == -1)
            {
                QMessageBox::information(this, tr("Edit Successful"),
                    tr("\"%1\" has been edited in your phone book.").arg(oldName));
                contactList.remove(contactList.phonenumberSearch(oldPhonenumber));
                contactList.add(name, phonenumber, email, address);
            }
            else
            {
                QMessageBox::information(this, tr("Edit Unsuccessful"),
                    tr("Sorry, Phonenumber \"%1\" is already in your phone book.").arg(phonenumber));
            }
        }
        else
        {
            QMessageBox::information(this, tr("Edit Successful"),
                tr("\"%1\" has been edited in your phone book.").arg(name));
            contactList.remove(contactList.phonenumberSearch(phonenumber));
            contactList.add(name, phonenumber, email, address);
        }
    }

    updateInterface(NavigationMode);
}

void PhoneBook::on_cancelButton_clicked()
{
    ui.nameLine->setText(oldName);
    ui.phonenumberLine->setText((oldPhonenumber));
    ui.emailLine->setText(oldEmail);
    ui.addressLine->setText(oldAddress);

    updateInterface(NavigationMode);
}

void PhoneBook::on_editButton_clicked()
{
    oldName = ui.nameLine->text();
    oldPhonenumber = ui.phonenumberLine->text();
    oldEmail = ui.emailLine->text();
    oldAddress = ui.addressLine->text();

    updateInterface(EditingMode);
}

void PhoneBook::on_removeButton_clicked()
{
    QString name = ui.nameLine->text();
    QString phonenumber = ui.phonenumberLine->text();

    int button = QMessageBox::question(this, tr("Confirm Remove"),
        tr("Are you sure you want to remove \"%1\"?").arg(name),
        QMessageBox::Yes | QMessageBox::No);

    if(button == QMessageBox::Yes)
    {
        on_previousButton_clicked();
        contactList.remove(contactList.phonenumberSearch(phonenumber));

        QMessageBox::information(this, tr("Remove Successful"),
            tr("\"%1\" has been removed from your phone book.").arg(name));
    }

    updateInterface(NavigationMode);
}

void PhoneBook::on_previousButton_clicked()
{
    QString name = ui.nameLine->text();
    int idx = contactList.nameSearch(name);

    if(idx != 0)
        idx--;
    else
        idx = contactList.size() - 1;

    QList<QString> temp = contactList.idxSearch(idx);
    ui.nameLine->setText(temp[0]);
    ui.phonenumberLine->setText(temp[1]);
    ui.emailLine->setText(temp[2]);
    ui.addressLine->setText(temp[3]);
}

void PhoneBook::on_nextButton_clicked()
{
    QString name = ui.nameLine->text();
    int idx = contactList.nameSearch(name);

    if(idx != contactList.size() - 1)
        idx++;
    else
        idx = 0;

    QList<QString> temp = contactList.idxSearch(idx);
    ui.nameLine->setText(temp[0]);
    ui.phonenumberLine->setText(temp[1]);
    ui.emailLine->setText(temp[2]);
    ui.addressLine->setText(temp[3]);
}

void PhoneBook::on_nameButton_clicked()
{
    QString name = ui.searchLine->text();
    if(contactList.nameSearch(name) == -1)
    {
        QMessageBox::information(this, tr("Contact Not Found"),
            tr("Sorry, \"%1\" is not in your phone book.").arg(name));
    }
    else
    {
        QList<QString> temp = contactList.idxSearch(contactList.nameSearch(name));
        ui.nameLine->setText(temp[0]);
        ui.phonenumberLine->setText(temp[1]);
        ui.emailLine->setText(temp[2]);
        ui.addressLine->setText(temp[3]);
    }
    ui.searchLine->clear();
}

void PhoneBook::on_phonenumberButton_clicked()
{
    QString phonenumber = ui.searchLine->text();
    if(contactList.phonenumberSearch(phonenumber) == -1)
    {
        QMessageBox::information(this, tr("Contact Not Found"),
            tr("Sorry, \"%1\" is not in your phone book.").arg(phonenumber));
    }
    else
    {
        QList<QString> temp = contactList.idxSearch(contactList.phonenumberSearch(phonenumber));
        ui.nameLine->setText(temp[0]);
        ui.phonenumberLine->setText(temp[1]);
        ui.emailLine->setText(temp[2]);
        ui.addressLine->setText(temp[3]);
    }
    ui.searchLine->clear();
}

void PhoneBook::on_emailButton_clicked()
{
    QString email = ui.searchLine->text();
    if(contactList.emailSearch(email) == -1)
    {
        QMessageBox::information(this, tr("Contact Not Found"),
            tr("Sorry, \"%1\" is not in your phone book.").arg(email));
    }
    else
    {
        QList<QString> temp = contactList.idxSearch(contactList.emailSearch(email));
        ui.nameLine->setText(temp[0]);
        ui.phonenumberLine->setText(temp[1]);
        ui.emailLine->setText(temp[2]);
        ui.addressLine->setText(temp[3]);
    }
    ui.searchLine->clear();
}

void PhoneBook::on_addressButton_clicked()
{
    QString address = ui.searchLine->text();
    if(contactList.addressSearch(address) == -1)
    {
        QMessageBox::information(this, tr("Contact Not Found"),
            tr("Sorry, \"%1\" is not in your phone book.").arg(address));
    }
    else
    {
        QList<QString> temp = contactList.idxSearch(contactList.addressSearch(address));
        ui.nameLine->setText(temp[0]);
        ui.phonenumberLine->setText(temp[1]);
        ui.emailLine->setText(temp[2]);
        ui.addressLine->setText(temp[3]);
    }
    ui.searchLine->clear();
}

void PhoneBook::updateInterface(Mode mode)
{
    currentMode = mode;

    switch(currentMode)
    {
    case AddingMode:
    case EditingMode:
        ui.nameLine->setReadOnly(false);
        ui.phonenumberLine->setReadOnly(false);
        ui.emailLine->setReadOnly(false);
        ui.addressLine->setReadOnly(false);
        ui.nameLine->setFocus(Qt::OtherFocusReason);

        ui.addButton->setEnabled(false);
        ui.editButton->setEnabled(false);
        ui.submitButton->setEnabled(true);
        ui.cancelButton->setEnabled(true);
        ui.removeButton->setEnabled(false);

        ui.nextButton->setEnabled(false);
        ui.previousButton->setEnabled(false);

        ui.nameButton->setEnabled(false);
        ui.phonenumberButton->setEnabled(false);
        ui.emailButton->setEnabled(false);
        ui.addressButton->setEnabled(false);

        ui.saveButton->setEnabled(false);
        ui.loadButton->setEnabled(false);
        break;

    case NavigationMode:
        if(contactList.isEmpty())
        {
            ui.nameLine->clear();
            ui.phonenumberLine->clear();
            ui.emailLine->clear();
            ui.addressLine->clear();
        }

        ui.nameLine->setReadOnly(true);
        ui.phonenumberLine->setReadOnly(true);
        ui.emailLine->setReadOnly(true);
        ui.addressLine->setReadOnly(true);

        ui.addButton->setEnabled(true);
        ui.submitButton->setEnabled(false);
        ui.cancelButton->setEnabled(false);

        int number = contactList.size();

        ui.editButton->setEnabled(number >= 1);
        ui.removeButton->setEnabled(number >= 1);

        ui.nextButton->setEnabled(number > 1);
        ui.previousButton->setEnabled(number > 1);

        ui.nameButton->setEnabled(number > 1);
        ui.phonenumberButton->setEnabled(number > 1);
        ui.emailButton->setEnabled(number > 1);
        ui.addressButton->setEnabled(number > 1);

        ui.saveButton->setEnabled(number >= 1);
        ui.loadButton->setEnabled(true);
        break;
    }
}

void PhoneBook::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Phone Book"), "",
        tr("Phone Book (*.abk);;All Files (*)"));

    if(fileName.isEmpty())
        return;
    else
    {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }

        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_5_15);

        QList<QList<QString>> temp;
        for(int i = 0; i < contactList.size(); i++)
        {
            temp.push_back(contactList.idxSearch(i));
        }

        out << temp;
    }
}

void PhoneBook::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Phone Book"), "",
        tr("Phone Book (*.abk);;All Files (*)"));

    if (fileName.isEmpty())
        return;
    else
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_5_15);

        contactList.clear();

        QList<QList<QString>> temp;
        in >> temp;

        for(int i = 0; i < temp.size(); i++)
        {
            contactList.add(temp[i][0], temp[i][1], temp[i][2], temp[i][3]);
        }

        if (contactList.isEmpty())
        {
            QMessageBox::information(this, tr("No contacts in file"),
                tr("The file you are attempting to open contains no contacts."));
        }
        else
        {
            QList<QString> temp = contactList.idxSearch(0);
            ui.nameLine->setText(temp[0]);
            ui.phonenumberLine->setText(temp[1]);
            ui.emailLine->setText(temp[2]);
            ui.addressLine->setText(temp[3]);
        }
    }

    updateInterface(NavigationMode);
}
