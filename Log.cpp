#include <Log.h>
#include <iostream>

MLlog::MLlog(std::string FileName) {
  File.open(FileName, std::fstream::in);
  if (File.is_open()) {
    File.seekg(0, std::ios::end);
    LastEnd = File.tellg();
    File.seekg(0, std::ios::beg);
  }
}

MLlog::~MLlog() { File.close(); }

std::string MLlog::ReadNewLines() {
  ssize_t NewEnd(0);
  ssize_t OldEnd(0);
  ssize_t DiffEnd(0);
  std::string DataFromFile;

  if (File.is_open()) {
    File.clear();
    File.seekg(0, std::ios::beg);
    File.seekg(0, std::ios::end);
    NewEnd = File.tellg();
    DiffEnd = NewEnd - LastEnd;

    if (DiffEnd > 0) {
      //std::cout << "File has new data" << std::endl;
      //std::cout << "Length of new data : " << DiffEnd << std::endl;
      File.seekg(-DiffEnd, std::ios::end);
      char *array = new char[DiffEnd];
      File.read(array, DiffEnd);
      std::string Output(array);
      delete []array;
      DataFromFile = Output;

    } else {
      //std::cout << "No new data" << std::endl;
      DataFromFile.clear();
    }
    LastEnd = NewEnd;
  }

  return DataFromFile;
}

std::string MLlog::ReadNLastLinesOfFile(int num) {
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

int MLlog::GetLineNumber() {
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

std::string MLlog::ReadWholeLogFile() {
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
