#include "ImageScene.h"

ImageScene::ImageScene() : QGraphicsScene(){}

ImageScene::ImageScene(qreal x, qreal y, qreal width, qreal height, QObject *parent) 
    : QGraphicsScene(x, y, width, height, parent) {}