/*Enter a pin: 4 digits, three tries;
Retry Message: "Invalid PIN, try again..."
Failed Message: "Sorry you can't continue, contact your bank for assistance!"

If the pin is correct, ask the costumer if they want the receipt (1 - yes and 2 - no)

Then the menu will display with 5 possible options:
Get Card Back: display "Goodbye!" and exit program
Fast Cash: Let the customer choose a preset amount of cash - Press 1 - 20, 2 - 40, 3 - 80, 4 - 100
Withdraw: Ask the user to enter the amount of money to withdraw and make sure the balance is capable
Deposit: Ask the user for the amount deposited
Balance: Display the amount of many the customer has
Print the receipt if the customer wants one

Clear screen after each option: system("cls");*/

void enterPIN(int* x);
int calcReceipt();
int menu();
void getCard(float x, float y, float z, float c);
void fastCash(float* x, float* y);
void withdraw(float* x, float* y);
void deposit(float* x, float* y);
void balance(float x);


#include <stdio.h>
#include <stdlib.h>

main() {
	int pin, option, cash = 589, receipt, add = 0, sub = 0;

	enterPIN(&pin);
	if (pin == 1) {
		printf("\n\nAccess Granted!\n\n\n");
		system("pause");
		receipt = calcReceipt;

		for (; option > 0 && option < 5;) {
			option = menu();
			switch (option) {
			case 1: fastCash(&cash, &sub);
				break;
			case 2: withdraw(&cash, &sub);
				break;
			case 3: deposit(&cash, &add);
				break;
			case 4: balance(cash);
				break;
			default: getCard(receipt, add, sub, cash);
				break;
			}//end switch
		}//end for
	}//end if
	else printf("\n\n\tThis account has been locked!\n\tContact your bank for assistance!\n\n\n");
	system("pause");
}//end main
void enterPIN(int* x) {
	int pin, attempts;
	printf("\tWelcome to the Virtual Bank!\n\nEnter PIN: ");
	scanf_s("%d", &pin);
	for (int i = 0; i < 2; i++) {
		if (pin > 999 && pin < 10000) {
			*x = 1;

		}
		else {
			printf("\n\nInvalid PIN!!!\nRe-enter PIN: ");
			scanf_s("%d", &pin);
		}//end else
		attempts = i;
	}//end for
	if (attempts == 2)
		*x = 0;

}//end enterPIN

int menu() {
	system("cls");
	int x;
	printf("Menu\n\n1. Fast Cash\t\t\t2. Withdraw\t\t\t3. Deposit\n4. Balance\t\t\t5. Get Card and Exit");
	scanf_s("%d", x);
	return x;
}

int calcReceipt() {
	system("cls");
	int x;
	printf("Would you like the receipt?\n\t\t1. Yes\t\t\t2. No");
	scanf_s("%D", &x);
	if (x == 1)
		return 1;
	else if (x == 2)
		return 0;
}

void getCard(float x, float y, float z, float c) {
	system("cls");
	if (x == 1)
		printf("Withdraw Total: %f\nDeposit Total: %f\n\tCurrent Balance: %f\n\n", y, z, c);
	printf("Thank You for Using the Bank!\n\tGoodbye!");
}

void fastCash(float* x, float* y) {
	system("cls");
	int z;
	printf("Please select Withdraw Amount:\n\t1: $20\t\t2: $40\n\t3: $80\t\t4: $100");
	scanf_s("%d", &z);
	switch (z) {
	case 1: *x = *x - 20;
		*y = *y + 20;
		break;
	case 2: *x = *x - 40;
		*y = *y + 40;
		break;
	case 3: *x = *x - 80;
		*y = *y + 80;
		break;
	case 4: *x = *x - 100;
		*y = *y + 100;
		break;
	}
}

void withdraw(float* x, float* y) {
	system("cls");
	float z;
	printf("Please Enter Withdraw Amount: ");
	scanf_s("%f", &z);
	*x = *x - z;
	*y = *y + z;
}

void deposit(float* x, float* y) {
	system("cls");
	float z;
	printf("Please Enter Deposit Amount: ");
	scanf_s("%f", z);
	*x = *x - z;
	*y = *y + z;
}

void balance(float x) {
	system("cls");
	printf("Your account balance is: %f", x);
}