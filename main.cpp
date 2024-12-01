
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
    int choice;
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
        display();
        //promot userChoice
        choice = userChoice();

        switch (choice) {
            //case1 - add code
        case 1: {
            string newCode;
            break;
        }
        case 2: {
            string deleteCode;
            break;
        }
        case 3: {
            string searchCode;
            break;
        }
        case 4: {
            string previousCode;
            string updatedCode;
            break;
        }
        case 5: {
            cout << "IN ORDER TRANSVERSAL" << endl;
            break;
        }
        case 6: {
            cout << "PRE ORDER TRANSVERSAL" << endl;
            break;
        }
        case 7: {
            cout << "POST ORDER TRANSVERSAL" << endl;
            break;
        }
        case 8: {
            exit = true;
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
        default: {
            cout << "Please select a valid option from the menu.\n";
            break;
        }
            //case2 - delete code
            //case3 - search for code
            //case4 - modify
            //case5 - display tree in order
            //case6 - display tree pre order
            //case7 - display tree post order
            //case8 - exit
        }

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