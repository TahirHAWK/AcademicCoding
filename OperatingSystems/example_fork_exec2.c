#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <errno.h>
#include <sys/wait.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> #include <errno.h>
/* Compiler call: gcc -o example_fork example_fork.c */

/* Program example_fork_exec1 (parent process) */
#define PROGNAM ”example_fork_exec2”

int main(int argc, char *argv[]) {
pid t npid; 
int rval;
char *argvk[] = {PROGNAM, NULL};
char *envmt[] = {”PROG=exec”,”TEST=text”, NULL};
npid = fork() ;
if (npid > 0) {
printf (”Ouput parent process \”%s\” (PID: %d)!\n”, 
argv[0], getpid());
wait(&rval);
return EXIT_SUCCESS;
} else if (npid == 0) {
execve(PROGNAM, argvk, envmt);
return EXIT_FAILURE;
} else {
fprintf (stderr ,”Error in fork() : %s\n”, 
strerror(errno)) ;
return EXIT_FAILURE;
}
}