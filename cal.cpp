#include <iostream>

using namespace std;

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
  return year;
}

int main() {
  int mon = getMonth(); 
  int year = getYear(); 
  cout << "Month: ";
  cout << mon;
  cout << "\n";
  cout << "Year: ";
  cout << year;
  cout << "\n";
}
