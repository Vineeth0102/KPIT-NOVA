#include<iostream>
#include<cstring>
#include"bitmap.h"
using namespace std;

Employee::Employee() : empid(0), basicsalary(0.0) {
    strcpy(name, "Unknown");
}

Employee::Employee(int id, const char *n, double sal) : empid(id), basicsalary(sal) {
    strcpy(name, n);
}

double Employee::GetBasicSalary() {
    return basicsalary;
}

void Employee::Display() {
    cout << "Employee ID: " << empid << endl;
    cout << "Name: " << name << endl;
    cout << "Basic Salary: " << basicsalary << endl;
}


WageEmployee::WageEmployee() : Employee(), hours(0), rate(0) {
}

WageEmployee::WageEmployee(int id, const char *n, double sal, int h, int r) : Employee(id, n, sal), hours(h), rate(r) {
}

double WageEmployee::CalcNetSalary() {
    return GetBasicSalary() + (hours * rate);
}

bool WageEmployee::IsTaxable() {
    return CalcNetSalary() >= 500000;
}

void WageEmployee::Display() {
    Employee::Display();
    cout << "Hours: " << hours << endl;
    cout << "Rate: " << rate << endl;
    cout << "Net Salary: " << CalcNetSalary() << endl;
    cout << "Taxable: " << (IsTaxable() ? "Yes" : "No") << endl;
}

SalesPerson::SalesPerson() : WageEmployee(), sales(0), comm(0) {
}

SalesPerson::SalesPerson(int id, const char *n, double sal, int h, int r, int s, int c) : WageEmployee(id, n, sal, h, r), sales(s), comm(c) {
}

double SalesPerson::CalcNetSalary() {
    return WageEmployee::CalcNetSalary() + (sales * comm);
}

bool SalesPerson::IsTaxable() {
    return CalcNetSalary() >= 500000;
}

void SalesPerson::Display() {
    WageEmployee::Display();
    cout << "Sales: " << sales << endl;
    cout << "Commission: " << comm << endl;
    cout << "Net Salary: " << CalcNetSalary() << endl;
    cout << "Taxable: " << (IsTaxable() ? "Yes" : "No") << endl;
}































