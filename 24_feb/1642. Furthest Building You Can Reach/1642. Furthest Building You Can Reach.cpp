class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq; 
        int l = heights[0], h, i;
        
        for (i=1;i<heights.size() && bricks >= 0;i++){
            h = heights[i] - l;
            if (h > 0){
                pq.push(h);
                bricks -= h;
                
                if (bricks<0){
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }
            }
            if (ladders < 0)
                    break;
            l = heights[i];
        }
        return i-1;
    }
};
