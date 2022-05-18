#include "File.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void populateDirectory(vector<File>&);
// fill vector - fills file info
// @param vector<File>& - files in directory
void printDirectory(vector<File>&);
//printDirectory - prints the information of the files in the directory
//@param const vector<File>& files in directory 

int main () {
	//Creates a new directory of files
  vector<File> myDirectory;
	//Populates the vector
  populateDirectory(myDirectory);
  //Prints the contents of the vector
  printDirectory(myDirectory);
  return 0;
}

void populateDirectory(vector<File>& newDirectory) {
  
  //Write this function
  //Needs to ask how many files
  //Gets file name, file type, and file size
  //Uses the overloaded constructor for the file
  //Needs to add files to the directory vector
  int numFiles;
  cout << "How many files are there?: ";
  cin >> numFiles;

  string fileName;
  string type;
  File temp;

  for(int i=0; i<numFiles; i++){
    cout << "What is the file's name?: " << endl;
    cin >> fileName;
    temp.SetFileName(fileName);

    cout << "What is the file's type?: " << endl;
    cin >> type;
    temp.SetFileType(type);

    cout << "The size of this file is " << i <<".\n" << endl;
    temp.SetFileSize(i);

    newDirectory.push_back(temp);
  }

//test

}

void printDirectory(vector<File>& newMyFile){
  //Needs to loop through the directory of files and outputs the information
  for(int i=0; i<newMyFile.size(); i++){
    newMyFile.at(i).PrintFile();
  }
}
