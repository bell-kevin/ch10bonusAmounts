// ch10bonusAmounts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//create a structure for employees that contains a string for the employee name, an integer for the sales amount for the employee, and a double for the bonus for the employee
struct employee {
	std::string name;
	int salesAmount;
	double bonus;
};

//prototype the function
//Write a function that accepts a pointer to the array to ask the user for the employee names and sales figures to fill the array of structures
void fillArray(employee* emp, int size);
//Write a function that accepts a pointer to the array to determine the bonus for each employee and store it in the structure in the array
void calcBonus(employee* emp, int size);
//Write a function that accepts a pointer to the array to display the information in the structure
void displayArray(employee* emp, int size);
//Use pointer notation for referencing the objects in the array. Use the structure pointer operator, "->", to reference the variables of the structure. You should not use brackets, [ ], except when declaring the array.
int main()
{
    cout << "Chapter 10 Bonus Amounts by Kevin Bell\n\n";
	// Create an array to hold 5 of these employee structures, and create a pointer to that array
	employee employees[5];
	employee* ptr = employees;
	//Call the function to fill the array
	fillArray(ptr, 5);
	//Call the function to calculate the bonus for each employee
	calcBonus(ptr, 5);
	//Call the function to display the array
	displayArray(ptr, 5);
	system("pause");
	return 0;
} // end main

//Write a function that accepts a pointer to the array to ask the user for the employee names and sales figures to fill the array of structures
void fillArray(employee* emp, int size) {
	//Write a loop to ask the user for the employee names and sales figures to fill the array of structures
	for (int i = 0; i < size; i++) {
		cout << "Enter the name of employee " << i + 1 << ": ";
		cin >> emp[i].name;
		//input validation no numbers
		while (emp[i].name.find_first_of("0123456789") != std::string::npos) {
			cout << "Invalid input. Please enter a name without numbers: ";
			cin >> emp[i].name;
		} // end while loop
		cout << "Enter the sales amount for employee " << i + 1 << ": ";
		cin >> emp[i].salesAmount;
		//input validation no negative numbers
		while (emp[i].salesAmount < 0) {
			cout << "Invalid input. Please enter a positive number: ";
			cin >> emp[i].salesAmount;
		} // end while loop
	}// end for loop
		
} // end fillArray

//Write a function that accepts a pointer to the array to determine the bonus for each employee and store it in the structure in the array
//The rules for determining the bonus amounts are: if the employee's sales are $10,000 or more, they get a bonus of 10% of the sales figure; if the employee's sales are $5,000 or more, they get a bonus of 5% of the sales figure; otherwise, the employee gets a bonus of $100
void calcBonus(employee* emp, int size) {
	//Write a loop to determine the bonus for each employee and store it in the structure in the array
	for (int i = 0; i < size; i++) {
		if (emp[i].salesAmount >= 10000) {
			emp[i].bonus = emp[i].salesAmount * .1;
		}
		else if (emp[i].salesAmount >= 5000) {
			emp[i].bonus = emp[i].salesAmount * .05;
		}
		else {
			emp[i].bonus = 100;
		}
	}
} // end calcBonus

//Write a function that accepts a pointer to the array to display the information in the structure
void displayArray(employee* emp, int size) {
	//Write a loop to display the information in the structure
	for (int i = 0; i < size; i++) {
		cout << "Employee " << i + 1 << " name: " << emp[i].name << endl;
		cout << "Employee " << i + 1 << " sales amount: " << emp[i].salesAmount << endl;
		cout << "Employee " << i + 1 << " bonus: " << emp[i].bonus << endl;
	}
} // end displayArray
