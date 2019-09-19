#ifndef LOGMODULE_H
#define LOGMODULE_H
#include <Log.h>
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <tuple>
#include <vector>

class MLlogModule {
 private:
  std::string DirToLog;
  std::vector<
      std::tuple<std::string, std::shared_ptr<MLlog>, std::shared_ptr<MLlog>>>
      LogerContainer;

 public:
  MLlogModule(std::string PathLog);
  ~MLlogModule();
  void AddModule(std::string Name);
  bool GetModuleByName(std::string Name, std::string& Err, std::string& Out);
  bool GetWholeLogByName(std::string Name, std::string& Err, std::string& Out);
  bool GetNLinesOfLogByName(std::string Name, std::string& Err,
                            std::string& Out, int len);
};

#endif
