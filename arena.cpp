#include <iostream>
#include "vector2.hpp"
#include "arena.hpp"
#include <stdlib.h>
#include <assert.h>

void arena::printe(const arena_e e){
  switch(e){
  case _NONE:
    std::cout<<" ";
    break;
  case _ROBOT1:
    std::cout<<"+";
    break;
  }
}
void arena::print(const vector2& p){
  vector2 i;

  for(i.x=0;i.x<width;i.x++){
    for(i.y=0;i.y<height;i.y++){
      if(p==i)std::cout<<"@";
      else printe(operator[](i));
    }
    std::cout<<std::endl;
  }
}

void arena::setrobots(const int num,vector2& p){
  robotsc = num;
  vector2 vlast;//to be player...

  //last one will be mutation!
  for(int i=0;i<num+1;i++){
    aren[i%width][i/width] = _ROBOT1;
  }
  
  {
    vector2 i;
    for(i.x=0;i.x<width;i.x++){
      for(i.y=0;i.y<height;i.y++){
	vector2 vt(rand()%width,rand()%height);
	arena_e tmp = operator[](i);
	operator[](i) = operator[](vt);
	operator[](vt) = tmp;
	if(i == vlast)vlast = vt;
	if(vt == vlast)vlast = i;
	if(operator[](vt)==_ROBOT1)
	  vlast = vt;
      }
    }
  }
  assert(operator[](vlast)==_ROBOT1);
  operator[](vlast) = _NONE;
  p = vlast;
}

void update(){
  
}

void arena::clear(){
  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++) aren[i][j] = _NONE;
  }
}

arena::arena(int _width,int _height){
  width = _width;
  height = _height;
  aren = new arena_e*[_height];
  for(int i=0;i<_height;i++){
    aren[i] = new arena_e[_width];
  }
  clear();
}

arena::~arena(){
  for(int i=0;i<width;i++){
    delete []aren[i];
  }
  delete []aren;
}
