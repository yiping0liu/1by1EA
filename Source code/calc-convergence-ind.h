void calc_convergence_ind(population *pop_ptr,int pop);

void calc_convergence_ind(population *pop_ptr,int pop)
{
	int i,j,k;
	float temp;
	float temp1;

	//calculate convergence_ind
	for(i=0;i<pop;i++)
	{
		if(convergence_type==0)//euclidean distance
		{
			temp=0;
			for(k=0;k<nfunc;k++)
			{
				temp+=square(pop_ptr->ind[i].fitness[k]-rz[k]);
			}
			temp=sqrt(temp);
		}//end type0

		else if(convergence_type==1)//Sum
		{
			temp=0;
			for(k=0;k<nfunc;k++)
			{
				temp+=pop_ptr->ind[i].fitness[k]-rz[k];
			}
		}//end type1

		else if(convergence_type==2)//Chebyshev distance
		{
			temp=-1;
			for(k=0;k<nfunc;k++)
			{
				temp1=fabs(pop_ptr->ind[i].fitness[k]-rz[k]);
				if(temp<temp1)
					temp=temp1;
			}
		}//end type2

		else if(convergence_type==3)//euclidean distance to nadir point
		{
			temp=0;
			for(k=0;k<nfunc;k++)
			{
				temp+=square(pop_ptr->ind[i].fitness[k]-rn[k]);
			}
			temp=sqrt(temp);
			temp=1/(temp+1);
		}//end type3

		else
		{
			printf("convergence_type error\n");
			getchar();
		}

		pop_ptr->ind[i].convergence_ind=temp;
	}

	//sorting in terms of convergence_ind
	for(i=0;i<pop-1;i++)
	{
		for(j=0;j<pop-i-1;j++)
		{
			if(pop_ptr->ind[j].convergence_ind>pop_ptr->ind[j+1].convergence_ind)
			{
				copyind(pop_ptr,pop_ptr,pop,j);
				copyind(pop_ptr,pop_ptr,j,j+1);
				copyind(pop_ptr,pop_ptr,j+1,pop);
			}
		}//end j
	}//end i


}//end convergence_ind