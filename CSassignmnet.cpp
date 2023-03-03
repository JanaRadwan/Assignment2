#include "Assignment2.h"


point Center(point C[], int n)
{
	float sumx = 0.0,sumy =0.0, AVGx, AVGy;
	
		for (int i = 0; i < n;i++)
		{
		sumx = sumx + C->getx();
		sumy = sumy + C->gety();
		C++;
		}
		C = C - n;
		AVGx = sumx / n;
		AVGy = sumy / n;
		point center(AVGx, AVGy);
		return center;
}
void Belong(point A, point B, point P)
{
	if (A.Distance(P) < B.Distance(P))
	{
		cout << " belongs to cluster A with a minimum distance of " << A.Distance(P)<<endl;
		
	 }
	else
	{
		cout << " belongs to cluster B with a minimum distance of " << B.Distance(P)<< endl;
		
	}

}

int main()
{
	int n; // number of points in cluster A
	cout << " Please Enter the number of points desired for cluster A" << endl;
	cin >> n;
	point* A;
	A = new point[n]; 
	srand(time(0));
	for (int i=0; i < n;i++)
	{
		A->Setx((rand() % 21) + 70);
		A->Sety((rand() % 21) + 70);
		A++;
	}
	A = A - n;
	
	int x; // number of points in cluster B 
	cout << " Please Eenter the number of points desired for cluster B" << endl;
	cin >> x;
	point* B;
	B = new point[x]; 
	srand(time(0));
	for (int i = 0; i < x;i++)
	{
		B->Setx((rand() % 21) + 20);
		B->Sety((rand() % 21) + 20);
		B++;
	}
	B = B - x;
	
	int m = 20; // number of m points 
	point* p;
	p = new point[m];
	srand(time(0));
	for (int i = 0; i < m;i++)
	{
		p->Setx((rand() % 96) + 5);
		p->Sety((rand() % 96) + 5);
		p++;
	}
	p = p - m;
	cout << " the following m points belong to the stated cluster : " << endl;
	for (int i = 1; i <= m;i++)
	{
		cout << " point p: m = " << i; Belong(Center(A, n), Center(B, x), p[i]);
	}
	


	return 0;
}

point::point(){x = 0; y = 0;}

point ::point(float X, float Y)
{ x = X; y = Y;}

void point:: Setx(float X){
	x = X;}

void point::Sety(float Y)
{
	y = Y;
}
float point::getx() {
	return x;
}
float point::gety() {
	return y;
}

void point::display() {
	cout << "(" << x << "," << y << ")" << endl;
}

double point::Distance( point p)
{
	float x2 = p.getx();
	float y2 = p.gety();

	return sqrt(pow(x - x2, 2) + pow(y - y2, 2));
}