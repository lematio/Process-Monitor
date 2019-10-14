#ifndef SYSTEM_H
#define SYSTEM_H

#include "process.h" // class Process
// process.h includes:
//   <string>

#include "processor.h" // class Processor

#include <vector>

class System {
 public:
  Processor& Cpu() { return cpu_; };
  std::vector<Process>& Processes();
  float MemoryUtilization();
  long UpTime();
  int TotalProcesses();
  int RunningProcesses();
  std::string Kernel();
  std::string OperatingSystem();

 private:
  Processor cpu_;
  std::vector<Process> processes_;
};

#endif
