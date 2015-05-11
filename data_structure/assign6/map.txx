#include <string>
#include <math.h>
using std::string;

// Constructor
template <class HashMapElemType>
HashMap<HashMapElemType>::HashMap(unsigned int c) 
{
	mapsize = 0;
	capacity = c;
	divisor = c - (1-c%2); // biggest odd number smaller than c
	ht = new HashMapElemType* [capacity];
	for(int i=0; i<capacity; i++) ht[i] = NULL;
}


// destructor
template <class HashMapElemType>
HashMap<HashMapElemType>::~HashMap() 
{
	delete [] ht;
}
	
template <class HashMapElemType>
HashMapElemType* 
HashMap<HashMapElemType>::find(const KeyType k) 
{ 
	int i = hashfunction(k);

	HashMapElemType * current = ht[i];
	
	if(current == NULL)
		return NULL;

	do
	{
		if(current->key == k)
			return current; //&current->key;
		current=current->link;

	}while(current!=NULL);

	return NULL;
}
	
template <class HashMapElemType>
void 
HashMap<HashMapElemType>::insert(const KeyType k, const ValType v) 
{
	HashMapElemType *here = new HashMapElemType;
	here->key=k;
	here->val=v;
        here->link = NULL;
	unsigned int i = hashfunction(k);
	HashMapElemType * current = ht[i];

	if(find(k)==NULL)
	{
		if(current==NULL)
			ht[i]=here;
		else{
		while(current->link!=NULL)
			current=current->link;


		current->link = here;		
		}
		mapsize++;
	}
	else
		find(k)->val=v;

}
		
template <class HashMapElemType>
bool 
HashMap<HashMapElemType>::remove(const KeyType k) 
{
	int i=hashfunction(k);
	HashMapElemType *curr = ht[i];
	HashMapElemType *prev = curr;

	if(find(k)!=NULL)
	{
		for(; curr != NULL; curr = curr->link)
		{
			if(curr->key==k)
			{
				if(curr==ht[i])
					ht[i]=curr->link;
				else
					prev->link = curr->link;
			}
			prev = curr;
		}
		mapsize--;		
		return true;
	}
	else
		return false;
}
	

template <class HashMapElemType>
unsigned int 
HashMap<HashMapElemType>::hashfunction(const KeyType k)
{
	unsigned int answer = convert(k);

	unsigned int a = answer%divisor;
		return a;
}


inline unsigned int convert(const string k)
{
        unsigned int answer = 0;
        string b=k;
        int length = (int)b.length();
        if(length%2==1)
        {
                answer=b.at(length-1);
                length--;
        }
        for(int i=0; i<length; i+=2)
        {
                answer+=b.at(i);
                answer+=((int)b.at(i+1))<<8;
        }

	return answer;
}

inline unsigned int convert(const double k)
{
	double b;
	unsigned int answer = 0;
	b = floor(k+0.5);
	answer = static_cast<int>(b);
	return answer;
}

inline unsigned int convert(const int k)
{
	unsigned int answer = k;
	return answer;
}

template <class HashMapElemType>
void 
HashMap<HashMapElemType>::print()
{
	HashMapElemType *list = new HashMapElemType[mapsize];
	HashMapElemType *curr = ht[0];
	HashMapElemType *temp;

	for(int i=0, j=0, k=0; i<mapsize; i++)
	{
		k=i;
		while(curr == NULL)
			curr=ht[++j];
		
//sorting
		if(i==0)
			list[i]=*curr;
		else
		{
			while(curr->val > list[k-1].val)
			{	list[k]=list[k-1];
				k--;
			}
			list[k]=*curr;
		}

		curr = curr->link;
	}

	for(int i=0; i<mapsize; i++)
		std::cout << list[i].key << ":" << list[i].val << std::endl;

}
