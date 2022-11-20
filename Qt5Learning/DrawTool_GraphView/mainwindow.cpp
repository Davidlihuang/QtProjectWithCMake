#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setup statusbar
    labViewCord = new QLabel("View 坐标:");
    labViewCord->setMinimumWidth(150);

    labSceneCord = new QLabel("Scene 坐标: ");
    labSceneCord->setMinimumWidth(150);

    labItemCord = new QLabel("Item 坐标: ");
    labItemCord->setMinimumWidth(150);

    labItemInfo = new QLabel("ItemInfo: ");
    labItemInfo->setMinimumWidth(200);

    ui->statusbar->addWidget(labViewCord);
    ui->statusbar->addWidget(labSceneCord);
    ui->statusbar->addWidget(labItemCord);
    ui->statusbar->addWidget(labItemInfo);

    //setup scene and view mode
    scene = new QGraphicsScene(-300, -200, 600, 200);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setCursor(Qt::CrossCursor);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    this->setCentralWidget(ui->graphicsView);


    qsrand(QTime::currentTime().second());
    //connect signals
    QObject::connect(ui->graphicsView, SIGNAL(mouseMovePoint(QPoint)), this, SLOT(on_mouseMovePoint(QPoint)));
    QObject::connect(ui->graphicsView, SIGNAL(mouseClicked(QPoint)), this, SLOT(on_mouseClicked(QPoint)));
    QObject::connect(ui->graphicsView, SIGNAL(mouseDoubleClick(QPoint)), this, SLOT(on_mouseDoubleClick(QPoint)));
    QObject::connect(ui->graphicsView, SIGNAL(keyPress(QKeyEvent*)), this, SLOT(on_keyPress(QKeyEvent*)));


    QObject::connect(ui->actionRectangle, SIGNAL(triggered()), this, SLOT(on_createRect()));
    QObject::connect(ui->actionEllipse, SIGNAL(triggered()), this, SLOT(on_createEllipse()));
    QObject::connect(ui->actionCircle, SIGNAL(triggered()), this, SLOT(on_createCircle()));
    QObject::connect(ui->actionTriangle, SIGNAL(triggered()), this, SLOT(on_createTriangle()));
    QObject::connect(ui->actionTrapezium, SIGNAL(triggered()), this, SLOT(on_createTrapezium()));
    QObject::connect(ui->actionLine, SIGNAL(triggered()), this, SLOT(on_createLine()));
    QObject::connect(ui->actionText, SIGNAL(triggered()), this, SLOT(on_createText()));

    QObject::connect(ui->actionZoomIn, SIGNAL(triggered()), this, SLOT(on_operateZoomIn()));
    QObject::connect(ui->actionZoomOut, SIGNAL(triggered()), this, SLOT(on_operateZoomOut()));
    QObject::connect(ui->actionRotateLeft, SIGNAL(triggered()), this, SLOT(on_operateRotateLeft()));
    QObject::connect(ui->actionRotateRight, SIGNAL(triggered()), this, SLOT(on_operateRotateRight()));
    QObject::connect(ui->actionRestore, SIGNAL(triggered()), this, SLOT(on_operateRestore()));
    QObject::connect(ui->actionFrontPlace, SIGNAL(triggered()), this, SLOT(on_operateFrontPlacement()));
    QObject::connect(ui->actionBackPlace, SIGNAL(triggered()), this, SLOT(on_operateBackPlacement()));
    QObject::connect(ui->actionCombine, SIGNAL(triggered()), this, SLOT(on_operateCombination()));
    QObject::connect(ui->actionScattered, SIGNAL(triggered()), this, SLOT(on_operateScatterd()));
    QObject::connect(ui->actionDelete, SIGNAL(triggered()), this, SLOT(on_operateDelete()));
    QObject::connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(on_operateExit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//event process
void MainWindow::on_mouseMovePoint(QPoint point)
{

    QString str = QString::asprintf("View 坐标: (%d, %d)", point.x(), point.y());
    labViewCord->setText(str);

    QPointF scenePointF = ui->graphicsView->mapToScene(point);
    str = QString::asprintf("Scene 坐标:(%.0f, %.0f)", scenePointF.x(), scenePointF.y());
    labSceneCord->setText(str);
}
void MainWindow::on_mouseClicked(QPoint point){
    QPointF itPoint = ui->graphicsView->mapToScene(point);
    QGraphicsItem* item = nullptr;
    item = scene->itemAt(itPoint, ui->graphicsView->transform());
    if(item != nullptr)
    {
        QPointF itemCord = item->mapFromScene(itPoint);
        QString str = QString::asprintf("Item 坐标：(%.0f, %.0f)",itemCord.x(), itemCord.y());
        labItemCord->setText(str);

        //<ItemInfo upate
        labItemInfo->setText(item->data(ItemDesciption).toString()+", ItemId="+
                           item->data(ItemId).toString());
    }
}
void MainWindow::on_mouseDoubleClick(QPoint point){

}
void MainWindow::on_keyPress(QKeyEvent* event){

}

//action process
void MainWindow::on_createRect(){
    QGraphicsRectItem* item = new QGraphicsRectItem(-50, -25, 100, 50);
    item->setFlags(QGraphicsItem::ItemIsSelectable|
                   QGraphicsItem::ItemIsFocusable|
                   QGraphicsItem::ItemIsMovable)    ;
    item->setBrush(QBrush(Qt::yellow));
    item->setPos(-50+(qrand()%100), -50+(qrand()%100));
    item->setZValue(++frontZ);

    item->setData(ItemId, ++seqNum);
    item->setData(ItemDesciption, "矩形");

    scene->addItem(item);
    scene->clearSelection();

    item->setSelected(true);
}
void MainWindow::on_createEllipse(){
    QGraphicsEllipseItem* item = new QGraphicsEllipseItem(-50, -30, 100, 60);
    item->setFlags(QGraphicsItem::ItemIsSelectable|
                   QGraphicsItem::ItemIsFocusable|
                   QGraphicsItem::ItemIsMovable)    ;
    item->setBrush(QBrush(Qt::blue));
    item->setPos(-50+(qrand()%100), -50+(qrand()%100));
    item->setZValue(++frontZ);

    item->setData(ItemId, ++seqNum);
    item->setData(ItemDesciption, "椭圆");

    scene->addItem(item);
    scene->clearSelection();

    item->setSelected(true);
}
void MainWindow::on_createCircle(){
    QGraphicsEllipseItem* item = new QGraphicsEllipseItem(-50, -50, 50, 50);
    item->setFlags(QGraphicsItem::ItemIsSelectable|
                   QGraphicsItem::ItemIsFocusable|
                   QGraphicsItem::ItemIsMovable)    ;
    item->setBrush(QBrush(Qt::cyan));
    item->setPos(-50+(qrand()%100), -50+(qrand()%100));
    item->setZValue(++frontZ);

    item->setData(ItemId, ++seqNum);
    item->setData(ItemDesciption, "圆形");

    scene->addItem(item);
    scene->clearSelection();

    item->setSelected(true);
}
void MainWindow::on_createTriangle(){

        QGraphicsPolygonItem* item = new QGraphicsPolygonItem;
        QPolygonF polyPoints;
        polyPoints.append(QPointF(0, -40));
        polyPoints.append(QPointF(60, 40));
        polyPoints.append(QPointF(-60, 40));
        item->setPolygon(polyPoints);

        item->setFlags(QGraphicsItem::ItemIsSelectable|
                       QGraphicsItem::ItemIsFocusable|
                       QGraphicsItem::ItemIsMovable)    ;
        item->setBrush(QBrush(Qt::magenta));
        item->setPos(-50+(qrand()%100), -50+(qrand()%100));
        item->setZValue(++frontZ);

        item->setData(ItemId, ++seqNum);
        item->setData(ItemDesciption, "三角形");

        scene->addItem(item);
        scene->clearSelection();

        item->setSelected(true);
}
void MainWindow::on_createTrapezium(){
    QGraphicsPolygonItem* item = new QGraphicsPolygonItem;
    QPolygonF polyPoints;
    polyPoints.append(QPointF(-40, -40));
    polyPoints.append(QPointF(40, -40));
    polyPoints.append(QPointF(100, 40));
    polyPoints.append(QPointF(-100, 40));
    item->setPolygon(polyPoints);

    item->setFlags(QGraphicsItem::ItemIsSelectable|
                   QGraphicsItem::ItemIsFocusable|
                   QGraphicsItem::ItemIsMovable)    ;
    item->setBrush(QBrush(Qt::green));
    item->setPos(-50+(qrand()%100), -50+(qrand()%100));
    item->setZValue(++frontZ);

    item->setData(ItemId, ++seqNum);
    item->setData(ItemDesciption, "梯形");

    scene->addItem(item);
    scene->clearSelection();

    item->setSelected(true);
}
void MainWindow::on_createLine(){
    QGraphicsLineItem* item = new QGraphicsLineItem(-100, 0, 100, 0);
    item->setFlags(QGraphicsItem::ItemIsSelectable|
                   QGraphicsItem::ItemIsFocusable|
                   QGraphicsItem::ItemIsMovable);
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::red);
    item->setPen(pen);

    item->setPos(-50+(qrand()%100), -50+(qrand()%100));
    item->setZValue(++frontZ);

    item->setData(ItemId, ++seqNum);
    item->setData(ItemDesciption, "直线");

    scene->addItem(item);
    scene->clearSelection();

    item->setSelected(true);
}
void MainWindow::on_createText(){
    QString str = QInputDialog::getText(this, "输入文字", "请输入文字");
    if(str.isEmpty())
        return;
    QGraphicsTextItem* item = new QGraphicsTextItem(str);

    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    item->setFont(font);

    item->setFlags(QGraphicsItem::ItemIsSelectable|
                   QGraphicsItem::ItemIsFocusable|
                   QGraphicsItem::ItemIsMovable)    ;

    item->setPos(-50+(qrand()%100), -50+(qrand()%100));
    item->setZValue(++frontZ);

    item->setData(ItemId, ++seqNum);
    item->setData(ItemDesciption, "文字");

    scene->addItem(item);
    scene->clearSelection();

    item->setSelected(true);

}

