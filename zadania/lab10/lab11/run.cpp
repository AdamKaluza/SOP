#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <string.h>
#include <signal.h>
//zad1,2,3,4

pid_t cpid;

void handler(int signal){
	kill(cpid,signal);
}

auto main (int argc, char *argv[]) -> int {
	
	cpid = fork();
	
	if (cpid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0) {
		execvp(argv[1], argv+1);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	
	signal(SIGINT, SIG_IGN);
	
	struct sigaction act{};
	act.sa_handler = handler;
	
	sigaction(SIGTERM, &act, nullptr); 
	
	int status = 0;
	waitpid(cpid, &status, 0);
	
	if (WIFEXITED(status)) {
		std::cout<<"Child PID is "<<cpid<<", status="<<WEXITSTATUS(status)<<"\n";
	}
	
	if (WIFSIGNALED(status)) {
		std::cout<<"Proccess: "<< cpid <<" killed by signal " << 
		WTERMSIG(status) << "\n" << strsignal(WTERMSIG(status)) << 
		"\n";
	}
	
		
	return 0;
}


