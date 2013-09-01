#include <string>
#include <iostream>
using namespace std;
string line;
int main()
{

	while(getline(cin, line))
		if(!line.empty())
			cout << line <<endl;
	return 0;
}
