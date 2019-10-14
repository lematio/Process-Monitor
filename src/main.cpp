#include "system.h" // class System
#include "ncurses_display.h" // NCursesDisplay::

int main() {
  System system;
  NCursesDisplay::Display(system);
}
