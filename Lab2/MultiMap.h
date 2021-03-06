#pragma once
#include<vector>
#include<utility>
//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -11111;
#define NULL_TELEM pair<int,int>(-11111, -11111);
class MultiMapIterator;
//class ZusatzIterator;

struct DLLNode
{
	DLLNode* prev;	//Adresse des Vorgangers
	DLLNode* next;	//Adress des Nachfolgers
	TElem info;		//die eigentliche Daten
};

struct DLL
{
	DLLNode* header;	//die Adresse des ersten Konten
	DLLNode* tail;		//die Adresse des letzten Konten
};

class MultiMap
{
	friend class MultiMapIterator;
	friend class ZusatzIterator;
private:
	//TODO - Representation

	DLLNode node;
	DLL map;
	int nr_noduri;		//die Anzahl der Knoten

public:
	//constructor
	MultiMap();

	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	//returns an iterator for the multimap
	//ZusatzIterator iteratorZ() const;

	//descturctor
	~MultiMap();


};

