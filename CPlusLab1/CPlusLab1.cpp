// CPlusLab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

	//void ReadFile(string FileName);

	// My structures
	struct Date
	{
		int Day;
		int Month;
		int Year;
	};
	struct Time
	{
		int Hour;
		int Min;
		int Sec;
	};
	struct Client
	{
		string FirstName;
		string LastName;
	};
	struct  Bill
	{
		Client MyClient;
		Date MyDate;
		Time MyTime;
		double Amount;
	};

	int main()
	{
		//my number of client
		int  NumberClients;
		Date thisDate;
		ofstream file;
		string filename;
		int CaselastMonth = 1;
		int numberPaidBill=0, numberUnPaidBill = 0,IndexHighestPaidBill=0;
		double sumLastYearBills=0, HighestPaidBill=0;

		cout << "***************Welcome***********************" <<endl;
		cout << "Please enter the Date of the day:" << endl;
		cout << "Day:";
		cin >> thisDate.Day;
		cout << "Month:";
		cin >> thisDate.Month;
		cout << "Year:";
		cin >> thisDate.Year;

		cout << "Please enter the number of Clients you have:\n";
		cin >> NumberClients;

		//creating a bill table corresponding on the number of clients
		Bill* Bills = new Bill[NumberClients];

		//filling the bill table 
		for (int unsigned i =0; i < NumberClients; i++) 
		{
			cout << "***********Client N#" << i + 1 << ":***************" << endl;
			cout << "Enter FirstName :";
			cin>>Bills[i].MyClient.FirstName;
			cout << "Enter LastName :";
			cin >> Bills[i].MyClient.FirstName;

			cout << endl;
			cout << "--Date--" << endl;
			cout << "Enter the Day   :";
			cin >> Bills[i].MyDate.Day;
			cout << "Enter the Month :";
			cin >> Bills[i].MyDate.Month;
			cout << "Enter the Year  :";
			cin >> Bills[i].MyDate.Year;

			cout << "--Time--" << endl;
			cout << "Enter the Hour   :";
			cin >> Bills[i].MyTime.Hour;
			cout << "Enter the Minute :";
			cin >> Bills[i].MyTime.Min;
			cout << "Enter the Second :";
			cin >> Bills[i].MyTime.Sec;
			cout << "Enter the Amount of the bill :";
			cin >> Bills[i].Amount;
			cout << endl;
		}
		

		//creating the method to write the bills of the day in a file
		cout << "Saving in progress.....\n";
		cout << endl;
		for (int unsigned i = 0; i < NumberClients; i++)
		{
			filename = to_string(Bills[i].MyDate.Day) + to_string(Bills[i].MyDate.Month) + to_string(Bills[i].MyDate.Year) +".txt";

			file.open(filename, ios::app);//if the file exist add new contents

			file<< "*********** Client N#" << i + 1 << ":***************" << endl;
			file << "FullName :" + Bills[i].MyClient.FirstName+" "+ Bills[i].MyClient.LastName <<endl;

			file << "Date :  " + to_string(Bills[i].MyDate.Day) + "." + to_string(Bills[i].MyDate.Month) + "." + to_string(Bills[i].MyDate.Year) << endl;
			file << "Time:   " + to_string(Bills[i].MyTime.Hour) + ":" + to_string(Bills[i].MyTime.Min) + ":" + to_string(Bills[i].MyTime.Sec) << endl;
			file << "Amount: " << Bills[i].Amount << endl;
			file.close();
		}
		cout << endl;
		cout << "------------------------" << endl;
		// number of person that paid last year bill
			
		//cout << "Searching last year paid & unpaid bills...." << endl;
		for (int unsigned i = 0; i < NumberClients; i++)
		{					
			if (Bills[i].MyDate.Year == thisDate.Year-1) {
				if (Bills[i].Amount > 0) {
					numberPaidBill += 1;
					sumLastYearBills += Bills[i].Amount;
				}
				else
					numberUnPaidBill += 1;
			}			
		}

		cout <<numberPaidBill+numberUnPaidBill<<" bill(s) found" << endl;
		cout << numberPaidBill << " -paid bill(s)" <<endl;
		cout << numberUnPaidBill << "-unpaid bill(s)" << endl;
		cout << endl;
		cout << "--------------------------" << endl;
		//last year paid bills
		cout << "Total last year paid bills :" << sumLastYearBills;

		//highest paid bill last month
		//case in month 1
		if (thisDate.Month == 1)
			CaselastMonth = 12;
		else
			CaselastMonth = thisDate.Month-1;

		cout << endl;

		
		//cout << "Searching last Month highest paid bill...." << endl;
		for (int i = 0; i < NumberClients - 1; i++)
		{
			if (Bills[i].MyDate.Month == CaselastMonth && Bills[i].MyDate.Year == thisDate.Year) {
				if (Bills[i].Amount) {
					HighestPaidBill = Bills[i].Amount;
					IndexHighestPaidBill = i;
					break;
				}
			}
		}

		for (int  i = 0; i < NumberClients; i++)
		{
			if (Bills[i].MyDate.Month == CaselastMonth && Bills[i].MyDate.Year == thisDate.Year) {
					if (Bills[i].Amount > HighestPaidBill) {
						HighestPaidBill = Bills[i].Amount;
						IndexHighestPaidBill = i;
					}		
			}
		}
		
		cout << endl;
		cout << "----------------------" << endl;
		cout << "Highest paid bill :" << endl;
		cout << "Client N# " << IndexHighestPaidBill+1 << ": "<<endl;
		cout << "FullName :  " << Bills[IndexHighestPaidBill].MyClient.FirstName + " " + Bills[IndexHighestPaidBill].MyClient.LastName<<endl;
		cout << "Amount :  " << Bills[IndexHighestPaidBill].Amount<<endl;
		cout << endl;
	}

	//Writing files 
	/*void ReadFile(string FileName)
	{
		ifstream file(FileName);
		string lines;
		if (file.is_open()) 
		{
			while (getline(file,lines))
			{
				cout << lines << endl;
			}
		}
		file.close();
		
	}*/

	

