#include <Log.h>
#include <LogModule.h>

MLlogModule::MLlogModule(std::string PathLog) {
  if (PathLog.size() > 0) {
    DirToLog = PathLog;
  } else {
    std::cout << "Inproper directory!" << std::endl;
  }
}

MLlogModule::~MLlogModule() {}

void MLlogModule::AddModule(std::string Name) {
  LogerContainer.push_back(
      std::make_tuple(Name, std::make_shared<MLlog>(Name + ".err.log"),
                      std::make_shared<MLlog>(Name + ".out.log")));
}

bool MLlogModule::GetModuleByName(std::string Name, std::string& Err,
                                  std::string& Out) {
  for (auto& it : LogerContainer) {
    if (std::get<0>(it) == Name) {
      Err = std::get<1>(it)->ReadNewLines();
      Out = std::get<2>(it)->ReadNewLines();
      if (Err.size()  || Out.size() ) {
        return true;
      }
      return false;
    }
  }
  return false;
}

bool MLlogModule::GetWholeLogByName(std::string Name, std::string& Err,
                                    std::string& Out) {
  for (auto& it : LogerContainer) {
    if (std::get<0>(it) == Name) {
      Err = std::get<1>(it)->ReadWholeLogFile();
      Out = std::get<2>(it)->ReadWholeLogFile();
      if (Err.size() || Out.size()) {
        return true;
      }
      return false;
    }
  }
  return false;
}

bool MLlogModule::GetNLinesOfLogByName(std::string Name, std::string& Err,
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
