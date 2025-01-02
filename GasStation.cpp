class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0, currentTank = 0, start = 0, size = gas.size();
        for (int i = 0; i < size; ++i) {
            int netGain = gas[i] - cost[i];
            totalTank += netGain; 
            currentTank += netGain; 
            if (currentTank < 0) {
                currentTank = 0;
                start = i + 1;
            }
        }
        return (totalTank >= 0) ? start : -1;
    }
};
