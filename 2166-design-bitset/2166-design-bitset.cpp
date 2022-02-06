class Bitset {
    string bitset;
    string flipped;
    int setBits=0;
    int unsetBits=0;
    int length=0;
public:
    Bitset(int size) {
        bitset="";
        flipped="";
        length=size;
        unsetBits=size;

        for(int i=0; i<length; i++){
            bitset+="0";
            flipped+="1";
        }           
    }
    
    void fix(int idx) {
        if(bitset[idx]!='1'){
            setBits++;
            unsetBits--;
        }
        
        bitset[idx]='1';
        flipped[idx]='0';

    }
    
    void unfix(int idx) {
        if(bitset[idx]!='0'){
            unsetBits++;
            setBits--;
            bitset[idx]='0';
            flipped[idx]='1';
        }
        
        // cout<<bitset<<" "<<setBits<<" " <<unsetBits<<endl;

    }
    
    void flip() {
        // for(int i=0; i<length; i++) {
        //     if(bitset[i]=='0') bitset[i]='1';
        //     else bitset[i]='0';
        // }
        
        
        bitset.swap(flipped);
        
        
        int temp=setBits;
        setBits=unsetBits;
        unsetBits=temp;
        
        // cout<<bitset<<endl;

    }
    
    bool all() {
        return setBits==length;
    }
    
    bool one() {
        return (setBits>=1);
    }
    
    int count() {
        return setBits;
    }
    
    string toString() {
        return bitset;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */