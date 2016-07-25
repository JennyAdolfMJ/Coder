#pragma once
#include <string>

class Type
{
public:
   Type(std::string);
   ~Type();

   Type& parse();

protected:
   std::string m_str;
};

