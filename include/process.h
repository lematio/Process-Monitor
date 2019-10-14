#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process {
 public:
  Process(int pid, long mem, long apt, long ut):
        id(pid), ram(mem), uptime(ut) {
    fraction_cpu = static_cast<float>(apt) / uptime;
  };
  int Pid();
  std::string User();
  float CpuUtilization();
  std::string Ram();
  long int UpTime();
  std::string Command();
  bool operator>(Process const& a) const;

 private:
   int id;
   long ram;
   long uptime;
   float fraction_cpu;
};

#endif
