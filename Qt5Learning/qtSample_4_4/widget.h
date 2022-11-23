#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

    void on_sld_red_valueChanged(int value);
    void on_dial_manual_valueChanged(int value);

    void on_rbtn_ten_clicked();

    void on_rbtn_oct_clicked();

    void on_rbtn_bin_clicked();

    void on_rbtn_hex_clicked();

    void on_sld_horizon_valueChanged(int value);

    void on_sld_vertical_valueChanged(int value);

    void on_scrbar_horizon_sliderMoved(int position);

    void on_scrbar_vertical_sliderMoved(int position);

private:
    void connectFunctions();
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
