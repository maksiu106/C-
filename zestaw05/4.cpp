#include <iostream>

class Drawing
{
 public:
  virtual ~Drawing() {}
  virtual void drawLine() {};
  virtual void drawCircle() {};
};

class DP1
{
public:
    void draw_a_line()
    {
        std::cout << " ----" << std::endl << "|    |" << std::endl << "|    |" << std::endl << " ----" << std::endl;        
    }
    void draw_a_circle()
    {
        std::cout << "    * *" << std::endl << "  *     *" << std::endl << "  *     *" << std::endl << "    * *" << std::endl;
    }
};

class DP2
{
public:
    void drawline()
    {
        std::cout << " _______" << std::endl << "|       |" << std::endl << "|       |" << std::endl << " ______" << std::endl;       
    }
    void drawcircle()
    {
        std::cout << "     x x" << std::endl << "   x     x" << std::endl << "  x       x" << std::endl << "  x       x" << std::endl << "   x     x" << std::endl << "     x x" << std::endl;
    }
};
 
class V1Drawing : public Drawing
{
private:
    DP1 obiekt;
public:
    V1Drawing(DP1 obiekt) : obiekt(obiekt) {}
    void drawLine() {obiekt.draw_a_line();}
    void drawCircle() {obiekt.draw_a_circle();}
};

class V2Drawing : public Drawing
{
private:
    DP2 obiekt;
public:
    V2Drawing(DP2 obiekt) : obiekt(obiekt) {}
    void drawLine() {obiekt.drawline();}
    void drawCircle() {obiekt.drawcircle();}
};

class Shape
{
protected:
  Drawing *drawing;
public:
  Shape(Drawing *drawing) : drawing(drawing) {}
  virtual ~Shape() {}
  virtual void draw() {}
  void setLib(Drawing *obiekt) {drawing = obiekt;}
};

class Rectangle : public Shape
{
public:
  Rectangle(Drawing *drawing) : Shape(drawing) {}
  virtual void draw()
  {
      return this->drawing->drawLine();
  }
};

class Circle : public Shape
{
public:
  Circle(Drawing *drawing) : Shape(drawing) {}
  virtual void draw()
  {
      return this->drawing->drawCircle();
  }
};

int main() {
DP1 library1; // pierwsza biblioteka
DP2 library2; // druga biblioteka

Drawing *d1 = new V1Drawing( library1 );
Drawing *d2 = new V2Drawing( library2 );

Shape *p1 = new Rectangle( d1 );
Shape *p2 = new Circle( d2 );

std::cout << "obiekt p1 (prostokat) za pomoca interfejsu V1:" << std::endl;
p1->draw(); // rectangle linia V1
std::cout << "obiekt p2 (okrag) za pomoca interfejsu V2:" << std::endl;
p2->draw(); // circle okrag V2


std::cout << std::endl << "\nZamiana interfejsow dla obu obiektow\n" << std::endl;
p1->setLib( d2 );
p2->setLib( d1 );

std::cout << "obiekt p1 (prostokat) za pomoca interfejsu V2:" << std::endl;
p1->draw(); // rectangle linia V2
std::cout << "obiekt p2 (okrag) za pomoca interfejsu V1:" << std::endl;
p2->draw(); // circle okrag V1

delete p1;
delete p2;
delete d1;
delete d2;
}