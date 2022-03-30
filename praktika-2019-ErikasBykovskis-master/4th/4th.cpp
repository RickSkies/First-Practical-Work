#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <fstream>

using namespace std;
using std::cout;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

struct character
{
    string name;
    int hp;
    int attack;
    int coins;
}me, goblin, skeleton, spider, zombie, wolf, bigbear, dinosaur, forestking;

int randomdrop()
{
    int randomnumber;
    srand(time(NULL));
    randomnumber = rand() % 100;
    return randomnumber;
}

void drops(int &gottendrop, int &valkyriesword, int &rock, int &flesh, int &metal, int &aotfk, string &dropname, int &price, int &value)
{
    if (gottendrop <= 1)
    {
        dropname = "Valkyrie Sword";
        valkyriesword++;
        price = 250;
        value = 50;
    }
    else if (gottendrop > 1 && gottendrop <= 10)
    {
        dropname = "Rock";
        rock++;
        price = 10;
        value = 1;
    }
    else if (gottendrop > 10 && gottendrop <= 20)
    {
        dropname = "Flesh";
        flesh++;
        price = 15;
        value = 3;
    }
    else if (gottendrop > 20 && gottendrop <= 30)
    {
        dropname = "Metal";
        metal++;
        price = 20;
        value = 5;
    }
    else if (gottendrop > 30 && gottendrop <= 31)
    {
        dropname = "Armor of The Fire Kobras";
        aotfk++;
        price = 500;
        value = 100;
    }
    else if (gottendrop > 31 && gottendrop <= 100)
    {
        dropname = "Nothing";
    }
}

void slowprint (const string& message, unsigned int millis_per_char)
{
    for (const char c: message)
    {
        cout << c << flush;
        sleep_for(milliseconds(millis_per_char));
    }
}

void error(string &message)
{
    cout << endl;
    message = "That's not what was quite planned. Try again Hero.";
    slowprint(message, 20);
}

void meniu2(string &message)
{
    cout << endl;
    cout << endl;
    cout << endl;
    message = "Choose your next move!";
    slowprint(message, 20);
    cout << endl;
    message = "1. Battle!";
    slowprint(message, 20);
    cout << endl;
    message = "2. Fight The Forest King!";
    slowprint(message, 20);
    cout << endl;
    message = "3. Shop";
    slowprint(message, 20);
    cout << endl;
    message = "4. My hero";
    slowprint(message, 20);
    cout << endl;
    message = "5. Achievements";
    slowprint(message, 20);
    cout << endl;
    message = "6. Exit to main menu";
    slowprint(message, 20);
    cout << endl;
}

void meniu(string &message)
{
    cout << endl;
    cout << endl;
    cout << endl;
    message = "Welcome to the Forest of Words! Make your choice!";
    slowprint(message, 20);
    cout << endl;
    message = "1. Start game";
    slowprint(message, 20);
    cout << endl;
    message = "2. Help";
    slowprint(message, 20);
    cout << endl;
    message = "3. Exit";
    slowprint(message, 20);
    cout << endl;
}

void help(string &message)
{
    cout << endl;
    cout << endl;
    cout << endl;
    message = "Welcome to the Forest of Words!";
    slowprint(message, 20);
    cout << endl;
    message = "1. Choose your game mode.";
    slowprint(message, 20);
    cout << endl;
    message = "2. Choose your class.";
    slowprint(message, 20);
    cout << endl;
    message = "3. Fight minions to strenghten up.";
    slowprint(message, 20);
    cout << endl;
    message = "4. Use shop to strenghten up.";
    slowprint(message, 20);
    cout << endl;
    message = "5. While adventuring you are earning xp, level and achievements.";
    slowprint(message, 20);
    cout << endl;
    message = "6. Every fight can drop you rewards.";
    slowprint(message, 20);
    cout << endl;
    message = "7. Fight and defeat The Forest King to win this game.";
    slowprint(message, 20);
}

void startgame(string &message)
{
    cout << endl;
    cout << endl;
    cout << endl;
    message = "Welcome, Hero. Choose your class!";
    slowprint(message, 20);
    cout << endl;
    message = "1. Warrior";
    slowprint(message, 20);
    cout << endl;
    message = "2. Mage";
    slowprint(message, 20);
    cout << endl;
    message = "3. Priest";
    slowprint(message, 20);
    cout << endl;
}

