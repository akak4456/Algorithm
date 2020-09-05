vector<int> parent;
   vector<int> rank;
   int getParent(int x){
      if (parent[x] == -1)
      return x;
      return parent[x] = getParent(parent[x]);
   }
   void unionn(int x, int y){
      int parX = getParent(x);
      int parY = getParent(y);
      if (parX == parY)
      return;
      if (rank[parX] >= rank[parY]) {
         rank[parX] += rank[parY];
         parent[parY] = parX;
      } else {
         rank[parY] += rank[parX];
         parent[parX] = parY;
      }
   }
   int largestComponentSize(vector<int>& A) {
      int ret = 0;
      int n = A.size();
      parent = vector<int>(n, -1);
      rank = vector<int>(n, 1);
      unordered_map<int, int> m;
      for (int i = 0; i < n; i++) {
         int x = A[i];
         for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
               if (m.count(j)) {
                  unionn(m[j], i);
               } else {
                  m[j] = i;
               }
               if (m.count(x / j)) {
                  unionn(m[x / j], i);
               } else {
                  m[x / j] = i;
               }
            }
         }
         if (m.count(x)) {
            unionn(m[x], i);
         } else {
            m[x] = i;
         }
         ret = max(ret, rank[getParent(i)]);
      }
      return ret;
   }