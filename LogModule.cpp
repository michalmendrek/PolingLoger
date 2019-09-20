#include <Log.h>
#include <LogModule.h>

LogModule::LogModule() {}

LogModule::~LogModule() {}

void LogModule::AddModule(std::string Name, std::string PathLog) {
  LogerContainer.emplace_back(
      std::make_tuple(Name, std::make_shared<Log>(PathLog + Name + ".err.log"),
                      std::make_shared<Log>(PathLog + Name + ".out.log")));
}

bool LogModule::GetNewDataFromModuleByName(std::string Name, std::string& Err,
                                           std::string& Out) {
  for (auto& it : LogerContainer) {
    if (std::get<0>(it) == Name) {
      Err = std::get<1>(it)->ReadNewLines();
      Out = std::get<2>(it)->ReadNewLines();
      if (Err.size() || Out.size()) {
        return true;
      }
      return false;
    }
  }
  return false;
}

bool LogModule::GetNLinesOfLogByName(std::string Name, std::string& Err,
                                     std::string& Out, int len) {
  for (auto& it : LogerContainer) {
    if (std::get<0>(it) == Name) {
      Err = std::get<1>(it)->ReadNLastLinesOfFile(len);
      Out = std::get<2>(it)->ReadNLastLinesOfFile(len);
      if (Err.size() || Out.size()) {
        return true;
      }
      return false;
    }
  }
  return false;
}

void LogModule::ForEachModule(
    const std::function<void(std::string)>& callback) {
  for (const auto& module : LogerContainer) {
    callback(std::get<0>(module));
  }
}
