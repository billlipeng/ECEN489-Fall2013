#include <iostream>
#include <vector>

using namespace std;

int main(){
    double entry = 0;
    vector<double> temps;

    cout << "Enter temperatures in Fahrenheit" << endl
         << "Enter any non-number to finish" << endl;
    while(1){
            cin >> entry;
            if (!cin) break;
            else temps.push_back(entry);
    }

    cout << "Fahrenheit (" << temps.size() << " total):" << endl;
    for (double& i : temps)
            cout << i << endl;
            
    for (double& i : temps)
        i = (i-32)*5/9;
	
    cout << "Celsius (" << temps.size() << " total):" << endl;
    for (double& i : temps)
            cout << i << endl;
                
    return 0;
}
