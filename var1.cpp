#include "pch.h"
#include <iostream>
#include <fstream>
#include<string>
#include <cstdio>
using namespace std;
int digit_count(int num) {
	int count = 0;
	while (num / 10 > 1) {
		count++;
	}
	return count;
}
int word_count(string line) {
	int count = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ' ' || line[i] == ',') {
			count++;
			if (line[i+1] == ' ' || line[i+1] == ',') {
				count--;
			}
		}
	}
	return count;
}
int main()
{
	string line;
	ifstream fin("numbers.txt");
	ofstream fout("anything.txt");
	string *numbers = new string[10];
	int m = 0;
	string nums = "one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen, twenty, thirty, fourty, fifty, sixty, seventy, eighty, ninety, hundred, thousand, million, ";
	for (int i = 0; i < nums.length(); i++) {
		string num = "";
		while (nums[i] != ',') {
			num += nums[i];
		}
		nums.erase(0, nums.find(' ') + 1);
		numbers[m++] = num;
	}
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			line += ' ';
			int count = word_count(line);
			for (int i = 0; i < count; i++) {
				string str_num = "";
				int k = 0;
				int num;
				while (line[k] != ',' && line[k] != ' ') {
					str_num += line[k];
					k++;
				}
				num = stoi(str_num);
				cout << num << endl;
				fout << num << endl;
				if (str_num.length = 1) {

				}
				line.erase(0, str_num.length());
				k = 0;
				while (line[k] == ' ' || line[k] == ',') {
					k++;
				}
				line.erase(0, k);
			}
		}
		fin.close();
	}
	else {
		cout << "unable to open file";
	}
	system("pause");
}
