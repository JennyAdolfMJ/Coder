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

class NotSupportedException {};

class Dict
{
public:
	Dict(std::string, std::vector<Type>&);
	~Dict(void);

   bool open();
   bool close();

   bool next();
   bool readLine();

   template <class T>
   T read() {
      T tmp(m_currentCell);
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

   template <class T>
   T read(unsigned &size) {
      throw NotSupportedException();
   };

   template <> char *read<char *>(unsigned &length)
   {
      return readChar(m_currentCell, length);
   }

   template <> int* read<int *>(unsigned &size)
   {
      size = readInt(m_currentCell.substr(0, m_currentCell.find(':')));
      int *tmp = new int[size];

      int value; unsigned index;
      for (unsigned i = 0; i < size; i++)
      {
         index = m_currentCell.find(',');
         value = readInt(m_currentCell.substr(0, index));
         m_currentCell.erase(0, index);
         tmp[i] = value;
      }

      return tmp;
   }

   template <> float* read<float *>(unsigned &size)
   {
      size = readInt(m_currentCell.substr(0, m_currentCell.find(':')));
      float *tmp = new float[size];

      float value; unsigned index;
      for (unsigned i = 0; i < size; i++)
      {
         index = m_currentCell.find(',');
         value = readFloat(m_currentCell.substr(0, index));
         m_currentCell.erase(0, index);
         tmp[i] = value;
      }

      return tmp;
   }

   template <> std::string* read<std::string *>(unsigned &size)
   {
      size = readInt(m_currentCell.substr(0, m_currentCell.find(':')));
      std::string *tmp = new std::string[size];

      std::string value; unsigned index;
      for (unsigned i = 0; i < size; i++)
      {
         index = m_currentCell.find(',');
         value = m_currentCell.substr(0, index);
         m_currentCell.erase(0, index);
         tmp[i] = value;
      }

      return tmp;
   }

private:
   int readInt(std::string);
   float readFloat(std::string);
   char *readChar(std::string, unsigned &);
   
private:
   std::string m_filepath;
   std::vector<Type> m_types;
   std::ifstream m_fs;
   std::string m_currentLine;
   std::string m_currentCell;
};