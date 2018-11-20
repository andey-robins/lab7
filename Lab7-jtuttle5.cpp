//
//  Code by Andey Tuttle
//  Last Update November 18, 2018
//  Liscenced under Apache 2.0 Liscence
//  Implementation of various sorting algorithms
//

#include "Lab7-jtuttle5.h"
#include <limits>

//helper functions for more complex sorting functions
//swap the two elements at index one and two
void swap(std::vector<double> & d, int one, int two) {
    double temp = d[one];
    d[one] = d[two];
    d[two] = temp;
}

//merge the elements in an array
//reference: https://www.geeksforgeeks.org/merge-sort/
void merge(std::vector<double> & d, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //make temp vectors
    std::vector<double> l;
    std::vector<double> r;

    //Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        l.push_back(d[left + i]);
    for (j = 0; j < n2; j++)
        r.push_back(d[mid + 1 + j]);

    // Merge the temp arrays back into d[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            d[k] = l[i];
            i++;
        } else {
            d[k] = r[j];
            j++;
        }
        k++;
    }

    //copy any and all remaining elements in the temp arrays
    while (i < n1) {
        d[k] = l[i];
        i++;
        k++;
    }
    while (j < n2) {
        d[k] = r[j];
        j++;
        k++;
    }
}

//an Implementation of the bubble sort algorithm
void bubbleSort(std::vector<double> & d) {

    int endingIndex = d.size() - 1;

    bool swapped = false;

    do {
        swapped = false;

        for (int i = 0; i < endingIndex; i++) {
            if (d[i] > d[i + 1]) {
                double temp = d[i + 1];
                d[i + 1] = d[i];
                d[i] = temp;

                swapped = true;
            }
        }

        endingIndex--;

    } while(swapped);
}

//an Implementation of the insertion sort algorithm
//reference: https://codereview.stackexchange.com/questions/110793/insertion-sort-in-c
void insertionSort(std::vector<double> & d) {

    for (int i = 1; i < d.size(); i++) {

        double currentElement = d[i];
        int endingIndex;

        for (int j = i; j > 0 && d[j - 1] > currentElement; j--) {
            d[j] = d[j - 1];
            endingIndex = j;
        }

        d[endingIndex - 1] = currentElement;
    }
}

//an Implementation of selection sort algorithm
void selectionSort(std::vector<double> & d) {

    for (int bottom = 0; bottom < d.size(); bottom++) {

        int minIndex = bottom;
        double min = std::numeric_limits<float>::max();

        for (int i = bottom; i < d.size(); i++) {
            if (d[i] < min) {
                min = d[i];
                minIndex = i;
            }
        }

        d[minIndex] = d[bottom];
        d[bottom] = min;
    }
}

//an Implementation of the merge sort algorithm
//reference: https://www.geeksforgeeks.org/merge-sort/
void mergeSort(std::vector<double> & d, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;

        //go partition and start recursive sorting
        mergeSort(d, left, middle);
        mergeSort(d, middle + 1, right);

        //merge the two partitions
        merge(d, left, middle, right);
    }
}

//an Implementation of the quicksort algorithms
//reference: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
void quickSort(std::vector<double> & d, int start, int end) {
    if (start < end) {

        int pivot = d[end];
        int i = (start - 1);  // Index of smaller element

        for (int j = start; j <= end - 1; j++) {
            // If current element is smaller than or
            // equal to pivot
            if (d[j] <= pivot) {
                i++;    // increment index of smaller element
                swap(d, i, j);
            }
        }

        swap(d, i + 1, end);

        quickSort(d, start, i);
        quickSort(d, i + 2, end);
    }
}
