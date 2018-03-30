void knst(population *pop_ptr,int pop);

void knst(population *pop_ptr,int pop)
{
	int i,j,k,l;
	int kn;
	float crowd;
	float temp;

	kn=nbsize;

	/*update ideal point*/
	maxmin(pop_ptr,pop);
	for(k=0;k<nfunc;k++)
		rz[k]=minf[k];

	/*calculate distribution indicator*/
	calc_distribution_ind(pop_ptr,pop);


	for(i=0;i<pop;i++)
	{
		for(j=0;j<pop;j++)
		{
			pop_ptr->ind[j].flag=0;
		}
		crowd=0;
		for(k=0;k<kn;k++)//find k-nearest solutions
		{
			temp=INF;
			for(j=0;j<pop;j++)
			{
				if(i!=j)
				{
					if(pop_ptr->ind[j].distribution_ind[i]<temp && pop_ptr->ind[j].flag==0)
					{
						temp=pop_ptr->ind[j].distribution_ind[i];
						l=j;
					}
				}
			}
			crowd+=temp;
			pop_ptr->ind[l].flag=1;
			pop_ptr->ind[i].pareto_rel[l]=1;
		}//end k
		pop_ptr->ind[i].cub_len=crowd;
	}//end i


}//end knst