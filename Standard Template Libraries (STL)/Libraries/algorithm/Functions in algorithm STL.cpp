/*
double X,Y;
int A,B;
char C;
-------------------------------------------------------------------------------------------------------------------------------
The header <algorithm> defines a collection of functions especially designed to be used on ranges of elements.
-------------------------------------------------------------------------------------------------------------------------------
**When passing the start and the end of a range in a container (possibly the whole container) we may use pointers or iterators**

When using **arrays** we pass pointers:--> (arr+l,arr+r+1) where l and r are the start and end of the range (0-indexed)
arr is a pointer has the same name of the array and points at the first element in the array (same as &arr[0])
(arr+l) is the same as (&arr[l])
to get the value which arr pointer points at use (*(arr+l)) which is same as (arr[l])
pointers to array elements can be incremented and decremented and it means to point at the following or previous element

When using **vectors, strings, sets ...etc** we pass iterators: 
--> (Container.begin()+l,Container.begin()+r+1) where l and r are the start and end of the range (0-indexed)
or possibly traverse the whole Container using (Container.begin(),Container.end())
Container.begin() is an iterator that points at the first element in the container
it's the same as &Container[0]
to get the value which the iterator points at use (*(Container.begin()+l)) which is same as (*&Container[l])

**We usually denote the start and end of a range either using pointers or iterators as [first, last) or [l,r) **
Input iterators to the initial and final positions in a sequence. The range used is [first,last), which contains all the elements between first and last, including the element pointed by first but NOT the element pointed by last.
-------------------------------------------------------------------------------------------------------------------------------
**Functions in <algorithm>**
-------------------------------------------------------------------------------------------------------------------------------
**Non-modifying sequence operations:**

all_of(l,r,[] (T){return ;})			Tests a condition on all elements in a range (function template) --> returns either true (1) or false (0)

any_of(l,r,[] (T){return ;})			Tests if any element in a range fulfills condition (function template)

none_of(l,r,[] (T) {return ;})			Tests if no elements fulfill a condition (function template)

for_each(l,r,function)					Apply a function to a range (function template)

find(l,r,Val)							Finds a value in a range (function template)

find_if(l,r,pred_function)				Finds an element in a range (function template)
-->returns An iterator to the first element in the range for which the pred_function does not return false.
If pred_function returns false for all elements, the function returns last.

find_if_not(l,r,pred_function)			Finds an element in a range (negative condition) (function template)

find_end(l1,r1,l2,r2)					Finds the last subsequence in a range (function template)
--> [l1,r1) is of the searched space and [l2,r2) is of the sequence to be searched for 
--> it returns an iterator (or a pointer) to the first element of the last occurrence of [l2,r2) in [l1,r1). If the sequence is not found, the function returns r1

find_first_of(l1,r1,l2,r2)				Finds an element from set in a range (function template)
--> [l1,r1) is of the searched space and [l2,r2) is of the sequence to be searched for 
--> returns an iterator (or a pointer) to the first element in [l1,r1) that matches one of [l2,r2) If no matches are found, the function returns r1

adjacent_find(l,r)						Finds equal adjacent elements (repeated elements) in a range (function template)
-->returns an iterator (or a pointer) to the first element of the first pair of matching consecutive elements in the range [l,r). If no such pair is found, the function returns r 

count(l,r,Val)							Counts appearances of a value in a range --> Returns the number of occurrences (function template)

count_if(l,r,pred_function)				Returns number of elements in a range satisfying some condition (function template)

mismatch(l1,r1,l2,r2)					Returns the first position where two ranges differ (function template)
--> Returns a pair, where its members first and second point to the first element in both sequences that did not compare equal to each other.
If the elements compared in both sequences have all matched, the function returns a pair with first set to r1 and second set to the element in that same relative position in the second sequence.
If none matched, it returns make_pair(l1,l2)

equal(l1,r1,l2,r2)						Tests whether the elements in two ranges are equal --> Returns either true (1) or false (0) (function template)

is_permutation(l1,r1,l2,r2)				Tests whether a range is permutation of another Returns either true (1) or false (0) (function template)

search(l1,r1,l2,r2)						Searches a range for a subsequence (function template)
--> [l1,r1) is of the searched space and [l2,r2) is of the sequence to be searched for 
--> returns an iterator to the first element of the first occurrence of [l2,r2) in [l1,r1). If the sequence is not found, the function returns r1

search_n(l,r,n,Val)						Searches a range for elements (function template)
--> n is Minimum number of successive elements to match
--> We can use a pred_function ---> search_n(l,r,n,Val,pred_function)
--> Returns an iterator to the first element of the sequence. If no such sequence is found, the function returns r.
-------------------------------------------------------------------------------------------------------------------------------
**Modifying sequence operations:**

copy(l1,r1,l2,r2)						Copies a range of elements (function template)
--> Copies [l1,r1) to [l2,r2)

copy_n(l1,n,l2)							Copies n elements (function template)

copy_if									Copy certain elements of range (function template)
copy_backward							Copy range of elements backward (function template)
move									Move range of elements (function template)
move_backward							Move range of elements backward (function template)
swap									Exchange values of two objects (function template)
swap_ranges								Exchange values of two ranges (function template)
iter_swap								Exchange values of objects pointed to by two iterators (function template)
transform								Transform range (function template)
replace									Replace value in range (function template)
replace_if								Replace values in range (function template)
replace_copy							Copy range replacing value (function template)
replace_copy_if							Copy range replacing value (function template)
fill	Fill							range with value (function template)
fill_n	Fill							sequence with value (function template)
generate								Generate values for range with function (function template)
generate_n								Generate values for sequence with function (function template)
remove									Remove value from range (function template)
remove_if								Remove elements from range (function template)
remove_copy								Copy range removing value (function template)
remove_copy_if							Copy range removing values (function template)
unique									Remove consecutive duplicates in range (function template)
unique_copy								Copy range removing duplicates (function template)
reverse									Reverse range (function template)
reverse_copy							Copy range reversed (function template)
rotate									Rotate left the elements in range (function template)
rotate_copy								Copy range rotated left (function template)
random_shuffle							Randomly rearrange elements in range (function template)
shuffle									Randomly rearrange elements in range using generator (function template)
-------------------------------------------------------------------------------------------------------------------------------
**Partitions:**

is_partitioned							Test whether range is partitioned (function template)
partition								Partition range in two (function template)
stable_partition						Partition range in two - stable ordering (function template)
partition_copy							Partition range into two (function template)
partition_point							Get partition point (function template)
-------------------------------------------------------------------------------------------------------------------------------
**Sorting:**

sort									Sort elements in range (function template)
stable_sort								Sort elements preserving order of equivalents (function template)
partial_sort							Partially sort elements in range (function template)
partial_sort_copy						Copy and partially sort range (function template)
is_sorted								Check whether range is sorted (function template)
is_sorted_until							Find first unsorted element in range (function template)
nth_element								Sort element in range (function template)
-------------------------------------------------------------------------------------------------------------------------------
**Binary search (operating on partitioned/sorted ranges):**

lower_bound								Return iterator to lower bound (function template)
upper_bound								Return iterator to upper bound (function template)
equal_range								Get subrange of equal elements (function template)
binary_search							Test if value exists in sorted sequence (function template)
-------------------------------------------------------------------------------------------------------------------------------
**Merge (operating on sorted ranges):**

merge									Merge sorted ranges (function template)
inplace_merge							Merge consecutive sorted ranges (function template)
includes								Test whether sorted range includes another sorted range (function template)
set_union								Union of two sorted ranges (function template)
set_intersection						Intersection of two sorted ranges (function template)
set_difference							Difference of two sorted ranges (function template)
set_symmetric_difference				Symmetric difference of two sorted ranges (function template)
-------------------------------------------------------------------------------------------------------------------------------
**Heap:**

push_heap								Push element into heap range (function template)
pop_heap								Pop element from heap range (function template)
make_heap								Make heap from range (function template)
sort_heap								Sort elements of heap (function template)
is_heap									Test if range is heap (function template)
is_heap_until							Find first element not in heap order (function template)
-------------------------------------------------------------------------------------------------------------------------------
**Min/max:**

min										Return the smallest (function template)
max										Return the largest (function template)
minmax									Return smallest and largest elements (function template)
min_element								Return smallest element in range (function template)
max_element								Return largest element in range (function template)
minmax_element							Return smallest and largest elements in range (function template)
-------------------------------------------------------------------------------------------------------------------------------
**Other:**

lexicographical_compare					Lexicographical less-than comparison (function template)
next_permutation						Transform range to next permutation (function template)
prev_permutation						Transform range to previous permutation (function template)
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#define ll long long
#define endl "\n"
using namespace std;

ll Mod_Exp(ll x,ll n,ll p)
{
    if(x%p==0 || !x)
    return 0;
    
    if(n==0)
    return 1;
    
    ll Half_Pow=Mod_Exp(x%p,n>>1,p);//Calculated Once
    
    if(n&1)//n is odd
    return ((x%p)*Half_Pow%p*Half_Pow%p)%p;
    else
    return (Half_Pow%p*Half_Pow%p)%p;
}

bool Isprime(ll n)
{
  if(n<2)
  return false;
  
  if(n<=3)
  return true;
  
  return (Mod_Exp(2,n-1,n)%n==1);
}

void Mult(int &n)
{
	n*=2;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int arr[5]={1,3,5,7,9};
    vector<int>V={2,4,6,8,10,23,2,2,4,12,20};
    
    cout<<arr<<" "<<&arr[0]<<endl;
    cout<<*(arr+1)<<" "<<arr[1]<<endl;
    auto it=V.begin();
    cout<<*it<<" "<<*&V[0]<<endl;
    cout<<*(it+2)<<endl;
    cout<<"----------------------------------------------------------\n";
    if(all_of(arr,arr+5,[](int i){return i%2!=0;}))
    cout<<"All elements are ODD\n";
    
    if(all_of(V.begin(),V.end(),[](int i){return i%2==0;}))
    cout<<"All elements are EVEN\n";
    
    if(any_of(V.begin(),V.end(),[](int c){return Isprime(c);}))
    cout<<"There is a prime\n";
    else
    cout<<"No primes found!\n";
    
    if(none_of(V.begin(),V.end(),[](int c){return Isprime(c);}))
    cout<<"There isn't any primes\n";
    else
    cout<<"Yes, primes found!\n";
    
    for_each(V.begin(),V.begin()+3,Mult);
    cout<<"After using for_each: ";
    for(auto i:V)//Range-based for loop
    cout<<i<<" ";
    cout<<endl;
    //V = {4,8,12,8,10,23,2,2,4,12,20}
    cout<<"The first Prime is --> "<<*find_if(V.begin(),V.end(),Isprime)<<"\n";
    cout<<"The first NON_Prime is --> "<<*find_if_not(V.begin(),V.end(),Isprime)<<endl;
    
    int arr2[10]={1,3,5,2,4,7,1,3,5,10};
    cout<<(find_end(arr2,arr2+10,arr,arr+3))<<endl;
    
    cout<<"At index: "<<find_first_of(V.begin(),V.end(),arr2,arr2+10)-V.begin()<<" --> "<<*find_first_of(V.begin(),V.end(),arr2,arr2+10)<<endl;
    
    cout<<"First repeated element consecutively is at index: "<<adjacent_find(V.begin(),V.end())-V.begin()<<" and equal "<<*adjacent_find(V.begin(),V.end())<<endl;
    
    cout<<"8 exists "<<count(V.begin(),V.end(),8)<<" times\n";
    
    cout<<"There exists "<<count_if(arr,arr+5,Isprime)<<" Primes in this range\n";
    
    cout<<"The first mismatching elements are --> "<<*mismatch(arr2,arr2+10,arr,arr+5).first<<" "<<*mismatch(arr2,arr2+10,arr,arr+5).second<<endl;
    
    if(equal(arr,arr+3,arr2,arr2+3))
    cout<<"Ranges are equal\n";
    else
    cout<<"Ranges are NOT equal\n";
    
    if(is_permutation(arr,arr+5,arr2))
    cout<<"Both Containers have the same elements\n";
    else
    cout<<"Containers have different elements\n";
    
    //V = {4,8,12,8,10,23,2,2,4,12,20}
    cout<<"two 2's are found at index: "<<search_n(V.begin(),V.end(),2,2)-V.begin()<<endl;
    cout<<"----------------------------------------------------------\n";
    int Myints[7]={1,2,3,4,5,6,7};
    copy(Myints,Myints+7,arr);
    for(int i:arr)
    cout<<i<<" ";
    cout<<endl;
    
    copy_n(Myints,4,V.begin());
    for(int i:V)
    cout<<i<<" ";
    cout<<endl;
    return 0;
}
