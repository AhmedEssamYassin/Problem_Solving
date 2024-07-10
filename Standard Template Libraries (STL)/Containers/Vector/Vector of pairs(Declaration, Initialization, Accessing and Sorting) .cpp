/*
A pair is a container which stores two values mapped to each other like this (a,b)
and a vector containing multiple number of such pairs is called a vector of pairs.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Driver function to sort the vector elements by second element of pairs
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<pair<int,int>>V;//Declaring a vector of pairs
    //Adding pairs to the vector 
    V.push_back({2,5});//we can write the ordered pair between curly brackets 
    V.push_back({3,12});
    V.push_back(make_pair(1,7));//we can also use make_pair( , ) 
    
    //we use V[i].first to access the first element of the ith pair
    //we use V[i].second to access the second element of the ith pair
    for(int i=0;i<V.size();i++)
    {
        cout<<V[i].first<<" "<<V[i].second<<endl;
    }
    cout<<"--------------------------------------------------------"<<endl;
    
    //Sorting the vector elements on the basis of first element of pairs in ascending order.
    sort(V.begin(),V.end());//By default the sort function sorts the vector elements on basis of first element of pairs.
    for(int i=0;i<V.size();i++)
    {
        cout<<V[i].first<<" "<<V[i].second<<endl;
    }
    cout<<"--------------------------------------------------------"<<endl;
    //Sorting the vector elements on the basis of second element of pairs in ascending order
    sort(V.begin(),V.end(),sortbysec);//we pass a third argument, a call to a user defined function in the sort() function.
    for(int i=0;i<V.size();i++)
    {
        cout<<V[i].first<<" "<<V[i].second<<endl;
    }
    cout<<"--------------------------------------------------------"<<endl;
    //Sorting the vector elements on the basis of first element of pairs in descending order.
    sort(V.rbegin(),V.rend());//using “sort()” and passing iterators of 1D vector as its arguments.
    for(int i=0;i<V.size();i++)
    {
        cout<<V[i].first<<" "<<V[i].second<<endl;
    }
    cout<<"--------------------------------------------------------"<<endl;
    //Sorting the vector elements on the basis of second element of pairs in descending order.
    sort(V.rbegin(),V.rend(),sortbysec);//we pass a third argument, a call to a user defined function in the sort() function.
    for(int i=0;i<V.size();i++)
    {
        cout<<V[i].first<<" "<<V[i].second<<endl;
    }
    cout<<"--------------------------------------------------------"<<endl;
    return 0;
}

/*
Problem: Dragons 
https://codeforces.com/problemset/problem/230/A
-------------------------------------------------------------------------------------------------------------------------------------------------------------
Solution: 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<pair<int,int>>V;
    int n,s,x,y;
    cin>>s>>n;
    while(n--)
    {
        cin>>x>>y;
        V.push_back({x,y});
    }
    sort(V.begin(),V.end());
    
    for(int i=0;i<V.size();i++)
    {
        if(s>V[i].first)
        s+=V[i].second;
        else
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
*/