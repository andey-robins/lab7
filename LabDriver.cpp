//
//  Code by Andey Tuttle
//  Last Update November 18, 2018
//  Liscenced under Apache 2.0 Liscence
//  This file has a set of test drivers to test sorting algorithms in Lab7-jtuttl5.h
//

#include "Lab7-jtuttle5.h"
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

//function declarations
void printVector(vector<double> v);
vector<double> getNums(size_t listSize, double minNum, double maxNum);
double randReal(double minReal, double maxReal);
double randUniform();
void randomizeSeed();

int main() {

    //single randomization call to setup rand functions
    randomizeSeed();

    //demonstrations
    //demonstration of bubble sort working
    cout << "Buble sort:" << endl;
    vector<double> v = getNums(20, 1, 500);
    printVector(v);
    bubbleSort(v);
    printVector(v);
    cout << endl << endl;

    //demonstration of insertion sort working
    cout << "Insertion Sort:" << endl;
    v = getNums(20, 1, 500);
    printVector(v);
    insertionSort(v);
    printVector(v);
    cout << endl << endl;

    //demonstration of selection sort working
    cout << "Selection Sort:" << endl;
    v = getNums(20, 1, 500);
    printVector(v);
    selectionSort(v);
    printVector(v);
    cout << endl << endl;

    //merge sort
    // cout << "Merge Sort:" << endl;
    // v = getNums(20, 1, 500);
    // printVector(v);
    // mergeSort(v, 0, v.size());
    // printVector(v);

    //demonstration of quicksort working
    cout << "Quicksort:" << endl;
    v = getNums(20, 1, 500);
    printVector(v);
    quickSort(v, 0, v.size());
    printVector(v);


    return 0;
}

//print out all of the elements in the vector passed to it
void printVector(vector<double> v) {

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    };

    cout << endl << endl;

    return;
}

// stolen from lab 6
// post: a sorted vector of listSize random doubles from
//         the range minNum to maxNum has been returned.
vector<double> getNums(size_t listSize, double minNum, double maxNum) {
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i) {
		theList.push_back(randReal(minNum, maxNum));
	}

	return theList;
}

// stolen from lab 6
// Return a random variate distributed uniformly on the
// range minReal upto, not including, maxReal.
// minReal is assumed < maxReal.
double randReal( double minReal, double maxReal ) {
	return minReal + ( maxReal - minReal ) * randUniform();
}

//stolen from lab 6
// Return a random variate distributed uniformly between
// zero and one.  All doubles in this range are
// approximately equally likely.
// 0 <= r < 1
double randUniform() {
   double r = double( rand() ) / ( RAND_MAX + 1.0 );
   r = ( double( rand() ) + r ) / ( RAND_MAX + 1.0 );
   r = ( double( rand() ) + r ) / ( RAND_MAX + 1.0 );
   r = ( double( rand() ) + r ) / ( RAND_MAX + 1.0 );
   return  r;
};

// stolen from lab 6
// Seed the random-number generator with current time so that
// the numbers will be different every time we run.
// WARNING:  Only do this once per run!
// The static variable called enforces the one call per run
// rule.
void randomizeSeed()
{
	static bool called = false;
	if( ! called )
	{
      srand( long( std::time(NULL) ) );
		called = true;
	}
}
