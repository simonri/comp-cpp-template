#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int count(vector<int> vec, int remUses, int rem, size_t i)
{
  int total = 0;

  if (remUses > 0 && i < vec.size())
  {
    if (vec[i] <= rem)
    {
      if (vec[i] == rem)
      {
        total++;
      }

      total += count(vec, remUses - 1, rem-vec[i], i);
    }

    total += count(vec, remUses, rem, i + 1);
  }

  return total;
}

int find(vector<int> vec, int n)
{
  sort(vec.begin(), vec.end(), greater<int>());
  return count(vec, vec.size(), n, 0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int result = 0;

    cout << "Hello world" << endl;
    return 0;

    int minutes;
    cin >> minutes;

    int num_dishes;
    cin >> num_dishes;

    vector<int> dishes;

    while(num_dishes--)
    {
        int temp;
        cin >> temp;

        dishes.push_back(temp);
    }

    result = find(dishes, minutes);
    cout << "Result:" << endl << result << endl; 

    return 0;
}
