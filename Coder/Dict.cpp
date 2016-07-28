#include "Dict.h"

#include <sstream> 

Dict::Dict(std::string path, std::vector<Type>& types)
{
   m_filepath = path;
   m_types = types;
}

Dict::~Dict(void)
{
}

bool Dict::open()
{
   std::ifstream m_fs(m_filepath);
   return true;
}

bool Dict::close()
{
   m_fs.close();
   return true;
}

bool Dict::next()
{
   if (m_currentLine.empty())
      return false;

   int index = m_currentLine.find('\t');
   if (index == -1)
   {
      return false;
   }
   else
   {
      m_currentCell = m_currentLine.substr(0, index);
      m_currentLine = m_currentCell.erase(0, index);

      return true;
   }
}

bool Dict::readLine(){

   m_fs >> m_currentLine;

   if (m_currentLine.empty())
      return false;
   else
      return true;
}

#pragma region private

int  Dict::readInt(std::string str)
{
   std::istringstream iss(str);
   int value;
   iss >> value;
   return value;
}

float Dict::readFloat(std::string str)
{
   std::istringstream iss(str);
   float value;
   iss >> value;
   return value;
}

char* Dict::readChar(std::string str, unsigned& size)
{
   size = str.size();
   char *tmp = new char[size];

   strcpy_s(tmp, str.size(), str.c_str());
   return tmp;
}

#pragma endregion


