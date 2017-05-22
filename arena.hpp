#pragma once
class arena{
public:
  arena(int width,int height);
  ~arena();
  int get_height(){return height;}
  int get_width(){return width;}
  void setrobots(int num,vector2& p);
  void print(const vector2& p);  
  enum arena_e{
    _NONE=0,
    _ROBOT1=1,
  };
  private:
  arena_e **aren;
  arena_e& operator[](vector2 v){return aren[v.y][v.x];}
  void printe(arena_e e);
  int width;
  int height;
  int robotsc;
  void clear();
};
