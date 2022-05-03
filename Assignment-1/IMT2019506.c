#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

static inline float truncfunc(float x) 
{
	return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  
}

double euclidean_distance(int size, double vector1[size], double vector2[size])
{
	double sum=0.0;
	for(int i=0; i<size; i++)
	{
		sum+=(pow(vector1[i] - vector2[i],2));
	}
	return sqrt(sum); 
}

double manhattan_distance(int size, double vector1[size], double vector2[size])
{
	double sum=0.0;
	for(int i=0; i<size ; i++)
	{
		sum+=(fabs(vector1[i]-vector2[i]));
	}
	return sum;
}

double chebyshev_distance(int size, double vector1[size], double vector2[size])
{
	double max = fabs(vector1[0]-vector2[0]);
	for(int i=1; i<size; i++)
	{
		if(max < fabs(vector1[i]-vector2[i]))
		{
			max = fabs(vector1[i]-vector2[i]);
		}
	}
	return max;
}

double kl_divergence(int size, double vector1[size], double vector2[size])
{
	double sum =0.0;
	for(int i=0; i<size ;i++)
	{
		sum+=(vector1[i]*log(vector1[i]/vector2[i]));
	}
	return sum;
}

double js_distance(int size, double vector1[size], double vector2[size])
{
	double M[size];
	for(int i=0; i<size; i++)
	{
		M[i]=0.5*(vector1[i] + vector2[i]);
	}

	return sqrt( 0.5*kl_divergence(size,vector1,M) + 0.5*kl_divergence(size,vector2,M));
}

void normalize(int size, double* vector1, double* vector2)
{
	double sum1=0.0;
	double sum2=0.0;
	int i;
	for(i=0; i<size; i++)
	{
		sum1+=vector1[i];
		sum2+=vector2[i];
	}
	for(i=0; i < size; i++)
	{
		vector1[i]=vector1[i]/sum1;
		vector2[i]=vector2[i]/sum2;
	}
}

int main() 
{
	char string[50];
	scanf("%[^\n]%*c", string);
	int size;
	char v1[20];
	char v2[20];
	if(sscanf(string,"%d -1 %s -1 %s -1",&size,v1,v2)==3)
	{
		double vector1[size];
		int i=0;
		double vector2[size];

		char *token1 = strtok(v1, ",");
		
		while(token1!=NULL)
		{
			vector1[i]=atof(token1);
			i++;
			token1 = strtok(NULL,",");
		}

		i=0;
		char *token2 = strtok(v2, ",");
		while(token2!=NULL)
		{
			vector2[i]=atof(token2);
			i++;
			token2 = strtok(NULL,",");
		}

		for(int i=0;i<size;i++)
		{
			if(vector1[i] < 0 || vector2[i] < 0)
			{
				printf("-1\n");
				return 0;
			}
		}
		normalize(4,vector1,vector2);
		printf("%.4lf,",truncfunc(manhattan_distance(4,vector1,vector2)));
		printf("%.4lf,",truncfunc(euclidean_distance(4,vector1,vector2)));
		printf("%.4lf,",truncfunc(chebyshev_distance(4,vector1,vector2)));
		printf("%.4lf,",truncfunc(kl_divergence(4,vector1,vector2) + kl_divergence(4,vector2,vector1)));
		printf("%.4lf\n",truncfunc(js_distance(4,vector1,vector2)));
	}
	else printf("-1\n");
   	return 0;
}


