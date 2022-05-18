#include "File.h"

File::File(){
  m_FileName = "NULL";
  m_FileType = "NULL";
  m_FileSize = 0;
}

File::File(string fileName, string fileType, int fileSize){
  m_FileName = fileName;
  m_FileType = fileType;
  m_FileSize = fileSize;
}

string File::GetFileName(){
  return m_FileName;
}

string File::GetFileType(){
  return m_FileType;
}

int File::GetFileSize(){
  return m_FileSize;
}

void File::SetFileName(string fileName){
  m_FileName = fileName;
}

void File::SetFileType(string fileType){
  m_FileType = fileType;
}

void File::SetFileSize(int size){
  m_FileSize = size;
}

void File::PrintFile(){
  cout << "File Name: " << m_FileName;
  cout << "File Type: " << m_FileType;
  cout << "File Size: " << m_FileSize;
}
