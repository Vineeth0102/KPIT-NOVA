#include "bitmap.h"
#include <iostream>

using namespace std;

/*
    Method to calculate and return Result Grade for Student 
*/

char Student::CalculateGrade() {
    if (TotalMarks == -1) {
        return '-';
    } else if (TotalMarks > 100) {
        return '#';
    } else if (TotalMarks >= 85) {
        return 'O';
    } else if (TotalMarks >= 61) {
        return 'A';
    } else if (TotalMarks >= 40) {
        return 'P';
    } else {
        return 'F';
    }
}

/*
    This method returns the name of the student
*/

std::string Student::GetStudentName() {
    return StudentName;
}


/*
    This method returns the ID of the  student
*/

std::string Student::GetStudentId() {
    return StudentId;
}


/*
    Parameterized constructor for Engineering Student
*/

EngineeringStudent::EngineeringStudent(std::string name, std::string id, int thMarks, int prMarks) 
    : Student(name, id), PractialMarks(prMarks), TheoryMarks(thMarks) {}


/*
    Method to calculate and return Total Marks for EngineeringStudent 
*/


void EngineeringStudent::CalculateMarks() {
    TotalMarks = PractialMarks + TheoryMarks;
}

/*
    Method to return Practical marks of the EngineeringStudent
*/

int EngineeringStudent::GetPracticalMarks() {
    return PractialMarks;
}


/*
    Method to return Theory marks of the EngineeringStudent
*/

char EngineeringStudent::GetTheoryMarks() {
    return TheoryMarks;
}

/*
    Method to get total marks for engineering student
*/

int EngineeringStudent::GetTotalMarks() {
    return TotalMarks;
}


/*
    Parameterized constructor for Architecture Student
*/

ArchitectureStudent::ArchitectureStudent(std::string name, std::string id, int dgMarks, int thMarks) 
    : Student(name, id), DesignMarks(dgMarks), ThesisMarks(thMarks) {}


/*
    Method to calculate and return Total Marks for ArchitectureStudent 
*/

void ArchitectureStudent::CalculateMarks() {
    TotalMarks = DesignMarks + ThesisMarks;
}

/*
    Method to return Design marks of the ArchitectureStudent
*/

int ArchitectureStudent::GetDesignMarks() {
    return DesignMarks;
}
/*
    Method to return Thesis marks of the ArchitectureStudent
*/
char ArchitectureStudent::GetThesisMarks() {
    return ThesisMarks;
}
/*
    This method returns the total marks for architecture student
*/

int ArchitectureStudent::GetTotalMarks() {
    return TotalMarks;
}