#ifndef HELPERS
#define HELPERS

#include <iostream>
#include <fstream>
#include <string>

#define NUMS_FILE "instances.csv"
#define PROFILE "profiles.csv"
using namespace std;

bool add_number(string fname, string lname, string number) {
    if(number.length() != 10) {
        return false;
    }
    ofstream file;
    file.open(NUMS_FILE, ios::app);
    file << lname << "," << fname << "," << number << endl;
    file.close();
    return true;
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
            if(line.substr(line.length()-10, line.length()) == props) { return line + '\n'; }
        }
    }
    if(status == '1') {
        if(list_of_names == "") {
            return "No number found\n";
        }
        return list_of_names + '\n'; 
    }
    return "No name found\n";
}

bool sign_log(string name, string pass, bool sign=false) {
    if(sign) {
        if(exists(name, PROFILE)) {
            return false;
        }
        ofstream file;
        file.open(PROFILE, ios::app);
        file << name << "," << pass << endl;
        file.close();
        return true;
    }
    string line;
    ifstream file(PROFILE);
    while(getline(file, line)) {
        if(name == line.substr(0, line.find(','))) {
            if(pass == line.substr(line.find(',')+1, line.length()-1)) {
                return true;
            }
            return false;
        }
    }
    return false;
}

bool rmv(string inst, string file_name) {
    string line, content, msg;
    ifstream file(file_name);
    if(file_name == NUMS_FILE) {
        inst = search(inst, '2');
        if(!exists(inst, NUMS_FILE)) { 
            return false;
        } 
    } else {
        if(!exists(inst.substr(0, inst.find(',')), PROFILE)) {
            return false;
        }
    }
    while(getline(file, line)) {
        if(file_name == NUMS_FILE) {
            if(inst != line + '\n') {
                content += line + '\n'; 
            }
        } else {    
            if(inst.substr(0, inst.find(',')) == line.substr(0, line.find(','))) {
                if(inst.substr(inst.find(',') + 1, inst.length()-1) != line.substr(line.find(',') + 1, line.length()-1)) {
                    return false;
                }
            } else {
                content += line + '\n';
            }
        }
    }
    file.close();

    ofstream wfile(file_name);
    wfile << content;
    wfile.close();
    return true;
}

bool update_acc(string name, string pass, string new_pass) {
    if(!exists(name, PROFILE)) {
        return false;
    }
    string line;
    string content;
    ifstream file(PROFILE);
    while(getline(file, line)) {
        if(name != line.substr(0, line.find(','))) {
            content += line;
        } else {
            if(pass != line.substr(line.find(',') + 1, line.length()-1)) {
                return false;
            }
            line = line.substr(0, line.find(',') + 1) + new_pass + "\n";
            content += line;
        }
    }
    ofstream wfile(PROFILE);
    wfile << content;
    wfile.close();
    return true;
}

#endif
