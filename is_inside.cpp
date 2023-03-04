#include<bits/stdc++.h>
using namespace std;

struct Point {
   double x, y;
};
int side(Point A, Point B, Point P)
{
    const int RIGHT = 1, LEFT = -1, ZERO = 0;
	// subtracting co-ordinates of point A from
	// B and P, to make A as origin
	B.x -= A.x;
	B.y -= A.y;
	P.x -= A.x;
	P.y -= A.y;

	// Determining cross Product
	double cross_product = B.x * P.y - B.y * P.x;

	// return RIGHT if cross product is positive
	if (cross_product > 0)
		return LEFT;

	// return LEFT if cross product is negative
	if (cross_product < 0)
		return RIGHT;

	// return ZERO if cross product is zero.
	return 0;
}

bool  isInside(Point p ,vector<Point> polygon){
    int n = polygon.size();
    for (int i = 0; i < n-1; i++)
    {
        if(side(polygon[i],polygon[i+1],p) == -1){
            return false;
        }
    }
    if(side(polygon[n-1],polygon[0],p) == -1){
        return false;
    }
    return true;
}


int main() {
  
   // Define a Point to test
   Point point = {0.5,1.5};
  
   // Define a polygon
   vector<Point> polygon = {{0, 1}, {0,2}, {1, 1.5}};


  
   if (isInside(point, polygon)) {
       cout << "Point is inside the polygon" << endl;
   } else {
       cout << "Point is outside the polygon" << endl;
   }

   return 0;
}