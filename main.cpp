#include <iostream>
using namespace std;


void displayTime12(int hours, int minutes, int seconds) {
    cout << "Clock12: ";
    cout << ((hours == 0 || hours == 12) ? 12 : hours % 12) << ":";
    cout << ((minutes < 10) ? "0" : "") << minutes << ":";
    cout << ((seconds < 10) ? "0" : "") << seconds << " " << ((hours >= 12) ? "PM" : "AM");
}

void displayTime24(int hours, int minutes, int seconds) {
    cout << "Clock24: ";
    cout << ((hours < 10) ? "0" : "") << hours << ":";
    cout << ((minutes < 10) ? "0" : "") << minutes << ":";
    cout << ((seconds < 10) ? "0" : "") << seconds;
}
void addHour(int &hours, int increment) {
    hours = (hours + increment) % 24;
}

void addMinute(int &minutes, int increment, int &hours) {
    int totalMinutes = minutes + increment;
    int additionalHours = totalMinutes / 60;
    minutes = totalMinutes % 60;
    addHour(hours, additionalHours);
}

void addSecond(int &seconds, int increment) {
    seconds = (seconds + increment) % 60;
}
int main() {
    int hours, minutes, seconds;
    char choice;

    cout << "Enter Initial Time (HH MM SS): ";
    cin >> hours;
    cin >> minutes;
    cin >> seconds;

    // Display the initial time
    displayTime12(hours, minutes, seconds);
    cout << "\t\t";
    displayTime24(hours, minutes, seconds);
    cout << endl;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Hour" << endl;
        cout << "2. Add Minute" << endl;
        cout << "3. Add Second" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '1') {
            int increment;
            cout << "How many hours would you like to add: ";
            cin >> increment;
            addHour(hours, increment);
        } else if (choice == '2') {
            int increment;
            cout << "How many minutes would you like to add: ";
            cin >> increment;
            addMinute(minutes, increment, hours);
        } else if (choice == '3') {
            int increment;
            cout << "How many seconds would you like to add: ";
            cin >> increment;
            addSecond(seconds, increment);
        } else if (choice != '0') {
            cout << "Invalid choice. Please try again." << endl;
        }

        displayTime12(hours, minutes, seconds);
        cout << "\t\t";
        displayTime24(hours, minutes, seconds);
        cout << endl;

    } while (choice != '0');

    return 0;
}