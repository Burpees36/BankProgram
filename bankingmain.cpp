/* Hunter Brashears
*  Project 2
*  4/3/24
*/
#include <iostream>
#include "banking.h"

using namespace std;

int main() {
	Banking agBank;
	
	agBank.welcomeScreen();
	agBank.displayBalance();
	agBank.displayReports();

	return 0;
}