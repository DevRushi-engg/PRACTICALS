/*Write a function template for selection sort that inputs, sorts and outputs an integer array and a 
float array*/

#include <iostream>
#include <vector>

using namespace std;

// Function template for selection sort
template <typename T>
void Ssort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part of the array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }

    // Print the sorted array
    cout << "Sorted array: ";
    for (const T& element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

// Function to get array input from user
template <typename T>
vector<T> getArray() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    vector<T> arr(size);
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    return arr;
}

int main() {
    char choice;
    do {
        cout << "\nSelect array type to sort:" << endl;
        cout << "1. Integer Array" << endl;
        cout << "2. Float Array" << endl;
        cout << "Enter your choice (1 or 2): ";
        int option;
        cin >> option;

        switch (option) {
            case 1: {
                vector<int> intArray = getArray<int>();
                Ssort(intArray);
                break;
            }
            case 2: {
                vector<float> floatArray = getArray<float>();
                Ssort(floatArray);
                break;
            }
            default:
                cout << "Invalid choice. Please enter 1 or 2." << endl;
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Program ended." << endl;
    return 0;
}