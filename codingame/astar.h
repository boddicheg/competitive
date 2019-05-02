#ifndef ASTAR_H
#define ASTAR_H

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <limits>
#include <algorithm>
#include <queue>
#include <map>

#define DEBUG
using namespace std;

constexpr int INF = numeric_limits<int>::max();

template<typename T>
struct node
{
    T value;
};

template<typename T>
struct link
{
    int b;
    int e;
    T cost;
};

/*!
 * Class incapsulate graph strcture
 */
template<typename T>
class Graph
{
public:
    Graph()
    {}

    ~Graph()
    {}

    void AddLink( int start, int end, T cost )
    {
        if( !IsNode(start) || !IsNode(end) )
        {
            throw std::logic_error( "Link is incorrect" );
        }
        m_links.push_back( { start, end, cost } );
    }

    void AddNode( T value ) { m_nodes.push_back( { value } );}

    size_t size() const { return m_nodes.size(); }

    /**
   * @brief Dijkstra algo with O(n^2 + m) complexity
   *
   * @param start Start path position
   * @param end End path position
   *
   * @return path
   */
    std::vector<int> Path( int startNode, int endNode ) const
    {
        size_t nodes = m_nodes.size();
        if( !IsNode( startNode ) )
        {
            throw std::logic_error("Wrong start path position");
        }
        if( !IsNode( endNode ) )
        {
            throw std::logic_error("Wrong end path position");
        }
        std::map<size_t, int> distances;
        std::map<size_t, bool> marks;
        std::map<size_t, size_t> parents;
        for( size_t i = 0; i < m_nodes.size(); ++i )
        {
            auto& node = m_nodes.at( i );
            distances.emplace( node.value, INF );
            marks.emplace( node.value, false );
            parents.emplace( node.value, INF );
        }

        distances.at( startNode ) = 0;
        // For each node...
        for (size_t i = 0; i < nodes; ++i)
        {
            // Get node with minimal distance
            int vertex = -1;
            for (size_t j = 0; j < nodes; ++j)
            {
                auto& node = m_nodes.at( j );
                size_t index = node.value;
                if(
                    !marks.at(index) &&
                    ( vertex == -1 || distances.at(index) < distances.at(vertex) )
                )
                {
                    vertex = index;
                }
            }

            if( vertex == INF )
            {
                break;
            }
            // Set vertex as already viewed
            marks.at(vertex) = true;
            // Get all edges from vertex
            std::vector<link<T>> edges;
            for( size_t j = 0; j < m_links.size(); ++j )
            {
                link<T> edge = m_links.at(j);
                if( edge.b == vertex || edge.e == vertex )
                {
                    edges.push_back(edge);
                }
            }
            // Calculate minimal paths to each vertex in graph
            for( size_t j = 0; j < edges.size(); ++j )
            {
                size_t to = (edges.at(j).b == vertex) ? edges.at(j).e : edges.at(j).b;
                T length = edges.at(j).cost;
                if (distances.at(vertex) + length < distances.at(to))
                {
                    distances.at(to) = distances.at(vertex) + length;
                    parents.at(to) = vertex;
                }
            }
        }
        // Build minimal path from start to end
        std::vector<int> minimalPath;
        for( int i = endNode; i != startNode; i = parents.at(i) )
        {
            minimalPath.push_back(i);
        }
        minimalPath.push_back(startNode);
        std::reverse(minimalPath.begin(), minimalPath.end());
        return minimalPath;
    }

    bool IsNode( T comp ) const
    {
        for( size_t i = 0; i < m_nodes.size(); ++i )
        {
            auto& node = m_nodes.at( i );
            if( node.value == comp )
            {
                return true;
            }
        }
        return false;
    }

private:
    std::vector<link<T>> m_links;
    std::vector<node<T>> m_nodes;
};

enum class ECell
{
    Floor,
    Wall
};

struct vec
{
    int x;
    int y;
    vec()
        : x(0)
        , y(0)
    {}

    vec( int _x, int _y )
        : x(_x)
        , y(_y)
    {}
};

class AStar
{
public:
    void SetBoard( const vector<string>& _board )
    {
        h = _board.size();
        assert( h != 0 );
        for( size_t i = 0; i < h; ++i )
        {
            auto& row = _board.at( i );
            w = row.size();
            vector<ECell> converted;
            for( size_t j = 0; j < w; ++j )
            {
                auto& cell = row.at(j);
                if( cell == '.')
                {
                    converted.push_back( ECell::Floor );
                }
                if( cell == 'W')
                {
                    converted.push_back( ECell::Wall );
                }
                if( cell == 'S' )
                {
                    converted.push_back( ECell::Floor );
                    startPos = ToOneDimension( j, i );
                }
                if( cell == 'E' )
                {
                    converted.push_back( ECell::Floor );
                    endPos = ToOneDimension( j, i );
                }
            }
            board.push_back( converted );
        }
        // Convert to graph
        // Set nodes
        for( size_t i = 0; i < h; ++i )
        {
            for( size_t j = 0; j < w; ++j )
            {
                auto& cell = board.at( i ).at( j );
                if( cell == ECell::Floor )
                {
                    g.AddNode( ToOneDimension( j, i) );
                }
            }
        }
        // Set links
        // Horisontal travestal
        for( size_t i = 0; i < h; ++i )
        {
            for( size_t j = 0; j < w - 1; ++j )
            {
                auto& cell = board.at( i ).at( j );
                auto& nextCell = board.at( i ).at( j + 1 );
                if( cell == ECell::Floor && nextCell == ECell::Floor )
                {
                    int start = ToOneDimension( j, i );
                    int end = ToOneDimension( j + 1, i );
                    g.AddLink( start, end, 1);
                }
            }
        }
        // Vertical travestal
        for( size_t i = 0; i < h - 1; ++i )
        {
            for( size_t j = 0; j < w; ++j )
            {
                auto& cell = board.at( i ).at( j );
                auto& nextCell = board.at( i + 1 ).at( j );
                if( cell == ECell::Floor && nextCell == ECell::Floor )
                {
                    int start = ToOneDimension( j, i );
                    int end = ToOneDimension( j, i + 1 );
                    g.AddLink( start, end, 1);
                }
            }
        }
    }

    vector<vec> GetPath()
    {
        vector<vec> minimalPath;
        auto path = g.Path( startPos, endPos );
        for( const auto& item: path )
        {
            auto pos = ToTwoDimensionals( item );
            minimalPath.push_back( pos );
        }
        return minimalPath;
    }

    int ToOneDimension( int x, int y )
    {
        return y * w + x;
    }

    vec ToTwoDimensionals( int pos )
    {
        int column = pos % w;
        int row = ( pos - column ) / h;
        return vec( row, column );
    }
private:
    vector<vector<ECell>> board;
    size_t w;
    size_t h;
    int startPos;
    int endPos;
    Graph<int> g;
};


int main()
{
    vector<string> table = {
        "S...W",
        "...W.",
        ".....",
        ".....",
        "....E"
    };
    AStar a;
    a.SetBoard( table );
    a.GetPath();

    return 0;
}

#endif // ASTAR_H
