#include <iostream>

#include <pistache/endpoint.h>
#include "./openAI/Completion/completionText.h"

using namespace Pistache;


class HelloHandler : public Http::Handler {
public:

    HTTP_PROTOTYPE(HelloHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response) {
        using namespace OpenAI;
        
        request.method();
        string key("");
        string model("text-davinci-003");
        string prompt("你好你是谁，你父亲是谁，住在哪?");

        OpenAICompletion completion(key,  prompt, model);
        std::string res = completion.GetCompletion() + "\n";
        std::cout << "Q: " << prompt << std::endl;
        std::cout << "A: \n" << res << std::endl;

        response.send(Http::Code::Ok, res.data());
    }
};
int main()
{
    Address addr(Ipv4::any(), Port(9080));
    auto opts = Http::Endpoint::options().threads(1);
    Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(Http::make_handler<HelloHandler>());
    server.serve();
    return 0;
}