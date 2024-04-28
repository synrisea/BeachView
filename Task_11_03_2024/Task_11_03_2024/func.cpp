#include "func.h"

std::vector<int> getIndeces(const std::vector<int>& heights)
{
    std::vector<int> indices;
    std::vector<int> result;
    
    int size = heights.size();

    int max_height = heights.back();
    
    if (!heights.empty())
    {
        indices.push_back(size - 1);
    }

    for (int i = size - 2; i >= 0; --i)
    {
        if (heights[i] > max_height)
        {
            indices.push_back(i);
            max_height = heights[i];
        }
    }
    
    int indicesSize = indices.size();
    for (int i = 0; i < indices.size() / 2; i++)
    {
        int temp = indices[i];
        indices[i] = indices[indicesSize - 1 - i];
        indices[indicesSize - 1 - i] = temp;
    }

    return indices;
}