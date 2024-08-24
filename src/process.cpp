#include "process.h"

#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// Return this process's ID
int Process::Pid() const { 
    return pid_; 
}

// Return this process's CPU utilization
float Process::CpuUtilization() const { 
    long total_time = LinuxParser::ActiveJiffies(pid_);
    long uptime = LinuxParser::UpTime();
    long starttime = LinuxParser::UpTime(pid_);
    long hertz = sysconf(_SC_CLK_TCK);
    float seconds = uptime - (starttime / hertz);
    return (total_time / hertz) / seconds;
}

// Return the command that generated this process
string Process::Command() const { 
    return LinuxParser::Command(pid_); 
}

// Return this process's memory utilization
string Process::Ram() const { 
    return LinuxParser::Ram(pid_); 
}

// Return the user (name) that generated this process
string Process::User() const { 
    return LinuxParser::User(pid_); 
}

// Return the age of this process (in seconds)
long int Process::UpTime() const { 
    return LinuxParser::UpTime(pid_); 
}

// Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const { 
    return this->CpuUtilization() < a.CpuUtilization(); 
}
