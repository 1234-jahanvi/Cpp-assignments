#ifndef Histogram_h_
#define Histogram_h_

class Histogram
{
	private:
		int seqSize;
		float* bin_value;
		float* bin_freq;
		int bins;

	public:
		//Constructor
		Histogram();

		//Copy Constructor
		Histogram (Histogram &histogram);

		void setBinValues(float* binValues);

		void setBinFrequencies(float* binFreqs);

		float* getBinValues();

		float* getBinFrequencies();

		int getNumberOfBins();

		void setSeqSize(int s);
};

#endif