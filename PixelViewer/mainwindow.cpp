#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);
    scene = new ImageScene(0, 0, 800, 600);
    ui.imageView->setScene(scene);
}

MainWindow::~MainWindow() {

}
