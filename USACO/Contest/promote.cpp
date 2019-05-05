/*
ID: samarjeet
LANG: C++
TASK: promote
*/
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream fin;
	ofstream fout;
	
	// Open File
	fin.open("promote.in");
	fout.open("promote.out");

	pair<int, int> plat, gold, silv, bronze;

	fin >> bronze.first >> bronze.second;
	fin >> silv.first >> silv.second;
	fin >> gold.first >> gold.second;
	fin >> plat.first >> plat.second;

	int prplat = plat.second  - plat.first;
	int prgold = gold.second - gold.first + prplat;
	int prsilver = silv.second - silv.first + prgold;

	fout << prsilver << endl;
	fout << prgold << endl;
	fout << prplat << endl;
	// Close File
	fin.close();
	fout.close();

	return 0;
}