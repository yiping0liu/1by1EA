void one_by_one_select(population *pop1_ptr,population *pop2_ptr,int pop1,int pop2,int gen);

void one_by_one_select(population *pop1_ptr,population *pop2_ptr,int pop1,int pop2,int gen)
{
	int i,j;
	int n,n1,n2,n3,nrank;
	int the_one;


	n=0;
	n1=0;
	n2=0;
	n3=0;
	nrank=1;

	pareto_relation(pop1_ptr,pop1);//pareto relationship

	for(j=0;j<pop1;j++)
	{
		//select corner solutions first
		if(pop1_ptr->ind[j].flag>=1000)
		{
			//selecte the one
			the_one=j;
			pop1_ptr->ind[the_one].rank=nrank;
			copyind(pop2_ptr,pop1_ptr,n,the_one);
			n++;

			//de-emphasize neighbors
			for(i=0;i<pop1;i++)
			{
			if(pop1_ptr->ind[i].flag==0)
			{
				if(pop1_ptr->ind[i].distribution_ind[the_one]<thr_zeta[gen])
				{
					pop1_ptr->ind[i].flag=999;
					n2++;
				}
			}		
			}

			//de-emphasize dominated solutions
			for(i=0;i<pop1;i++)
			{
			if(pop1_ptr->ind[i].flag==0)
			{
				if(pop1_ptr->ind[i].pareto_rel[the_one]==1)
				{
					pop1_ptr->ind[i].flag=999;
					n3++;
				}
			}		
			}
		}//end if

	}//end j


	//number of the rest
	n1=0;
	for(i=0;i<pop1;i++)
	{
		if(pop1_ptr->ind[i].flag==0)
		{
			n1++;
		}
	}

	while(n1>0)
	{

		//find the smallest convergence_ind	
		for(i=0;i<pop1;i++)
		{
			if(pop1_ptr->ind[i].flag==0)
			{
				the_one=i;
				break;
			}
		}

		//selecte the one
		pop1_ptr->ind[the_one].flag=1;
		pop1_ptr->ind[the_one].rank=nrank;
		copyind(pop2_ptr,pop1_ptr,n,the_one);
		n++;

		//de-emphasize neighbors
		for(i=0;i<pop1;i++)
		{
			if(pop1_ptr->ind[i].flag==0)
			{
				if(pop1_ptr->ind[i].distribution_ind[the_one]<thr_zeta[gen])
				{
					pop1_ptr->ind[i].flag=999;
					n2++;
				}
			}		
		}

		//de-emphasize dominated solutions
		for(i=0;i<pop1;i++)
		{
			if(pop1_ptr->ind[i].flag==0)
			{
				if(pop1_ptr->ind[i].pareto_rel[the_one]==1)
				{
					pop1_ptr->ind[i].flag=999;
					n3++;
				}
			}		
		}


		//number of the rest
		n1=0;
		for(i=0;i<pop1;i++)
		{
			if(pop1_ptr->ind[i].flag==0)
			{
				n1++;
			}
		}//end i

	}//end while n1


	//adjust thr_zeta
	ratio[gen]=n*1.0/(popsize*1.0);
	if(n3<(2.0-thr_ratio)*popsize)
	{
		thr_zeta[gen+1]=thr_zeta[gen]*exp((ratio[gen]/thr_ratio-1.0)/(nfunc*1.0));
	}
	else
	{
		thr_zeta[gen+1]=thr_zeta[gen];
	}

	//fill pop2
	while(n<pop2)
	{
		//number of the rest
		n1=0;
		for(i=0;i<pop1;i++)
		{
			if(pop1_ptr->ind[i].flag==0)
			{
				n1++;
			}
		}//end i

		//renew de-emphasize solutions
		if(n1==0)
		{
			for(i=0;i<pop1;i++)
			{
				if(pop1_ptr->ind[i].flag==999)
					pop1_ptr->ind[i].flag=0;
			}

			nrank++;//additive rank number
		}

		//selecte the one
		for(i=0;i<pop1;i++)
		{
			if(pop1_ptr->ind[i].flag==0)
			{
				the_one=i;
				break;
			}
		}
		pop1_ptr->ind[the_one].flag=1;
		pop1_ptr->ind[the_one].rank=nrank;
		copyind(pop2_ptr,pop1_ptr,n,the_one);
		n++;

		//de-emphasize neighbors
		for(i=0;i<pop1;i++)
		{
			if(pop1_ptr->ind[i].flag==0)
			{
				if(pop1_ptr->ind[i].distribution_ind[the_one]<thr_zeta[gen])
				{
					pop1_ptr->ind[i].flag=999;
				}
			}		
		}

		//de-emphasize dominated solutions
		for(i=0;i<pop1;i++)
		{
			if(pop1_ptr->ind[i].flag==0)
			{
				if(pop1_ptr->ind[i].pareto_rel[the_one]==1)
				{
					pop1_ptr->ind[i].flag=999;
				}
			}		
		}

	}//end while n




}//end 