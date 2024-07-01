#include "../unit_test.hpp"

int main() {
    Face face({
        {0,0,0},
        {1,0,0},
        {0,0,1}
    });
    ASSERT_EQ_F(face.getPerimetr(), 3.41421);

    Face face2({
        {0,0,0},
        {1,0,0},
        {1,1,0},
        {0,1,0}
    });
    ASSERT_EQ_F(face2.getPerimetr(), 4.0);
}