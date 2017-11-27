#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    radius = ui->sliderBlurRadius->value();
    blurType = ui->spinBoxBlurType->value();

    originalImage = QImage(":/img/lenna.png");

    updateWindowImages();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sliderBlurRadius_sliderMoved(int position)
{
    radius = position;
    ui->labelBlurredImage->setPixmap(QPixmap::fromImage(GLBluring.blurImage(shownImage, radius, blurType)));
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    updateWindowImages();
}

void MainWindow::on_buttonOpenFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    if (!fileName.isEmpty())
    {
        QImageReader reader(fileName);
        if (reader.canRead())
        {
            originalImage = QImage(fileName);
            updateWindowImages();
        }
    }
}

void MainWindow::on_spinBoxBlurType_valueChanged(int arg1)
{
    blurType = arg1;
    ui->labelBlurredImage->setPixmap(QPixmap::fromImage(GLBluring.blurImage(shownImage, radius, blurType)));
}

void MainWindow::updateWindowImages()
{
    shownImage = originalImage.scaled(ui->labelOriginalImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    ui->labelOriginalImage->setPixmap(QPixmap::fromImage(shownImage));
    ui->labelBlurredImage->setPixmap(QPixmap::fromImage(GLBluring.blurImage(shownImage, radius, blurType)));
}
