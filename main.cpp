#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define the Visitor structure
struct Visitor {
    int id;
    string name;
    string checkInTime;
    string checkOutTime;
    Visitor* next; // Pointer to the next visitor in the list
};

// Global head pointer for linked list
Visitor* head = nullptr;

// File to store visitor data
const string fileName = "visitors.txt";

// Function declarations
void checkInVisitor();
void checkOutVisitor();
void loadFromFile();
void saveToFile();
void displayVisitors();
void deleteAllVisitors();

// Function to load visitor data from the file
void loadFromFile() {
    ifstream file(fileName);
    if (file.is_open()) {
        Visitor* newVisitor;
        while (!file.eof()) {
            newVisitor = new Visitor(); // Allocate memory for newVisitor
            file >> newVisitor->id >> ws;
            if (file.fail()) break; // Break if reading fails (EOF reached)

            getline(file, newVisitor->name);
            getline(file, newVisitor->checkInTime);
            getline(file, newVisitor->checkOutTime);
            newVisitor->next = head;
            head = newVisitor;
        }
        file.close();
    }
}

// Function to save visitor data to the file
void saveToFile() {
    ofstream file(fileName);
    if (file.is_open()) {
        Visitor* temp = head;
        while (temp != nullptr) {
            file << temp->id << '\n';
            file << temp->name << '\n';
            file << temp->checkInTime << '\n';
            file << temp->checkOutTime << '\n';
            temp = temp->next;
        }
        file.close();
    }
}

// Function to check in a visitor
void checkInVisitor() {
    Visitor* newVisitor = new Visitor();
    cout << "Enter Visitor ID: ";
    cin >> newVisitor->id;
    cin.ignore(); // To ignore the newline character after entering ID

    cout << "Enter Visitor Name: ";
    getline(cin, newVisitor->name);

    cout << "Enter Check-In Time (HH:MM): ";
    getline(cin, newVisitor->checkInTime);

    newVisitor->checkOutTime = ""; // Leave check-out time blank initially
    newVisitor->next = head;
    head = newVisitor;

    cout << "Visitor checked in successfully!" << endl;
}

// Function to check out a visitor
void checkOutVisitor() {
    int visitorId;
    cout << "Enter Visitor ID for check-out: ";
    cin >> visitorId;

    Visitor* temp = head;
    while (temp != nullptr) {
        if (temp->id == visitorId) {
            cout << "Enter Check-Out Time (HH:MM): ";
            cin.ignore(); // To clear the input buffer
            getline(cin, temp->checkOutTime);
            cout << "Visitor checked out successfully!" << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Visitor not found!" << endl;
}

// Function to display all visitors
void displayVisitors() {
    if (head == nullptr) {
        cout << "No visitors in the system." << endl;
        return;
    }

    Visitor* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << ", Name: " << temp->name
             << ", Check-In: " << temp->checkInTime
             << ", Check-Out: " << temp->checkOutTime << endl;
        temp = temp->next;
    }
}

// Function to delete all visitors (for cleanup)
void deleteAllVisitors() {
    Visitor* temp = head;
    while (temp != nullptr) {
        Visitor* toDelete = temp;
        temp = temp->next;
        delete toDelete; // Free memory
    }
    head = nullptr; // Set head to nullptr after deletion
}

int main() {
    int choice;
    loadFromFile(); // Load visitor data from file on startup

    do {
        cout << "\nVisitor Management System\n";
        cout << "1. Check-In Visitor\n";
        cout << "2. Check-Out Visitor\n";
        cout << "3. Display All Visitors\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkInVisitor();
                break;
            case 2:
                checkOutVisitor();
                break;
            case 3:
                displayVisitors();
                break;
            case 4:
                saveToFile(); // Save visitor data to file before exiting
                deleteAllVisitors(); // Clean up memory
                cout << "Exiting system..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!" << endl;
        }

    } while (choice != 4);

    return 0;
}
