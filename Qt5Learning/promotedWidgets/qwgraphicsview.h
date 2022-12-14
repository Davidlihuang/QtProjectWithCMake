#ifndef QWGRAPHICSVIEW_H
#define QWGRAPHICSVIEW_H
#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QObject>
#include <QGraphicsView>

class QWGraphicsView:public QGraphicsView
{
    Q_OBJECT
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
public:
    QWGraphicsView(QWidget *parent=0);
signals:
    void mouseMovePoint(QPoint point);
    void mouseClicked(QPoint point);
};

#endif // QWGRAPHICSVIEW_H
