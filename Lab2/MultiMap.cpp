#include "MultiMap.h"
#include "MultiMapIterator.h"
//#include "ZusatzIterator.h"
#include <exception>
#include <iostream>

using namespace std;
//Gewohnlich Θ(1) ist nur wenn nur elementar Operationen sind.


//Komplexitat: 
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
MultiMap::MultiMap() {
	
	//DLLNode* new_node = new DLLNode;
	//new_node->info= NULL_TELEM;
	//new_node->prev = NULL;
	//new_node->next = NULL;
	map.header=NULL;
	map.tail=NULL;
	nr_noduri = 0; 
}

//Komplexitat: 
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
void MultiMap::add(TKey c, TValue v) {
	
	DLLNode* new_node = new DLLNode;
	new_node->info = pair <TKey, TValue>(c, v);		//es erzeugt man das neue Knoten

	if (isEmpty() == true) {			//wenn  die Liste leer ist, dann erzeugt man das erste Knoten
		new_node->prev = NULL;
		new_node->next =NULL ;
		map.header = new_node;
		map.tail = map.header;
		nr_noduri++;	//die Anzahl der Knoten wachst
	}
	else {								//sonst, fugt man am Ende der Liste das neue Knoten
		new_node->next = NULL;
		map.tail->next= new_node;
		new_node->prev = map.tail;
		map.tail = new_node;
		nr_noduri++;	//die Anzahl der Knoten wachst
	}
}

//Komplexitat: weil immer wird deer While durchgefuhrt
//best case: O(1)
//worst case: O(n)
//avg case: O(n)
bool MultiMap::remove(TKey c, TValue v) {	
	
	DLLNode* index = map.header;	//man verwendet index damit man die Liste durchquert
	if (isEmpty() == false) {			//wenn die Liste nicht leer ist sucht man der Knoten in der Liste
		 //das wird durchgequert nur wenn in der Liste 1 Knoten mit der gesuchte Info ist
		if (map.tail == map.header && index->info == pair<TKey, TValue>(c, v)) {		//**Komplexitat: Θ(1)
			DLLNode* kill = index;			//diesen Koten wird dann geloscht
			map.header = NULL;
			map.tail = NULL;
			delete kill;
			nr_noduri--;	//die Anzahl der Knoten wird kleiner
			return true;
		}

		while (index != NULL) {//man durchquert die Liste um den Konten zi finden       //**Komplexitat: O(n)
			if (index->info == pair<TKey, TValue>(c, v))
				if (index == map.tail) {      	//wenn es sich am Ende der Liste befindet
					DLLNode* kill = index;
					map.tail = index->prev;		//Tail wird der vorletzte Knoten sein
					index->prev->next= NULL;
					//delete kill;  das ist kommentiert weil ich eine Error bekomme
					nr_noduri--;	//die Anzahl der Knoten wird kleiner
					return true;
				}
				else if (index == map.header) { //wenn es sich am Amfang der Liste befindet 
					DLLNode* kill = index;
					map.header = index->next;		//Header wird der zweite Knoten sein
					index->next->prev = NULL;
					delete kill;
					nr_noduri--;	//die Anzahl der Knoten wird kleiner
					return true;
				}
				else {						   //wenn es sich im Inneren der Liste befindet 
					DLLNode* kill = index;
					index->prev->next = index->next;	//der vorrige Knoten verbindet sich mit der Nachfolger
					index->next->prev = index->prev;
					delete kill;
					nr_noduri--;	//die Anzahl der Knoten wird kleiner
					return true;
				}
			index = index->next;
		}
		return false;
	}
	delete index;		//man wird der Speicherplatz geleert
	return  false;
}


//Komplexitat: weil immer wird deer While durchgefuhrt
//best case: O(n)
//worst case: O(n)
//avg case: O(n)
vector<TValue> MultiMap::search(TKey c) const {
	
	DLLNode* index = map.header;	//man verwendet index damit man die Liste durchquert
	vector<TValue> v{};				//der Vektor fur die Werte wird initialisiert
	while (index != NULL) {		
		if (index->info.first == c)				//man sucht den Knoten, der das Key c hat
			v.push_back(index->info.second);	//wenn es gefunden wird, wird das Wert dieser Knoten im Vektor gespeichert
		index = index->next;
	}
	delete index;		//man wird der Speicherplatz geleert
	return v;
}

//Komplexitat: 
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
int MultiMap::size() const {	//gibt die Anzahl der Knoten zuruck

	return nr_noduri;
}

//Komplexitat: 
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
bool MultiMap::isEmpty() const {
	
	if (map.header == NULL || map.tail == NULL)		//wenn der erste oder der letzte Knoten nicht existiert, dass heist dass die Liste leer ist
		return true;
	return false;
}

//Komplexitat: 
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}

//Komplexitat: 
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
/*
ZusatzIterator MultiMap::iteratorZ() const {
	return ZusatzIterator(*this);
}*/


//Komplexitat: 
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
MultiMap::~MultiMap() {
	
	delete map.header;		//man wird der Speicherplatz geleert
	delete map.tail;
}

