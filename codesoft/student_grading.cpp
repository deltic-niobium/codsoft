#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    double grade;
};

int main() {
    
    Student newStudent;
        cout << "Enter name of student " << newStudent.name << ": ";
        cin.ignore(); // To clear the input buffer before getline
        getline(cin, newStudent.name);

    int numsubjects;
    cout << "Enter the number of subjects: ";
    cin >> numsubjects;
    
    if(numsubjects<=0)
    {
        cout<<"Grading system is not applicable:";
    }

    vector<Student> students;
    double totalGrade = 0.0;
    double highestGrade = 100.0;
    double lowestGrade = 0.0; // Assuming the grades will be between 0 and 100
    

    for (int i = 0; i < numsubjects; ++i) {
        
        cout << "Enter grade for subject " <<  i + 1 << ": ";
        cin >> newStudent.grade;

        // Update totalGrade, highestGrade, and lowestGrade 
        totalGrade += newStudent.grade;
        highestGrade = max(highestGrade, newStudent.grade);
        lowestGrade = min(lowestGrade, newStudent.grade);

        students.push_back(newStudent);
    }

    double averageGrade = totalGrade / numsubjects;

    // Output the results
    cout << "\n--- Student Grades Summary ---" << endl;
    cout << "Average Grade: " << averageGrade << endl;
    cout << "Highest Grade: " << highestGrade << endl;
    cout << "Lowest Grade: " << lowestGrade << endl;

    return 0;
}
