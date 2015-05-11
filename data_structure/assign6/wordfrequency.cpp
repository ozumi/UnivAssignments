#include "wordfrequency.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
/** 
 * Assignment 6 for CSE231 Data Structures
 *
 * 2014. 1. 16
 *
 */

WordFrequency::WordFrequency()
{
	
}

WordFrequency::~WordFrequency()
{
	
}

void WordFrequency::ReadText(const char* filename)
{
	ifstream is(filename);

	is.seekg(0, std::ios::end);
	long length = is.tellg();
	is.seekg(0, std::ios::beg);
	char *buffer = new char[length];
	is.read(buffer, length);

	for(int i=0; i<length; i++)
	{
		int c = buffer[i];
	
		if(c<=64 || 123<=c || (91<=c && c<=96))
			buffer[i]=' ';
			
	
	}

	istringstream iss(buffer);

	while(iss)
	{
		string sub;
		iss >> sub;
	
		if(sub!="\0")
		{
			cout << "Substring: " << sub << endl;
			transform(sub.begin(), sub.end(), sub.begin(), ::tolower);

			IncreaseFrequency(sub);
		}
		
	}
		
	delete []buffer;
	is.close();
	
}

int WordFrequency::GetFrequency(const std::string word)
{
	if(map.find(word)==NULL)
		return 0;
	else
		return int(map.find(word)->val);
}

void WordFrequency::IncreaseFrequency(const std::string word)
{
	if(map.find(word)==NULL)
		map.insert(word, 1);
	else
	{
		int v = map.find(word)->val;
		map.insert(word, v+1);
	}
}
