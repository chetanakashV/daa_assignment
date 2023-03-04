#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>

using namespace std;

class Edge;
class Face;
class Vertex
{
public:
    int x, y;
    vector<Edge *> outgoingEdges; // outgoing edges
    Vertex(int a, int b)
    {
        x = a;
        y = b;
    }
};

class Edge
{

public:
    Vertex *origin; // e.destination = e.twin.origin
    Edge *twin;
    Face *left;
    vector<Edge *> nextEdges, previousEdges; // in counter clockwise wrt to face
};

class Face
{

public:
    Edge *incidet; // anti-clock wise
};

class DCEL
{
public:
    vector<Vertex *> v; // vertices

    vector<Edge *> e; // edges

    vector<Face *> f; // faces

    // add edge
    void addVertex(int x, int y);
    // add  edge
    void addEdge(int x1, int y1, int x2, int y2);
    // add face
};

void DCEL ::addVertex(int x, int y)
{
    Vertex *vnew = new Vertex(x, y);
    v.push_back(vnew);
}
void DCEL::addEdge(int x1, int y1, int x2, int y2)
{
    Edge *e1 = new Edge();
    Edge *e2 = new Edge();

    e.push_back(e1);
    e.push_back(e2);

    Vertex *v1, *v2;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]->x == x1 && v[i]->y == y1)
        {
            v1 = v[i];
        }
        if (v[i]->x == x2 && v[i]->y == y2)
        {
            v2 = v[i];
        }
    }

    e1->twin = e2;
    e2->twin = e1;

    e1->origin = v1;
    e2->origin = v2;

    e1->nextEdges = v2->outgoingEdges;
    e2->nextEdges = v1->outgoingEdges;

    e1->previousEdges = v1->outgoingEdges;

    // cout << (int )(e1->previousEdges.size())-1 <<"  "<< i<<endl;
    for (int i = 0; i < (int)(e1->previousEdges.size()) - 1; i++)
    {
        e1->previousEdges[i] = e1->previousEdges[i]->twin;
    }

    e2->previousEdges = v2->outgoingEdges;
    for (int i = 0; i < (int)(e2->previousEdges.size()) - 1; i++)
    {
        e2->previousEdges[i] = e2->previousEdges[i]->twin;
    }

    // adding outgoing edges at the end so that next edges and previous edges won't get affected
    v1->outgoingEdges.push_back(e1);
    v2->outgoingEdges.push_back(e2);
}


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

DCEL* convexalize(DCEL* poly){
    vector<Vertex*> list;
    list.push_back(poly->v[0]);
    int i = 1;
    while(true){
        
        
            
        
    }
}

int main(){

    fstream file("inp.txt");
    
    int n;
    file>>n;
    DCEL* poly = new DCEL();
    
    for(int i = 0; i < n; i++){
        int x, y;
        file>>x>>y;
        cout<<x<<" "<<y<<endl;
        poly->addVertex(x,y);
    }

    for(int i = 1; i < poly->v.size(); i++){
        poly->addEdge(poly->v[i-1]->x, poly->v[i-1]->y, poly->v[i]->x, poly->v[i]->y);
    }

    file.close();
    DCEL* final = convexalize(poly);
    return 0;
}