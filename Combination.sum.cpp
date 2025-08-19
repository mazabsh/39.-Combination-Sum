#include<iostream> 
#include<vector> 

using namespace std; 

class Solution{
public: 
     void backtrack(vector<int>& candidates, vector<vector<int>>& res, vector<int>& ans, int start, int remain){
       if(remain==0){
         res.push_back(ans); 
         return; 
       }else if(remain<0) return; 
       for(int i=start; i<candidates.size(); ++i){
         ans.push_back(candidates[i]); 
         backtrack(candidates, res, ans, i, remain-candidates[i]); 
         ans.pop_back(); 
       }
     }
     vector<vector<int>> combinationSum(vector<int>& candidates, int target){
       vector<vector<int>> res; 
       vector<int> ans; 
       backtrack(candidates, res, ans, 0, target); 
       return res; 
     }
};
int main(){
  vector<int> candidates = {2,3,5}; 
  int target = 8; 
  Solution sol; 
  vector<vector<int>> res= sol.combinationSum(candidates, target); 
  for(auto vec:res){
    cout << "[" ; 
    for(int n: vec){
      cout << n << "," ; 
    }
    cout << "]" ;
  }
  cout << endl; 
  return 0; 
}
