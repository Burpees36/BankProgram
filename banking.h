/* Hunter Brashears
*  Project 2
*  4/3/24
*/
#pragma once
#ifndef banking_h
#define banking_h

#include <string>
using namespace std;

class Banking {
private:
	int m_numberOfYears; // Hold user input 
	double m_initialInvestment, m_monthlyDeposit, m_interestRate;  // Hold user input 
	
	
public:
	double endBalance, interestEarned;  // Used for calculations of interest earned and ending balances 
	Banking(); // Constructor

	// Setters
	void setNumYears(int);
	void setInitialInvestment(double);
	void setMonthlyDeposit(double);
	void setInterestRate(double);
	
	// Getters
	int getNumYears();
	double getInitialInvestment();
	double getMonthlyDeposit();
	double getInterestRate();

	// Welcome user and set initial values
	void welcomeScreen();

	// Display user data reports
	int displayBalance();
	void displayReports();

};
#endif banking_h