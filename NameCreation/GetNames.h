#pragma once
#include <list>
#include <fstream>
#include <string>

using namespace std;

string sfile = "";

list<list<char>> getNames() {//reads the file char by character into a list of a list of characters. Each secondary list is a Name
	ifstream inFile;
	list<char> name;
	list<list<char>> names;
	inFile.open(sfile);
	string s;
	char n[256];
	char c;
	while (inFile.get(c)) {
		if( c != '\n'){ //End of name so end current list and start another
			name.push_back(tolower(c));
		}
		else {
			names.push_back(name);
			name.clear();
		}
	};
	return names;
}

void printName(string s) {//takes a string and prints it character by character
	printf("%c", toupper(s.at(0)));
	for (int iter = 1; iter != s.length(); iter++) {
		printf("%c", s.at(iter));
	}
}

void setFile(char c) { //sets the file to be read from. 
	if (c == 'm') {
		sfile = "namesBoys.txt";
	}
	else {
		sfile = "namesGirls.txt";
	}
}