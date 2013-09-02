
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <limits>
using std::numeric_limits;

int main(int argc, char **argv)
{
    cout << "Please enter two numbers: ";

    double a = std::numeric_limits<double>::signaling_NaN();
    double b = std::numeric_limits<double>::signaling_NaN();
    
    cin >> a >> b;

    cout << (a + b) << endl;
}
