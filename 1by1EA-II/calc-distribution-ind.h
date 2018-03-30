void calc_distribution_ind(population *pop_ptr,int pop);

void calc_distribution_ind(population *pop_ptr,int pop)
{
	int i,j,k;
	float temp;
	float vl[maxpop];


	//calculate vector length
	for(i=0;i<pop;i++)
	{
		vl[i]=0;
		for(k=0;k<nfunc;k++)
			vl[i]+=square(pop_ptr->ind[i].fitness[k]-rz[k]);
		vl[i]=sqrt(vl[i]);
		if(vl[i]==0)
		{
			printf("error distribution_ind 0\n");
			getchar();
		}
	}

	//calculate distribution indicator
	for(i=0;i<pop;i++)
	{
		for(j=i;j<pop;j++)
		{
			temp=0;

			for(k=0;k<nfunc;k++)
				temp+=(pop_ptr->ind[i].fitness[k]-rz[k])*(pop_ptr->ind[j].fitness[k]-rz[k]);
			if(vl[i]==0||vl[j]==0)
				temp=1;
			else
				temp=temp/(vl[i]*vl[j]);
			temp=1-temp;
			
			pop_ptr->ind[i].distribution_ind[j]=temp;
			pop_ptr->ind[j].distribution_ind[i]=temp;

		}//end j
	}//end i


}//end distribution_ind