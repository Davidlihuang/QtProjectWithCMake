#include "mainwindow.h"
#include <QApplication>
#include "spdlog/spdlog.h"
#include "btdLogger.h"
#include <QDebug>

void setLoggerInfo(LogInfo& info)
{
    // set logger
    info.isConsole     = true;            // log输出到console
    info.loggerName    = "btdlog";        // logger 的名字
    info.savePath      = "./log";         // log文件保存路径
    info.pattern       = "%Y-%m-%d %H:%M:%S.%f [%l] <thread %t> [%@: %!]: %v";      // log输出的格式
    info.logLevel      = "debug";         // log等级
    info.eachFileSize  = 5 * 1024 * 1024; // rotate中每个文件的大小
    info.maxFileNums   = 1000;            // 最大的文件数量
    info.poolSize      = 1024;            // logger的线程池大小
    info.threaNum      =  1;              // async logger的工作线程数
    info.flushLevel    = info.logLevel;        // flush level to logger file
}
static spdlog::logger *globalLoger = nullptr;
int main(int argc, char *argv[])
{

    // FilePathMag path;
    // std::string strPath = path.getCurrentPath();
    // std::cout << "strPath: " << strPath << std::endl;
    QApplication a(argc, argv);
    MainWindow w;

    LogInfo info;
    setLoggerInfo(info);
    BtdLogger *Btdlogger = BtdLogger::getInstance(&info);
    
    ///< 创建qt_sink
    auto qt_sink = std::make_shared<spdlog::sinks::qt_sink_mt>(w.ui->txedt_msg, "appendPlainText");
    globalLoger = BtdLogger::getInstance()->getLogger().get();
    globalLoger->sinks().push_back(qt_sink);

    
    

    // logger write
    LOG_TRACE("first log message!");
    LOG_INFO("first log message!");
    LOG_ERROR("first log message!");
    LOG_DEBUG("first log message!");
    LOG_WARN("first log message!");

    



    //  run qt project
    // QApplication a(argc, argv);
    // MainWindow w;
    w.show();
    return a.exec();
}
