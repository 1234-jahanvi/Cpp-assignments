#include "DataSequence.h"
#include <cmath>

//Constructor
DataSequence::DataSequence(int s, float * arrayptr):fiveValues()
{
	size = s;
	ptr = new float[size];
	for(int i=0; i<size; i++)
	{
		ptr[i] = arrayptr[i];	
	}
}

//Copy constructor
// DataSequence::DataSequence(DataSequence &dseq):fiveValues()
// {
// 	size = dseq.size;
// 	ptr = new float[size];		//New memory location for deep copy
// 	for(int i=0; i<size; i++)
// 	{
// 		ptr[i] = dseq.ptr[i];	//Copy value
// 	}
// }

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

	fiveValues.setMin(sortedSeq[0]);		//Minimum
	fiveValues.setMax(sortedSeq[size-1]);	//Maximum

	//Calculating Median, and Quartiles
	double temp1 = 0.25*(size-1);
	double temp2 = 0.5*(size-1);
	double temp3 = 0.75*(size-1);
	
	float firstQ = calcQuartile(typeCheck(temp1),temp1);
	float median = calcQuartile(typeCheck(temp2),temp2);
	float thirdQ = calcQuartile(typeCheck(temp3),temp3);

	fiveValues.setMedian(median);
	fiveValues.setFirstQ(firstQ);
	fiveValues.setThirdQ(thirdQ);
}

float DataSequence::calcQuartile(std::string str,double temp)
{
	if(str=="float")
	{
		int index1 = floor(temp);
		int index2 = ceil(temp);
		return 0.5*(sortedSeq[index1] + sortedSeq[index2]);
	}
	else if(str=="int")
	{
		return (sortedSeq[(int)temp]);
	}
	else return -1;
}

std::string DataSequence::typeCheck(double temp)
{
	double val = 1e-12;
	int intVal = (int)temp;
	if(fabs(temp - intVal)/temp > val)
	{
		return "float";
	}
	else return "int";
}

//Creates the Histogram
Histogram DataSequence::createHistogram()
{
	Histogram histogram;
	int numberOfbins = histogram.getNumberOfBins();

	float maximum = fiveValues.getMax();
	float minimum = fiveValues.getMin();
	float binwidth = (maximum - minimum)/numberOfbins;

	float* bin_values = new float[numberOfbins+1];
	float* bin_freq = new float[numberOfbins];

	//Setting the bin values
	bin_values[0] = minimum;
	for(int i=1; i<numberOfbins+1; i++)
	{
		bin_values[i] = bin_values[i-1] + binwidth;
	}

	histogram.setBinValues(bin_values);
	histogram.setSeqSize(size);

	//Setting the bin frequencies
	int j=1;
	int k=0;
	bin_freq[0]=1;
	bin_freq[numberOfbins-1]=1;
	while(j < size-1)
	{
		if(sortedSeq[j] < bin_values[k+1])
		{
			bin_freq[k]+=1;
			j++;
		}
		else
		{
			k++;
		}
	}
	histogram.setBinFrequencies(bin_freq);
	return histogram;
}

//Updates whenever the float pointer to datasequence gets changed
void DataSequence::update(int s, float* arrayptr)
{
	size=s;
	for(int i=0; i<size; i++)
	{
		ptr[i] = arrayptr[i];	
	}
	sortAndCalculate();
}


float* DataSequence::getSeqPointer()
{
	return ptr;
}

int DataSequence::getSeqSize()
{
	return size;
}