#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

int feedAnimals(std::vector<int>& animals, std::vector<int>& food)
{
    size_t size_animals = std::size(animals);
    size_t size_food = std::size(food);
    int count = 0;
    int i;
    int j;

    if (size_animals == 0 || size_food == 0)
    {
        return 0;
    }

    std::sort(animals.begin(), animals.end(), std::greater<int>());
    std::sort(food.begin(), food.end(), std::greater<int>());

    for (i = 0; i < size_food; i++)
    {
        while (j < size_animals)
        {
            if (food[i] >= animals[j])
            {
                count++;
                j++;
                break;
            }
            j++;
        }
    }
    return count;
}


TEST(FeedAnimalsTest, BasicFeed)
{
    std::vector<int> animals = {1, 4, 3, 8};
    std::vector<int> food = {8, 2, 3, 2};
    EXPECT_EQ(feedAnimals(animals, food), 3);

    std::vector<int> animals_1 = {2, 2, 2};
    std::vector<int> food_1 = {2, 2, 2};
    EXPECT_EQ(feedAnimals(animals_1, food_1), 3);
}

TEST(FeedAnimalsTest, NotEnoughFood)
{
    std::vector<int> animals = {4, 5, 6};
    std::vector<int> food = {1, 2, 3};
    EXPECT_EQ(feedAnimals(animals, food), 0);
}

TEST(FeedAnimalsTest, PartiallyFed)
{
    std::vector<int> animals = {1, 3, 5};
    std::vector<int> food = {3, 2};
    EXPECT_EQ(feedAnimals(animals, food), 2);

    std::vector<int> animals_1 = {3, 8, 1, 4};
    std::vector<int> food_1 = {1, 1, 2};
    EXPECT_EQ(feedAnimals(animals_1, food_1), 1);

    std::vector<int> animals_2 = {1, 2, 2};
    std::vector<int> food_2 = {7, 1};
    EXPECT_EQ(feedAnimals(animals_2, food_2), 2);
}

TEST(FeedAnimalsTest, NoAnimals)
{
    std::vector<int> animals = {};
    std::vector<int> food = {1, 2, 3};
    EXPECT_EQ(feedAnimals(animals, food), 0);
}

TEST(FeedAnimalsTest, NoFood)
{
    std::vector<int> animals = {1, 2, 3};
    std::vector<int> food = {};
    EXPECT_EQ(feedAnimals(animals, food), 0);
}

TEST(FeedAnimalsTest, ReverseElements)
{
    std::vector<int> animals = {8, 1};
    std::vector<int> food = {1, 8};
    EXPECT_EQ(feedAnimals(animals, food), 2);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}