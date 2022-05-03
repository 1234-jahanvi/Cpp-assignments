#ifndef Histogram_h_
#define Histogram_h_
#include <iostream>
#include <iomanip>
using namespace std;
#include <cmath>

inline float truncfunc(float x)
{ 
	return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4;  
}

class Histogram
{
	private:
		float* bin_value;
		double* bin_freq;
		int bins;

	public:
		//Constructor
		Histogram (int bins);

		//Copy Constructor
		Histogram (Histogram &histogram);

		void setBinValues(float* binValues);

		void setBinFrequencies(double* binFreqs);

		float* getBinValues();

		double* getBinFrequencies();

		int getNumberOfBins();

		void setNumberOfBins(int bins);

		friend void distances(Histogram* hist1, Histogram* hist2)
		{
			if(hist1->bins != hist2->bins)
			{
				cerr<<-1<<endl;
			}
			else
			{
				double* vector1 = hist1->getBinFrequencies();
				double* vector2 = hist2->getBinFrequencies();
				hist1->normalize(hist1->bins,vector1,vector2);
				cout.precision(4);
				cout<<fixed;
				cout<<truncfunc(hist1->manhattan_distance(hist1->bins,vector1,vector2))<<" ";
				cout<<truncfunc(hist1->euclidean_distance(hist1->bins,vector1,vector2))<<" ";
				cout<<truncfunc(hist1->chebyshev_distance(hist1->bins,vector1,vector2))<<" ";
				cout<<truncfunc((hist1->kl_divergence(hist1->bins,vector1,vector2)+hist1->kl_divergence(hist1->bins,vector2,vector1)))<<" ";
				cout<<truncfunc(hist1->js_distance(hist1->bins,vector1,vector2))<<endl;
			}
		}

		double euclidean_distance(int size, double* vector1, double* vector2);

		double manhattan_distance(int size, double* vector1, double* vector2);

		double chebyshev_distance(int size, double* vector1, double* vector2);

		double kl_divergence(int size, double* vector1, double* vector2);

		double js_distance(int size, double* vector1, double* vector2);

		void normalize(int size, double* vector1, double* vector2);
};

#endif