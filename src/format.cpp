#include "format.h" // Format::
// format.h includes:
//   <string> // to_string

using std::to_string;
using std::string;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) {
  long ss, mm, hh;
  ss = seconds % 60;
  mm = seconds / 60;
  hh = mm / 60;
  mm %= 60;

  auto strTT = [](long tt) {
    return tt < 10 ? "0" + to_string(tt) : to_string(tt);
  };

  return strTT(hh) + ":" + strTT(mm) + ":" + strTT(ss);
}
