#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int maxHealth = health;
    int healTime = bandage[0];
    int healPerSecond = bandage[1];
    int extraHeal = bandage[2];
    int prevTime = 0;
    
    for (vector<int> attack: attacks)
    {
        int attackTime = attack[0];
        int damage = attack[1];
        
        health = min(maxHealth, health + (attackTime - prevTime - 1) * healPerSecond);
        if (attackTime - prevTime > healTime)
        {
            health = min(maxHealth, health + (attackTime - prevTime) / healTime * extraHeal);
        }
        health = health - damage;
        if (health <= 0)
            return (-1);
        
        prevTime = attackTime;
    }
    return (health);
}