#include <iostream>

#include "graph.hpp"
#include "vector2.hpp"

int main()
{
    {
        Graph g; 
        for (int i = 0; i < 10; i++)
        {
            Vector2 v((float)i, (float)i);
            g.pushPoint(v);
        }

        
        Vector2 p3 = Vector2(7.2, 4.4);
        g.pushPoint(p3);
        Vector2 p4 = Vector2(2.2, 8.4);
        g.showPoint();
    }
    return 0;
}