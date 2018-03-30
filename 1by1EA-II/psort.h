void psort_dec(int len);

void psort_dec(int len)
{
	int i,j;

	float temp;
	int tp;

	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(asort[j]<asort[j+1])
			{
				temp=asort[j];
				asort[j]=asort[j+1];
				asort[j+1]=temp;

				tp=nsort[j];
				nsort[j]=nsort[j+1];
				nsort[j+1]=tp;
			}
		}//j
	}//i

}//end psrot

void psort_inc(int len);

void psort_inc(int len)
{
	int i,j;

	float temp;
	int tp;

	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(asort[j]>asort[j+1])
			{
				temp=asort[j];
				asort[j]=asort[j+1];
				asort[j+1]=temp;
				
				tp=nsort[j];
				nsort[j]=nsort[j+1];
				nsort[j+1]=tp;

			}
		}//j
	}//i

}//end psrot

void psort2_inc(int len);

void psort2_inc(int len)
{
	int i, j;

	float temp;
	int tp;

	for (i = 0; i<len - 1; i++)
	{
		for (j = 0; j<len - i - 1; j++)
		{
			if (asort[j]>asort[j + 1])
			{
				temp = asort[j];
				asort[j] = asort[j + 1];
				asort[j + 1] = temp;

				tp = nsort2[j];
				nsort2[j] = nsort2[j + 1];
				nsort2[j + 1] = tp;

			}
		}//j
	}//i

}//end psrot

