#pragma once
#include <fstream>
#include "Support.h"
class asmAnalyzer {

private:
	std::shared_ptr<Node> ParseTree;
	std::ofstream outFile;
	//std::vector<std::string> reprIdTable;
	std::vector<std::string> IdTable;
	std::vector<std::string> IdTableFunc;
	int countOperators;
	std::vector<std::string> idType;
	std::vector<std::string> idTypeFunc;
	std::vector<std::string> TEMPIDTable;
	std::string parameter;
	std::string lastOperation;
	int flagLastOperation;



public:
	asmAnalyzer(std::shared_ptr<Node> ParseTree, std::vector<std::string> idType, std::vector<std::string> idTypeFunc,
		std::vector<std::string> IdTable, std::vector<std::string> IdTableFunc, int countOperators)
		: ParseTree(ParseTree), idType(idType), idTypeFunc(idTypeFunc), IdTable(IdTable), IdTableFunc(IdTableFunc),
		countOperators(countOperators)
	
	{
		outFile.open("output.txt", std::ios::out);

		if (!outFile.is_open()) {
			std::cerr << "File don't open!" << std::endl;
		}
	}

	void analysis();

	std::string analysisExpression(const std::shared_ptr<Node>& node);
	void analysisBody(const std::shared_ptr<Node>& node);
	void analysisS();
	std::string analysisIDOrCallF(const std::shared_ptr<Node>& node);


	void analysisCountID();



};