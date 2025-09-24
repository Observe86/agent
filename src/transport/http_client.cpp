#include "http_client.h"
#include <iostream>

namespace agent {
HttpClient::HttpClient() : curl_handle_(nullptr) {
    std::cout << "HttpClient Initialized" << std::endl;
}

HttpClient::~HttpClient(){

}

HttpResponse HttpClient::post(const std::string& url, const std::string& jsonData, const std::map<std::string, std::string>& headers) {
    HttpResponse response;
    std::cout << "Mock POST to: " << url << std::endl;
    std::cout << "Data: " << jsonData << std::endl;
    std::cout << "Headers: " << headers.size() << " headers" << std::endl;

    response.success = true;
    response.statusCode = 200;
    response.body = "{\"status\":\"ok\",\"message\":\"mock response\"}";
    return response;
}

HttpResponse HttpClient::get(const std::string& url, const std::map<std::string, std::string>& headers){
    HttpResponse response;
    std::cout << "Mock GET from: " << url << std::endl;
    std::cout << "Headers: " << headers.size() << " headers" << std::endl;
    
    response.success = true;
    response.statusCode = 200;
    response.body = "{\"status\":\"ok\"}";
    
    return response;
}

void HttpClient::setupHeaders(const std::map<std::string, std::string>& headers) {
    for (const auto& header: headers) {
        std::cout << "Header: " << header.first << " = " << header.second << std::endl;
    }
}
}