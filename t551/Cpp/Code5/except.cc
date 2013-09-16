
#include <iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;
#include <stdexcept>
using std::exception;
using std::runtime_error;

int main(int argc, char **argv)
{
    int a = 0;
    int b = 0;
    
    if(! (cin >> a >> b))
    {
        cerr << "Non-integer supplied." << endl;
        return 1;
    }

    try
    {
        if(b == 0)
            throw runtime_error("Attempted divide by 0.");
        
        cout << (a / b) << endl;
    }
    catch(exception &e)
    {
        cerr << e.what() << endl;
        return 1;
    }
}
