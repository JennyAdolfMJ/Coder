#pragma once
#include<vector>
#include<string>


class Dict
{
	std::vector<std::string> vec;
	int  currentcell;
	std::string filepath;
	std::string  currentLine;
public:
	void *  cellReader();
	void  readLine();
	Dict(void);
	~Dict(void);
};

