#ifndef SYSTEM_PARSER_H
#define SYSTEM_PARSER_H

#include <string>
#include <unordered_map>
#include <vector>

namespace LinuxParser {
// Paths
const std::string kProcDirectory{"/proc/"};
const std::string kCmdlineFilename{"/cmdline"};
const std::string kCpuinfoFilename{"/cpuinfo"};
const std::string kStatusFilename{"/status"};
const std::string kStatFilename{"/stat"};
const std::string kUptimeFilename{"/uptime"};
const std::string kMeminfoFilename{"/meminfo"};
const std::string kVersionFilename{"/version"};
const std::string kOSPath{"/etc/os-release"};
const std::string kPasswordPath{"/etc/passwd"};

// System
std::string OperatingSystem();
std::string Kernel();
std::unordered_map<std::string, long> aggregateCPUtickData();
float MemoryUtilization();
int TotalProcesses();
int RunningProcesses();
long UpTime();

// Processes
std::vector<int> Pids();
std::string Uid(int pid);
std::string User(int pid);
long ActiveProcessTime(int pid);
long Ram(int pid);
long int UpTime(int pid);
std::string Command(int pid);
};  // namespace LinuxParser

#endif
