#include <iostream>
using namespace std;

class AgeChecker {
public:
    int ages[3] = { 0, 0, 0 };

    string checkCategory(int age) {
        if (age <= ages[0]) return "You are child\n";
        if (age <= ages[1]) return "You are teenager\n";
        return "You are adult\n";
    }
};

// Функция ввода максимального возраста для категории
int readLimit(string message, int minValue, int& errors) {
    int value;

    while (errors < 10) {
        cout << message;
        cin >> value;

        if (!cin.fail() && value > minValue) {
            return value;
        }

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid. Try again.\n";
        errors++;
    }

    return -1;
}

// Функция ввода возраста человека
int readAge(int maxAdult, int& errors) {
    int age;

    while (errors < 10) {
        cout << "Enter person's age: ";
        cin >> age;

        if (!cin.fail() && age >= 0 && age <= maxAdult) {
            return age;
        }

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid. Try again.\n";
        errors++;
    }

    return -1;
}

// Функция вывода результата
void printResult(AgeChecker& ac, int age) {
    cout << ac.checkCategory(age);
}

int main() {
    AgeChecker ac;
    int errors = 0;

    ac.ages[0] = readLimit("Enter max age for child: ", 0, errors);
    if (errors >= 10) { cout << "You are mocking the system.\n"; return 0; }

    ac.ages[1] = readLimit("Enter max age for teenager: ", ac.ages[0], errors);
    if (errors >= 10) { cout << "You are mocking the system.\n"; return 0; }

    ac.ages[2] = readLimit("Enter max age for adult: ", ac.ages[1], errors);
    if (errors >= 10) { cout << "You are mocking the system.\n"; return 0; }

    int age = readAge(ac.ages[2], errors);
    if (errors >= 10) { cout << "You are mocking the system.\n"; return 0; }

    printResult(ac, age);
}
