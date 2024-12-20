/* Hunter Brashears
*  Project 2
*  4/3/24
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "banking.h"

Banking::Banking() {
	m_numberOfYears = 0;  // Number of years the program runs for
	m_initialInvestment = 0.0;  // Initial money put in account
	m_monthlyDeposit = 0.0;  // Monthly deposits
	m_interestRate = 0.0;  // Interest rate set as double 
	endBalance = 0.0;  // Used for getEndlingBalance
	interestEarned = 0.0;  // Used for getInterestEarned()
}
// Setter Functions
void Banking::setNumYears(int years) {
	m_numberOfYears = years;
}
void Banking::setInitialInvestment(double initialAmount) {
	m_initialInvestment = initialAmount;
}
void Banking::setMonthlyDeposit(double monthly) {
	m_monthlyDeposit = monthly;
}
void Banking::setInterestRate(double interest) {
	m_interestRate = interest;
}

// Getter Functions
int Banking::getNumYears() {
	return m_numberOfYears;
}
double Banking::getInitialInvestment() {
	return m_initialInvestment;
}
double Banking::getMonthlyDeposit() {
	return m_monthlyDeposit;
}
double Banking::getInterestRate() {
	return m_interestRate;
}

// Welcomes user and sets their initial values
void Banking::welcomeScreen() {
	double t_initial;
	double t_monthly;
	double t_interest;
	int t_years;

	cout << "***************WELCOME****************" << endl;
	cout << "**************************************" << endl;
	cout << "Please enter the following values: " << endl;
	
	// Set initial values with user error handling
	try {
		cout << "Initial Investment Amount: " << endl;
		while (!(cin >> t_initial)) {  
			cout << "Invalid input. Please enter a valid Initial Investment: " << endl;
			cin.clear();  // Clears the error
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard input buffer
		}
		setInitialInvestment(t_initial);  // Sets correct input 

		cout << "Monthly Deposit: " << endl;
		while (!(cin >> t_monthly)) {
			cout << "Invalid input. Please enter a valid Monthly Deposit: " << endl;
			cin.clear();  // Clears the error
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard input buffer
		}
		setMonthlyDeposit(t_monthly);  // Sets correct input 


		cout << "Annual Interest %: " << endl;
		while (!(cin >> t_interest)) {
			cout << "Invalid input. Please enter a valid Annual Interest %: " << endl;
			cin.clear();  // Clears the error
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard input buffer
		}
		setInterestRate(t_interest);  // Sets correct input 


		cout << "Number of years: " << endl;
		while (!(cin >> t_years)) {
			cout << "Invalid input. Please enter a valid number of years: " << endl;
			cin.clear();  // Clears the error
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard input buffer
		}
		setNumYears(t_years);  // Sets correct input 


		cout << "--------------------------------------" << endl;
		cout << endl;
	} catch (const std::exception& e) {
		cerr << "Error: " << e.what() << endl;
		
	}

}


// Display user input values and allows user to quit using 'q'
int Banking::displayBalance() {
	string input;  // Holds user input
	while (input != "q") {
		cout << endl;
		cout << "*************************************" << endl;
		cout << "***********Airgead Banking***********" << endl;
		cout << "Inital Investment Amount: $" << m_initialInvestment << endl;
		cout << "Monthly Deposit: $" << m_monthlyDeposit << endl;
		cout << "Annual Interest: %" << m_interestRate << endl;
		cout << "Number of years: " << m_numberOfYears << endl;
		cout << "Press any key to continue, q to quit" << endl;
		cin >> input;
		// Sets input to lowercase and checks if == 'q' 
		if (tolower(input[0]) == 'q') {
			cout << "Thank you. Exiting program." << endl;
			return 0;
		}
		else {
			break;
		}
	}
	return 0;
}

// Display reports without monthly deposits 
void Banking::displayReports() {
	cout << endl;
	cout << endl;
	cout << "   Balance and Interest Without Additional Monthly Deposits   " << endl;
	cout << "==============================================================" << endl;
	cout << "Year          Year End Balance          Yearly Interest Earned" << endl;
	cout << fixed << setprecision(2);  // Sets output to print 2 places after decimal point
	double yearlyInterest = 0.0;  // Holds total interest accumulated for the year
	double totalInterestWithoutDeposits = 0.0;  // Used to get interest rate

	// Calculates the end balance and interest for each year
	for (int i = 1; i <= m_numberOfYears; ++i) {
		double yearlyInterest = (m_initialInvestment + totalInterestWithoutDeposits) * (m_interestRate / 100);
		totalInterestWithoutDeposits += yearlyInterest;
		endBalance = m_initialInvestment + totalInterestWithoutDeposits;
		cout << i << "             $" << endBalance << "                     $" << yearlyInterest << endl;
		cout << "-------------------------------------------------------------" << endl;
	}
	cout << endl;
	cout << endl;
	// Display reports with monthly deposits 
	cout << "    Balance and Interest With Additional Monthly Deposits     " << endl;
	cout << "==============================================================" << endl;
	cout << "Year          Year End Balance          Interest Earned Yearly" << endl;
	double yearEndBalance = m_initialInvestment; // Sets year end balance to initial investment for first iteration 
	double compoundInterest = 0.0; // Holds interest value for the month, adds to f_yearEndInterest
	double yearEndInterest = 0.0; // Holds total interest accumulated for the year

	// Calculates the end balance and interest for each year 
	for (int j = 1; j <= m_numberOfYears; j++) {
		yearEndInterest = 0.0;  // Resets the value each iteration of outter loop
		for (int h = 1; h <= 12; h++) {
			compoundInterest = (yearEndBalance + m_monthlyDeposit) * ((m_interestRate / 100) / 12);
			yearEndInterest += compoundInterest;
			yearEndBalance += m_monthlyDeposit;
			yearEndBalance += compoundInterest;
			
		}
		cout << j << "             $" << yearEndBalance << "                   $" << yearEndInterest << endl;
		cout << "-------------------------------------------------------------" << endl;
	}
}
