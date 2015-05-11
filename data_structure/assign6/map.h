#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>

/** 
  * Assignment 6 for CSE231 Data Structures
  *
  * 2014. 1. 16
  *
  */

// Map element
template <class KeyType, class ValType>
class MapElem
{
public:
	typedef KeyType ktype;
	typedef ValType vtype;
	
	KeyType key;
	ValType val;
	
	MapElem* link;
};

bool inline operator==(std::string a, std::string b)
{
	if((a).compare(b) == 0) return true;
	return false;
}

//
// Map data structure
//
template <class HashMapElemType> 
class HashMap
{
public:
	typedef typename HashMapElemType::ktype KeyType;
	typedef typename HashMapElemType::vtype ValType;
	
	// constructor
	HashMap(unsigned int c = 1000);
	
	// destructor
	~HashMap();
	
	// Modify below functions
	int size() { return mapsize; };
	
	bool isEmpty() { return (mapsize == 0); };
	
	// ToDo
	HashMapElemType* find(const KeyType k);
	
	void insert(const KeyType k, const ValType v);
		
	bool remove(const KeyType k);
	
	unsigned int hashfunction(const KeyType k);
	
	void print();
	
private:
	// Hash Table
	HashMapElemType** ht;
	
	unsigned int mapsize, capacity, divisor;
};

#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include "map.txx"
#endif

#endif
