#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
private:
    string name;
    string title;
    double hourlyWage;
public:
    Employee(string Name, string Title, double HourlyWage) {
        name = Name;
        title = Title;
        hourlyWage = HourlyWage;
    }
    string getName() const {
        return name;
    }
    string getTitle() const {
        return title;
    }
    double getHourlyWage() const {
        return hourlyWage;
    }
    void setName(string Name) {
        name = Name;
    }
    void setTitle(string Title) {
        title = Title;
    }
    void setHourlyWage(double HourlyWage) {
        if (HourlyWage >= 0) {
            hourlyWage = HourlyWage;
        } else {
            hourlyWage = 0.0;
        }
    }
};

int main() {
    vector<Employee> employees;
    employees.push_back(Employee("Alice", "Manager", 35.0));
    employees.push_back(Employee("Bob", "Engineer", 40.0));
    employees.push_back(Employee("Charlie", "Technician", 25.0));
    employees.push_back(Employee("Bray", "HR Specialist", 30.0));
    employees.push_back(Employee("Harley", "Senior Engineer", 50.0));

    cout << "Welcome to the employee database!" << endl;
    cout << "This program tracks employee information, including their name, title, and hourly wage." << endl;
    cout << "It also calculates and displays the total wages based on hours worked.\n" << endl;

    int userInput;
    cout << "Please choose which function you would like to use:" << endl;
    cout << "1. Print list of employees" << endl;
    cout << "2. Calculate total wages" << endl;
    cout << "3. Exit" << endl;
    cin >> userInput;

    while (userInput != 3) {
        if (userInput == 1) {
            cout << "\nList of Employees:" << endl;
            for (const auto& employee : employees) {
                cout << "Name, Title, Hourly Wage: " << employee.getName() << ", " << employee.getTitle() << ", $" << employee.getHourlyWage() << endl;
            }
            cout << "Would you like to use another function?" << endl;
            cout << "1. Print list of employees" << endl;
            cout << "2. Calculate total wages" << endl;
            cout << "3. Exit" << endl;
            cin >> userInput;
        } else if (userInput == 2) {
            double totalWages = 0.0;
            for (const auto& employee : employees) {
                double hoursWorked;
                cout << "Enter hours worked for " << employee.getName() << ": ";
                cin >> hoursWorked;
                if (hoursWorked < 0) {
                    cout << "Invalid input. Hours worked cannot be negative. Try again." << endl;
                    cin >> hoursWorked;
                }
                totalWages += employee.getHourlyWage() * hoursWorked;
            }
            cout << "\nTotal wages for all employees: $" << totalWages << endl;
            cout << "Would you like to use another function?" << endl;
            cout << "1. Print list of employees" << endl;
            cout << "2. Calculate total wages" << endl;
            cout << "3. Exit" << endl;
            cin >> userInput;
        } else if (userInput == 3) {
            cout << "Exiting the program." << endl;
        } else {
            cout << "Invalid input. Please try again." << endl;
            cin >> userInput;
        }
    }

    return 0;
}