#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    btn = new QPushButton(this);
    btn->setText("draw");
    btn->setObjectName(QString::fromUtf8("drawBtn"));
    btn->setGeometry(QRect(10, 10, 89, 25));
    QObject::connect(btn, SIGNAL(clicked()), this, SLOT(drawSlot()));

    clearBtn = new QPushButton(this);
    clearBtn->setText("clear");
    clearBtn->setObjectName(QString::fromUtf8("clearBtn"));
    clearBtn->setGeometry(QRect(100, 10, 89, 25));
    QObject::connect(clearBtn, SIGNAL(clicked()), this, SLOT(clearSlot()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent* event)
{
    if(flag)
    {
        Q_UNUSED(event);

        QPainter painter;
        painter.begin(this);
        painter.setBrush(Qt::NoBrush);

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

        QRect rt(0, 250,10, 10);
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

        ///< linestyle
        linecpaStyle(painter);

        ///< join style
        linejoinStyle(painter);

        ///<brash fill
        //brushfill(painter);

        painter.end();
    }
}

void Widget:: brushfill(QPainter& painter)
{
    QPen pen;
    QBrush brush(Qt::green, Qt::Dense3Pattern);
    pen.setWidth(1);
    pen.setColor(Qt::green);
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawEllipse(0,350, 100, 50);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::blue);
    painter.drawEllipse(50, 350, 100, 50);

    ///< brush file img
    QPixmap pixmap(":/qt.png");
    int w = pixmap.width();
    int h = pixmap.height();
    pixmap.scaled(w,h,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QBrush br(pixmap);
    painter.setBrush(br);
    painter.setPen(Qt::blue);
    painter.drawRect(200,350, w, h);
}
void Widget::linecpaStyle(QPainter& painter)
{

    QPen pen;

    pen.setWidth(10);
    pen.setCapStyle(Qt::FlatCap);
    painter.setPen(pen);
    painter.drawLine(100, 30, 200, 30);

    pen.setCapStyle(Qt::SquareCap);
    painter.setPen(pen);
    painter.drawLine(100,70,200,70);

    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.drawLine(100, 110, 200, 110);
}
void Widget::linejoinStyle(QPainter& painter)
{
    QPen pen;
    pen.setWidth(10);
    int delta = 200;
    QPointF p1(30.0+delta, 80.0);
    QPointF p2(20.0+delta, 40.0);
    QPointF p3(80.0+delta, 60.0);
    QPointF *pA[3]={&p1, &p2, &p3};

    pen.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pen);
    painter.drawPolyline(*pA,3);

    p1.setX(p1.x()+delta);p2.setX(p2.x()+delta);p3.setX(p3.x()+delta);
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(pen);
    painter.drawPolyline(*pA,3);

    p1.setX(p1.x()+delta);p2.setX(p2.x()+delta);p3.setX(p3.x()+delta);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    painter.drawPolyline(*pA,3);
}
