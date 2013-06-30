#include "mainwindow.h"
#include <QtGui>
#include <qgraphicsitem.h>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <boost\bind.hpp>
#include <qtextcodec.h>
#include "ColorMode.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

        ui.setupUi(this);

        ui.modeSelectComboBox->addItem("Gray", ColorMode::GRAY);
        ui.modeSelectComboBox->addItem("R", ColorMode::RED);
        ui.modeSelectComboBox->addItem("G", ColorMode::GREEN);
        ui.modeSelectComboBox->addItem("B", ColorMode::BLUE);
        ui.modeSelectComboBox->addItem("RGB", ColorMode::RGB);

        scene = new ImageScene();
        scene->onMouseMoveEvent = boost::bind(&MainWindow::onSceneMouseMoveEvent, this, _1, _2);
        ui.imageView->setScene(scene);
        ui.imageView->show();
}

MainWindow::~MainWindow() {    
}

void MainWindow::imageReferenceButtonClicked() {
    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open Image File"),
        QDir::homePath(),
        tr("Image files (*.jpg *.png *gif *bmp *jpeg);;All files (*.*)")
        );

    if(!filename.isNull()) {
        ui.uriLineEdit->setText(filename);
    }

    openImage(filename);
}

void MainWindow::openImage(QString filename) {
    QImage image(filename);
    if(image.isNull()) {
        QMessageBox messageBox(this);
        messageBox.setText("file open is failed.");
        messageBox.exec();
        return;
    }
    scene->setImage(&image);  
}

void MainWindow::onSceneMouseMoveEvent(QPointF position, QRgb rgb) {
    if(ui.colorValuecheckBox->isChecked()) {
        QString str, numstr;
        switch (ui.modeSelectComboBox->currentIndex())
        {
        case ColorMode::GRAY:
            numstr = QString::number(qGray(rgb));
            str = QTextCodec::codecForLocale()->toUnicode( "画素の値: ") + numstr;
            break;
        case ColorMode::RED:
            numstr = QString::number(qRed(rgb));
            str = QTextCodec::codecForLocale()->toUnicode( "画素の値(赤): ") + numstr;
            break;
        case ColorMode::GREEN:
            numstr = QString::number(qGreen(rgb));
            str = QTextCodec::codecForLocale()->toUnicode( "画素の値(緑): ") + numstr;
            break;
        case ColorMode::BLUE:
            numstr = QString::number(qBlue(rgb));
            str = QTextCodec::codecForLocale()->toUnicode( "画素の値(青): ") + numstr;
            break;
        case ColorMode::RGB:
            numstr = QString::number(qRed(rgb)) + ", " + QString::number(qGreen(rgb)) + ", " + QString::number(qBlue(rgb));
            str = QTextCodec::codecForLocale()->toUnicode( "赤, 緑, 青: ") + numstr;
            break;
        default:
            break;
        }

		ui.colorLabel->setText(str);
    }
}