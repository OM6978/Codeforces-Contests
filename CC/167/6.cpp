#include <bits/stdc++.h>
using namespace std; 

void rotatematrix(int m, int n,vector<vector<int>> & mat) 
{ 
	int row = 0, col = 0; 
	int prev, curr; 

	while (row < m && col < n) 
	{ 
		if (row + 1 == m || 
			col + 1 == n) 
			break; 

		prev = mat[row + 1][col]; 

		for (int i = col; i < n; i++) 
		{ 
			curr = mat[row][i]; 
			mat[row][i] = prev; 
			prev = curr; 
		} 
		row++; 

		for (int i = row; i < m; i++) 
		{ 
			curr = mat[i][n-1]; 
			mat[i][n-1] = prev; 
			prev = curr; 
		} 
		n--; 

		if (row < m) 
		{ 
			for (int i = n-1; i >= col; i--) 
			{ 
				curr = mat[m-1][i]; 
				mat[m-1][i] = prev; 
				prev = curr; 
			} 
		} 
		m--; 

		if (col < n) 
		{ 
			for (int i = m-1; i >= row; i--) 
			{ 
				curr = mat[i][col]; 
				mat[i][col] = prev; 
				prev = curr; 
			} 
		} 
		col++; 
	}
}

void firsass(vector<vector<int>> & mat,int i)
{
    int N = mat.size();

    if(i%2 == 1)
    {
        int curr = 1;
        for(int j=N/2 - 1;j>=i+1;j++)
        {
            mat[i][j] = curr++;
        }
    }
    else
    {
        int curr = 1;
        for(int j=i+1;j<N/2;j++)
        {
            mat[i][j] = curr++;
        }
    }
}

void nextass(vector<vector<int>> & mat,int i)
{
    int N = mat.size();
    int curr = 1;

    if(i%2 == 1)
    {
        for(int j=N/2 - i - 2;j>= N/2;j++)
        {
            mat[i][j] = curr++;
        }
    }
    else
    {
        for(int j=N/2;j< N/2 - i - 1;j++)
        {
            mat[i][j] = curr++;
        }
    }
}

void solve()
{
    int N;
    cin>>N;

    vector<vector<int>> mat(N,vector<int>(N,0));
    for(int i=0;i<N;i++)
    {
        mat[i][i] = N/2;
        mat[i][N-i-1] = N/2 + 1;
    }

    for(int i=0;i<N;i++)
    {
        firsass(mat,i);
        nextass(mat,i);
    }

    rotatematrix(N,N,mat);

    for(int i=0;i<N;i++)
    {
        firsass(mat,i);
        nextass(mat,i);
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}