#include <iostream>
#include <string>
#include <fstream>
int firstTask(std::string fileName){
	
	std::ifstream file(fileName);

	if(!file)
		return -1;

	for(std::string line; std::getline(file,line);){
		std::cout<< line << "\n";
	}

	return 0;
}

int main(int argc, char** argv){
	
	if(argc!=1){
		int firstTaskResult = firstTask(argv[1]);
		std::cout << firstTaskResult << "\n";
	}


	return 0;
}

