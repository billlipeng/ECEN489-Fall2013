#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){

	stringstream list;
	list << "3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 1, 6, 9, 3, 9, 9, 3, 7, 5, 1, 0, 5, 8, 2, 0, 9, 7, 4, 9, 4, 4, 5, 9, 2, 3, 0, 7, 8, 1, 6, 4, 0, 6, 2, 8, 6, 2, 0, 8, 9, 9, 8, 6, 2, 8, 0, 3, 4, 8, 2, 5, 3, 4, 2, 1, 1, 7, 0, 6, 7, 9, 8, 2, 1, 4"; 	//first 50 decimal digits of pi

	vector<double> digits;
	char trash;
	char num;
	char *digit = &num;
	for (int i = 0 ; i<50 ; ++i)
	{
		//cout << i << endl;
		list >> *digit;		//read one character at a time
		if (*digit != ' ' && *digit != ','){
			digits.push_back((double) atoi(digit));	//convert char to double
		}else{			//if comma or space, try again
			--i;
		}	
	}

	for (int i = 0 ; i<digits.size() ; ++i){
		cout << digits.at(i) << " ";
		if (!((i+1) % 25))		//list 25 per line
			cout << endl;
	}
	cout << endl;
	cout << "Total digits: " << digits.size() << endl;

	//Mean
	cout << "Mean: ";	//standard average
	double sum = 0;
	for (int i = 0 ; i<digits.size() ; ++i)
		sum += digits.at(i);
	double mean = sum/digits.size();
	cout << mean << endl;

	cout << "Median: ";
	sort(digits.begin(),digits.end());	//rearrange elements in ascending order
	if (digits.size() % 2)			//if odd number of entries, pick middle
		cout << digits.at(digits.size()/2-.5);
	else					//if even, average middle two (from definition)
		cout << (digits.at(digits.size()/2)+digits.at(digits.size()/2-1))/2;
	cout << endl;

	/*
	for (int i = 0 ; i<digits.size() ; ++i){
		cout << digits.at(i) << " ";
		if (!((i+1) % 25))
			cout << endl;
	}
	*/

	//Mode
	cout << "Mode: ";
	vector<int> scores;
	for (int i = 0 ; i<digits.size() ; ++i){	//calculate # occurences of each  
		scores.push_back(0);		
		for (int j = 0 ; j<digits.size() ; ++j){
			if (digits.at(j) == digits.at(i)){
				++scores.at(i);
			}
		}
	}
	int max_score = 0;				
	for (int i = 0 ; i<digits.size() ; ++i)		//calculate the highest # occurences
       		if (scores.at(i) > max_score)
			max_score = scores.at(i);
	vector<double> winners;
	for (int i = 0 ; i<digits.size() ; ++i){	//make vector of those with highest #
		bool already = false;			//but only if they're not already in vector
		for (int j = 0 ; j<winners.size() ; ++j)
			if (digits.at(i) == winners.at(j)) //check if already in vector
				already = true;
		if (!(already) && scores.at(i) == max_score)
			winners.push_back(digits.at(i));
	}
	for (int i = 0 ; i<winners.size() ; ++i){	//print winners.
		if (i != 0)
			cout << ", ";
		cout << winners.at(i); 
  	}
	cout << endl;
	
	//Unbiased sample variance
	cout << "Unbiased sample variance: ";
	sum = 0; 
	for (int i = 0 ; i < digits.size() ; ++i){
		sum += (digits.at(i)-mean)*(digits.at(i)-mean);
	}
	cout << sum/(digits.size()-1) << endl;

	cout << endl << "Thanks and Gig 'em!" << endl;        
	return 0;
}
