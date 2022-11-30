#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <string>

#include "spdlog/spdlog.h"
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h" // or "../stdout_sinks.h" if no color needed
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"

#ifdef _WIN32 // Windows
    #include <direct.h>
    #include <io.h>
#else // Linux
    #include <sys/io.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <dirent.h>
#endif



#ifdef _WIN32 //Windows
    #define SYSTEM_FLAGS "windows"
#else
    #define SYSTEM_FLAGS "linux"
#endif






class FilePathMag
{
enum class Platform{ windows, linux};
public:
    FilePathMag(){
        if(SYSTEM_FLAGS == "windows")
        {
            m_curPlatform = Platform::windows;
            std::cout << "current platforms: " << "windows" << std::endl;
        }
        else{
            m_curPlatform = Platform::linux;
            std::cout << "current platforms: " << "linux" << std::endl;
        }
    }

    std::string getCurrentPath()
    {
        char buffer[1024]; 
        memset(buffer, 0x00, sizeof(buffer));
        getcwd(buffer, sizeof(buffer)-1);
        m_currentPath = std::string(buffer);
        std::cout << "currentPath: " << m_currentPath << std::endl;
#ifdef _WIN32 // Windows
       // getcwd(buffer, sizeof(buffer)-1);
        //m_currentPath = std::string(buffer);
#else
       
#endif
        return m_currentPath;
    }

    std::string getRelativePath()
    {
        return m_relativePath;
    }

    bool createDirectory(const std::string&path)
    {
        return true;
    }
private:
     Platform m_curPlatform;
     std::string m_currentPath;
     std::string m_relativePath;
};




///< get data time
static inline int NowDateToInt()
{
    time_t now;
    time(&now);

    // choose thread save version in each platform
    tm p;
#ifdef _WIN32
    localtime_s(&p, &now);
#else
    localtime_r(&now, &p);
#endif // _WIN32
    int now_date = (1900 + p.tm_year) * 10000 + (p.tm_mon + 1) * 100 + p.tm_mday;
    return now_date;
}

static inline int NowTimeToInt()
{
    time_t now;
    time(&now);
    // choose thread save version in each platform
    tm p;
#ifdef _WIN32
    localtime_s(&p, &now);
#else
    localtime_r(&now, &p);
#endif // _WIN32

    int now_int = p.tm_hour * 10000 + p.tm_min * 100 + p.tm_sec;
    return now_int;

}





/*********************************************************
 * @brief BtdLogger：  The logger  to record runing status
 * 
 *********************************************************/
class BtdLogger
{
public:
    static BtdLogger &getInstance()
    {
        std::call_once(initInstanceFlag, &BtdLogger::initSingleton);
        // volatile int dummy{};
        return *instance;
    }

private:
    BtdLogger();
    ~BtdLogger();
    BtdLogger(const BtdLogger &) = delete;
    BtdLogger &operator=(const BtdLogger &) = delete;

private:
    static BtdLogger *instance;
    static std::once_flag initInstanceFlag;

    std::shared_ptr<spdlog::logger> m_logger;

private:
    static void initSingleton()
    {
        instance = new BtdLogger;
    }

public:
    std::shared_ptr<spdlog::logger> getLogger();
};


///< realize all logger functions;
BtdLogger::BtdLogger()
    {
        // hardcode log path
		const std::string log_dir = "./log"; // should create the folder if not exist
		const std::string logger_name_prefix = "btdlog_";
 
		// decide print to console or log file
		bool console = false;
 
		// decide the log level
		std::string level = "debug";

        try
        {
            // logger name with timestamp
            int date = NowDateToInt();
            int time = NowTimeToInt();
            const std::string logger_name = logger_name_prefix + std::to_string(date) + "_" + std::to_string(time);

            if (console)
                m_logger = spdlog::stdout_color_st(logger_name); // single thread console output faster
            else
                // m_logger = spdlog::create_async<spdlog::sinks::basic_file_sink_mt>(logger_name, log_dir + "/" + logger_name + ".log"); // only one log file
                m_logger = spdlog::create_async<spdlog::sinks::rotating_file_sink_mt>(logger_name, log_dir + "/" + logger_name + ".log", 500 * 1024 * 1024, 1000); // multi part log files, with every part 500M, max 1000 files

            // custom format
            m_logger->set_pattern("%Y-%m-%d %H:%M:%S.%f <thread %t> [%l] [%@] %v"); // with timestamp, thread_id, filename and line number

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
        catch (const spdlog::spdlog_ex &ex)
        {
            std::cout << "Log initialization failed: " << ex.what() << std::endl;
        }
}

BtdLogger::~BtdLogger()
{
    spdlog::drop_all(); //must do
    spdlog::shutdown();
}

std::shared_ptr<spdlog::logger> BtdLogger::getLogger()
{
    return m_logger;
}


BtdLogger* BtdLogger::instance= nullptr;
std::once_flag BtdLogger::initInstanceFlag;
// use embedded macro to support file and line number
#define LOG_TRACE(...) SPDLOG_LOGGER_CALL(BtdLogger::getInstance()->getLogger().get(), spdlog::level::trace, __VA_ARGS__)
#define LOG_DEBUG(...) SPDLOG_LOGGER_CALL(BtdLogger::getInstance()->getLogger().get(), spdlog::level::debug, __VA_ARGS__)
#define LOG_INFO(...) SPDLOG_LOGGER_CALL(BtdLogger::getInstance()->getLogger().get(), spdlog::level::info, __VA_ARGS__)
#define LOG_WARN(...) SPDLOG_LOGGER_CALL(BtdLogger::getInstance()->getLogger().get(), spdlog::level::warn, __VA_ARGS__)
#define LOG_ERROR(...) SPDLOG_LOGGER_CALL(BtdLogger::getInstance()->getLogger().get(), spdlog::level::err, __VA_ARGS__)