void default_minions(int &gottendrop, int &newhp, int &newattack, int &newcoins, string &newname, int &difficulty)
{
    if (gottendrop <= 25)
    {
        if (difficulty == 1)
        {
            goblin.name = "Goblin";
            newname = goblin.name;
            goblin.hp = 100;
            newhp = goblin.hp;
            goblin.attack = 10;
            newattack = goblin.attack;
            goblin.coins = 1;
            newcoins = goblin.coins;
        }
        else if (difficulty == 2)
        {
            goblin.name = "Goblin";
            newname = goblin.name;
            goblin.hp = 110;
            newhp = goblin.hp;
            goblin.attack = 11;
            newattack = goblin.attack;
            goblin.coins = 1;
            newcoins = goblin.coins;
        }
        else if (difficulty == 3)
        {
            newname = goblin.name;
            newhp = goblin.hp;
            newattack = goblin.attack;
            newcoins = goblin.coins;
        }
    }
    else if (gottendrop > 25 && gottendrop <= 35)
    {
        if (difficulty == 1)
        {
            skeleton.name = "Skeleton";
            newname = skeleton.name;
            skeleton.hp = 150;
            newhp = skeleton.hp;
            skeleton.attack = 15;
            newattack = skeleton.attack;
            skeleton.coins = 3;
            newcoins = skeleton.coins;
        }
        else if (difficulty == 2)
        {
            skeleton.name = "Skeleton";
            newname = skeleton.name;
            skeleton.hp = 160;
            newhp = skeleton.hp;
            skeleton.attack = 16;
            newattack = skeleton.attack;
            skeleton.coins = 3;
            newcoins = skeleton.coins;
        }
        else if (difficulty == 3)
        {
            newname = skeleton.name;
            newhp = skeleton.hp;
            newattack = skeleton.attack;
            newcoins = skeleton.coins;
        }
    }
    else if (gottendrop > 35 && gottendrop <= 50)
    {
        if (difficulty == 1)
        {
            spider.name = "Spider";
            newname = spider.name;
            spider.hp = 200;
            newhp = spider.hp;
            spider.attack = 18;
            newattack = spider.attack;
            spider.coins = 4;
            newcoins = spider.coins;
        }
        else if (difficulty == 2)
        {
            spider.name = "Spider";
            newname = spider.name;
            spider.hp = 210;
            newhp = spider.hp;
            spider.attack = 19;
            newattack = spider.attack;
            spider.coins = 4;
            newcoins = spider.coins;
        }
        else if (difficulty == 3)
        {
            newname = spider.name;
            newhp = spider.hp;
            newattack = spider.attack;
            newcoins = spider.coins;
        }
    }
    else if (gottendrop > 50 && gottendrop <= 69)
    {
        if (difficulty == 1)
        {
            zombie.name = "Zombie";
            newname = zombie.name;
            zombie.hp = 1000;
            newhp = zombie.hp;
            zombie.attack = 3;
            newattack = zombie.attack;
            zombie.coins = 0;
            newcoins = zombie.coins;
        }
        else if (difficulty == 2)
        {
            zombie.name = "Zombie";
            newname = zombie.name;
            zombie.hp = 1010;
            newhp = zombie.hp;
            zombie.attack = 4;
            newattack = zombie.attack;
            zombie.coins = 0;
            newcoins = zombie.coins;
        }
        else if (difficulty == 3)
        {
            newname = zombie.name;
            newhp = zombie.hp;
            newattack = zombie.attack;
            newcoins = zombie.coins;
        }
    }
    else if (gottendrop > 69 && gottendrop <= 79)
    {
        if (difficulty == 1)
        {
            wolf.name = "Wolf";
            newname = wolf.name;
            wolf.hp = 300;
            newhp = wolf.hp;
            wolf.attack = 25;
            newattack = wolf.attack;
            wolf.coins = 10;
            newcoins = wolf.coins;
        }
        else if (difficulty == 2)
        {
            wolf.name = "Wolf";
            newname = wolf.name;
            wolf.hp = 310;
            newhp = wolf.hp;
            wolf.attack = 26;
            newattack = wolf.attack;
            wolf.coins = 10;
            newcoins = wolf.coins;
        }
        else if (difficulty == 3)
        {
            newname = wolf.name;
            newhp = wolf.hp;
            newattack = wolf.attack;
            newcoins = wolf.coins;
        }
    }
    else if (gottendrop > 79 && gottendrop <= 89)
    {
        if (difficulty == 1)
        {
            bigbear.name = "Big Bear";
            newname = bigbear.name;
            bigbear.hp = 700;
            newhp = bigbear.hp;
            bigbear.attack = 35;
            newattack = bigbear.attack;
            bigbear.coins = 15;
            newcoins = bigbear.coins;
        }
        else if (difficulty == 2)
        {
            bigbear.name = "Big Bear";
            newname = bigbear.name;
            bigbear.hp = 710;
            newhp = bigbear.hp;
            bigbear.attack = 36;
            newattack = bigbear.attack;
            bigbear.coins = 15;
            newcoins = bigbear.coins;
        }
        else if (difficulty == 3)
        {
            newname = bigbear.name;
            newhp = bigbear.hp;
            newattack = bigbear.attack;
            newcoins = bigbear.coins;
        }
    }
    else if (gottendrop > 89 && gottendrop <= 100)
    {
        if (difficulty == 1)
        {
            dinosaur.name = "Dinosaur";
            newname = dinosaur.name;
            dinosaur.hp = 1500;
            newhp = dinosaur.hp;
            dinosaur.attack = 50;
            newattack = dinosaur.attack;
            dinosaur.coins = 50;
            newcoins = dinosaur.coins;
        }
        else if (difficulty == 2)
        {
            dinosaur.name = "Dinosaur";
            newname = dinosaur.name;
            dinosaur.hp = 1510;
            newhp = dinosaur.hp;
            dinosaur.attack = 51;
            newattack = dinosaur.attack;
            dinosaur.coins = 50;
            newcoins = dinosaur.coins;
        }
        else if (difficulty == 3)
        {
            newname = dinosaur.name;
            newhp = dinosaur.hp;
            newattack = dinosaur.attack;
            newcoins = dinosaur.coins;
        }
    }
    else if (gottendrop == 101)
    {
        if (difficulty == 1)
        {
            forestking.name = "Forest King";
            newname = forestking.name;
            forestking.hp = 15000;
            newhp = forestking.hp;
            forestking.attack = 40;
            newattack = forestking.attack;
            forestking.coins = 500;
            newcoins = forestking.coins;
        }
        else if (difficulty == 2)
        {
            forestking.name = "Forest King";
            newname = forestking.name;
            forestking.hp = 15010;
            newhp = forestking.hp;
            forestking.attack = 41;
            newattack = forestking.attack;
            forestking.coins = 500;
            newcoins = forestking.coins;
        }
        else if (difficulty == 3)
        {
            newname = forestking.name;
            newhp = forestking.hp;
            newattack = forestking.attack;
            newcoins = forestking.coins;
        }
    }
}

void bossfight(int &kills, int &gotsword, int &gotaotfk, int &level, int &xp, int &gottendrop, string &message, int &valkyriesword, int &rock, int &flesh, int &metal, int &aotfk, int &forestkingkilled, int &completedeasy, int &completedhard, int &valkyrieswordobtained, int &rockobtained, int &fleshobtained, int &metalobtained, int &aotfkobtained, int &difficulty)
{
    int newhp, newattack, newcoins;
    string newname;
    gottendrop = 101;
    default_minions(gottendrop, newhp, newattack, newcoins, newname, difficulty);
    while (newhp > 0)
    {
        newhp = newhp - me.attack;
        me.hp = me.hp - newattack;
    }
    if (me.hp > 0)
    {
        kills++;
        xp = xp + 2000;
        level = xp/1000;
        if (level == 3 && gotsword == 0)
        {
            valkyriesword++;
            gotsword = 1;
        }
        if (level == 6 && gotaotfk == 0)
        {
            aotfk++;
            gotaotfk = 1;
        }
        if (gottendrop = 101)
        {
            forestkingkilled = 1;
        }
        if (difficulty = 1)
        {
            completedeasy = 1;
        }
        if (difficulty = 2)
        {
            completedhard = 1;
        }
        cout << endl;
        cout << endl;
        cout << endl;
        message = "You defeated The Forest King and you get all his drops.";
        slowprint(message, 20);
        valkyrieswordobtained = 1;
        rockobtained = 1;
        fleshobtained = 1;
        metalobtained = 1;
        aotfkobtained = 1;
        valkyriesword++;
        rock++;
        flesh++;
        metal++;
        aotfk++;
        cout << endl;
        me.coins = me.coins + newcoins;
    }
    else
    {
        cout << endl;
        cout << endl;
        cout << endl;
        message = "YOU ARE DEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADDDDD.";
        slowprint(message, 20);
        cout << endl;
        message = "Hero, this is not the end of our journey, come back with new knowledge you have gotten and show who is the real deal here!";
        slowprint(message, 20);
        cout << endl;
    }
}

void shopmenu(string &message)
{
    cout << endl;
    cout << endl;
    cout << endl;
    message = "What are you willing to do?";
    slowprint(message, 20);
    cout << endl;
    message = "1. Buy";
    slowprint(message, 20);
    cout << endl;
    message = "2. Exit";
    slowprint(message, 20);
    cout << endl;
}

