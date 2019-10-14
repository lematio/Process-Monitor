#ifndef NCURSES_DISPLAY_H
#define NCURSES_DISPLAY_H

#include "system.h" // class System
// system.h includes:
//   "process.h" // class Process
//   process.h includes:
//     <string>
//   <vector>

#include <curses.h> // WINDOW
// https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html

namespace NCursesDisplay {
void Display(System& system, int n = 10);
void DisplaySystem(System& system, WINDOW* window);
void DisplayProcesses(std::vector<Process>& processes, WINDOW* window, int n);
std::string ProgressBar(float percent);
};  // namespace NCursesDisplay

#endif
