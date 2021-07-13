#include <iostream>
using namespace std;

int main()
{
    int rows;
    cout << "enter rows : ";
    cin >> rows;

    int tempRow = rows;
    int starCount = 1;
    int space = 1;

    for (int i = 1; i <= rows; i++)
    {
        starCount =1;
        while(starCount <= i)
        {
            cout<<"*";
            starCount++;
        }

        space = 1;
        while(space <= 2*(tempRow -1))
        {
            cout<<" ";
            space ++;
        }

        starCount = 1;
        while (starCount <= i)
        {
            cout << "*";
            starCount++;
        }

        cout<<endl;

        tempRow -=1;
     }

     // till here first half printing is done

    tempRow = 0;
    /*
    for(int i=1; i<=rows; i++)
    {
        starCount = 1;
        while(starCount <= rows - i + 1 )
        {
            cout<<"*";
            starCount++;
        }

        space = 1;

        while(space <= tempRow)
        {
            cout<<" ";
            space++;
        }

        starCount = 1;
        while (starCount <= rows - i + 1)
        {
            cout << "*";
            starCount++;
        }
        tempRow += 2;
        cout<<endl;
        */

    //or to keep it symmetric just use n to 1 for i other code would be same

    // and space would grow from 0 to 6 etc

    //same thing follow whichever you feel easy

    tempRow = 1;

    for (int i = rows; i >= 1; i--)
    {
        starCount = 1;
        while (starCount <= i)
        {
            cout << "*";
            starCount++;
        }

        space = 1;
        while (space <= 2 * (tempRow - 1))
        {
            cout << " ";
            space++;
        }

        starCount = 1;
        while (starCount <= i)
        {
            cout << "*";
            starCount++;
        }

    

        tempRow += 1;
        cout << endl;
    }

    return 0;
}


/* logic is same but the way it is implemented is Bad
*/