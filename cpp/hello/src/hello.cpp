#include "hello.h"

int x = 3;
const int y = 33;
std::string hello(std::string name)
{

#if __ARCH_X86
  double v75 = 0.75*38 + 33;
 // one liner
  #if 0
  std::string message;
  message += "Hello, ";
  message += name;
  #endif
  /* message += "!"; */
  return message;
#endif
}
