class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>maxBefor(prices.size(),0),maxAfter(prices.size(),0);
        stack<int>st;
        maxBefor[0]=0;
        maxAfter[prices.size()-1]=0;
        st.push(0);
        for(int i=1;i<prices.size();i++){
            while(!st.empty() && prices[st.top()]>=prices[i])st.pop();
            int prev=prices[i];
            if(!st.empty()){
                prev=prices[st.top()];
            }
            maxBefor[i]=max(maxBefor[i-1],prices[i]-prev);
            if(st.empty())st.push(i);


        }

        while(!st.empty())st.pop();

        st.push(prices.size()-1);
        for(int i=prices.size()-2;i>=0;i--){
            while(!st.empty() && prices[st.top()]<=prices[i])st.pop();
            int prev=prices[i];
            if(!st.empty()){
                prev=prices[st.top()];
            }
            maxAfter[i]=max(maxAfter[i],prev-prices[i]);
            if(st.empty())st.push(i);
        }
        int res = 0;
        for(int i=0;i<prices.size();i++){
            int next_max = 0;
            if(i<prices.size()-1)next_max = maxAfter[i];
            res = max(maxBefor[i]+next_max,res);
        }
        return res;

        
    }
};