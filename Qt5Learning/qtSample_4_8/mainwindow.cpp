#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTreeWidget();
    statusLabel = new QLabel("dd");
    ui->statusbar->addWidget(statusLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dockWidget_topLevelChanged(bool topLevel)
{
    ui->actDockFloat->setChecked(topLevel);
}

void MainWindow::on_dockWidget_visibilityChanged(bool visible)
{
    ui->actDockVisible->setChecked(visible);
    ui->actDockFloat->setEnabled(visible);
}

void MainWindow::on_actDockFloat_toggled(bool arg1)
{
    ui->dockWidget->setFloating(arg1);
}

void MainWindow::on_actDockVisible_toggled(bool arg1)
{
    ui->dockWidget->setVisible(arg1);
    ui->actDockFloat->setEnabled(arg1);
}

void MainWindow::initTreeWidget()
{
    // 清空
    ui->treeWidget->clear();


    // 新建item
    QTreeWidgetItem* rootItem = new QTreeWidgetItem(itTopItem);

    // 设置icon
    QIcon icon(":/images/icons/15.ico");
    rootItem->setIcon(colItem, icon);

    // 设置文本
    rootItem->setText(colItem, "Tree Root");
    rootItem->setText(colItemType,"type: itTopItem");

    // 设置item flags
    rootItem->setFlags(Qt::ItemIsEnabled|
                       Qt::ItemIsSelectable|
                       Qt::ItemIsUserCheckable|
                       Qt::ItemIsAutoTristate);

    // 设置data
    QString data("root");
    rootItem->setData(colItem, Qt::UserRole,data);

    // 添加到toplevel
    ui->treeWidget->addTopLevelItem(rootItem);
    rootItem->setCheckState(colItem, Qt::Checked);
    rootItem->setSelected(true);
}


void MainWindow::on_actAddFolder_triggered()
{
    ///< 选择目录
    QString dirPathName = QFileDialog::getExistingDirectory();

    ///< 合法性检查
    if(dirPathName.isEmpty() || !ui->treeWidget->currentIndex().isValid())
    {
        return;
    }


    QTreeWidgetItem* parentItem = nullptr;
    QTreeWidgetItem* curItem = ui->treeWidget->currentItem();
    if(curItem->type() == itImageItem)
    {
        parentItem = curItem->parent();
    }
    else
    {
        parentItem = curItem;
    }

    if(!parentItem) return;

    ///< 目录提取
    int len = dirPathName.length();
    int lastSlash = dirPathName.lastIndexOf("/");
    QString dirName = dirPathName.right(len-lastSlash-1);

    ///< 构建新的item
    QTreeWidgetItem *item = new QTreeWidgetItem(itGroupItem);

    ///< setIcon
    QIcon icon(":/images/icons/open3.bmp");
    item->setIcon(colItem, icon);

    ///< set Text
    item->setText(colItem, dirName);
    item->setText(colItemType, "type: itGroupItem");

    ///< setFlags
    item->setFlags(Qt::ItemIsEnabled|
                   Qt::ItemIsSelectable|
                   Qt::ItemIsUserCheckable|
                   Qt::ItemIsAutoTristate);
    item->setCheckState(colItem,Qt::Checked);

    ///< set user data
    item->setData(colItem, Qt::UserRole, QVariant(dirPathName));

    ///< add item to parent as child
    parentItem->addChild(item);
}



void MainWindow::on_actAddFiles_triggered()
{
    ///< 选择目录
    QStringList filePathNameList = QFileDialog::getOpenFileNames(this,
                                                        "选择一个或多个图片",
                                                        "",
                                                        "jpg(*.jpg);;png(*.png);;bmp(*bmp);;所有文件(*.*)");

    ///< 合法性检查
    if(filePathNameList.isEmpty() || !ui->treeWidget->currentIndex().isValid())
    {
        return;
    }

    QTreeWidgetItem *parentItem=nullptr;
    QTreeWidgetItem *curItem = ui->treeWidget->currentItem();
    if(!curItem) return;

    if(curItem->type() == itImageItem)
    {
        parentItem = curItem->parent();
    }
    else
    {
        parentItem = curItem;
    }

    if(!parentItem) return;

    ///< 遍历处理所有list
    foreach(auto& fileStr, filePathNameList)
    {
        ///< 目录提取
        int len = fileStr.length();
        int lastSlash = fileStr.lastIndexOf("/");
        QString imgFileName = fileStr.right(len-lastSlash-1);

        ///< 构建新的item
        QTreeWidgetItem *item = new QTreeWidgetItem(itImageItem);

        ///< setIcon
        QIcon icon(":/images/icons/31.ico");
        item->setIcon(colItem, icon);

        item->setText(colItem, imgFileName);
        item->setText(colItemType, "type: itImageItem");
        item->setData(colItem, Qt::UserRole ,QVariant(fileStr));

        ///< setFlags
        item->setFlags(Qt::ItemIsEnabled|
                       Qt::ItemIsSelectable|
                       Qt::ItemIsUserCheckable|
                       Qt::ItemIsAutoTristate);
        item->setCheckState(colItem,Qt::Checked);


        ///< add item to parent as child
        parentItem->addChild(item);
    }

}



void MainWindow::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
  Q_UNUSED(previous);
  if(current == nullptr) return;
  int var = current->type();
  statusLabel->setText(current->data(colItem, Qt::UserRole).toString());
  switch (var) {
  case itTopItem:
  {
      ui->actAddFolder->setEnabled(true);
      ui->actAddFiles->setEnabled(true);
      ui->actDeleteItem->setEnabled(false);
      setImgViewActionEnable(false);
      break;
  }
  case itGroupItem:
  {
      ui->actAddFolder->setEnabled(true);
      ui->actAddFiles->setEnabled(true);
      ui->actDeleteItem->setEnabled(true);
      setImgViewActionEnable(false);
      break;
  }
  case itImageItem:
  {

      ///< set actions
      ui->actAddFiles->setEnabled(true);
      ui->actAddFolder->setEnabled(false);
      ui->actDeleteItem->setEnabled(true);

      ///< load imag to pixmap
      QString img = current->data(colItem, Qt::UserRole).toString();
      if(img.isEmpty()) return;
      curPixMap.load(img);

      ///< fitTowindow
      on_actZoomFitH_triggered();

      setImgViewActionEnable(true);
      break;
  }
  }
  return ;
}

