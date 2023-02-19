#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

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
    void    setActionsForButton();
    void    createSelectionPopMenu();
private slots:
    void on_actListClear_triggered();  //清除项

    void on_actListIni_triggered(); //项初始化

    void on_actListInsert_triggered();  //插入项

    void on_actListAppend_triggered();  //添加项

    void on_actListDelete_triggered();  //删除当前项


    void on_actSelAll_triggered(); //全选

    void on_actSelNone_triggered();//全不选

    void on_actSelInvs_triggered();//反选

    ///List Widget

    void on_toolBox_currentChanged(int index);

    void on_tabWidget_currentChanged(int index);



    void on_tabWidget_customContextMenuRequested(const QPoint &pos);

    void on_cb_lwtisWritable_clicked(bool checked);

    void on_lwt_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_actSelPopMenu_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
