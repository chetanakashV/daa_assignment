#include<bits/stdc++.h>
using namespace std;

struct Point
{
    double x,  y;
};



bool isAcute(Point v1, Point v2, Point v3){
    double slope1, slope2;
    slope1 = (v1.y - v1.y) / (v2.x - v1.x);
    slope2 = (v2.y - v3.y) / (v2.x - v3.x);
    double tanti = (slope2 - slope1) / (1 + slope1*slope2);
    if(tanti >= 0)
        return true;
    else 
        return false;
}


int main()
{
    cout<<isAcute({1,2},{0.9,1},{1,0})<<endl;
    
 return 0;
}