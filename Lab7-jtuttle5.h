//
//  Code by Andey Tuttle
//  Last Update November 18, 2018
//  Liscenced under Apache 2.0 Liscence
//  This file provides a set of sorting algorithms
//

#ifndef _LAB7_JTUTTLE_H_
#define _LAB7_JTUTTLE_H_

#include <vector>

//helper functions for more complex sorting algorithms
void swap(std::vector<double> & d, int one, int two);
void merge(std::vector<double> & d, int left, int mid, int right);

void bubbleSort(std::vector<double> & d);
void insertionSort(std::vector<double> & d);
void selectionSort(std::vector<double> & d);
void mergeSort(std::vector<double> & d, int right, int left);
void quickSort(std::vector<double> & d, int start, int end);

#endif
