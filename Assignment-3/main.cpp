#include <iostream>
#include <string>
#include <vector>
#include "DataSequence.h"
using namespace std;

int main()
{
	string input;
	getline(cin,input);					//Input string

	vector<string> segments;

	vector<float> addToSeq;
	vector<int> sizes;
	string part="";
	int i=0;
	
	while(i < (int)(input.length()))
	{
		if(input[i]=='-' && input[i+1]=='1')
		{
			segments.push_back(part);
			i+=3;
			part="";
		}
		else
		{
			part = part + input[i];
			i++;
		}
	}
	
	vector<float> sequence;
	vector<vector<float>> DSvector;
	vector<DataSequence> DSobjects;

	for(string segment: segments)
	{
		if(segment[0]=='N')
		{
			//flag=0;
			sequence.clear();
			string part="";
			int k=2,size;
			while(k<(int)segment.length()-1)
			{
				if(segment[k]==' ')
				{
					size = stoi(part);
					sizes.push_back(size);
					part="";
				}
				else if(segment[k]==',')
				{
					sequence.push_back(stof(part));
					part="";
				}
				else part = part + segment[k];
				k++;
			}
			if(k!=3)
			{
				sequence.push_back(stof(part));
				DSvector.push_back(sequence);
				int len=DSvector.size();
				float* seqptr = DSvector[len-1].data();
				Histogram histogram;
				DataSequence dseq(sequence.size(),seqptr);
				dseq.sortAndCalculate();
				DSobjects.push_back(dseq);
			}
		}
		else if(segment[0]=='A')
		{
			int j=2;
			string p="";
			addToSeq.clear();
			while(j < (int)segment.length()-1)
			{
				if(segment[j]==',')
				{
					addToSeq.push_back(stof(p));
					p="";
				}
				else p = p + segment[j];
				j++;
			}
			addToSeq.push_back(stof(p));
			int index = (int)(addToSeq[0]);
			DSvector[index].push_back(addToSeq[1]);
			sizes[index]+=1;
			float* seqptr = DSvector[index].data();
			DSobjects[index].update(sizes[index],seqptr);
		}
	}

	cout<<DSobjects[0];
	for(int i=1; i < (int)DSobjects.size();i++)
	{
		cout<<" "<<DSobjects[i];
	}
}