#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->splitter);
    setActionsForButton();
    createSelectionPopMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

///< window initialization
void    MainWindow::setActionsForButton()
{
    //set action for toolbutton
    ui->tBtn_ListInit->setDefaultAction(ui->actListIni);
    ui->tBtn_ListInit->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->tBtn_ListClear->setDefaultAction(ui->actListClear);
    ui->tBtn_ListClear->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->tBtn_ListInsert->setDefaultAction(ui->actListInsert);
    ui->tBtn_ListInsert->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->tBtn_ListDelete->setDefaultAction(ui->actListDelete);
    ui->tBtn_ListDelete->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->tBtn_ListAppend->setDefaultAction(ui->actListAppend);
    ui->tBtn_ListAppend->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->tBtn_SelAll->setDefaultAction(ui->actSelAll);
    ui->tBtn_SelNone->setDefaultAction(ui->actSelNone);
    ui->tBtn_SelInvs->setDefaultAction(ui->actSelInvs);

}
void    MainWindow::createSelectionPopMenu()
{
// 创建下拉菜单
    QMenu* menuSelection = new QMenu(this);
    menuSelection->addAction(ui->actSelAll);
    menuSelection->addAction(ui->actSelNone);
    menuSelection->addAction(ui->actSelInvs);

// 工具栏上的下拉菜单
    QToolButton *aBtn = new QToolButton(this);
    aBtn->setPopupMode(QToolButton::InstantPopup);
    aBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    aBtn->setDefaultAction(ui->actSelPopMenu);
    aBtn->setMenu(menuSelection);
    ui->mainToolBar->addWidget(aBtn);

// listWidget上的下拉菜单
    ui->tBtn_SelectItems->setPopupMode(QToolButton::MenuButtonPopup);
    ui->tBtn_SelectItems->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tBtn_SelectItems->setDefaultAction(ui->actSelPopMenu);
    ui->tBtn_SelectItems->setMenu(menuSelection);


// 工具栏上追加actions
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actQuit);
}

///< actions defines
void MainWindow::on_actListClear_triggered()  //清除项
{
    ui->lwt_listWidget->clear();
}

void MainWindow::on_actListIni_triggered() //项初始化
{
     QListWidgetItem *item = nullptr;
     QIcon icon(":/images/icons/check2.ico");
     bool chk = ui->cb_lwtisWritable->isChecked();

     ui->lwt_listWidget->clear();
     for(int i = 0; i< 10; i++)
     {
         QString str = QString::asprintf("Item %d", i);
         item = new QListWidgetItem();
         item->setText(str);
         item->setIcon(icon);
         item->setCheckState(Qt::Checked);
         if(chk)
         {
             item->setFlags(Qt::ItemIsSelectable|
                            Qt::ItemIsEditable|
                            Qt::ItemIsUserCheckable|
                            Qt::ItemIsEnabled);
         }
         else
         {
             item->setFlags(Qt::ItemIsSelectable|
                            Qt::ItemIsUserCheckable|
                            Qt::ItemIsEnabled);
         }
         ui->lwt_listWidget->addItem(item);
     }
}

void MainWindow::on_actListInsert_triggered()  //插入项
{

    QIcon icon(":/images/icons/check2.ico");
    QString str("new item insert");
    QListWidgetItem *item = new QListWidgetItem(icon, str);
    item->setCheckState(Qt::Checked);
    if(ui->cb_lwtisWritable->isChecked())
    {
        item->setFlags(Qt::ItemIsSelectable|
                       Qt::ItemIsEnabled|
                       Qt::ItemIsEditable|
                       Qt::ItemIsUserCheckable);

    }
    else
    {

        item->setFlags(Qt::ItemIsSelectable|
                        Qt::ItemIsEnabled|
                       Qt::ItemIsUserCheckable);
    }
    ui->lwt_listWidget->insertItem(ui->lwt_listWidget->currentRow(), item);
}

