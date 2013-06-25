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
    void setIsShowPixelValue(bool val);
    bool getIsShowPixelValue();

protected slots:
    void wheelEvent(QWheelEvent *event);
    //void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
private:
    bool isShowPixelValue;
};

#endif