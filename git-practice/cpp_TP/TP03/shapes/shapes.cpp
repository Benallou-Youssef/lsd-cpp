#include <iostream>

using namespace std;

class shape{		//A class shape containing height and width
	protected:
		float height;
		float width;
	public:
		shape(float w ,float h) {height = w ; width = h;}
};

class rectangle : public shape{			//Class rectangle inherits from the class shape. It has a function area() that returns the area of the given rectangle
	public:
		rectangle(float w ,float h) : shape(w ,h) {}
		float area() {return height*width;}
};

class triangle : public shape{			//Class triangle inherits from the class shape. It has a function area() that returns the area of the given triangle
	public:
		triangle(float w ,float h) : shape(w ,h) {}
		float area() {return (height*width)/2;}
};

int main(){
	
	triangle T(3,2);
	cout << T.area() << endl;
	
	rectangle R(5,3);
	cout << R.area() << endl;
	
	return 0;
}