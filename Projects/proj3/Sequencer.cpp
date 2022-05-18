/********************************************
 ** File:    Sequencer.cpp
 ** Project: CMSC 202 Project 3, Spring 2017
 ** Author:  Brendan Cain
 ** Date:    03/30/17
 ** Section: 16 (lecture) 18 (discussion)
 ** E-mail:  bcain1@umbc.edu
 **
 ** Class implementation for Sequencer.h
 **********************************************/

#include "Sequencer.h"

Sequencer::Sequencer(string fileName){
	m_fileName = fileName;
	m_dna = DNA();
	readFile();
	cout << "New sequencer loaded." << endl;
	mainMenu();

}//end constructor

//
Sequencer::~Sequencer(){
}

//reads in the nucleotides from the text file
void Sequencer::readFile(){
	//opens file.
	fstream readIn;
	char insert;
	//loop while there is still an input
	do{
		//reads in and adds to linked lists.
		readIn >> insert;
		m_dna.InsertEnd(insert);
	}while(!readIn.eof()); //while there is still something left to read in
	readIn.close();
}//end ReadFile

//displays main menu and executes what the user wishes to do
void Sequencer::mainMenu(){
	const int EXIT = 5;
	int choice;
	do{
		//gets the users choice
		cout << "What would you like to do?:" << endl;
		cout << "1. Display Sequencer (Leading Strand)" << endl;
		cout << "2. Display Sequencer (Base Pairs)" << endl;
		cout << "3. Inventory Basic Amino Acids" << endl;
		cout << "4. Sequence Entire DNA Strand" << endl;
		cout << "5. Exit" << endl;
		cin >> choice;

		switch(choice){
			case 1://Display Strand
			case 2://Display Base Pairs
				m_dna.Display(choice);
			break;

			case 3://Inventory Acids
				m_dna.NumAmino("Tryptophan", "TGG");
				m_dna.NumAmino("Phenylalanine", "TTT");
			break;

			case 4://Sequence Entire DNA Strand
				m_dna.Sequence();
			break;

			case 5://Exit
				cout << "DNA removed from memory" << endl;
			break;

			default://this causes a repromt if the user enters somthing other than 1-5
			break;
		}//end switch
	}while(choice!=EXIT);
}//end mainMenu
