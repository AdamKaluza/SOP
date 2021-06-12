#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <vector>

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
auto main(int argc, char* argv[]) -> int{
	
	auto args = vector<string>{}; //tablica zmiennej długości
	
	for(auto i = 1; i < argc; ++i){
		args.push_back(argv[i]); //dodaje na koniec vectora
	}
	
	execute(args);
	
}
