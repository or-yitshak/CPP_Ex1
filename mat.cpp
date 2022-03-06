#include <iostream>
#include <string>

using namespace std;

#include "mat.hpp"

namespace ariel
{
    string mat(int cols, int rows, char ch1, char ch2)
    {
        if (cols % 2 == 0 || rows % 2 == 0)
        {
            throw invalid_argument("Mat size is always odd");
        }
        if (cols < 0 || rows < 0)
        {
            throw invalid_argument("Mat size is always positive");
        }
        char table[rows][cols];//maybe need to use vector instead.
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                table[i][j] = ch1;
            }
        }
        int k = 1;
        int start_row = k;
        int end_row = cols - k;
        int start_col = k;
        int end_col = rows - k;
        while (start_row < end_row || start_col < end_col)
        {
            start_row = k;
            end_row = cols - k;
            start_col = k;
            end_col = rows - k;
            for (int i = start_row; i < end_row; i++) // the up row
            {
                table[start_col][i] = ch2;
            }
            for (int i = start_col; i < end_col; i++) // left cloumn
            {
                table[i][start_row] = ch2;
            }
            for (int i = start_row; i < end_row; i++) // bottom row
            {
                table[end_col - 1][i] = ch2;
            }
            for (int i = start_col; i < end_col; i++) // bottom row
            {
                table[i][end_row - 1] = ch2;
            }
            k += 2;
        }
        string ans = "";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                ans += table[i][j];
            }
            ans += '\n';
        }
        return ans;
    }
}
