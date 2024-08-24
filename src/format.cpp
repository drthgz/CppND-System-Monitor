#include "format.h"

#include <iomanip>
#include <sstream>
#include <string>

using std::string;

// Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
  int hours = seconds / 3600;
  seconds = seconds % 3600;
  int minutes = seconds / 60;
  seconds = seconds % 60;

  // Formatting to ensure two digits for hours, minutes, and seconds
  std::ostringstream timeStream;
  timeStream << std::setw(2) << std::setfill('0') << hours << ":"
             << std::setw(2) << std::setfill('0') << minutes << ":"
             << std::setw(2) << std::setfill('0') << seconds;

  return timeStream.str();
}