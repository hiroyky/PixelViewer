#ifndef __IMAGE_SCENE_H__
#define __IMAGE_SCENE_H__

#include <QtWidgets\qgraphicsview.h>
#include <qgraphicssceneevent.h>
#include <qgraphicsitem.h>
#include <qtooltip.h>
#include <boost/function.hpp>

class ImageScene : public QGraphicsScene {
public:
    ImageScene();
    ImageScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = 0);
    void setImage(QImage *_image);    
    boost::function<void (QPointF, QRgb)> onMouseMoveEvent;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsTextItem *cursor;
    QImage *image;
};


#endif