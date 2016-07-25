#include "Type.h"

Type::Type(std::string str)
{
   m_str = str;
}

Type::~Type()
{
}

Type& Type::parse()
{
   return Type("");
}