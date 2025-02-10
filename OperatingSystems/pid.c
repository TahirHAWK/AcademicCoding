
#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <errno.h>
/* Compiler call: gcc -o example_fork example_fork.c */

int main(void){
pid_t npid;
int i;
npid = fork();
if (npid >0) {
printf("Process %d: I am your father.\n", 
getpid());
} else if (npid ==0) {
printf("Prozess %d: Output child process.\n", 
getpid());
}
else {
fprintf(stderr, "Error No. %d in fork()!\n", errno);
return 1;
}
}



