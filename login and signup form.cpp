#include <iostream>
#include <fstream>
using namespace std;

class Temp {
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;

public:
    void login();
    void signUP();
    void forgot();
} obj;

int main() {
    char choice;
    do {
        cout << "\n1- Login";
        cout << "\n2- Sign-Up";
        cout << "\n3- Forgot Password";
        cout << "\n4- Exit";
        cout << "\nEnter Your Choice :: ";
        cin >> choice;
        cin.ignore(); // Ensure getline works correctly after cin

        switch (choice) {
            case '1':
                obj.login();
                break;
            case '2':
                obj.signUP();
                break;
            case '3':
                obj.forgot();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid Selection...!";
        }
    } while (choice != '4');
    return 0;
}

void Temp::signUP() {
    cout << "\nEnter Your User Name :: ";
    getline(cin, userName);
    cout << "Enter Your Email Address :: ";
    getline(cin, Email);
    cout << "Enter Your Password :: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << userName << "*" << Email << "*" << password << endl;
        file.close();
        cout << "Registration successful!" << endl;
    } else {
        cout << "Error opening file for registration." << endl;
    }
}

void Temp::login() {
    cout << "----------LOGIN---------\n";
    cout << "Enter Your User Name :: ";
    getline(cin, searchName);
    cout << "Enter Your Password :: ";
    getline(cin, searchPass);

    bool loginSuccess = false;
    file.open("loginData.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password)) {
            if (userName == searchName && password == searchPass) {
                loginSuccess = true;
                cout << "\nAccount Login Successful...!";
                cout << "\nUsername :: " << userName << "\nEmail :: " << Email << endl;
                break;
            }
        }
        file.close();
        if (!loginSuccess) {
            cout << "Invalid username or password!" << endl;
        }
    } else {
        cout << "Error opening file for login." << endl;
    }
}

void Temp::forgot() {
    cout << "\nEnter Your UserName :: ";
    getline(cin, searchName);
    cout << "Enter Your Email Address :: ";
    getline(cin, searchEmail);

    bool accountFound = false;
    file.open("loginData.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password)) {
            if (userName == searchName && Email == searchEmail) {
                accountFound = true;
                cout << "\nAccount Found...!";
                cout << "\nYour Password :: " << password << endl;
                break;
            }
        }
        file.close();
        if (!accountFound) {
            cout << "\nAccount not found or information incorrect!" << endl;
        }
    } else {
        cout << "Error opening file for password retrieval." << endl;
    }
}

