/* 
iterators : pointers like structure in c++
points the elements of the container

.end() ==> points to just next to last
.begin() ==> points to first element of the vector

1,2,3,4,5
.being() ==> v[0]
.end() ==> v[n] ie one more than last element

syntax :
container :: iterator itName;

vector<int> :: iterator it;
it = v.begin();

*it ==> will give value of v[0]
*(it+1) ==> will give v[1]

note it+1 and all cannot be done for all containers
those which have indexes can be used with it+1
and those who don't have indexes cannot be used
*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    vector<int>::iterator it;
    it = v.begin();

    cout << "second element : " << *(it + 1) << endl;

    for (; it != v.end(); ++it)
    {
        //++it will take it to next
        //element in container
        cout << *it << " ";
    }
    cout << endl;

    vector<pair<int, int>> vp = {{1, 2}, {3, 4}, {5, 6}};

    vector<pair<int, int>>::iterator p_it;
    for (p_it = vp.begin(); p_it != vp.end(); ++p_it)
    {
        // cout<< (*p_it).first<<" "<<(*p_it).second<<endl;
        // p_it ==> is pointing to location
        // *p_it ==> value of the pair so we can call first and second

        //special syntax for pair
        cout << p_it->first << " " << p_it->second << endl;
    }
    return 0;
}

/*
it+1 ==> next location
++it ==> next iterator

in case of vector both are same since vector are stored
in contiguous manner

but in some containers which are not store in contagious manner
this does have a difference 

eg: in case of maps and sets (not in contagious manner)

it+1 will take to next location which is invalid
it++ will take to next iterator so will work :)


*/
