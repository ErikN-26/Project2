/*
Project Two: Airgead Banking

10/7/25

Erik Nava

*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class CalculateBanking {
private:
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_interestRate;
	int m_numYear;

public:
	// Constructor
	CalculateBanking(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numYear) {
		m_initialInvestment = t_initialInvestment;
		m_monthlyDeposit = t_monthlyDeposit;
		m_interestRate = t_interestRate;
		m_numYear = t_numYear;
	}
	// Method to Calculate balance
	void calculateAndDisplayWithAdditionalDeposits() {
		const int monthsInYear = 12;
		double totalBalance = m_initialInvestment;

		// display the header and yearly balance for additional monthly deposits
		cout << fixed << setprecision(2);
		cout << "Year    Year End Balance    Year End Earned Balance" << endl;
		cout << "---------------------------------------------------" << endl;

		// go through the number of years input by the user
		for (int year = 1; year <= m_numYear; year++) {
			double yearlyInterest = 0.0;

			// go thtrough each month in the year
			for (int month = 1; month <= monthsInYear; month++) {
				double monthlyInterest = (totalBalance + m_monthlyDeposit) * (m_interestRate / 100) / monthsInYear; // calculate the monthly interest
				yearlyInterest = monthlyInterest + yearlyInterest;

				// update the total balance
				totalBalance = m_monthlyDeposit + monthlyInterest + totalBalance;
			}
			// display the result of the year
			cout << year << "         $" << totalBalance << "                $" << yearlyInterest << endl;
		}
	}
	void calculateAndDisplayWithoutAdditionalDeposits() {
		const int monthsInYear = 12;
		double totalBalance = m_initialInvestment;

		// display the header and yearly balance without montlhly deposits
		cout << fixed << setprecision(2);
		cout << "Year    Year End Balance    Year End Earned Balance" << endl;
		cout << "---------------------------------------------------" << endl;

		// go through the years input by the user
		for (int year = 1; year <= m_numYear; year++) {
			double yearlyInterest = 0.0;

			// go through each month in the year
			for (int month = 1; month <= monthsInYear; month++) {
				double monthlyInterest = totalBalance* (m_interestRate / 100) / monthsInYear;
				yearlyInterest = monthlyInterest + yearlyInterest;

				//update total balance
				totalBalance = totalBalance + monthlyInterest;
			}
			//display the result of the year
			cout << year << "         $" << totalBalance << "                 $" << yearlyInterest << endl;
		}
	}
};

int main() {
	// variables to stor user input
	double initialInvestment;
	double monthlyDeposit;
	double interestRate;
	int numYear;

	//prompt the user for their input
	cout << "Initial Investment Amount: $";
	cin >> initialInvestment;
	cout << "Monthly Deposit: $";
	cin >> monthlyDeposit;
	cout << "Annual Interest: %";
	cin >> interestRate;
	cout << "Number of Years: ";
	cin >> numYear;

	// check if the user inputs are valid
	if (initialInvestment < 0 || monthlyDeposit < 0 || interestRate < 0 || numYear <= 0) {
		cout << "Invalid input. Please try again with a positive number." << endl;
		return 1;
	}
	// calculate the users inputs and display the report
	CalculateBanking report(initialInvestment, monthlyDeposit, interestRate, numYear);
	report.calculateAndDisplayWithoutAdditionalDeposits();
	report.calculateAndDisplayWithAdditionalDeposits();

	return 0;
}