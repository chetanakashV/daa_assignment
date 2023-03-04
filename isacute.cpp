#include <iostream>
using namespace std;

class Vertex
{
public:
    double x, y;
    //vector<Edge *> outgoingEdges; // outgoing edges
    Vertex(int a, int b)
    {
        x = a;
        y = b;
    }
};

bool isAcute(Vertex* v1, Vertex* v2, Vertex* v3){
    double slope1, slope2;
    slope1 = (v2->y - v1->y) / (v2->x - v1->x);
    slope2 = (v2->y - v3->y) / (v2->x - v3->x);
    double tanti = (slope2 - slope1) / (1 + slope1*slope2);
    if(tanti >= 0)
        return true;
    else 
        return false;
}

int main(){
    
}