/*
 * test_statistics.h
 *
 *  Created on: Dec 6, 2013
 *      Author: Brian
 */

#ifndef TEST_STATISTICS_H_
#define TEST_STATISTICS_H_


#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include "libpq-fe.h"
#include<sstream>
#include<cmath>
#include<numeric>
#include<cctype>
#include<stdio.h>

using namespace std;

PGconn* connectToDatabase();
void insertDataPoint(PGconn *conn, string, char, int, char, double, double, double, double, double, double, double, double, double, string);

class Score_Record;

void returnVector(vector<Score_Record>& scores, vector<double>& result, string parameter);
double findCorrelationCoefficient(vector<double>& operand1, vector<double>& operand2);
double findMean(vector<double>& operand);
double findStandardDeviation(vector<double>& operand);
double findMedian(vector<double>& operand);
double findHighScore(vector<double>& operand);
double findLowScore(vector<double>& operand);
void findHistogram(const vector<double>& data, vector<int>& histogram, vector<int>& hist_intervals, const int num_bins);

string getQuery(string identifier = "ANY", string major = "ANY",char gender = 'A',int age = 0, char dominant_hand = 'A');
void fetchScoreRecord(PGconn *conn, vector<Score_Record>& result, string query);

void printVector(vector<double>& data, string filename);
void printVector(vector<int>& data, string filename);
void getParameters(string& major, char& gender, char& dominant_hand, int& age, string& identifier);
string getFilename(int n);
void printParameter(string parameter);
void removeParameterFile();
void removeDataFiles(int n);
void removeIdentifierFile();
void printIdentifier(string identifier, string major, char gender, int age, char dominant_hand);
string getHistFilename(int n);



class Score_Record
{
public:

	Score_Record();

	double getScoreRVLH();
	double getScoreRVLHRight();
	double getScoreRVLHLeft();
	double getScoreLVRH();
	double getScoreLVRHRight();
	double getScoreLVRHLeft();
	double getScoreTotal();
	double getScoreTotalRight();
	double getScoreTotalLeft();

	double _score_rvlh;
	double _score_right_rvlh;
	double _score_left_rvlh;
	double _score_lvrh;
	double _score_right_lvrh;
	double _score_left_lvrh;
	double _score_total;
	double _score_right_total;
	double _score_left_total;


};



#endif /* TEST_STATISTICS_H_ */
