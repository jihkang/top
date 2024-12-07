#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <utility>

#define pi std::pair<int, int>

class Vector2;

class Graph
{
private:
    std::vector<Vector2> p;
    std::vector<pi> pointList;
    float minX, minY;
    float maxX, maxY;
private:
    Graph(const Graph& grp);
public:
    Graph();
    ~Graph();
public:
    void pushPoint(Vector2& v);
    void showPoint();
    void showList();
};

#endif