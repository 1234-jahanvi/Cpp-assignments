#include "BinomialDistribution.h"

BinomialDistribution::BinomialDistribution(int n, float p):Histogram(n+1)
{
	this->n=n;
	this->p=p;
}

void BinomialDistribution::setN(int n)
{
	this->n=n;
}

void BinomialDistribution::setP(float p)
{
	this->p=p;
}

double BinomialDistribution::pmfValue(int k)
{
	return binCoeff(n,k)*pow(p,k)*pow(1-p,n-k);
}

double BinomialDistribution::binCoeff(int num, int k)
{
	if(k==0) return 1;
	if(k>num/2) return binCoeff(num,num-k);
	return (num*binCoeff(num-1,k-1))/k;
}

void BinomialDistribution::makeHistogram()
{
	int numberOfBins = Histogram::getNumberOfBins();
	float* centers = new float[numberOfBins];
	for(int i=0; i <= n ;i++)
	{
		centers[i]=i;
	}

	float* binValues = new float[numberOfBins+1];
	for(int k=0; k < numberOfBins; k++)
	{
		binValues[k] = centers[k]-0.5;
	}
	binValues[numberOfBins] = binValues[numberOfBins-1] + 1;
	Histogram::setBinValues(binValues);

	double* binFreqs = new double[numberOfBins];
	for(int j=0; j <= n; j++)
	{
		binFreqs[j]= this->pmfValue(j);
	}
	Histogram::setBinFrequencies(binFreqs);
}