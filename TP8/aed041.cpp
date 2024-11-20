#include <set>
#include <iostream>

using namespace std;

void makeDeck(int deckSize, multiset<int, greater<int>> &deck)
{
    for (int i = 0; i < deckSize; i++)
    {
        int card;
        cin >> card;
        deck.insert(card);
    }
}

void battle(multiset<int, greater<int>> &deck1, multiset<int,greater<int>> &deck2)
{
    auto card1Point = deck1.begin();
    auto card2Point = deck2.begin();

    int card1 = *card1Point;
    int card2 = *card2Point;
    
    if (card1 > card2)
    {

        card1-= card2;
        deck1.erase(card1Point);
        deck2.erase(card2Point);
        deck1.insert(card1);
    }
    else if (card2 > card1)
    {

        card2-= card1;
        deck1.erase(card1Point);
        deck2.erase(card2Point);

        deck2.insert(card2);
    }
    else
    {
        deck1.erase(card1Point);
        deck2.erase(card2Point);
    }

    if (!(deck1.size() == 0 || deck2.size() == 0)){
        battle(deck1, deck2);
    };

    
}



int main(){

    multiset<int, greater<int>> alicesDeck;
    multiset<int, greater<int>> bobsDeck;
    
    int d1;
    cin >> d1;

    makeDeck(d1, alicesDeck);
    
    int d2;
    cin >> d2;

    makeDeck(d2, bobsDeck);

    battle(bobsDeck, alicesDeck);

    int res = alicesDeck.size() - bobsDeck.size();

    if (res > 0){
        cout << "Alice wins" << endl << alicesDeck.size()<<endl;
    }
    else if (res<0){
         cout << "Bob wins" << endl << bobsDeck.size()<<endl;
    }
    else{
         cout << "Tie" << endl << 0<<endl;
    }

    return 0;
}