#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> grid, vector<vector<int>> taxi_stands, vector<int> passenger)
{
    int N = grid.size(),M = grid[0].size() , O = taxi_stands.size();
    
    vector<vector<int>> ans;
    queue<pair<int,int>> pointers;
    map<pair<int,int>,pair<int,int>> prevs;
    set<pair<int,int>> taxiii;
    
    prevs[{passenger[0],passenger[1]}] = {-1,-1};
    vector<pair<int,int>> nexx = {{1,0},{0,1},{-1,0},{0,-1}};
    
    auto is_valid = [&](int x,int y) -> bool
    {
        return (x <= N && x>0 && y <= M && y>0);
    };
    
    for(int i=0;i<O;i++)taxiii.insert({taxi_stands[i][0],taxi_stands[i][1]});
    
    grid[passenger[0] - 1][passenger[1]-1] = 1;
    pointers.push({passenger[0],passenger[1]});
    
    while(pointers.size())
    {
        int curr = pointers.size();
        while(curr--)
        {
            auto top = pointers.front();
            int x = top.first,y = top.second;
            
            if(is_valid(x,y) && taxiii.find({x,y}) != taxiii.end())
            {
                pair<int,int> now = {x,y};
                
                while(prevs[now] != (pair<int,int>){-1,-1})
                {
                    ans.insert(ans.begin(),{now.first,now.second});
                    now = prevs[now];  
                }
                
                return ans;
            }
            
            pointers.pop();
            for(pair<int,int> val : nexx)
            {
                int new_x = x + val.first,new_y = y + val.second;
                
                if(is_valid(new_x,new_y) && grid[new_x-1][new_y-1] == 0)
                {
                    pointers.push({new_x,new_y});
                    prevs[{new_x,new_y}] = {x,y};
                }
            }
            grid[x-1][y-1] = 1;
        }
    }
    
    return ans;
}

signed main()
{
    vector<vector<int>> grid,tax;
    auto ans = solution()
}
