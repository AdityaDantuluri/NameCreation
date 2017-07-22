#pragma once
#include <unordered_map>
#include <list>
#include "GetNames.h"
#include <string>
using namespace std;

unordered_map<string, int> oNames;

unordered_map<string, int> getONames() {//return a list of the original names
	return oNames;
}

unordered_map<string, int> buildModel(int order) {//builds a Markov Model of order 'order'-1
	unordered_map<string, int> retmap;
	list<list<char>> names = getNames();
	cin.ignore();
	while (!names.empty()) {
		list<char> name = names.front();
		names.pop_front();
		list<char> tname = name;
		string strName;
		while (!tname.empty()) {
			strName += tname.front();
			tname.pop_front();
		}
		oNames.emplace(strName, 1);//build a list of original names
		string key;
		for (int i = 0; i < order; i++) {
			key.insert(0, "_");
		}
		while (!key.empty()) {
			if (retmap.count(key) <= 0) {
				retmap.emplace(key, 1);
			}
			else {
				retmap.at(key) += 1;
			}

			string temp = key.substr(1, key.size() - 1);
			key = temp;
			if (name.empty()) {
				key.push_back(':');
				if (retmap.count(key) <= 0) {
					retmap.emplace(key, 1);
				}
				else {
					retmap.at(key) += 1;
				}
				key.clear();
			}
			else {
				string s(1, name.front());
				key.insert(key.size(), 1, name.front());
				name.pop_front();
			}
		}
	}
	return retmap;
}
