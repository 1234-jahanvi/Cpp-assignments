#ifndef Histogram_h_
#define Histogram_h_

class Histogram
{
	private:
		float* bin_value;
		int* bin_freq;
		int bins;

	public:
		//Constructor
		Histogram(int numberOfBins);

		//Copy Constructor
		Histogram (Histogram &histogram);

		void setBinValues(float* binValues);

		void setBinFrequencies(int* binFreqs);

		void setNumberOfBins(int numberOfBins);

		float* getBinValues();

		int* getBinFrequencies();

		int getNumberOfBins();

};

#endif