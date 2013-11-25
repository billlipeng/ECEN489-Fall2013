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
#include<string>
#include<vector>
#include<numeric>
#include<cmath>
#include<algorithm>
#include<Windows.h>

using namespace std;


//class Score_Record;
//class Stat_Record;

string getQueryMaxMean(string parameter, string major,char gender,int age, char dominant_hand);
string getQueryMedian(string parameter, string major,char gender,int age, char dominant_hand);


//void fetchDataRecordScore(PGconn *conn, vector<Score_Record>&, string = "ANY", char = 'A', int = 0);
//void insertDataPoint(PGconn *conn, string major, char gender, int age, char dom_hand, double score_RVLH, double score_right_RVLH, double score_left_RVLH, double score_LVRH, double score_right_LVRH, double score_left_LVRH, double score, double score_right, double score_left);
//double findMean(vector<double>&);
//double findStandardDeviation(vector<double>&);
//double findMedian(vector<double>&);
//double findCorrelationCoefficient(vector<double>& operand1, vector<double>& operand2);
//void findHistogram(const vector<double>& data, vector<int>& histogram, const int num_bins);
//double getHighScore(PGconn *conn, string major, char gender, int age, string parameter);
//double findLowScore(vector<double>&);
//double findHighScore(vector<double>&);

//Stat_Record compareMaleScores(PGconn*);
//Stat_Record compareFemaleScores(PGconn*);
//Stat_Record compareRightHandedScores(PGconn*);
//Stat_Record compareLeftHandedScores(PGconn*);
//Stat_Record compareAgeGroupScores(PGconn*, int);
//Stat_Record compareMajorScores(PGconn*, string);

//Stat_Record compareVerticalScores(PGconn* conn);
//Stat_Record compareHorizontalScores(PGconn* conn);
//Stat_Record compareRightScores(PGconn* conn);
//Stat_Record compareLeftScores(PGconn* conn);
//Stat_Record compareVerticalScores(vector<Score_Record>& scores);
//Stat_Record compareHorizontalScores(vector<Score_Record>& scores);
//Stat_Record compareRightScores(vector<Score_Record>& scores);
//Stat_Record compareLeftScores(vector<Score_Record>& scores);



//PGconn* connectToDatabase();

//double dot(const vector<double>& A, const vector<double>& B);
//const double pi = 3.14159265359;


//double scorePercentage(const double tilt_angle, const vector<double>& acceleration);

//class Score_Record
//{
//public:

//	Score_Record();

//	double getScoreRVLH();
//	double getScoreRVLHRight();
//	double getScoreRVLHLeft();
//	double getScoreLVRH();
//	double getScoreLVRHRight();
//	double getScoreLVRHLeft();
//	double getScoreTotal();
//	double getScoreTotalRight();
//	double getScoreTotalLeft();

//	double _score_rvlh;
//	double _score_right_rvlh;
//	double _score_left_rvlh;
//	double _score_lvrh;
//	double _score_right_lvrh;
//	double _score_left_lvrh;
//	double _score_total;
//	double _score_right_total;
//	double _score_left_total;


//};

//class Stat_Record
//{
//public:

//	Stat_Record();

//	double _mean;
//	double _median;
//	double _high;
//	double _low;
//	double _stddev;

//};


#endif /* PROJECT_ANALYSIS_STATISTICS_H_ */
