

#include "project_analysis_statistics.h"

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
	double mean = sum/operand.size();

	double accum = 0.0;
	for (auto iter = operand.begin();iter<operand.end();++iter) {
		accum += (*iter - mean) * (*iter - mean);
	}

	double stddev = sqrt(accum/(operand.size()-1));

	return stddev;

}

double findMedian(vector<double>& operand) 
{
	vector<double> tempData = operand;
	sort(tempData.begin(),tempData.end());

	auto midpt = tempData.begin() + tempData.size()/2;

	double median = *midpt;
		
	return median;
}