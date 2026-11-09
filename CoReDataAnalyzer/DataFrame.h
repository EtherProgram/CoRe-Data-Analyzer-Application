
#ifndef DATAFRAME_H
#define DATAFRAME_H

#include "Observation.h"

const int MAX_OBSERVATIONS = 100;

struct DataFrame {
    Observation observations[MAX_OBSERVATIONS];
    int count;
};

void initializeDataFrame(DataFrame& df);
void addObservation(DataFrame& df);
void deleteObservation(DataFrame& df);
void displayDataFrame(const DataFrame& df);

#endif
