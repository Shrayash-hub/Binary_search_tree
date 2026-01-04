class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // we are going to use priority_queue(max heap) to pick two heaviest two stones
        priority_queue<int> p;

        // inserting elements into the queue
        for(int i=0;i<stones.size();i++){
            p.push(stones[i]);
        }

        while(p.size()>1){
            int heaviest = p.top();
            p.pop();
            heaviest= heaviest-p.top();
            p.pop();
            p.push(heaviest);
        }
        return p.top();
    }
};