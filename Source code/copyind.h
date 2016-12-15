int copyind(population *pop1_ptr,population *pop2_ptr,int num1,int num2);

int copyind(population *pop1_ptr,population *pop2_ptr,int num1,int num2)
{
	int i,k;

	for(k=0;k<nvar;k++)
		pop1_ptr->ind[num1].xreal[k] = pop2_ptr->ind[num2].xreal[k];
	for(k=0;k<nfunc;k++)
		pop1_ptr->ind[num1].fitness[k] = pop2_ptr->ind[num2].fitness[k];
	for(k=0;k<ncons;k++)
		pop1_ptr->ind[num1].constr[k] = pop2_ptr->ind[num2].constr[k];
	pop1_ptr->ind[num1].cub_len =pop2_ptr->ind[num2].cub_len;
	pop1_ptr->ind[num1].rank = pop2_ptr->ind[num2].rank;
	pop1_ptr->ind[num1].flag = pop2_ptr->ind[num2].flag;
	
	pop1_ptr->ind[num1].convergence_ind = pop2_ptr->ind[num2].convergence_ind;
	for(i=0;i<popsize;i++)
		pop1_ptr->ind[num1].distribution_ind[i] =pop2_ptr->ind[num2].distribution_ind[i];
	for(i=0;i<popsize;i++)
		pop1_ptr->ind[num1].pareto_rel[i] =pop2_ptr->ind[num2].pareto_rel[i];


}//end copyind