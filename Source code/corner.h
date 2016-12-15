void corner(population *pop_ptr,int pop,int gen);

void corner(population *pop_ptr,int pop,int gen)
{
	int i,j,k;
	float temp;
	float temp1;
	float min_corner;
	int cs[maxfun];

	if(switch_norm)//pre-norm
	{
		maxmin(pop_ptr,pop);
		normalize(pop_ptr,pop);
	}

	/*update ideal and nadir points*/
	maxmin(pop_ptr,pop);
	for(k=0;k<nfunc;k++)
	{
		rz[k]=minf[k];
		rn[k]=maxf[k];
	}
		
	for(i=0;i<pop;i++)
		pop_ptr->ind[i].flag=0;

	//search for k corner solutions
	for(k=0;k<nfunc;k++)
	{
		//calculate the all-but-one function
		for(i=0;i<pop;i++)
		{
			if(corner_type==0)//euclidean distance
			{

			temp=0;
			for(j=0;j<nfunc;j++)
			{
				if(j!=k)
				temp+=square(pop_ptr->ind[i].fitness[j]-rz[j]);
			}
			temp=sqrt(temp);

			}//end type0

			else if(corner_type==1)//Sum
			{

			temp=0;
			for(j=0;j<nfunc;j++)
			{
				if(j!=k)
				temp+=pop_ptr->ind[i].fitness[j]-rz[j];
			}

			}////end type1type1

			else if(corner_type==2)//Chebyshev distance
			{

			temp=-1;
			for(j=0;j<nfunc;j++)
			{
				if(j!=k)
				{
				temp1=fabs(pop_ptr->ind[i].fitness[j]-rz[j]);
				if(temp<temp1)
					temp=temp1;
				}
			}

			}//end type2

			else if(corner_type==3)//euclidean distance to nadir point
			{

			temp=0;
			for(j=0;j<nfunc;j++)
			{
				if(j!=k)
					temp+=square(pop_ptr->ind[i].fitness[j]-rn[j]);
			}
			temp=sqrt(temp);
			temp=1/(temp+1);

			}//end type3

			else
			{
				printf("corner_type error\n");
				getchar();
			}

			pop_ptr->ind[i].convergence_ind=temp;

		}//end all but one

		min_corner=pop_ptr->ind[0].convergence_ind;
		cs[k]=0;
		for(i=1;i<pop;i++)
		{
			if(min_corner>pop_ptr->ind[i].convergence_ind)
			{
				min_corner=pop_ptr->ind[i].convergence_ind;
				cs[k]=i;
			}
		}//end i

		//mark k-th corner solution
		pop_ptr->ind[cs[k]].flag=1000+k;

		//update nadir point
		rn[k]=pop_ptr->ind[cs[k]].fitness[k];
		maxminf[k]=rn[k]-rz[k];



	}//end k


	//normalization
	if(switch_norm)
	{
		normj=1;
		for(k=0;k<nfunc;k++)
		{
			if(maxminf[k]<EPS)
			{
				normj=0;
				printf("normalization warning!\n");
				maxminf[k]=1;
			}
		}

		if(normj)
		for(i=0;i<pop;i++)
		{
			for(k=0;k<nfunc;k++)
				pop_ptr->ind[i].fitness[k]=pop_ptr->ind[i].fitness[k]/maxminf[k];
		}
	}

}//end idealcorner