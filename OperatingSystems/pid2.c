#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <errno.h>
/* Compiler call: gcc -o example_fork example_fork.c */

int main(void)
{
pid_t npid;
int i;
for (i = 0; i<2; i++) {
npid = fork();
if (npid >0) {
printf("i = %d, Process %d: I am your father.\n",i, 
getpid());
}else if (npid ==0) {
printf("i = %d, Prozess %d: Output child process.\n",i, 
getpid());
}
else {
fprintf(stderr, "i = %d, Error No. %d in fork()!\n", i, errno);
return 1;
}
}
}