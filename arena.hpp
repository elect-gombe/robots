#pragma once

class arena{
public:
  arena(int width,int height);
  arena(arena *n);
  ~arena();
  int get_height(){return height;}
  int get_width(){return width;}
  void setrobots(int num,vector2& p);
  void print();
  void print(vector2 p);
  int update(vector2 p);
  void playerupdate(vector2& vp,const vector2& vdir);
  void playermoverandomly(vector2& vp);
  bool isblank();
  enum arena_e{
    _NONE=0,
    _ROBOT1=1,
    _HEAP=2,
    _PLAYER=3,
  };
  arena_e& operator[](vector2 v){return aren[v.y][v.x];}
  void clear();  
private:
  arena_e **aren;
  void printe(arena_e e);
  int width;
  int height;
  int robotsc;
  int kill(arena_e e);
};
