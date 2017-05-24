#include <iostream>
#include "vector2.hpp"
#include "arena.hpp"
#include <stdlib.h>
#include <assert.h>

int arena::kill(arena_e e){
  int score;
  switch(e){
  case _ROBOT1:
    score = 10;
    break;
  default:
    score = -1;
    break;
  }

  return score;
}

void arena::printe(const arena_e e){
  switch(e){
  case _NONE:
    std::cout<<" ";
    break;
  case _ROBOT1:
    std::cout<<"+";
    break;
  case _HEAP:
    std::cout<<"#";
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
    aren[i/width][i%width] = _ROBOT1;
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

int arena::update(vector2 p){
  vector2 i;
  vector2 d;
  vector2 n;
  arena temp_arena(this);
  int score = 0;

  for(i.y=0;i.y<height;i.y++){
    for(i.x=0;i.x<width;i.x++)
      if(temp_arena[i] == _ROBOT1)temp_arena[i] = _NONE;
  }
  
  temp_arena.print(p);
  for(i.y=0;i.y<height;i.y++){
    for(i.x=0;i.x<width;i.x++) {
      if(operator[](i) == _ROBOT1){
	d = nearest_direction(i,p);
	n = d+i;
	// std::cout << "d("<< d.x <<","<<d.y<<")";
	// std::cout<<std::endl;
	// std::cout << "n("<< n.x <<","<<n.y<<")"; 
	// std::cout<<std::endl;
	if(temp_arena[n] != _NONE){
	  score += kill(temp_arena[i]);
	  temp_arena[n] = _HEAP;
	}else{
	  temp_arena[n] = operator[](i);
	}
      }
    }
  }

  for(i.y=0;i.y<height;i.y++){
    for(i.x=0;i.x<width;i.x++)
      operator[](i) = temp_arena[i];
  }
}


void arena::clear(){
  vector2 i;
  for(i.y=0;i.y<height;i.y++){
    for(i.x=0;i.x<width;i.x++) operator[](i) = _NONE;
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

arena::arena(arena *a){
  width = a->get_width();
  height = a->get_height();
  aren = new arena_e*[height];
  for(int i=0;i<height;i++){
    aren[i] = new arena_e[width];
    for(int j=0;j<width;j++){
      aren[i][j] = a->aren[i][j];
    }
  }
}

arena::~arena(){
  for(int i=0;i<height;i++){
    delete []aren[i];
  }
  delete []aren;
}
