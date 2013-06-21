#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ImageScene.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void imageReferenceButtonClicked();

private:
    Ui::MainWindowClass ui;
    ImageScene* scene;

    void openImage(QString filename);
};

#endif // MAINWINDOW_H
