/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *layoutUIElements;
    QPushButton *buttonOpenFile;
    QLabel *labelConstantBlurType;
    QSpinBox *spinBoxBlurType;
    QLabel *labelConstantBlurAmount;
    QSlider *sliderBlurRadius;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *layoutImages;
    QLabel *labelOriginalImage;
    QLabel *labelBlurredImage;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(826, 472);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        layoutUIElements = new QHBoxLayout();
        layoutUIElements->setSpacing(6);
        layoutUIElements->setObjectName(QStringLiteral("layoutUIElements"));
        buttonOpenFile = new QPushButton(centralWidget);
        buttonOpenFile->setObjectName(QStringLiteral("buttonOpenFile"));

        layoutUIElements->addWidget(buttonOpenFile);

        labelConstantBlurType = new QLabel(centralWidget);
        labelConstantBlurType->setObjectName(QStringLiteral("labelConstantBlurType"));

        layoutUIElements->addWidget(labelConstantBlurType);

        spinBoxBlurType = new QSpinBox(centralWidget);
        spinBoxBlurType->setObjectName(QStringLiteral("spinBoxBlurType"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBoxBlurType->sizePolicy().hasHeightForWidth());
        spinBoxBlurType->setSizePolicy(sizePolicy);
        spinBoxBlurType->setMinimumSize(QSize(0, 0));
        spinBoxBlurType->setMinimum(1);
        spinBoxBlurType->setMaximum(3);
        spinBoxBlurType->setValue(2);

        layoutUIElements->addWidget(spinBoxBlurType);

        labelConstantBlurAmount = new QLabel(centralWidget);
        labelConstantBlurAmount->setObjectName(QStringLiteral("labelConstantBlurAmount"));

        layoutUIElements->addWidget(labelConstantBlurAmount);

        sliderBlurRadius = new QSlider(centralWidget);
        sliderBlurRadius->setObjectName(QStringLiteral("sliderBlurRadius"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sliderBlurRadius->sizePolicy().hasHeightForWidth());
        sliderBlurRadius->setSizePolicy(sizePolicy1);
        sliderBlurRadius->setMinimumSize(QSize(400, 0));
        sliderBlurRadius->setMinimum(1);
        sliderBlurRadius->setMaximum(15);
        sliderBlurRadius->setPageStep(10);
        sliderBlurRadius->setValue(5);
        sliderBlurRadius->setOrientation(Qt::Horizontal);
        sliderBlurRadius->setInvertedAppearance(false);
        sliderBlurRadius->setInvertedControls(false);
        sliderBlurRadius->setTickPosition(QSlider::TicksAbove);
        sliderBlurRadius->setTickInterval(1);

        layoutUIElements->addWidget(sliderBlurRadius);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutUIElements->addItem(horizontalSpacer);


        verticalLayout->addLayout(layoutUIElements);

        layoutImages = new QHBoxLayout();
        layoutImages->setSpacing(6);
        layoutImages->setObjectName(QStringLiteral("layoutImages"));
        layoutImages->setSizeConstraint(QLayout::SetDefaultConstraint);
        labelOriginalImage = new QLabel(centralWidget);
        labelOriginalImage->setObjectName(QStringLiteral("labelOriginalImage"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelOriginalImage->sizePolicy().hasHeightForWidth());
        labelOriginalImage->setSizePolicy(sizePolicy2);
        labelOriginalImage->setMinimumSize(QSize(400, 400));
        labelOriginalImage->setSizeIncrement(QSize(1, 1));
        labelOriginalImage->setBaseSize(QSize(0, 0));
        labelOriginalImage->setFrameShape(QFrame::WinPanel);
        labelOriginalImage->setFrameShadow(QFrame::Sunken);
        labelOriginalImage->setScaledContents(false);
        labelOriginalImage->setAlignment(Qt::AlignCenter);
        labelOriginalImage->setMargin(0);

        layoutImages->addWidget(labelOriginalImage);

        labelBlurredImage = new QLabel(centralWidget);
        labelBlurredImage->setObjectName(QStringLiteral("labelBlurredImage"));
        sizePolicy2.setHeightForWidth(labelBlurredImage->sizePolicy().hasHeightForWidth());
        labelBlurredImage->setSizePolicy(sizePolicy2);
        labelBlurredImage->setMinimumSize(QSize(400, 400));
        labelBlurredImage->setFrameShape(QFrame::WinPanel);
        labelBlurredImage->setFrameShadow(QFrame::Sunken);
        labelBlurredImage->setAlignment(Qt::AlignCenter);

        layoutImages->addWidget(labelBlurredImage);


        verticalLayout->addLayout(layoutImages);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        buttonOpenFile->setText(QApplication::translate("MainWindow", "Open File", Q_NULLPTR));
        labelConstantBlurType->setText(QApplication::translate("MainWindow", "Blur strength:", Q_NULLPTR));
        labelConstantBlurAmount->setText(QApplication::translate("MainWindow", "Blur radius: ", Q_NULLPTR));
        labelOriginalImage->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        labelBlurredImage->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
