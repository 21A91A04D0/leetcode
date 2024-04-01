class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = 0;
        int bottlesDrunk = 0;
        while(numBottles != 0 or emptyBottles - numExchange >= 0) {
            if(emptyBottles - numExchange >= 0) {
                numBottles++;
                
                emptyBottles = emptyBottles - numExchange;
                numExchange++;
            }
            else if(numBottles > 0) {
                bottlesDrunk += numBottles;
                emptyBottles += numBottles;
                numBottles = 0;
            }
        }
        return bottlesDrunk;
    }
};