#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QLabel>
#include <QString>
#include <qrandom.h>
#include <QInputDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QTime>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    static const int ItemId = 1; //绘图项目定义数据的key
    static const int ItemDesciption = 2; //绘图项目定义数据的key

    int seqNum = 0; //图形编号，每个图形一个
    int backZ  = 0; //用于bring to back
    int frontZ = 0; //用于bring to front

    QGraphicsScene *scene; //保存场景

    QLabel *labViewCord; //鼠标在视图坐标信息
    QLabel *labSceneCord; //鼠标在场景中的坐标信息
    QLabel *labItemCord; //鼠标在item中的局部坐标信息
    QLabel *labItemInfo;//

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //event process
    void on_mouseMovePoint(QPoint point);
    void on_mouseClicked(QPoint point);
    void on_mouseDoubleClick(QPoint point);
    void on_keyPress(QKeyEvent* event);

    //action process
    void on_createRect();
    void on_createEllipse();
    void on_createCircle();
    void on_createTriangle();
    void on_createTrapezium();
    void on_createLine();
    void on_createText();

    void on_operateZoomIn();
    void on_operateZoomOut();
    void on_operateRestore();
    void on_operateRotateLeft();
    void on_operateRotateRight();
    void on_operateFrontPlacement();
    void on_operateBackPlacement();
    void on_operateCombination();
    void on_operateScatterd();

    void on_operateDelete();
    void on_operateExit();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
