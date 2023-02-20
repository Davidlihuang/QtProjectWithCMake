#pragma once
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <unordered_map>

using namespace std;

namespace OpenAI
{

    class OpenAICompletion
    {
    public:
        OpenAICompletion(const string & api_key,  const string& prompt="Say hello to my!", const string& model="text-davinci-003")
        : m_apikey(api_key), m_model(model),m_prompt(prompt)
        {
                m_temperature    = 0.7;
                m_maxTokens       = 1024;
                m_genNumerical  =  1;
                m_topP                     =  1;
                m_suffix                    =  "null"  ;
                m_genNumerical  = 1  ;
                m_stream                 = false    ; 
                m_logprobs             =  "null" ;
                m_echo                     =  false    ;
                m_stop                            =  ""   ;  //Do not add to http body, when empty
                m_presencePenalty   = 0;
                m_frequencyPenalty = 0;
                m_bestOf                        = 1;
                //m_logitBiasMap ;                  //Do not add to http body,when empty
                m_user  =  "";                              //Do not add to http body, when empty
        }
        OpenAICompletion(const std::string &api_key, const std::string &model, const std::string &prompt, int max_tokens, double temperature)
            : m_apikey(api_key), m_model(model), m_prompt(prompt), m_maxTokens(max_tokens), m_temperature(temperature) 
            {
               
                m_genNumerical  =  1;
                m_topP                     =  1;
                m_suffix                    =  "null"  ;
                m_stream                 = false    ; 
                m_logprobs             =  "null" ;
                m_echo                     =  false    ;
                m_stop                            =  ""   ;  //Do not add to http body, when empty
                m_presencePenalty   = 0;
                m_frequencyPenalty = 0;
                m_bestOf                        = 1;
                //m_logitBiasMap ;                  //Do not add to http body,when empty
                m_user  =  "";                              //Do not add to http body, when empty
            }

        ~OpenAICompletion() {}

        std::string GetCompletion();

    private:
        static size_t WriteCallback(char *ptr, size_t size, size_t nmemb, void *userdata)
        {
            ((std::string *)userdata)->append(ptr, size * nmemb);
            return size * nmemb;
        }

        string          m_apikey;
        string          m_model;
        string          m_prompt;
        string          m_suffix;
        int                m_maxTokens;
        double       m_temperature;
        double       m_topP;
        int                m_genNumerical;
        bool            m_stream;
        string          m_logprobs;
        bool            m_echo;
        string          m_stop;
        double       m_presencePenalty;
        double       m_frequencyPenalty;
        int                                                        m_bestOf;
        unordered_map<string, int>   m_logitBiasMap;
        string                                                  m_user;

    };

}; // openAI namesapce

// int main() {
//     // 初始化 libcurl 库
//     curl_global_init(CURL_GLOBAL_ALL);

//     // 创建 OpenAICompletion 对象，并使用 GetCompletion() 方法获取响应
//     OpenAICompletion completion("YOUR_API_KEY", "davinci", "Once upon a time", 20, 0.5);
//     std::string response = completion.GetCompletion();

//     // 输出响应内容
//     std::cout << response << std::endl;

//     // 清理 libcurl 库
//     curl_global_cleanup();

//     return 0;
// }
