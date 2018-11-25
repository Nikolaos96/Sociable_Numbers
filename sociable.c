/* File: sociable.c */
#include <stdio.h>
#define MAXNUM 10000000                                     /* Maximum number which check  */
#define MAXCYC 28                                             /* Maximum length cycle */
main()
{ long n, i, l, lengthcycle, stop, j, sumdivisor;
  long k, sumcycle, sociable, amicable, perfect;
  
printf(" $ ./sociable\n"); 
perfect = 0;                                                  /* Archive the perfect numbers from 0  */
amicable = 0;                                                 /* Archive the amicable numbers from 0 */
sociable = 0;                                                 /* Archive the perfect numbers from 0  */
sumcycle = 0;                                                 /* Archive the perfect numbers from 0 */
for(n = 2 ; n <= MAXNUM ; n++){
	lengthcycle = 0;                                          /* For each number the length cycle starting from 0 */
	stop = 0;                                                 /* For each repeat stop archive from 0 */
	j = n;													  /* Member n to check later */									
	do{													 		
	    lengthcycle = lengthcycle + 1;				          /* Raise the length of cycle */
	    sumdivisor = 0;                                       /* Sum of divisor */
	    if(n % 2 == 0){                                      
			for(i = 1 ; i*i <= n ; i++){					  /* Looking until the root of the number */	
			 	if(n % i==0){                     			  /* Checks if i is a divisor of n */  
			    	sumdivisor = sumdivisor + i;
					sumdivisor = sumdivisor + (n/i);                   	 		        
				}                                                  
			}
			sumdivisor = sumdivisor - n;
	    }
	    if(n % 2 != 0){                                       /* If the number is odd then only look for odd divider */
	    	for(i = 1 ; i*i <= n ; i =i + 2){				  /* Looking until the root of the number */	
			 	if(n % i==0){                     			  /* Checks if i is a divisor of n */  
			    	sumdivisor = sumdivisor + i;
					sumdivisor = sumdivisor + (n/i);                   	 		        
				}                                                  
			}
			sumdivisor = sumdivisor - n;
		}
		if(sumdivisor > MAXNUM || sumdivisor < j){            /* If the sumdivisor > MAXNUM or sumdivisor < n then stop and goes next number */
	    	stop = 1; 								          /* If the stop become 1 over the repetition */	
		}                                              			
		if(j == sumdivisor && stop == 0){                     /* Chek if found sociable number */
			if(lengthcycle == 1) perfect = perfect + 1;       /* Chek if the number is perfect */
			if(lengthcycle == 2) amicable = amicable + 1;     /* Chek if the number is amicable  */
			if(lengthcycle > 2)  sociable = sociable + 1;	  /* Chek if the number is sociable */
		    stop = 1;								          /* Stop become one over the repetition */
	    	printf(" Cycle of length %ld: %ld ", lengthcycle, j);
			for(k = 1 ; k <= lengthcycle ; k++){                
				l = 0;
				for(i = 1 ; i*i <= j ; i++){                   /* Repeat the process of finding sum of divisors but now prints */
			    	if(j % i == 0){
                        l = l + i;
                        l = l + (j/i);
			    	}
			    }
                l = l - j;
			    printf(" %ld ", l);                             
			    j = l;
            }
            printf("\n");
		}
		if(stop == 0 ){
			n = sumdivisor;                                    /* If sum of divisor is different from number then continue for number=sumdivisor */
		}
	}while( lengthcycle < MAXCYC && stop == 0);                /* Continue while length < 28 and stop = 0 repeat */
    n = j;                                                     /* Continue from n where had stayed */
}
printf("\n");
sumcycle = perfect + amicable + sociable;                      /* Sum of alla the cycle */
printf(" Found %ld cycles including\n", sumcycle);
printf(" %ld cycles with perfect numbers and\n", perfect);
printf(" %ld cycles with amicable numbers\n", amicable);
printf(" $\n ");
}
