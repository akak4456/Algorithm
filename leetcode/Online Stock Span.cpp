class StockSpanner {
public:
    stack<pair<int,int> >st;
    int day = 1;
    StockSpanner() {
        st.push(make_pair(1000000,0));
    }
    
    int next(int price) {
        int lastDay = 0;
        while(!st.empty()){
            int lastPrice = st.top().first;
            lastDay = st.top().second;
            if(lastPrice > price){
                st.push(make_pair(price,day));
                day++;
                return day-lastDay-1;
            }
            st.pop();
        }
        return 0;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */