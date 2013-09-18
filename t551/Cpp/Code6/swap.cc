
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <sstream>
using std::istringstream;
#include <string>
using std::string;

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        cerr << "Please supply two integer arguments." << endl;
        return 1;
    }

    istringstream argstream(string(argv[1]) + " " + string(argv[2]));
    int arg1 = 0;
    int arg2 = 0;
    argstream >> arg2 >> arg1;
    
    if(! argstream)
    {
        cerr << "Please supply two integer arguments." << endl;
        return 1;
    }

    cout << arg1 << " " << arg2;
}
