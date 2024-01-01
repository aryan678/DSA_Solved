class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.size()==0 || s.size()==0)  return 0;
       // if(g[0]>g[g.size()-1])
            sort(g.begin(),g.end());
       // if(s[0]>s[s.size()-1])
            sort(s.begin(),s.end());
        int i=0,j=0,ctr=0;
        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){
                i++;j++;ctr++;
            }
            else if(g[i]>s[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return ctr;
    }
};