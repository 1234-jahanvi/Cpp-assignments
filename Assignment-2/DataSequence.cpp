#include "DataSequence.h"

//Constructor
DataSequence::DataSequence(int s, float * arrayptr)
{
	size = s;
	ptr = new float[size];
	for(int i=0; i<size; i++)
	{
		ptr[i] = arrayptr[i];	
	}
}

//Destructor
DataSequence::~DataSequence()
{
	delete[] ptr;
}

//Copy constructor
DataSequence::DataSequence(DataSequence &dseq)
{
	size = dseq.size;
	ptr = new float[size];		//New memory location for deep copy
	for(int i=0; i<size; i++)
	{
		ptr[i] = dseq.ptr[i];	//Copy value
	}
}

//Sorts the data sequence and 
//calculates minimum, maximum,mean and median with this sorted sequence
void DataSequence::sortAndCalculate()
{
	sortedSeq = new float[size];
	for(int i=0; i< size; i++)
	{
		sortedSeq[i] = ptr[i];
	}

	//Sorting the sequence
	int i,j,min_idx;
	for(i=0; i< size-1; i++)
	{
		min_idx = i;
		for(j=i+1; j< size; j++)
		{
			if(sortedSeq[j] < sortedSeq[min_idx])
			{
				min_idx = j;
			}
		}
		float temp = sortedSeq[i];
		sortedSeq[i]= sortedSeq[min_idx];
		sortedSeq[min_idx] = temp;
	}

	minimum = sortedSeq[0];			//Minimum
	maximum = sortedSeq[size-1];	//Maximum

	//Calculating Mean
	float sum =0;
	for(int i=0; i<size; i++)
	{
		sum = sum + ptr[i];
	}
	mean = sum/size;

	//Calculating Median
	if(size%2==0)
	{
		median = (sortedSeq[size/2 - 1] + sortedSeq[size/2])/2;
	}
	else
	{
		median = sortedSeq[((size+1)/2) - 1];
	}
}

//Creates the Histogram
Histogram DataSequence::createHistogram(int numberOfbins)
{
	Histogram histogram(numberOfbins);

	float binwidth = (maximum - minimum)/numberOfbins;

	float* bin_values = new float[numberOfbins+1];
	int* bin_freq = new int[numberOfbins];

	//Setting the bin values
	bin_values[0] = minimum;
	for(int i=1; i<numberOfbins+1; i++)
	{
		bin_values[i] = bin_values[i-1] + binwidth;
	}

	histogram.setBinValues(bin_values);

	//Setting the bin frequencies
	int i=0;
	int k=0;
	while(i<size)
	{
		if(sortedSeq[i]< bin_values[k+1])
		{
			bin_freq[k]+=1;
			i++;
		}
		else
		{
			k++;
		}
	}
	histogram.setBinFrequencies(bin_freq);

	return histogram;
}

float DataSequence::getMinimum()
{
	return minimum;
}

float DataSequence::getMaximum()
{
	return maximum;
}

float DataSequence::getMedian()
{
	return median;
}

float DataSequence::getMean()
{
	return mean;
}

float* DataSequence::getSeqPointer()
{
	return ptr;
}

int DataSequence::getSeqSize()
{
	return size;
}


