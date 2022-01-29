class StockSpanner {
    stack<pair<int,int>> st;
    int count=1;
public:
    StockSpanner() {
        count=1;
    }
    
    int next(int price) {
        
        int ans=0;
        if(st.size()==0){
            ans=1;
            
        }else if(st.size()>0 && st.top().first <= price){
            while(st.size()>0 && st.top().first <= price){
                st.pop();
            }
            if(st.size()==0) ans= count;
            else ans= count - st.top().second;
            
            
        }else if(st.size()>0 && st.top().first > price){
            ans = 1;
        } 
        pair<int,int> pair;
        pair.first=price; pair.second=count;
        st.push(pair);
        
        count++;
        
        return ans;
        
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */