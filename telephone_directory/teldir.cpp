#include <iostream>
#include <string>
#include "helpers.hpp"

#define SUP "ih8cpp" //SUper Password for admins or something

int main() {
    string cmd;
    {
        string name, pass, new_pass;
        bool log_stat = false;
        cout<<"Telephone Directory\n";
        cout<<"1.Sign in\n2.Log in\n3.Delete Account\n4.Update Account\n5.Exit\n";
        while(1) {
            cout << ">> ";
            cin>>cmd;
            switch(cmd[0]) {
                case '1': case '2': case '4':
                    cout << "Enter name: ";
                    cin >> name;
                    cout << "Enter password: ";
                    cin >> pass;
                    if(cmd[0] == '1') {
                        log_stat = sign_log(name, pass, true);
                        if(!log_stat) {
                            cout << "Username " + name + " is already taken\n";
                            break;
                        }  
                        cout << "Signed in successfully!\n";
                    }
                    if(cmd[0] == '2') {
                        log_stat = sign_log(name, pass);
                        if(!log_stat) {
                            cout << "You either enetered a profile that doesn't exist or you entered wrong password\n";
                            break;
                        }
                        cout << "Logged in successfully\n";
                    } 
                    if(cmd[0] == '4') {
                        cout << "Enter new password: ";
                        cin >> new_pass;
                        if(!update_acc(name, pass, new_pass)) {
                            cout << "You either enetered a profile that doesn't exist or you entered wrong password\n";
                            break;
                        }
                        cout << "Password updated successfully!\n";
                    }
                    break;
                case '3':
                    cout << "1.Name-SUP\n2.Name-Pass\n";
                    cin >> cmd;
                    cout << "Enter name: ";
                    cin >> name;
                    cout << "Enter password: ";
                    cin >> pass;
                    if(cmd == "1") {
                        if(pass == SUP) {
                            string line;
                            ifstream sfile(PROFILE);
                            while(getline(sfile, line)) {
                                if(name == line.substr(0, line.find(','))) { break; }
                            }
                            cout << rmv(line ,PROFILE);
                        }
                    } else if(cmd == "2") {
                        cout << rmv(name + ',' + pass, PROFILE);
                    }
                    break;
                case '5':
                    cout<<"Terminating..\n";
                    return 0;
                default:
                    cout<<"Invalid Input\n";
            }
            if(log_stat) {
                system("clear");
                break;
            }
        }
    }
    cout << "1.Add number\n2.Search Number\n3.Delete number (SUP)\n4.Log out\n";
    string fn, ln, n, prop;
    while(true) {
        cout << "Cmd: ";
        cin >> cmd;
        switch(cmd[0]) {
            case '1':
                cout << "Enter first name: ";
                cin >> fn;
                cout << "Enter last name: ";
                cin >> ln;
                cout << "Enter phone number: ";
                cin >> n;
                if(exists(ln + "," + fn + "," + n + "\n", NUMS_FILE)) {
                    cout << "Instance already exists\n";
                    break;
                }
                if(add_number(fn, ln, n)) {
                    cout << "Instance added successfully!\n";
                } else {
                    cout << "Phone number must contain 10 digits\n";
                }
                break;
            case '2':
                cout<<"1.Search by name(<first name> <last name>)\n2.Search by phone number\n>> ";
                cin >> cmd;
                if(cmd[0] != '1' && cmd[0] != '2') {
                    cout<<"Invalid command\n";
                    break;
                }
                cout << "Enter property: ";
                cin.ignore();
                getline(cin, prop);
                cout << search(prop, cmd[0]);
                break;
            case '3':
                cout << "Enter SUP: ";
                cin >> cmd;
                if(cmd == SUP) {
                    cout << "Enter phone number: ";
                    cin >> cmd;
                    cout << rmv(cmd, NUMS_FILE);
                } else {
                    cout << "Wrong SUP\n";
                }
                break;
            case '4':
                cout<<"Terminating...\n";
                return 0;
            default:
                cout<<"Invalid command\n";
        }
    }
}
