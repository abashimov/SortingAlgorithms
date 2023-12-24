# SortingAlgorithms C++

SortingAlgorithms program implemented in C++

This C++ program reads a list of words from a file, sorts them using either Quick Sort or Merge Sort, and writes the sorted data to an output file. The user can choose between Quick Sort and Merge Sort.

# Dependencies:

The program uses the following C++ libraries:

- iostream
- vector
- fstream
- algorithm
- chrono

# Functions:

The program consists of the following functions:

1. **quicksort(vector<string> &vec):**
   - Interface function for Quick Sort.
   - Calls the overloaded quicksort function.

2. **quicksort(vector<string> &vec, int start, int finish):**
   - Recursive implementation of Quick Sort.
   - Partitions the vector and recursively sorts subvectors.

3. **partition(vector<string> &vec, int start, int finish):**
   - Partitions the vector using a pivot element.
   - Rearranges elements less than the pivot to the left and greater to the right.

4. **mergeSort(vector<string> &v):**
   - Recursive implementation of Merge Sort.
   - Divides the vector into two halves and recursively applies Merge Sort.

5. **merge(vector<string> &v, vector<string> &left, vector<string> &right):**
   - Merges two sorted vectors (left and right) into a single sorted vector (v).

6. **writeToFile(const vector<string> &sortedData, const string &sortType):**
   - Writes the sorted data to "output.txt" with the specified sorting algorithm type.

7. **main():**
   - Reads data from "text.txt," initializes a vector with words, and prompts the user to choose Quick Sort or Merge Sort.
   - Applies the chosen algorithm, writes the sorted data to "output.txt," and exits upon user input 'e'.

# Usage:

Compile and run the program. When prompted, enter 'm' for Merge Sort, 'q' for Quick Sort, or 'e' to exit the program.

# bash

g++ -std=c++11 SortingAlgorithms.cpp
./SortingAlgorithms
