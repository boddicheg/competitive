#ifndef TEADS_H
#define TEADS_H

#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <queue>

using namespace std;


namespace math {

template<typename T>
struct node {
  T value;
};

template<typename T>
struct link {
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

  void addLink(int start, int end, T cost) {
    if (start >= m_nodes.size() || end >= m_nodes.size()) {
      throw std::logic_error("Link is incorrect");
    }
    m_links.push_back({start, end, cost});
  };

  void addNode(T value) {
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
  std::vector<int> path(int start, int end) const {
    size_t nodes = m_nodes.size();
    std::vector<int> parents(nodes);
    std::vector<bool> marks(nodes, false);
    std::vector<int> distances(nodes, INF);
    if (start >= nodes) {
      throw std::logic_error("Wrong start path position");
    }
    if (end >= nodes) {
      throw std::logic_error("Wrong end path position");
    }
    distances.at(start) = 0; // Set start node
    // Main loop
    for (int i = 0; i < nodes; ++i) {
      // Get node with minimal distance
      int vertex = -1;
      for (int j = 0; j < nodes; ++j) {
        if (!marks.at(j) && (vertex == -1 || distances.at(j) < distances.at(vertex))) {
          vertex = j;
        }
      }
      if (vertex == INF) {
        break;
      }
      // Set vertex as already viewed
      marks.at(vertex) = true;
      // Get all edges from vertex
      std::vector<link<T>> edges;
      for (int j = 0; j < m_links.size(); ++j) {
        link<T> edge = m_links.at(j);
        if (edge.b == vertex || edge.e == vertex) {
          edges.push_back(edge);
        }
      }
      // Calculate minimal paths to each vertex in graph
      for (int j = 0; j < edges.size(); ++j) {
        int to = (edges.at(j).b == vertex) ? edges.at(j).e : edges.at(j).b;
        T length = edges.at(j).cost;
        if (distances.at(vertex) + length < distances.at(to)) {
          distances.at(to) = distances.at(vertex) + length;
          parents.at(to) = vertex;
        }
      }
    }
    // Build minimal path from start to end
    std::vector<int> minimalPath;
    for (int i = end; i != start; i=parents[i]) {
      minimalPath.push_back(i);
    }
    minimalPath.push_back(start);
    std::reverse(minimalPath.begin(), minimalPath.end());
    return minimalPath;
  }

  std::vector<int> bfs(int start, int end) const {
    std::vector<int> path;
    size_t nodes = m_nodes.size();
    std::vector<bool> marks(nodes, false);
    std::queue<int> q;
    q.push(start);
    marks.at(start) = true;
    while(!q.empty()) {
      auto n = q.front();
      path.push_back(n);
      q.pop();
      if (n == end) {
        return path;
      }
      auto neighbrs = neighbours(n);
      for (int i = 0; i < neighbrs.size(); ++i) {
        if (!marks.at(neighbrs.at(i))) {
          q.push(neighbrs.at(i));
          marks.at(neighbrs.at(i)) = true;
        }
      }
    }
    return path;
  }

  std::vector<int> neighbours(int vertex) const {
      std::vector<int> nodes;
      for (int j = 0; j < m_links.size(); ++j) {
        link<T> edge = m_links.at(j);
        if (edge.b == vertex) {
          nodes.push_back(edge.e);
        }
        if (edge.e == vertex) {
          nodes.push_back(edge.b);
        }
      }
      return nodes;
  }

  void removeLink(int start, int end) {
      for(size_t i = 0; i < m_links.size(); i++) {
        auto l = m_links.at(i);
        if ((l.b == start && l.e == end) || (l.b == end && l.e == start)) {
            m_links.erase(m_links.begin() + i);
        }
      }
  }

private:
  std::vector<link<T>> m_links;
  std::vector<node<T>> m_nodes;
};
} // namespace math

class Game
{
public:
    void AddLink( ) {}
private:
    math::graph<int> g;
};
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n; // the number of adjacency relations
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int xi; // the ID of a person which is adjacent to yi
        int yi; // the ID of a person which is adjacent to xi
        cin >> xi >> yi; cin.ignore();
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "1" << endl; // The minimal amount of steps required to completely propagate the advertisement
}

#endif // TEADS_H
