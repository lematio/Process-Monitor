#include "system.h" // class System
// system.h includes:
//   "process.h" // class Process
//   process.h includes:
//     <string>
//   <vector>

#include "linux_parser.h" // LinuxParser::

#include <algorithm> // sort
#include <functional> // greater

using std::sort;
using std::greater;
using std::string;
using std::vector;

// Return a container composed of the system's processes.
vector<Process>& System::Processes() {
  vector<int> pids{LinuxParser::Pids()};

  processes_.clear();
  long mem, activeProcTime, uptime;
  for(int pid: pids) {
    mem = LinuxParser::Ram(pid); // from /proc/[pid]/status
    activeProcTime = LinuxParser::ActiveProcessTime(pid); // from --|
    uptime = LinuxParser::UpTime(pid); // from /proc/[pid]/stat <---|

    if(mem > -1 and activeProcTime > -1 and uptime > 0)
      processes_.emplace_back(pid, mem, activeProcTime, uptime);
  //else
  //  Process object is not instantiated. So, process is not listed. One of the
  //  following cases has occurred:
  //  If mem is -1, process status file couldn't be opened.
  //  If activeProcTime or uptime is -1, process stat file conldn't be opened.
  //  If uptime is 0, then process CPU usage cannot be computed.
  }
  sort(processes_.begin(), processes_.end(), greater<>());
  return processes_;
}

// Return the system's kernel identifier(string).
string System::Kernel() { return LinuxParser::Kernel(); }

// Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

// Return the operating system name.
string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

// Return the number of processes actively running on the system.
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

// Return the total number of processes on the system.
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

// Return the number of seconds since the system started running.
long System::UpTime() { return LinuxParser::UpTime(); }
