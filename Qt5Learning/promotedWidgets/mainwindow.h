#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

protected:
    void resizeEvent(QResizeEvent* event);

private slots:
    void on_mouseMovePoint(QPoint point);
    void on_mouseClicked(QPoint point);

private:
    QGraphicsScene *scene;
    QLabel *labViewCord;
    QLabel *labSceneCord;
    QLabel *labItemCord;

private:
    void initGraphicsSystem();//< 创建Graphics view各项
};
#endif // MAINWINDOW_H
