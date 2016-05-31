#include <iostream>
#include <iomanip>

using namespace std;

string monthNames[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getMonth() {
  int month = -1;
  while(month < 1 || month > 12) {
    cout << "Which month? ";
    cin >> month;
  }
  return month;
}

int getYear() {
  int year = -1;
  while (year < 1753) {
    cout << "Which year? ";
    cin >> year;
  }
  cout << "\n";
  return year;
}

bool isLeapYear(int year) {
  if (year % 400 == 0) {
    return true;
  } else if (year % 100 == 0) {
    return false;
  } else if (year % 4 == 0) {
    return true;
  } else {
    return false;
  }
}

int getDaysInMonth(int month, int year) {
  return (month == 2 && isLeapYear(year))
    ? daysInMonth[month - 1] + 1
    : daysInMonth[month - 1];
}

int getOffset(int month, int year) {
  int daysSince = 0;

  for (int i = 1753; i < year; ++i) {
    daysSince += isLeapYear(i)
      ? 366
      : 365;
  }

  for (int i = 1; i < month; ++i) {
    daysSince += getDaysInMonth(i, year);
  }

  return daysSince % 7;
}

void displayHeader(int month, int year) {
  cout << " " << monthNames[month - 1] << " " << year << "\n";
  cout << " Su  Mo  Tu  We  Th  Fr  Sa\n";
}

// NOTE: 1st day in 1753, start of Gregorian cal, is a Monday; offset 6 = Sun
int getBlanksCount(int offset) {
  return offset == 6
    ? 0
    : offset + 1;
}

void displayBlanks(int blanksCount) {
  for (int i = 0; i < blanksCount; ++i) {
    cout << "    ";
  }
}

int displayFirstWeek(int blanksCount) {
  int day = 0;
  for (int i = 0; i < (7 - blanksCount); ++i) {
    cout << setw(4) << ++day;
  }
  cout << "\n";
  return day;
}

void displayRemainingDays(int day, int daysInMonth) {
  while (day < daysInMonth) {
    for (int i = 0; i < 7 && day < daysInMonth; ++i) {
      cout << setw(4) << ++day; 
    }
    cout << "\n";
  }
}

void displayDays(int offset, int daysInMonth) {
  int blanksCount = getBlanksCount(offset);
  displayBlanks(blanksCount);
  int day = displayFirstWeek(blanksCount);
  displayRemainingDays(day, daysInMonth);
}

void displayCalendar(int month, int year, int offset, int daysInMonth) {
  displayHeader(month, year);
  displayDays(offset, daysInMonth);
}

int main() {
  int month = getMonth(); 
  int year = getYear(); 
  displayCalendar(month, year, getOffset(month, year), getDaysInMonth(month, year));
}
