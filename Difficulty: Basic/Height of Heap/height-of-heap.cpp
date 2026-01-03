class Solution {
  public:
    int heapHeight(int n, int arr[]) {
        // code here
        if(n==1) return 1;
        int height = 0;
        while(n>1){
            n = n/2;
            height++;
        }
        return height;
    }
};