#include <iostream>
#include <string>
#include "helpers.hpp"

int main() {
    cout<<"Telephone Directory\n";
    cout << "1.Add number\n2.Search Number\n3.Exit\n";
    string fn, ln, n, cmd, prop;
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
                if(inst_exists(fn, ln, n)) {
                    cout << "Instance already exists\n";
                    break;
                }
                add_number(fn, ln, n);
                break;
            case '2':
                cout<<"1.Search by name(<first name> <last name>)\n2.Search by phone number\n";
                cin >> cmd;
                if(cmd[0] != '1' && cmd[0] != '2') {
                    cout<<"Invalid command\n";
                    break;
                }
                cout << "Enter property: ";
                cin.ignore();
                getline(cin, prop);
                cout << search(prop, cmd[0]) << endl;
                break;
            case '3':
                cout<<"Terminating...\n";
                return 0;
            default:
                cout<<"Invalid command\n";
        }
    }
}
