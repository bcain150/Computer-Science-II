/********************************************
 ** File:    DNA.cpp
 ** Project: CMSC 202 Project 3, Spring 2017
 ** Author:  Brendan Cain
 ** Date:    03/28/17
 ** Section: 16 (lecture) 18 (discussion)
 ** E-mail:  bcain1@umbc.edu
 **
 ** The Link List Class for a DNA strand.
 **********************************************/
#include "DNA.h"

//Helper method for Display
//takes in a Nucleotide and then outputs its compliment pair.
char getPair(char c);

//Constructor
DNA::DNA(){
	m_head = NULL;
	m_tail = NULL;
	m_size = 0;
}//end DNA

//Destructor
DNA::~DNA(){
	Clear();
	delete m_tail;
	m_head = NULL;
	m_tail = NULL;
}//end ~DNA

//inserts a node at the end of the DNA strand
void DNA::InsertEnd(char payload){
	Nucleotide *temp = m_head;
	Nucleotide *curr = temp;
	//loops through Linked list
	while(temp != NULL){
		curr = temp;
		temp = temp -> m_next;
	}
	//adds to end unless the head is null
	if(!IsEmpty()){
		temp = new Nucleotide;
		temp -> m_payload = payload;
		cout << temp -> m_payload << endl;
		temp -> m_next = m_tail;
		//updates pointer of now second to last element and the list's size
		curr -> m_next = temp;
	}
	//starts the linked list
	else{
		m_head = new Nucleotide;
		m_head -> m_payload = payload;
		cout << m_head -> m_payload << endl;
		m_head -> m_next = m_tail;
	}
}//end InsertEnd

//Displays nucleotides or base pairs depending on numStrand
void DNA::Display(int numStrand){
	cout << "Base Pairs: " << endl;
	Nucleotide *temp = m_head;
	Nucleotide *curr;
	switch(numStrand){
		//displays a single strand
		case 1:
			for(int i=0; i<m_size; i++){
				curr = temp;
				cout << curr -> m_payload << endl;
				temp = curr -> m_next;
			}//end for
			//Displays end and the number of nucleotides and trinucleotides
			cout << "END" << endl;
			cout << m_size << " nucleotides listed." << endl;
			//divided by 3 because of TRInucleotides.
			cout << m_size/TRINUCLEOTIDE_SIZE << " trinucleotides listed." << endl;
		break;

		//displays both strands
		case 2:
			for(int i=0; i<m_size; i++){
				curr = temp;
				cout << curr -> m_payload << "-" << getPair(curr -> m_payload) << endl;
				temp = curr -> m_next;
			}
			//Displays end and the number of nucleotides and trinucleotides
			cout << "END" << endl;
			cout << m_size << " base pairs listed." << endl;
			//divided by 3 because of TRInucleotides.
			cout << m_size/3 << " trinucleotides listed." << endl;
		break;
	}//end switch case
	//update size
	SizeOf();
}//end Display

//Helper method for Display
char getPair(char c){
	if(c=='C')
		return 'G';
	else if(c=='G')
		return 'C';
	else if (c=='A')
		return 'T';
	else if (c=='T')
		return 'A';
	else
		return '?';
}//end getPair

//takes in an amino acid name and its trinucleotide
//displays how frequent it occurs in the DNA strand.
void DNA::NumAmino(string name, string trinucleotide){
	int triCount = 0;//keeps track of trinucleotide occurences.
	cout << trinucleotide << endl;
	string triNuc;
	Nucleotide *temp = m_head;
	Nucleotide *minusTwo;
	Nucleotide *minusOne;
	Nucleotide *curr;
	
	for(int i=0; i<m_size/TRINUCLEOTIDE_SIZE; i++){
		//initiates the pointers to three sequential nodes 
		minusTwo = temp;
		minusOne = temp -> m_next;
		curr = (temp -> m_next) -> m_next;
		//if the trinucleotide matches the inputed one.
		triNuc = (minusTwo -> m_payload) + (minusOne -> m_payload) + (curr -> m_payload);
		if(triNuc == trinucleotide)
			triCount++;
		//change temp 
		temp = curr -> m_next;
	}while(temp != NULL);
	//display the frequency of Amino Acid
	cout << name << ": " << triCount << " identified" << endl;
}// end NumAmino

