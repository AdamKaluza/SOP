#include <stdlib.h>
#include <iostream>

auto main(int argc, char* argv[]) -> int {
	
	auto zmienna = argv[1];
	auto resoult = getenv(zmienna);
	
	if (resoult != nullptr){
		std::cout<< resoult<< '\n';
	}
	
	return 0;
}
