#ifndef HELPERS
#define HELPERS

#include <iostream>
#include <fstream>
#include <string>

#define NUMS_FILE "instances.txt"
#define PROFILE "profiles.txt"
using namespace std;

void add_number(string fname, string lname, string number) {
    if(number.length() != 10) {
        cout<< "Phone number must contain 10 digits\n";
        return;
    }
    ofstream file;
    file.open(NUMS_FILE, ios::app);
    file << lname << "," << fname << "," << number << endl;
    file.close();
    cout<<"Instance added successfully!\n";
}

bool exists(string inst, string file_name) {
    string line;
    ifstream file(file_name);
    while(getline(file, line)) {
        if(file_name == NUMS_FILE) {
            if(inst == line || inst.substr(inst.length()-11) == line.substr(line.length() - 10) + '\n') {
                return true;
            }
        } else {
            if(inst == line.substr(0, line.find(','))) { return true; }
        }
    }
    return false;
}

string search(string props, char status) {
    string line, name, list_of_names;
    ifstream file(NUMS_FILE);
    if(status == '1') {
        int i = props.find(' ');
        name = props.substr(i+1) + "," + props.substr(0, i);
    }
    while(getline(file, line)) {
        if(status == '1') {
            if(name == line.substr(0, line.length()-11)) { list_of_names += "-" + line; }
            continue;
        }
        if(status == '2') {
            if(line.substr(line.length()-10, line.length()) == props) { return line; }
        }
    }
    if(status == '1') { return list_of_names; }
    return "There is no name with that number\n";
}

bool sign_log(string name, string pass, bool sign=false) {
    if(sign) {
        if(exists(name, PROFILE)) {
            cout << "Username " + name + " is already taken\n";
            return false;
        }
        ofstream file;
        file.open(PROFILE, ios::app);
        file << name << "," << pass << endl;
        file.close();
        cout << "Signed in successfully!\n";
        return true;
    }
    string line;
    ifstream file(PROFILE);
    while(getline(file, line)) {
        if(name == line.substr(0, line.find(','))) {
            if(pass == line.substr(line.find(',')+1, line.length()-1)) {
                cout << "Logged in successfully!\n";
                return true;
            }
            cout << "Wrong password\n";
            return false;
        }
    }
    cout << "There is no profile with that name\nBut you can use sign in to create one\n";
    return false;
}

void rmv(string inst, string file_name) {
    string line, content, msg;
    ifstream file(file_name);
    if(file_name == NUMS_FILE) {
        inst = search(inst, '2');
        if(!exists(inst, NUMS_FILE)) { 
            cout << "Our database contains no name with phone number " + inst.substr(inst.length()-10, inst.length()-1) + '\n';
            return;
        } 
        msg = "Number deleted successfully\n";
    } else {
        if(!exists(inst.substr(0, inst.find(',')), PROFILE)) {
            cout << "There is no profile with the name " + inst.substr(0, inst.find(',')) + '\n';
            return;
        }
        msg = "Account deleted successfully\n";
    }
    while(getline(file, line)) {
        if(file_name == NUMS_FILE) {
            if(inst != line) { content += line + '\n'; }
        } else {    
            if(inst.substr(0, inst.find(',')) == line.substr(0, line.find(','))) {
                if(inst.substr(inst.find(',') + 1, inst.length()-1) != line.substr(line.find(',') + 1, line.length()-1)) {
                    cout << "Wrong password\n";
                    return;
                }
                cout << "Deleting Account..\n";
            } else {
                content += line + '\n';
            }
        }
    }
    file.close();

    ofstream wfile(file_name);
    wfile << content;
    wfile.close();
    cout << msg;
}

void update_acc(string name, string pass) {
    if(!exists(name, PROFILE)) {
        cout << "There is no account with that username\n";
        return;
    }
    string line;
    string content;
    ifstream file(PROFILE);
    while(getline(file, line)) {
        if(name != line.substr(0, line.find(','))) {
            content += line;
        } else {
            if(pass != line.substr(line.find(',') + 1, line.length()-1)) {
                cout << "Wrong password\n";
                return;
            }
            cout << "Enter new password: ";
            cin >> pass;
            line = line.substr(0, line.find(',') + 1) + pass + "\n";
            content += line;
            cout << "Updating..\n";
        }
    }
    ofstream wfile(PROFILE);
    wfile << content;
    wfile.close();
    cout << "Password updated successfully\n";
}

#endif
