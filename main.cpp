
#include <iostream>
#include <fstream>
#include "StringBinaryTree.h"

const string FILENAME = "codes.txt";

//Prototypes here
//need some basic functions for displaying menu, gets userChoice, and gets userString
void displayMenu();
int userChoice();
string userString(const string &prompt);


int main() {
    //starting here 
    StringBinaryTree bst;
    string code;
    bool exit = false;
    int userChoice;
    ifstream infile(FILENAME);

    // Check if the file was opened successfully.
    if (!infile) {
        cout << "Error: Unable to open file \"" << FILENAME << "\" for reading." << endl;
        return 1;
    }

    // Read codes from the file and insert into the BST.
    while (getline(infile, code)) {
        if (!code.empty()) { // Avoid inserting empty lines.
            bst.insertNode(code);
        }
    }

    infile.close();
    cout << "Successfully loaded codes from \"" << FILENAME << "\" into the BST.\n";

    while (!exitProgram) {
        //display
        //promot userChoice

         //case1
         //case2
         //case3
         //case4
         //case5
         //case6
         //case7
         //case8
    }

    return 0;
}

//Definitions
void displayMenu() {
    cout << "--- Binary Search Tree Menu ---" << endl;
    cout << "1. Add a Code" << endl;
    cout << "2. Delete a Code" << endl;
    cout << "3. Search for a Code" << endl;
    cout << "4. Modify a Code" << endl;
    cout << "5. Display Tree (In-order)" << endl;
    cout << "6. Display Tree (Pre-order)" << endl;
    cout << "7. Display Tree (Post-order)" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}
int userChoice() {
    int choice;
    while (!(cin >> choice) || choice < 1 || choice > 8) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter a number between 1 and 8: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    return choice;
}
string userString(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (!input.empty()) {
            break; // Valid input.
        }
        cout << "Input cannot be empty. Please try again.\n";
    }
    return input;
}