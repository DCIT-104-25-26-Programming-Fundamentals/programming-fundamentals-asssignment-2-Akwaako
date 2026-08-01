#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < scores.size(); i++) {
        sum += scores[i];
    }

    return sum / scores.size();
}

void addStudent(vector<Student>& students) {
    Student newStudent;

    cin.ignore();
    cout << "Student name: ";
    getline(cin, newStudent.name);

    cout << "Student ID: ";
    cin >> newStudent.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        newStudent.scores.push_back(score);
    }

    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << fixed << setprecision(2);

    for (int i = 0; i < students.size(); i++) {
        const Student& s = students[i];

        cout << "Name: " << s.name << endl;
        cout << "ID: " << s.id << endl;
        cout << "Scores: ";
        for (int j = 0; j < s.scores.size(); j++) {
            cout << s.scores[j] << " ";
        }
        cout << endl;
        cout << "Average: " << calculateAverage(s.scores) << endl;
        cout << "--------------------------------" << endl;
    }
}

void findStudentAverage(const vector<Student>& students) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            cout << fixed << setprecision(2);
            cout << students[i].name << "'s average score: "
                 << calculateAverage(students[i].scores) << endl;
            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

void printMenu() {
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        printMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayAllStudents(students);
        } else if (choice == 3) {
            findStudentAverage(students);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Error: Invalid choice. Please enter 1-4." << endl;
        }

        cout << endl;

    } while (choice != 4);

    return 0;
}