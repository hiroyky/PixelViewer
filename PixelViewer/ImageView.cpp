#include "ImageView.h"
#include <qgraphicsitem.h>
#include <qlist.h>
#include <qtooltip.h>

ImageView::ImageView(QWidget *parent) : QGraphicsView(parent) {
    isShowPixelValue = false;    
}

void ImageView::setIsShowPixelValue(bool val) {
    isShowPixelValue = val;
}

bool ImageView::getIsShowPixelValue() {
    return isShowPixelValue;
}

void ImageView::scaleReset() {
    scale(0, 0);
}

void ImageView::wheelEvent(QWheelEvent  *event) {
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    // Scale the view / do the zoom
    double scaleFactor = 1.15;
    if(event->delta() > 0) {
        // Zoom in
        scale(scaleFactor, scaleFactor);
    } else {
        // Zooming out
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }
    // http://www.qtcentre.org/wiki/index.php?title=QGraphicsView:_Smooth_Panning_and_Zooming
}
#if 0
void ImageView::mouseMoveEvent(QMouseEvent *event) {
    QPointF position = event->screenPos();
}
#endif

void ImageView::paintEvent(QPaintEvent *event) {
    QGraphicsView::paintEvent(event);
}

#include "moc_ImageView.cpp"