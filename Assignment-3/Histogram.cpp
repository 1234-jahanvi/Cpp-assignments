#include "Histogram.h"

//Constructor
Histogram::Histogram()
{
	bins=10;
	bin_value = new float[bins+1];
	bin_freq = new float[bins];

	for(int i=0; i<bins; i++)
	{
		bin_freq[i] = 0;
	}
}

//Copy Constructor
Histogram::Histogram (Histogram &histogram)
{
	//Copying all the values(deep copy)
	bins = histogram.bins;
	bin_value = new float[bins+1];
	bin_freq = new float[bins];

	float* ptr = histogram.getBinValues();
	for(int i=0; i<bins+1; i++)
	{
		bin_value[i]=ptr[i];
	}
	
	ptr=histogram.getBinFrequencies();
	for(int i=0; i<bins; i++)
	{
		bin_freq[i]=ptr[i];
	}

}

void Histogram::setBinValues(float* binValues)
{
	for(int i=0; i<bins+1; i++)
	{
		bin_value[i] = binValues[i];
	}
	
}

void Histogram::setBinFrequencies(float* binFreqs)
{
	for(int i=0; i<bins; i++)
	{
		bin_freq[i] = binFreqs[i]/seqSize;
	}
}

float* Histogram::getBinValues()
{
	return bin_value;
}

float* Histogram::getBinFrequencies()
{
	return bin_freq;
}

int Histogram::getNumberOfBins()
{
	return bins;
}

void Histogram::setSeqSize(int s)
{
	seqSize = s;
}

