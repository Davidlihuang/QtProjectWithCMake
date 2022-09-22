#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter;
    painter.begin(this);

    //set pen
    painter.setPen(Qt::blue);

    //draw line
    QPoint p1(10,10);
    QPoint p2(100, 40);
    painter.drawLine(p1, p2);

    ///< draw rect
    int x{120}, y{10};
    int wight{80}, height{80};
    painter.drawRect(x,y, wight, height);

    ///< draw round rect
    QRectF rect(230.0, 10.0, 80.0, 80.0);
    painter.drawRoundRect(rect, 20, 20);

    ///< draw line
    QPointF points[3] = {
        QPointF(10.0, 110.0),
        QPointF(110.0, 110.0),
        QPointF(110.0, 190.0)};
    painter.drawPolyline(points, 3);

    ///<draw polygon
    QPointF polyPoints[3] = {
        QPointF(120.0, 110.0),
        QPointF(220.0, 110.0 ),
        QPointF(220.0, 190.0)
    };
    painter.drawPolygon(polyPoints, 3);

    ///< set text properties
    painter.setFont(QFont("Arial", 20));
    painter.setPen(Qt::red);

    QRect font_rect(10, 150, 220, 180);//show text area
    QString text = "I love you!";
    painter.drawText(font_rect, Qt::AlignHCenter, text);

    ///< Qpen
    QColor color(Qt::black);
    int linewight{3};
    QPen pen(color, linewight, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    QRect rect1(10.0, 200.0, 80.0, 50);
    painter.drawEllipse(rect1);

    pen.setStyle(Qt::DashDotLine);
    painter.setPen(pen);
    QRect rect2(110.0, 200.0, 80.0, 50);
    painter.drawEllipse(rect2);

    pen.setCapStyle(Qt::FlatCap);
    painter.setPen(pen);
    QRect rect3(220.0, 200.0, 80.0, 50);
    painter.drawEllipse(rect3);

    pen.setCapStyle(Qt::SquareCap);
    painter.setPen(pen);
    QRect rect4(440.0, 200.0, 80.0, 50);
    painter.drawEllipse(rect4);

    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    QRect rect5(550.0, 200.0, 80.0, 50);
    painter.drawEllipse(rect5);

    QRect rt(0, 400,10, 10);
    for(int i=1; i<6;i++)
    {
        int dx{100};
        pen.setStyle(Qt::PenStyle(i));
        painter.setPen(pen);
        rt.setBottomLeft(QPoint(100*(i-1), y));
        rt.setWidth(80);
        rt.setHeight(80);
        painter.drawRect(rt);
    }
    painter.end();
}
