#include "ImageScene.h"

ImageScene::ImageScene() : QGraphicsScene() {
    image = 0;
}

ImageScene::ImageScene(qreal x, qreal y, qreal width, qreal height, QObject *parent) 
    : QGraphicsScene(x, y, width, height, parent) {
        image = 0;
}


void ImageScene::setImage(QImage* _image) {
    image = new QImage(*_image);
    
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(*image));
    clear();        
    this->addItem(item);
    setSceneRect(itemsBoundingRect());
    update();
    
}

void ImageScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if(image != 0) {
        QPointF position = event->scenePos();
        QRgb rgb = image->pixel(position.x(), position.y());        

        onMouseMoveEvent(position, rgb);
    }

}