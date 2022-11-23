#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->sld_red->setMaximum(255);
    ui->sld_green->setMaximum(255);
    ui->sld_blue->setMaximum(255);
    ui->sld_alpha->setValue(255);
    ui->sld_alpha->setMaximum(255);
    on_sld_red_valueChanged(0);

    ui->sld_vertical->setRange(0, 100);
    ui->sld_horizon->setRange(0, 100);

    ui->scrbar_vertical->setRange(0,100);
    ui->pgbar_vertical->setRange(0,100);
    ui->scrbar_vertical->setInvertedAppearance(true);

    ui->scrbar_horizon->setRange(0,100);
    ui->pgbar_horizon->setRange(0, 100);

    connectFunctions();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::connectFunctions()
{
    QObject::connect(ui->sld_blue,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(on_sld_red_valueChanged(int)));
    QObject::connect(ui->sld_green,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(on_sld_red_valueChanged(int)));
    QObject::connect(ui->sld_alpha,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(on_sld_red_valueChanged(int)));
}

void Widget::on_sld_red_valueChanged(int value)
{
    Q_UNUSED(value);
    QColor color;
    int R = ui->sld_red->value();
    int G = ui->sld_green->value();
    int B = ui->sld_blue->value();
    int alpha = ui->sld_alpha->value();
    color.setRgb(R, G, B, alpha);
    QPalette pal = ui->textEdit->palette();
    pal.setColor(QPalette::Base,color);
    ui->textEdit->setPalette(pal);
}

void Widget::on_dial_manual_valueChanged(int value)
{
    ui->lcdNumber->display(value);
}


void Widget::on_rbtn_ten_clicked()
{
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setDecMode();
}

void Widget::on_rbtn_oct_clicked()
{
    ui->lcdNumber->setDigitCount(4);
    ui->lcdNumber->setOctMode();
}

void Widget::on_rbtn_bin_clicked()
{
    ui->lcdNumber->setDigitCount(8);
    ui->lcdNumber->setBinMode();
}

void Widget::on_rbtn_hex_clicked()
{
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setHexMode();
}

void Widget::on_sld_horizon_valueChanged(int value)
{
    ui->pgbar_horizon->setValue(value);
    ui->scrbar_horizon->setValue(value);
}

void Widget::on_sld_vertical_valueChanged(int value)
{
    ui->pgbar_vertical->setValue(value);
    ui->scrbar_vertical->setValue(value);

}

void Widget::on_scrbar_horizon_sliderMoved(int position)
{
    ui->pgbar_horizon->setValue(position);;
}

void Widget::on_scrbar_vertical_sliderMoved(int position)
{
    ui->pgbar_vertical->setValue(position);
}
