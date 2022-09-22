#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:

    Widget(QWidget *parent = nullptr);
    ~Widget();
    void linecpaStyle(QPainter& painter); ///< capstyle
    void linejoinStyle(QPainter& painter); ///< joinStyle
    void brushfill(QPainter& painter);  ///<Qbrush
protected:
    void paintEvent(QPaintEvent *event);
private:
    bool flag;
    QPushButton* btn;
    QPushButton* clearBtn;
    Ui::Widget *ui;
public slots:
    void clearSlot()
    {
        flag = false;
        update();
    }
    void drawSlot()
    {
        flag = true;
        update();
    }
    void toggleStatus()
    {
        if(flag)
            flag = false;
        else
            flag = true;
        update();
    }
};
#endif // WIDGET_H
