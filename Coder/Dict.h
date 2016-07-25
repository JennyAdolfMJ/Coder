#pragma once
#include <fstream>
#include <string>
#include <vector>

class Dict
{
public:
	Dict(std::string);
	~Dict(void);

   bool open();
   bool close();

   bool next();
   bool readLine();
   void readArray(int *);
   void readArray(float *);
   void readArray(char **);

   template <class T> class Type;
   template <class T>
   T &read() {
      T tmp("");
      tmp.parse();
      return tmp; 
   };

private:
   int readInt(std::string);
   float readFloat(std::string);
   char *readChar(std::string);
   
private:
   std::string m_filepath;
   std::ifstream m_fs;
   std::string m_currentLine;
   std::string m_currentCell;
};

