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
struct LogInfo
{
    bool        isConsole;    // log输出到console
    
    std::string loggerName;   // logger 的名字
    std::string savePath;     // log文件保存路径

    std::string pattern;      // log输出的格式
    std::string logLevel;     // log等级
    long        eachFileSize; // rotate中每个文件的大小
    int         maxFileNums;  // 最大的文件数量
    long        poolSize;     // logger的线程池大小
    int         threaNum;     // async logger的工作线程数
    std::string flushLevel;   // flush level to logger file
};

class BtdLogger
{
public:
    
    static BtdLogger* getInstance(const LogInfo* info=nullptr);

private:
    BtdLogger(const LogInfo* info=nullptr);
    ~BtdLogger();
    
    BtdLogger(const BtdLogger &) = delete;
    BtdLogger &operator=(const BtdLogger &) = delete;

private:
    static BtdLogger *instance;
    static std::once_flag initInstanceFlag;

    std::shared_ptr<spdlog::logger> m_logger;

private:
    static void initSingleton(const LogInfo* info)
    {
        std::cout << "crate BtdLogger Sington instance!" << std::endl;
        instance = new BtdLogger(info);
    }

public:
    std::shared_ptr<spdlog::logger> getLogger();
};


// use embedded macro to support file and line number
#define LOG_TRACE(...) SPDLOG_LOGGER_CALL(BtdLogger::getInstance()->getLogger().get(), spdlog::level::trace, __VA_ARGS__)
#define LOG_DEBUG(...) SPDLOG_LOGGER_CALL(BtdLogger::getInstance()->getLogger().get(), spdlog::level::debug, __VA_ARGS__)
#define LOG_INFO(...) SPDLOG_LOGGER_CALL(BtdLogger::getInstance()->getLogger().get(), spdlog::level::info, __VA_ARGS__)
#define LOG_WARN(...) SPDLOG_LOGGER_CALL(BtdLogger::getInstance()->getLogger().get(), spdlog::level::warn, __VA_ARGS__)
#define LOG_ERROR(...) SPDLOG_LOGGER_CALL(BtdLogger::getInstance()->getLogger().get(), spdlog::level::err, __VA_ARGS__)
