#include <qgraphicsscene.h>

class ImageScene : public QGraphicsScene {
public:
    ImageScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = 0) 
        : QGraphicsScene(x, y, width, height, parent) {}

protected:
    void paintEvent(QPaintEvent *event);
};