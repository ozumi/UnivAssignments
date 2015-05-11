#ifndef WORDFREQUENCY_H
#define WORDFREQUENCY_H

#include "map.h"
#include <iostream>

/** 
 * Assignment 6 for CSE231 Data Structures
 *
 * 2014. 1. 16

 */

typedef MapElem<std::string, int> WordFreqElem;
typedef HashMap<WordFreqElem> WordFreqMap;

// WORDFREQUENCY class
class WordFrequency {
public:
	WordFrequency();
	~WordFrequency();
	
	void ReadText(const char* filename);
		
	int GetFrequency(const std::string word);
	
	void IncreaseFrequency(const std::string word);
	
	void PrintAllFrequency()
	{
		map.print();
	}
	//
private:
	
	WordFreqMap map;
};

#endif
