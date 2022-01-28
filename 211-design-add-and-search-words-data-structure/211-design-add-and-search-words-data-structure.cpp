struct Node{
    Node* ref[26];
    bool flag=false;
    
    bool containsKey(char c){
        return ref[c-'a']!=NULL;
    }
    void put(char c, Node* node){
        ref[c-'a'] =node;
    }
    Node* get(char c){
        return ref[c-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
    
};

class WordDictionary {
    private: Node* root;
    
    
    
    
    bool processNode(string &word, Node* ptr, int &n, int idx){
        
        bool isItPos=false;
        
        if(idx==n){
            return ptr->isEnd();    
        }
        
        char curr=word[idx];
        
        if(curr=='.'){
            for(int i=0;i<26;i++){
                char c=(char)('a'+ i);
                if(ptr->containsKey(c)){
                    isItPos= isItPos or processNode(word, ptr->get(c), n, idx+1);
                }
            }
        }else if(!ptr->containsKey(curr)){
            return false;
        }else{
            return processNode(word, ptr->get(curr), n, idx+1);
        }
        
        return isItPos;
    }
    
    
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* ptr=root;
		for(char c:word){
            if(!ptr->containsKey(c)){
                ptr->put(c,new Node());
            }
            ptr=ptr->get(c);
        }
        ptr->setEnd();
    }
    
    bool search(string word) {
        int n=word.length();
        return processNode(word,root,n,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */