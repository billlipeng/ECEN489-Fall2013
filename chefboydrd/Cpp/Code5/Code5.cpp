#include <iostream>
using namespace std;


double divideNums(double A, double B) {
        if(B == 0) {
                throw "Error: Can' divide by zero.";
        }
        double result = A/B;
        return result;
}

int main () {
        double Num1, Num2;
        cout << "Gimme two numbers to divide: ";
        cin >> Num1 >> Num2;

        while(1) {
                try {
                //      double Solution = Divide_by_Zero(Num1, Num2);
                        cout << Num1 << "/" << Num2 << " = " << (divideNums(Num1, Num2)) << endl;
                        break;
                }

                catch (const char* message) {
                        cout << "Error: "<< message << endl;
                        cout << "Please input two valid integers: ";
                        cin >> Num1 >> Num2;
                        cout << endl;
                }
        }
        return 0;
}