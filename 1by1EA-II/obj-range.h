void maxmin(population *pop_ptr,int pop);

void maxmin(population *pop_ptr,int pop)
{
	int i,k;


	for(k=0;k<nfunc;k++)
	{
		maxf[k]=-INF;
		minf[k]=INF;
		for(i=0;i<pop;i++)
		{
			if(pop_ptr->ind[i].fitness[k]>maxf[k])
					maxf[k]=pop_ptr->ind[i].fitness[k];
			if(pop_ptr->ind[i].fitness[k]<minf[k])
					minf[k]=pop_ptr->ind[i].fitness[k];
		}
		maxminf[k]=maxf[k]-minf[k];
	}

}//end maxmin

void ideal_nadir(population *pop_ptr, int pop);

void ideal_nadir(population *pop_ptr, int pop)
{
	int i, k;

	paretorank(pop_ptr, pop);
	for (k = 0; k < nfunc; k++)
	{
		rn[k] = -INF;
		rz[k] = INF;
		for (i = 0; i < pop; i++)
		{
			if (pop_ptr->ind[i].fitness[k] > rn[k] && pop_ptr->ind[i].rank == 0)
				rn[k] = pop_ptr->ind[i].fitness[k];
			if (pop_ptr->ind[i].fitness[k] < rz[k] && pop_ptr->ind[i].rank == 0)
				rz[k] = pop_ptr->ind[i].fitness[k];
			
		}
		
	}

}//end maxmin


