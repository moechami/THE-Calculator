#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Function prototypes
float ComputeSum(const float &a, const float &b);
float ComputeSub(const float &a, const float &b);
float ComputeMul(const float &a, const float &b);
float ComputeDiv(const float &a, const float &b);
float ComputeRoot(const float &a, const int &index);
float ComputePower(const float &a, const int &b);
float ComputePerc(const float &a, const float &b);
int ComputeLCM(int a, int b);
int ComputeGCD(int a, int b);
float ComputeMod(const int &a, const int &b);
bool getFloat(float& userVal, const int maxAttempts, string message, bool clrBuffer);

string WelcomeMessage();
void displayExitMessage();
char displayMenuAndGetChoice();

int main() {
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: To display and loop the main menu as well as display an intitial Welcome Message
**********************************/
    cout << WelcomeMessage();

    bool running = true;
    while (running) {
        char choice = displayMenuAndGetChoice();
        float num1, num2, result;
        int num1i, num2i; // For operations requiring an int as the second parameter

        switch (toupper(choice)) {
            case 'A':
                cout << "Please provide the first number: ";
                cin >> num1;
                cout << "Please provide the second number: ";
                cin >> num2;
                result = ComputeSum(num1, num2);
                cout << "Operation: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case 'B':
                cout << "Please provide the first number: ";
                cin >> num1;
                cout << "Please provide the second number: ";
                cin >> num2;
                result = ComputeSub(num1, num2);
                cout << "Operation: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case 'C':
                cout << "Please provide the first number: ";
                cin >> num1;
                cout << "Please provide the second number: ";
                cin >> num2;
                result = ComputeMul(num1, num2);
                cout << "Operation: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case 'D':
                cout << "Please provide the first number: ";
                cin >> num1;
                cout << "Please provide the second number: ";
                cin >> num2;
                if(num2 == 0) {
                    cout << "Error: Division by zero" << endl;
                    break;
                }
                result = ComputeDiv(num1, num2);
                cout << "Operation: " << num1 << " / " << num2 << " = " << result << endl;
                break;

            case 'E': {
                float base;
                int index;
                bool validInput = false;

                while (!validInput) {
                    validInput = getFloat(base, 3, "Please provide a non-negative number for the base: ", true);
                    if (base < 0) {
                        cout << "Negative numbers are not allowed for the base of the root operation.\n";
                        validInput = false;
                    }
                }

                cout << "Please provide a positive integer for the index (root degree): ";
                cin >> index;
                if (index <= 0) {
                    cout << "The index must be a positive integer.\n";
                }

                if (validInput) {
                    float result = ComputeRoot(base, index);
                    cout << "The root of " << base << " with index " << index << " is " << result << endl;
                }
                break;
            }

            case 'F': {
                float base, exponent, result;
                bool validInputBase = false, validInputExponent = false;

                while (!validInputBase) {
                    validInputBase = getFloat(base, 3, "Please provide a non-negative base: ", true);
                    if (base < 0) {
                        cout << "Negative numbers are not allowed for the base.\n";
                        validInputBase = false; 
                    }
                }

                // Validate exponent
                while (!validInputExponent) {
                    validInputExponent = getFloat(exponent, 3, "Please provide a non-negative exponent: ", true);
                    if (exponent < 0) {
                        cout << "Negative numbers are not allowed for the exponent.\n";
                        validInputExponent = false; 
                    }
                }

                result = ComputePower(base, static_cast<int>(exponent));
                cout << base << " raised to the power of " << exponent << " = " << result << endl;
                break;
}

            case 'G':
                cout << "Please provide the total value: ";
                cin >> num1;
                cout << "Please provide the percentage value: ";
                cin >> num2;
                result = ComputePerc(num1, num2);
                cout << num2 << "% of " << num1 << " = " << result << endl;
                break;

             case 'H': {
                float tempInput1, tempInput2; 
                int num1, num2;
                bool validInput = false;

                while (!validInput) {
                    validInput = getFloat(tempInput1, 3, "Please provide the first non-negative number for LCM: ", true);
                    if (tempInput1 < 0 || float(tempInput1) != tempInput1) {
                        cout << "Only non-negative integers are allowed.\n";
                        validInput = false; 
                    } else {
                        num1 = static_cast<int>(tempInput1);
                    }
                }

                validInput = false;
                while (!validInput) {
                    validInput = getFloat(tempInput2, 3, "Please provide the second non-negative number for LCM: ", true);
                    if (tempInput2 < 0 || float(tempInput2) != tempInput2) {
                        cout << "Only non-negative integers are allowed.\n";
                        validInput = false; 
                    } else {
                        num2 = static_cast<int>(tempInput2);
                    }
                }

                if (validInput) {
                    int lcmResult = ComputeLCM(num1, num2);
                    cout << "LCM of " << num1 << " and " << num2 << " is: " << lcmResult << endl;
                }
                break;
            }

            case 'I': {
                float tempInput1, tempInput2; 
                int num1i, num2i;
                bool validInput = false;

                while (!validInput) {
                    validInput = getFloat(tempInput1, 3, "Please provide the first non-negative number for GCD: ", true);
                    if (tempInput1 < 0) {
                        cout << "Negative numbers are not allowed for this operation.\n";
                        validInput = false; // Ensure non-negative
                    } else {
                        num1i = static_cast<int>(tempInput1); // Convert to int after validation
                        validInput = true;
                    }
                }
                
                validInput = false;
                while (!validInput) {
                    validInput = getFloat(tempInput2, 3, "Please provide the second non-negative number for GCD: ", true);
                    if (tempInput2 < 0) {
                        cout << "Negative numbers are not allowed for this operation.\n";
                        validInput = false; // Ensure non-negative
                    } else {
                        num2i = static_cast<int>(tempInput2); // Convert to int after validation
                        validInput = true;
                    }
                }

                if (validInput) {
                    int result = ComputeGCD(num1i, num2i);
                    cout << "The GCD of " << num1i << " and " << num2i << " is: " << result << endl;
                }
                break;
            }
            case 'J': {
                float tempInput;
                bool validInput = false;
                while (!validInput) {
                    validInput = getFloat(tempInput, 3, "Please provide a non-negative dividend: ", true);
                    if (tempInput < 0) {
                        cout << "Negative numbers are not allowed for this operation.\n";
                        validInput = false;
                    } else {
                        num1i = static_cast<int>(tempInput);
                        cout << "Please provide a non-negative divisor: ";
                        validInput = getFloat(tempInput, 3, "Please provide a non-negative divisor: ", true);
                    if (tempInput <= 0) {
                        cout << "The divisor must be positive and non-zero.\n";
                        validInput = false;
                    } else {
                        num2i = static_cast<int>(tempInput);
                        validInput = true;
                    }
                }
            }
            if (validInput) {
                float result = ComputeMod(num1i, num2i);
                cout << "Modulus of " << num1i << " % " << num2i << " = " << result << endl;
                }
                break;
            }
            case 'K':
                running = false;
                displayExitMessage();
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}

/* Functions for ComputeSum, ComputeSub, ComputeMul, ComputeDiv, ComputeRoot, ComputePower, ComputePerc, ComputeLCM, ComputeGCD, ComputeMod, WelcomeMessage, displayExitMessage, and displayMenuAndGetChoice */

string WelcomeMessage() 
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: A Function to display my Welcome Message
**********************************/
{
    return 
    "----------------------------------------------------------------------\nWELCOME TO THE CALCULATOR PROJECT\n----------------------------------------------------------------------\n";
}

void displayExitMessage() 
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: A function to display my exit message once the user inputs the option 'k' or "k"
**********************************/
{
    cout << "Thank you for using my Calculator Project Simulator. Goodbye!" << endl;
}

char displayMenuAndGetChoice() 
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: A function to display my main menu with the corresponding letter option
**********************************/
{
    char choice;
    cout << "\nA.) Addition" << endl;
    cout << "B.) Subtraction" << endl;
    cout << "C.) Multiplication" << endl;
    cout << "D.) Division" << endl;
    cout << "E.) Roots (only positive numbers)" << endl;
    cout << "F.) Power (only positive numbers)" << endl;
    cout << "G.) Percentage" << endl;
    cout << "H.) Least Common Multiplier (only positive numbers)" << endl;
    cout << "I.) Greatest Common Divisor (only positive numbers)" << endl;
    cout << "J.) Modulus (only positive numbers)" << endl;
    cout << "K.) Quit" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Please select an operation: ";
    cin >> choice;
    return choice;
}

float ComputeSum(const float &a, const float &b) 
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: A function that adds two numbers of type float
**********************************/
{
    return a + b;
}

float ComputeSub(const float &a, const float &b) 
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: A function that subtracts two numbers of type float
**********************************/
{
    return a - b;
}

float ComputeMul(const float &a, const float &b) 
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: A function that multiplies two numbers of type float
**********************************/
{
    return a * b;
}

float ComputeDiv(const float &a, const float &b)
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: A function that divides two numbers of type float
**********************************/
{
    return a / b;
}

float ComputeRoot(const float &root, const int &index) 
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: A premade function that finds the root of two provided numbers of type float and int
**********************************/
{
    float tp, mid, low = 0.0, high = root;

    do {
        mid = (low + high) / 2;
        if (ComputePower(mid, index) > root) 
            high = mid;
        else 
            low = mid;

        mid = (low + high) / 2;
        tp = ComputePower(mid, index) - root;

        if (tp < 0) {      //grab absolute value
            tp = -tp;
        }
    } while (tp > .00005); //accuracy of our root

    return mid;
}

float ComputePower(const float &x, const int &n) 
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: A function that finds the power of one number with another
**********************************/
{
    float numProduct = 1.0;

    for (int i = 0; i < n; i++) {
        numProduct *= x;
    }

    return numProduct;
}

float ComputePerc(const float &a, const float &b) 
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: A function that finds the percentage of two provided numbers of type float
**********************************/
{
    if (b == 0.0f) {
        cout << "Error: Division by zero" << endl;
        return 0.0f;
    }
    return (a / b) * 100.0f;
}

int ComputeLCM(int a, int b) 
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: A function that finds the lowest common multiple of two provided numbers of type int
**********************************/
{
    return ((a * b) / ComputeGCD(a, b));
}

int ComputeGCD(int a, int b) 
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: A function that finds the greatest common divisor of two provided numbers of type int
**********************************/
{
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

float ComputeMod(const int &a, const int &b) 
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: A function that finds the root of two provided numbers
**********************************/
{
    if (b == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return -1;
    }

    int result = a % b;
    return static_cast<float>(result);
}

bool getFloat(float& userVal, const int maxAttempts, string message, bool clrBuffer) 
/**********************************
Name: Mohammad El-Chami
Creation Date: 3/14/2024
Modification Date: 3/25/2024
Purpose: A function that asks for a float n times, returning input by parameter. Return true if within n attempts else return false
**********************************/
{
	int numAttempts = 1;

	cout << message;

	while ((!(cin >> userVal)) && numAttempts < maxAttempts) {
		++numAttempts;
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
		cout << "Invalid input\n" << message;
	}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}

	if (clrBuffer) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return retVal;
}