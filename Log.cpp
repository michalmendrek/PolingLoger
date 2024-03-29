#include <Log.h>
#include <iostream>


Log::Log(std::string FileName) {
  File.open(FileName, std::fstream::in);
  if (File.is_open()) {
    File.seekg(0, std::ios::end);
    LastEnd = File.tellg();
    File.seekg(0, std::ios::beg);
  }
}

Log::~Log() { File.close(); }

ssize_t Log::GetLastEndFullLineAproach()
{
  unsigned int number(0);
  ssize_t LastPos(0);
  std::string unused;
  if (File.is_open()) {
    File.seekg(0, std::ios::beg);
    while (std::getline(File, unused)) {
      ++number;
    }
    File.clear();
    LastPos=File.tellg();
    File.clear();
    File.seekg(0, std::ios::beg);
  }
  return LastPos;

}

std::string Log::ReadNewLines() {
  ssize_t NewEnd(0);
  ssize_t OldEnd(0);
  ssize_t DiffEnd(0);
  std::string DataFromFile;
  std::string LineOfData;
  if (File.is_open()) {
    File.clear();
    File.seekg(0, std::ios::beg);
    NewEnd = GetLastEndFullLineAproach();
    DiffEnd = NewEnd - LastEnd;

    if (DiffEnd > 0) {
      File.seekg(-DiffEnd, std::ios::end);
      while (std::getline(File, LineOfData)){
      DataFromFile+=LineOfData;
     }

    } else {
      DataFromFile.clear();
    }
    LastEnd = NewEnd;
  }

  return DataFromFile;
}

std::string Log::ReadNLastLinesOfFile(int num) {
  int LineNumber = GetLineNumber();
  std::cout << "Len of total file: " << LineNumber << std::endl;
  int tmp(0);
  std::string unused;
  std::string out_string;
  if (File.is_open()) {
    while (std::getline(File, unused)) {
      ++tmp;
      if (tmp > (LineNumber - num)) {
        out_string += unused + "\n";
      }
    }
    File.seekg(0, std::ios::beg);
  }
  return out_string;
}

int Log::GetLineNumber() {
  int number(0);
  std::string unused;
  if (File.is_open()) {
    File.seekg(0, std::ios::beg);
    while (std::getline(File, unused)) {
      ++number;
    }
    File.clear();
    File.seekg(0, std::ios::beg);
  }
  return number;
}

std::string Log::ReadWholeLogFile() {
  std::string OutputData;
  std::string LineOfData;
  if (File.is_open()) {
    while (std::getline(File, LineOfData)) {
      OutputData += LineOfData + "\n";
    }
    File.clear();
    File.seekg(0, std::ios::beg);
  }

  return OutputData;
}
