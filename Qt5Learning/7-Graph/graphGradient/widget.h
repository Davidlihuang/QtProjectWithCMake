#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void paintEvent(QPaintEvent* event);
    void drawGradient();
signals:
    void clickBtn(int);
public slots:
    void padslots();
    void repeatslots();
    void reflecslots();

    //void drawGraph(int flag);
private:
    Ui::Widget *ui;
    QPainter painter;
    bool padflg = false;
    bool repeatflg = false;
    bool reflectflg = false;
    QPushButton *padSpreadBtn;
    QPushButton *repeatSpreadBtn;
    QPushButton *reflectSpreadBtn;
};
#endif // WIDGET_H
