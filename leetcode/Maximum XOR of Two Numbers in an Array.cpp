struct Node{
   Node* child[2];
   Node(){
      child[1] = child[0] = NULL;
   }
};
class Solution {
public:
    void insertNode(int val, Node* head){
      Node* curr = head;
      for(int i = 31; i>= 0; i--){
         int bit = (val >> i) & 1;
         if(!curr->child[bit]){
            curr->child[bit] = new Node();
         }
         curr = curr->child[bit];
      }
   }
   int find(int val, Node* head){
      Node* curr = head;
      int ans = 0;
      for(int i = 31; i>= 0; i--){
         int bit = (val >> i) & 1;
         if(curr->child[!bit]){
            ans |= (1 << i);
            curr = curr->child[!bit];
         } else {
            curr = curr->child[bit];
         }
      }
      return ans;
   }
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
      int n = nums.size();
      Node* head = new Node();
      for(int i = 0; i < n; i++){
         insertNode(nums[i], head);
      }
      for(int i = 0; i < n; i++){
         ans = max(ans, find(nums[i], head));
      }
      return ans;
    }
};