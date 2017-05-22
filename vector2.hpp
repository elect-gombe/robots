#pragma once
class vector2{
public:
  int x;
  int y;

  vector2(int _x,int _y):x(_x),y(_y){}
  vector2(const vector2& v):x(v.x),y(v.y){};
  vector2():x(0),y(0){};

  vector2& operator+=(const vector2& v){
    this->x += v.x;
    this->y += v.y;
    return *this;
  }
  
  vector2& operator-=(const vector2& v){
    this->x -= v.x;
    this->y -= v.y;
    return *this;
  }

  vector2& operator=(const vector2& v){
    this->x = v.x;
    this->y = v.y;
    return *this;
  }

  vector2 operator+(){return *this;}
  vector2 operator-(){
    vector2 v;
    v.x = -this->x;
    v.y = -this->y;
    return v;
  }

  void print();
};

inline static
bool operator==(vector2 v1,vector2 v2){return v1.x == v2.x&&v1.y == v2.y;}

inline static
vector2 operator+(const vector2& v1,const vector2& v2){
  vector2 w;

  w.x = v1.x+v2.x;
  w.y = v1.y+v2.y;

  return w;
}

inline static
vector2 operator-(const vector2& v1,const vector2& v2){
  vector2 w;

  w.x = v1.x-v2.x;
  w.y = v1.y-v2.y;

  return w;
}
