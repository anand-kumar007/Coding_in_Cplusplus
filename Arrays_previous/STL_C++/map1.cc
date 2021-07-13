// Topic: MAP
// 1. syntax : map<T1,T2> T1 is key type and T2 is value type
// 2. std::map is associative container that stores elements in key 
//    value combinations where key should be unique otherwise it
//    overrides the previous data value.
// 3. It is implemented using self balanced binary tree (avl/red black tree)

// 4. it stores key value pair in sorted order on the basis of key.
// 5. std:: map is used in dictionary type problems.

// 6. T1 should be a datatype which has predefined comparison functions.
//    can not be a class and all.

// 7. key is single value but value could be a vector(multiple values)

#include<iostream>
#include<map>
#include<functional>
#include<vector>

using namespace std;

void haha();
int main()
{
    //default order is ascending order    
    // std:: map<string,int> MAP;

    //descending order (provide greater<basis dtype for classification>)
    // std:: map<string,int,greater<string>> MAP; 

    // ascending default one
    std:: map<string,int,less<>> MAP; 

    MAP["chotu"] = 9833923;
    MAP["Amit"] = 90902231;
    MAP.insert(std::make_pair("Bot",7354221));

    //loop through map(range based for loop)(first is key and second is value)
    for(auto &it : MAP)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }

    //access using [] notation
    MAP["Bot"]=10;  // only value can be changed key can never be changed
    cout << MAP["Bot"]<< endl;

    haha();
    return 0;
}

void haha()
{
    // ascending default one
    std::map<string, vector<int>, less<>> MAP;

    MAP["chotu"].push_back(93939331);
    MAP["Amit"].push_back(102);
    MAP["Amit"].push_back(1002);

    // MAP.insert(std::make_pair("Bot", 7354221));

    for (auto &it : MAP)
    {
        cout << it.first << " " ;
        //as second is a vector now
        for(auto &el2 : it.second)
        cout<<el2<<" ";

        cout<<endl;
    }

   
}