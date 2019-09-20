#ifndef LOG_H
#define LOG_H
#include <fstream>
#include <string>

class Log {
 private:
  std::ifstream File;
  ssize_t LastEnd;
  int GetLineNumber();

 public:
  Log(std::string FileName);
  ~Log();
  std::string ReadNewLines();
  std::string ReadNLastLinesOfFile(int num);
  std::string ReadWholeLogFile();
};

#endif
