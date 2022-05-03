#ifndef DataSequence_h_
#define DataSequence_h_
#include "Histogram.h"

class DataSequence
{
	private:
		float* ptr;
		int size;
		float maximum, minimum, median, mean;
		float *sortedSeq;

	public:

		//Constructor
		DataSequence(int s, float * arrayptr);

		//Destructor
		~DataSequence();

		//Copy constructor
		DataSequence(DataSequence &dseq);

		//Sorts the data sequence and 
		//calculates minimum, maximum,mean and median with this sorted sequence
		void sortAndCalculate();

		//Creates the Histogram
		Histogram createHistogram(int bins);

		float getMinimum();

		float getMaximum();

		float getMedian();

		float getMean();

		float* getSeqPointer();

		int getSeqSize();
};

#endif