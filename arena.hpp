#pragma once
class arena{
public:
  arena(int width,int height);
  arena(arena *n);
  ~arena();
  int get_height(){return height;}
  int get_width(){return width;}
  void setrobots(int num,vector2& p);
  void print(const vector2& p);  
  int update(vector2 p);
  enum arena_e{
    _NONE=0,
    _ROBOT1=1,
    _HEAP=2,
  };
  arena_e& operator[](vector2 v){return aren[v.y][v.x];}

private:
  arena_e **aren;
  void printe(arena_e e);
  int width;
  int height;
  int robotsc;
  void clear();
  int kill(arena_e e);
};
