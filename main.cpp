#include <iostream>
#include <gtest/gtest.h>

TEST(Dummy, scenario) {
    ASSERT_TRUE(1 == 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
