#include <iostream>
#include <fstream>
#include "address.h"
#include "tree.h"
#include "timer.h"

using namespace std;

int main() {
    Tree binaryTree;
    Timer insertionTimer; //timer for insert
    Timer searchTimer;    //timer for search

    string filename;
    float latitude, longitude;
    int houseNumber;
    string streetName;

    cout << "Enter name of address file: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Error, failed to open: " << filename << endl;
        return 1;
    }

    int count = 0;

    while (inputFile >> latitude >> longitude >> houseNumber >> ws && getline(inputFile, streetName)) {
        insertionTimer.start_timer(); //start timer 
        Address address(latitude, longitude, houseNumber, streetName);
        binaryTree.insert(address);
        insertionTimer.end_timer(); //end timer

        count++;
    }

    inputFile.close();

    cout << "Addresses inserted: " << count << endl;
    cout << "Insert time: " << insertionTimer.elapsed_time() << " secs" << endl;

    while (true) {
        cout << "Enter house number and street name: ";
        cin >> houseNumber;

        cin.ignore();
        getline(cin, streetName);
        Address queryAddress(0, 0, houseNumber, streetName);

        if (binaryTree.search(queryAddress)) {
            searchTimer.start_timer(); //Start timer
            cout << "Address found:" << endl;
            Address foundAddress = binaryTree.retrieveDetails(queryAddress);
            foundAddress.print(); //Print address details
            searchTimer.end_timer(); //End timer
        } else {
            cout << "Address not found." << endl;
        }

        cout << "Search time: " << searchTimer.elapsed_time() << " secs" << endl;

        cout << "Search for another address? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    return 0;
}