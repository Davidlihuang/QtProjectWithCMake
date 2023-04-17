#include "completionText.h"

std::string  OpenAI::OpenAICompletion::GetCompletion()
        {
            std::string response;

            CURL *curl = curl_easy_init();

            if (curl)
            {
                // 设置要访问的 URL
                std::string url = "https://api.openai.com/v1/completions";
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

                // 设置 HTTP 请求头
                struct curl_slist *headers = NULL;
                headers = curl_slist_append(headers, ("Content-Type: application/json"));
                headers = curl_slist_append(headers, ("Authorization: Bearer " + this->m_apikey).c_str());
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

                // 设置 HTTP 请求体
                m_inputPrompt["model"]             = this->m_model;
                m_inputPrompt["prompt"]           = this->m_prompt;
                m_inputPrompt["max_tokens"]  =  this->m_maxTokens;
                m_inputPrompt["temperature"]  =  this->m_temperature;
                m_inputPrompt["n"]                         = this->m_genNumerical;
                m_inputPrompt["top_p"]                = m_topP;
                
               // std::cout << "messaged body: " <<std::endl;
               // std::cout << setw(4) << m_inputPrompt << std::endl;

                std::string data = m_inputPrompt.dump();
                
                // 
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

                // 将响应写入到字符串中
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

                // 发送请求
                CURLcode res = curl_easy_perform(curl);

                // 检查请求是否成功
                if (res != CURLE_OK)
                {
                    std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
                }

                // 清理 curl 句柄
                curl_easy_cleanup(curl);
            }

           m_outputResult = Json::parse(response);
          std::cout <<"resBody: "<< setw(4) << m_outputResult << std::endl;
           auto choices = m_outputResult["choices"];
           for(size_t i=0; i< choices.size();i++)
           {
                auto item = m_outputResult["choices"][i];
                response = item["text"];
           }
           
            return response;
        }