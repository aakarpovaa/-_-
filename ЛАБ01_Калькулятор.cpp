#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double sum(double var1, double var2);

double sub(double var1, double var2);

double mul(double var1, double var2);

double div(double var1, double var2);

unsigned long long fact(int n);

void mat(int matrix1[3][3], int matrix2[3][3]);


int main() {
	while (true) {
		int choice, num3, step;
		double num1, num2;
		float res;
		char operation;
		int matrix1[3][3];
		int matrix2[3][3];

		cout << "Which operation you want to use:" << "\n" << "1 - Sum of matrix" << "\n" << "2 - Typical operations(+, -, *, /, ^, )"
			<< "\n" << "3 - Factorial" << "\n" << "4 - Exit" << "\n";
		cin
			>> choice;

		switch (choice) {
		case 1:
			mat(matrix1, matrix2);
			break;

		case 2:
			cout << "Enter math expression:" << "\n";

			cin >> num1 >> operation >> num2;
			switch (operation) {
			case '+':
				res = num1 + num2;
				cout << "Result =" << res << endl;
				break;

			case '-':
				res = num1 - num2;
				cout << "Result =" << res << endl;
				break;

			case '*':
				res = num1  * num2;
				cout << "Result =" << res << endl;
				break;

			case '/':
				res = num1 / num2;
				cout << "Result =" << res << endl;
				break;

			case '^':
				cout << "Result =" << pow(num1, num2) << endl;
				break;


			default:
				cout << "Unidentified symbol" << endl;
			}
			break;

		case 3:
			cout << "Enter number to find it factorial:" << "\n";
			cin >> num3;
			cout << "Result: " << fact(num3) << endl;
			break;

		case 4:
			cout << "Exiting the program";
			exit(EXIT_SUCCESS);


		default:
			return 0;
		}
	}
}


double sum(double num1, double num2) {
	return num1 + num2;
}

double sub(double num1, double num2) {
	return num1 - num2;
}

double mul(double num1, double num2) {
	return num1 * num2;
}

double div(double num1, double num2) {
	if (num2 == 0) {
		cout << "You cant divide by zero";
	}
	else {
		return num1 / num2;
	}
}

unsigned long long int fact(int n) {
	unsigned long long int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

void mat(int matrix1[3][3], int matrix2[3][3]) {
	cout << "Enter matrix1:" << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix1[i][j] = rand() % 10;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix1[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";

	cout << "Enter matrix2:" << "\t";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix2[i][j] = rand() % 10;
		}
	}

	cout << "\n";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix2[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "Sum of matrix:" << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix1[i][j] + matrix2[i][j] << "\t";
		}
		cout << "\n";
	}

}