void MainWindow::on_operateZoomIn(){
    int count = scene->selectedItems().count();
    if(count == 1)
    {
        QGraphicsItem *item=nullptr;
        item = scene->selectedItems().at(0);
        if(item==nullptr)
            return;
        item->setScale(0.1+item->scale());
    }
    else
    {
        ui->graphicsView->scale(1.1, 1.1);
    }
}
void MainWindow::on_operateZoomOut(){
    int count = scene->selectedItems().count();
    if(count == 1)
    {
        QGraphicsItem *item=nullptr;
        item = scene->selectedItems().at(0);
        if(item==nullptr)
            return;
        item->setScale(item->scale()-0.1);
    }
    else
    {
        ui->graphicsView->scale(0.9, 0.9);
    }
}
void MainWindow::on_operateRestore(){
    int count = scene->selectedItems().count();
    if(count == 1)
    {
        QGraphicsItem *item=nullptr;
        item = scene->selectedItems().at(0);
        if(item==nullptr)
            return;
        item->setScale(1.0);
        item->setRotation(0);
    }
    else
    {
        ui->graphicsView->resetTransform();
    }
}
void MainWindow::on_operateRotateLeft(){
    int count = scene->selectedItems().count();
    if(count == 1)
    {
        QGraphicsItem *item=nullptr;
        item = scene->selectedItems().at(0);
        if(item==nullptr)
            return;
        item->setRotation(-30+item->rotation());
    }
    else
    {
        ui->graphicsView->rotate(-30);
    }
}
void MainWindow::on_operateRotateRight(){
    int count = scene->selectedItems().count();
    if(count == 1)
    {
        QGraphicsItem *item = scene->selectedItems().at(0);
        if(item==nullptr)
            return;
        item->setRotation(30+item->rotation());
    }
    else
    {
        ui->graphicsView->rotate(30);
    }
}
void MainWindow::on_operateFrontPlacement(){
    int cnt = scene->selectedItems().count();
    if(cnt>0)
    {
        QGraphicsItem *item = scene->selectedItems().at(0);
        item->setZValue(++frontZ);

    }
}
void MainWindow::on_operateBackPlacement(){
    int cnt = scene->selectedItems().count();
    if(cnt>0)
    {
        QGraphicsItem *item = scene->selectedItems().at(0);
        item->setZValue(--backZ);
    }
}
void MainWindow::on_operateCombination(){
    int cnt = scene->selectedItems().count();
    if(cnt >1)
    {
        QGraphicsItemGroup* group = new QGraphicsItemGroup;
        scene->addItem(group);
        for(int i =0; i< cnt; i++)
        {
            QGraphicsItem *item = scene->selectedItems().at(0);
            item->setSelected(false);
            item->clearFocus();
            group->addToGroup(item);
        }
        group->setFlags(QGraphicsItem::ItemIsFocusable|
                        QGraphicsItem::ItemIsSelectable|
                        QGraphicsItem::ItemIsMovable);
        group->setZValue(++frontZ);
        group->clearFocus();
        group->setSelected(true);

    }
}
void MainWindow::on_operateScatterd(){
    int cnt = scene->selectedItems().count();
    if(cnt == 1)
    {
        QGraphicsItem* item = nullptr;
        item = scene->selectedItems().at(0);
        if(item->type() == QGraphicsItemGroup::Type)
        {
            QGraphicsItemGroup *group = (QGraphicsItemGroup*)item;
            scene->destroyItemGroup(group);
        }
    }
}

void MainWindow::on_operateDelete(){
    int count = scene->selectedItems().count();
    for(int i=0; i< count; i++)
    {
        QGraphicsItem* item = scene->selectedItems().at(0);
        scene->removeItem(item);
    }
}
void MainWindow::on_operateExit(){
    this->close();
}

