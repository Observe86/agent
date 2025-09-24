#pragma once

#include <string>
#include <map>
#include <vector>
#include <chrono>

namespace agent {
struct Metric {
    std::string name;
    double value;
    std::chrono::system_clock::time_point timestamp;
    std::map<std::string, std::string> tags;
    std::string host;

    Metric() : value(0.0), timestamp(std::chrono::system_clock::now()) {}
    Metric(const std::string& n, double v) : name(n), value(v), timestamp(std::chrono::system_clock::now()) {}
};

enum class Status {
    SUCCESS,
    ERROR,
    TIMEOUT,
    NOT_FOUND,
    PERMISSION_DENIED
};

struct AgentConfig {
    std::string intakeEndpoint;
    std::string apiKey;
    std::string hostname;
    int metricIntervalSeconds;
    bool enableSystemMetrics;
    AgentConfig() : metricIntervalSeconds(60), enableSystemMetrics(true) {}
};
}