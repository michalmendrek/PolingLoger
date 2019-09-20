#include <LogModule.h>
#include <iostream>
#include <string>

using namespace std;

void func(std::string data) { cout << data << endl; }

int main() {
  LogModule Loger;
  Loger.AddModule("Module1", "/var/log/");
  Loger.AddModule("Module2", "/var/log/");
  string Out1, Out2, Err1, Err2;
  //Loger.ForEachModule(func);

    if (Loger.GetNLinesOfLogByName("Module1", Err1, Out1, 20)) {
      cout << "Out1:" << endl << Out1 << endl;
      cout << "Err1:" << endl << Err1 << endl;
    }



  while (1) {
    if (Loger.GetNewDataFromModuleByName("Module1", Err1, Out1)) {
      cout << "Out1:" << endl << Out1 << endl;
      cout << "Err1:" << endl << Err1 << endl;
    }

    if (Loger.GetNewDataFromModuleByName("Module2", Err2, Out2)) {
      cout << "Out2:" << endl << Out2 << endl;
      cout << "Err2:" << endl << Err2 << endl;
    }
  }
}
