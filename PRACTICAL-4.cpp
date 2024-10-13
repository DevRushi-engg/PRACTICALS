/*Write a C++ program that creates an output file, writes information to it, closes the file, open it 
again as an input file and read the information from the file.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to write data to the file
void writeToFile() {
    // Open the file in append mode
    ofstream outputFile("personnel.txt", ios::app);
    
    if (outputFile.is_open()) {
        string id, name;
        double salary;

        // Get user input
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Salary: ";
        cin >> salary;

        // Write to file
        outputFile << id << "," << name << "," << salary << endl;

        cout << "Data written INto file successfully!" << endl;
        
        // Close the file
        outputFile.close();
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

// Function to read data from the file
void readFromFile() {
    // Open the file for reading
    ifstream inputFile("PERSONALINFO.txt");
    
    if (inputFile.is_open()) {
        string line;
        cout << "\nPersonnel Information:" << endl;
        
        // Read file line by line
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        
        // Close the file
        inputFile.close();
    } else {
        cout << "Unable to open file for reading." << endl;
    }
}

int main() {
    int choice;

    do {
        // Display menu
        cout << "\n1. Write to file" << endl;
        cout << "2. Read from file" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeToFile();
                break;
            case 2:
                readFromFile();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Wrong choice. Please enter a number between 1 and 3." << endl;
        }
    } while (choice != 3);

    return 0;
}