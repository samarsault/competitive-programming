/*
ID: samarjeet
LANG: C++
TASK: gift1
PROG: gift1
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct Account {
	string name;
	int money;
} Account;

int getindex(Account *acs,int NP, string name)
{
	for (int i = 0;i < NP;i++)
		if (acs[i].name == name)
			return i;
	return -1;
}

int main(int argc, char const *argv[])
{
	ifstream fin;
	ofstream fout;

	// open file
	fin.open("gift1.in");
	fout.open("gift1.out");

	// Logic
	int amt, NP, peep;

	fin >> NP;
	Account *acs = new Account[NP];
	for (int i = 0;i < NP;i++)
	{
		string name;
		fin >> name;
		// initialize account
		acs[i].name = name;
		acs[i].money = 0;
	}

	for (int t = 0; t < NP;t++) // Till End of File
	{
		string giver;
		fin >> giver;
		fin >> amt >> peep;
		// location of giver
		int giverI = getindex(acs, NP, giver);
		for (int i = 0;i < peep;i++)
		{
			string name;
			fin >> name;
			int namei = getindex(acs, NP, name);
			int each = amt / peep;

			acs[namei].money += each;
			acs[giverI].money -= each;
		}
	}

	for (int i = 0;i < NP;i++)
		fout << acs[i].name << " " << acs[i].money << endl;

	// free memory
	delete [] acs;
	// close file
	fin.close();
	fout.close();
	return 0;
}