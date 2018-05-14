// https://www.codingame.com/ide/puzzle/skynet-revolution-episode-1

#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <queue>
#include <iostream>

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

const int INF = std::numeric_limits<int>::max();

/*!
 * Class incapsulate graph strcture
 */
template<typename T>
class graph
{
public:
    graph() {}
    ~graph() {}

    void addLink(int start, int end, T cost)
    {
        if (start >= m_nodes.size() || end >= m_nodes.size())
            throw std::logic_error("Link is incorrect");
        m_links.push_back({start, end, cost});
    };

    void addNode(T value)
    {
        m_nodes.push_back({value});
    };

    size_t size() const { return m_nodes.size(); }
    /**
     * @brief Dijkstra algo with O(n^2 + m) complexity
     *
     * @param start Start path position
     * @param end End path position
     *
     * @return path
     */
    std::vector<int> path(int start, int end) const
    {
        size_t nodes = m_nodes.size();
        std::vector<int> parents(nodes);
        std::vector<bool> marks(nodes, false);
        std::vector<int> distances(nodes, INF);
        if (start >= nodes)
            throw std::logic_error("Wrong start path position");
        if (end >= nodes)
            throw std::logic_error("Wrong end path position");
        distances.at(start) = 0; // Set start node
        // Main loop
        int vertex = -1;
        for (int i = 0; i < nodes; ++i)
        {
            // Get node with minimal distance

            for (int j = 0; j < nodes; ++j)
            {
                if (!marks.at(j) && (vertex == -1 || distances.at(j) < distances.at(vertex)))
                    vertex = j;
            }
            if (vertex == INF)
                break;
            // Set vertex as already viewed
            marks.at(vertex) = true;
            // Get all edges from vertex
            std::vector<link<T>> edges;
            for (int j = 0; j < m_links.size(); ++j)
            {
                link<T> edge = m_links.at(j);
                if (edge.b == vertex || edge.e == vertex)
                    edges.push_back(edge);
            }
            // Calculate minimal paths to each vertex in graph
            for (int j = 0; j < edges.size(); ++j)
            {
                int to = (edges.at(j).b == vertex) ? edges.at(j).e : edges.at(j).b;
                T length = edges.at(j).cost;
                if (distances.at(vertex) + length < distances.at(to))
                {
                    distances.at(to) = distances.at(vertex) + length;
                    parents.at(to) = vertex;
                }
            }
        }
        // Build minimal path from start to end
        std::cerr << "Build path. Parents: "  << parents.size() << std::endl;
        std::cerr << "args: "  << start << ", " << end << std::endl;
        std::vector<int> minimalPath;
        if (vertex == end)
        {
            while (vertex != start)
            {
                std::cerr << "node = " << vertex << std::endl;
                minimalPath.push_back(vertex);
                vertex = parents.at(vertex);
            }
            minimalPath.push_back(start);
            std::reverse(minimalPath.begin(), minimalPath.end());
        }


        return minimalPath;
    }

    std::vector<int> bfs(int start, int end) const
    {
        std::vector<int> path;
        size_t nodes = m_nodes.size();
        std::vector<int> parents(nodes, -1);
        std::vector<bool> marks(nodes, false);
        std::queue<int> q;
        q.push(start);
        marks.at(start) = true;
        int n = -1;
        while (!q.empty())
        {
            n = q.front();
            path.push_back(n);
            q.pop();
            if (n == end)
                break;
            auto neighbrs = neighbours(n);
            for (int i = 0; i < neighbrs.size(); ++i)
            {
                if (!marks.at(neighbrs.at(i)))
                {
                    q.push(neighbrs.at(i));
                    parents.at(neighbrs.at(i)) = n;
                    marks.at(neighbrs.at(i)) = true;
                }
            }
        }

        if (n == end)
        {
            while (n != start)
            {
                std::cerr << "node = " << n << std::endl;
                path.push_back(n);
                n = parents.at(n);
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
        }
        return path;
    }

    std::vector<int> neighbours(int vertex) const
    {
        std::vector<int> nodes;
        for (int j = 0; j < m_links.size(); ++j)
        {
            link<T> edge = m_links.at(j);
            if (edge.b == vertex)
                nodes.push_back(edge.e);
            if (edge.e == vertex)
                nodes.push_back(edge.b);
        }
        return nodes;
    }

    void removeLink(int start, int end)
    {
        for (size_t i = 0; i < m_links.size(); i++)
        {
            auto l = m_links.at(i);
            if ((l.b == start && l.e == end) || (l.b == end && l.e == start))
                m_links.erase(m_links.begin() + i);
        }
    }

private:
    std::vector<link<T>> m_links;
    std::vector<node<T>> m_nodes;
};

void drawPath(std::vector<int> path)
{
    std::cerr << "Path: ";
    for (size_t i = 0; i < path.size(); i++)
        std::cerr << path.at(i) << " ";
    std::cerr << std::endl;
}

int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways

    std::cin >> N >> L >> E; std::cin.ignore();

    graph<int> g;

    for (int i = 0; i < N; i++)
        g.addNode(i);


    for (int i = 0; i < L; i++)
    {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        std::cin >> N1 >> N2; std::cin.ignore();
        // Create link
        g.addLink(N1, N2, 1);
    }

    std::vector<int> gateways;
    for (int i = 0; i < E; i++)
    {
        int EI; // the index of a gateway node
        std::cin >> EI; std::cin.ignore();
        gateways.push_back(EI);
        std::cerr << "Gateway: " << EI << std::endl;
    }

    // game loop
    while (1)
    {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        std::cin >> SI; std::cin.ignore();
        std::cerr << "Agent: " << SI << std::endl;
        // For each gateway
        std::vector<int> minPath;
        int minSize = std::numeric_limits<int>::max();
        for (int i = 0; i < E; i++)
        {
            auto path = g.bfs(SI, gateways.at(i));
            drawPath(path);
            if (path.size() != 0 && path.size() < minSize)
            {
                minSize = path.size();
                minPath = path;
            }
        }
        // Write an action using cout. DON'T FORGET THE "<< endl"
        g.removeLink(minPath.at(0), minPath.at(1));
        std::cout << minPath.at(0) << " " << minPath.at(1) << std::endl;
    }
}