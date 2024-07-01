#include <geomath/CubeShape.hpp>
#include <geomath/ParallelepipedShape.hpp>
#include <geomath/PrismShape.hpp>
#include <geomath/PyramidShape.hpp>
#include <geomath/types/Face.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>

#define ASSERT_EQ(a, b) if (a != b) return 1;
#define ASSERT_EQ_F(a, b) if ((std::fabs(a - b) > 0.00001)) return 1;
//#define ASSERT_EQ_MSG(a, b, msg) if (a != b) {printf("%s", msg); return 1;}