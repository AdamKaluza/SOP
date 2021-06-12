#include <sys/types.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

auto execute(vector<string> args) -> int {
	
	auto argv = vector<char*>{};
	
	for(auto const& each : args){
		argv.push_back(const_cast<char*>(each.c_str()));
	}
	
	argv.push_back(nullptr);
	
	auto env = vector<char*>{};
	env.push_back(nullptr);
	
	execve(argv[0], argv.data(), env.data());
	perror("OH NOES");
	
	exit(EXIT_FAILURE);
}

auto sigchld_handler(int signo) -> void{
	cout<< "got SIGCHLD\n";
	
	auto status = int{0};
	auto child = waitpid(-1, &status, 0);
	
	if(WIFEXITED(status)){
		cout << "child " << child << " exited normally with " 
		<< WEXITSTATUS(status) << "\n";
		
		exit(0);
	}
}
auto main(int argc, char* argv[]) -> int{

		auto const child = fork();
		
		if(child == 0){
			execute({"/bin/sleep", "10"});
		}
		
		cout << "spawned child " << child << "\n";
		
		signal(SIGCHLD, sigchld_handler);
		
		while(true);
		
		return 0;
}
