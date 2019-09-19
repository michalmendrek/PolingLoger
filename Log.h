#ifndef LOG_H
#define LOG_H
#include <fstream>
#include <string>

class MLlog {
 private:
  std::ifstream File;
  ssize_t LastEnd;
   int GetLineNumber();
 public:
  MLlog(std::string FileName);
  ~MLlog();
  std::string ReadNewLines();
  std::string ReadNLastLinesOfFile(int num);
  std::string ReadWholeLogFile();
};

#endif
