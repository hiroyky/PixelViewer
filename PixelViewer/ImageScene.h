#ifndef __IMAGE_SCENE_H__
#define __IMAGE_SCENE_H__

#include <qgraphicsscene.h>

class ImageScene : public QGraphicsScene {
public:
    ImageScene();
    ImageScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = 0);

protected:
   
};


#endif