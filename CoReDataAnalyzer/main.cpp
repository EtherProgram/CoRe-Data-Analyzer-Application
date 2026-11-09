
#include <iostream>
#include "DataFrame.h"

using namespace std;

int main() {

    DataFrame electionData;

    initializeDataFrame(electionData);

    int option;

    do {
        cout << "\n====================================\n";
        cout << "       CoRe DATA ANALYZER\n";
        cout << "====================================\n";

        cout << "1. Add Observation\n";
        cout << "2. Delete Observation\n";
        cout << "3. Display Data Frame\n";
        cout << "0. Exit\n";

        cout << "====================================\n";
        cout << "Select an option: ";

        cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');

            cout << "\nInvalid option. Try again.\n";
            continue;
        }

        switch (option) {

            case 1:
                addObservation(electionData);
                break;

            case 2:
                deleteObservation(electionData);
                break;

            case 3:
                displayDataFrame(electionData);
                break;

            case 0:
                cout << "\nExiting CoRe Data Analyzer...\n";
                break;

            default:
                cout << "\nInvalid option. Try again.\n";
        }

    } while (option != 0);

    return 0;
}
