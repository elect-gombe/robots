#include <iostream>
#include <stdlib.h>
#include "vector2.hpp"
#include "arena.hpp"
#include <stdio.h>

int main(void){
  arena arena(20,30);
  vector2 p;
  srand(time(NULL));

  arena.setrobots(5,p);
  arena.print(p);

  while(true){
    getchar();
    arena.update(p);
    arena.print(p);
  }
  
  return EXIT_SUCCESS;
}

