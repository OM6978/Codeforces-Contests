#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    struct Node
    {
        int is;
        int passed;
        Node* next[10];
    };

    Node* root;
    Node* init()
    {
        Node* ret = new Node;

        ret->is = 0;
        ret->passed = 0;
        for(int i=0;i<10;i++)ret->next[i] = NULL;

        return ret;
    }

    Trie()
    {
        root = init();
    }
    
    void insert(string & word)
    {
        Node* curr = root;

        for(char a : word)
        {
            int in = a - 'a';
            in = (in-(in>=18)-(in==25))/3 + 2;

            if(curr->next[in] == NULL)curr->next[in] = init();

            curr = curr->next[in];
            curr->passed++;
        }

        curr->is++;
    }
    
    int startsWith(string & prefix) 
    {
        Node* curr = root;
        for(char a : prefix)
        {
            int in = a - '0';
            if(curr->next[in] == NULL)return 0;

            curr= curr->next[in];
        }

        return curr->passed;
    }
};

void solve()
{
    int N,M;
    cin>>N>>M;

    Trie runes;

    string s,r;
    for(int i=0;i<N;i++)
    {
        cin>>s;
        runes.insert(s);
    }

    for(int i=0;i<M;i++)
    {
        cin>>r;
        cout << runes.startsWith(r) << '\n';
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
    
    solve();
    
    return 0;
}