#ifndef BinomialDistribution_h_
#define BinomialDistribution_h_
#include <cmath>
#include "Histogram.h"

class BinomialDistribution: public Histogram
{
	private:
		int n;
		float p;

	public:
		BinomialDistribution(int n, float p);

		void setN(int n);

		void setP(float p);

		double pmfValue(int k);

		double binCoeff(int n, int k);

		void makeHistogram();
};

#endif