class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        set<pair<int, int >> st;
        map<int,int> mp;
        int n=nums.size();
        int c=0;
        for(int i=0; i<n; i++){
            mp[nums[i]]=i;
            cout<<nums[i]<<"=>"<<i<<endl;
        }
        
        
        for(int i=0; i<n; i++){
            auto p=make_pair(k+nums[i],nums[i]);
            auto p1=make_pair(nums[i], k+nums[i]);
            auto q=make_pair(nums[i]-k,nums[i]);
            auto q1=make_pair(nums[i],nums[i]-k);

            
            if(mp.count(k+nums[i])!=0 && mp[k+nums[i]] > i && st.count(p)==0 && st.count(p1)==0){
                c++;
                st.insert(p);
                st.insert(p1);
                            // cout<<nums[i]<<" "<<k+ nums[i]<<" "<<mp[k+nums[i]]<<"=>"<<c<<endl;

            }
            if(mp.count(nums[i]-k)!=0 && mp[nums[i]-k] >i &&  st.count(q)==0 && st.count(q1)==0){
                c++;
                st.insert(q);
                st.insert(q1);
                            // cout<<nums[i]<<" "<<nums[i]-k<<" "<<mp[nums[i]-k]<<"=>"<<c<<endl;

            }
            

        }
        
        
        return c;
    }
};