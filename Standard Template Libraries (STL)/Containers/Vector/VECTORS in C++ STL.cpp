/*
begin() – Returns an iterator pointing to the first element in the vector
end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
size() – Returns the number of elements in the vector.
max_size() – Returns the maximum number of elements that the vector can hold.
capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
resize(n) – Resizes the vector so that it contains n elements and destroy all elements beyond index n-1
empty() – Returns whether the container is empty.
shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
reserve() – Requests that the vector capacity be at least enough to contain n elements.
at(g) – Returns a reference to the element at position ‘g’ in the vector
front() – Returns a reference to the first element in the vector
back() – Returns a reference to the last element in the vector
assign() – It assigns new value to the vector elements by replacing old ones
push_back() – It push the elements into a vector from the back
pop_back() – It is used to pop or remove elements from a vector from the back.
insert() – It inserts new elements before the element at the specified position
erase() – It is used to remove elements from a container from the specified position or range.
swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
clear() – It is used to remove all the elements of the vector container
emplace() – It extends the container by inserting new element at position
emplace_back() – It is used to insert a new element into the vector container, the new element is added to 
the end of the vector
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int>V(10);//Declaration of a vector that holds 10 elements and is 0-indexed
    //Unlike arrays,the default value of all elements is 0 (NOT a garbage value)
    cout<<V[0]<<" "<<V[6]<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    vector<int>V1(10,5);//The second parameter denotes the value that should be placed in every element of the vector
    //we can access elements just like an array 
    cout<<V1[2]<<endl;
    V1[5]=3;
    cout<<V1[5]<<endl;
    V1.resize(5);//Resizes the vector so that it contains 5 elements and destroy all elements beyond index 5-1
    //cout<<V1.at(5)<<endl;//-->makes an error, out of bounds of the vector after resizing
    V1.clear();//erases the whole vector
    cout<<V1[8]<<endl;//it still prints 5 because it was set as the default value for this vector elements
    cout<<"--------------------------------------------------------------------------"<<endl;
    vector<int>V2;//Unlike arrays, we can declare a vector without an initial size
    //When we do this, the vector is empty. It has no elements, so we can’t even access V[0] or V[2], etc.
    V2.push_back(12);//Adds an element to the end of the vector, increasing its size by 1.
    V2.push_back(16);
    V2.push_back(20);
    V2.push_back(26);
    //V2(4)={12,16,20,26};
    //V2.begin():Returns an iterator that represents the first element in the vector : 0
    //V2.end():Returns an iterator that represents one element past the last element : 4 
    //(if (n-1) is the index of the last element, it returns n)
//V.erase(index):removes a specific element
    cout<<V2.front()<<endl;//returns the first element in the vector: V2[0]
    cout<<V2[0]<<endl;
    V2.erase(V2.begin());//removes the first element in the vector
    cout<<V2.front()<<endl;
    cout<<V2.back()<<endl;//returns the last element in the vector:V2[3]
    cout<<V2[3]<<endl;
    V2.pop_back();//removes the last element in the vector (totally equal to V2.erase(V2.end()-1);)
    cout<<V2.back()<<endl;
    //now V2(2)={16,20}
    V2.insert(V2.begin(),54);// inserts 54 at the beginning but doesn't replace 16
    cout<<V2.at(0)<<" "<<V2.at(1)<<endl;
    //now V2[0]=54  V2[1]=16  V2[2]=20
    V2.insert(V2.begin()+1,88);//V2[1] becomes 88 and V2[2] becomes 16 and so on
    cout<<V2.at(1)<<" "<<V2.at(2)<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    V1.swap(V2);//swaps the contents of one vector with another vector of same type. Sizes may differ.
    //in other words, V1 holds the elements of V2 and vice versa
    for(int i=0;i<V1.size();i++)
    cout<<V1.at(i)<<" ";
    cout<<endl;
    for(int i=0;i<V2.size();i++)
    cout<<V2.at(i)<<" ";//prints nothing because V1 elements were destroyed when we used clear()
    cout<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    
    
    
    
    
    return 0;
}