#include "btdLogger.h"
#include <QDebug>

BtdLogger *BtdLogger::instance = nullptr;
std::once_flag BtdLogger::initInstanceFlag;

BtdLogger::~BtdLogger()
{
    spdlog::drop_all(); // must do
    spdlog::shutdown();
}

/// @brief BtdLogger构造函数，完成rotation file loggger 的初始化和创建
/// @param info  rotation file logger 需要的信息
BtdLogger::BtdLogger(const LogInfo *info)
{
    bool console = true;
    std::string log_dir("./log"); // should create the folder if not exist
    std::string loggerName("btdlog");
    std::string pattern("%Y-%m-%d %H:%M:%S.%f <thread %t> [%l] [%@] %v");
    std::string level("debug");
    long long eachFileSize(5 * 1024 * 1024);
    int maxFileNums(1000);
    long poolSize(1024);
    int threadNum(1);
    
    try{
        //接受外部的数据来初始化单例
        if (info != nullptr)
        {
            console      = info->isConsole;
            log_dir      = info->savePath;
            loggerName   = info->loggerName;
            pattern      = info->pattern;
            level        = info->logLevel;
            eachFileSize = info->eachFileSize;
            maxFileNums  = info->maxFileNums;
            threadNum    = info->threaNum;
            poolSize     = info->poolSize;
            qDebug() <<"pattern  = " << pattern.c_str() ;
            qDebug()<<"set info" ;
        }

        // 检查当前目录，不存在则创建之
        FilePathMag pathMag;
        std::string currentDir = pathMag.getCurrentPath();
        std::cout << "running in: " << currentDir << std::endl;
        int flag = 0;
        if (access(currentDir.c_str(), 0) == -1)
        {
#ifdef _WIN32
            flag = mkdir(currentDir.c_str()); // windows创建文件夹
#else
            flag = mkdir(currentDir.c_str(), S_IRWXU); // Linux下创建文件夹
#endif
        }
        else
        {
            std::cout << "This Directory exists!" << std::endl;
        }

        ///< directory exists, create rotation logger
        if (flag == 0)
        {
            std::cout << "create directory success!" << std::endl;

            ///< logger name with timestamp
            int date = NowDateToInt();
            int time = NowTimeToInt();
            const std::string logFileName = loggerName + "_" + std::to_string(date) + "_" + std::to_string(time);
            std::cout << "log File Name = " << logFileName << std::endl;

            ///< create async rotate file logger
            if (console)
                m_logger = spdlog::stdout_color_st(loggerName); // single thread console output faster
            else
                m_logger = spdlog::create_async<spdlog::sinks::rotating_file_sink_mt>(loggerName, log_dir + "/" + logFileName + ".log", eachFileSize, maxFileNums); // multi part log files, with every part 500M, max 1000 files


            // custom format and flush time
            m_logger->set_pattern(pattern); // with timestamp, thread_id, filename and line number

            if (level == "trace")
            {
                m_logger->set_level(spdlog::level::trace);
                m_logger->flush_on(spdlog::level::trace);
            }
            else if (level == "debug")
            {
                m_logger->set_level(spdlog::level::debug);
                m_logger->flush_on(spdlog::level::debug);
            }
            else if (level == "info")
            {
                m_logger->set_level(spdlog::level::info);
                m_logger->flush_on(spdlog::level::info);
            }
            else if (level == "warn")
            {
                m_logger->set_level(spdlog::level::warn);
                m_logger->flush_on(spdlog::level::warn);
            }
            else if (level == "error")
            {
                m_logger->set_level(spdlog::level::err);
                m_logger->flush_on(spdlog::level::err);
            }
        }
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cout << "Log initialization failed: " << ex.what() << std::endl;
    }
}


/**
 * @brief 创建一个roatation 单例
 * @param info logger配置，信息
 * @return BtdLogger& 
 */
BtdLogger* BtdLogger::getInstance(const LogInfo *info)
{
    std::call_once(initInstanceFlag, &BtdLogger::initSingleton, info);
    // volatile int dummy{};
    return instance;
}

/// @brief 获取当前spdlogger
/// @return 
std::shared_ptr<spdlog::logger>
BtdLogger::getLogger()
{
    return m_logger;
}

std::shared_ptr<spdlog::logger>
BtdLogger::getQtLogger()
{
    
    return m_qtLogger;
}

bool BtdLogger::createQtLogger(QObject *qt_object, const std::string &meta_method)
    {
         //< 创建qtLogger
        m_qtLogger = spdlog::qt_logger_mt("QLogger",qt_object, meta_method);
        spdlog::register_logger(m_qtLogger);
        if(m_qtLogger == nullptr) return false;
        return true;
    }
