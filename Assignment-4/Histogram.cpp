#include "Histogram.h"

//Constructor
Histogram::Histogram(int bins)
{
	this->bins = bins;
	bin_value = new float[bins+1];
	bin_freq = new double[bins];

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
	bin_freq = new double[bins];

	float* ptr = histogram.getBinValues();
	for(int i=0; i<bins+1; i++)
	{
		bin_value[i]=ptr[i];
	}
	
	double * ptr1=histogram.getBinFrequencies();
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

void Histogram::setBinFrequencies(double* binFreqs)
{
	for(int i=0; i<bins; i++)
	{
		bin_freq[i] = binFreqs[i];
	}
}

float* Histogram::getBinValues()
{
	return bin_value;
}

double* Histogram::getBinFrequencies()
{
	return bin_freq;
}

int Histogram::getNumberOfBins()
{
	return bins;
}

void Histogram::setNumberOfBins(int b)
{
	bins = b;
}

double Histogram::euclidean_distance(int size, double* vector1, double* vector2)
{
	double sum=0.0;
	for(int i=0; i<size; i++)
	{
		sum+=(pow(vector1[i] - vector2[i],2));
	}
	return sqrt(sum); 
}

double Histogram::manhattan_distance(int size, double* vector1, double* vector2)
{
	double sum=0.0;
	for(int i=0; i<size ; i++)
	{
		sum+=(abs(vector1[i]-vector2[i]));
	}
	return sum;
}

double Histogram::chebyshev_distance(int size, double* vector1, double* vector2)
{
	double max = fabs(vector1[0]-vector2[0]);
	for(int i=1; i<size; i++)
	{
		if(max < abs(vector1[i]-vector2[i]))
		{
			max = abs(vector1[i]-vector2[i]);
		}
	}
	return max;
}

double Histogram::kl_divergence(int size, double* vector1, double* vector2)
{
	double sum =0.0;
	for(int i=0; i<size ;i++)
	{
		sum+=(vector1[i]*log(vector1[i]/vector2[i]));
	}
	return sum;
}

double Histogram::js_distance(int size, double* vector1, double* vector2)
{
	double* M = new double[size];
	for(int i=0; i<size; i++)
	{
		M[i]=0.5*(vector1[i] + vector2[i]);
	}

	return sqrt( 0.5*kl_divergence(size,vector1,M) + 0.5*kl_divergence(size,vector2,M));
}

void Histogram::normalize(int size, double* vector1, double* vector2)
{
	double sum1=0.0;
	double sum2=0.0;
	int i;
	for(i=0; i<size; i++)
	{
		sum1+=vector1[i];
		sum2+=vector2[i];
	}
	for(i=0; i <size; i++)
	{
		vector1[i]=vector1[i]/sum1;
		vector2[i]=vector2[i]/sum2;
	}
}

