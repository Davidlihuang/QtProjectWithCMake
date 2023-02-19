#include "widget.h"
#include "ui_widget.h"
#include <QBrush>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    padSpreadBtn = new QPushButton(this);
    padSpreadBtn->setText("pad Spread gradient");
    padSpreadBtn->setToolTip("QGradient::PadSpred");
    padSpreadBtn->setObjectName(QString::fromUtf8("padSpreadBtn"));
    padSpreadBtn->setGeometry(QRect(0, 0, 100, 30));
    QObject::connect(padSpreadBtn, SIGNAL(clicked()), this, SLOT(padslots()));

    repeatSpreadBtn = new QPushButton(this);
    repeatSpreadBtn->setText("repeat Spread gradient");
    repeatSpreadBtn->setToolTip("QGradient::RepeatSpred");
    repeatSpreadBtn->setObjectName(QString::fromUtf8("repeatSpreadBtn"));
    repeatSpreadBtn->setGeometry(QRect(0, 40, 100, 30));
    QObject::connect(repeatSpreadBtn, SIGNAL(clicked()), this, SLOT(repeatslots()));

    reflectSpreadBtn = new QPushButton(this);
    reflectSpreadBtn->setText("reflect Spread gradient");
    reflectSpreadBtn->setToolTip("QGradient::ReflectSpred");
    reflectSpreadBtn->setObjectName(QString::fromUtf8("padSpreadBtn"));
    reflectSpreadBtn->setGeometry(QRect(0, 80, 100, 30));
    QObject::connect(reflectSpreadBtn, SIGNAL(clicked()), this, SLOT(reflecslots()));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    drawGradient();
}
void  Widget::padslots()
{
     padflg = !padflg;
     update();
}

void  Widget::repeatslots()
{
    repeatflg = !repeatflg;
    update();
}

void  Widget::reflecslots()
{
    reflectflg = !reflectflg;
    update();
}

void  Widget::Widget::drawGradient()
{
    painter.begin(this);
    if(padflg)
    {
        //线性渐变
        QPoint start(150,0);
        QPoint end(250, 100);
        QLinearGradient ling(start, end); ///< 定义一个线性渐变对象
        ling.setColorAt(0, Qt::blue); ///< 设置起点的颜色
        ling.setColorAt(1, Qt::red); ///< 设置终点颜色

        ///< 设置起点和终点区域以外部分的显示模式
        ling.setSpread(QGradient::PadSpread); ///<
        QBrush brush(ling);
        painter.setBrush(Qt::NoBrush);
        painter.setBrush(brush);
        painter.drawRect(150, 0, 100, 100);

    }
    if(repeatflg)
    {
        QLinearGradient ling1(QPoint(350,0),QPoint(450, 100));
        ling1.setColorAt(0, Qt::blue); ///< 设置起点的颜色
        ling1.setColorAt(1, Qt::red); ///< 设置终点颜色
        ling1.setSpread(QGradient::RepeatSpread);
        painter.setBrush(Qt::NoBrush);
        QBrush brush1(ling1);
        painter.setBrush(brush1);
        painter.drawRect(350, 0, 100, 100);
    }
    if(reflectflg)
    {
        QLinearGradient ling2(QPoint(550,00),QPoint(650, 100));
        ling2.setColorAt(0, Qt::blue); ///< 设置起点的颜色
        ling2.setColorAt(1, Qt::red); ///< 设置终点颜色
        ling2.setSpread(QGradient::ReflectSpread);
        QBrush brush2(ling2);
        painter.setBrush(Qt::NoBrush);
        painter.setBrush(brush2);
        painter.drawRect(550, 0, 100, 100);
    }





    //辐射渐变

    //角度渐变

    painter.end();
}

