#include <bits/stdc++.h>
using namespace std;

long long int n, m, q;
long long int tot;

struct node
{
  node *child[26];
  long long int prefix;
  vector<string> wend;
  node()
  {
    prefix = 0;
    for (int i = 0; i < 26; i++)
    {
      child[i] = NULL;
    }
  }
};

struct trie
{
  node *root;
  trie()
  {
    root = new node;
  }

  void insert(string s)
  {
    node *current = root;
    for (int i = 0; i < s.length(); i++)
    {
      current->prefix++;
      long long int x = s[i] - 'a';
      if (current->child[x] == NULL)
      {
        current->child[x] = new node;
      }
      current = current->child[x];
    }
    current->wend.push_back(s);
  }
  void dfs(node *current)
  {
    if (current == NULL || tot == 0)
      return;

    for (int i = 0; i < current->wend.size() && tot > 0; i++)
    {
      tot--;
      cout << current->wend[i] << " ";
    }

    for (int i = 0; i < 26; i++)
    {
      dfs(current->child[i]);
    }
  }
};

void solve()
{
  cin >> n >> m >> q;
  trie t;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    string s;
    cin >> s;
    t.insert(s);
  }
  long long int k, a;
  string s;
  for (int i = 0; i < q; i++)
  {
    cin >> a >> s >> k;
    for (int i = 1; i <= a; i++)
    {
      tot = k;
      string p = s.substr(0, i);
      auto current = t.root;
      for (int i = 0; i < p.length(); i++)
      {
        current = current->child[p[i] - 'a'];
        if (current == NULL)
          break;
      }

      t.dfs(current);

      cout << "\n";
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int test_cases;
  test_cases = 1;

  while (test_cases--)
  {
    solve();
  }
}
