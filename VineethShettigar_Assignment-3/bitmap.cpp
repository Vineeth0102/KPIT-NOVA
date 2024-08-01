#include<iostream>
#include<cstring>
#include"bitmap.h"
using namespace std;

Account::Account() : accno(0), balance(0.0) {
    strcpy(name, "");
}


Account::Account(int acc, const char *n, double bal) : accno(acc), balance(bal) {
    strcpy(name, n);
}

void Account::accept() {
    cout << "Enter Account Number: ";
    cin >> accno;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(name, 100);
    cout << "Enter Balance: ";
    cin >> balance;
}


void Account::display() {
    cout << "Account Number: " << accno << endl;
    cout << "Name: " << name << endl;
    cout << "Balance: " << balance << endl;
}

void Account::deposite(int amount) {
    if(amount > 0) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    } else {
        cout << "Invalid amount!" << endl;
    }
}

void Account::withdraw(int amount) {
    if(amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
    } else {
        cout << "Invalid amount or insufficient balance!" << endl;
    }
}

int Account::getAccno() {
    return accno;
}
    
char* Account::getName() {
    return name;
}

double Account::getBalance() {
    return balance;
}

void Account::setAccno(int id) {
    accno = id;
}

void Account::setName(const char *n) {
    strcpy(name, n);
}

void Account::setBalance(double bal) {
    balance = bal;
}

bool Account::searchAccountById(Account *accounts, int size, int id) {
    for(int i = 0; i < size; i++) {
        if(accounts[i].getAccno() == id) {
            return true;
        }
    }
    return false;
}

double Account::getHighestBalance(Account *accounts, int size) {
    if(size == 0) return 0.0;

    double highestBal = accounts[0].getBalance();
    for(int i = 1; i < size; i++) {
        if(accounts[i].getBalance() > highestBal) {
            highestBal = accounts[i].getBalance();
        }
    }
    return highestBal;
}

double Account::getLowestBalance(Account *accounts, int size) {
    if(size == 0) return 0.0;

    double lowestBal = accounts[0].getBalance();
    for(int i = 1; i < size; i++) {
        if(accounts[i].getBalance() < lowestBal) {
            lowestBal = accounts[i].getBalance();
        }
    }
    return lowestBal;
}













