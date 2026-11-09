
#include "DataFrame.h"
#include <iostream>
#include <iomanip>

using namespace std;

void initializeDataFrame(DataFrame& df) {
    df.count = 0;
}

void addObservation(DataFrame& df) {

    if (df.count >= MAX_OBSERVATIONS) {
        cout << "\nThe Data Frame is full.\n";
        return;
    }

    Observation newObservation = readObservation();

    // Check whether the ID already exists.
    for (int i = 0; i < df.count; i++) {
        if (df.observations[i].id == newObservation.id) {
            cout << "\nError: This ID already exists.\n";
            return;
        }
    }

    df.observations[df.count] = newObservation;
    df.count++;

    cout << "\nObservation added successfully!\n";
}

void deleteObservation(DataFrame& df) {

    if (df.count == 0) {
        cout << "\nThe Data Frame is empty.\n";
        return;
    }

    int searchID;

    cout << "\nEnter the ID of the observation to delete: ";
    cin >> searchID;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid ID.\n";
        return;
    }

    int position = -1;

    for (int i = 0; i < df.count; i++) {
        if (df.observations[i].id == searchID) {
            position = i;
            break;
        }
    }

    if (position == -1) {
        cout << "\nObservation not found.\n";
        return;
    }

    // Shift remaining observations to the left.
    for (int i = position; i < df.count - 1; i++) {
        df.observations[i] = df.observations[i + 1];
    }

    df.count--;

    cout << "\nObservation deleted successfully!\n";
}

void displayDataFrame(const DataFrame& df) {

    if (df.count == 0) {
        cout << "\nThe Data Frame is empty.\n";
        return;
    }

    cout << "\n================ CORe DATA ANALYZER ================\n";

    cout << left
         << setw(8) << "ID"
         << setw(8) << "State"
         << setw(20) << "County"
         << setw(15) << "Total Votes"
         << setw(15) << "Dem. Votes"
         << setw(15) << "Rep. Votes"
         << "Dem. Share\n";

    cout << "---------------------------------------------------------------"
            "----------------\n";

    for (int i = 0; i < df.count; i++) {
        displayObservation(df.observations[i]);
    }

    cout << "\nTotal observations: " << df.count << "\n";
}
