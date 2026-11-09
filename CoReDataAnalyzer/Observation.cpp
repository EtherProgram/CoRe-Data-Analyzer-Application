
#include "Observation.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

Observation readObservation() {
    Observation observation;

    cout << "\n--- ADD NEW OBSERVATION ---\n";

    cout << "Enter ID: ";
    cin >> observation.id;

    while (cin.fail() || observation.id <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid ID. Enter a positive number: ";
        cin >> observation.id;
    }

    cout << "Enter State (PA, OH, FL): ";
    cin >> observation.state;

    transform(observation.state.begin(),
              observation.state.end(),
              observation.state.begin(),
              ::toupper);

    while (observation.state != "PA" &&
           observation.state != "OH" &&
           observation.state != "FL") {

        cout << "Invalid state. Enter PA, OH, or FL: ";
        cin >> observation.state;

        transform(observation.state.begin(),
                  observation.state.end(),
                  observation.state.begin(),
                  ::toupper);
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter County: ";
    getline(cin, observation.county);

    while (observation.county.empty()) {
        cout << "County cannot be empty. Enter County: ";
        getline(cin, observation.county);
    }

    cout << "Enter Total Votes: ";
    cin >> observation.totalVotes;

    while (cin.fail() || observation.totalVotes < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid number. Enter Total Votes: ";
        cin >> observation.totalVotes;
    }

    cout << "Enter Democratic Votes: ";
    cin >> observation.democraticVotes;

    while (cin.fail() ||
           observation.democraticVotes < 0 ||
           observation.democraticVotes > observation.totalVotes) {

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid number. Enter Democratic Votes: ";
        cin >> observation.democraticVotes;
    }

    cout << "Enter Republican Votes: ";
    cin >> observation.republicanVotes;

    while (cin.fail() ||
           observation.republicanVotes < 0 ||
           observation.democraticVotes + observation.republicanVotes
           > observation.totalVotes) {

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid number. Enter Republican Votes: ";
        cin >> observation.republicanVotes;
    }

    if (observation.totalVotes > 0) {
        observation.democraticShare =
            (static_cast<double>(observation.democraticVotes)
            / observation.totalVotes) * 100.0;
    }
    else {
        observation.democraticShare = 0.0;
    }

    return observation;
}

void displayObservation(const Observation& observation) {
    cout << left
         << setw(8) << observation.id
         << setw(8) << observation.state
         << setw(20) << observation.county
         << setw(15) << observation.totalVotes
         << setw(15) << observation.democraticVotes
         << setw(15) << observation.republicanVotes
         << fixed << setprecision(2)
         << observation.democraticShare << "%\n";
}
