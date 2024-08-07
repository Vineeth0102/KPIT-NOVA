#include "bitmap.h"

//Data values

data d1 =
{
    {"SaleUnits", 17000},
    {"Price", 45000},
    {"Efficiency", 10},
    {"HorsePower", 140}

};

data d2 =
{
    {"SaleUnits", 10000},
    {"Price", 65000},
    {"Efficiency", 12},
    {"HorsePower", 160}

};

data d3 =
{
    {"SaleUnits", 20000},
    {"Price", 35000},
    {"Efficiency", 14},
    {"HorsePower", 155}

};

data d4 =
{
    {"SaleUnits", 17000},
    {"Price", 45000},
    {"Efficiency", 10},
    {"HorsePower", 140}

};


data d5 =
{
    {"SaleUnits", 21000},
    {"Price", 40000},
    {"Efficiency", -1},
    {"HorsePower", 145}

};


//insert data values to vector for convenient processing    
std::vector <data> records = {d1,d2,d3,d4,d5};

/*
    To find the Average Price, apply this logic

        i) Loop over vector of values.
        ii)For every record
            a) Look for 'Price' key.
            b) If found, check if Price is invalid (set to -1)
            c) If a valid Price is found, add to total.
        iii)Find the average based on total and record size.

*/

float AverageCarPrice(std::vector<data>& values) {
    int total = 0;
    int count = 0;

    for (const auto& record : values) {
        auto it = record.find("Price");
        if (it != record.end() && it->second != -1) {
            total += it->second;
            count++;
        }
    }

    if (count == 0) return 0.0; // Avoid division by zero

    return round(static_cast<float>(total) / count);
}

/*
    To find the Maximum Horsepower Price, apply this logic

        i) Loop over the vector of values.
        ii)For every record
            a) Look for the 'Horsepower' key.
            b) If found, check if Price is invalid (set to -1)
            c) If a valid value is found, compare to see if it is higher than current value. Update where applicable.
*/

int MaxHorsepower(std::vector<data>& values) {
    int maxPower = 0;

    for (const auto& record : values) {
        auto it = record.find("HorsePower");
        if (it != record.end() && it->second != -1) {
            if (it->second > maxPower) {
                maxPower = it->second;
            }
        }
    }

    return maxPower;
}



/*
    To find lowest efficiency, apply this logic

        i) Loop over vector of values.
        ii)For every record
            a) Look for 'efficiency' key.
            b) If found, check if efficiency is invalid (set to -1)
            c) If a valid value is found, compare to see if it is lower than current value. Update where applicable.
*/

int FindLowestEfficiency(std::vector<data>& values) {
    int lowestEfficiency = 100; 
    for (const auto& record : values) {
        auto it = record.find("Efficiency");
        if (it != record.end() && it->second != -1) {
            if (it->second < lowestEfficiency) {
                lowestEfficiency = it->second;
            }
        }
    }

    return lowestEfficiency;
}