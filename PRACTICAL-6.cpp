/*Write C++ program using STL for sorting and searching user defined records such as Item 
records (Item code, name, cost, quantity etc) using vector container*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Define the Item structure
struct Item {
    int code;
    string name;
    double cost;
    int quantity;

    // Constructor for easy item creation
    Item(int c, string n, double co, int q) : code(c), name(n), cost(co), quantity(q) {}
};

// Function to display a single item
void displayItem(const Item& item) {
    cout << "Code: " << item.code << ", Name: " << item.name 
         << ", Cost: " << item.cost << ", Quantity: " << item.quantity << endl;
}

// Function to display all items in the vector
void displayAllItems(const vector<Item>& items) {
    cout << "\nAll Items:" << endl;
    for (const auto& item : items) {
        displayItem(item);
    }
}

// Function to add a new item
void addItem(vector<Item>& items) {
    int code, quantity;
    string name;
    double cost;

    cout << "Enter item code: ";
    cin >> code;
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter item cost: ";
    cin >> cost;
    cout << "Enter item quantity: ";
    cin >> quantity;

    items.push_back(Item(code, name, cost, quantity));
    cout << "Item added successfully!" << endl;
}

// Function to search for an item by code
void searchItem(const vector<Item>& items) {
    int searchCode;
    cout << "Enter item code to search: ";
    cin >> searchCode;

    auto it = find_if(items.begin(), items.end(), 
                      [searchCode](const Item& item) { return item.code == searchCode; });

    if (it != items.end()) {
        cout << "Item found:" << endl;
        displayItem(*it);
    } else {
        cout << "Item not found." << endl;
    }
}

// Function to sort items by code
void sortItems(vector<Item>& items) {
    sort(items.begin(), items.end(), 
         [](const Item& a, const Item& b) { return a.code < b.code; });
    cout << "Items sorted by code." << endl;
}

// Function to delete an item by code
void deleteItem(vector<Item>& items) {
    int deleteCode;
    cout << "Enter item code to delete: ";
    cin >> deleteCode;

    auto it = find_if(items.begin(), items.end(), 
                      [deleteCode](const Item& item) { return item.code == deleteCode; });

    if (it != items.end()) {
        items.erase(it);
        cout << "Item deleted successfully!" << endl;
    } else {
        cout << "Item not found." << endl;
    }
}

int main() {
    vector<Item> items;
    int choice;

    do {
        cout << "\n1. Add Item" << endl;
        cout << "2. Display All Items" << endl;
        cout << "3. Search Item" << endl;
        cout << "4. Sort Items" << endl;
        cout << "5. Delete Item" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem(items);
                break;
            case 2:
                displayAllItems(items);
                break;
            case 3:
                searchItem(items);
                break;
            case 4:
                sortItems(items);
                break;
            case 5:
                deleteItem(items);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}