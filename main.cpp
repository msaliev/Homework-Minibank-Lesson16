
//MiniBank


#include <iostream>

using namespace std;

struct User {
    string name;
    float balance;

    User() {
        name = "";
        balance = 0;
    }

    User(string name_, float balance_) {
        name = name_;
        balance = balance_;
    }
};

void printUsers(User users[], int usersCount) {
    cout << "*** All users ***" << endl;
    for(int i=0; i<usersCount; i++) {
        cout << "> Name: " << users[i].name << " | Balance: " << users[i].balance << endl;
    }
}

User addUser() {
    string name;
    float balance;

    cout << "Enter name: "; cin >> name;
    cout << "Enter balance: "; cin >> balance;

    return User(name, balance);;
}

bool userExists(User users[], int usersCount, string userName) {
    for(int i=0; i<usersCount; i++) {
        if(users[i].name == userName) {
            return true;
        }
    }

    return false;
}

int userIndex(User users[], int usersCount, string userName) {
    for(int i=0; i<usersCount; i++) {
        if(users[i].name == userName) {
            return i;
        }
    }

    return -1;
}

int main()
{
    User users[100];
    int usersCount = 0;
    string userName;
    float amount;
    int command = 1;

    while(command != 0) {
        cout << "1. Display Users" << endl;
        cout << "2. Add User" << endl;
        cout << "3. Fill Balance" << endl;
        cout << "4. Withdraw Money" << endl;
        cout << "5. Remove User" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter command: "; cin >> command;

        switch(command) {
            case 1: {
                cout << endl;
                printUsers(users, usersCount);
                cout << endl;
            } break;

            case 2: {
                users[usersCount] = addUser();
                usersCount++;
            } break;

            case 3: {
                cout << "Enter user's name: "; cin >> userName;
                if(userExists(users, usersCount, userName)) {
                    cout << "Enter amount: "; cin >> amount;
                    for(int i=0; i<usersCount; i++) {
                        if(users[i].name == userName) {
                            users[i].balance += amount;
                        }
                    }
                } else {
                    cout << "User does not exist!" << endl;
                }
            } break;

            case 4: {
                cout << "Enter user's name: "; cin >> userName;
                if(userExists(users, usersCount, userName)) {
                    cout << "Enter amount: "; cin >> amount;
                    for(int i=0; i<usersCount; i++) {
                        if(users[i].name == userName) {
                            if(users[i].balance >= amount) {
                                users[i].balance -= amount;
                            } else {
                                cout << "User does not have enough money!" << endl;
                            }
                        }
                    }
                } else {
                    cout << "User does not exist!" << endl;
                }
            } break;

            case 5: {
                cout << "Enter user's name: "; cin >> userName;
                if(userExists(users, usersCount, userName)) {
                    int index = userIndex(users, usersCount, userName);
                    for(int i=index; i<usersCount-1; i++) {
                        users[i] = users[i+1];
                    }
                    usersCount--;
                    cout << "User removed!" << endl;
                } else {
                    cout << "User does not exist!" << endl;
                }
            } break;
        }
    }
    return 0;
}