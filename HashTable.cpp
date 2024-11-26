#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <conio.h>
#include "Data.h"
#include "HashTable.h"
   using namespace std;


HashTable * initHashTable (int sizeTable) {

	return NULL;
}



HashTable * initHashTableFromFile (int sizeTable, char fileName[]) {

	ifstream inputFile;
	ofstream outputFile;

	Movie movie;
	int numMovies;
	
	HashTable * ht = initHashTable(sizeTable);	
	
	inputFile.open(fileName);
	
	if (!inputFile.is_open()) {
		cout << "Input file " << fileName << " could not be opened. Aborting ..." << endl;
		return ht;
	}
	
	numMovies = 0;
	inputFile >> movie.ID;
	
	while (movie.ID != "END") {
		inputFile >> movie.yearReleased >> movie.duration >> movie.genre >> ws;
		getline (inputFile, movie.title);
		numMovies++;

		insertHT (ht, movie);
		inputFile >> movie.ID;
	}

	inputFile.close();
	
	cout << numMovies << " movies read from " << fileName << " and stored in hash table." << endl;
	
	return ht;
}



int containsHT (HashTable * ht, string key) {
	
	return -1;
}



void displayMovie (Movie movie) {
	
	cout << "ID:              " << movie.ID << endl;
	cout << "TITLE:           " << movie.title << endl;
	cout << "YEAR RELEASED:   " << movie.yearReleased << endl;
	cout << "DURATION:        " << movie.duration << endl;
	cout << "GENRE:           " << movie.genre << endl;
	cout << endl;	
}



void displayMovieHT (HashTable * ht, string key) {

	return;
}


	
int lengthChain (HashTable * ht, int location) {
	
	//is the location valid
	if (location < 0 || location >= ht->sizeTable){
		cout << "Invalid Location" << location << endl;
		return -1;
	}
	
	//Go through the LL and count the nodes
	int count = 0;
	LLNode *current = ht->elements[location];
	while (current != NULL){
		count++;
		current = current->next;
		
	}
	
	return count;
}



LLNode * createNode (Movie movie) {
	LLNode * newNode;
	
	newNode = new LLNode;
	
	newNode->data = movie;
	newNode->next = NULL;
	
	return newNode;
}



void insertHT (HashTable * ht, Movie movie) {
	
	//Work out the hash for the movie ID
	string key = movie.ID;
	int hashValue = 0;
	for (int i = 0; i < key.length(); ++i) {
		char c = key[i];
		hashValue = (hashValue * 31 + c) % ht->sizeTable;
	}
	
	int location = hashValue;
	
	//is the movie in the hash table
	LLNode *current = ht->elements[location];
	while(current != NULL){
		if(current->data.ID == movie.ID){
			cout << "Movie with ID " << movie.ID << " already exists in hash table." << endl;
			return;
		}
		current = current->next;
	}
	
	//make a node and insert it into the LL
	LLNode *newNode = new LLNode;
	newNode->data = movie;
	newNode->next = ht->elements[location];
	ht->elements[location] = newNode;
	
	cout << "Movie with ID " << movie.ID << " inserted in hash table at location " << location << "." << endl;
}




void statisticsHT(HashTable *ht) {
    int filled = 0, empty = 0, maxChainLength = 0;
    for (int i = 0; i < ht->sizeTable; ++i) {
        if (ht->elements[i] == NULL) {
            empty++;
        } else {
            filled++;
            int chainLength = 0;
            LLNode *curr = ht->elements[i];
            while (curr != NULL) {
                chainLength++;
                curr = curr->next;
            }
            maxChainLength = std::max(maxChainLength, chainLength);
        }
    }

    std::cout << "Number of filled locations: " << filled << std::endl;
    std::cout << "Number of empty locations: " << empty << std::endl;
    std::cout << "Length of the longest chain: " << maxChainLength << std::endl;
}




void deleteHT (HashTable * ht, string key) {
	return;
}
	
