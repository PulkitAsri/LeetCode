class ATM {
    vector<long long> currencyNotes;
    vector<long long> value={20,50,100,200,500};
    long long total;
    
public:
    ATM() {
        currencyNotes=vector<long long>(5,0);
        total=0;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0; i<5; i++){
            currencyNotes[i]+=banknotesCount[i];
            total+=value[i]*banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        
        int amt=amount;
        vector<int> notesWithdrawn(5,0);
        vector<int> err(1,-1);
        
        for(int i=4; i>=0; i--){
            if(amt>=value[i] ){
                long long possibleNotes= amt/value[i];
                int notes= min(possibleNotes, currencyNotes[i]);
                notesWithdrawn[i]= notes;
                amt-=  notes*value[i];
            }
        }
        
        if(amt==0){
            for(int i=0; i<5; i++){
                currencyNotes[i]-=notesWithdrawn[i];
            }
            return notesWithdrawn;
        }else return err;
        
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */