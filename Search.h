#include <iostream>
#include <string>

using namespace std;

// write a function to print the contents of your array
//   bonus! try to implement your function so that it can accept
//     many types of data (int, char, string, etc.)
template <typename flexibleType> // ???
void printArray(flexibleType arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Implement a sequential search algorithm
// your function should search for a target value (target)
//    within the indices of "start" to "end"
// return true if target exists in the array within this range,
//    return false otherwise
bool seqSearch(string target, string arr[], int start, int end) {
    if (start > end) {
        return false;
    }
    else if (arr[start] == target) {
        return true;
    }
    else {
        return seqSearch(target, arr, start+1, end);
    }
        
}

// Implement an iterative binary search 
// Return true if target exists in the array with size n,
//    return false otherwise 
bool binSearch(float target, float arr[], int n) {
    int start = 0, end = n-1, m = (start+end)/2;
    while (start <= end) {
        if (arr[m] == target) {
            return true;
        }
        else if (arr[m] > target) {
            end = m-1;
        }
        else {
            start = m+1;
        }
        m = (start+end)/2;
    }
    return false;
}

// Implement a recursive binary search 
// Return true if target exists in the array with size n
//   return false otherwise
bool binSearchR(char target, char charray[], int n, int s = 0) {
    // base case 
    int start = s;
    int end = n-1;
    int mid = (start+end)/2;
    if (start > end) {
        return false;
    }
    if (charray[mid] == target) {
        return true;
    }
    else if (charray[mid] > target) {
        return binSearchR(target, charray, mid-1);
    }
    else {
        return binSearchR(target, charray, n, mid+1);
    }

}

// Implement a brand new sorting algorithm
//    Don't use a reference for this!
//    Be sure to do your best to implement the algorithm's logical steps
// Step 1: implement a function swap() that will swap any two elements in an array,
//          given their indices
// Step 2: implement a function minFind() that will find and return 
//          the **index** of the smallest element in an array
/*
Step 3: Finally, use your two functions above to complete the following in newSort():
        1 - search through the array to find the location of the smallest value
        2 - swap this value with the value at the start of the array
        3 - the first element is now sorted! 
            Redo your sort on the remaining elements (from index 1 to end)
            On the next iteration, you should be swapping the smallest remaining value 
                with the second index value in the array
            ...then swapping the smallest remaining value with the third indexed value... etc.
            
        4 - continue iterating until you reach the end of the list
        *** You can make this recursive, if you wish!
*/

void swap(double darray[], int ind1, int ind2) {
    double temp = darray[ind1];
    darray[ind1] = darray[ind2];
    darray[ind2] = temp; 
}

int minFind(double darray[], int n) {
    int minI = 0;
    for (int i = 1; i < n; i++) {
        if (darray[i] < darray[minI]) {
            minI = i;
        }
    }
    return minI;
}

void newSort(double darray[], int n) {
   for (int i = 0; i < n; i++) { 
    swap(darray, i, i+minFind(darray+i, 5-i));
   }
}
