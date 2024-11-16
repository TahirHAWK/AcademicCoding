#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/file.h>

#define BUFFER_SIZE 25
#define READ  0
#define WRITE 1

int create_file(char *file_name);
int read_file(char *file_name);
int delete_file(char *file_name);
char c[1000];

char sentence[100] = "Welcome to Operating Systems Lab 2";
int main(void)
{
  char *file_a = "file_A.txt";
  char *file_b = "file_B.txt";
  pid_t pid;

  // 5 pipes, each to be used for a different signal
  int mypipefd[2];
  int mypipefd2[2];
  int mypipefd3[2];
  int mypipefd4[2];
  int mypipefd5[2];

  // Creating pipes
	if (pipe(mypipefd) == -1 || pipe(mypipefd2) == -1 || pipe(mypipefd3) == -1 || pipe(mypipefd4) == -1 || pipe(mypipefd5) == -1) {
		fprintf(stderr, "Error in pipes!");
		return 1;
	}

  // Fork child process
  pid = fork();

  if (pid < 0) {
    fprintf(stderr, "Fork failed!");
    return 1;
  }

  // Parent process
  if (pid > 0) {
    while(1) {
		int create = 0;
		int reading = 0;
		int delete = 0;
		sleep(1);

		create_file(file_a);
		printf("....................\n");
		printf("File created for Process A.\n");			// send message to Process B that file is created by Process A
		sleep(1);

		create++;
		write(mypipefd[WRITE], &create, sizeof(create));
		sleep(2);

		read(mypipefd2[READ], &reading, sizeof(read));		// receive message from Process B that file has been read by Process B
		if (reading) {
			delete_file(file_a);
			delete = 1;
		}
		write(mypipefd3[WRITE], &delete, sizeof(delete));	// send message to Process B that file has been deleted by Process A
		sleep(1);

		read(mypipefd4[READ], &reading, sizeof(read));		// receive message from Process B that file is created by Process B
		if (reading == 1){
			printf("File for Process B being read by Process A.\n");
			read_file(file_b);
			delete = 1;
		}
		sleep(2);

		write(mypipefd5[WRITE], &delete, sizeof(delete));	// send message after file has been read by Process A
	}
  }
  // Child process
  else {
	while (1) {
		int create = 0;
		int reading = 0;
		int delete = 0;
		read(mypipefd[READ], &create, sizeof(create));		// receive message that file is created by Process A

		// Process B reads the data from Process A
		if (create) {
			printf("File for Process A being read by Process B.\n");
			read_file(file_a);
			reading = 1;
			create = 0;
		}
		reading++;
		write(mypipefd2[WRITE], &reading, sizeof(read));		// send message after file has been read by Process B
		sleep(1);

		read(mypipefd3[READ], &create, sizeof(create));			// receive message that file has been deleted by Process A
		// Process B creates file
		if (create == 1) {
			create_file(file_b);
			reading = 1;
			printf("....................\n");
			printf("File created for Process B.\n");
		}
		write(mypipefd4[WRITE], &reading, sizeof(read));		// send message to Process A to read data from file
		sleep(1);

		read(mypipefd5[READ], &delete, sizeof(delete));			// receive message from Process A that file has been read by Process A
		if (delete == 1) {										// send message to Process A that file has been deleted by Process B
			delete_file(file_b);
		}
	}
  }
}

// Creating a file
int create_file(char *file_name) {
	FILE *fptr;
	fptr = fopen(file_name, "w+");

	if(fptr == NULL) printf("Error!");
	if(flock(fileno(fptr), LOCK_EX | LOCK_NB) != 0) printf("Lock Error In File.\n");
	fprintf(fptr, "%s", sentence);
	if(flock(fileno(fptr), LOCK_UN | LOCK_NB) != 0) printf("Unlock Error In File.\n");
	printf("\n");
	fclose(fptr);
	return 1;
}

// Read data from a file
int read_file(char *file_name) {
	int d;
	FILE *file;
	file = fopen(file_name, "r");
	if (file) {
		if(flock(fileno(file), LOCK_EX | LOCK_NB) != 0) printf("Lock Error In File.\n");
		while ((d = getc(file)) != EOF)
			putchar(d);
        if(flock(fileno(file), LOCK_UN | LOCK_NB) != 0) printf("Unlock Error In File.\n");
		fclose(file);
	}
	printf("\n");
	return 1;
}

//Delete a file
int delete_file(char *file_name) {
	if (remove(file_name) == 0) {
		printf("File deleted successfully.\n");
		return 1;
	}
	else
		printf("Unable to delete file.");
	return 0;
}
