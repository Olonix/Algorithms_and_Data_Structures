#include <string>

bool canMakeValidWithDeletions(const std::string& s, int k) {
    int balance = 0;
    int extra_closed_balance = 0;
    for (int i = 0; i < static_cast<int>(s.length()); i++) {
        if (s[i] == '(') {
            balance += 1;
        } else {
            if (balance > 0) {
                balance -= 1;
            } else {
                extra_closed_balance += 1;
            }
        }
    }
    int total_needed = balance + extra_closed_balance;
    return total_needed <= k;
}


#include <gtest/gtest.h>

TEST(CanMakeValidWithDeletionsTest, AlreadyValid) {
    std::string s = "()()";
    int k = 0;
    EXPECT_TRUE(canMakeValidWithDeletions(s, k));
}

TEST(CanMakeValidWithDeletionsTest, NeedsOneDeletion) {
    std::string s = "(()))";
    int k = 1;
    EXPECT_TRUE(canMakeValidWithDeletions(s, k));
}

TEST(CanMakeValidWithDeletionsTest, NeedsTooManyDeletions) {
    std::string s = "(((((";
    int k = 3;
    EXPECT_FALSE(canMakeValidWithDeletions(s, k));
}

TEST(CanMakeValidWithDeletionsTest, EmptyString) {
    std::string s = "";
    int k = 0;
    EXPECT_TRUE(canMakeValidWithDeletions(s, k));
}

TEST(CanMakeValidWithDeletionsTest, AllWrongButEnoughK) {
    std::string s = ")))(((";
    int k = 6;
    EXPECT_TRUE(canMakeValidWithDeletions(s, k));
}

TEST(CanMakeValidWithDeletionsTest, NotEnoughK) {
    std::string s = "(()((())())()))))";
    int k = 1;
    EXPECT_FALSE(canMakeValidWithDeletions(s, k));
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}