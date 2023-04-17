#include <iostream>

#include <pistache/endpoint.h>
#include "./openAI/Completion/completionText.h"
#include  <spdlog/spdlog.h>
#include "nlohmann/json.hpp"

using namespace Pistache;
using namespace OpenAI;
using Json =nlohmann::json;
class HelloHandler : public Http::Handler {
    private:
    Json m_inputPromt;
    Json m_outResult;
public:

    HTTP_PROTOTYPE(HelloHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response) {
        
        std::cout << "get request" << std::endl;
        request.method();
        string key("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");
        string model("text-davinci-003");
        string prompt("你好你是谁，你父亲是谁，住在哪?");
        
        OpenAICompletion completion(key,  prompt, model);
        std::string res = completion.GetCompletion() + "\n";
        std::cout << "Q: " << prompt << std::endl;
        std::cout << "A: \n" << res << std::endl;
        std::cout << "gerestult " << std::endl;
        response.send(Http::Code::Ok, res.data());
    }
};
int main()
{
    // std::cout << "start chatbot server" << std::endl;
    // Address addr(Ipv4::any(), Port(9081));
    // auto opts = Http::Endpoint::options().threads(1);
    // Http::Endpoint server(addr);
    // server.init(opts);
    // server.setHandler(Http::make_handler<HelloHandler>());
    // server.serve();

        string key("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");
        string model("text-davinci-003");
        string prompt("你好你是谁，你父亲是谁，住在哪?");
        OpenAICompletion completion(key,  prompt, model);
        prompt.clear();
        while(true)
        {
            string input;
            cout << "prompt: " << prompt << std::endl;
            std::cout << "Q:  ";
            getline(cin, input);
            prompt = input ;
           // prompt += input;
           completion.setPrompt(prompt);
            
            std::string res = completion.GetCompletion() + "\n";
           // size_t first = res.find_first_not_of("\n");
          //  size_t last = res.length();
            //std::string trimmed = res.substr(first, last - first + 1);
            std::cout << "A: "<<  res   << std::endl;
            //prompt += res;
        } 
    return 0;
}