#include "FiveNumberSummary.h"

void FiveNumberSummary::setMin(float min)
{
	minimum=min;
}
void FiveNumberSummary::setMax(float max)
{
	maximum=max;
}
void FiveNumberSummary::setMedian(float med)
{
	median=med;
}
void FiveNumberSummary::setThirdQ(float tQ)
{
	thirdQ=tQ;
}
void FiveNumberSummary::setFirstQ(float fQ)
{
	firstQ=fQ;
}

float FiveNumberSummary::getMin()
{
	return minimum;
}
float FiveNumberSummary::getMax()
{
	return maximum;
}
float FiveNumberSummary::getMedian()
{
	return median;
}
float FiveNumberSummary::getThirdQ()
{
	return thirdQ;
}
float FiveNumberSummary::getFirstQ()
{
	return firstQ;
}
