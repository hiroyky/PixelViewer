#include "ImageView.h"

ImageView::ImageView(QWidget *parent) : QGraphicsView(parent) {
}

void ImageView::scaleReset() {
    scalemount = 0;
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

//void ImageView::paintEvent(QPaintEvent *event)  {
    //this->scale(scalemount, scalemount);
//}

#include "moc_ImageView.cpp"