#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int get_pow_distance(int x, int y, int targetX, int targetY)
{
    return (pow(x - targetX, 2) + pow(y - targetY, 2));
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (vector<int> ball: balls)
    {
        int minDistance = 987654321;
        int targetX = ball[0];
        int targetY = ball[1];
        
        int mirrorTopY = n + (n - startY);
        int topSideDistance = get_pow_distance(startX, mirrorTopY, targetX, targetY);
        
        int mirrorLeftX = -startX;
        int leftSideDistance = get_pow_distance(mirrorLeftX, startY, targetX, targetY);
        
        int mirrorBottomY = -startY;
        int bottomSideDistance = get_pow_distance(startX, mirrorBottomY, targetX, targetY);
        
        int mirrorRightX = m + (m - startX);
        int rightSideDistance = get_pow_distance(mirrorRightX, startY, targetX, targetY);
        
        if (!(startX == targetX && startY < targetY))
            minDistance = min(minDistance, topSideDistance); 
        if (!(startX == targetX && startY > targetY))
            minDistance = min(minDistance, bottomSideDistance); 
        if (!(startY == targetY && startX > targetX))
            minDistance = min(minDistance, leftSideDistance); 
        if (!(startY == targetY && startX < targetX))
            minDistance = min(minDistance, rightSideDistance); 
        answer.push_back(minDistance);
    }
    return answer;
}
