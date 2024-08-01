#include "editdialog.h"
#include "ui_editdialog.h"
#include <QFileDialog> // Allows the user to select files and directories, used for uploading photos

EditDialog::EditDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditDialog)
{
    ui->setupUi(this);
}

EditDialog::~EditDialog()
{
    delete ui;
}

// All code above this comment was automatically generated by Qt Creator (when creating a new ui form for the dialog editor to edit paint entries)

// Added member functions below:

/* C++ reminder, we are passing the arguments by reference '&', which is a reference to the memory addresses of the variables - brand, color, etc.
 * When passing by reference, the function can access and manipulate the variables directly without making a copy. However, the 'const' keyword makes it so the value of these variables
 * cannot be changed. Here, they are used to populate the Edit window so the user can edit the fields, so we wouldn't want to change these values */

// Populate the Edit window with the fields to be edited
void EditDialog::setValues(const QString &brand, const QString &color, const QString &itemNumber, const QString &type, const QString &collection, const QString &quantity, const QString &imagePath)
{
    // setText(<variable>) sets the text of the input field (user's input) to the value of <variable>
    ui->inputBrand->setText(brand);
    ui->inputColor->setText(color);
    ui->inputItemNum->setText(itemNumber);
    ui->inputType->setText(type);
    ui->inputCollection->setText(collection);
    ui->inputQuantity->setText(quantity);

    // setPixmap(...): Sets the scaled image to be displayed in the labelImage widget.
    // QPixmap(imagePath): Loads the image from the file path stored in fileName
    ui->labelImage->setPixmap(QPixmap(imagePath).scaled(100, 100, Qt::KeepAspectRatio));
    selectedImagePath = imagePath;
}


// Retrieves the text entered by the user in the respective input fields
QString EditDialog::getBrand() const
{
    return ui->inputBrand->text();
}

QString EditDialog::getColor() const
{
    return ui->inputColor->text();
}

QString EditDialog::getItemNumber() const
{
    return ui->inputItemNum->text();
}

QString EditDialog::getType() const
{
    return ui->inputType->text();
}

QString EditDialog::getCollection() const
{
    return ui->inputCollection->text();
}

QString EditDialog::getQuantity() const
{
    return ui->inputQuantity->text();
}

QString EditDialog::getImagePath() const
{
    return selectedImagePath;
}

void EditDialog::on_buttonUploadImage_clicked()
{
    // Explaination of "QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");":
    // 'fileName' stores the path of the selected file as a string
    // 'getOpenFileName' opens a dialog window for the user to select a file
    // the 'this' pointer refers to the parent widget (in this case, the current instance of the EditDialog class)
    // "Open Image" is the title of the window
    // "" is the initial directory where the dialog will open, an empty string means it will use the root directory by default
    // The last parameter is a filter to show only the file types allowed for upload
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");
    if (!fileName.isEmpty()) {
        // setPixmap(...): Sets the scaled image to be displayed in the labelImage widget.
        // QPixmap(fileName): Loads the image from the file path stored in fileName
        ui->labelImage->setPixmap(QPixmap(fileName).scaled(100, 100, Qt::KeepAspectRatio));
        selectedImagePath = fileName; // Store the selected image path
    }
}


void EditDialog::on_buttonDeleteImage_clicked()
{
    ui->labelImage->clear();
    selectedImagePath.clear();
}

