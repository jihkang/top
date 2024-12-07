#include "graph.hpp"
#include "vector2.hpp"

Graph::Graph():  minX(0.0), minY(0.0), maxX(1.0), maxY(1.0) { }
Graph::~Graph() { }

void Graph::pushPoint(Vector2& v)
{
    float vX = v.getX();
    float vY = v.getY();
    if (minX > vX) {
        minX = vX - 1;
    } else if (maxX < vX) {
        maxX = vX + 1;
    }
    if (minY > vY) {
        minY = vY - 1;
    } else if (maxY < vY) {
        maxY = vY + 1;
    }
    p.push_back(v);
    pointList.push_back(std::make_pair((int)vX, (int)vY));
}

void Graph::showList() {
    for (unsigned int i = 0; i < pointList.size(); i++)
    {
        std::cout << pointList[i].first << ", " << pointList[i].second << "\n";
    }
}

void Graph::showPoint()
{
    int xS = int(minX - 1);
    int xE = int(maxX + 1);
    int yS = int(minY - 1);
    int yE = int(maxY + 1);

    for (int i = yE; i >= yS; i--)
    {
        if (i != yS)
        {
            std::cout << i << " ";        
            for (int j = xS + 1; j <= xE; j++)
            {
                if (i != yS)
                {
                    bool bFind = false;
                    
                    for (unsigned int k = 0; k < pointList.size(); k++)
                    {
                        if (pointList[k].first == j && pointList[k].second == i)
                        {
                            bFind = true; 
                            break;
                        }
                    }

                    std::cout << (bFind ? "X " : ". ");
                }
            }
        }
        else {
            std::cout << " ";
            for (int j = xS + 1; j <= xE; j++)
            {
                std::cout << j << " ";
            }
        }
        std::cout << std::endl;
    }
}