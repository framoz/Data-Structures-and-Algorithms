#include <iostream>
#include <list>
#include <string>

using namespace std;

void make_list(list<string> &people, int size)
{   

    for (int i = 0; i < size; i++)
    {
        string child;
        cin >> child;
        people.push_back(child);
    }
}

int get_num()
{
    string sentence;
    getline(cin, sentence);
    int ret = 1;
    for (auto c : sentence)
    {
        if (c == ' ')
        {
            ret++;
        }
    }
    return ret;
}

void game(list<string> &children, int k)
{
    auto it = children.begin();

    // k%children.size() -1
    while (children.size() > 0)
    {

        for (int i = 1; i < k; i++)
        {
            it++;
            if (it == children.end())
            {
                it = children.begin();
            }
        }
        cout << *it << endl;

        it = children.erase(it);
        if (it == children.end())
            it = children.begin();

    }
}

int main()
{

    int k = get_num();
    int children_num;
    cin >> children_num;
    list<string> children;

    make_list(children, children_num);
    game(children, k);

    return 0;
}