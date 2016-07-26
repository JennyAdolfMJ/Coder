#pragma once
#include <string>

class CustomType
{
public:
   CustomType(std::string);
   ~CustomType();

protected:
   virtual void parse() {};

protected:
   std::string m_str;
};

