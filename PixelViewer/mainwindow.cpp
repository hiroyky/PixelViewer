#include "mainwindow.h"
#include <QtGui>
#include <qgraphicsitem.h>
#include <qmessagebox.h>
#include <qfiledialog.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
      
    ui.setupUi(this);

    scene = new ImageScene();
    ui.imageView->setScene(scene);
    ui.imageView->show();
}

MainWindow::~MainWindow() {
    delete scene;
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

    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->clear();        
    scene->addItem(item);
    scene->setSceneRect(scene->itemsBoundingRect());
}