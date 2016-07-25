#include "Dict.h"
#include <fstream>
#include <sstream> 

void *  Dict::cellReader(){
	if(!currentLine.empty()){
		int index =currentLine.find("/t");
		std::string str = currentLine.substr(0,index);
		if(vec[currentcell]=="int"){	
			std::istringstream  iss(str);
			int value;
			iss>>value; 
			return &value;
		}
		else if(vec[currentcell]=="float"){	
			std::istringstream  iss(str);
			float value;
			iss>>value; 
			return &value;
		}
		else if(vec[currentcell]=="char"){
			char * tmp;
			strcpy(tmp,str.c_str());
			return  tmp;
		}
		else if(vec[currentcell]=="array"){
			int index = str.find(":");
			std::string subnum = str.substr(0,index);
			std::istringstream iss(subnum);
			int num;
			iss>>num;
			int start=index,end;
			
		    for(int i=0;i <num ;i++){
				end = str.substr(start, str.size()).find(',');
				std::string  item = str.substr(start, end);
				start = end;
				if(item =="int"){	
			     std::istringstream  iss(item);
			     int value;
			     iss>>value;
                 //itemarray[num] = value;			     
		          }
				else if(vec[currentcell]=="float"){	
					std::istringstream  iss(str);
					float value;
					iss>>value; 
					return &value;
				}
				else if(vec[currentcell]=="char"){
					char * tmp;
					strcpy(tmp,str.c_str());
					return  tmp;
				}
			}
			return nullptr;
		}
	}
}

void Dict::readLine(){
	std::ifstream file( filepath);
   file >> currentLine;
	file.close();
}

Dict::Dict(void)
{
}


Dict::~Dict(void)
{
}
