class FiveNumberSummary
{
	private:
		float minimum;
		float maximum;
		float median;
		float firstQ;
		float thirdQ;

	public:
		void setMin(float min);

		void setMax(float max);

		void setMedian(float med);

		void setThirdQ(float tQ);

		void setFirstQ(float fQ);

		float getMin();

		float getMax();

		float getMedian();

		float getThirdQ();

		float getFirstQ();
};