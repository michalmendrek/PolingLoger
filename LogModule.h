#ifndef LOGMODULE_H
#define LOGMODULE_H
#include <Log.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <tuple>
#include <vector>

class LogModule {
 private:
  std::vector<
      std::tuple<std::string, std::shared_ptr<Log>, std::shared_ptr<Log>>>
      LogerContainer;

 public:
  LogModule();
  ~LogModule();
  void AddModule(std::string Name, std::string PathLog);
  bool GetNewDataFromModuleByName(std::string Name, std::string& Err,
                                  std::string& Out);
  bool GetNLinesOfLogByName(std::string Name, std::string& Err,
                            std::string& Out, int len);
  void ForEachModule(const std::function<void(std::string)>& callback);
};

#endif
