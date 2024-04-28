# Beach Houses with Ocean View
### Problem Statement
Suppose there is a beach with a row of houses of varying heights, located one behind the other. Given a list of the heights of these houses, you need to determine which houses have an ocean view and which do not. A house has an ocean view if its height is greater than all subsequent houses.

### Solution Outline
To solve this problem, we traverse the list of house heights from the end to the beginning, tracking the maximum height encountered. A house has an ocean view if it is taller than the maximum height seen so far. We gather the indices of these houses and return them in ascending order.

### Code Explanation
The function `getIndeces` takes in a vector of integers representing the heights of houses and returns a vector of indices indicating which houses have an ocean view.

- **Initialization**:
  - The `indices` vector stores the indices of houses with ocean views.
  - The `result` vector is initially empty and not used in this code.
  - The `size` variable holds the length of the input `heights`.
  - The `max_height` variable is set to the height of the last house, assuming it has an ocean view.

- **First check**:
  - If `heights` is not empty, the index of the last house (`size - 1`) is added to `indices`.

- **Main loop**:
  - We traverse the `heights` vector from right to left.
  - If a house is taller than the `max_height`, we add its index to `indices` and update `max_height` with the new taller height.

- **Reverse `indices`**:
  - Since we traversed from the end, we reverse `indices` to return the indices in ascending order.

### Testing
To ensure that the `getIndeces` function works correctly, here are some Google Test (gtest) test cases:

```cpp
#include <gtest/gtest.h>
#include "func.h"

using namespace std;

TEST(HouseTest, Test1) {
    vector<int> expectedResult = { 0, 2 };
    vector<int> heights = { 2, 1, 1 };
    ASSERT_EQ(expectedResult, getIndeces(heights));
}

TEST(HouseTest, Test2) {
    vector<int> expectedResult = { 2 };
    vector<int> heights = { 1, 1, 1 };
    ASSERT_EQ(expectedResult, getIndeces(heights));
}

TEST(HouseTest, Test3) {
    vector<int> expectedResult = { 1, 2 };
    vector<int> heights = { 1, 2, 1 };
    ASSERT_EQ(expectedResult, getIndeces(heights));
}

TEST(HouseTest, Test4) {
    vector<int> expectedResult = { 0, 1, 2 };
    vector<int> heights = { 3, 2, 1 };
    ASSERT_EQ(expectedResult, getIndeces(heights));
}

TEST(HouseTest, Test5) {
    vector<int> expectedResult = { 2 };
    vector<int> heights = { 1, 2, 3 };
    ASSERT_EQ(expectedResult, getIndeces(heights));
}

TEST(HouseTest, Test6) {
    vector<int> expectedResult = {};
    vector<int> heights = { 0 };
    ASSERT_EQ(expectedResult, getIndeces(heights));
}
```

### Test Explanation
Here's an explanation of each test case, including the input and expected results:

- **Test 1: Houses with Decreasing Heights**
  - **Description**: This test checks a scenario where the house heights decrease from left to right, with one outlier.
  - **Input**: `heights = [2, 1, 1]`
  - **Expected Result**: The indices of the houses with ocean views should be `[0, 2]`. The first house (index 0) is taller than the others, and the last house (index 2) has an ocean view because it's at the end of the row.

- **Test 2: Houses with Identical Heights**
  - **Description**: This test checks a scenario where all houses have the same height.
  - **Input**: `heights = [1, 1, 1]`
  - **Expected Result**: The only house with an ocean view is the last one (index 2), because it's at the end of the row.

- **Test 3: Increasing and Decreasing Heights**
  - **Description**: This test checks a scenario where the house heights increase and then decrease.
  - **Input**: `heights = [1, 2, 1]`
  - **Expected Result**: The indices of the houses with ocean views should be `[1, 2]`. The second house (index 1) is taller than the first, and the last house (index 2) has an ocean view because it's at the end of the row.

- **Test 4: Strictly Decreasing Heights**
  - **Description**: This test checks a scenario where the house heights strictly decrease from left to right.
  - **Input**: `heights = [3, 2, 1]`
  - **Expected Result**: The indices of the houses with ocean views should be `[0, 1, 2]`. Each house is taller than the ones that follow.

- **Test 5: Strictly Increasing Heights**
  - **Description**: This test checks a scenario where the house heights strictly increase from left to right.
  - **Input**: `heights = [1, 2, 3]`
  - **Expected Result**: The only house with an ocean view is the last one (index 2), as it's the tallest and at the end of the row.

- **Test 6: Empty List**
  - **Description**: This test checks a scenario where the list of house heights is empty.
  - **Input**: `heights = []`
  - **Expected Result**: Since there are no houses, the expected result is an empty list of indices.

