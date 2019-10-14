#include "process.h" // class Process
// process.h includes:
//   <string> // to_string

#include "linux_parser.h" // LinuxParser::

using std::string;
using std::to_string;

// Return this process's ID.
int Process::Pid() { return id; }

// Return the user (name) that generated this process.
string Process::User() { return LinuxParser::User(id); }

// Return this process's CPU utilization.
float Process::CpuUtilization() { return fraction_cpu; }

// Return this process's memory utilization.
string Process::Ram() { return to_string(ram); }

// Return the age of this process (in seconds).
long int Process::UpTime() { return uptime; }

// Return the command that generated this process.
string Process::Command() { return LinuxParser::Command(id); }

// Overload the "greater than" comparison operator for Process objects.
bool Process::operator>(Process const& a) const {
//if(ram > a.ram) // to sort processes based on ram
  if(fraction_cpu > a.fraction_cpu) // to sort processes based on CPU usage
    return true;
  return false;
}
