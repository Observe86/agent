#pragma once

#include <string>
#include <map>

namespace agent {
struct HttpResponse {
    int statusCode;
    std::string body;
    bool success;
    std::string errorMessage;

    HttpResponse() : statusCode(0), success(false) {}
};

class HttpClient {
public:
    HttpClient();
    ~HttpClient();

    HttpResponse post(const std::string& url, const std::string &jsonData, const std::map<std::string, std::string> &headers = {});
    HttpResponse get(const std::string& url, const std::map<std::string, std::string>& headers = {});
private:
    void* curl_handle_;
    void setupHeaders(const std::map<std::string, std::string>& headers);
};

}