#include <iostream>
#include "boost/assign.hpp"
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/linestring.hpp>
#include <boost/geometry/geometries/point_xy.hpp>

using namespace boost::assign;
int main()
{
    // Calculate the intersects of a cartesian polygon
    typedef boost::geometry::model::d2::point_xy<double> P;
    boost::geometry::model::linestring<P> line1, line2;

    // boost::geometry::read_wkt("linestring(2 2,7 21)", line1);
    boost::geometry::read_wkt("linestring(0 2,8 19)", line2);
    line1 += P(2,2);
    line1.emplace_back(7,21);
    bool b = boost::geometry::intersects(line1, line2);

    std::cout << "Intersects: " << (b ? "YES" : "NO") << std::endl;
    std::vector<P> output;
    boost::geometry::intersection(line1, line2, output);
    for (auto&& p : output) {
        std::cout << boost::geometry::wkt(p) << std::endl;
    
    }
    return 0;
}
