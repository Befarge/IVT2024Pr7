#include "unit_test.hpp"

int main() {
    CubeShape cube;
    ASSERT_EQ_F(cube.getSurfaceArea(), 6)
    
    CubeShape cube2(10);
    ASSERT_EQ_F(cube2.getSurfaceArea(), 600)
    
    CubeShape cube3(100);
    ASSERT_EQ_F(cube3.getSurfaceArea(), 60000)
}