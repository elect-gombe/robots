#include <iostream>
#include <stdlib.h>
#include "vector2.hpp"
#include "arena.hpp"
#include <stdio.h>

extern "C"{
  char getChar(void);
};

/*key settings*/
/*key and move value
 * ex. 4 ...move left 
 */

const struct{
  char key;
  vector2 dir;
} vlookupdir[]={
  {'4',vector2(-1,0)},
  {'8',vector2(0,-1)},
  {'6',vector2(1,0)},
  {'2',vector2(0,1)},
  {'7',vector2(-1,-1)},
  {'9',vector2(1,-1)},
  {'1',vector2(-1,1)},
  {'3',vector2(1,1)},
};

vector2 getdir(char key){
  for(unsigned int i=0;i<sizeof(vlookupdir)/sizeof(vlookupdir[0]);i++){
    if(vlookupdir[i].key==key)return vlookupdir[i].dir;
  }
  return vector2(0,0);
}

int main(void){
  arena arena(60,20);
  vector2 p;
  char key;
  int score = 0;
  int ret;
  
  srandom(time(NULL));  
  arena.setrobots(2,p);
  arena.print(p);

  while(true){
    key = getChar();if(!isdigit(key))continue;
    if(key == '0')arena.playermoverandomly(p);
    arena.playerupdate(p,getdir(key));
    ret = arena.update(p);
    if(ret == -1){
      std::cout<<"game over"<<std::endl;
      break;
    }
    score += ret;
    std::cout<<"score"<<score<<std::endl;
    if(arena.isblank()){
      arena.setrobots(20,p);
      arena.print(p);
    }
  }

  std::cout<<"thank you for playing!\n"<<std::endl;
  return EXIT_SUCCESS;
}
