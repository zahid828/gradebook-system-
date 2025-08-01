#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_STUDENTS = 50;
const int MAX_SUBJECTS = 10;


struct Student {
    string name;
    int rollNo;
    string subjectNames[MAX_SUBJECTS];
    float marks[MAX_SUBJECTS];
    float gpa;
};


float calculateGPA(float marks[], int numSubjects) {
    float total = 0;
    for (int i = 0; i < numSubjects; i++) {
        total += marks[i];
    }

    float avg = total / numSubjects;

    if (avg >= 90) return 4.0;
    else if (avg >= 80) return 3.0;
    else if (avg >= 70) return 2.0;
    else if (avg >= 60) return 1.0;
    else return 0.0;
}


void inputStudentData(Student students[], int numStudents, int numSubjects) {
    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, students[i].name);

        cout << "Enter roll number: ";
        cin >> students[i].rollNo;

        for (int j = 0; j < numSubjects; j++) {
            cout << "Enter subject " << j + 1 << " name: ";
            cin >> students[i].subjectNames[j];
            cout << "Enter marks for " << students[i].subjectNames[j] << ": ";
            cin >> students[i].marks[j];
        }

        students[i].gpa = calculateGPA(students[i].marks, numSubjects);
    }
}

void generateAndSaveReport(Student students[], int numStudents, int numSubjects) {
    ofstream outFile("student_report.txt");

    if (!outFile) {
        cout << "Error: Could not create report file.\n";
        return;
    }

    cout << "\n\n===== STUDENT REPORT =====\n";
    outFile << fixed << setprecision(2);
    cout << fixed << setprecision(2);

    for (int i = 0; i < numStudents; i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "Roll No: " << students[i].rollNo << endl;
        cout << "Subjects and Marks:\n";

        outFile << "Name: " << students[i].name << "\n";
        outFile << "Roll No: " << students[i].rollNo << "\n";
        outFile << "Subjects and Marks:\n";

        for (int j = 0; j < numSubjects; j++) {
            cout << "  " << students[i].subjectNames[j] << ": " << students[i].marks[j] << endl;
            outFile << "  " << students[i].subjectNames[j] << ": " << students[i].marks[j] << "\n";
        }

        cout << "GPA: " << students[i].gpa << endl;
        cout << "---------------------------\n";

        outFile << "GPA: " << students[i].gpa << "\n";
        outFile << "---------------------------\n";
    }

    outFile.close();
    cout << "\nReport saved successfully to 'student_report.txt'.\n";
}

int main() {
    int numStudents, numSubjects;
    Student students[MAX_STUDENTS];

    cout << "Enter number of students: ";
    cin >> numStudents;

    cout << "Enter number of subjects per student: ";
    cin >> numSubjects;

    inputStudentData(students, numStudents, numSubjects);
    generateAndSaveReport(students, numStudents, numSubjects);

    return 0;
}

