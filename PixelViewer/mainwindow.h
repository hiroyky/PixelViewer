#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "ImageScene.h"
#include <qpoint.h>
#include <qrgb.h>
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void imageReferenceButtonClicked();

private:
    Ui::MainWindowClass ui;
    ImageScene *scene;

    void onSceneMouseMoveEvent(QPointF position, QRgb rgb);
    void openImage(QString filename);
};

#endif // MAINWINDOW_H
