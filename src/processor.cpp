#include "processor.h"
#include "linux_parser.h"

// Return the aggregate CPU utilization
float Processor::Utilization() { 
    // Retrieve current CPU times from LinuxParser
    long idle = LinuxParser::IdleJiffies();
    long non_idle = LinuxParser::ActiveJiffies();
    long total = idle + non_idle;

    // Calculate differences from previous times
    long total_diff = total - prev_total_;
    long idle_diff = idle - prev_idle_;

    // Update previous times for next calculation
    prev_idle_ = idle;
    prev_non_idle_ = non_idle;
    prev_total_ = total;

    // Calculate CPU utilization
    float utilization = (total_diff - idle_diff) / static_cast<float>(total_diff);
    return utilization;
}
