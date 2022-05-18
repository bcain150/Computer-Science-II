#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
using namespace std;

class File {
 public:
  //Default Constructor
  File();
  //Overload Constructor
  File(string fileName, string fileType, int fileSize);

  string GetFileName();
  string GetFileType();
  int GetFileSize();

  void SetFileName(string fileName);
  void SetFileType(string fileType);
  void SetFileSize(int fileSize);

  void PrintFile();
 private:
  string m_FileName;
  string m_FileType;
  int m_FileSize;
};

#endif
