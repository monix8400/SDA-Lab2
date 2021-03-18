#include <iostream>
#include "MultiMap.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include "MultiMapIterator.h"

using namespace std;


int main() {


	testAll();
	cout << "End Short Tests" << endl;
	testAllExtended();
	cout << "End Extended Tests" << endl;
	system("pause");

}
