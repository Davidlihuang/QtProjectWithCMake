#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenu>
#include <QTextDocument>
#include <QTextBlock>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_btn_initCboBox_clicked();

    void on_btn_clearCboBox_clicked();

    void on_cb_isEditable_clicked(bool checked);

    void on_cbb_generaCboBox_currentIndexChanged(const QString &arg1);

    void on_btn_initCityNumber_clicked();

    void on_cbb_userDataCboBox_currentIndexChanged(const QString &arg1);

    void on_btn_addContextToCboBox_clicked();

    void on_btn_clearContext_clicked();

    void on_cb_isReadOnly_clicked(bool checked);

    void on_pte_plainTextEdit_customContextMenuRequested(const QPoint &pos);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
