#include "mainwindow.h"
#include <QApplication>
#include "spdlog/spdlog.h"
#include "btdLogger.h"
#include <QDebug>

int main(int argc, char *argv[])
{

    FilePathMag path;
    std::string strPath = path.getCurrentPath();
    std::cout << "strPath: " << strPath << std::endl;

    // set logger 
    LogInfo info;
    BtdLogger *Btdlogger = BtdLogger::getInstance(nullptr);

    // logger write
    LOG_TRACE("first log message!");
    LOG_INFO("first log message!");
    LOG_ERROR("first log message!");
    LOG_DEBUG("first log message!");
    LOG_WARN("first log message!");
    
    //  run qt project
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
