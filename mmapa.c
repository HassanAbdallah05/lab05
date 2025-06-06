#include <stdio.h>
#include <sys/mman.h>

int main(){

  int N=5;
  int *ptr = mmap ( NULL, N*sizeof(int),
      PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0 );

  if(ptr == MAP_FAILED){
    printf("Mapping Failed\n");
    return 1;
  }

  // Fill the elements of the array
  for(int i=0; i<N; i++)
     ptr[i] = i*10;

  // Print the elements of the array
  printf("The elements of the array => ");
  for(int i=0; i<N; i++)
     printf("[%d] ",ptr[i]);

  printf("\n");
  int err = munmap(ptr, 10*sizeof(int));
  if(err != 0){
     printf("UnMapping Failed\n");
     return 1;
  }

  return 0;
}
