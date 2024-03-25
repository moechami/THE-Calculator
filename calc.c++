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
string WelcomeMessage();
void displayExitMessage();
char displayMenuAndGetChoice();

int main() {
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
            case 'E':
                cout << "Please provide the number: ";
                cin >> num1;
                cout << "Please provide the root index: ";
                cin >> num2i;
                result = ComputeRoot(num1, num2i);
                cout << "Root of " << num1 << " is " << result << endl;
                break;
              case 'F':
                cout << "Please provide the number: ";
                cin >> num1;
                cout << "Please provide the power: ";
                cin >> num2i;
                result = ComputePower(num1, num2i);
                cout << num1 << " raised to the power of " << num2i << " = " << result << endl;
                break;
            case 'G':
                cout << "Please provide the total value: ";
                cin >> num1;
                cout << "Please provide the percentage value: ";
                cin >> num2;
                result = ComputePerc(num1, num2);
                cout << num2 << "% of " << num1 << " = " << result << endl;
                break;
             case 'H':
                cout << "Please provide the first number: ";
                cin >> num1i;
                cout << "Please provide the second number: ";
                cin >> num2i;
                cout << "LCM of " << num1i << " and " << num2i << " = " << ComputeLCM(num1i, num2i) << endl;
                break;
            case 'I':
                cout << "Please provide the first number: ";
                cin >> num1i;
                cout << "Please provide the second number: ";
                cin >> num2i;
                cout << "GCD of " << num1i << " and " << num2i << " = " << ComputeGCD(num1i, num2i) << endl;
                break;
               case 'J':
                cout << "Please provide the dividend (number): ";
                cin >> num1i;
                cout << "Please provide the divisor (number): ";
                cin >> num2i;
                if(num2i == 0) {
                    cout << "Error: Division by zero is not allowed." << endl;
                } else {
                    result = ComputeMod(num1i, num2i);
                    cout << "Modulus of " << num1i << " % " << num2i << " = " << result << endl;
                }
                break;   
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

string WelcomeMessage() {
    return 
    "----------------------------------------------------------------------\nWELCOME TO THE CALCULATOR PROJECT\n----------------------------------------------------------------------\n";
}

void displayExitMessage() {
    cout << "Thank you for using my Calculator Project Simulator. Goodbye! ^v^" << endl;
}

char displayMenuAndGetChoice() {
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

float ComputeSum(const float &a, const float &b) {
    return a + b;
}

float ComputeSub(const float &a, const float &b) {
    return a - b;
}

float ComputeMul(const float &a, const float &b) {
    return a * b;
}

float ComputeDiv(const float &a, const float &b){
    return a / b;
}

float ComputeRoot(const float &root, const int &index) {
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

float ComputePower(const float &x, const int &n) {
    float numProduct = 1.0;

    for (int i = 0; i < n; i++) {
        numProduct *= x;
    }

    return numProduct;
}

float ComputePerc(const float &a, const float &b) {
    if (b == 0.0f) {
        cout << "Error: Division by zero" << endl;
        return 0.0f;
    }
    return (a / b) * 100.0f;
}


int ComputeLCM(int a, int b) {
    return ((a * b) / ComputeGCD(a, b));
}


int ComputeGCD(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

float ComputeMod(const int &a, const int &b) {
    if (b == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return -1;
    }

    int result = a % b;
    return static_cast<float>(result);
}
