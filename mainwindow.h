#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QImageReader>

#include <QElapsedTimer>

#include "glblurfunctions.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sliderBlurRadius_sliderMoved(int position);
    void on_buttonOpenFile_clicked();

    void on_spinBoxBlurType_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;

    int radius;
    int blurType;

    GLBlurFunctions GLBluring;
    QImage originalImage;
    QImage shownImage;

    QElapsedTimer timer;

    void resizeEvent(QResizeEvent *event);
    void updateWindowImages();
};

#endif // MAINWINDOW_H
