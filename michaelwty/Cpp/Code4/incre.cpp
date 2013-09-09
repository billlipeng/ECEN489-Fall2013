
#include<iostream>
#include<vector>

using namespace std;

int main(){
	//build vec and Pi's array
	vector<double> vec;
	double pi[50] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3,
			         3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 1, 6, 9, 3, 9, 9, 3, 7, 5, 1};

	//pass Pi to vec and print
	for(int i=0; i<50; ++i)
		vec.push_back(pi[i]);
	auto pbeg = vec.begin();
	cout << "data set: ";
	while(pbeg != vec.end())
		cout << *pbeg++ << ", ";
	cout << endl;

	//arithmetic mean
	double sum = 0;
	for(unsigned int j=0; j<vec.size(); ++j)
		sum = sum + vec[j];
	cout << "arithmetic mean: " << sum/50 <<endl;

	//median
	if(vec.size() % 2 == 0)
		cout << "median: " << (vec[vec.size()/2 - 1] + vec[vec.size()/2])/2 << endl;
	else
		cout << "median: " << vec[vec.size() - 1]/2 << endl;

	//mode
	double temp = 0;
	int count = 1, max_count = 1;
	for(unsigned int i=0; i<vec.size(); ++i){
		temp = vec[i];		//loop over data set
		for(unsigned int j=1; j<vec.size(); ++j){
			if(temp == vec[j])
				count++;		//if get the same digit, plus 1 to count
		}
		if(max_count < count){
			max_count = count;		//set max count for digit if it's bigger
			cout << "mode: " << temp << ", " << max_count << " times" << endl;
		}
		count = 1;
	}

	//unbiased sample variance
	double median = (vec[vec.size()/2 - 1] + vec[vec.size()/2])/2 , temp2 = 0, sum2 =0;
	for(unsigned int i=0; i<vec.size(); ++i){
		temp2 = (vec[i]-median)*(vec[i]-median);
		sum2 += temp2;
	}
	cout << "unbiased sample variance: " << sum/(vec.size()-1) << endl;

	return 0;
}


