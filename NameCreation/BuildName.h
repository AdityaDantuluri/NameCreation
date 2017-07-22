#pragma once
#include <unordered_map>
#include <ctime>
#include <list>
#include "GetNames.h"

using namespace std;

list<char> buildList(unordered_map<string, int> map, string bkey);

int getrand(int max) { //returns a random int between 0 and max
	int xRan;
	rand(); rand(); rand();
	xRan = rand() % max; 
	return xRan;
}

string createName(unordered_map<string, int> map, string name, int order) { //Creates a name
	if (name.size() < order) {
		name.insert(0, order - name.size(), '_');
	}
	char lc = name.back();
	while (lc != ':') {
		string bkey = name.substr(name.size() - order + 1, order - 1);
		list<char> cList = buildList(map, bkey);
		int ran = getrand(cList.size());
		list<char>::iterator iter = cList.begin();
		advance(iter, ran);
		name.insert(name.size(), 1, *iter);
		lc = name.back();
	}
	while (name.front() == '_') {
		name = name.substr(1, name.size() - 1);
	}
	name = name.substr(0, name.size() - 1);
	return name;
}

list<char> buildList(unordered_map<string, int> map, string bkey) {//builds a list of possible next characters with each characters occuring a proportional number of times compared to every other character
	list<char> cList;
	for (char c = 'a'; c <= 'z'; c++) {
		string key = bkey + c;
		if (map.count(key) > 0) {
			int temp = map.at(key);
			for (int i = 0; i < temp; i++) {
				cList.push_back(c);
			}
		}
	}
	char c = ':';
	if (map.count(bkey + c) > 0) {
		int temp = map.at(bkey + c);
		for (int i = 0; i < temp; i++) {
			cList.push_back(c);
		}
	}
	return cList;
}

string buildName(unordered_map<string, int> map, int min, int max, int order, string name) { //calls the createName function to get a name but check to make sure the name satisfies the constraints before being passed along
	int nsize = 0;
	string retName;
	while ((nsize < min) || (nsize > max) || (getONames().count(retName) > 0)) {
		retName  = createName(map, name, order);
		nsize = retName.length();
	}
	return retName;
}