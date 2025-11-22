#include <iostream>
using namespace std;

class AgeChecker {
public:
    int ages[3] = { 0, 0, 0 }; // child, teen, adult

    // Функция определения категории
    string checkCategory(int age) const {
        if (age <= ages[0]) return "You are child\n";
        if (age <= ages[1]) return "You are teenager\n";
        return "You are adult\n";
    }
};

int main() {
    AgeChecker ac;
    int age = 0;
    string inputMessage = "Enter max age for ";
    string prompts[3] = { "child: ", "teenager: ", "adult: " };
    string errorMessage = "You are mocking the system.\n";
    string invalidMessage = "Invalid. Try again.\n";
    int errors = 0;

    // Ввод возрастных категорий
    for (int i = 0; i < 3; i++) {
        int input = 0;

        while (errors < 10) {
            cout << inputMessage << prompts[i];
            cin >> input;

            if (cin.fail()) {
                cin.clear(); cin.ignore(10000, '\n');
                errors++; cout << invalidMessage;
            }
            else if (i > 0 && input <= ac.ages[i - 1]) {
                errors++; cout << invalidMessage;
            }
            else if (input <= 0) {
                errors++; cout << invalidMessage;
            }
            else break;
        }

        if (errors >= 10) {
            cout << errorMessage;
            return 0;
        }

        ac.ages[i] = input;
    }

    // Ввод возраста человека
    while (errors < 10) {
        cout << "Enter person's age:\n";
        cin >> age;

        if (cin.fail()) {
            cin.clear(); cin.ignore(10000, '\n');
            errors++; cout << invalidMessage;
        }
        else if (age < 0 || age > ac.ages[2]) {
            errors++; cout << invalidMessage;
        }
        else break;
    }

    if (errors >= 10) {
        cout << errorMessage;
        return 0;
    }

    // Используем функцию из класса
    cout << ac.checkCategory(age);
}