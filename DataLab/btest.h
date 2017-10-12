#pragma GCC diagnostic ignored "-Wparentheses"
/*
 * CS:APP Data Lab
 */

/* 
 * Students work in teams of one or two.  Teams enter their team name, 
 * personal names and login IDs in a struct of this
 * type in their bits.c file.
 */
typedef struct {
    char *teamname; /* "ID1+ID2" (two-person team) or "ID" (one-person team) */
    char *name1;   
    char *id1;
    char *name2;
    char *id2;
} team_struct;

/* Declare different function types */
typedef long (*funct_t) (void);
typedef long (*funct1_t)(long);
typedef long (*funct2_t)(long, long); 
typedef long (*funct3_t)(long, long, long); 

/* Combine all the information about a function and its tests as structure */
typedef struct {
    char *name;
    funct_t solution_funct; /* These will typically be casted */
    funct_t test_funct;
    long args;
    char *ops;
    int op_limit;
    int rating;
    long arg_ranges[3][2]; /* Min & Max values for each argument */
} test_rec, *test_ptr;

extern test_rec test_set[];







