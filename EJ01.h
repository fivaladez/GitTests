//Exercise of classes
#include <iostream>
using namespace std;
/*Nuevo comentario para branch 1*/

class Polygon {
	protected:
		int width, height;
	public:
		Polygon (int a, int b):width(a), height(b){}//Contructor
		virtual int area(void) =0;//Abstract base class
};

class Triangle : public Polygon {
	private: //For being visible to friend class
		int secret = 5;
	public:
		friend class Rectangle;//Friend Class - Class Rectangle' members can see class triangle's members
		Triangle(int a, int b):Polygon(a,b){}
		int area(){return (width*height)/2;}
		friend void printSecret2(Triangle&);//Friend function
		int seeMe = 0;
};

void printSecret2(Triangle& t2){
    cout <<"The secret, using a Friend function in class Triangle is: "<< t2.secret << endl;
}

class Rectangle: public Polygon {
	public:
		Rectangle(int a, int b):Polygon(a,b){}
		int area(){return width*height;}
		void printSecret(Triangle&);
};

void Rectangle::printSecret(Triangle& t){
    cout<< "The secret, usisng  a Friend Class Triangle is: "<< t.secret <<endl;
    t.seeMe = 2;
}

int main () {
  Rectangle rect(2,3);
  Triangle trgl(2,3);
  Triangle trgl2(2,4);
  
  rect.printSecret(trgl);//this function is an element of the class Rectangle
						 //It can use trgl because Rectangle is a Friend Class
  printSecret2(trgl);//It is not a member of the class Triangle but,
					 //you can have access because it is a friend function
  
  Polygon *p1 = &rect;
  Polygon *p2 = &trgl;
  
  cout << "The area of the rectangle is: " << p1->area() << endl;
  cout << "The area of the triangle is: " << p2->area() << endl;
  
  Polygon *p3 = new Rectangle(2,5);
  cout << "The area of the rectangle pointer is: " << p3->area() << endl;
  delete p3;
  
  return 0;
}