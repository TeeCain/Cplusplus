#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

// Tinisha cain-Beckford
// 06-16-2023
/* This program analyzes the text records that a company generates throughout the day. 
These records list items purchased in chronological order from the time the store opens to the time it closes. 
It rearranges their produce section based on how often items are purchased so they can create the most effective layout for their customers. 
*/

// Function to read the input file and update item frequencies
void updateItemFrequencies(const string& inputFile, map<string, int>& itemFrequencies) {
    ifstream file(inputFile);
    string line, item;

    while (getline(file, line)) {
        istringstream iss(line);
        while (iss >> item) {
            itemFrequencies[item]++;
        }
    }

    file.close();
}

// Prints the frequency of a specific item
void printItemFrequency(const string& item, const map<string, int>& itemFrequencies) {
    cout << "Frequency of '" << item << "': " << itemFrequencies.at(item) << endl;
}

// Print the frequency of all items
void printAllItemFrequencies(const map<string, int>& itemFrequencies) {
    for (const auto& pair : itemFrequencies) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// Prints a histogram of item frequencies
void printHistogram(const map<string, int>& itemFrequencies) {
    for (const auto& pair : itemFrequencies) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Creates a backup file with item frequencies
void createBackupFile(const string& backupFile, const map<string, int>& itemFrequencies) {
    ofstream file(backupFile);
    for (const auto& pair : itemFrequencies) {
        file << pair.first << " " << pair.second << endl;
    }
    file.close();
}

int main() {
    const string inputFile = "CS210_Project_Three_Input_File.txt";
    const string backupFile = "frequency.dat";

    map<string, int> itemFrequencies;

    // Update item frequencies from the input file
    updateItemFrequencies(inputFile, itemFrequencies);

    // Create backup file
    createBackupFile(backupFile, itemFrequencies);

    int choice;
    string item;

    // Menu Options
    while (true) {
        cout << "Menu Options:" << endl;
        cout << "1. Look up frequency of a specific item" << endl;
        cout << "2. Print frequency of all items" << endl;
        cout << "3. Print histogram of item frequencies" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        
        switch (choice) {
        case 1:
            cout << "Enter item to look up: ";
            cin >> item;
            printItemFrequency(item, itemFrequencies);
            break;
        case 2:
            printAllItemFrequencies(itemFrequencies);
            break;
        case 3:
            printHistogram(itemFrequencies);
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