void MainWindow::on_actListAppend_triggered()  //添加项
{
    QIcon icon(":/images/icons/check2.ico");
    QString str("new item appended");
    QListWidgetItem *item = new QListWidgetItem(icon, str);
    item->setCheckState(Qt::Checked);
    if(ui->cb_lwtisWritable->isChecked())
    {
        item->setFlags(Qt::ItemIsSelectable|
                       Qt::ItemIsEnabled|
                       Qt::ItemIsEditable|
                       Qt::ItemIsUserCheckable);

    }
    else
    {

        item->setFlags(Qt::ItemIsSelectable|
                        Qt::ItemIsEnabled|
                       Qt::ItemIsUserCheckable);
    }
    ui->lwt_listWidget->addItem(item);//增加一个项
}

void MainWindow::on_actListDelete_triggered()  //删除当前项
{
    int curRow = ui->lwt_listWidget->currentRow();
    QListWidgetItem* item = ui->lwt_listWidget->takeItem(curRow); //<移除指定行，但是没有delete
    delete item;

}

///< selection
void MainWindow::on_actSelAll_triggered() //全选
{
    int count = ui->lwt_listWidget->count();
    for(int i =0; i< count; i++)
    {
        auto item = ui->lwt_listWidget->item(i);
        item->setCheckState(Qt::Checked);
    }
}

void MainWindow::on_actSelNone_triggered()//全不选
{
    int count = ui->lwt_listWidget->count();
    for(int i =0; i< count; i++)
    {
        auto item = ui->lwt_listWidget->item(i);
        item->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::on_actSelInvs_triggered()//反选
{
    int count = ui->lwt_listWidget->count();
    for(int i =0; i< count; i++)
    {
        auto item = ui->lwt_listWidget->item(i);
        if(item->checkState() == Qt::Unchecked)
            item->setCheckState(Qt::Checked);
        else
            item->setCheckState(Qt::Unchecked);
    }
}

///< toolBOx and tabWidget interpretive
void MainWindow::on_toolBox_currentChanged(int index)
{
    ui->tabWidget->setCurrentIndex(index);
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->toolBox->setCurrentIndex(index);
}


void MainWindow::on_tabWidget_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
    QMenu* menuList = new QMenu(this);

    menuList->addAction(ui->actListIni);
    menuList->addAction(ui->actListClear);
    menuList->addAction(ui->actListInsert);
    menuList->addAction(ui->actListDelete);
    menuList->addAction(ui->actListAppend);

    menuList->addSeparator();
    menuList->addAction(ui->actSelAll);
    menuList->addAction(ui->actSelNone);
    menuList->addAction(ui->actSelInvs);
}


void MainWindow::on_cb_lwtisWritable_clicked(bool checked)
{
    QListWidgetItem* item;
    int count = ui->lwt_listWidget->count();
    for (int i=0; i< count; i++)
    {
        item = ui->lwt_listWidget->item(i);
        if(checked)
        {
            item->setFlags(Qt::ItemIsSelectable|
                           Qt::ItemIsEditable|
                           Qt::ItemIsUserCheckable|
                           Qt::ItemIsEnabled);
        }
        else
        {
            item->setFlags(Qt::ItemIsSelectable|
                           Qt::ItemIsUserCheckable|
                           Qt::ItemIsEnabled);
        }
    }
}


void MainWindow::on_lwt_listWidget_currentItemChanged(QListWidgetItem *current,
                                                      QListWidgetItem *previous)
{
    QString str;
    if(current!=nullptr)
    {
        if(previous == nullptr)
        {
            str = "当前：" + current->text();
        }
        else
        {
            str = "前一项： " + previous->text() + "; 当前项目： " + current->text();
        }
        ui->le_curItemChanged->clear();
        ui->le_curItemChanged->setText(str);
    }
}


void MainWindow::on_actSelPopMenu_triggered()
{


}

