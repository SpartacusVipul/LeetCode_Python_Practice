class Solution {
public:
    // basic idea is whenever an empty slot is detected, 
    // we check the previous anbd next slots 
    // if both of them are empty then we can plat here, 
    // prev can be empty because its previous may have a plant 
    // one more edge cases are if current is last index, then no next so next is considered empty 
    // if current is first index, then no previous exists so prev is considered empty
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sum = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                int next = i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1];
                int prev = i == 0 ? 0 : flowerbed[i - 1];
                if (next == 0 && prev == 0) {
                    flowerbed[i] = 1;
                    sum ++;
                }  
            }
        }
        return sum >= n;
    }
};