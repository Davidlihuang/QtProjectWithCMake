#include "mainWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/image/image/LightMusicPlayer.ico")); //为窗口标题添加图片，注意要路径要添加 “: ”
    MainWidget w;
    w.show();
    
    return a.exec();
}
