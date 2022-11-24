#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);

    fTimer = new QTimer(this);
    fTimer->stop();
    fTimer->setInterval(1000);
    ui->spbClockPeriod->setRange(0,INT_MAX);
    ui->spbClockPeriod->setValue(1000);
    ui->spbClockPeriod->setSuffix(QString(" ms"));

    QObject::connect(fTimer,
                     SIGNAL(timeout()),
                     this,
                     SLOT(on_timer_timeout()));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnCurDateTime_clicked()
{
    QDateTime curDateTime = QDateTime::currentDateTime();
    QTime time = curDateTime.time();
    QDate date = curDateTime.date();

    ui->timeEdit->setTime(time);
    ui->dateEdit->setDate(date);
    ui->dateTimeEdit->setDateTime(curDateTime);

    ui->ledtTime->setText(time.toString("hh:mm:ss"));
    ui->ledtDate->setText(date.toString("yyyy-MM-dd"));
    ui->ledtDateTime->setText(curDateTime.toString("yyyy-MM-dd hh:mm:ss"));

    ui->ledtSelectDateTime->setText(date.toString("yyyy-MM-dd"));
}

void Widget::on_btnSetTime_clicked()
{
    QString time = ui->ledtTime->text();
    time= time.trimmed();
    if(!time.isEmpty())
    {
        QTime qTime = QTime::fromString(time, "hh:mm:ss");
        ui->timeEdit->setTime(qTime);
    }

}

void Widget::on_btnSetDate_clicked()
{
    QString date = ui->ledtDate->text();
    date = date.trimmed();
    if(!date.isEmpty())
    {
        QDate qDate = QDate::fromString(date, "yyyy-MM-dd");
        ui->dateEdit->setDate(qDate);
    }


}

void Widget::on_btnSetDateTime_clicked()
{
    QString dateTimeStr = ui->ledtDateTime->text();
    dateTimeStr = dateTimeStr.trimmed();
    if(!dateTimeStr.isEmpty())
    {
        QDateTime dateTime = QDateTime::fromString(dateTimeStr,
                                                   "yyyy-MM-dd hh:mm:ss");
        ui->dateTimeEdit->setDateTime(dateTime);
    }

}

void Widget::on_calendarWidget_selectionChanged()
{
    QDate date = ui->calendarWidget->selectedDate();
    ui->ledtSelectDateTime->setText(date.toString("yyyy-MM-dd"));
}

void Widget::on_timer_timeout()
{
    QTime curTime = QTime::currentTime();
    ui->lcdHour->display(curTime.hour());
    ui->lcdMinute->display(curTime.minute());
    ui->lcdSecond->display(curTime.second());
    int va = ui->progressBar->value();
    va ++;
    if(va > 100)
    {
        va = 0;
    }
    ui->progressBar->setValue(va);
}

void Widget::on_btnClockStart_clicked()
{
    ui->btnClockEnd->setEnabled(true);
    ui->btnClockStart->setEnabled(false);
    ui->btnSetPeriod->setEnabled(false);
    fTimer->start();
    fTimeCounter.start();
}

void Widget::on_btnClockEnd_clicked()
{
    ui->btnClockEnd->setEnabled(false);
    ui->btnClockStart->setEnabled(true);
    ui->btnSetPeriod->setEnabled(true);
    fTimer->stop();
    int tmMsec = fTimeCounter.elapsed();
    int ms = tmMsec % 1000;
    int sec = tmMsec /1000;
    QString str(QString::asprintf("流逝时间：%d 秒， %d 毫秒", sec, ms));
    ui->lbTimeFlow->setText(str);

}

void Widget::on_btnSetPeriod_clicked()
{
    int period = ui->spbClockPeriod->value();
    fTimer->setInterval(period);

}
