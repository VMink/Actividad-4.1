#include <iostream>
#include <vector>

struct Point {
    int x, y;
};

// O(1)
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// O(N)
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && o3 == 0) {
        if (p2.x >= std::min(p1.x, q1.x) && p2.x <= std::max(p1.x, q1.x) &&
            p2.y >= std::min(p1.y, q1.y) && p2.y <= std::max(p1.y, q1.y))
            return true;
    }

    if (o2 == 0 && o4 == 0) {
        if (q2.x >= std::min(p1.x, q1.x) && q2.x <= std::max(p1.x, q1.x) &&
            q2.y >= std::min(p1.y, q1.y) && q2.y <= std::max(p1.y, q1.y))
            return true;
    }

    return false;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<bool> results;

    // O(N)
    for (int i = 0; i < n; i++) {
        Point p1, q1, p2, q2;
        char comma;

        std::cin >> p1.x >> comma >> p1.y >> q1.x >> comma >> q1.y >> p2.x >> comma >> p2.y >> q2.x >> comma >> q2.y;

        bool intersect = doIntersect(p1, q1, p2, q2);
        results.push_back(intersect);
    }

    // O(N)
    for (bool result : results) {
        if (result) {
            std::cout << "True" << std::endl;
        } else {
            std::cout << "False" << std::endl;
        }
    }

    return 0;
}