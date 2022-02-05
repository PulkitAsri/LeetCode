class Solution {
    
    string makeString(int mins, int secs){
        string secStr=(secs<10)
                        ? "0" + to_string(secs)
                        : to_string(secs);      
        return to_string(mins) + secStr ;      
    }
    
    
    int calcCost(string s, int startAt, int moveCost, int pushCost){
        int cost=0;
        if(s.length()>4) return INT_MAX;
        // cout<<startAt<<endl;
        for(int i=0; i<s.length(); i++){
            
            if(startAt!= s[i]-'0'){ 
                cost+=moveCost;
                startAt=s[i]-'0';
                // cout<<"move "<<startAt;
            }
            cost+=pushCost; 
            // cout<<endl;

        }
        return cost;
    }
    
    
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {  
        vector<string> possStr;
    
        if(targetSeconds >=10 && targetSeconds<100){ 
            // 2 digit seconds 97----> "97"
            string sr=to_string(targetSeconds);
            possStr.push_back(sr);
            
        }else if(targetSeconds < 10){
            // 1 digit seconds
            string sr=to_string(targetSeconds);  //"2"
            possStr.push_back(sr);
            
            sr="0"+sr;  //"02"
            possStr.push_back(sr); 
        }
        
        //Calc Mins and Secs
        int mins= targetSeconds/60;
        int secs= targetSeconds%60;
        
        string s= makeString(mins,secs);
        possStr.push_back(s);
        
        //Adding trailing zeroes Possibilities
        while(s.length() < 4){
            s= "0" + s;
            possStr.push_back(s);
        }
        
        //If converting 1min into 60 sec works
        if(secs< 40 && mins>=1){
            mins--;
            secs+=60;
            string s= makeString(mins, secs);
            possStr.push_back(s);
            
            //Adding trailing zeroes Possibilities
            while(s.length()<4){
                s="0"+s;
                possStr.push_back(s);
            }
        }
        
        int ans=INT_MAX; 
        for(string str:possStr){
            // cout<<str<<" "<<calcCost(str,startAt,moveCost,pushCost)<<endl;
            ans=min(ans,calcCost(str,startAt,moveCost,pushCost));
        }
        
        return ans;
    }
};