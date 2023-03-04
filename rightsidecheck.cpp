// C++ Program to Determine Direction of Point
// from line segment
#include <iostream>
using namespace std;

// structure for point in cartesian plane.
struct Point {
	double x, y;
};

// constant integers for directions

void ans(vector<Point> P,vector<vector<Point> & finalpols){

    vector<Point> notches;
    L // push
}


int directionOfPoint(point A, point B, point P)
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
	return ZERO;
}

// Driver code
int main()
{
	point A, B, P;
    A = {1,1.5};
    B = {0,1};
    P = {0.1,1.5};

	int direction = directionOfPoint(A, B, P);
	if (direction == 1)
		cout << "Right Direction" << endl;
	else if (direction == -1)
		cout << "Left Direction" << endl;
	else
		cout << "Point is on the Line" << endl;
	return 0;
}