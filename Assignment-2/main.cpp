#include <iostream>
#include <string>
#include <cmath>
#include "DataSequence.h"
using namespace std;

inline float truncfunc(float x)
{ 
	return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4;  
}

int main()
{
	string input;
	getline(cin,input);					//Input string

	string parts[3];
	string part="";
	int i=0;
	int k=0;
	while(i < (int)(input.length()))
	{
		if(input[i]=='-')				//-1 delimiter check
		{
			parts[k]=part;
			k++;
			part="";
			i+=2;
		}
		else
		{
			if(input[i]!=' ')
			{
				part = part + input[i];
			}
			i++;
		}
	}

	if(k!=3)							//Incorrect input check
	{
		cout<<"-1"<<endl;
		return 0;
	}

	int size = stoi(parts[0]);
	int bins = stoi(parts[2]);
	string values = parts[1];

	if(bins<=0)							//Incorrect input check
	{
		cout<<"-1"<<endl;
		return 0;
	}

	float* dataseq = new float[size];	//Data Sequence Array
	string value="";
	int j=0;
	k=0;
	while(j < (int)(values.length()))
	{
		if(values[j]==',')				// delimiter check
		{
			dataseq[k]=stof(value);
			k++;
			value="";
		}
		else
		{
			value=value+values[j];
		}
		j++;
	}
	dataseq[k]=stof(value);
	k++;

	if(k!=size)							//Incorrect input check
	{
		cout<<"-1"<<endl;
		return 0;
	}

	int flag=0;
	for(i=0; i<size; i++)
	{
		if(dataseq[i]==0)				//Incorrect input check
		{
			cout<<"-1"<<endl;
			flag=1;
		}
	}
	if(flag==1) return 0;

	cout.precision(4);
	cout<<fixed;

	DataSequence obj(size,dataseq);
	obj.sortAndCalculate();
	cout<<truncfunc(obj.getMinimum())<<" -1 ";
	cout<<truncfunc(obj.getMean())<<" -1 ";
	cout<<truncfunc(obj.getMedian())<<" -1 ";
	cout<<truncfunc(obj.getMaximum())<<" -1 ";
	
	Histogram histogram(bins);
	histogram = obj.createHistogram(bins);

	float* binValues = histogram.getBinValues();
	int* binFreqs = histogram.getBinFrequencies();

	for(int i=0; i<bins; i++)
	{
		cout<<truncfunc(binValues[i])<<",";
	}
	cout<<binValues[bins]<<" -1 ";

	for(int i=0; i<bins-1; i++)
	{
		cout<<binFreqs[i]<<",";
	}
	cout<<binFreqs[bins-1]<<" -1 "<<endl;
	return 0;
}