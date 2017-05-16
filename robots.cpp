#include <iostream>

class vector2{
public:
  int x;
  int y;

  vector2(int _x,int _y):x(_x),y(_y){}
  vector2(const vector2& v):x(v.x),y(v.y){};
  vector2():x(0),y(0){};
  vector2& operator=(const vector2& v);
  vector2 operator+();
  vector2 operator-();
  void print(void);
};

vector2 operator+(const vector2& v1,const vector2& v2);
vector2 operator*(const vector2& v1,int n);
vector2 operator-(const vector2& v1,const vector2& v2);

class arena{
public:
  arena(int width,int height);
  ~arena();
  int get_height(){return height;}
  int get_width(){return width;}
  void setrobots(int num);
  enum arena_e{
    _NONE=0,
    _ROBOT1=1,
  };
  private:
  arena_e **aren;
  int width;
  int height;
  int robotsc;
  void clear();
};



void arena::setrobots(int num){
  robotsc = num;
  int last;

  for(int i=0;i<num+1;i++){
    aren[i%width][i/width] = _ROBOT1;
  }
  arena_e tmp;
  int tx,ty;
  for(int x=0;x<width;x++){
    for(int y=0;y<height;y++){
      tx = rand()%width;
      ty = rand()%width;
      tmp =  aren[y][x];
    }
  }
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

int main(void){
  arena arena(20,20);

  
  return EXIT_SUCCESS;
}

