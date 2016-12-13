#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void) {
	srand(time(NULL)); // To not have the same numbers over and over again.

	while (true) { // Main loop
		// Initialize and allocate
		int inumber = rand() % 100 + 1; // System number is stored in here.
		int iguess; // User guess is stored in here.
		int itries = 0; // Number of tries is stored here.
		char canswer; // User answer to question is stored here.


		while (true) { // Get user number loop
			// Get number
			std::cout << "Enter a number between 1 and 100 (" << 20 - itries << " tries left): ";
			std::cin >> iguess;
			std::cin.ignore();

			// Check is tries are taken up.
			if (itries >= 20) {
				break;
			}

			// Check number.
			if (iguess > inumber) {
				std::cout << "Too high! Try again.\n";
			}
			else if (iguess < inumber) {
				std::cout << "To low! Try again.\n";
			}
			else {
				break;
			}

			// If not number, increment tries.
			itries++;
		}

		// Check for tries.
		if (itries >= 20) {
			std::cout << "You ran out of tries!\n\n";
		}
		else {
			// Or, user won.
			std::cout << "Congratulations!! " << std::endl;
			std::cout << "You got the rigth number in " << itries << " tries\n";
		}

		while (true) { // Loop to ask user is he/she would like to play again.
					   // Get user response
			std::cout << "Would you like to play again (Y/N)? ";
			std::cin >> canswer;
			std::cin.ignore();

			// Check if proper response.
			if (canswer == 'n' || canswer == 'N' || canswer == 'y' || canswer == 'Y') {
				break;
			}
			else {
				std::cout << "Please enter \'Y\' or \'N\'...\n";
			}
		}

		// Check user's input and run again or exit;
		if (canswer == 'n' || canswer == 'N') {
			std::cout << "Thank you for playing!";
			break;
		}
		else {
			std::cout << "\n\n\n";
		}

	}
	// Safely exit
	std::cout << "\nEnter anything to exit...";
	std::cin.ignore();
	return 0;
}