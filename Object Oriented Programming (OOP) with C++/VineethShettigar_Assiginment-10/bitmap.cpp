#include<iostream>
#include<cstring>
#include<algorithm>
#include"bitmap.h"
using namespace std;

Laptop::Laptop() : lid(0), cost(0.0) {
    strcpy(make, "Unknown");
}

Laptop::Laptop(int id, const char *m, double c) : lid(id), cost(c) {
    strcpy(make, m);
}

int Laptop::GetLid() {
    return lid;
}

char* Laptop::GetMake() {
    return make;
}

double Laptop::GetCost() {
    return cost;
}

void Laptop::Display() {
    cout << "Laptop ID: " << lid << endl;
    cout << "Make: " << make << endl;
    cout << "Cost: " << cost << endl;
}

void LaptopStore::InsertLaptop(Laptop l) {
    vect_laptop.push_back(l);
}

bool compare(Laptop l1, Laptop l2) {
    return l1.GetCost() < l2.GetCost();
}

void LaptopStore::SortLaptops() {
    sort(vect_laptop.begin(), vect_laptop.end(), compare);
}

vector<Laptop> LaptopStore::GetVect_Laptop() {
    return vect_laptop;
}

Laptop LaptopStore::GetMinCostLaptop() {
    auto minElement = min_element(vect_laptop.begin(), vect_laptop.end(), compare);
    return *minElement;
}

Laptop LaptopStore::GetMaxCostLaptop() {
    auto maxElement = max_element(vect_laptop.begin(), vect_laptop.end(), compare);
    return *maxElement;
}

void LaptopStore::ShowLaptops() {
    for (auto& laptop : vect_laptop) {
        laptop.Display();
        cout << endl;
    }
}




