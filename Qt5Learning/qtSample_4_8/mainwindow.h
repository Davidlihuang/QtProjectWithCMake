#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTreeWidgetItem>
#include <QLabel>
#include <QPixmap>
#include "./ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    enum treeItemType{itTopItem=1001, itGroupItem, itImageItem};
    enum treeColNum{colItem=0, colItemType};

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_dockWidget_topLevelChanged(bool topLevel);

    void on_dockWidget_visibilityChanged(bool visible);

    void on_actDockFloat_toggled(bool arg1);

    void on_actDockVisible_toggled(bool arg1);
    void on_actAddFolder_triggered();

    void on_actAddFiles_triggered();

    void on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

    void on_actZoomFitH_triggered();

    void on_actZoomFitW_triggered();

    void on_actZoomRealSize_triggered();

    void on_actZoomOut_triggered();

    void on_actZoomIn_triggered();

    void on_actScanItems_triggered();

    void on_actDeleteItem_triggered();



    void on_actClearTreeList_triggered();

public:
    void initTreeWidget();
    void setImgViewActionEnable(bool on)
    {
        ui->actZoomIn->setEnabled(on);
        ui->actZoomOut->setEnabled(on);
        ui->actZoomFitH->setEnabled(on);
        ui->actZoomFitW->setEnabled(on);
        ui->actZoomRealSize->setEnabled(on);
    }
    void traverTrees(QTreeWidgetItem* item);
    void handleNodeTreeItem(QTreeWidgetItem* item);
private:
    Ui::MainWindow *ui;
    QLabel *statusLabel;
    QPixmap curPixMap;
    float   pixRatio;//当前图片缩放比例
};

#endif // MAINWINDOW_H
