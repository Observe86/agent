#pragma once

#include <vector>
#include <string>
#include "../core/types.h"

namespace agent {
class MetricCollector {
public:
    MetricCollector();
    ~MetricCollector();

    std::vector<Metric> collectMetrics();

    Metric getCPUUsage();
    Metric getMemoryUsage();
    Metric getDiskUsage();

    void setHostname(const std::string& hostname);
    void addTag(const std::string& key, const std::string& value);
private:
    std::string hostname_;
    std::map<std::string, std::string> globalTags_;

    double readCPUPercentage();
    double readMemoryPercentage();
    double readDiskPercentage();
    void addGlobalTags(Metric& metric);
};
}