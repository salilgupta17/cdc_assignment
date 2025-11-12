#include <bits/stdc++.h>
using namespace std;

void dfsFill(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
    int m = image.size(), n = image[0].size();
    if (r < 0 || c < 0 || r >= m || c >= n || image[r][c] != oldColor) return;

    image[r][c] = newColor;

    // explore 4 directions
    dfsFill(image, r + 1, c, oldColor, newColor);
    dfsFill(image, r - 1, c, oldColor, newColor);
    dfsFill(image, r, c + 1, oldColor, newColor);
    dfsFill(image, r, c - 1, oldColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor != newColor)
        dfsFill(image, sr, sc, oldColor, newColor);
    return image;
}

/*
Logic:
- Start from source (sr, sc) pixel.
- Replace contiguous same-color pixels using DFS/BFS.
- Stop when different color or boundary is reached.
Time Complexity: O(m × n)

Flood fill updates all connected pixels of the same color starting from a source pixel.
*/