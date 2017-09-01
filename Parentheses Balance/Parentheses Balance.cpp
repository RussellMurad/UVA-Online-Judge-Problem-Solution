#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    cin >> N;
    getchar();
    while(N--)
    {
        char str[200];
        stack <char> Stack;
        gets(str);
        int Size = strlen(str);
        for(int i=0; i<Size; i++)
        {
            if(!Stack.empty() && ((Stack.top()=='(' && str[i]==')') || (Stack.top()=='[' && str[i]==']')))
            {
                Stack.pop();
            }
            else
                Stack.push(str[i]);
        }

        if(Stack.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }
    return 0;
}
