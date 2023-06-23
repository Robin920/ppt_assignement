#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int n = students.size();
    int m = sandwiches.size();

    queue<int> studentQueue;
    for (int i = 0; i < n; i++) {
        studentQueue.push(students[i]);
    }

    int currentIndex = 0;
    int unableToEat = 0;

    while (!studentQueue.empty()) {
        int currentStudent = studentQueue.front();
        studentQueue.pop();

        if (currentStudent == sandwiches[currentIndex]) {
            currentIndex++;
            unableToEat = 0; // Reset the count of unable to eat students
        } else {
            studentQueue.push(currentStudent);
            unableToEat++;

            // If all remaining students are unable to eat, break the loop
            if (unableToEat == studentQueue.size()) {
                break;
            }
        }
    }

    return studentQueue.size();
}

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    int unableToEat = countStudents(students, sandwiches);
    cout << "Number of students unable to eat: " << unableToEat << endl;

    return 0;
}
