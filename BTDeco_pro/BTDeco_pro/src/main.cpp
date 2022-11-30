#include "mainwindow.h"
#include <QApplication>
#include "spdlog/spdlog.h"
#include "btdLogger.h"
#include <QDebug>

int main(int argc, char *argv[])
{

    // FilePathMag path;
    // std::string strPath = path.getCurrentPath();
    // std::cout << "strPath: " << strPath << std::endl;

    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

   

    // return a.exec();
    LogInfo info;
   // BtdLogger *Btdlogger = BtdLogger::getInstance(nullptr);
    //auto logger = Btdlogger->getLogger();
    LOG_TRACE("first log message!");
    LOG_INFO("first log message!");
    LOG_ERROR("first log message!");
    LOG_DEBUG("first log message!");
    LOG_WARN("first log message!");
    return 0;
}
