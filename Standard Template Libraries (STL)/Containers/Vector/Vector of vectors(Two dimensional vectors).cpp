/*
Vector of vectors is a two-dimensional vector with a variable number of rows where each row is vector.
Each index of vector stores a vector which can be traversed and accessed using iterators.
It is similar to an Array of Vectors but with dynamic properties.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<int>>V(5);//Declaring a vector of a constant number of vectors(rows) which have
    //variable number of elements(columns)
    
    //The vector of a constant number of vectors is similar to an Array of Vectors but with dynamic properties.
    
    //initializing all vectors
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<=i;j++)
        V[i].push_back(j);
    }
    //we can access elements stored in the vectors as if we were accessing the rows of a 2d array
    for(int i=0;i<5;i++)
    {
        cout<<"elements in the "<<i+1;
        if(i==0)
        cout<<"st";
        else if(i==1)
        cout<<"nd";
        else if(i==2)
        cout<<"rd";
        else
        cout<<"th";
        cout<<" vector are: ";
        
        for(int j=0;j<V[i].size();j++)
        cout<<V[i][j]<<" ";
        cout<<endl;
    }
    cout<<"------------------------------------------------------"<<endl;
    //We can use some of the methods like at(), front(), back(), push_back(), pop_back(), insert(), swap()
    //erase(), clear(), empty(), size(), resize(), etc. with both the vector of vectors and the vectors themselves.
    //but be careful that the arguments passed to the methods when we use it with the vector of vectors must be 
    //of type vector
    V.pop_back();//will delete the last vector stored in the vector of vectors
    vector<int>v1={5,12,18};
    V.push_back(v1);//will store the vector v1 at index 4 in the vector of vectors(instead of the vector we've just deleted)
    for(int i=0;i<5;i++)
    {
        cout<<"elements in the "<<i+1;
        if(i==0)
        cout<<"st";
        else if(i==1)
        cout<<"nd";
        else if(i==2)
        cout<<"rd";
        else
        cout<<"th";
        cout<<" vector are: ";
        
        for(int j=0;j<V[i].size();j++)
        cout<<V[i][j]<<" ";
        cout<<endl;
    }
    cout<<"------------------------------------------------------"<<endl;
    /*A vector of a variable number of vectors(rows) which have variable number of elements(columns)
    can be declared as vector<vector<int>>V;
    we can't initialize it using a for loop to iterate over its indices because it doesn't have a size yet
    instead we can use a temporary vector v1 and fill it with the elements we want using push_back() 
    and then add this vector v1 to V using also push_back()
    */
    //-------------------------------------------------------------------------------------------------------------
    //Also We can use some of the methods like at(), front(), back(), push_back(), pop_back(), insert(), swap()
    //erase(), clear(), empty(), size(), resize(), etc. with both the vector of vectors and the vectors themselves.
    //but be careful that the arguments passed to the methods when we use it with the vector of vectors must be 
    //of type vector
    //-------------------------------------------------------------------------------------------------------------
    //after initializing the vector of vectors V we can access elements(vectors)
    //as if we were accessing the rows of a 2d array or a 2d vector using a nested loop and indices 
    //-------------------------------------------------------------------------------------------------------------
    vector<vector<int>>vec(3,vector<int>(4));//declaring a 2d vector with number of rows(vectors) = 3
    //and number of columns(length of each vector) = 4;
    //STILL,number of vectors or their length can be changed because vectors are dynamic
    //vec.size() returns the number of vectors(rows) while vec[i].size() returns the length of the ith vector(row)
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
        vec[i][j]=1;
    }
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
        cout<<vec[i][j]<<" ";
        cout<<endl;
    }
    cout<<"------------------------------------------------------"<<endl;
    vec.push_back(v1);//adding a vector (a row) to the 2d vector vec with making the number of vectors = 4 (not 3)
    vec[0].push_back(5);//adding a number to the first vector(row) making its length = 5(not 4)
    vec[2].pop_back();//deleting the last number from the third vector(row) making its length = 3(not 4)
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
        cout<<vec[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}