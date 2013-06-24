#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <qobject.h>
#include <QtGui>
#include <qgraphicsview.h>

class ImageView : public QGraphicsView {
    Q_OBJECT
public:
    ImageView(QWidget *parent = 0);
    void scaleReset();
protected:
    void wheelEvent(QWheelEvent *event);
    //void paintEvent(QPaintEvent *event);

private:
    qreal scalemount;
};

#endif