/*
 * statistics.cpp
 *
 *  Created on: Dec 6, 2013
 *      Author: Brian
 */




#include "test_statistics.h"

void returnVector(vector<Score_Record>& scores, vector<double>& result, string parameter)
{
	result.clear();
	auto siz = scores.size();

	if (parameter == "total") {
		for (int i= 0; i < siz; i++) {
			result.push_back(scores[i]._score_total);
		}
	}

	if (parameter == "right") {
		for (int i = 0; i < siz; i++) {
			result.push_back(scores[i]._score_right_rvlh + scores[i]._score_right_lvrh);
		}
	}

	if (parameter == "left") {
		for (int i = 0; i < siz; i++) {
			result.push_back(scores[i]._score_left_rvlh + scores[i]._score_left_lvrh);
		}
	}

	if (parameter == "vertical") {
		for (int i = 0; i < siz; i++) {
			result.push_back(scores[i]._score_right_rvlh + scores[i]._score_left_lvrh);
		}
	}

	if (parameter == "horizontal") {
		for (int i = 0; i < siz; i++) {
			result.push_back(scores[i]._score_left_rvlh + scores[i]._score_right_lvrh);
		}
	}

	return;
}

double findCorrelationCoefficient(vector<double>& operand1, vector<double>& operand2)
{

	int n1 = operand1.size();
	int n2 = operand2.size();
	int n = min(n1,n2);

	vector<double> operanda = operand1;
	vector<double> operandb = operand2;

	if(n1!=n2) {
		if(n2>n1) {
			int n_rem = (n2-n1)/2;
			sort(operandb.begin(),operandb.end());
			operandb.erase(operandb.begin(),operandb.begin()+n_rem);
			operandb.erase(operandb.end()-n_rem,operandb.end());
		}
		else {
			int n_rem = (n1-n2)/2;
			sort(operanda.begin(),operanda.end());
			operanda.erase(operanda.begin(),operanda.begin()+n_rem);
			operanda.erase(operanda.end()-n_rem,operanda.end());
		}
	}

	double sum1 = std::accumulate(operanda.begin(), operanda.end(), 0.0);
	double mean1 = sum1/operanda.size();

	double sum2 = std::accumulate(operandb.begin(), operandb.end(), 0.0);
	double mean2 = sum2/operandb.size();

	double accum1 = 0.0;
	for (auto iter = operanda.begin();iter<operanda.end();++iter) {
		accum1 += (*iter - mean1) * (*iter - mean1);
	}

	double stddev1 = sqrt(accum1/(operand1.size()-1));

	double accum2 = 0.0;
	for (auto iter = operandb.begin();iter<operandb.end();++iter) {
		accum2 += (*iter - mean2) * (*iter - mean2);
	}

	double stddev2 = sqrt(accum2/(operand2.size()-1));

	double sum_of_product = 0.0;
	for(int i = 0;i < operanda.size();i++) {
		auto iter1 = operanda.begin() + i;
		auto iter2 = operandb.begin() + i;

		sum_of_product += (*iter1)*(*iter2);
	}

	double corr = (sum_of_product - n*mean1*mean2)/((n-1)*stddev1*stddev2);

	return corr;
}

double findMean(vector<double>& operand)
{
	double sum = std::accumulate(operand.begin(), operand.end(),0.0);
	double mean = sum/operand.size();

	return mean;

}

double findStandardDeviation(vector<double>& operand)
{
	double sum = std::accumulate(operand.begin(), operand.end(), 0.0);
	double mean = sum/(operand.size()-1);

	double accum = 0.0;
	for (auto iter = operand.begin();iter<operand.end();++iter) {
		accum += (*iter - mean) * (*iter - mean);
	}

	double stddev = sqrt(accum/(operand.size()));

	return stddev;

}

double findMedian(vector<double>& operand)
{
	vector<double> temp_data = operand;
	sort(temp_data.begin(),temp_data.end());

	auto midpt = temp_data.begin() + temp_data.size()/2;

	double median = *midpt;

	return median;
}

double findHighScore(vector<double>& operand)
{
	vector<double> temp_data = operand;
	sort(temp_data.begin(),temp_data.end());

	double high_score = *(temp_data.end()-1);

	return high_score;

}

double findLowScore(vector<double>& operand)
{
	vector<double> temp_data = operand;
	sort(temp_data.begin(),temp_data.end());

	double low_score = *(temp_data.begin());

	return low_score;
}


void findHistogram(const vector<double>& data, vector<int>& histogram, vector<int>& hist_intervals, const int num_bins)
{
	vector<double> temp_data = data;
	sort(temp_data.begin(),temp_data.end());

	histogram.clear();

	vector<int> hist_array (num_bins,0);
	vector<int> hist_limit (num_bins,0);
	hist_intervals = hist_limit;

	for (int n = 1; n <= num_bins; n++) {
		hist_intervals[n-1] = n/num_bins*(*(temp_data.end()-1));
	}



	for (auto iter = temp_data.begin(); iter < temp_data.end(); iter++) {
		for (int n = 0; n < num_bins; n++) {
			if ((*iter > (n*((*(temp_data.end()-1))/num_bins))) && (*iter < ((n+1)*((*(temp_data.end()-1))/num_bins))))
				hist_array[n] = hist_array[n] + 1;
		}
	}

	histogram = hist_array;

	return;
}
