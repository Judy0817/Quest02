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
#include <conio.h>

using namespace std;

//-----------------------------string convertor to float---------------------//

/*string balance = "20";
double int_balance;
stringstream ss;
ss << balance;
ss >> int_balance;

string amount = "20.34";
double int_amount;
stringstream ss1;
ss1 << amount;
ss1 >> int_amount;

cout << int_balance + int_amount << endl;
*/

//------------------------------------------------------------------------------//

#define MAX_LINES 1000


	int Balance;
	double Interest;
	double Rate;
	int transactions;


	int Deposit(int Amount, int Balance)
	{
		Balance = Balance + Amount;
		Balance++;
		return Balance;
		//cout << "\n\n\tDeposit Money successfull.\n\tThank You..!" << endl;
	}

	int Withdraw(int Amount, int Balance)
	{
		Balance = Balance - Amount;
		Balance++;
		return Balance;
		//cout << "\n\n\tWithdraw Money successfull.\nThank You..!" << endl;
	}

	double CalInterest()
	{
		Interest = Balance * Rate;
		Balance = Balance + Interest;
		return Interest;
	}


	int getTransactions()
	{
		return transactions;
	}



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

		//------------------Get Line Info comma separate balance sheet------------------------//  

		string Date, AccNo, temp, Balance;

		for (int i = 0; i < 11; i++)
		{
			istringstream ss(array[i]);

			getline(ss, Date, ',');
			getline(ss, AccNo, ',');
			getline(ss, Balance, ',');

			int flt_Balance;
			stringstream ss1;  // 
			ss1 << Balance;
			ss1 >> flt_Balance;

			ofstream myFiles(fileName[i], ofstream::app);
			myFiles << "Date\t\t- " << Date << endl;
			myFiles << "Acount No\t- " << AccNo << endl;
			myFiles << "Opening Balance\t- " << Balance << endl << endl;
			//myFiles << flt_Balance<< endl;
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
		//cout << array2[0] << endl;

		fileTransaction.close();


		//------------------Get Line Info comma separate Transaction sheet------------------------//
		string type, date, accNo, amount;
		for (int j = 0; j < MAX_LINES; j++)
		{
			for (int i = 0; i < 11; i++)
			{
				istringstream ss3(array2[j]);

				getline(ss3, date, ',');
				getline(ss3, accNo, ',');
				getline(ss3, type, ',');
				getline(ss3, amount, ',');

				int flt_Amount;
				stringstream ss2;
				ss2 << amount;
				ss2 >> flt_Amount;

				istringstream ss(array[i]);
				getline(ss, Date, ',');
				getline(ss, AccNo, ',');
				getline(ss, Balance, ',');

				int flt_Balance;
				stringstream ss1;
				ss1 << Balance;
				ss1 >> flt_Balance;

				if (accNo == AccNo)
				{


					if (type == "1") //Deposit
					{
						ifstream myFiles(fileName[i]);
						myFiles >> flt_Balance;
						while (!myFiles.eof())
						{
							myFiles >> flt_Balance;
						}
						flt_Balance = flt_Amount + flt_Balance;
						//Deposit(flt_Amount, flt_Balance);
						//myFiles << "\nYour Balance is  (" << date << ")-Deposit:  " << flt_Balance << endl;
						ofstream myFiles1(fileName[i], ofstream::app);
						myFiles1 << flt_Balance;
					}


					/*	if (type == "2") // Withdraw
						{

							ofstream myFiles(fileName[i], ofstream::app);
							//myFiles << "Type\t\t- Withdraw " << endl;
							//flt_Balance = flt_Balance - flt_Amount;
							myFiles << "\nYour Balance is  (" << date << ")-Withdraw:  " << Withdraw(flt_Amount, flt_Balance) << endl;
						}*/


				}


			}




		}

	}