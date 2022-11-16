#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QGraphicsEllipseItem>
#include <QPoint>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //set label
    labViewCord  = new QLabel(tr("View 坐标:"));
    labViewCord->setMidLineWidth(150);

    labSceneCord = new QLabel(tr("Scene 坐标:"));
    labSceneCord->setMidLineWidth(150);

    labItemCord  = new QLabel(tr("Item 坐标: "));
    labItemCord->setMidLineWidth(150);

    ui->statusbar->addWidget(labViewCord);
    ui->statusbar->addWidget(labSceneCord);
    ui->statusbar->addWidget(labItemCord);

    ui->graphicsView->setCursor(Qt::CrossCursor);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

    QObject::connect(ui->graphicsView, SIGNAL(mouseMovePoint(QPoint)), this, SLOT(on_mouseMovePoint(QPoint)));
    QObject::connect(ui->graphicsView, SIGNAL(mouseClicked(QPoint)), this, SLOT(on_mouseClicked(QPoint)));

    initGraphicsSystem();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mouseMovePoint(QPoint point)
{
    QString str = QString::asprintf("View 坐标：(%d,%d)",point.x(),point.y());
    labViewCord->setText(str);

    QPointF scenePoint =  ui->graphicsView->mapToScene(point);

    str = QString::asprintf("Scene 坐标: (%0.f, %0.f)", scenePoint.x(), scenePoint.y());
    labSceneCord->setText(str);
}
void MainWindow::on_mouseClicked(QPoint point)
{
    QGraphicsItem* item = nullptr;
    QPointF pointScene = ui->graphicsView->mapToScene(point);
    item = scene->itemAt(pointScene,ui->graphicsView->transform());
    if(item != nullptr)
    {
        QPointF itemCord = item->mapFromScene(pointScene);
        QString str =QString::asprintf("Item 坐标: (%.0f, %.0f)",itemCord.x(), itemCord.y());
        labItemCord->setText(str);
    }
    else
    {
        labItemCord->setText(QString("Item 坐标: "));
    }
}


void MainWindow::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);
    ui->labViewSize->setText(
                QString::asprintf("Graphics View坐标，左上角总是（0,0），宽度=%d，高度=%d",
                                  ui->graphicsView->width(), ui->graphicsView->height())
               );
    QRectF rectF = ui->graphicsView->sceneRect();
    ui->labSceneRect->setText(QString::asprintf("QGraphicsView::sceneRect=(left, top, width, height)= (%.0f,%.0f,%.0f,%.0f)",
                                                rectF.left(), rectF.top(), rectF.width(), rectF.height()));

}

void MainWindow::initGraphicsSystem()
{
    QRectF rect(-200, -100, 400, 200);
    scene = new QGraphicsScene(rect);
    ui->graphicsView->setScene(scene);

    QGraphicsRectItem * rectItem = new QGraphicsRectItem(rect);
    rectItem->setFlags(QGraphicsItem::ItemIsMovable|
                       QGraphicsItem::ItemIsFocusable|
                       QGraphicsItem::ItemIsSelectable);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::green);
    rectItem->setPen(pen);
    scene->addItem(rectItem);

    QRectF ellRect(-100, -50, 200, 100);
    QGraphicsEllipseItem *ellItem = new QGraphicsEllipseItem(ellRect);//矩形框内创建椭圆,绘图项的局部坐标，左上角(-100,-50)，宽200，高100
    ellItem->setPos(0, 0);
    ellItem->setBrush(QBrush(Qt::blue));
    ellItem->setFlags(QGraphicsItem::ItemIsMovable|
                      QGraphicsItem::ItemIsFocusable|
                      QGraphicsItem::ItemIsSelectable);
    scene->addItem(ellItem);

    QRectF cirRect(-50, -50, 100, 100);
    QGraphicsEllipseItem *cirItem = new QGraphicsEllipseItem(cirRect);
    cirItem->setPos(rect.right(), rect.bottom());
    cirItem->setBrush(QBrush(Qt::yellow));
    cirItem->setFlags(QGraphicsItem::ItemIsMovable|
                       QGraphicsItem::ItemIsFocusable|
                       QGraphicsItem::ItemIsSelectable);
    scene->addItem(cirItem);

    scene->clearSelection();


}