void shop(string &message, int &choice, int &gottendrop, int &valkyriesword, int &rock, int &flesh, int &metal, int &aotfk, string &dropname, int &price, int &value)
{
    int closed=0;
    while (closed!=1)
    {
        cout << endl;
        cout << endl;
        cout << endl;
        message = "Welcome, traveler. If you have the right amount of money you can buy some of my goods.";
        slowprint(message, 20);
        cout << endl;
        choice = 0;
        shopmenu(message);
        cin >> choice;
        int dissapear = 0;
        if (choice == 1)
        {
            cout << endl;
            cout << endl;
            cout << endl;
            message = "What you want?";
            slowprint(message, 20);
            cout << endl;
            message = "1. Valkyrie sword (250 coins) +50 Attack";
            slowprint(message, 20);
            cout << endl;
            message = "2. Rock (10 coins) +1 Attack";
            slowprint(message, 20);
            cout << endl;
            message = "3. Flesh (15 coins) +3 Health";
            slowprint(message, 20);
            cout << endl;
            message = "4. Metal (20 coins) +5 Health";
            slowprint(message, 20);
            cout << endl;
            message = "5. Armor of The Fire Kobras (500 coins) +100 Health";
            slowprint(message, 20);
            cout << endl;
            message = "6. +100 Health (100 coins)";
            slowprint(message, 20);
            cout << endl;
            int iwant = 0;
            cin >> iwant;
            while (dissapear != 1)
            {
                if (iwant == 1)
                {
                    gottendrop = 1;
                    drops(gottendrop, valkyriesword, rock, flesh, metal, aotfk, dropname, price, value);
                    if (me.coins >= price)
                    {
                        me.coins = me.coins - price;
                    }
                    else
                    {
                        valkyriesword--;
                    }
                    dissapear = 1;
                }
                else if (iwant == 2)
                {
                    gottendrop = 10;
                    drops(gottendrop, valkyriesword, rock, flesh, metal, aotfk, dropname, price, value);
                    if (me.coins >= price)
                    {
                        me.coins = me.coins - price;
                    }
                    else
                    {
                        rock--;
                    }
                    dissapear = 1;
                }
                else if (iwant == 3)
                {
                    gottendrop = 20;
                    drops(gottendrop, valkyriesword, rock, flesh, metal, aotfk, dropname, price, value);
                    if (me.coins >= price)
                    {
                        me.coins = me.coins - price;
                    }
                    else
                    {
                        flesh--;
                    }
                    dissapear = 1;
                }
                else if (iwant == 4)
                {
                    gottendrop = 30;
                    drops(gottendrop, valkyriesword, rock, flesh, metal, aotfk, dropname, price, value);
                    if (me.coins >= price)
                    {
                        me.coins = me.coins - price;
                    }
                    else
                    {
                        metal--;
                    }
                    dissapear = 1;
                }
                else if (iwant == 5)
                {
                    gottendrop = 31;
                    drops(gottendrop, valkyriesword, rock, flesh, metal, aotfk, dropname, price, value);
                    if (me.coins >= price)
                    {
                        me.coins = me.coins - price;
                    }
                    else
                    {
                        aotfk--;
                    }
                    dissapear = 1;
                }
                else if (iwant == 6)
                {
                    if (me.coins >= 100)
                    {
                        me.hp = me.hp + 100;
                        me.coins = me.coins - 100;
                    }
                    dissapear = 1;
                }
                else
                {
                    message = "I do not have this item, check later.";
                    slowprint(message, 20);
                    cout << endl;
                    dissapear = 1;
                }
            }
        }
        else if (choice == 2)
        {
            dissapear = 1;
            closed = 1;
        }
        else
        {
            error(message);
        }
    }
}

