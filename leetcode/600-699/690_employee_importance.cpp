#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

class Employee
{
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int _getImportance(Employee *employees[2000], int id)
    {
        int importance = employees[id]->importance;
        for (int i = 0; i < employees[id]->subordinates.size(); ++i)
        {
            int idx = employees[id]->subordinates.at(i);
            importance += _getImportance(employees, idx);
        }
        return importance;
    }

    int getImportance(vector<Employee *> employees, int id)
    {
        //indexing
        Employee *db[2000] = { nullptr };
        for (int i = 0; i < employees.size(); ++i)
        {
            Employee *e = employees.at(i);
            db[e->id] = e;
        }
        return _getImportance(db, id);
    }
};

int main(int argc, char const *argv[])
{
    vector<Employee *> data;

    Employee *e1 = new Employee();
    e1->id = 1;
    e1->importance = 5;
    e1->subordinates.push_back(2);

    Employee *e2 = new Employee();
    e2->id = 2;
    e2->importance = 4;
    // e1->subordinates.push_back(3);

    Employee *e3 = new Employee();
    e3->id = 3;
    e3->importance = 3;

    data.push_back(e1);
    data.push_back(e2);
    data.push_back(e3);

    Solution s;
    std::cout << s.getImportance(data, 3) << std::endl;

    delete e1;
    delete e2;
    delete e3;

    return 0;
}
