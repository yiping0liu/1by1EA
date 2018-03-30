void calc_double_convergence(population *pop_ptr, int pop);

void calc_double_convergence(population *pop_ptr, int pop)
{
	int i, j, k;
	float temp;
	float temp1;

	//calculate two convergence indicators
	for (i = 0; i<pop; i++)
	{

		temp = -1;
		for (k = 0; k<nfunc; k++)
		{
			temp1 = fabs(pop_ptr->ind[i].fitness[k] - rz[k]);
			if (temp<temp1)
				temp = temp1;
		}

		pop_ptr->ind[i].c1 = temp;

		temp = INF;
		for (k = 0; k<nfunc; k++)
		{
			temp1 = pop_ptr->ind[i].fitness[k] - rn[k];
			if (temp>temp1)
				temp = temp1;
		}

		pop_ptr->ind[i].c2 = temp;


	}


	//sorting in terms of convergence indicator
	for (i = 0; i < pop; i++)
	{
		asort[i] = pop_ptr->ind[i].c1;
		nsort[i] = i;
	}
	psort_inc(pop);

	for (i = 0; i < pop; i++)
	{
		asort[i] = pop_ptr->ind[i].c2;
		nsort2[i] = i;
	}
	psort2_inc(pop);

	


}//end convergence_ind