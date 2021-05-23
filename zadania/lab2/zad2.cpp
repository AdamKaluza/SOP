#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>


auto main(int argc, char* argv[])->int{
	auto const pid = fork();
	
	if(pid == 0){
		
		std::cout<< "parent pid: " << getppid() << std::endl;
	}
	else{
		std::cout<<"child pid: " << pid << std::endl;
	}
}
