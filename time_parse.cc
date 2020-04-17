//
// Code that parses time data from Twitter.
//
// Note: See here for information about
// tm data : http://www.cplusplus.com/reference/ctime/tm/
//
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <ctime>

using namespace std;

int main() {

  string t1 = "Mon May 04 18:54:25 +0000 2009";
  string t2 = "Thu Jul 11 15:08:23 +0000 2019";
  std::tm my_time;

  istringstream in(t2);

  in >> get_time(&my_time, "%a %b %d %H:%M:%S +0000 %Y");
  //if (strftime(t1.c_str(),t1.length(),"%a %b %d %H:%M:%S %z %Y",&my_time)) {
  //  cout << "Failed!" << endl;
  //}
  if (!in.fail()) {
    cout << my_time.tm_year << endl;
    cout << my_time.tm_mon << endl;
  } else {
    cout << "Failed again!" << endl;
  }
}

  
