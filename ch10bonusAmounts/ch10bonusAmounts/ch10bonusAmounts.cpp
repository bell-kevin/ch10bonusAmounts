// ch10bonusAmounts.cpp : This file contains the 'main' function
//

#include <iostream>
using namespace std;

//create a structure for employees
struct employee {
	std::string name;
	int salesAmount;
	double bonus;
};

//prototype the function
//function fill the array of structures
void fillArray(employee* emp, int size);
//function bonus for each employee and store it
void calcBonus(employee* emp, int size);
//function display the information in the structure
void displayArray(employee* emp, int size);

int main()
{
    cout << "Chapter 10 Bonus Amounts by Kevin Bell\n\n";
	// array to hold 5 of these employee structures
	employee employees[5];
	employee* ptr = employees;
	//fill the array
	fillArray(ptr, 5);
	//calculate the bonus for each employee
	calcBonus(ptr, 5);
	//display the array
	displayArray(ptr, 5);
	system("pause");
	return 0;
} // end main

//function fill the array of structures
void fillArray(employee* emp, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter the name of employee " << i + 1 << ": ";
		cin >> (emp + i)->name;
		//input validation no numbers
		while ((emp + i)->name.find_first_of("0123456789") != std::string::npos) {
			cout << "Invalid input. Please enter a name without numbers: ";
			cin >> (emp + i)->name;
		} // end while loop
		cout << "Enter the sales amount for employee " << i + 1 << ": ";
		cin >> (emp + i)->salesAmount;
		//input validation no negative numbers
		while ((emp + i)->salesAmount < 0) {
			cout << "Invalid input. Please enter a positive number: ";
			cin >> (emp + i)->salesAmount;
		} // end while loop
	}// end for loop	
} // end fillArray function

//function bonus for each employee and store it
void calcBonus(employee* emp, int size) {
	for (int i = 0; i < size; i++) {
		if ((emp + i)->salesAmount >= 10000) {
			(emp + i)->bonus = (emp + i)->salesAmount * .1;
		}
		else if ((emp + i)->salesAmount >= 5000) {
			(emp + i)->bonus = (emp + i)->salesAmount * .05;
		} 
		else {
			(emp + i)->bonus = 100;
		} // end if else
	} // end for loop
} // end calcBonus

//function display the information in the structure
void displayArray(employee* emp, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Employee " << i + 1 << " name: " << (emp + i)->name << endl;
		cout << "Employee " << i + 1 << " sales amount: " << (emp + i)->salesAmount << endl;
		cout << "Employee " << i + 1 << " bonus: " << (emp + i)->bonus << endl;
	} // end for loop
} // end displayArray
