#include <iostream>
#include <stdlib.h>
#include "vector2.hpp"
#include "arena.hpp"

int main(void){
  arena arena(40,30);
  vector2 p;
  srand(time(NULL));
  arena.setrobots(50,p);
  arena.print(p);
  
  return EXIT_SUCCESS;
}

