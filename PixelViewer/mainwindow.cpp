#include "mainwindow.h"
#include <QtGui>
#include <qgraphicsitem.h>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <boost\bind.hpp>
#include <qtextcodec.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

        ui.setupUi(this);

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
        QString str = QString::number(qGray(rgb));
		ui.colorLabel->setText(QTextCodec::codecForLocale()->toUnicode( "画素の値: ") + str);
    }
}