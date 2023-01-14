#include<iostream>
#include<math.h>
#include<stack>
#include<fstream>
#include<sstream>
//#include <bits/stdc++.h>
#include <string.h>
#include<stdlib.h>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;


/*	string fileName[11] = {"111111.txt","102340.txt","102341.txt","102342.txt", "102343.txt","102344.txt",
	"201444.txt","201445.txt","201446.txt","201447.txt","201448.txt" };

	ofstream myFiles[11];

	for (int i = 0; i < 11; i++)
	{
		myFiles[i].open(fileName[i].c_str());
		ifstream BalanceFile("balance.txt");
		string Date, AccNo, Amount;
		string myString, line;
		while (getline(BalanceFile, line))
		{
			stringstream ss(line);
			getline(ss, Date, ',');
			getline(ss, AccNo, ',');
			getline(ss, Amount, ',');

			myFiles[i] <<"Date - " << endl;
		}
	}

	ofstream result("111111.txt", ofstream::app);
	result.close();*/

#define MAX_LINES 1000

int main()
{
	//-----------------create account text files-----------------------------//

	string fileName[11] = { "111111.txt","102340.txt","102341.txt","102342.txt", "102343.txt","102344.txt",
	"201444.txt","201445.txt","201446.txt","201447.txt","201448.txt" };
	ofstream myFiles[11];

	for (int i = 0; i < 11; i++)
	{
		myFiles[i].open(fileName[i].c_str());
	
	}
	
	//--------------------get lines in the balance text file into array--------------//

	ifstream fileBalance;
	string array[MAX_LINES];
	fileBalance.open("balance.txt");
	int lines = 0;
	while (!fileBalance.eof())
	{
		fileBalance >> array[lines];
		lines++;
	}

	fileBalance.close();

	//------------------Get Line Info comma separate-----------------------------------------------------------//

	string Date, AccNo,Balance;


	for (int i = 0; i < 11; i++)
	{
		istringstream ss(array[i]);

		getline(ss, Date, ',');
		getline(ss, AccNo, ',');
		getline(ss, Balance, ',');

		ofstream myFiles(fileName[i], ofstream::app);
		myFiles << "Date\t\t- "<<Date<<endl;
		myFiles << "Acount No\t- " << AccNo << endl;
		myFiles << "Balance\t\t- " << Balance << endl;
	}
	
	//--------------------get lines in the transaction text file into array--------------//

	ifstream fileTransaction;
	string array2[MAX_LINES];
	fileTransaction.open("transaction.txt");
	int lines2 = 0;
	while (!fileTransaction.eof())
	{
		fileTransaction >> array2[lines2];
		lines2++;
	}
	cout << array2[0];
	fileTransaction.close();

	/*
		
	string type, amount,date,accNo;
	for (int j = 0; j < MAX_LINES; j++)
	{
		istringstream ss(array2[j]);

		getline(ss, date, ',');
		getline(ss, accNo, ',');
		getline(ss, type, ',');
		getline(ss, amount, ',');


		if (accNo == AccNo)
		{
			for (int j = 0; j < 11; j++)
			{
				ofstream myFiles(fileName[j], ofstream::app);
				myFiles << "Type\t\t- " << type << endl;
				myFiles << "Amount\t\t- " << amount << endl;
			}
			
		}
	}*/


	
}