void myhero(int &level, int &xp, string &message, int &choice, int &gottendrop, int &valkyriesword, int &rock, int &flesh, int &metal, int &aotfk, string &dropname, int &price, int &value, int &valkyrieswordequipped, int &rockequipped, int &fleshequipped, int &metalequipped, int &aotfkequipped)
{
    cout << endl;
    cout << endl;
    cout << endl;
    message = "What you want to do?";
    slowprint(message, 20);
    cout << endl;
    message = "1. My hero";
    slowprint(message, 20);
    cout << endl;
    message = "2. Inventory";
    slowprint(message, 20);
    cout << endl;
    choice = 0;
    cin >> choice;
    int start = 0;
    while (start != 1)
    {
        if (choice == 1)
        {
            cout << endl;
            cout << "Your name: " << me.name << endl;
            cout << "HP: " << me.hp << endl;
            cout << "Attack: " << me.attack << endl;
            cout << "Coins: " << me.coins << endl;
            cout << "Level: " << level << endl;
            cout << "XP: (" << xp << " / 1000)" << endl;
            cout << endl;
            start = 1;
        }
        else if (choice == 2)
        {
            cout << endl;
            cout << endl;
            message = "What you want to do?";
            slowprint(message, 20);
            cout << endl;
            message = "1. Equip";
            slowprint(message, 20);
            cout << endl;
            message = "2. Unequip";
            slowprint(message, 20);
            cout << endl;
            message = "3. Sell";
            slowprint(message, 20);
            cout << endl;
            int take = 0;
            cin >> take;
            int starter = 0;
            while (starter != 1)
            {
                if (take == 1)
                {
                    cout << endl;
                    message = "What you want to equip?";
                    slowprint(message, 20);
                    cout << endl;
                    if (valkyriesword > 0)
                    {
                        message = "1. Valkyrie Sword (";
                        slowprint(message, 20);
                        cout << valkyriesword;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    if (rock > 0)
                    {
                        message = "2. Rock (";
                        slowprint(message, 20);
                        cout << rock;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    if (flesh > 0)
                    {
                        message = "3. Flesh (";
                        slowprint(message, 20);
                        cout << flesh;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    if (metal > 0)
                    {
                        message = "4. Metal (";
                        slowprint(message, 20);
                        cout << metal;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    if (aotfk > 0)
                    {
                        message = "5. Armor of The Fire Kobras (";
                        slowprint(message, 20);
                        cout << aotfk;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    int mymatter = 0;
                    cin >> mymatter;
                    int circle = 0;
                    while (circle != 1)
                    {
                        if (mymatter == 1)
                        {
                            if (valkyriesword > 0)
                            {
                                valkyriesword--;
                                valkyrieswordequipped++;
                                me.attack = me.attack + 50;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                        if (mymatter == 2)
                        {
                            if (rock > 0)
                            {
                                rock--;
                                rockequipped++;
                                me.attack = me.attack + 1;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                        if (mymatter == 3)
                        {
                            if (flesh > 0)
                            {
                                flesh--;
                                fleshequipped++;
                                me.hp = me.hp + 3;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                        if (mymatter == 4)
                        {
                            if (metal > 0)
                            {
                                metal--;
                                metalequipped++;
                                me.hp = me.hp + 5;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                        if (mymatter == 5)
                        {
                            if (aotfk > 0)
                            {
                                aotfk--;
                                aotfkequipped++;
                                me.hp = me.hp + 100;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                    }
                    starter = 1;
                }
                if (take == 2)
                {
                    cout << endl;
                    message = "What you want to unequip?";
                    slowprint(message, 20);
                    cout << endl;
                    if (valkyrieswordequipped > 0)
                    {
                        message = "1. Valkyrie Sword (";
                        slowprint(message, 20);
                        cout << valkyrieswordequipped;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    if (rockequipped > 0)
                    {
                        message = "2. Rock (";
                        slowprint(message, 20);
                        cout << rockequipped;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    if (fleshequipped > 0)
                    {
                        message = "3. Flesh (";
                        slowprint(message, 20);
                        cout << fleshequipped;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    if (metalequipped > 0)
                    {
                        message = "4. Metal (";
                        slowprint(message, 20);
                        cout << metalequipped;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    if (aotfkequipped > 0)
                    {
                        message = "5. Armor of The Fire Kobras (";
                        slowprint(message, 20);
                        cout << aotfkequipped;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    int mymatter = 0;
                    cin >> mymatter;
                    int circle = 0;
                    while (circle != 1)
                    {
                        if (mymatter == 1)
                        {
                            if (valkyrieswordequipped > 0)
                            {
                                valkyriesword++;
                                valkyrieswordequipped--;
                                me.attack = me.attack - 50;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                        if (mymatter == 2)
                        {
                            if (rockequipped > 0)
                            {
                                rock++;
                                rockequipped--;
                                me.attack = me.attack - 1;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                        if (mymatter == 3)
                        {
                            if (fleshequipped > 0)
                            {
                                flesh++;
                                fleshequipped--;
                                me.hp = me.hp - 3;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                        if (mymatter == 4)
                        {
                            if (metalequipped > 0)
                            {
                                metal++;
                                metalequipped--;
                                me.hp = me.hp - 5;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                        if (mymatter == 5)
                        {
                            if (aotfkequipped > 0)
                            {
                                aotfk++;
                                aotfkequipped--;
                                me.hp = me.hp - 100;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                    }
                    starter = 1;
                }
                if (take == 3)
                {
                    cout << endl;
                    message = "What you want to sell?";
                    slowprint(message, 20);
                    cout << endl;
                    if (valkyriesword > 0)
                    {
                        message = "1. Valkyrie Sword (";
                        slowprint(message, 20);
                        cout << valkyriesword;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    if (rock > 0)
                    {
                        message = "2. Rock (";
                        slowprint(message, 20);
                        cout << rock;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    if (flesh > 0)
                    {
                        message = "3. Flesh (";
                        slowprint(message, 20);
                        cout << flesh;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    if (metal > 0)
                    {
                        message = "4. Metal (";
                        slowprint(message, 20);
                        cout << metal;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    if (aotfk > 0)
                    {
                        message = "5. Armor of The Fire Kobras (";
                        slowprint(message, 20);
                        cout << aotfk;
                        message = ")";
                        slowprint(message, 20);
                        cout << endl;
                    }
                    int mymatter = 0;
                    cin >> mymatter;
                    int circle = 0;
                    while (circle != 1)
                    {
                        if (mymatter == 1)
                        {
                            if (valkyriesword > 0)
                            {
                                valkyriesword--;
                                me.coins = me.coins + 175;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                        if (mymatter == 2)
                        {
                            if (rock > 0)
                            {
                                rock--;
                                me.coins = me.coins + 5;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                        if (mymatter == 3)
                        {
                            if (flesh > 0)
                            {
                                flesh--;
                                me.coins = me.coins + 7;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                        if (mymatter == 4)
                        {
                            if (metal > 0)
                            {
                                metal--;
                                me.coins = me.coins + 10;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                        if (mymatter == 5)
                        {
                            if (aotfk > 0)
                            {
                                aotfk--;
                                me.coins = me.coins + 250;
                            }
                            else
                            {
                                error(message);
                            }
                            circle = 1;
                        }
                    }
                    starter = 1;
                }
            }
            start = 1;
        }
        else
        {
            error(message);
        }
    }
}

void fight(int &kills, int &gotsword, int &gotaotfk, int &level, int &xp, int &gottendrop, string &message, int &valkyriesword, int &rock, int &flesh, int &metal, int &aotfk, int &price, int &value, string &dropname, int &goblinkilled, int &skeletonkilled, int &spiderkilled, int &zombiekilled, int &wolfkilled, int &bigbearkilled, int &dinosaurkilled, int &valkyrieswordobtained, int &rockobtained, int &fleshobtained, int &metalobtained, int &aotfkobtained, int &nothingobtained, int &difficulty)
{
    int newhp, newattack, newcoins;
    string newname;
    gottendrop = randomdrop();
    default_minions(gottendrop, newhp, newattack, newcoins, newname, difficulty);
    while (newhp > 0)
    {
        newhp = newhp - me.attack;
        me.hp = me.hp - newattack;
    }
    if (me.hp > 0)
    {
        kills++;
        if (gottendrop <= 25)
        {
            goblinkilled = 1;
            xp = xp + 50;
        }
        if (gottendrop > 25 && gottendrop <= 35)
        {
            skeletonkilled = 1;
            xp = xp + 70;
        }
        if (gottendrop > 35 && gottendrop <= 50)
        {
            spiderkilled = 1;
            xp = xp + 100;
        }
        if (gottendrop > 50 && gottendrop <= 69)
        {
            zombiekilled = 1;
            xp = xp + 120;
        }
        if (gottendrop > 69 && gottendrop <= 79)
        {
            wolfkilled = 1;
            xp = xp + 150;
        }
        if (gottendrop > 79 && gottendrop <= 89)
        {
            bigbearkilled = 1;
            xp = xp + 170;
        }
        if (gottendrop > 89 && gottendrop <= 100)
        {
            dinosaurkilled = 1;
            xp = xp + 200;
        }
        level = xp/1000;
        if (level == 3 && gotsword == 0)
        {
            valkyriesword++;
            gotsword = 1;
        }
        if (level == 6 && gotaotfk == 0)
        {
            aotfk++;
            gotaotfk = 1;
        }
        cout << endl;
        cout << endl;
        cout << endl;
        message = "You defeated ";
        slowprint(message, 20);
        message = newname;
        slowprint(message, 20);
        message = " , he has dropped ";
        slowprint(message, 20);
        gottendrop = randomdrop();
        if (gottendrop <= 1)
        {
            valkyrieswordobtained = 1;
        }
        if (gottendrop > 1 && gottendrop <= 10)
        {
            rockobtained = 1;
        }
        if (gottendrop > 10 && gottendrop <= 20)
        {
            fleshobtained = 1;
        }
        if (gottendrop > 20 && gottendrop <= 30)
        {
            metalobtained = 1;
        }
        if (gottendrop > 30 && gottendrop <= 31)
        {
            aotfkobtained = 1;
        }
        if (gottendrop > 31 && gottendrop <= 100)
        {
            nothingobtained = 1;
        }
        drops(gottendrop, valkyriesword, rock, flesh, metal, aotfk, dropname, price, value);
        cout << dropname;
        cout << endl;
        me.coins = me.coins + newcoins;
    }
    else
    {
        cout << endl;
        cout << endl;
        cout << endl;
        message = "YOU ARE DEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADDDDD.";
        slowprint(message, 20);
        cout << endl;
        message = "Hero, this is not the end of our journey, come back with new knowledge you have gotten and show who is the real deal here!";
        slowprint(message, 20);
        cout << endl;
    }
}

void achievements(int &showme, string &message, int &counting, int &goblinkilled, int &skeletonkilled, int &spiderkilled, int &zombiekilled, int &wolfkilled, int &bigbearkilled, int &dinosaurkilled, int &forestkingkilled, int &completedeasy, int &completedhard, int &valkyrieswordobtained, int &rockobtained, int &fleshobtained, int &metalobtained, int &aotfkobtained, int &nothingobtained)
{
    cout << endl;
    if (goblinkilled == 1)
    {
        if (showme == 1)
        {
        message = "You have killed a Goblin";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (skeletonkilled == 1)
    {
        if (showme == 1)
        {
        message = "You have killed a Skeleton";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (spiderkilled == 1)
    {
        if (showme == 1)
        {
        message = "You have killed a Spider";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (zombiekilled == 1)
    {
        if (showme == 1)
        {
        message = "You have killed a Zombie";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (wolfkilled == 1)
    {
        if (showme == 1)
        {
        message = "You have killed a Wolf";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (bigbearkilled == 1)
    {
        if (showme == 1)
        {
        message = "You have killed a Big Bear";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (dinosaurkilled == 1)
    {
        if (showme == 1)
        {
        message = "You have killed a Dinosaur";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (forestkingkilled == 1)
    {
        if (showme == 1)
        {
        message = "You have killed a The Forest King";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (completedeasy == 1)
    {
        if (showme == 1)
        {
        message = "You have completed the game in Easy Mode";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (completedhard == 1)
    {
        if (showme == 1)
        {
        message = "You have completed the game in Hard Mode";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (valkyrieswordobtained == 1)
    {
        if (showme == 1)
        {
        message = "You have obtained a Valkyrie Sword";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (rockobtained == 1)
    {
        if (showme == 1)
        {
        message = "You have obtained a Rock";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (fleshobtained == 1)
    {
        if (showme == 1)
        {
        message = "You have obtained a Flesh";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (metalobtained == 1)
    {
        if (showme == 1)
        {
        message = "You have obtained a Metal";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (aotfkobtained == 1)
    {
        if (showme == 1)
        {
        message = "You have obtained an Armor of The Fire Kobras";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (nothingobtained == 1)
    {
        if (showme == 1)
        {
        message = "You have obtained a Nothing";
        slowprint(message, 20);
        cout << endl;
        }
        showme = 0;
        counting++;
    }
    if (showme == 1)
    {
    message = "You have completed ";
    slowprint(message, 20);
    cout << counting << "/16";
    message = " achievements.";
    slowprint(message, 20);
    cout << endl;
    }
    showme = 0;
}

void howhard(int &difficulty, string &message)
{
    cout << endl;
    message = "How tough you are?";
    slowprint(message, 20);
    cout << endl;
    message = "1. Easy";
    slowprint(message, 20);
    cout << endl;
    message = "2. Hard";
    slowprint(message, 20);
    cout << endl;
    message = "3. Custom";
    slowprint(message, 20);
    cout << endl;
    int itake = 0;
    int forever = 0;
    while (forever != 1)
    {
        cin >> itake;
        if (itake == 1)
        {
            difficulty = 1;
            forever = 1;
        }
        else if (itake == 2)
        {
            difficulty = 2;
            forever = 1;
        }
        else if (itake == 3)
        {
            difficulty = 3;
            forever = 1;
            cout << endl;
            cout << endl;
            message = "Increase or decrease minions attack by: ";
            slowprint(message, 20);
            int value = 0;
            cin >> value;
            goblin.attack = 10;
            skeleton.attack = 15;
            spider.attack = 18;
            zombie.attack = 3;
            wolf.attack = 25;
            bigbear.attack = 35;
            dinosaur.attack = 50;
            forestking.attack = 45;
            goblin.attack = goblin.attack + (value);
            skeleton.attack = skeleton.attack + (value);
            spider.attack = spider.attack + (value);
            zombie.attack = zombie.attack + (value);
            wolf.attack = wolf.attack + (value);
            bigbear.attack = bigbear.attack + (value);
            dinosaur.attack = dinosaur.attack + (value);
            forestking.attack = forestking.attack + (value);
            cout << endl;
            cout << endl;
            message = "Increase or decrease minions hp by: ";
            slowprint(message, 20);
            cin >> value;
            goblin.hp = 100;
            skeleton.hp = 150;
            spider.hp = 200;
            zombie.hp = 1000;
            wolf.hp = 300;
            bigbear.hp = 700;
            dinosaur.hp = 1500;
            forestking.hp = 15000;
            goblin.hp = goblin.hp + (value);
            skeleton.hp = skeleton.hp + (value);
            spider.hp = spider.hp + (value);
            zombie.hp = zombie.hp + (value);
            wolf.hp = wolf.hp + (value);
            bigbear.hp = bigbear.hp + (value);
            dinosaur.hp = dinosaur.hp + (value);
            forestking.hp = forestking.hp + (value);
            cout << endl;
            cout << endl;
            message = "Increase or decrease minions coins by: ";
            slowprint(message, 20);
            goblin.coins = 1;
            skeleton.coins = 3;
            spider.coins = 4;
            zombie.coins = 0;
            wolf.coins = 10;
            bigbear.coins = 15;
            dinosaur.coins = 50;
            forestking.coins = 500;
            goblin.coins = goblin.coins + (value);
            skeleton.coins = skeleton.coins + (value);
            spider.coins = spider.coins + (value);
            zombie.coins = zombie.coins + (value);
            wolf.coins = wolf.coins + (value);
            bigbear.coins = bigbear.coins + (value);
            dinosaur.coins = dinosaur.coins + (value);
            forestking.coins = forestking.coins + (value);
            cout << endl;
            cout << endl;
        }
        else
        {
            error(message);
        }
    }
}

void ratings(string &message, int &alreadysaved, int &taken, int &kills, int &xp, int &counting, int &showme, int &goblinkilled, int &skeletonkilled, int &spiderkilled, int &zombiekilled, int &wolfkilled, int &bigbearkilled, int &dinosaurkilled, int &forestkingkilled, int &completedeasy, int &completedhard, int &valkyrieswordobtained, int &rockobtained, int &fleshobtained, int &metalobtained, int &aotfkobtained, int &nothingobtained)
{
    achievements(showme, message, counting, goblinkilled, skeletonkilled, spiderkilled, zombiekilled, wolfkilled, bigbearkilled, dinosaurkilled, forestkingkilled, completedeasy, completedhard, valkyrieswordobtained, rockobtained, fleshobtained, metalobtained, aotfkobtained, nothingobtained);
    int n;
    ifstream ifnumber("n.txt");
    ifnumber >> n;
    if (alreadysaved == 1)
    {
        ofstream ofresults("results.txt", ios::app);
        ofresults << n << endl;
        ofresults << kills << endl;
        ofresults << xp << endl;
        ofresults << counting << endl;
    }
    int kint = 0;
    ifstream ifresults ("results.txt");
    int nown[n], nowkills[n], nowxp[n], nowcounting[n];
    while (kint != n)
    {
        ifresults >> nown[kint];
        ifresults >> nowkills[kint];
        ifresults >> nowxp[kint];
        ifresults >> nowcounting[kint];
        kint++;
    }
    if (taken == 1) // KILLS
    {
        int kintkint = 0;
        int i, j;
        for (i = 0; i < n-1; i++)
        {
            for (j = 0; j < n-i-1; j++)
            {
                if (nowkills[j] < nowkills[j+1])
                {
                    swap(nowkills[j], nowkills[j+1]);
                    swap(nown[j], nown[j+1]);
                    swap(nowxp[j], nowxp[j+1]);
                    swap(nowcounting[j], nowcounting[j+1]);
                }
            }
        }
        remove("output.html");
        ofstream galutinis("output.html", ios::app);
        galutinis << "<!DOCTYPE html>" << endl;
        galutinis << "<html>" << endl;
        galutinis << "<head>" << endl;
        galutinis << "<style>" << endl;
        galutinis << " " << endl;
        galutinis << "html{" << endl;
        galutinis << "background: url('https://image.ibb.co/cH625y/fonas.jpg') no-repeat center center" << endl;
        galutinis << "fixed;" << endl;
        galutinis << "-webkit-background-size: cover;" << endl;
        galutinis << "-moz-background-size: cover;" << endl;
        galutinis << "-o-background-size: cover;" << endl;
        galutinis << "background-size: cover;" << endl;
        galutinis << "}" << endl;
        galutinis << "table {" << endl;
        galutinis << "font-family: arial, sans-serif;" << endl;
        galutinis << "border-collapse: collapse;" << endl;
        galutinis << "width: 100%;" << endl;
        galutinis << "}" << endl;
        galutinis << " " << endl;
        galutinis << "td, th {" << endl;
        galutinis << "border: 1px solid #dddddd;" << endl;
        galutinis << "text-align: left;" << endl;
        galutinis << "padding: 8px;" << endl;
        galutinis << "font-size: 30px;" << endl;
        galutinis << "font-weight: bold;" << endl;
        galutinis << " " << endl;
        galutinis << "}" << endl;
        galutinis << " " << endl;
        galutinis << "tr:nth-child(even) {" << endl;
        galutinis << "background-color: #dddddd;" << endl;
        galutinis << "opacity: 0.6;" << endl;
        galutinis << "}" << endl;
        galutinis << " " << endl;
        galutinis << "tr:nth-child(odd) {" << endl;
        galutinis << "background-color: red;" << endl;
        galutinis << "opacity: 0.6;" << endl;
        galutinis << "}" << endl;
        galutinis << " " << endl;
        galutinis << "</style>" << endl;
        galutinis << "</head>" << endl;
        galutinis << "<body>" << endl;
        galutinis << " " << endl;
        galutinis << "<h1 align=\"center\" style=\"color:white\">WORLD OF WORDS TOP 100 SCOREBOARD</h2>" << endl;
        galutinis << " " << endl;
        galutinis << "<table style=\"width:600px\" align=\"center\">" << endl;
        galutinis << "<tr>" << endl;
        galutinis << "<th>Player</th>" << endl;
        galutinis << "<th>Kills</th>" << endl;
        galutinis << "<th>Experience</th>" << endl;
        galutinis << "<th>Achievments</th>" << endl;
        galutinis << "</tr>" << endl;
        while (kintkint != n)
        {
            galutinis << "<tr>" << endl;
            galutinis << "<td>Player " << nown[kintkint] << "</td>" << endl;
            galutinis << "<td>" << nowkills[kintkint] << "</td>" << endl;
            galutinis << "<td>" << nowxp[kintkint] << "</td>" << endl;
            galutinis << "<td>" << nowcounting[kintkint] << "</td>" << endl;
            galutinis << "</tr>" << endl;
            kintkint++;
        }
    }
    else if (taken == 2) // XP
    {
        int kintkint = 0;
        int i, j;
        for (i = 0; i < n-1; i++)
        {
            for (j = 0; j < n-i-1; j++)
            {
                if (nowxp[j] < nowxp[j+1])
                {
                    swap(nowkills[j], nowkills[j+1]);
                    swap(nown[j], nown[j+1]);
                    swap(nowxp[j], nowxp[j+1]);
                    swap(nowcounting[j], nowcounting[j+1]);
                }
            }
        }
        remove("output.html");
        ofstream galutinis("output.html", ios::app);
        galutinis << "<!DOCTYPE html>" << endl;
        galutinis << "<html>" << endl;
        galutinis << "<head>" << endl;
        galutinis << "<style>" << endl;
        galutinis << " " << endl;
        galutinis << "html{" << endl;
        galutinis << "background: url('https://image.ibb.co/cH625y/fonas.jpg') no-repeat center center" << endl;
        galutinis << "fixed;" << endl;
        galutinis << "-webkit-background-size: cover;" << endl;
        galutinis << "-moz-background-size: cover;" << endl;
        galutinis << "-o-background-size: cover;" << endl;
        galutinis << "background-size: cover;" << endl;
        galutinis << "}" << endl;
        galutinis << "table {" << endl;
        galutinis << "font-family: arial, sans-serif;" << endl;
        galutinis << "border-collapse: collapse;" << endl;
        galutinis << "width: 100%;" << endl;
        galutinis << "}" << endl;
        galutinis << " " << endl;
        galutinis << "td, th {" << endl;
        galutinis << "border: 1px solid #dddddd;" << endl;
        galutinis << "text-align: left;" << endl;
        galutinis << "padding: 8px;" << endl;
        galutinis << "font-size: 30px;" << endl;
        galutinis << "font-weight: bold;" << endl;
        galutinis << " " << endl;
        galutinis << "}" << endl;
        galutinis << " " << endl;
        galutinis << "tr:nth-child(even) {" << endl;
        galutinis << "background-color: #dddddd;" << endl;
        galutinis << "opacity: 0.6;" << endl;
        galutinis << "}" << endl;
        galutinis << " " << endl;
        galutinis << "tr:nth-child(odd) {" << endl;
        galutinis << "background-color: red;" << endl;
        galutinis << "opacity: 0.6;" << endl;
        galutinis << "}" << endl;
        galutinis << " " << endl;
        galutinis << "</style>" << endl;
        galutinis << "</head>" << endl;
        galutinis << "<body>" << endl;
        galutinis << " " << endl;
        galutinis << "<h1 align=\"center\" style=\"color:white\">WORLD OF WORDS TOP 100 SCOREBOARD</h2>" << endl;
        galutinis << " " << endl;
        galutinis << "<table style=\"width:600px\" align=\"center\">" << endl;
        galutinis << "<tr>" << endl;
        galutinis << "<th>Player</th>" << endl;
        galutinis << "<th>Kills</th>" << endl;
        galutinis << "<th>Experience</th>" << endl;
        galutinis << "<th>Achievments</th>" << endl;
        galutinis << "</tr>" << endl;
        while (kintkint != n)
        {
            galutinis << "<tr>" << endl;
            galutinis << "<td>Player " << nown[kintkint] << "</td>" << endl;
            galutinis << "<td>" << nowkills[kintkint] << "</td>" << endl;
            galutinis << "<td>" << nowxp[kintkint] << "</td>" << endl;
            galutinis << "<td>" << nowcounting[kintkint] << "</td>" << endl;
            galutinis << "</tr>" << endl;
            kintkint++;
        }
    }
    else if (taken == 3) //COUNTING
    {
        int kintkint = 0;
        int i, j;
        for (i = 0; i < n-1; i++)
        {
            for (j = 0; j < n-i-1; j++)
            {
                if (nowcounting[j] < nowcounting[j+1])
                {
                    swap(nowkills[j], nowkills[j+1]);
                    swap(nown[j], nown[j+1]);
                    swap(nowxp[j], nowxp[j+1]);
                    swap(nowcounting[j], nowcounting[j+1]);
                }
            }
        }
        remove("output.html");
        ofstream galutinis("output.html", ios::app);
        galutinis << "<!DOCTYPE html>" << endl;
        galutinis << "<html>" << endl;
        galutinis << "<head>" << endl;
        galutinis << "<style>" << endl;
        galutinis << " " << endl;
        galutinis << "html{" << endl;
        galutinis << "background: url('https://image.ibb.co/cH625y/fonas.jpg') no-repeat center center" << endl;
        galutinis << "fixed;" << endl;
        galutinis << "-webkit-background-size: cover;" << endl;
        galutinis << "-moz-background-size: cover;" << endl;
        galutinis << "-o-background-size: cover;" << endl;
        galutinis << "background-size: cover;" << endl;
        galutinis << "}" << endl;
        galutinis << "table {" << endl;
        galutinis << "font-family: arial, sans-serif;" << endl;
        galutinis << "border-collapse: collapse;" << endl;
        galutinis << "width: 100%;" << endl;
        galutinis << "}" << endl;
        galutinis << " " << endl;
        galutinis << "td, th {" << endl;
        galutinis << "border: 1px solid #dddddd;" << endl;
        galutinis << "text-align: left;" << endl;
        galutinis << "padding: 8px;" << endl;
        galutinis << "font-size: 30px;" << endl;
        galutinis << "font-weight: bold;" << endl;
        galutinis << " " << endl;
        galutinis << "}" << endl;
        galutinis << " " << endl;
        galutinis << "tr:nth-child(even) {" << endl;
        galutinis << "background-color: #dddddd;" << endl;
        galutinis << "opacity: 0.6;" << endl;
        galutinis << "}" << endl;
        galutinis << " " << endl;
        galutinis << "tr:nth-child(odd) {" << endl;
        galutinis << "background-color: red;" << endl;
        galutinis << "opacity: 0.6;" << endl;
        galutinis << "}" << endl;
        galutinis << " " << endl;
        galutinis << "</style>" << endl;
        galutinis << "</head>" << endl;
        galutinis << "<body>" << endl;
        galutinis << " " << endl;
        galutinis << "<h1 align=\"center\" style=\"color:white\">WORLD OF WORDS TOP 100 SCOREBOARD</h2>" << endl;
        galutinis << " " << endl;
        galutinis << "<table style=\"width:600px\" align=\"center\">" << endl;
        galutinis << "<tr>" << endl;
        galutinis << "<th>Player</th>" << endl;
        galutinis << "<th>Kills</th>" << endl;
        galutinis << "<th>Experience</th>" << endl;
        galutinis << "<th>Achievments</th>" << endl;
        galutinis << "</tr>" << endl;
        while (kintkint != n)
        {
            galutinis << "<tr>" << endl;
            galutinis << "<td>Player " << nown[kintkint] << "</td>" << endl;
            galutinis << "<td>" << nowkills[kintkint] << "</td>" << endl;
            galutinis << "<td>" << nowxp[kintkint] << "</td>" << endl;
            galutinis << "<td>" << nowcounting[kintkint] << "</td>" << endl;
            galutinis << "</tr>" << endl;
            kintkint++;
        }
    }
    else
    {
        error(message);
    }
    n++;
    ofstream ofnumber("n.txt");
    ofnumber << n;
}

int main()
{
    int exit = 0;
    int exitt = 0;
    while (exit != 1)
    {
        string dropname = "Nothing";
        int gottendrop = 0;
        int taken = 0;
        int alreadysaved = 0;
        int kills = 0;
        int counting = 0;
        int xp = 1000;
        int level = 0;
        int gotsword = 0;
        int gotaotfk = 0;
        int goblinkilled = 0;
        int difficulty = 0;
        int skeletonkilled = 0;
        int spiderkilled = 0;
        int zombiekilled = 0;
        int wolfkilled = 0;
        int bigbearkilled = 0;
        int dinosaurkilled = 0;
        int forestkingkilled = 0;
        int completedeasy = 0;
        int completedhard = 0;
        int valkyrieswordobtained = 0;
        int rockobtained = 0;
        int fleshobtained = 0;
        int metalobtained = 0;
        int aotfkobtained = 0;
        int nothingobtained = 0;
        int valkyriesword = 0;
        int rock = 0;
        int showme = 0;
        int flesh = 0;
        int metal = 0;
        int aotfk = 0;
        int valkyrieswordequipped = 0;
        int rockequipped = 0;
        int fleshequipped = 0;
        int metalequipped = 0;
        int aotfkequipped = 0;
        int value = 0;
        int price = 0;
        int nothing;
        int ok = 0;
        int myclass;
        string message;
        meniu(message);
        int choice = 0;
        while (ok != 1)
        {
            cin >> choice;
            if (choice == 1)
            {
                startgame(message);
                cin >> myclass;
                if (myclass == 1 || myclass == 2 || myclass == 3)
                {
                    ok=1;
                }
                else
                {
                    error(message);
                }
            }
            else if (choice == 2)
            {
                help(message);
                cout << endl;
            }
            else if (choice == 3)
            {
                exit = 1;
                ok = 1;
            }
            else
            {
                error(message);
            }
        }
        int okk;
        if (exit == 1)
        {
            okk = 1;
        }
        else okk = 0;
        while (okk != 1)
        {
            int okkk = 0;
            if (myclass == 1)
            {
                me.name="Warrior";
                me.hp=10000;
                me.attack=50;
                me.coins=0;
            }
            if (myclass == 2)
            {
                me.name="Mage";
                me.hp=8000;
                me.attack=70;
                me.coins=0;
            }
            if (myclass == 3)
            {
                me.name="Priest";
                me.hp=12000;
                me.attack=30;
                me.coins=0;
            }
            howhard(difficulty, message);
            while (okkk!=1)
            {
                if (me.hp > 0)
                {
                    meniu2(message);
                    cin >> choice;
                    if (choice == 1)
                    {
                        fight(kills, gotsword, gotaotfk, level, xp, gottendrop, message, valkyriesword, rock, flesh, metal, aotfk, price, value, dropname, goblinkilled, skeletonkilled, spiderkilled, zombiekilled, wolfkilled, bigbearkilled, dinosaurkilled, valkyrieswordobtained, rockobtained, fleshobtained, metalobtained, aotfkobtained, nothingobtained, difficulty);
                    }
                    else if (choice == 2)
                    {
                        bossfight(kills, gotsword, gotaotfk, level, xp, gottendrop, message, valkyriesword, rock, flesh, metal, aotfk, forestkingkilled, completedeasy, completedhard, valkyrieswordobtained, rockobtained, fleshobtained, metalobtained, aotfkobtained, difficulty);
                    }
                    else if (choice == 3)
                    {
                        shop(message, choice, gottendrop, valkyriesword, rock, flesh, metal, aotfk, dropname, price, value);
                    }
                    else if (choice == 4)
                    {
                        myhero(level, xp, message, choice, gottendrop, valkyriesword, rock, flesh, metal, aotfk, dropname, price, value, valkyrieswordequipped, rockequipped, fleshequipped, metalequipped, aotfkequipped);
                    }
                    else if (choice == 5)
                    {
                        showme = 1;
                        achievements(showme, message, counting, goblinkilled, skeletonkilled, spiderkilled, zombiekilled, wolfkilled, bigbearkilled, dinosaurkilled, forestkingkilled, completedeasy, completedhard, valkyrieswordobtained, rockobtained, fleshobtained, metalobtained, aotfkobtained, nothingobtained);
                    }
                    else if (choice == 6)
                    {
                        message = "Are you sure Hero? Your whole run will be destroyed!";
                        slowprint(message, 20);
                        cout << endl;
                        message = "1. Continue";
                        slowprint(message, 20);
                        cout << endl;
                        message = "2. Exit";
                        slowprint(message, 20);
                        cout << endl;
                        int what = 0;
                        cin >> what;
                        int boomboom = 0;
                        while (boomboom != 1)
                        {
                        if (what == 1)
                        {
                            continue;
                            boomboom = 1;
                        }
                        else if (what == 2)
                        {
                            ok = 1;
                            okk = 1;
                            okkk = 1;
                            boomboom = 1;
                            int giveme = 0;
                cout << endl;
                cout << endl;
                cout << endl;
                message = "Do you want to save your run?";
                slowprint(message, 20);
                cout << endl;
                message = "1. Yes";
                slowprint(message, 20);
                cout << endl;
                message = "2. No";
                slowprint(message, 20);
                cout << endl;
                cin >> giveme;
                int circular = 0;
                while (circular != 1)
                {
                    if (giveme == 1)
                    {
                        alreadysaved = 1;
                        circular = 1;
                    }
                    else if (giveme == 2)
                    {
                        circular = 1;
                    }
                    else
                    {
                        error(message);
                    }
                }
                circular = 0;
                giveme = 0;
                cout << endl;
                cout << endl;
                message = "Do you want to see Top 100?";
                slowprint(message, 20);
                cout << endl;
                message = "1. Yes, Top 100 by Kills";
                slowprint(message, 20);
                cout << endl;
                message = "2. Yes, Top 100 by XP";
                slowprint(message, 20);
                cout << endl;
                message = "3. Yes, Top 100 by Achievements";
                slowprint(message, 20);
                cout << endl;
                message = "4. No";
                slowprint(message, 20);
                cout << endl;
                cin >> giveme;
                while (circular != 1)
                {
                    if (giveme == 1)
                    {
                        taken = 1;
                        ratings(message, alreadysaved, taken, kills, xp, counting, showme, goblinkilled, skeletonkilled, spiderkilled, zombiekilled, wolfkilled, bigbearkilled, dinosaurkilled, forestkingkilled, completedeasy, completedhard, valkyrieswordobtained, rockobtained, fleshobtained, metalobtained, aotfkobtained, nothingobtained);
                        message = "Top 100 is saved to: \"output.html\"";
                        slowprint(message, 20);
                        cout << endl;
                        circular = 1;
                    }
                    else if (giveme == 2)
                    {
                        taken = 2;
                        ratings(message, alreadysaved, taken, kills, xp, counting, showme, goblinkilled, skeletonkilled, spiderkilled, zombiekilled, wolfkilled, bigbearkilled, dinosaurkilled, forestkingkilled, completedeasy, completedhard, valkyrieswordobtained, rockobtained, fleshobtained, metalobtained, aotfkobtained, nothingobtained);
                        message = "Top 100 is saved to: \"output.html\"";
                        slowprint(message, 20);
                        cout << endl;
                        circular = 1;
                    }
                    else if (giveme == 3)
                    {
                        taken = 3;
                        ratings(message, alreadysaved, taken, kills, xp, counting, showme, goblinkilled, skeletonkilled, spiderkilled, zombiekilled, wolfkilled, bigbearkilled, dinosaurkilled, forestkingkilled, completedeasy, completedhard, valkyrieswordobtained, rockobtained, fleshobtained, metalobtained, aotfkobtained, nothingobtained);
                        message = "Top 100 is saved to: \"output.html\"";
                        slowprint(message, 20);
                        cout << endl;
                        circular = 1;
                    }
                    else if (giveme == 4)
                    {
                        circular = 1;
                    }
                    else
                    {
                        error(message);
                    }
                }
                        }
                        else
                        {
                            error(message);
                        }
                        }
                    }
                }
                else
                {
                    okk = 1;
                    ok = 1;
                    okk = 1;
                }
            }
        }
    }
    return 0;
}
