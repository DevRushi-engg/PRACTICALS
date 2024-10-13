/*Write a program in C++ to use map associative container. The keys will be the names of states 
and the values will be the populations of the states. When the program runs, the user is 
prompted to type the name of a state. The program then looks in the map, using the state name 
as an index and returns the population of the state.*/

#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// Function to display the entire map
void displayMap(const map<string, int>& populationMap) {
    cout << "\nState Populations:" << endl;
    cout << setw(20) << left << "State" << "Population" << endl;
    cout << string(30, '-') << endl;
    for (const auto& pair : populationMap) {
        cout << setw(20) << left << pair.first << pair.second << endl;
    }
    cout << endl;
}

int main() {
    // Create a map to store state names and populations
    map<string, int> populationMap;

    // Insert values into the map (using approximate 2011 census data, scaled down for int)
    populationMap.insert({"Uttar Pradesh", 199812341});
    populationMap.insert({"Maharashtra", 112374333});
    populationMap.insert({"Bihar", 104099452});
    populationMap.insert({"West Bengal", 91276115});
    populationMap.insert({"Madhya Pradesh", 72626809});

    // Display the initial map
    cout << "Initial map:" << endl;
    displayMap(populationMap);

    // Get the size of the map
    cout << "Size of the map: " << populationMap.size() << endl;

    // Delete an element from the map
    string stateToDelete;
    cout << "Enter the name of a state to delete: ";
    getline(cin, stateToDelete);

    auto it = populationMap.find(stateToDelete);
    if (it != populationMap.end()) {
        populationMap.erase(it);
        cout << stateToDelete << " has been removed from the map." << endl;
    } else {
        cout << stateToDelete << " not found in the map." << endl;
    }

    // Display the map after deletion
    cout << "\nMap after deletion:" << endl;
    displayMap(populationMap);

    // Search for a state's population
    string searchState;
    char continueSearch;
    do {
        cout << "Enter the name of a state to find its population: ";
        getline(cin, searchState);

        auto search = populationMap.find(searchState);
        if (search != populationMap.end()) {
            cout << "Population of " << searchState << " is " << search->second << endl;
        } else {
            cout << "State not found in the map." << endl;
        }

        cout << "Do you want to search for another state? (y/n): ";
        cin >> continueSearch;
        cin.ignore(); // Clear the newline from the input buffer
    } while (continueSearch == 'y' || continueSearch == 'Y');

    // Clear the map
    populationMap.clear();
    cout << "\nMap cleared. Size of the map now: " << populationMap.size() << endl;

    return 0;
}