class Solution {
    
    void moveIn(int d,vector<int> &cood){
        switch(d){
            //north 
            case 0: cood[1]++;
                break;
            //south
            case 2: cood[1]--;
                break;
            //east 
            case 1: cood[0]++;
                break;
            //west
            case 3: cood[0]--;
                break;
                
        }
    }
    
public:
    bool isRobotBounded(string instructions) {
        int n=instructions.length();
        vector<int> cood(2,0);
        int dir = 0;
        for(int cycle=0;cycle<4;cycle++){
            for(int i=0;i<n;i++){
                switch(instructions[i]){
                    case 'G':
                        moveIn(dir, cood);
                        break;
                    case 'L':
                        dir= (dir+1 +4)%4;
                        break;
                    case 'R':
                        dir= (dir-1 +4)%4;
                        break;
                }
            }
        }
        
        // cout<<cood[0]<<cood[1]<<endl;
        return (cood[0]==0 && cood[1]==0);
    }
};