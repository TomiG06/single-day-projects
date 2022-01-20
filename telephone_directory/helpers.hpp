#ifndef HELPERS
#define HELPERS

#include <iostream>
#include <fstream>
#include <string>

#define FILE_NAME "instances.txt"
using namespace std;

void add_number(string fname, string lname, string number) {
    if(number.length() != 10) {
        cout<< "Phone number must contain 10 digits\n";
        return;
    }
    ofstream file;
    file.open(FILE_NAME, ios::app);
    file << lname << "," << fname << "," << number << endl;
    file.close();
    cout<<"Instance added successfully!\n";
}

bool inst_exists(string fn, string ln, string n) {
    string line;
    string inst = ln + "," + fn + "," + n + "\n";
    ifstream file(FILE_NAME);
    while(getline(file, line)) {
        if(inst == line || n == line.substr(line.length() - 10)) {
            return true;
        }
    }
    return false;
}

string search(string props, char status) {
    string line, name;
    ifstream file(FILE_NAME);
    if(status == '1') {
        int i = props.find(' ');
        name = props.substr(i+1) + "," + props.substr(0, i);
    }
    while(getline(file, line)) {
        if(status == '1') {
            if(name == line.substr(0, line.length()-11)) { return line; }
            continue;
        }
        if(status == '2') {
            if(line.substr(line.length()-10, line.length()) == props) { return line; }
        }
    }
    return "No profile\n";
}

#endif
