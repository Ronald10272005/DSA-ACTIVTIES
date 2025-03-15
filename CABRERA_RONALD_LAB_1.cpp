#include <iostream>
#include <string>
using namespace std;

int myArray[10];
int numElem = 0;
int maxLen = 10;

// Traverse the array
void traverseArray() {
    for (int i = 0; i < numElem; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;
}

// Insert at the end
string insertAtTheEnd(int num) {
    if (numElem < maxLen) {
        myArray[numElem] = num;
        numElem++;
        return "An element is successfully inserted at the end.\n";
    }
    return "The array is full. Please remove elements before inserting a new one.\n";
}

// Insert at the beginning
string insertAtBeginning(int num) {
    if (numElem < maxLen) {
        for (int i = numElem; i > 0; i--) {
            myArray[i] = myArray[i - 1];
        }
        myArray[0] = num;
        numElem++;
        return "An element is successfully inserted at the beginning.\n";
    }
    return "The array is full. Please remove elements before inserting a new one.\n";
}

// Insert at the given position
string insertAtTheGivenPosition(int num, int elementAfter) {
    if (numElem < maxLen) {
        int position = -1;
        for (int i = 0; i < numElem; i++) {
            if (myArray[i] == elementAfter) {
                position = i + 1;
                break;
            }
        }
        if (position != -1) {
            for (int i = numElem; i > position; i--) {
                myArray[i] = myArray[i - 1];
            }
            myArray[position] = num;
            numElem++;
            return "An element is successfully inserted at the specified location.\n";
        } else {
            return "Element not found.\n";
        }
    }
    return "The array is full. Please remove elements before inserting a new one.\n";
}

// Bubble sort
void bubbleSort() {
    bool swapped;
    for (int i = 0; i < numElem - 1; i++) {
        swapped = false;
        for (int j = 0; j < numElem - i - 1; j++) {
            if (myArray[j] > myArray[j + 1]) {
                swap(myArray[j], myArray[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Delete from the end
string deleteFromTheEnd() {
    if (numElem > 0) {
        numElem--;
        return "An element has been deleted from the end.\n";
    }
    return "The array is underflow. Delete is not possible.\n";
}

// Delete from the beginning
string deleteFromBeginning() {
    if (numElem > 0) {
        for (int i = 0; i < numElem - 1; i++) {
            myArray[i] = myArray[i + 1];
        }
        numElem--;
        return "An element has been deleted from the beginning.\n";
    }
    return "The array is underflow. Delete is not possible.\n";
}

// Delete from a given position
string deleteFromGivenPosition(int position) {
    if (numElem > 0 && position >= 0 && position < numElem) {
        for (int i = position; i < numElem - 1; i++) {
            myArray[i] = myArray[i + 1];
        }
        numElem--;
        return "An element has been deleted from the given position.\n";
    }
    return "The array is underflow or the position is invalid. Delete is not possible.\n";
}

// Binary search
int binarySearch(int num, int lowest, int highest) {
    while (lowest <= highest) {
        int middle = lowest + (highest - lowest) / 2;
        if (myArray[middle] == num) {
            return middle;
        }
        if (myArray[middle] < num) {
            lowest = middle + 1;
        } else {
            highest = middle - 1;
        }
    }
    return -1;
}

int main() {
    cout << insertAtBeginning(5);
    cout << insertAtTheEnd(10);
    cout << insertAtTheEnd(9);
    cout << insertAtBeginning(25);
    cout << insertAtTheGivenPosition(37, 7);
    cout << insertAtBeginning(256);
    cout << insertAtTheGivenPosition(128, 9);
    cout << insertAtBeginning(19);

    cout << "Array after insertion: ";
    traverseArray();

    bubbleSort();
    cout << "Sorted array: ";
    traverseArray();

    cout << deleteFromTheEnd();
    cout << deleteFromBeginning();
    cout << deleteFromGivenPosition(1);

    cout << "Array after deletions: ";
    traverseArray();

    int index = binarySearch(20, 0, numElem - 1);
    cout << "Index of 37: " << index << endl;

    index = binarySearch(38, 0, numElem - 1);
    cout << "Index of 38: " << index << endl;

    return 0;
}