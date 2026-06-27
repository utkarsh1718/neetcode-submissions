class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int boats = 0;
        
        while (i <= j) {
            // If the lightest and heaviest can share, move the left pointer
            if (people[i] + people[j] <= limit) {
                i++;
            }
            // Heaviest always leaves, and a boat is always counted
            j--;
            boats++;
        }
        
        return boats;
    }
};