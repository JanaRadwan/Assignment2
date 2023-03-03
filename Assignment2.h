#include <iostream>
#include <cmath>
using namespace std; 

class point
{
private:
	float x;
	float y;
public:
	point();
	point(float , float );
	void Setx(float X);
	void Sety(float Y);
	float getx(); 
	float gety();
	void display(); 
	double Distance(point p );
};