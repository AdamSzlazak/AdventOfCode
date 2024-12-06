#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


bool compareInts(int i, int j){
	return (i<j);
}

int firstTask(char* inputFile){
	std::ifstream streamInput(inputFile);
	if(!streamInput){
		printf("failed to open file\n");
		return 1;
	}

	std::vector<int> leftColumn;
	std::vector<int> rightColumn;

	for(std::string line; std::getline(streamInput, line);){
		int spaceIndex = line.find(" ");
		leftColumn.push_back(std::stoi(line.substr(0,spaceIndex)));
		rightColumn.push_back(std::stoi(line.substr(spaceIndex+1,line.size())));
	}
	
	std::stable_sort(leftColumn.begin(), leftColumn.end(),compareInts);
	std::sort(rightColumn.begin(),rightColumn.end(),compareInts);
	int result = 0;

	for(int i = 0; i < leftColumn.size();i++){
	
		int tmp = (leftColumn[i] - rightColumn[i]);
		if(tmp<0)
			tmp =tmp*-1;
		result += tmp;
	}
	return result;

}

int secondTask(char* inputFile){
	std::ifstream streamInput(inputFile);
	if(!streamInput){
		printf("Failed to open file\n");
	}
	
	std::vector<int> leftColumn;
	std::vector<int> rightColumn;

	for(std::string line; std::getline(streamInput,line);){
		leftColumn.push_back(std::stoi(line.substr(0,line.find(" "))));
		rightColumn.push_back(std::stoi(line.substr(line.find(" ")+1,line.size())));
	}
	
	int result = 0;

	for(int i = 0; i < leftColumn.size();i++){
		int tmp = std::count(rightColumn.begin(),rightColumn.end(), leftColumn[i]);
		result += tmp * leftColumn[i];
	}
	return result;
}
int main(int argc, char** argv){
	if (argc == 1){
		printf("user did not passed any file\n");
		return 1;
	}
	
	int firstTaskAnswer = firstTask(argv[1]);
	int secondTaskAnswer = secondTask(argv[1]);
	printf("first task: %d\nsecond task: %d", firstTaskAnswer, secondTaskAnswer);
	return 0;
}
