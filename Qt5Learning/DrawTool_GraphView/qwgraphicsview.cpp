#include "qwgraphicsview.h"
#include  <QMouseEvent>
#include  <QPoint>


QWGraphicsView::QWGraphicsView(QWidget *parent):QGraphicsView(parent)
{

}

void QWGraphicsView::mouseMoveEvent(QMouseEvent *event)
{//鼠标移动事件
    QPoint point = event->pos();
    emit mouseMovePoint(point);
    QGraphicsView::mouseMoveEvent(event);
}

void QWGraphicsView::mousePressEvent(QMouseEvent *event)
{ //鼠标左键按下事件
   if(event->button() == Qt::LeftButton)
   {
       QPoint point = event->pos();
       emit mouseClicked(point);
   }
   QGraphicsView::mousePressEvent(event);
}

void QWGraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{ //鼠标双击事件
    if(event->button() == Qt::LeftButton)
    {
        QPoint point = event->pos();
        emit mouseDoubleClick(point);
    }
    QGraphicsView::mouseDoubleClickEvent(event);
}

void QWGraphicsView::keyPressEvent(QKeyEvent *event)
{ //按键事件
    emit keyPress(event);
    QGraphicsView::keyPressEvent(event);
}

