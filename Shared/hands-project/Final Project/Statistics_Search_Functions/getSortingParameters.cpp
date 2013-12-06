/*
 * getSortingParameters.cpp
 *
 *  Created on: Dec 6, 2013
 *      Author: Brian
 */


#include "test_statistics.h"

void getParameters(string& major, char& gender, char& dominant_hand, int& age, string& identifier)
{
	major = "ANY";
	identifier = "ANY";
	gender = 'A';
	dominant_hand = 'A';
	age = 0;

	cout<<"Enter 'i' if this is an individual record and 'g' if it is a group record"<<endl;
	char x;
	cin>>x;

	if (x == 'i' || x =='I') {
		cout<<"Enter the identifier you would like to search"<<endl;
		cin>>identifier;
	}
	else if (x=='g' || x == 'G') {
	cout<<"Enter a major:";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin,major);

	if (major.empty())
		major = "ANY";
	bool major_temp = (major=="ANY" || major == "any" || major == "a" || major == "A");
	if (major_temp)
		major = "ANY";

	cout<<"Enter a gender:";
	std::cin>>std::noskipws;
	cin>>gender;

	if (gender == '\n')
		gender = 'A';
	gender = toupper(gender);
	std::cin>>std::skipws;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout<<"Enter which dominant hand you want to find: ";
	std::cin>>std::noskipws;
	cin>>dominant_hand;

	if (dominant_hand == '\n')
		dominant_hand = 'A';
	dominant_hand = toupper(dominant_hand);
	std::cin>>std::skipws;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout<<"Enter the age to search for: "<<endl;
	string age_temp;

	std::cin>>std::noskipws;
	cin>>age_temp;
	stringstream ss_age;
	ss_age<<age_temp;

	string age_str = ss_age.str();
	if (age_temp.empty())
		age = 0;

	else if (age_str == "any" || age_str == "a" || age_str == "A" || age_str == "ANY")
		age = 0;

	else
	ss_age>>age;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.clear();
	std::cin>>std::skipws;

	}

	else {
		cerr<<"uh-oh, please enter i or g and nothing else"<<endl;
		getParameters(major,gender,dominant_hand,age,identifier);
	}

	return;

}





