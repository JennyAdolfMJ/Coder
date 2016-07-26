#pragma once
#include <fstream>
#include <string>
#include <vector>

enum Type
{
   intType,
   floatType,
   charType,
   arrayType,
   customType
};

class Dict
{
public:
	Dict(std::string, std::vector<Type>&);
	~Dict(void);

   bool open();
   bool close();

   bool next();
   bool readLine();
   void readArray(int *);
   void readArray(float *);
   void readArray(char **);

   template <class T>
   T read() {
      T tmp("");
      return tmp; 
   };

   template <> int read<int>()
   {
      return readInt(m_currentCell);
   }

   template <> float read<float>()
   {
      return readFloat(m_currentCell);
   }

   template <> char *read<char *>()
   {
      return readChar(m_currentCell);
   }

private:
   int readInt(std::string);
   float readFloat(std::string);
   char *readChar(std::string);
   
private:
   std::string m_filepath;
   std::vector<Type> m_types;
   std::ifstream m_fs;
   std::string m_currentLine;
   std::string m_currentCell;
};