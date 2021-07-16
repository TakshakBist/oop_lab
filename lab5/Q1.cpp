#include <iostream>
#include <cmath>
#define SUCCESS 0
using namespace std;
class Coordinate;
class Vector;
class Polar
{
private:
  float radius , theta;
public:
  Polar (float r ,float angle ):radius(r),theta(angle){};
  friend class Vector; // let Vector acess all its private data types
  Coordinate toCartesian(); // not defined here due to incomplete type error
};
class Vector
{
public: 
  // not defined here due to incomplete type error

  Coordinate add(Coordinate a, Coordinate b);
  Coordinate sub(Coordinate a, Coordinate b);
  Coordinate mul(Coordinate a, Coordinate b);
  Coordinate div(Coordinate a, Coordinate b);
};

class Coordinate
{
private:
  float x, y;
public:
  Coordinate(float a, float b):x(a),y(b){};
  friend Coordinate Vector::add(Coordinate a, Coordinate b); // let Vectors add member access private members
  friend Coordinate Vector::sub(Coordinate a, Coordinate b); // let Vecors sub member access private members
  Polar toPolar()
  {
    Polar temp(sqrt(x*x+y*y),atanf(y/x));
    return temp;
  }
  void display()
  {
    cout << "(" << x << "," << y <<  ")";
  }
};

Coordinate Polar::toCartesian()
  {
    Coordinate C(radius*cos(theta), radius *sin(theta));
    return C;
  }
Coordinate Vector::add(Coordinate a, Coordinate b)
  {
    Coordinate temp(a.x+b.x, a.y+b.y);
    return temp;
  }
Coordinate Vector::sub(Coordinate a, Coordinate b)
  {
    Coordinate temp(a.x-b.x, a.y-b.y);
    return temp;
  }
Coordinate Vector::mul(Coordinate a, Coordinate b)
  {
    Polar pa = a.toPolar();
    Polar pb = b.toPolar();
    Polar p(pa.radius*pb.radius,pa.theta+pb.theta);
    return p.toCartesian();
    
  }
Coordinate Vector::div(Coordinate a, Coordinate b)
  {
    Polar pa = a.toPolar();
    Polar pb = b.toPolar();
    Polar p(pa.radius/pb.radius,pa.theta-pb.theta);
    return p.toCartesian();
  }
  
int main()
{
  int x , y;
  char temp; // garbage value of ,
  cout << "Enter cordinate x y in format x,y";
  cin >> x >> temp >> y;
  Coordinate a(x,y);
  cout << "Enter cordinate x y in format x,y";
  cin >> x >> temp >> y;
  Coordinate b(x,y);
  Vector v; 
  Coordinate c = v.add(a,b);
  cout << "The sum is ";
  c.display();
  cout << endl;
  Coordinate d = v.sub(a,b);
  cout << "The difference is";
  d.display();
  cout << endl;
  Coordinate p = v.mul(a,b);
  cout << "The product is";
  p.display();
  cout << endl;
  Coordinate q = v.div(a,b);
  cout << "The quotient is";
  q.display();
  cout << endl;
  return SUCCESS;
}