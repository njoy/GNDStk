#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;

int main()
{
   Tree("employees.xml").write("employees.json");
}
