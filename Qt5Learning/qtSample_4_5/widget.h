#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QDateTime>

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
    void on_btnCurDateTime_clicked();

    void on_btnSetTime_clicked();

    void on_btnSetDate_clicked();

    void on_btnSetDateTime_clicked();

    void on_calendarWidget_selectionChanged();

    void on_timer_timeout();
    void on_btnClockStart_clicked();

    void on_btnClockEnd_clicked();

    void on_btnSetPeriod_clicked();

private:
    Ui::Widget *ui;
    QTimer *fTimer;
    QTime fTimeCounter;
};
#endif // WIDGET_H
