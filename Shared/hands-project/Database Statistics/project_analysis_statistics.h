/*
 * project_analysis_statistics.h
 *
 *  Created on: Nov 21, 2013
 *      Author: Brian
 */

#ifndef PROJECT_ANALYSIS_STATISTICS_H_
#define PROJECT_ANALYSIS_STATISTICS_H_

#include<sstream>
#include<iostream>
#include<fstream>
#include<libpq-fe.h>
#include<string>
#include<vector>
#include<numeric>
#include<cmath>
#include<algorithm>
#include<Windows.h>

using namespace std;


class Score_Record;

void fetchDataRecordScore(PGconn *conn, vector<Score_Record>&, string = "ANY", char = 'A', int = 0);
void insertDataPoint(PGconn *conn, string major, char gender, int age, char dom_hand, double score_RVLH, double score_right_RVLH, double score_left_RVLH, double score_LVRH, double score_right_LVRH, double score_left_LVRH, double score, double score_right, double score_left);
double findMean(vector<double>&);
double findStandardDeviation(vector<double>&);
double findMedian(vector<double>&);
double findCorrelationCoefficient(vector<double>& operand1, vector<double>& operand2);
void findHistogram(const vector<double>& data, vector<int>& histogram, const int num_bins);

PGconn* connectToDatabase();

double dot(const vector<double>& A, const vector<double>& B);
const double pi = 3.14159265359;


double scorePercentage(const double tilt_angle, const vector<double>& acceleration);

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


#endif /* PROJECT_ANALYSIS_STATISTICS_H_ */
