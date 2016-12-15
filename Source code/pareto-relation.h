void pareto_relation(population *pop_ptr,int pop);

void pareto_relation(population *pop_ptr,int pop)
{
	int i,j,k;
	int pflag,pflag1;


	for(i=0;i<pop;i++)
	{
		for(j=0;j<pop;j++)
		{
			pflag=1;
			pflag1=0;
			for(k=0;k<nfunc;k++)
			{
				if(pop_ptr->ind[i].fitness[k]>pop_ptr->ind[j].fitness[k])
					pflag=0;
				if(pop_ptr->ind[i].fitness[k]<pop_ptr->ind[j].fitness[k])
					pflag1=1;
			}
			if(pflag==1&&pflag1==1)
				pop_ptr->ind[j].pareto_rel[i]=1;//j is dominated by i
			else
				pop_ptr->ind[j].pareto_rel[i]=0;

		}//end j
	}//end i






}//end pvalue