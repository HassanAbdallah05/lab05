#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>

int main(){

    int N=5; // Number of elements for the array
   
    // fill in the missing parameters in the mmap command

    int *ptr = mmap( NULL ,N*sizeof(int) ,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1 ,0); 

    if(ptr == MAP_FAILED){
     printf("Mapping Failed\n");
     return 1;
    }

    for(int i=0; i < N; i++){
     ptr[i] = i + 1;
    }

    printf("Initial values of the array elements :\n");
    for (int i = 0; i < N; i++ ){
     printf(" %d", ptr[i] );
    }
    printf("\n");

    pid_t child_pid = fork();
   
    if (child_pid == 0 ){
     //child
     for (int i = 0; i < N; i++){
         ptr[i] = ptr[i] * 5;
     }
    }
    else{
         //parent
	 wait(NULL);    
         printf("\nParent:\n");

         printf("Updated values of the array elements :\n");
        
        // fill in here the missing code ....

	for (int i = 0; i < N; i++){
             printf(" %d", ptr[i]);
        }
         printf("\n");


    }

    int err = munmap(ptr, N*sizeof(int));

    if(err != 0){
     printf("UnMapping Failed\n");
     return 1;
    }
    return 0;
}
