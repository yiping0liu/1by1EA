#define INF 1.0e21
#define EPS 1.0e-21
#define E  2.71828182845905
#define PI 3.14159265358979323846

#define square(x) ((x)*(x)) 

#define maxpop  2000  
#define maxvar    100  
#define maxfun    50 
#define maxcons   50 
#define maxgener 5000 



/*parameters in 1by1EA*/
int switch_norm;//switch for normalization
int normj;//normalization judgement

float thr_zeta[maxgener];//distribution threshold
float thr_zeta0;//original distribution threshold
float thr_ratio;//threshold for control ratio of preselected solutions
float ratio[maxgener];//ratio of preselected solutions

int convergence_type;//type of convergence indicator
int corner_type;//type of corner point

int nbsize;//neighbor size

/*common parameters*/
char dir[100];
char filename[100];
float startTime;
float endTime;
float runtime[50];

int test_flag;//Test Problem, DTLZ 1~7
int nfunc;//number of objective    
int nvar;//number of variable        
int ncons;//number of constraint 

float seed; 
float seed0;//original seed
int maxrun;//max run times
int gener;//generation
int popsize;//population size
                  
float pcross;//crossover probability       
float pmut_r;//mutation probability        
float lim_r[maxvar][2];
float di;       
float dim;  
int var_bound;

float asort[maxpop];

float rz[maxfun];//ideal point
float rn[maxfun];//nadir point
float maxf[maxfun],minf[maxfun],maxminf[maxfun];//max/min values of objecitves

typedef struct      
{
	int	flag;
	int rank;//Pareto rank
	float xreal[maxvar];//variable
	float fitness[maxfun];//objective
    float constr[maxcons];//constraint   
    float cub_len;//crowding distance
	
	float convergence_ind;//value of convergence indicator
	float distribution_ind[maxpop];//value of distribution indicator
	int pareto_rel[maxpop];//Pareto domination relationship
}individual;        

typedef struct
{
	int rankno[maxpop];
	int maxrank;
	individual ind[maxpop], 
    *ind_ptr; 
}population ; 

population 
	oldpop,
	newpop,
	matepop,
	*old_pop_ptr,
	*new_pop_ptr,
	*mate_pop_ptr;

