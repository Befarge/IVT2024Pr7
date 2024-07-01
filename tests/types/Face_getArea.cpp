#include "../unit_test.hpp"

int main() {
    //TODO: Add body
    Face face({
        {0,0,0},
        {1,0,0},
        {0,0,1}
    });
    ASSERT_EQ_F(face.getArea(), 0.5);

    Face face2({
        {0,0,0},
        {1,0,0},
        {1,1,0},
        {0,1,0}
    });
    ASSERT_EQ_F(face2.getArea(), 1.0);
}