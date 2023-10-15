class Solution {
    struct Node{
        Node* links[2];
        bool contains_key(int bit){
            return (links[bit]!=NULL);
        }
        Node* get(int bit){
            return links[bit];
        }
        void put(int bit, Node* node){
            links[bit]=node;
        }
    };
public:
    class Trie{
        Node* root;
        public:
        Trie(){
            root=new Node();
        }
        void ins(int num){
            Node* node=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i) & 1;
                if(!node->contains_key(bit)){
                    node->put(bit,new Node());
                }
                node=node->get(bit);
            }
        }
        int getmax(int num){
            Node* node=root;
            int maxnum=0;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(node->contains_key(!bit)){
                    maxnum=maxnum | (1<<i);
                    node=node->get(!bit);
                }
                else    node=node->get(bit);
            }
            return maxnum;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(auto &it:nums)  t.ins(it);
        int maxi=0;
        for(auto &it:nums){
            maxi=max(maxi,t.getmax(it));
        }
        return maxi;
    }
};