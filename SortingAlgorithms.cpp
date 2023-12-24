// Header
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>  
using namespace std;
using namespace std::chrono;


// Global Declarations 
void quicksort(vector<string> &vec);
void quicksort(vector<string> &vec, int start, int finish);
int partition(vector<string> &vec, int start, int finish);
void mergeSort(vector<string> &v);
void merge(vector<string> &v, vector<string> &left, vector<string> &right);

// Quick Sort

void quicksort(vector<string> &vec){
    quicksort(vec, 0, vec.size() - 1);
}
void quicksort(vector<string> &vec, int start, int finish){
    if (start >= finish) return;
    int boundary = partition(vec, start, finish);
    quicksort(vec, start, boundary - 1);
    quicksort(vec, boundary + 1, finish);
}
int partition(vector<string> &vec, int start, int finish){
    string pivot = vec[start];
    transform(pivot.begin(), pivot.end(), pivot.begin(), ::tolower); // convert pivot to lower case

    int lh = start + 1;
    int rh = finish;
    
    while (true){
        while (lh < rh && vec[rh] >= pivot) rh--;
        while (lh < rh && vec[lh] < pivot) lh++;
        if (lh == rh) break;
            
        // swap
        string tmp = vec[lh];
        vec[lh] = vec[rh];
        vec[rh] = tmp;
    }
    
    if (vec[lh] >= pivot) return start;
    vec[start] = vec[lh];
    vec[lh] = pivot;
    return lh;
}

// Merge Sort

void mergeSort(vector<string> &v){
    
    int n = v.size();
    if(n <= 1) return;

    vector<string> left;
    vector<string> right;

    for(int i = 0; i < n; i++){
        if(i < n/2){
            left.push_back(v[i]);
        } else {
            right.push_back(v[i]);
        }
    }

    mergeSort(left);
    mergeSort(right);

    v.clear();
    
    merge(v, left, right);
}

void merge(vector<string> &v, vector<string> &left, vector<string> &right){
    
    int n1 = left.size();
    int n2 = right.size();

    int p1 = 0;
    int p2 = 0;

    while(p1 < n1 && p2 < n2){
        string leftElement = left[p1];
        string rightElement = right[p2];

        transform(leftElement.begin(), leftElement.end(), leftElement.begin(), ::tolower); // convert leftElement to lower case
        transform(rightElement.begin(), rightElement.end(), rightElement.begin(), ::tolower); // convert rightElement to lower case

        if(leftElement <= rightElement){
            v.push_back(left[p1]);
            p1++;
        } else {
            v.push_back(right[p2]);
            p2++;
        }
    }

    while(p1 < n1){
        v.push_back(left[p1]);
        p1++;
    }

    while(p2 < n2){
        v.push_back(right[p2]);
        p2++;
    }
}

// Function for writing file
void writeToFile(const vector<string> &sortedData, const string &sortType) {
    ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << sortType << ": ";
        for (int i = 0; i < sortedData.size(); i ++) {
            outFile << sortedData[i] << " ";
        }
        outFile.close();
        cout << "Data written to output.txt (" << sortType << ")" << endl;
    } else {
        cout << "Error writing to file." << endl;
    }
}

int main() {
    ifstream myfile;
    vector<string> wvector;
    myfile.open("text.txt");

    if (myfile.is_open()) {
        string word;

        while (myfile >> word) {
            wvector.push_back(word);
        }

        myfile.close();

        char inp;

        while (inp != 'e') {
            cout<<"Which sorting algorithm do you want to use?: (m for mergesort, q for quicksort, e for exit)"<<endl;
            cin>>inp;

            switch (inp) {
                case 'm':
                    mergeSort(wvector);
                    writeToFile(wvector, "Merge Sort");
                    break;
                case 'q':
                    quicksort(wvector);
                    writeToFile(wvector, "Quick Sort");
                    break;
                case 'e':
                    cout << "Exiting program." << endl;
                    return 0;
                default:
                    cout << "Invalid input. Please try again." << endl;
            }
        }
    } else {
        cout<<"Couldn't open the file"<<endl;
    }

    return 0;
}