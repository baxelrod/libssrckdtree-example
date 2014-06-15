#include <ssrc/spatial/kd_tree.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <sstream>

template<typename T>
struct TruePred {
    bool operator()(const T &) { return true; }
};

typedef std::array<unsigned int, 2> Point;
typedef ssrc::spatial::kd_tree<Point, std::string> Tree;
typedef TruePred<Tree::value_type> True;

inline std::ostream & operator<<(std::ostream & out, const Point & point) {
    return out << "[ " << point[0] << ", " << point[1] << " ]";
}

int main(int argc, char *argv[]) {
    Tree tree;

    std::stringstream s;
    for(unsigned int i = 0; i < 100; ++i) {
        //Point point{ { std::rand() % 100, std::rand() % 100 } };
        Point point{ i, i };
        s << "x: " << point[0] << " y: " << point[1] << std::endl;
        tree[point] = s.str();
    }

     assert((tree.size() ==
                 std::count_if<Tree::iterator, True>(tree.begin(), tree.end(),
                     True())));

    Point center{ { 25, 25 } };

    std::pair<Tree::knn_iterator, Tree::knn_iterator> range = tree.find_nearest_neighbors(center, 4);
    
    for (Tree::knn_iterator it = range.first; it != range.second; ++it)
    {
        std::pair<Point, std::string> p = *it;
        std::cout <<  p.first<< std::endl;
    }
    return 0;
}

