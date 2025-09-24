#include "metric_collector.h"
#include <iostream>
#include <random>
#include <chrono>

namespace agent{
MetricCollector::MetricCollector() : hostname_("localhost") {
    std::cout << "MetricCollector Initialized" << std::endl;
    globalTags_["agent"] = "custom-agent";
    globalTags_["version"] = "1.0.0";
}
std::vector<Metric> MetricCollector::collectMetrics() {
    std::vector<Metric> metrics;
    metrics.push_back(getCPUUsage());
    metrics.push_back(getMemoryUsage());
    metrics.push_back(getDiskUsage());
    return metrics;
}
Metric MetricCollector::getCPUUsage() {
    double cpuPercent = readCPUPercentage();
    Metric metric("system.cpu.usage", cpuPercent);
    addGlobalTags(metric);
    return metric;
}
Metric MetricCollector::getMemoryUsage() {
    double memoryPercent = readMemoryPercentage();
    Metric metric("system.memory.usage", memoryPercent);
    addGlobalTags(metric);
    return metric;
}
Metric MetricCollector::getDiskUsage() {
    double diskPercent = readDiskPercentage();
    Metric metric("system.disk.usage", diskPercent);
    addGlobalTags(metric);
    return metric;
}
void MetricCollector::setHostname(const std::string& hostname) {
    hostname_ = hostname;
}
void MetricCollector::addTag(const std::string& key, const std::string& value) {
    globalTags_[key] = value;
}
double MetricCollector::readCPUPercentage() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(10.0, 90.0);
    
    return dis(gen);
}
double MetricCollector::readMemoryPercentage() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(20.0, 80.0);
    
    return dis(gen);
}
double MetricCollector::readDiskPercentage() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(30.0, 70.0);
    
    return dis(gen);
}

void MetricCollector::addGlobalTags(Metric& metric) {
    metric.host = hostname_;
    
    for (const auto& tag : globalTags_) {
        metric.tags[tag.first] = tag.second;
    }
}
}