#include "unit_test.hpp"

int main() {
    CubeShape cube;
    ASSERT_EQ_F(cube.getVolume(), 1);
    
    CubeShape cube2(10);
    ASSERT_EQ_F(cube2.getVolume(), 1000);
    
    CubeShape cube3(200);
    ASSERT_EQ_F(cube3.getVolume(), 8000000);
}