#include "processor.h" // class Processor

#include "linux_parser.h" // LinuxParser::aggregateCPUtickData
// linux_parser.h includes:
//   <string>
//   <unordered_map>

#include <chrono> // seconds
#include <thread> // sleep_for

using std::chrono::seconds;
using std::this_thread::sleep_for;
using std::string;
using std::unordered_map;

// Return the aggregate CPU utilization.
float Processor::Utilization() {
  unordered_map<string, long> ticks = LinuxParser::aggregateCPUtickData();
  long activetickTypes = ticks["user"] + ticks["nice"] + ticks["system"]
    + ticks["irq"] + ticks["softirq"] + ticks["steal"];
  long idletickTypes = ticks["idle"] + ticks["iowait"];

  sleep_for(seconds(1));

  ticks = LinuxParser::aggregateCPUtickData();
  activetickTypes = ticks["user"] + ticks["nice"] + ticks["system"]
    + ticks["irq"] + ticks["softirq"] + ticks["steal"] - activetickTypes;
  idletickTypes = ticks["idle"] + ticks["iowait"] - idletickTypes;

  return static_cast<float>(activetickTypes)
    / (activetickTypes + idletickTypes);
}
