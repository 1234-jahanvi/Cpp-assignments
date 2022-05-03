#include "Histogram.h"

//Constructor
Histogram::Histogram(int numberOfBins)
{
	bins = numberOfBins;
	bin_value = new float[bins+1];
	bin_freq = new int[bins];

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
	bin_freq = new int[bins];

	float* ptr = histogram.getBinValues();
	for(int i=0; i<bins+1; i++)
	{
		bin_value[i]=ptr[i];
	}
	
	int* ptr1 = histogram.getBinFrequencies();
	for(int i=0; i<bins; i++)
	{
		bin_freq[i]=ptr1[i];
	}

}

void Histogram::setBinValues(float* binValues)
{
	for(int i=0; i<bins+1; i++)
	{
		bin_value[i] = binValues[i];
	}
	
}

void Histogram::setBinFrequencies(int* binFreqs)
{
	for(int i=0; i<bins; i++)
	{
		bin_freq[i] = binFreqs[i];
	}
}

void Histogram::setNumberOfBins(int numberOfBins)
{
	bins = numberOfBins;
}

float* Histogram::getBinValues()
{
	return bin_value;
}

int* Histogram::getBinFrequencies()
{
	return bin_freq;
}

int Histogram::getNumberOfBins()
{
	return bins;
}