//goes through the nucleotides, looks at tri nucleotides, finds their respective amino acids
//prints out the sequenced list of amino acids. and how many there are.
void DNA::Sequence(){
	int memSize = m_size/TRINUCLEOTIDE_SIZE; // initializes the maximum size of the amino acid list to be 1/3 of the nucleotide list
	// ^^^ this is also the dynamic arrays size in memory
	int actualSize = 0; //the actual size shows how many amino acids are currently in the sequence
	int numAcids = 0; // shows the number of unique amino acids

	string *acidList = new string[memSize];
	Nucleotide *temp = m_head;
	Nucleotide *minusTwo;
	Nucleotide *minusOne;
	Nucleotide *curr;
	string triNuc;
	string name;
	bool hasAcid = false;
	
	for(int i=0; i<memSize; i++){
		//initiates the pointers to three sequential nodes 
		minusTwo = temp;
		minusOne = temp -> m_next;
		curr = (temp -> m_next) -> m_next;
		//creates the trinucleotide and translates it to an amino acid.
		triNuc = minusTwo -> m_payload + minusOne -> m_payload + curr -> m_payload;
		name = Translate(triNuc);
		//Checks the list to see if the amino acid we are looking at is already in it.
		for(int i=0; i<actualSize; i++){
			if(acidList[i] == name)
				hasAcid = true;
		}// end for
		//add to number of unique acids
		if(!hasAcid)
			numAcids++;
		//updates and resizes array.
		acidList[memSize] = name;
		actualSize++;
		//resets hasAcid and changes temp
		hasAcid = false;
		temp = curr -> m_next;
	}//end for
	//displays acid list
	cout << "Acid List:" << endl;
	for(int i=0; i<actualSize; i++){
		cout << acidList[i] << endl;
		cout << "Total amino acids identified: " << numAcids << endl;
	}//end for
	delete [] acidList;
	acidList = NULL;
}// end Sequence

//returns true if m_head = NULL
bool DNA::IsEmpty(){
	if(m_head == NULL)
		return true;
	else
		return false;
}//end IsEmpty

void DNA::SizeOf(){
	Nucleotide *curr = m_head;
	int count = 0;
	while(curr != NULL){
		curr = curr -> m_next;
		count++;
	}//end while
	m_size = count;
}//end SizeOf

void DNA::Clear(){
	//m_size will be changing so we need to keep track of original
	Nucleotide *curr;
	Nucleotide *temp;	
	int size = m_size;
	for(int i=0; i<size; i++){
		curr = m_head;
		temp = m_head;
		while(temp != NULL){
			curr = temp;
			temp = curr -> m_next;
		}//end while
		delete curr;
		curr = NULL;
	}//end for
}//end Clear

//Given
string DNA::Translate(const string trinucleotide){
  if((trinucleotide=="ATT")||(trinucleotide=="ATC")||(trinucleotide=="ATA"))
    return ("Isoleucine");
  else if((trinucleotide=="CTT")||(trinucleotide=="CTC")||(trinucleotide=="CTA")||
	  (trinucleotide=="CTG")|| (trinucleotide=="TTA")||(trinucleotide=="TTG"))
    return ("Leucine");
  else if((trinucleotide=="GTT")||(trinucleotide=="GTC")||
	  (trinucleotide=="GTA")||(trinucleotide=="GTG"))
    return ("Valine");
  else if((trinucleotide=="TTT")||(trinucleotide=="TTC"))
    return ("Phenylalanine");
  else if((trinucleotide=="ATG"))
    return ("Methionine");
  else if((trinucleotide=="TGT")||(trinucleotide=="TGC"))
    return ("Cysteine");
  else if((trinucleotide=="GCT")||(trinucleotide=="GCC")||
	  (trinucleotide=="GCA")||(trinucleotide=="GCG"))
    return ("Alanine");
  else if((trinucleotide=="GGT")||(trinucleotide=="GGC")||
	  (trinucleotide=="GGA")||(trinucleotide=="GGG"))
    return ("Glycine");
  else if((trinucleotide=="CCT")||(trinucleotide=="CCC")||
	  (trinucleotide=="CCA")||(trinucleotide=="CCG"))
    return ("Proline");
  else if((trinucleotide=="ACT")||(trinucleotide=="ACC")||
	  (trinucleotide=="ACA")||(trinucleotide=="ACG"))
    return ("Threonine");
  else if((trinucleotide=="TCT")||(trinucleotide=="TCC")||
	  (trinucleotide=="TCA")||(trinucleotide=="TCG")||
	  (trinucleotide=="AGT")||(trinucleotide=="AGC"))
    return ("Serine");
  else if((trinucleotide=="TAT")||(trinucleotide=="TAC"))
    return ("Tyrosine");
  else if((trinucleotide=="TGG"))
    return ("Tryptophan");
  else if((trinucleotide=="CAA")||(trinucleotide=="CAG"))
    return ("Glutamine");
  else if((trinucleotide=="AAT")||(trinucleotide=="AAC"))
    return ("Asparagine");
  else if((trinucleotide=="CAT")||(trinucleotide=="CAC"))
    return ("Histidine");
  else if((trinucleotide=="GAA")||(trinucleotide=="GAG"))
    return ("Glutamic acid");
  else if((trinucleotide=="GAT")||(trinucleotide=="GAC"))
    return ("Aspartic acid");
  else if((trinucleotide=="AAA")||(trinucleotide=="AAG"))
    return ("Lysine");
  else if((trinucleotide=="CGT")||(trinucleotide=="CGC")||(trinucleotide=="CGA")||
	  (trinucleotide=="CGG")||(trinucleotide=="AGA")||(trinucleotide=="AGG"))
    return ("Arginine");
  else if((trinucleotide=="TAA")||(trinucleotide=="TAG")||(trinucleotide=="TGA"))
    return ("Stop");
  else
    cout << "returning unknown" << endl;
  return ("Unknown");
}