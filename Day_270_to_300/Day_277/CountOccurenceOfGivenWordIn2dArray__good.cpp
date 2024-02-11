#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

namespace temp {
    using namespace std;
    
    //Function to find the target string path starting from a particular element.
    int findPath(vector<vector<char> > mat, string target, int startX, int startY, int targetIndex){
        
        //if the current element is out of bounds, return 0.
        if(startX < 0 || startY < 0 || startX >= mat.size() || startY >= mat[startX].size()){
            return 0;
        }
        
        //storing the original value of the current element.
        char original = mat[startX][startY];
        
        //if the original value of the current element is not equal to the target character,
        //return 0.
        if(original != target[targetIndex])
            return 0;
        
        //if we reach the last character of the target string, return 1 as path found.
        if(targetIndex == target.size() - 1)
            return 1;

        int count = 0;
        //changing the value of the current element to '\0' to mark it as visited
        //and avoid returning back to this element.
        mat[startX][startY] = '\0';

        //recursively calling findPath function for all possible neighboring elements.
        count += findPath(mat, target, startX+1, startY, targetIndex+1);
        count += findPath(mat, target, startX, startY+1, targetIndex+1);
        count += findPath(mat, target, startX-1, startY, targetIndex+1);
        count += findPath(mat, target, startX, startY-1, targetIndex+1);
        
        //restoring the original value of the current element.
        mat[startX][startY] = original;
        //returning the count of paths found.
        return count;
    }

    int findOccurrence(vector<vector<char> > &mat, string target){
        int count = 0;
        //iterating over the matrix elements.
        for(int i = 0; i < mat.size() ; i++){
            for(int j = 0; j < mat[i].size(); j++){
                //calling the findPath function to find if target string is present
                //starting from the current element.
                count += findPath(mat, target, i, j, 0);
            }
        }
        //returning the total count of occurrences of the target string.
        return count;
    }
};

using namespace temp;

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector(m, 'A'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];

    std::string s;
    std::cin >> s;

    std::cout << findOccurrence(a, s);
    
    return 0; 
}    