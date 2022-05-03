#ifndef DataSequence_h_
#define DataSequence_h_
#include "Histogram.h"
#include <iostream>
#include <cmath>
#include "FiveNumberSummary.h"

inline float truncfunc(float x)
{ 
	return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4;  
}

class DataSequence
{
	private:
		float* ptr;
		int size;
		float *sortedSeq;
		FiveNumberSummary fiveValues;

	public:

		//Constructor
		DataSequence(int s, float * arrayptr);

		//Destructor
		//~DataSequence();
		
		//Copy constructor
		//DataSequence(DataSequence &dseq);

		//Sorts the data sequence and 
		//calculates minimum,maximum,first quartile,third quartile and median with this sorted sequence
		void sortAndCalculate();

		//Calculates the Quartiles according to the datatype of temp
		float calcQuartile(std::string str, double temp);

		//Used to check the datatype (float or int)
		std::string typeCheck(double temp);

		//Creates the Histogram
		Histogram createHistogram();

		//Updates whenever the float pointer to datasequence gets changed
		void update(int s, float* arrayptr);

		float* getSeqPointer();

		int getSeqSize();

		friend std::ostream& operator<< (std::ostream &output, DataSequence &dseq)
		{
			output.precision(4);
			output<<std::fixed;
			output<<truncfunc(dseq.fiveValues.getMin())<<",";
			output<<truncfunc(dseq.fiveValues.getFirstQ())<<",";
			output<<truncfunc(dseq.fiveValues.getMedian())<<",";
			output<<truncfunc(dseq.fiveValues.getThirdQ())<<",";
			output<<truncfunc(dseq.fiveValues.getMax())<<" ";
			
			Histogram histogram;
			histogram = dseq.createHistogram();
			float* binValues = histogram.getBinValues();
			int bins = histogram.getNumberOfBins();
			for(int j=0; j < bins;j++)
			{
				output<<truncfunc(binValues[j])<<",";
			}
			output<<truncfunc(binValues[bins])<<" ";

			float* binFreqs = histogram.getBinFrequencies();
			for(int k=0; k < bins-1;k++)
			{
				output<<truncfunc(binFreqs[k])<<",";
			}
			output<<truncfunc(binFreqs[bins-1])<<" -1";

			return output;
		}
};

#endif