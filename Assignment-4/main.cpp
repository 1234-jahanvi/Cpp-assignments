#include<iostream>
#include "BinomialDistribution.h"
using namespace std;

int main()
{
	string input;						//Taking input as a string
	getline(cin,input);

	string parts[3];
	string part="";
	int i=0;
	int k=0;
	while(i < (int)input.length())
	{
		if(input[i]==' ')
		{
			parts[k]=part;
			k++;
			part="";
		}
		else
		{
			part = part + input[i];
		}
		i++;
	}
	parts[k++]=part;
	
	if(k!=3)							//Invalid input check
	{
		cout<<"-1"<<endl;
		return 0;
	}

	int flag=0;
	for(int i=0; i<3; i++)
	{
		if(parts[i][0]=='-')			//Invalid input check
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		cout<<"-1"<<endl;
		return 0;
	}

	int n = stoi(parts[0]);
	float p1 = stof(parts[1]);
	float p2 = stof(parts[2]);
	if(p1>=1 || p2>=1)					//Invalid input check
	{
		cout<<"-1"<<endl;
		return 0;
	}

	BinomialDistribution bdist1(n,p1);
	BinomialDistribution bdist2(n,p2);

	bdist1.makeHistogram();
	bdist2.makeHistogram();

	Histogram* histPtr1;
	Histogram* histPtr2;

	histPtr1 = &bdist1;
	histPtr2 = &bdist2;

	distances(histPtr1,histPtr2);
}