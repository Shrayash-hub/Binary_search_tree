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
            int heaviest = p.top(); // first heaviest
            p.pop();
            heaviest= heaviest-p.top(); // subtract second heaviest from first 
            p.pop();
            p.push(heaviest); // push remains back to the heap
        }
        return p.top(); // return the last left stone
    }
};