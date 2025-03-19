#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

struct Task {
    string name;
    bool completed;
    string priority;
    string dueDate;
    string category;
};

vector<Task> tasks;
const string filename = "tasks.txt";

void loadTasks() {
    ifstream file(filename);
    tasks.clear();
    if (!file) return;
    string name, priority, dueDate, category;
    bool completed;
    while (file >> completed) {
        file.ignore();
        getline(file, name);
        getline(file, priority);
        getline(file, dueDate);
        getline(file, category);
        tasks.push_back({name, completed, priority, dueDate, category});
    }
    file.close();
}

void saveTasks() {
    ofstream file(filename);
    for (auto &task : tasks)
        file << task.completed << "\n" << task.name << "\n" << task.priority << "\n" << task.dueDate << "\n" << task.category << "\n";
    file.close();
}

string getPriorityColor(const string &priority) {
    if (priority == "High") return RED;
    if (priority == "Medium") return YELLOW;
    if (priority == "Low") return GREEN;
    return RESET;
}

void addTask() {
    Task task;
    cout << "Task ka naam likho: ";
    cin.ignore();
    getline(cin, task.name);
    cout << "Priority likho (High, Medium, Low): ";
    getline(cin, task.priority);
    cout << "Due Date likho (DD/MM/YYYY): ";
    getline(cin, task.dueDate);
    cout << "Category likho (Work, Study, Personal, etc.): ";
    getline(cin, task.category);
    task.completed = false;
    tasks.push_back(task);
    saveTasks();
    cout << GREEN << "Task add ho gaya!" << RESET << "\n";
}

void displayTasks() {
    if (tasks.empty()) {
        cout << RED << "Koi task nahi hai." << RESET << "\n";
        return;
    }
    cout << "\n" << CYAN << "Tumhare Tasks:" << RESET << "\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        string color = getPriorityColor(tasks[i].priority);
        cout << color << "[" << i << "] " << (tasks[i].completed ? "✓ " : "✗ ") << tasks[i].name
             << " (Priority: " << tasks[i].priority << ", Due: " << tasks[i].dueDate
             << ", Category: " << tasks[i].category << ")" << RESET << "\n";
    }
}

void removeTask() {
    displayTasks();
    cout << "Kaunsa task delete karna hai? Index likho: ";
    int index;
    cin >> index;
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        saveTasks();
        cout << GREEN << "Task delete ho gaya!" << RESET << "\n";
    } else {
        cout << RED << "Invalid index!" << RESET << "\n";
    }
}

void markCompleted() {
    displayTasks();
    cout << "Kaunsa task complete kar diya hai? Index likho: ";
    int index;
    cin >> index;
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        saveTasks();
        cout << GREEN << "Task complete ho gaya!" << RESET << "\n";
    } else {
        cout << RED << "Invalid index!" << RESET << "\n";
    }
}

void editTask() {
    displayTasks();
    cout << "Kaunsa task edit karna hai? Index likho: ";
    int index;
    cin >> index;
    cin.ignore();
    if (index >= 0 && index < tasks.size()) {
        cout << "Naya naam likho: ";
        getline(cin, tasks[index].name);
        cout << "Nayi priority likho (High, Medium, Low): ";
        getline(cin, tasks[index].priority);
        cout << "Naya due date likho (DD/MM/YYYY): ";
        getline(cin, tasks[index].dueDate);
        cout << "Nayi category likho: ";
        getline(cin, tasks[index].category);
        saveTasks();
        cout << GREEN << "Task update ho gaya!" << RESET << "\n";
    } else {
        cout << RED << "Invalid index!" << RESET << "\n";
    }
}

void clearCompletedTasks() {
    tasks.erase(remove_if(tasks.begin(), tasks.end(), [](Task &t) { return t.completed; }), tasks.end());
    saveTasks();
    cout << GREEN << "Completed tasks delete ho gaye!" << RESET << "\n";
}

void sortTasks() {
    sort(tasks.begin(), tasks.end(), [](Task &a, Task &b) {
        return a.priority < b.priority;
    });
    cout << YELLOW << "Tasks sort ho gaye priority ke mutabiq!" << RESET << "\n";
    saveTasks();
}

int main() {
    loadTasks();
    while (true) {
        cout << "\n" << BLUE << "To-Do List Manager" << RESET << "\n";
        cout << "1. Task Add Karo\n2. Task Delete Karo\n3. Task Complete Mark Karo\n4. Sab Tasks Dekho\n5. Completed Tasks Hatao\n6. Task Edit Karo\n7. Tasks Sort Karo\n8. Exit\n";
        cout << "Option Choose Karo: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: removeTask(); break;
            case 3: markCompleted(); break;
            case 4: displayTasks(); break;
            case 5: clearCompletedTasks(); break;
            case 6: editTask(); break;
            case 7: sortTasks(); break;
            case 8: cout << GREEN << "Bye!" << RESET; return 0;
            default: cout << RED << "Galat option! Try karo dobara." << RESET << "\n";
        }
    }
}
