#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid) : pid_(pid) {}  // Constructor to initialize the process with a PID
  int Pid() const;                               // See src/process.cpp
  std::string User() const;                      // See src/process.cpp
  std::string Command() const;                   // See src/process.cpp
  float CpuUtilization() const;                  // See src/process.cpp
  std::string Ram() const;                       // See src/process.cpp
  long int UpTime() const;                       // See src/process.cpp
  bool operator<(Process const& a) const;        // See src/process.cpp

  // Declare any necessary private members
 private:
   int pid_;
};

#endif