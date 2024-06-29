#include <cassert>
#include <cstdio>

#define ASSERT_EQ(a, b) !(a == b)
#define ASSERT_EQ_MSG(a, b, msg) if (a != b) {printf("%s", msg); return 1;}

int main() {
    ASSERT_EQ_MSG(5, 6, "Ошибка")
}