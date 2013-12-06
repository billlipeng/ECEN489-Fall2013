/*
 * exportData.cpp
 *
 *  Created on: Dec 6, 2013
 *      Author: Brian
 */




#include "test_statistics.h"

void printVector(vector<double>& data, string filename)
{
	string filepath = "C:\\Users\\Brian\\test_data\\" + filename + ".txt";

	const char* filepath1 = filepath.c_str();
	ofstream file_write;
	file_write.open(filepath1,ofstream::out);

	if (!file_write.is_open()) {
		cerr<<"Error, file did not open properly"<<endl;
		return;
	}

	int siz = data.size();
	for (int i = 0;i < siz; i++) {
		file_write<<data[i]<<'\t'<<endl;
	}

}

void printVector(vector<int>& data, string filename)
{
	string filepath = "C:\\Users\\Brian\\test_data\\" + filename + ".txt";

	ofstream file_write;

	const char* filepath1 = filepath.c_str();
	file_write.open(filepath1,ofstream::out);

	if (!file_write.is_open()) {
		cerr<<"Error, file did not open properly"<<endl;
		return;
	}

	int siz = data.size();
	for (int i = 0;i < siz; i++) {
		file_write<<data[i]<<'\t'<<endl;
	}

}

void removeParameterFile()
{
	string file ="C:\\Users\\Brian\\test_data\\parameter_file.txt";

	const char* strfile = file.c_str();
	remove(strfile);

	return;
}

void removeIdentifierFile()
{
	string file ="C:\\Users\\Brian\\test_data\\identifier_file.txt";

	const char* strfile = file.c_str();
	remove(strfile);

	return;
}

void removeDataFiles(int n)
{

	for (int i = 1;i <= n; i++) {
		stringstream ss_num;
		ss_num<<i;
		string num_str = ss_num.str();

		string filename = "testfile" + num_str;

		string file ="C:\\Users\\Brian\\test_data\\" + filename + ".txt";

		const char* strfile = file.c_str();
		remove(strfile);
	}


	return;
}

void printParameter(string parameter)
{
	string filepath = "C:\\Users\\Brian\\test_data\\parameter_file.txt";
	ofstream parameter_write;
	const char* filepath1 = filepath.c_str();

	parameter_write.open(filepath1,ofstream::app);

	if (!parameter_write.is_open()) {
		cerr<<"Error, Parameter file did not open properly"<<endl;
		return;
	}

	parameter_write<<parameter<<'\t'<<endl;

	return;
}

void printIdentifier(string identifier, string major, char gender, int age, char dominant_hand)
{
	string filepath = "C:\\Users\\Brian\\test_data\\identifier_file.txt";
	ofstream identifier_write;
	const char* filepath1 = filepath.c_str();
	identifier_write.open(filepath1,ofstream::app);

	if (!identifier_write.is_open()) {
		cerr<<"Error, Parameter file did not open properly"<<endl;
		return;
	}

	identifier_write<<identifier<<'\t'<<major<<'\t'<<gender<<'\t'<<age<<'\t'<<dominant_hand<<endl;

	return;
}

string getFilename(int n)
{
	stringstream ss_num;
	ss_num<<n;
	string num_str = ss_num.str();

	string filename = "testfile" + num_str;

	return filename;
}

string getHistFilename(int n)
{
	stringstream ss_num;
	ss_num<<n;
	string num_str = ss_num.str();

	string filename = "histfile" + num_str;

	return filename;
}

