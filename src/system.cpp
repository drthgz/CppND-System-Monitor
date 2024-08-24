#include "system.h"

#include <unistd.h>

#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// Return a container composed of the system's processes
vector<Process>& System::Processes() {
  processes_.clear();  // Clear the vector to ensure it's updated with current
                       // processes

  vector<int> pids = LinuxParser::Pids();  // Get the list of all process IDs
  for (int pid : pids) {
    Process process(pid);              // Create a Process object for each PID
    processes_.emplace_back(process);  // Add it to the vector
  }

  std::sort(
      processes_.begin(), processes_.end(),
      [](const Process& a, const Process& b) {
        return b < a;  // Sort processes by CPU utilization in descending order
      });
  return processes_;
}

// Return the system's kernel identifier (string)
std::string System::Kernel() { return LinuxParser::Kernel(); }

// Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

// Return the operating system name
std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

// Return the number of processes actively running on the system
int System::RunningProcesses() { return LinuxParser::RunningProcesses();  }

// Return the total number of processes on the system
int System::TotalProcesses() { return LinuxParser::TotalProcesses();  }

// Return the number of seconds since the system started running
long int System::UpTime() { return LinuxParser::UpTime();  }