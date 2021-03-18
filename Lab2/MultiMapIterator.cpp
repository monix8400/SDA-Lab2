#include "MultiMapIterator.h"
#include "MultiMap.h"

//Θ(1) ist nur wenn nur elementar Operationen sind.

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
	index = c.map.header;
}

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
TElem MultiMapIterator::getCurrent() const{	//gibt der Knoten zuruck, wenn es ein Knoten gibt
	
	if (valid() == true)
		return index->info;
	return NULL_TELEM;
}

//Komplexitat: 
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)

bool MultiMapIterator::valid() const {	//bestimmt ob Elemente in der Liste sind, also ob die Liste leer ist

	if (col.isEmpty())				
		return false;
	if (index == NULL)
		return false;
	if (index==col.map.header)
		return true;
	if (index->prev != NULL)
		return true;
	return false;
}

//Komplexitat: 
//best case: Θ(1)
//worst case: Θ(1) 
//avg case: Θ(1)
void MultiMapIterator::next() { //gibt der nachste Knoten zuruck
	
	if (index == NULL) {
		exception e;
		throw e;
	}
	index = index->next;
}

//Komplexitat: 
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
void MultiMapIterator::first() { //gibt der erste Knoten zuruck
	
	index=col.map.header ;
}
