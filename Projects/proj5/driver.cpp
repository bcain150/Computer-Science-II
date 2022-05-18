//Title: driver.cpp
//Author: Jeremy Dixon
//Date: 4/29/2017
//Description: Driver for project 5 in CMSC 202 - Spring 2017

#include "ReadyDelivery.h"
#include "ManageDelivery.h"

void title();

int main(int argc, char* argv[]) {
  title();
  if (argc < 3) //Checks to see if the project call has any arguments
    {
      cout << "You must include three files to run the program. " << endl;
      cout << "File 1 should be a file of trucks. " << endl;
      cout << "File 2 should be a file of deliveries. " << endl;
      cout << "File 3 should be a file of items. " << endl;
    }
  else
    {
      ReadyDelivery R = ReadyDelivery(argv[1],argv[2],argv[3]); //Populates all vectors
      ManageDelivery M = ManageDelivery(R.GetTruck(), R.GetDelivery(), R.GetItem()); 
    }
  return 0;
}

void title() {
  cout << endl;
  cout << "TTT H H EEE  GGGGG  RRRR   OOOOO   CCCC  EEEEE  RRRR " << endl;
  cout << " T  H H E    G      R   R  O   O  C      E      R   R" << endl;
  cout << " T  HHH EEE  G  GG  RRRR   O   O  C      EEEEE  RRRR " << endl;
  cout << " T  H H E    G   G  R   R  O   O  C      E      R   R" << endl;
  cout << " T  H H EEE  GGGGG  R   R  OOOOO   CCCC  EEEEE  R   R" << endl << endl;
}
