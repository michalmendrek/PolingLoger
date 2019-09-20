#include <LogModule.h>
#include <iostream>
#include <string>

using namespace std;

int main() {


  MLlogModule Loger("./");
  Loger.AddModule("Module1");
  Loger.AddModule("Module2");
  string Out1, Out2, Err1, Err2;

  if (Loger.GetWholeLogByName("Module1", Err1, Out1)) {
    cout << "Out1:" << endl << Out1 << endl;
    cout << "Err1:" << endl << Err1 << endl;
  }


  if (Loger.GetWholeLogByName("Module2", Err2, Out2)) {
    cout << "Out2:" << endl << Out2 << endl;
    cout << "Err2:" << endl << Err2 << endl;
  }

  while (1) {
 
  if (Loger.GetModuleByName("Module1", Err1, Out1)) {
      cout << "Out1:" << endl << Out1 << endl;
      cout << "Err1:" << endl << Err1 << endl;
      //Out1.clear();
     // Err1.clear();
    }

    if (Loger.GetModuleByName("Module2", Err2, Out2)) {
      cout << "Out2:" << endl << Out2 << endl;
      cout << "Err2:" << endl << Err2 << endl;
      //Out2.clear();
      //Err1.clear();
    }
    //getchar();
  }
}
