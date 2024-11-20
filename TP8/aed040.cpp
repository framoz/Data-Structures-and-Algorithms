#include <set>
#include <iostream>

using namespace std;

void startCollection(int collectionSize, set<int> &stickerSet)
{
    for (int i = 0; i < collectionSize; i++)
    {
        int sticker;
        cin >> sticker;
        stickerSet.insert(sticker);
    }
}

set<int> openPack(int packSize, set<int> &stickerSet)
{
    int ret = 0;
    int sticker;
    set<int> resSet;

    for (int i = 0; i < packSize; i++)
    {
        cin >> sticker;
        int s1 = stickerSet.size();
        stickerSet.insert(sticker);
        if (s1 != stickerSet.size())
        {
            ret++;
            resSet.insert(sticker);
        }
    }
    cout << ret << endl;
    return resSet;
}

int main()
{
    int collectionSize;
    cin >> collectionSize;

    set<int> stickerSet;

    startCollection(collectionSize, stickerSet);

    int packSize;
    cin >> packSize;

    set<int> newSet = openPack(packSize, stickerSet);

    if (newSet.size() > 0)
    {
        auto it = newSet.begin();
        cout << *it;

        it++;
        for (; it != newSet.end(); it++)
        {
            cout << " " << *it;
        }
        cout << endl;
    }

    return 0;
}