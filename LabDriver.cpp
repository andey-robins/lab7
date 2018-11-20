//
//  Code by Andey Tuttle
//  Last Update November 18, 2018
//  Liscenced under Apache 2.0 Liscence
//  This file has a set of test drivers to test sorting algorithms in Lab7-jtuttl5.h
//

#include "Lab7-jtuttle5.h"
#include "unixTimer.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>

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
    //4 seconds = 31000
    //double = 16.538 seconds
    //quad = 68.536 seconds
    // cout << "Buble sort:" << endl;
    // Timer bubbleTime;
    vector<double> v = getNums(124000, 1, 500);
    // //printVector(v);
    // bubbleTime.start();
    // bubbleSort(v);
    // bubbleTime.stop();
    // //printVector(v);
    // cout << endl << "Sorted in: " << bubbleTime() << endl << endl;

    //demonstration of insertion sort working
    //4 seconds = 57000
    //double = 16.294 seconds
    //quad = 63.544 seconds
    // cout << "Insertion Sort:" << endl;
    // Timer insertionTime;
    // v = getNums(228000, 1, 500);
    // //printVector(v);
    // insertionTime.start();
    // insertionSort(v);
    // insertionTime.stop();
    // //printVector(v);
    // cout << endl << "Sorted in: " << insertionTime() << endl << endl;

    //demonstration of selection sort working
    //4 seconds = 57000
    //double = 16.282 seconds
    //quad = 68.433 seconds
    // cout << "Selection Sort:" << endl;
    // Timer selectionTime;
    // v = getNums(228000, 1, 500);
    // //printVector(v);
    // selectionTime.start();
    // selectionSort(v);
    // selectionTime.stop();
    // //printVector(v);
    // cout << endl << "Sorted in: " << selectionTime() << endl << endl;

    //merge sort
    //4 seconds = 230000
    //double = 8.171
    //quad = 16.649
    cout << "Merge Sort:" << endl;
    Timer mergeTime;
    v = getNums(9200000, 1, 500);
    //printVector(v);
    mergeTime.start();
    mergeSort(v, 0, v.size() - 1);
    mergeTime.stop();
    //printVector(v);
    cout << endl << "Sorted in: " << mergeTime() << endl << endl;

    //demonstration of quicksort working
    //4 seconds = 1400000
    //double = 18.889 seconds
    //quad = 62.150 seconds
    // cout << "Quicksort:" << endl;
    // Timer quickTime;
    // v = getNums(5600000, 1, 500);
    // //printVector(v);
    // quickTime.start();
    // quickSort(v, 0, v.size());
    // quickTime.stop();
    // //printVector(v);
    // cout << endl << "Sorted in: " << quickTime() << endl << endl;

    //demonstration of STL::sort
    //4 seconds = 43000000
    //double = 8.414 seconds
    //quad = 17.704 seconds
    // cout << "STL Sort:" << endl;
    // Timer standardTime;
    // v = getNums(172000000, 1, 500);
    // //printVector(v);
    // standardTime.start();
    // sort(v.begin(), v.end());
    // standardTime.stop();
    // //printVector(v);
    // cout << endl << "Sorted in: " << standardTime() << endl << endl;

    //garbage collection; stops seg fault 11
    v.clear();


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
