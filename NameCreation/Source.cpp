#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include "BuildModel.h"
#include "GetNames.h"
#include "BuildName.h"

using namespace std;

int main() {//Main function that gets the inputs and then displays names;

	printf("Baby Name Creation Engine \n");

	printf("Would you like male or female names?(type m or f) ");
	char gen;
	cin >> gen;
	setFile(gen);
	printf("\n");
	printf("What would you like your minimum name length to be? ");
	int min;
	cin >> min;
	printf("\n");
	printf("What would you like your maximum name length to be? ");
	int max;
	cin >> max;
	printf("\n");
	printf("What would you like for the order of the Markov Model? ");
	int order;
	cin >> order;
	printf("\n");
	printf("How many names would you like to generate? ");
	int num;
	cin >> num;
	printf("\n");
	printf("Any letters to start the name off?(use lowercase and leave  _ if no) ");
	string start;
	cin >> start;
	
	unordered_map<string, int> map;
	map = buildModel(order+1);
	unordered_map<string, int> onames = getONames();

	printf("\nNames:\n");
	srand(time(0));
	for (int i = 0; i < num; i++) {
		string name = buildName(map,min,max,order+1,start);
		printName(name);
		printf("\n");
	}

	printf("\nEND\n");
	cin.ignore();
}
