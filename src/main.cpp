#include <iostream>
#include <string>
#include "core/types.h"
#include "transport/http_client.h"

int main(int argc, char *argv[]) {
    // test our types
    agent::Metric testMetric("cpu.usage", 45.5);
    testMetric.host = "localhost";
    testMetric.tags["environment"] = "test";
    std::cout << "Created test metric: " << testMetric.name << " = " << testMetric.value << " on host: " << testMetric.host << std::endl;
    agent::AgentConfig config;
    config.intakeEndpoint = "http://localhost:8080/intake";
    config.apiKey = "test-key";
    std::cout << "Config loaded - endpoint: " << config.intakeEndpoint << std::endl;

    // test HTTP client
    agent::HttpClient httpClient;
    
    std::map<std::string, std::string> headers;
    headers["Content-Type"] = "application/json";
    headers["Authorization"] = "Bearer test-key";
    
    std::string testData = "{\"metric\":\"cpu.usage\",\"value\":45.5}";
    agent::HttpResponse response = httpClient.post("http://localhost:8080/intake/metrics", testData, headers);
    
    std::cout << "HTTP Response - Status: " << response.statusCode 
              << ", Success: " << (response.success ? "true" : "false") << std::endl;
    std::cout << "Response body: " << response.body << std::endl;
    
    std::cout << "Agent test completed!" << std::endl;
    return 0;
}