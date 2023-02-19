///< OpenAI Requst API 
#ifndef OPENAI_H_
#define OPENAI_H_
#include <iostream>
#include <string>
#include "./Completion/completionText.h"
//#include <rapidjson>
//#include "completionText.h"

namespace OPENAI{
    using namespace std;
    class OpenAI
    {
    private:
        string m_organization;
         static string  sta_apiKey;     
    };
};
/* 
    Completion,
    Customer,
    Edit,
    Deployment,
    Embedding,
    Engine,
    ErrorObject,
    File,
    FineTune,
    Image,
    Model,
    Moderation,
    */
   
#endif