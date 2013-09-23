//#include <json/json-forwards.h>
#include <json/json.h>

#include<iostream>
#include<sstream>

using namespace std;


int main(){

	Json::Value root;
	cin >> root;
	

	// Get value of the member of root named 'id',
	// return 'unknown' if there is no such member.
	string encoding = root.get("id", "unknown" ).asString();
	cout << "Connected Sensors: " << endl;
	Json::Value sensors = root["sensors"];
	for ( int i = 0; i < sensors.size(); ++i )  // Iterates over the sequence elements.
		//must tell program to represent as string
		cout << i+1 << ") " << sensors[i].asString() << endl;
	
	//change temp scale to Fahrenheiti
	//must tell program to represent read data as double
	root["data"]["temperature"] = root["data"]["temperature"].asDouble()*9.0/5+32;

	double total_distance = 54.6;	//example of previously accumulated data
	root["data"]["total_distance"] = root["data"]["movement"].asDouble() + total_distance;
	
	Json::Value errors = root["data"]["errors"];
	if (errors.size() > 0)
		root["maintanance required"] = true;	//boolean values
	else 
		root["maintanance required"] = false;

	std::cout << root;
	return 0;
}