void MainWindow::on_actZoomFitH_triggered()
{
    setImgViewActionEnable(true);

    int H = ui->scrollArea->height();
    int realH = curPixMap.height();
    pixRatio = (float)H/realH;
    QPixmap pix = curPixMap.scaledToHeight(H-30);
    ui->lb_imgShow->setPixmap(pix);
}



void MainWindow::on_actZoomFitW_triggered()
{
    int W = ui->scrollArea->width();
    int realW = curPixMap.width();
    pixRatio = (float)W/realW;
    QPixmap pix = curPixMap.scaledToWidth(W-30);
    ui->lb_imgShow->setPixmap(pix);
}

void MainWindow::on_actZoomRealSize_triggered()
{
     pixRatio = 1;
     ui->lb_imgShow->setPixmap(curPixMap);
}

void MainWindow::on_actZoomOut_triggered()
{
    pixRatio /= 1.2;
    int w = pixRatio*curPixMap.width();
    int h = pixRatio*curPixMap.height();
    QPixmap pix = curPixMap.scaled(w,h);
    ui->lb_imgShow->setPixmap(pix);
}

void MainWindow::on_actZoomIn_triggered()
{
    pixRatio *= 1.2;
    int w = pixRatio*curPixMap.width();
    int h = pixRatio*curPixMap.height();
    QPixmap pix = curPixMap.scaled(w,h);
    ui->lb_imgShow->setPixmap(pix);
}

void MainWindow::on_actDeleteItem_triggered()
{
    QTreeWidgetItem* curItem = ui->treeWidget->currentItem();
    if(curItem == nullptr) return;
    curItem->parent()->removeChild(curItem);
    delete curItem;

}


void MainWindow::handleNodeTreeItem(QTreeWidgetItem *item)
{
    if(item == nullptr) return;
    QString str = "*"+item->text(colItem);
    item->setText(colItem, str);
}

void MainWindow::traverTrees(QTreeWidgetItem *item)
{
    if(item == nullptr) return;
    handleNodeTreeItem(item);
    for(int i=0; i< item->childCount();i++)
    {
        traverTrees(item->child(i));
    }
}


void MainWindow::on_actScanItems_triggered()
{
    for(int i=0; i< ui->treeWidget->topLevelItemCount(); i++)
    {
        QTreeWidgetItem* item = ui->treeWidget->topLevelItem(i);
        traverTrees(item);
    }
}


void MainWindow::on_actClearTreeList_triggered()
{
    initTreeWidget();
}
