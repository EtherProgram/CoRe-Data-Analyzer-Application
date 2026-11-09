
#ifndef OBSERVATION_H
#define OBSERVATION_H

#include <string>

struct Observation {
    int id;
    std::string state;
    std::string county;
    int totalVotes;
    int democraticVotes;
    int republicanVotes;
    double democraticShare;
};

Observation readObservation();
void displayObservation(const Observation& observation);

#endif
