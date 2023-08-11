static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

template<typename T>
struct p { T x; T y;};
typedef p<int> pdd;

const double pi = std::acos(-1);

inline int dot(const pdd& p1, const pdd& p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}

inline pdd vec(const pdd& p1, const pdd& p2)
{
    return {p2.x - p1.x, p2.y - p1.y};
}

inline double rad2deg(double rad)
{
    return rad * 180.0 / pi;
}

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points)
    {
        pdd prev = {points.at(0).at(0), points.at(0).at(1)};
        pdd curr = {points.at(1).at(0), points.at(1).at(1)};
        pdd next = {points.at(2).at(0), points.at(2).at(1)};

        pdd v1 = vec(curr, prev);
        pdd v2 = vec(curr, next);

        std::cout << v2.x << " " << v2.y << std::endl;

        double angle_rad = std::atan2( v1.x * v2.y - v1.y * v2.x,
                                v1.x * v2.x + v1.y * v2.y);

        if (angle_rad < 0.0)
            angle_rad +=  2.0 * pi;

        double angle = rad2deg(angle_rad);

        return angle != 180.0 && angle != 0.0;
        
    }
};