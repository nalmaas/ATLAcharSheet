//NEED TO ADD WEAPONS AT SOME POINT
//I can store all of the scrolls for each class in various documents corresponding to each variable and then copy them line by line into an array at the start of the character creator. 
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

int userAnswer;
int count;
string inputWait;
bool valid = false;
int condition;
string tempString;
int partyMax = 100;
int alliesMax = 100;
int notesMax = 100;
int featureMax = 4;
int inventoryMax = 100;
int scrollMax = 14;
int weaponMax = 100;


int allScrollNumber = 98;
string allScrollNames[98];
string allScrollDescriptions[98];
int allScrollDiceTypes[98];
int allScrollDiceCounts[98];
string allScrollRanges[98];
string allScrollActions[98];
string allScrollTypes[98];
int allScrollTiers[98];
bool allScrollPractices[98];
bool allScrollHavePractices[98];

//if you ever update these Max values make sure to change the corresponding array lengths

struct characterInfo{
    string playerName;
    string playerStyle;
    string playerPath;
    int playerTier;
    string playerOutward;
    string playerInward;
    string playerBackground;
    string playerVariant;
    string playerRole;

    int playerProficiencyBonus;

    int playerStaminaMax;
    int playerStamina;
    int playerHealthMax;
    int playerHealth;
    int playerFortitudeMax;
    int playerFortitude;

    int playerSpiritBond;

    int playerPower;
    int playerFinesse;
    int playerVitality;
    int playerKnowledge;
    int playerReason;
    int playerCharacter;

    bool powerSave;
    bool finesseSave;
    bool vitalitySave;
    bool knowledgeSave;
    bool reasonSave;
    bool characterSave;

    int powerMod;
    int finesseMod;
    int vitalityMod;
    int knowledgeMod;
    int reasonMod;
    int characterMod;

    int powerSaveMod;
    int finesseSaveMod;
    int vitalitySaveMod;
    int knowledgeSaveMod;
    int reasonSaveMod;
    int characterSaveMod;

    string playerParty[100];
    int partyCount;
    string playerAllies[100];
    int alliesCount;
    string playerNotes[100];
    int notesCount;

    string featureName[4];
    string featureDescription[4];
    int featureCount;

    string playerInventory[100];
    int inventoryCount;
    int inventoryAmount[100];

    int playerCopper;
    int playerSilver;
    int playerGold;

    string scrollName[14];
    string scrollDescription[14];
    int scrollDiceType[14];
    int scrollDiceCount[14];
    string scrollRange[14];
    string scrollAction[14];
    string scrollType[14];
    int scrollTier[14];
    bool scrollPractice[14];
    bool scrollHavePractice[14];
    int scrollCount;

    int scrollChoices[14];

    string weaponName[100];
    string weaponDescription[100];
    int weaponDiceCount[100];
    int weaponDiceType[100];
    int weaponCount;

    bool athleticsProf;
    int athleticsMod;
    bool acrobaticsProf;
    int acrobaticsMod;
    bool escamotageProf;
    int escamotageMod;
    bool stealthProf;
    int stealthMod;
    bool willpowerProf;
    int willpowerMod;
    bool historyProf;
    int historyMod;
    bool investigationProf;
    int investigationMod;
    bool natureProf;
    int natureMod;
    bool seafaringProf;
    int seafaringMod;
    bool spiritProf;
    int spiritMod;
    bool tamingProf;
    int tamingMod;
    bool huntingProf;
    int huntingMod;
    bool insightProf;
    int insightMod;
    bool medicineProf;
    int medicineMod;
    bool perceptionProf;
    int perceptionMod;
    bool deceptionProf;
    int deceptionMod;
    bool intimidationProf;
    int intimidationMod;
    bool performanceProf;
    int performanceMod;
    bool persuasionProf;
    int persuasionMod;
};


/*struct scroll{
    string name;
    string description;
    int diceType;
    int diceCount;
    int tier;
};*/


//old
//5,5,6,3 (bender)
//6,3,6,3 (non-bender)

//new
//5,6,6,3 (bender)

characterInfo createCharacter();
characterInfo loadCharacter();
int characterSheet(characterInfo player);
int diceRoll(int diceType, int diceCount, int diceMod);
int statRoll(int statMod, string stat);
int scrollRoll(int diceType, int diceCount, int diceMod, string description, string name);
//int changeLine(string filePath, string fileBackup, string lineCount,  string replacement, int userChoice);

int main(){
//setting up random number generator
    //cout << floor((7 - 10) / 2) << endl;
    srand (time(NULL));
    //diceRoll(20, 1, -20);

    ifstream extracting;
    extracting.open("Scrolls/name.txt", std::ifstream::in);
    cout << "working\n";
    count = 0;
    while(!extracting.eof()){
        getline(extracting, allScrollNames[count]);
        cout << allScrollNames[count] << endl;
        count = count + 1;
    }
    extracting.close();
/*
    extracting.open("Scrolls/description.txt", std::ifstream::in); 
    count = 0;
    while(!extracting.eof()){
        getline(extracting, allScrollDescriptions[count]);
        count = count + 1;
    }
    extracting.close();

    extracting.open("Scrolls/diceType.txt", std::ifstream::in); 
    count = 0;
    while(!extracting.eof()){
        extracting >> allScrollDiceTypes[count];
        cout << allScrollDiceTypes[count] << endl;
        count = count + 1;
    }
    extracting.close();

    extracting.open("Scrolls/diceCount.txt", std::ifstream::in); 
    count = 0;
    while(!extracting.eof()){
        extracting >> allScrollDiceCounts[count];
        count = count + 1;
    }
    extracting.close();

    extracting.open("Scrolls/range.txt", std::ifstream::in); 
    count = 0;
    while(!extracting.eof()){
        getline(extracting, allScrollRanges[count]);
        count = count + 1;
    }
    extracting.close();

    extracting.open("Scrolls/action.txt", std::ifstream::in); 
    count = 0;
    while(!extracting.eof()){
        getline(extracting, allScrollActions[count]);
        count = count + 1;
    }
    extracting.close();

    extracting.open("Scrolls/type.txt", std::ifstream::in); 
    count = 0;
    while(!extracting.eof()){
        getline(extracting, allScrollTypes[count]);
        count = count + 1;
    }
    extracting.close();

    extracting.open("Scrolls/tier.txt", std::ifstream::in); 
    count = 0;
    while(!extracting.eof()){
        extracting >> allScrollTiers[count];
        count = count + 1;
    }
    extracting.close();

    extracting.open("Scrolls/practice.txt", std::ifstream::in); 
    count = 0;
    while(!extracting.eof()){
        extracting >> allScrollPractices[count];
        cout << allScrollPractices[count] << endl;
        count = count + 1;
    }
    extracting.close();

    extracting.open("Scrolls/havePractice.txt", std::ifstream::in); 
    count = 0;
    while(!extracting.eof()){
        extracting >> allScrollHavePractices[count];
        count = count + 1;
    }
    extracting.close();*/






    characterInfo characterData;
    while( condition == 0 ) {
        //cout << "What would you like to do?\n1. Create a new character\n2. Use the currently existing character\n3. Quit\n";
        //cin >> userAnswer;
        valid = false;
        while(!valid){
            cout << "What would you like to do?\n1. Create a new character\n2. Use the currently existing character\n3. Quit\n";
            valid = true;
            cin >> userAnswer;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "Please enter a number (especially you, Michael)\n";
                valid = false;
            }
        }
        switch(userAnswer){
            case 1:
                createCharacter();
                characterData = loadCharacter();
                characterSheet(characterData);
                condition = 1;
                break;
            case 2:
                characterData = loadCharacter();
                characterSheet(characterData);
                //cout << "something " << characterData.playerAllies[0] << " something else" << endl;
                condition = 1;
                break;
            case 3:
                return 0;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
	return 0;
};

characterInfo createCharacter(){
    characterInfo player;    
    ofstream data;
    cout << "Welcome to the character creator! Just follow the instructions to create your character. Don't worry if you input something incorrectly. You can go back and change it later so just continue filling in everything else." << endl << endl;

    cout << "What is your character's name?" << endl;
    cin.ignore();
    cin.clear();    
    getline(cin, player.playerName);
    //cin.ignore();
    //cin.clear();    
    //cin >> player.playerName;
    data.open("Data/Other/name.txt", std::fstream::trunc);
    data << player.playerName;
    data.close();

    //cout << "What is your character's style?" << endl;
    valid = false;
    while( condition == 0 ) {
        //cin >> userAnswer;
        while(!valid){
            cout << "\nWhat is your character's style?\n1. Water\n2. Earth\n3. Fire\n4. Air\n5. Devoted" << endl;
            valid = true;
            cin >> userAnswer;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "Please enter a number (especially you, Michael)\n";
                valid = false;
            }
        }
        switch(userAnswer){
            case 1:
                player.playerStyle = "Water";
                condition = 1;
                break;
            case 2:
                player.playerStyle = "Earth";
                condition = 1;
                break;
            case 3:
                player.playerStyle = "Fire";
                condition = 1;
                break;
            case 4:
                player.playerStyle = "Air";
                condition = 1;
                break;
            case 5:
                player.playerStyle = "Devoted";
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    condition = 0;
    //cin >> player.playerStyle;
    data.open("Data/Other/style.txt", std::fstream::trunc);
    data << player.playerStyle;
    data.close();



    if( player.playerStyle == "Water" ){
        //cout << "\nWhat is your character's path?\n1. Path of Restoration\n2. Path of the Stoic\n3. Path of Subjugation\n4. None" << endl;
        //cin >> userAnswer;
        valid = false;
        while(!valid){
            cout << "\nWhat is your character's path?\n1. Path of Restoration\n2. Path of the Stoic\n3. Path of Subjugation\n4. None" << endl;
            valid = true;
            cin >> userAnswer;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "Please enter a number (especially you, Michael)\n";
                valid = false;
            }
        }
        switch(userAnswer){
            case 1:
                player.playerPath = "Path of Restoration";
                break;
            case 2:
                player.playerPath = "Path of the Stoic";
                break;
            case 3:
                player.playerPath = "Path of Subjugation";
                break;
            default:
                player.playerPath = "None";
                break;
        }
    } else if( player.playerStyle == "Earth" ){
        //cout << "\nWhat is your character's path?\n1. Path of the Peacekeeper\n2. Path of the Purist\n3. Path of the Ravager\n4. None" << endl;
        //cin >> userAnswer;
        valid = false;
        while(!valid){
            cout << "\nWhat is your character's path?\n1. Path of the Peacekeeper\n2. Path of the Purist\n3. Path of the Ravager\n4. None" << endl;
            valid = true;
            cin >> userAnswer;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "Please enter a number (especially you, Michael)\n";
                valid = false;
            }
        }
        switch(userAnswer){
            case 1:
                player.playerPath = "Path of the Peacekeeper";
                break;
            case 2:
                player.playerPath = "Path of the Purist";
                break;
            case 3:
                player.playerPath = "Path of the Ravager";
                break;
            default:
                player.playerPath = "None";
                break;
        }
    } else if( player.playerStyle == "Fire" ){
        //cout << "\nWhat is your character's path?\n1. Path of the Elevated\n2. Path of the Zelous\n3. Path of the Fanatic\n4. None" << endl;
        //cin >> userAnswer;
        valid = false;
        while(!valid){
            cout << "\nWhat is your character's path?\n1. Path of the Elevated\n2. Path of the Zelous\n3. Path of the Fanatic\n4. None" << endl;
            valid = true;
            cin >> userAnswer;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "Please enter a number (especially you, Michael)\n";
                valid = false;
            }
        }
        switch(userAnswer){
            case 1:
                player.playerPath = "Path of the Elevated";
                break;
            case 2:
                player.playerPath = "Path of the Zelous";
                break;
            case 3:
                player.playerPath = "Path of the Fanatic";
                break;
            default:
                player.playerPath = "None";
                break;
        }
    } else if( player.playerStyle == "Air" ){
        //cout << "\nWhat is your character's path?\n1. Path of Peace\n2. Path of Indifference\n3. Path of Conflict\n4. None" << endl;
        //cin >> userAnswer;
        valid = false;
        while(!valid){
            cout << "\nWhat is your character's path?\n1. Path of Peace\n2. Path of Indifference\n3. Path of Conflict\n4. None" << endl;
            valid = true;
            cin >> userAnswer;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "Please enter a number (especially you, Michael)\n";
                valid = false;
            }
        }
        switch(userAnswer){
            case 1:
                player.playerPath = "Path of Peace";
                break;
            case 2:
                player.playerPath = "Path of Indifference";
                break;
            case 3:
                player.playerPath = "Path of Conflict";
                break;
            default:
                player.playerPath = "None";
                break;
        }
    } else if( player.playerStyle == "Devoted" ){
        //cout << "\nWhat is your character's path?\n1. Spirit Blocker\n2. The Duelist\n3. The Assassin\n4. None" << endl;
        //cin >> userAnswer;
        valid = false;
        while(!valid){
            cout << "\nWhat is your character's path?\n1. Spirit Blocker\n2. The Duelist\n3. The Assassin\n4. None" << endl;
            valid = true;
            cin >> userAnswer;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "Please enter a number (especially you, Michael)\n";
                valid = false;
            }
        }
        switch(userAnswer){
            case 1:
                player.playerPath = "Spirit Blocker";
                break;
            case 2:
                player.playerPath = "The Duelist";
                break;
            case 3:
                player.playerPath = "The Assassin";
                break;
            default:
                player.playerPath = "None";
                break;
        }
    }
    //cin >> player.playerPath;
    data.open("Data/Other/path.txt", std::fstream::trunc);
    data << player.playerPath;
    data.close();



    //cout << "What is your character's tier?" << endl;
    //cout << "\nWhat is your character's tier? 1, 2, 3, or 4?" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nWhat is your character's tier? 1, 2, 3, or 4?" << endl;
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 2:
            player.playerTier = 2;
            break;
        case 3:
            player.playerTier = 3;
            break;
        case 4:
            player.playerTier = 4;
            break;
        default:
            player.playerTier = 1;
            break;
    }
    //cin >> player.playerTier;
    data.open("Data/Other/tier.txt", std::fstream::trunc);
    data << player.playerTier;
    data.close();


    //cout << "What is your character's outward personality?" << endl;
    //cout << "\nWhat is your character's outward personality?" << endl << "1. Benevolent\n2. Malevolent\n3. Ambivalent\n";
    //cin >> userAnswer;        
    valid = false;
    while(!valid){
        cout << "\nWhat is your character's outward personality?\n1. Benevolent\n2. Ambivalent\n3. Malevolent\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.playerOutward = "Benevolent";
            break;
        case 3:
            player.playerOutward = "Malevolent";
            break;
       default:
            player.playerOutward = "Ambivalent";
            break;
    }
    //cin >> player.playerOutward;
    data.open("Data/Other/outward.txt", std::fstream::trunc);
    data << player.playerOutward;
    data.close();



    //cout << "\nWhat is your character's inward personality?" << endl << "1. Benevolent\n2. Malevolent\n3. Ambivalent\n";
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nWhat is your character's inward personality?\n1. Benevolent\n2. Ambivalent\n3. Malevolent\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.playerInward = "Benevolent";
            condition = 1;
            break;
        case 3:
            player.playerInward = "Malevolent";
            condition = 1;
            break;
        default:
            player.playerInward = "Ambivalent";
            break;
    }
    //cout << "What is your character's inward personality?" << endl;
    //cin >> player.playerInward;
    data.open("Data/Other/inward.txt", std::fstream::trunc);
    data << player.playerInward;
    data.close();

    cout << "\nWhat is your character's background?" << endl;
    cin.clear();
    cin.ignore();
    getline(cin, player.playerBackground);
    data.open("Data/Other/background.txt", std::fstream::trunc);
    data << player.playerBackground;
    data.close();

    cout << "\nWhat is your character's role?" << endl;
    cin.clear();
    cin.ignore();
    getline(cin, player.playerRole);
    //cin >> player.playerRole;
    data.open("Data/Other/role.txt", std::fstream::trunc);
    data << player.playerRole;
    data.close();

    //cout << "\nWhat is your character's maximum stamina?" << endl;
    //cin >> player.playerStaminaMax;
    valid = false;
    while(!valid){
        cout << "\nWhat is your character's maximum stamina?" << endl;
        valid = true;
        cin >> player.playerStaminaMax;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    player.playerStamina = player.playerStaminaMax;
    data.open("Data/Stats/staminaMax.txt", std::fstream::trunc);
    data << player.playerStaminaMax;
    data.close();
    data.open("Data/Stats/stamina.txt", std::fstream::trunc);
    data << player.playerStamina;
    data.close();


    //cout << "\nWhat is your character's maximum health?" << endl;
    //cin >> player.playerHealthMax;
    valid = false;
    while(!valid){
        cout << "\nWhat is your character's maximum health?" << endl;
        valid = true;
        cin >> player.playerHealthMax;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    player.playerHealth = player.playerHealthMax;
    data.open("Data/Stats/healthMax.txt", std::fstream::trunc);
    data << player.playerHealthMax;
    data.close();
    data.open("Data/Stats/health.txt", std::fstream::trunc);
    data << player.playerHealth;
    data.close();


    //cout << "\nWhat is your character's maximum fortitude?" << endl;
    //cin >> player.playerFortitudeMax;
    valid = false;
    while(!valid){
        cout << "\nWhat is your character's maximum fortitude?" << endl;
        valid = true;
        cin >> player.playerFortitudeMax;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    player.playerFortitude = player.playerFortitudeMax;
    data.open("Data/Stats/fortitudeMax.txt", std::fstream::trunc);
    data << player.playerFortitudeMax;
    data.close();
    data.open("Data/Stats/fortitude.txt", std::fstream::trunc);
    data << player.playerFortitude;
    data.close();



    //cout << "\nHow many spirit bonds does your character have? 0, 1, 2, or 3?" << endl;
    //cin >> userAnswer;        
    valid = false;
    while(!valid){
        cout << "\nHow many spirit bonds does your character have? 0, 1, 2, or 3?\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.playerSpiritBond = 1;
            break;
        case 2:
            player.playerSpiritBond = 2;
            break;
        case 3:
            player.playerSpiritBond = 3;
            break;
        default:
            player.playerSpiritBond = 0;
            break;
    }
    data.open("Data/Other/spiritBond.txt", std::fstream::trunc);
    data << player.playerSpiritBond;
    data.close();


    //cout << "\nWhat is your character's power?" << endl;
    //cin >> player.playerPower;
    valid = false;
    while(!valid){
        cout << "\nWhat is your character's power?\n";
        valid = true;
        cin >> player.playerPower;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    data.open("Data/Stats/power.txt", std::fstream::trunc);
    data << player.playerPower;
    data.close();

    //cout << "\nDoes your character have proficiency in power saving throws?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in power saving throws?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }        
    switch(userAnswer){
        case 1:
            player.powerSave = true;
            break;
        default:
            player.powerSave = false;
            break;
    }    
    data.open("Data/Stats/powerSave.txt", std::fstream::trunc);
    data << player.powerSave;
    data.close();


    //cout << "\nWhat is your character's finesse?" << endl;
    //cin >> player.playerFinesse;
    valid = false;
    while(!valid){
        cout << "\nWhat is your character's finesse?\n";
        valid = true;
        cin >> player.playerFinesse;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }    
    data.open("Data/Stats/finesse.txt", std::fstream::trunc);
    data << player.playerFinesse;
    data.close();

    //cout << "\nDoes your character have proficiency in finesse saving throws?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;        
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in power finesse throws?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.finesseSave = true;
            break;
        default:
            player.finesseSave = false;
            break;
    }
    data.open("Data/Stats/finesseSave.txt", std::fstream::trunc);
    data << player.finesseSave;
    data.close();


    //cout << "\nWhat is your character's vitality?" << endl;
    //cin >> player.playerVitality;
    valid = false;
    while(!valid){
        cout << "\nWhat is your character's vitality?\n";
        valid = true;
        cin >> player.playerVitality;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    data.open("Data/Stats/vitality.txt", std::fstream::trunc);
    data << player.playerVitality;
    data.close();

    //cout << "\nDoes your character have proficiency in vitality saving throws?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;        
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in power vitality throws?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }    
    switch(userAnswer){
        case 1:
            player.vitalitySave = true;
            break;
        default:
            player.vitalitySave = false;
            break;
    }
    data.open("Data/Stats/vitalitySave.txt", std::fstream::trunc);
    data << player.vitalitySave;
    data.close();


    //cout << "\nWhat is your character's knowledge?" << endl;
    //cin >> player.playerKnowledge;
    valid = false;
    while(!valid){
        cout << "\nWhat is your character's knowledge?\n";
        valid = true;
        cin >> player.playerKnowledge;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    data.open("Data/Stats/knowledge.txt", std::fstream::trunc);
    data << player.playerKnowledge;
    data.close();

    //cout << "\nDoes your character have proficiency in knowledge saving throws?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in knowledge saving throws?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.knowledgeSave = true;
            break;
        default:
            player.knowledgeSave = false;
            break;
     }
    data.open("Data/Stats/knowledgeSave.txt", std::fstream::trunc);
    data << player.knowledgeSave;
    data.close();


    //cout << "\nWhat is your character's reason?" << endl;
    //cin >> player.playerReason;
    valid = false;
    while(!valid){
        cout << "\nWhat is your character's reason?\n";
        valid = true;
        cin >> player.playerReason;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    data.open("Data/Stats/reason.txt", std::fstream::trunc);
    data << player.playerReason;
    data.close();

    //cout << "\nDoes your character have proficiency in reason saving throws?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;        
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in reason saving throws?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.reasonSave = true;
            break;
        default:
            player.reasonSave = false;
            break;
    }
    data.open("Data/Stats/reasonSave.txt", std::fstream::trunc);
    data << player.reasonSave;
    data.close();


    //cout << "\nWhat is your character's character?" << endl;
    //cin >> player.playerCharacter;
    valid = false;
    while(!valid){
        cout << "\nWhat is your character's character?\n";
        valid = true;
        cin >> player.playerCharacter;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    data.open("Data/Stats/character.txt", std::fstream::trunc);
    data << player.playerCharacter;
    data.close();

    //cout << "\nDoes your character have proficiency in character saving throws?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;        
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in character saving throws?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.characterSave = true;
            break;
        default:
            player.characterSave = false;
            break;
    }
    data.open("Data/Stats/characterSave.txt", std::fstream::trunc);
    data << player.characterSave;
    data.close();


    //cout << "\nHow much gold does your character have?" << endl;
    //cin >> player.playerGold;
    valid = false;
    while(!valid){
        cout << "\nHow much gold does your character have?\n";
        valid = true;
        cin >> player.playerGold;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    data.open("Data/Money/gold.txt", std::fstream::trunc);
    data << player.playerGold;
    data.close();

    //cout << "\nHow much silver does your character have?" << endl;
    //cin >> player.playerSilver;
    valid = false;
    while(!valid){
        cout << "\nHow much silver does your character have?\n";
        valid = true;
        cin >> player.playerSilver;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    data.open("Data/Money/silver.txt", std::fstream::trunc);
    data << player.playerSilver;
    data.close();

    //cout << "\nHow much copper does your character have?" << endl;
    //cin >> player.playerCopper;
    valid = false;
    while(!valid){
        cout << "\nHow much copper does your character have?\n";
        valid = true;
        cin >> player.playerCopper;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    data.open("Data/Money/copper.txt", std::fstream::trunc);
    data << player.playerCopper;
    data.close();

//inventory support will come later
    condition = 0;
    while( condition == 0 ) {
        cout << "\nHow many items do you have in your inventory?" << endl;
        cin >> userAnswer;
        player.inventoryCount = userAnswer;    
        data.open("Data/Other/inventoryCount.txt", std::fstream::trunc);
        data << userAnswer;
        data.close();
        if ( userAnswer <= inventoryMax ) {
            condition = 1;
        }
        else {
            cout << "Maximum number of items is " << inventoryMax << endl;
        }   
    }
    condition = 0;
    data.open("Data/Other/inventory.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Other/inventory.txt", std::fstream::app);
    if(player.inventoryCount != 0){
        cout << "\nEnter the names of your items. DO NOT USE ANY SPACES. PLEASE FOR THE LOVE OF GOD, I HAVEN'T FIGURED OUT HOW TO NOT MAKE THINGS BREAK. Instead use an underscore (_) to represent spaces." << endl;
    }
    for (int n = 0; n < userAnswer; n++) {
        cout << (n + 1) << ". ";
        cin >> player.playerInventory[n];
        data << player.playerInventory[n] << endl;
    }
    data.close();


//party member support will maybe come later
    while( condition == 0 ) {
        cout << "\nHow many party members do you have?" << endl;
        cin >> userAnswer;
        player.partyCount = userAnswer;    
        data.open("Data/Other/partyCount.txt", std::fstream::trunc);
        data << userAnswer;
        data.close();
        if ( userAnswer <= partyMax ) {
            condition = 1;
        }
        else {
            cout << "\nMaximum number of party members is " << partyMax << endl;
        }   
    }
    condition = 0;
    data.open("Data/Other/party.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Other/party.txt", std::fstream::app);
    if(player.partyCount != 0){
        cout << "\nEnter the names of your party members. DO NOT USE ANY SPACES. PLEASE FOR THE LOVE OF GOD, I HAVEN'T FIGURED OUT HOW TO NOT MAKE THINGS BREAK. Instead use an underscore (_) to represent spaces." << endl;
    }
    for (int n = 0; n < userAnswer; n++) {
        cout << (n + 1) << ". ";
        cin >> player.playerParty[n];
        data << player.playerParty[n] << endl;
    }
    data.close();


//ally member support will come later
    while( condition == 0 ) {
        cout << "\nHow many allies do you have?" << endl;
        cin >> userAnswer;
        player.alliesCount = userAnswer;    
        data.open("Data/Other/alliesCount.txt", std::fstream::trunc);
        data << userAnswer;
        data.close();
        if ( userAnswer <= alliesMax ) {
            condition = 1;
        }
        else {
            cout << "\nMaximum number of allies is " << partyMax << endl;
        }   
    }
    condition = 0;
    data.open("Data/Other/allies.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Other/allies.txt", std::fstream::app);
    if(player.alliesCount != 0){
        cout << "\nEnter the names of your allies. DO NOT USE ANY SPACES. PLEASE FOR THE LOVE OF GOD, I HAVEN'T FIGURED OUT HOW TO NOT MAKE THINGS BREAK. Instead use an underscore (_) to represent spaces." << endl;
    }
    for (int n = 0; n < userAnswer; n++) {
        cout << (n + 1) << ". ";
        cin >> player.playerAllies[n];
        data << player.playerAllies[n] << endl;
    }
    data.close();

//notes support will come later (probably not)
//features support will come later
//scrolls support will come later

    cout << "\nHow many scrolls do you have? There is a maximum of 14.\n";
    while( condition == 0 ) {
        cin >> userAnswer;
        if (userAnswer > scrollMax){
            cout << "\nThe maximum number of scrolls is 14.";
        } else{
            player.scrollCount = userAnswer;
            condition = 1;
        }
    }
    data.open("Data/Scrolls/scrollCount.txt", std::fstream::trunc);
    data << player.scrollCount;
    data.close();
    condition = 0;

    data.open("Data/Scrolls/scrollNames.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollDescriptions.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollDiceTypes.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollDiceCounts.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollTiers.txt", std::fstream::trunc);
    data << "";
    data.close();


    ifstream extracting;
    for(int i = 0; i < player.scrollCount; i++){
        //cout << "test statement" << endl;
        //cout << player.playerStyle << endl;
        if(player.playerStyle == "Water"){
            cout << "\n1. " << allScrollNames[0] << "\n2. " << allScrollNames[1] << "\n3. " << allScrollNames[2] << "\n4. " << allScrollNames[3] << "\n5. " << allScrollNames[4] << "\n6." << allScrollNames[5] << "\n7." << allScrollNames[6] << "\n8." << allScrollNames[7] << "\n9." << allScrollNames[8] << "\n10." << allScrollNames[9] << "\n11." << allScrollNames[10] << "\n12." << allScrollNames[11] << "\n13." << allScrollNames[12] << "\n14." << allScrollNames[13] << "\n15." << allScrollNames[14] << "\n16." << allScrollNames[15] << "\n17." << allScrollNames[16] << "\n18." << allScrollNames[17] << "\n19." << allScrollNames[18] << "\n20. " << allScrollNames[19] << "\n";
            cin >> userAnswer;
            if(userAnswer <= 20 && userAnswer >= 1){
                player.scrollName[i] = allScrollNames[userAnswer - 1];
//names
                /*extracting.open("Scrolls/name.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollName[i]);
                    }
                    count = count + 1;
                }
                extracting.close();*/
//descriptions
                extracting.open("Scrolls/description.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollDescription[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//dice types
                //player.scrollDiceType[i] = allScrollDiceTypes[userAnswer - 1];
                extracting.open("Scrolls/diceType.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollDiceType[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//dice counts
                //player.scrollDiceCount[i] = allScrollDiceCounts[userAnswer - 1];
                extracting.open("Scrolls/diceCount.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollDiceCount[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//tiers
                //player.scrollTier[i] = allScrollTiers[userAnswer - 1];
                extracting.open("Scrolls/tier.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollTier[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//ranges
                //player.scrollRange[i] = allScrollRanges[userAnswer - 1];
                extracting.open("Scrolls/range.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollRange[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//actions
                //player.scrollAction[i] = allScrollActions[userAnswer - 1];
                extracting.open("Scrolls/action.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollAction[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//types
                //player.scrollType[i] = allScrollTypes[userAnswer - 1];
                extracting.open("Scrolls/type.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollType[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//practices
                //player.scrollPractice[i] = allScrollPractices[userAnswer - 1];
                extracting.open("Scrolls/practice.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollPractice[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have practices
                //player.scrollHavePractice[i] = allScrollHavePractices[userAnswer - 1];
                extracting.open("Scrolls/havePractice.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollHavePractice[i];
                    }
                    count = count + 1;
                }
                extracting.close();
                data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
                data << player.scrollName[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDescriptions.txt", std::fstream::app);
                data << player.scrollDescription[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceTypes.txt", std::fstream::app);
                data << player.scrollDiceType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceCounts.txt", std::fstream::app);
                data << player.scrollDiceCount[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTiers.txt", std::fstream::app);
                data << player.scrollTier[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollRanges.txt", std::fstream::app);
                data << player.scrollRange[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollActions.txt", std::fstream::app);
                data << player.scrollAction[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTypes.txt", std::fstream::app);
                data << player.scrollType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollPractices.txt", std::fstream::app);
                data << player.scrollPractice[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollHavePractices.txt", std::fstream::app);
                data << player.scrollHavePractice[i] << endl;
                data.close();
            } else{
                player.scrollName[i] = "";
                player.scrollDescription[i] = "";
                player.scrollDiceType[i] = 0;
                player.scrollDiceCount[i] = 0;
                player.scrollTier[i] = 0;
                player.scrollRange[i] = "";
                player.scrollAction[i] = "";
                player.scrollType[i] = "";
                player.scrollPractice[i] = false;
                player.scrollHavePractice[i] = false;
                data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
                data << player.scrollName[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDescriptions.txt", std::fstream::app);
                data << player.scrollDescription[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceTypes.txt", std::fstream::app);
                data << player.scrollDiceType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceCounts.txt", std::fstream::app);
                data << player.scrollDiceCount[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTiers.txt", std::fstream::app);
                data << player.scrollTier[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollRanges.txt", std::fstream::app);
                data << player.scrollRange[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollActions.txt", std::fstream::app);
                data << player.scrollAction[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTypes.txt", std::fstream::app);
                data << player.scrollType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollPractices.txt", std::fstream::app);
                data << player.scrollPractice[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollHavePractices.txt", std::fstream::app);
                data << player.scrollHavePractice[i] << endl;
                data.close();
            }
        } else if(player.playerStyle == "Earth"){
            cout << "\n1. " << allScrollNames[20] << "\n2. " << allScrollNames[21] << "\n3. " << allScrollNames[22] << "\n4. " << allScrollNames[23] << "\n5. " << allScrollNames[24] << "\n6." << allScrollNames[25] << "\n7." << allScrollNames[26] << "\n8." << allScrollNames[27] << "\n9." << allScrollNames[28] << "\n10." << allScrollNames[29] << "\n11." << allScrollNames[30] << "\n12." << allScrollNames[31] << "\n13." << allScrollNames[32] << "\n14." << allScrollNames[33] << "\n15." << allScrollNames[34] << "\n16." << allScrollNames[35] << "\n17." << allScrollNames[36] << "\n18." << allScrollNames[37] << "\n19." << allScrollNames[38] << "\n20. " << allScrollNames[39] << "\n";
            cin >> userAnswer;
            if(userAnswer <= 20 && userAnswer >= 1){
                player.scrollName[i] = allScrollNames[userAnswer + 19];
//names
                /*extracting.open("Scrolls/name.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollName[i]);
                    }
                    count = count + 1;
                }
                extracting.close();*/
//descriptions
                extracting.open("Scrolls/description.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollDescription[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//dice types
                //player.scrollDiceType[i] = allScrollDiceTypes[userAnswer + 19];
                extracting.open("Scrolls/diceType.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollDiceType[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//dice counts
                //player.scrollDiceCount[i] = allScrollDiceCounts[userAnswer + 19];
                extracting.open("Scrolls/diceCount.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollDiceCount[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//tiers
                //player.scrollTier[i] = allScrollTiers[userAnswer + 19];
                extracting.open("Scrolls/tier.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollTier[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//ranges
                //player.scrollRange[i] = allScrollRanges[userAnswer + 19];
                extracting.open("Scrolls/range.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollRange[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//actions
                //player.scrollAction[i] = allScrollActions[userAnswer + 19];
                extracting.open("Scrolls/action.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollAction[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//types
                //player.scrollType[i] = allScrollTypes[userAnswer + 19];
                extracting.open("Scrolls/type.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollType[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//practices
                //player.scrollPractice[i] = allScrollPractices[userAnswer + 19];
                extracting.open("Scrolls/practice.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollPractice[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have practices
                //player.scrollHavePractice[i] = allScrollHavePractices[userAnswer + 19];
                extracting.open("Scrolls/havePractice.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollHavePractice[i];
                    }
                    count = count + 1;
                }
                extracting.close();
                data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
                data << player.scrollName[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDescriptions.txt", std::fstream::app);
                data << player.scrollDescription[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceTypes.txt", std::fstream::app);
                data << player.scrollDiceType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceCounts.txt", std::fstream::app);
                data << player.scrollDiceCount[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTiers.txt", std::fstream::app);
                data << player.scrollTier[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollRanges.txt", std::fstream::app);
                data << player.scrollRange[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollActions.txt", std::fstream::app);
                data << player.scrollAction[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTypes.txt", std::fstream::app);
                data << player.scrollType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollPractices.txt", std::fstream::app);
                data << player.scrollPractice[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollHavePractices.txt", std::fstream::app);
                data << player.scrollHavePractice[i] << endl;
                data.close();
            } else{
                player.scrollName[i] = "";
                player.scrollDescription[i] = "";
                player.scrollDiceType[i] = 0;
                player.scrollDiceCount[i] = 0;
                player.scrollTier[i] = 0;
                player.scrollRange[i] = "";
                player.scrollAction[i] = "";
                player.scrollType[i] = "";
                player.scrollPractice[i] = false;
                player.scrollHavePractice[i] = false;
                data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
                data << player.scrollName[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDescriptions.txt", std::fstream::app);
                data << player.scrollDescription[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceTypes.txt", std::fstream::app);
                data << player.scrollDiceType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceCounts.txt", std::fstream::app);
                data << player.scrollDiceCount[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTiers.txt", std::fstream::app);
                data << player.scrollTier[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollRanges.txt", std::fstream::app);
                data << player.scrollRange[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollActions.txt", std::fstream::app);
                data << player.scrollAction[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTypes.txt", std::fstream::app);
                data << player.scrollType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollPractices.txt", std::fstream::app);
                data << player.scrollPractice[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollHavePractices.txt", std::fstream::app);
                data << player.scrollHavePractice[i] << endl;
                data.close();
            }
        } else if(player.playerStyle == "Fire"){
            cout << "\n1. " << allScrollNames[40] << "\n2. " << allScrollNames[41] << "\n3. " << allScrollNames[42] << "\n4. " << allScrollNames[43] << "\n5. " << allScrollNames[44] << "\n6." << allScrollNames[45] << "\n7." << allScrollNames[46] << "\n8." << allScrollNames[47] << "\n9." << allScrollNames[48] << "\n10." << allScrollNames[49] << "\n11." << allScrollNames[50] << "\n12." << allScrollNames[51] << "\n13." << allScrollNames[52] << "\n14." << allScrollNames[53] << "\n15." << allScrollNames[54] << "\n16." << allScrollNames[55] << "\n17." << allScrollNames[56] << "\n18." << allScrollNames[57] << "\n19." << allScrollNames[58] << "\n20. " << allScrollNames[59] << "\n";
            cin >> userAnswer;
            if(userAnswer <= 20 && userAnswer >= 1){
                player.scrollName[i] = allScrollNames[userAnswer + 39];
//names
                /*extracting.open("Scrolls/name.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollName[i]);
                    }
                    count = count + 1;
                }
                extracting.close();*/
//descriptions
                extracting.open("Scrolls/description.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollDescription[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//dice types
                //player.scrollDiceType[i] = allScrollDiceTypes[userAnswer + 39];
                extracting.open("Scrolls/diceType.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollDiceType[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//dice counts
                //player.scrollDiceCount[i] = allScrollDiceCounts[userAnswer + 39];
                extracting.open("Scrolls/diceCount.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollDiceCount[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//tiers
                //player.scrollTier[i] = allScrollTiers[userAnswer + 39];
                extracting.open("Scrolls/tier.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollTier[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//ranges
                //player.scrollRange[i] = allScrollRanges[userAnswer + 39];
                extracting.open("Scrolls/range.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollRange[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//actions
                //player.scrollAction[i] = allScrollActions[userAnswer + 39];
                extracting.open("Scrolls/action.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollAction[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//types
                //player.scrollType[i] = allScrollTypes[userAnswer + 39];
                extracting.open("Scrolls/type.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollType[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//practices
                //player.scrollPractice[i] = allScrollPractices[userAnswer + 39];
                extracting.open("Scrolls/practice.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollPractice[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have practices
                //player.scrollHavePractice[i] = allScrollHavePractices[userAnswer + 39];
                extracting.open("Scrolls/havePractice.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollHavePractice[i];
                    }
                    count = count + 1;
                }
                extracting.close();
                data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
                data << player.scrollName[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDescriptions.txt", std::fstream::app);
                data << player.scrollDescription[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceTypes.txt", std::fstream::app);
                data << player.scrollDiceType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceCounts.txt", std::fstream::app);
                data << player.scrollDiceCount[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTiers.txt", std::fstream::app);
                data << player.scrollTier[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollRanges.txt", std::fstream::app);
                data << player.scrollRange[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollActions.txt", std::fstream::app);
                data << player.scrollAction[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTypes.txt", std::fstream::app);
                data << player.scrollType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollPractices.txt", std::fstream::app);
                data << player.scrollPractice[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollHavePractices.txt", std::fstream::app);
                data << player.scrollHavePractice[i] << endl;
                data.close();
            } else{
                player.scrollName[i] = "";
                player.scrollDescription[i] = "";
                player.scrollDiceType[i] = 0;
                player.scrollDiceCount[i] = 0;
                player.scrollTier[i] = 0;
                player.scrollRange[i] = "";
                player.scrollAction[i] = "";
                player.scrollType[i] = "";
                player.scrollPractice[i] = false;
                player.scrollHavePractice[i] = false;
                data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
                data << player.scrollName[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDescriptions.txt", std::fstream::app);
                data << player.scrollDescription[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceTypes.txt", std::fstream::app);
                data << player.scrollDiceType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceCounts.txt", std::fstream::app);
                data << player.scrollDiceCount[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTiers.txt", std::fstream::app);
                data << player.scrollTier[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollRanges.txt", std::fstream::app);
                data << player.scrollRange[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollActions.txt", std::fstream::app);
                data << player.scrollAction[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTypes.txt", std::fstream::app);
                data << player.scrollType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollPractices.txt", std::fstream::app);
                data << player.scrollPractice[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollHavePractices.txt", std::fstream::app);
                data << player.scrollHavePractice[i] << endl;
                data.close();
            }
        } else if(player.playerStyle == "Air"){
            cout << "\n1. " << allScrollNames[60] << "\n2. " << allScrollNames[61] << "\n3. " << allScrollNames[62] << "\n4. " << allScrollNames[63] << "\n5. " << allScrollNames[64] << "\n6." << allScrollNames[65] << "\n7." << allScrollNames[66] << "\n8." << allScrollNames[67] << "\n9." << allScrollNames[68] << "\n10." << allScrollNames[69] << "\n11." << allScrollNames[70] << "\n12." << allScrollNames[71] << "\n13." << allScrollNames[72] << "\n14." << allScrollNames[73] << "\n15." << allScrollNames[74] << "\n16." << allScrollNames[75] << "\n17." << allScrollNames[76] << "\n18." << allScrollNames[77] << "\n19." << allScrollNames[78] << "\n20. " << allScrollNames[79] << "\n";
            cin >> userAnswer;
            if(userAnswer <= 20 && userAnswer >= 1){
                player.scrollName[i] = allScrollNames[userAnswer + 59];
//names
                /*extracting.open("Scrolls/name.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollName[i]);
                    }
                    count = count + 1;
                }
                extracting.close();*/
//descriptions
                extracting.open("Scrolls/description.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollDescription[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//dice types
                //player.scrollDiceType[i] = allScrollDiceTypes[userAnswer + 59];
                extracting.open("Scrolls/diceType.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollDiceType[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//dice counts
                //player.scrollDiceCount[i] = allScrollDiceCounts[userAnswer + 59];
                extracting.open("Scrolls/diceCount.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollDiceCount[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//tiers
                //player.scrollTier[i] = allScrollTiers[userAnswer + 59];
                extracting.open("Scrolls/tier.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollTier[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//ranges
                //player.scrollRange[i] = allScrollRanges[userAnswer + 59];
                extracting.open("Scrolls/range.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollRange[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//actions
                //player.scrollAction[i] = allScrollActions[userAnswer + 59];
                extracting.open("Scrolls/action.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollAction[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//types
                //player.scrollType[i] = allScrollTypes[userAnswer + 59];
                extracting.open("Scrolls/type.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollType[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//practices
                //player.scrollPractice[i] = allScrollPractices[userAnswer + 59];
                extracting.open("Scrolls/practice.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollPractice[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have practices
                //player.scrollHavePractice[i] = allScrollHavePractices[userAnswer + 59];
                extracting.open("Scrolls/havePractice.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollHavePractice[i];
                    }
                    count = count + 1;
                }
                extracting.close();
                data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
                data << player.scrollName[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDescriptions.txt", std::fstream::app);
                data << player.scrollDescription[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceTypes.txt", std::fstream::app);
                data << player.scrollDiceType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceCounts.txt", std::fstream::app);
                data << player.scrollDiceCount[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTiers.txt", std::fstream::app);
                data << player.scrollTier[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollRanges.txt", std::fstream::app);
                data << player.scrollRange[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollActions.txt", std::fstream::app);
                data << player.scrollAction[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTypes.txt", std::fstream::app);
                data << player.scrollType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollPractices.txt", std::fstream::app);
                data << player.scrollPractice[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollHavePractices.txt", std::fstream::app);
                data << player.scrollHavePractice[i] << endl;
                data.close();
            } else{
                player.scrollName[i] = "";
                player.scrollDescription[i] = "";
                player.scrollDiceType[i] = 0;
                player.scrollDiceCount[i] = 0;
                player.scrollTier[i] = 0;
                player.scrollRange[i] = "";
                player.scrollAction[i] = "";
                player.scrollType[i] = "";
                player.scrollPractice[i] = false;
                player.scrollHavePractice[i] = false;
                data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
                data << player.scrollName[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDescriptions.txt", std::fstream::app);
                data << player.scrollDescription[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceTypes.txt", std::fstream::app);
                data << player.scrollDiceType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceCounts.txt", std::fstream::app);
                data << player.scrollDiceCount[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTiers.txt", std::fstream::app);
                data << player.scrollTier[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollRanges.txt", std::fstream::app);
                data << player.scrollRange[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollActions.txt", std::fstream::app);
                data << player.scrollAction[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTypes.txt", std::fstream::app);
                data << player.scrollType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollPractices.txt", std::fstream::app);
                data << player.scrollPractice[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollHavePractices.txt", std::fstream::app);
                data << player.scrollHavePractice[i] << endl;
                data.close();
            }
        } else if(player.playerStyle == "Devoted"){
            cout << "\n1. " << allScrollNames[80] << "\n2. " << allScrollNames[81] << "\n3. " << allScrollNames[82] << "\n4. " << allScrollNames[83] << "\n5. " << allScrollNames[84] << "\n6." << allScrollNames[85] << "\n7." << allScrollNames[86] << "\n8." << allScrollNames[87] << "\n9." << allScrollNames[88] << "\n10." << allScrollNames[89] << "\n11." << allScrollNames[90] << "\n12." << allScrollNames[91] << "\n13." << allScrollNames[92] << "\n14." << allScrollNames[93] << "\n15." << allScrollNames[94] << "\n16." << allScrollNames[95] << "\n17." << allScrollNames[96] << "\n18." << allScrollNames[97] << "\n";
            cin >> userAnswer;
            if(userAnswer <= 18 && userAnswer >= 1){
                player.scrollName[i] = allScrollNames[userAnswer + 79];
//names
                /*extracting.open("Scrolls/name.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollName[i]);
                    }
                    count = count + 1;
                }
                extracting.close();*/
//descriptions
                extracting.open("Scrolls/description.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollDescription[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//dice types
                //player.scrollDiceType[i] = allScrollDiceTypes[userAnswer + 79];
                extracting.open("Scrolls/diceType.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollDiceType[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//dice counts
                //player.scrollDiceCount[i] = allScrollDiceCounts[userAnswer + 79];
                extracting.open("Scrolls/diceCount.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollDiceCount[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//tiers
                //player.scrollTier[i] = allScrollTiers[userAnswer + 79];
                extracting.open("Scrolls/tier.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollTier[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//ranges
                //player.scrollRange[i] = allScrollRanges[userAnswer + 79];
                extracting.open("Scrolls/range.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollRange[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//actions
                //player.scrollAction[i] = allScrollActions[userAnswer + 79];
                extracting.open("Scrolls/action.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollAction[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//types
                //player.scrollType[i] = allScrollTypes[userAnswer + 79];
                extracting.open("Scrolls/type.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        getline(extracting, tempString);
                        cout << tempString << endl;
                    } else{
                        getline(extracting, player.scrollType[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//practices
                //player.scrollPractice[i] = allScrollPractices[userAnswer + 79];
                extracting.open("Scrolls/practice.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollPractice[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have practices
                //player.scrollHavePractice[i] = allScrollHavePractices[userAnswer + 79];
                extracting.open("Scrolls/havePractice.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        cout << tempString << endl;
                    } else{
                        extracting >> player.scrollHavePractice[i];
                    }
                    count = count + 1;
                }
                extracting.close();
                data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
                data << player.scrollName[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDescriptions.txt", std::fstream::app);
                data << player.scrollDescription[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceTypes.txt", std::fstream::app);
                data << player.scrollDiceType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceCounts.txt", std::fstream::app);
                data << player.scrollDiceCount[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTiers.txt", std::fstream::app);
                data << player.scrollTier[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollRanges.txt", std::fstream::app);
                data << player.scrollRange[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollActions.txt", std::fstream::app);
                data << player.scrollAction[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTypes.txt", std::fstream::app);
                data << player.scrollType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollPractices.txt", std::fstream::app);
                data << player.scrollPractice[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollHavePractices.txt", std::fstream::app);
                data << player.scrollHavePractice[i] << endl;
                data.close();
            } else{
                player.scrollName[i] = "";
                player.scrollDescription[i] = "";
                player.scrollDiceType[i] = 0;
                player.scrollDiceCount[i] = 0;
                player.scrollTier[i] = 0;
                player.scrollRange[i] = "";
                player.scrollAction[i] = "";
                player.scrollType[i] = "";
                player.scrollPractice[i] = false;
                player.scrollHavePractice[i] = false;
                data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
                data << player.scrollName[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDescriptions.txt", std::fstream::app);
                data << player.scrollDescription[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceTypes.txt", std::fstream::app);
                data << player.scrollDiceType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollDiceCounts.txt", std::fstream::app);
                data << player.scrollDiceCount[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTiers.txt", std::fstream::app);
                data << player.scrollTier[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollRanges.txt", std::fstream::app);
                data << player.scrollRange[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollActions.txt", std::fstream::app);
                data << player.scrollAction[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollTypes.txt", std::fstream::app);
                data << player.scrollType[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollPractices.txt", std::fstream::app);
                data << player.scrollPractice[i] << endl;
                data.close();
                data.open("Data/Scrolls/scrollHavePractices.txt", std::fstream::app);
                data << player.scrollHavePractice[i] << endl;
                data.close();
            }
        }
    }















    //cout << "\nDoes your character have proficiency in athletics?\n1. Yes\n2. No\n";
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in athletics?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.athleticsProf = true;
            break;
        default:
            player.athleticsProf = false;
            break;
    }
    data.open("Data/Proficiencies/athletics.txt", std::fstream::trunc);
    data << player.athleticsProf;
    data.close();

    //cout << "\nDoes your character have proficiency in acrobatics?\n1. Yes\n2. No\n";
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in acrobatics?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.acrobaticsProf = true;
            break;
        default:
            player.acrobaticsProf = false;
            break;
    }
    data.open("Data/Proficiencies/acrobatics.txt", std::fstream::trunc);
    data << player.acrobaticsProf;
    data.close();

    //cout << "\nDoes your character have proficiency in escamotage?\n1. Yes\n2. No\n";
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in escamotage?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.escamotageProf = true;
            break;
        default:
            player.escamotageProf = false;
            break;
    }
    data.open("Data/Proficiencies/escamotage.txt", std::fstream::trunc);
    data << player.escamotageProf;
    data.close();

    //cout << "\nDoes your character have proficiency in stealth?\n1. Yes\n2. No\n";
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in stealth?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.stealthProf = true;
            break;
        default:
            player.stealthProf = false;
            break;
    }    
    data.open("Data/Proficiencies/stealth.txt", std::fstream::trunc);
    data << player.stealthProf;
    data.close();
    condition = 0;

    //cout << "\nDoes your character have proficiency in willpower?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in willpower?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.willpowerProf = true;
            break;
        default:
            player.willpowerProf = false;
            break;
    }
    data.open("Data/Proficiencies/willpower.txt", std::fstream::trunc);
    data << player.willpowerProf;
    data.close();

    //cout << "\nDoes your character have proficiency in history?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in history?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.historyProf = true;
            break;
        case 2:
            player.historyProf = false;
            break;
    }
    data.open("Data/Proficiencies/history.txt", std::fstream::trunc);
    data << player.historyProf;
    data.close();

    //cout << "\nDoes your character have proficiency in investigation?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in investigation?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }   
    switch(userAnswer){
        case 1:
            player.investigationProf = true;
            break;
        case 2:
            player.investigationProf = false;
            break;
    }
    data.open("Data/Proficiencies/investigation.txt", std::fstream::trunc);
    data << player.investigationProf;
    data.close();

    //cout << "\nDoes your character have proficiency in nature?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in nature?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.natureProf = true;
            break;
        case 2:
            player.natureProf = false;
            break;
    }    
    data.open("Data/Proficiencies/nature.txt", std::fstream::trunc);
    data << player.natureProf;
    data.close();

    //cout << "\nDoes your character have proficiency in seafaring?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in seafaring?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.seafaringProf = true;
            break;
        default:
            player.seafaringProf = false;
            break;
    }
    data.open("Data/Proficiencies/seafaring.txt", std::fstream::trunc);
    data << player.seafaringProf;
    data.close();

    //cout << "\nDoes your character have proficiency in spirit?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in spirit?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.spiritProf = true;
            break;
        default:
            player.spiritProf = false;
            break;
    }
    data.open("Data/Proficiencies/spirit.txt", std::fstream::trunc);
    data << player.spiritProf;
    data.close();

    //cout << "\nDoes your character have proficiency in taming?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in taming?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.tamingProf = true;
            break;
        default:
            player.tamingProf = false;
            break;
    }
    data.open("Data/Proficiencies/taming.txt", std::fstream::trunc);
    data << player.tamingProf;
    data.close();

    //cout << "\nDoes your character have proficiency in hunting?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in hunting?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.huntingProf = true;
            break;
        default:
            player.huntingProf = false;
            break;
    }
    data.open("Data/Proficiencies/hunting.txt", std::fstream::trunc);
    data << player.huntingProf;
    data.close();

    //cout << "\nDoes your character have proficiency in insight?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in insight?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.insightProf = true;
            break;
        default:
            player.insightProf = false;
            break;
    }
    data.open("Data/Proficiencies/insight.txt", std::fstream::trunc);
    data << player.insightProf;
    data.close();

    //cout << "\nDoes your character have proficiency in medicine?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in medicine?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.medicineProf = true;
            break;
        default:
            player.medicineProf = false;
            break;
    }
    data.open("Data/Proficiencies/medicine.txt", std::fstream::trunc);
    data << player.medicineProf;
    data.close();

    //cout << "\nDoes your character have proficiency in perception?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in perception?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
           player.perceptionProf = true;
            break;
        default:
            player.perceptionProf = false;
            break;
    }
    data.open("Data/Proficiencies/perception.txt", std::fstream::trunc);
    data << player.perceptionProf;
    data.close();

    //cout << "\nDoes your character have proficiency in deception?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in deception?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.deceptionProf = true;
            break;
        default:
            player.deceptionProf = false;
            break;
    }
    data.open("Data/Proficiencies/deception.txt", std::fstream::trunc);
    data << player.deceptionProf;
    data.close();

    //cout << "\nDoes your character have proficiency in intimidation?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in intimidation?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.intimidationProf = true;
            break;
        default:
            player.intimidationProf = false;
            break;
    }
    data.open("Data/Proficiencies/intimidation.txt", std::fstream::trunc);
    data << player.intimidationProf;
    data.close();

    //cout << "\nDoes your character have proficiency in performance?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in performance?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.performanceProf = true;
            break;
        default:
            player.performanceProf = false;
            break;
    }
    data.open("Data/Proficiencies/performance.txt", std::fstream::trunc);
    data << player.performanceProf;
    data.close();

    //cout << "\nDoes your character have proficiency in persuasion?" << endl << "1. Yes" << endl << "2. No" << endl;
    //cin >> userAnswer;
    valid = false;
    while(!valid){
        cout << "\nDoes your character have proficiency in persuasion?\n1. Yes\n2. No\n";
        valid = true;
        cin >> userAnswer;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Please enter a number (especially you, Michael)\n";
            valid = false;
        }
    }
    switch(userAnswer){
        case 1:
            player.persuasionProf = true;
            break;
        default:
            player.persuasionProf = false;
            break;
    }
    data.open("Data/Proficiencies/persuasion.txt", std::fstream::trunc);
    data << player.persuasionProf;
    data.close();

    return player;
};

characterInfo loadCharacter(){
    characterInfo player;
    ifstream data;

    data.open("Data/Other/name.txt");
    getline(data, player.playerName);    
    //data >> player.playerName;
    data.close();

    data.open("Data/Other/style.txt");
    data >> player.playerStyle;
    data.close();

    data.open("Data/Other/path.txt");
    //data >> player.playerPath;
    getline(data, player.playerPath, '\n');
    cout << player.playerPath;
    data.close();

    data.open("Data/Other/tier.txt");
    data >> player.playerTier;
    data.close();

    data.open("Data/Other/outward.txt");
    data >> player.playerOutward;
    data.close();

    data.open("Data/Other/inward.txt");
    data >> player.playerInward;
    data.close();

    data.open("Data/Other/background.txt");
    getline(data, player.playerBackground);
    //data >> player.playerBackground;
    data.close();

    data.open("Data/Other/role.txt");
    getline(data, player.playerRole);
    //data >> player.playerRole;
    data.close();

//read the player proficiency bonus

    data.open("Data/Stats/staminaMax.txt");
    data >> player.playerStaminaMax;
    data.close();

    data.open("Data/Stats/stamina.txt");
    data >> player.playerStamina;
    data.close();

    data.open("Data/Stats/healthMax.txt");
    data >> player.playerHealthMax;
    data.close();

    data.open("Data/Stats/health.txt");
    data >> player.playerHealth;
    data.close();

    data.open("Data/Stats/fortitudeMax.txt");
    data >> player.playerFortitudeMax;
    data.close();

    data.open("Data/Stats/fortitude.txt");
    data >> player.playerFortitude;
    data.close();

    data.open("Data/Other/spiritBond.txt");
    data >> player.playerSpiritBond;
    data.close();

    data.open("Data/Stats/power.txt");
    data >> player.playerPower;
    data.close();

    data.open("Data/Stats/finesse.txt");
    data >> player.playerFinesse;
    data.close();

    data.open("Data/Stats/vitality.txt");
    data >> player.playerVitality;
    data.close();

    data.open("Data/Stats/knowledge.txt");
    data >> player.playerKnowledge;
    data.close();

    data.open("Data/Stats/reason.txt");
    data >> player.playerReason;
    data.close();

    data.open("Data/Stats/character.txt");
    data >> player.playerCharacter;
    data.close();

    data.open("Data/Stats/powerSave.txt");
    data >> player.powerSave;
    data.close();

    data.open("Data/Stats/finesseSave.txt");
    data >> player.finesseSave;
    data.close();

    data.open("Data/Stats/vitalitySave.txt");
    data >> player.vitalitySave;
    data.close();

    data.open("Data/Stats/knowledgeSave.txt");
    data >> player.knowledgeSave;
    data.close();

    data.open("Data/Stats/reasonSave.txt");
    data >> player.reasonSave;
    data.close();

    data.open("Data/Stats/characterSave.txt");
    data >> player.characterSave;
    data.close();

//will add party members *added*
    data.open("Data/Other/partyCount.txt");
    data >> player.partyCount;
    data.close();
    ifstream extracting;
    extracting.open("Data/Other/party.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.partyCount)
    {
        getline(extracting, player.playerParty[count], '\n');
        //cout << count << ". " << player.playerParty[count] << endl;
        count = count + 1;
    }
    extracting.close();


//will add allies *added*
    data.open("Data/Other/alliesCount.txt");
    data >> player.alliesCount;
    data.close();
    extracting.open("Data/Other/allies.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.alliesCount)
    {
        getline(extracting, player.playerAllies[count], '\n');
        cout << count << ". " << player.playerAllies[count] << endl;
        count = count + 1;
    }
    extracting.close();

//will add notes
//will add features


//will add inventory *added*
    data.open("Data/Other/inventoryCount.txt");
    data >> player.inventoryCount;
    data.close();
    extracting.open("Data/Other/inventory.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.inventoryCount)
    {
        getline(extracting, player.playerInventory[count], '\n');
        //cout << count << ". " << player.playerInventory[count] << endl;
        count = count + 1;
    }
    extracting.close();

    data.open("Data/Money/copper.txt");
    data >> player.playerCopper;
    data.close();

    data.open("Data/Money/silver.txt");
    data >> player.playerSilver;
    data.close();

    data.open("Data/Money/gold.txt");
    data >> player.playerGold;
    data.close();

//will add scrolls
    data.open("Data/Scrolls/scrollCount.txt");
    data >> player.scrollCount;
    data.close();
    extracting.open("Data/Scrolls/scrollNames.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        getline(extracting, player.scrollName[count], '\n');
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollDescriptions.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        getline(extracting, player.scrollDescription[count], '\n');
        count = count + 1;
    }
    extracting.close();
//add converting string to int later
    extracting.open("Data/Scrolls/scrollDiceTypes.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        extracting >> player.scrollDiceType[count];
        cout << player.scrollDiceType[count] << endl;
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollDiceCounts.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        extracting >> player.scrollDiceCount[count];
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollTiers.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        extracting >> player.scrollTier[count];
        count = count + 1;
    }
    extracting.close();





    data.open("Data/Proficiencies/athletics.txt");
    data >> player.athleticsProf;
    data.close();

    data.open("Data/Proficiencies/acrobatics.txt");
    data >> player.acrobaticsProf;
    data.close();

    data.open("Data/Proficiencies/escamotage.txt");
    data >> player.escamotageProf;
    data.close();

    data.open("Data/Proficiencies/stealth.txt");
    data >> player.stealthProf;
    data.close();

    data.open("Data/Proficiencies/willpower.txt");
    data >> player.willpowerProf;
    data.close();

    data.open("Data/Proficiencies/history.txt");
    data >> player.historyProf;
    data.close();

    data.open("Data/Proficiencies/investigation.txt");
    data >> player.investigationProf;
    data.close();

    data.open("Data/Proficiencies/nature.txt");
    data >> player.natureProf;
    data.close();

    data.open("Data/Proficiencies/seafaring.txt");
    data >> player.seafaringProf;
    data.close();

    data.open("Data/Proficiencies/spirit.txt");
    data >> player.spiritProf;
    data.close();

    data.open("Data/Proficiencies/taming.txt");
    data >> player.tamingProf;
    data.close();

    data.open("Data/Proficiencies/hunting.txt");
    data >> player.huntingProf;
    data.close();

    data.open("Data/Proficiencies/insight.txt");
    data >> player.insightProf;
    data.close();

    data.open("Data/Proficiencies/medicine.txt");
    data >> player.medicineProf;
    data.close();

    data.open("Data/Proficiencies/perception.txt");
    data >> player.perceptionProf;
    data.close();

    data.open("Data/Proficiencies/deception.txt");
    data >> player.deceptionProf;
    data.close();

    data.open("Data/Proficiencies/intimidation.txt");
    data >> player.intimidationProf;
    data.close();

    data.open("Data/Proficiencies/performance.txt");
    data >> player.performanceProf;
    data.close();

    data.open("Data/Proficiencies/persuasion.txt");
    data >> player.persuasionProf;
    data.close();

    return player;
};

int characterSheet(characterInfo player){
    condition = 0;
    ofstream data;
    while ( condition == 0 ){
//need to recalculate the ability modifiers and proficiency bonus each time the character sheet is displayed because variables may have changed

//proficiency bonus will be calculated here depending on what their tier is, need to talk to Josh and Luis to get specific values
        player.playerProficiencyBonus = 2 * player.playerTier;

//ability modifiers

//first, modifiers for raw stat totals
        //player.powerMod = floor((player.playerPower - 10) / 2);

        //player.finesseMod = floor((player.playerFinesse - 10) / 2);

        //player.vitalityMod = floor((player.playerVitality - 10) / 2);

        //player.knowledgeMod = floor((player.playerKnowledge - 10) / 2);

        //player.reasonMod = floor((player.playerReason - 10) / 2);

        //player.characterMod = floor((player.playerCharacter - 10) / 2);

        switch(player.playerPower){
            case 1:
                player.powerMod = -5;
                break;
            case 2:
            case 3:
                player.powerMod = -4;
                break;
            case 4:
            case 5:
                player.powerMod = -3;
                break;
            case 6:
            case 7:
                player.powerMod = -2;
                break;
            case 8:
            case 9:
                player.powerMod = -1;
                break;
            case 10:
            case 11:
                player.powerMod = 0;
                break;
            case 12:
            case 13:
                player.powerMod = 1;
                break;
            case 14:
            case 15:
                player.powerMod = 2;
                break;
            case 16:
            case 17:
                player.powerMod = 3;
                break;
            case 18:
            case 19:
                player.powerMod = 4;
                break;
            case 20:
                player.powerMod = 5;
                break;
        }

        switch(player.playerFinesse){
            case 1:
                player.finesseMod = -5;
                break;
            case 2:
            case 3:
                player.finesseMod = -4;
                break;
            case 4:
            case 5:
                player.finesseMod = -3;
                break;
            case 6:
            case 7:
                player.finesseMod = -2;
                break;
            case 8:
            case 9:
                player.finesseMod = -1;
                break;
            case 10:
            case 11:
                player.finesseMod = 0;
                break;
            case 12:
            case 13:
                player.finesseMod = 1;
                break;
            case 14:
            case 15:
                player.finesseMod = 2;
                break;
            case 16:
            case 17:
                player.finesseMod = 3;
                break;
            case 18:
            case 19:
                player.finesseMod = 4;
                break;
            case 20:
                player.finesseMod = 5;
                break;
        }

        switch(player.playerVitality){
            case 1:
                player.vitalityMod = -5;
                break;
            case 2:
            case 3:
                player.vitalityMod = -4;
                break;
            case 4:
            case 5:
                player.vitalityMod = -3;
                break;
            case 6:
            case 7:
                player.vitalityMod = -2;
                break;
            case 8:
            case 9:
                player.vitalityMod = -1;
                break;
            case 10:
            case 11:
                player.vitalityMod = 0;
                break;
            case 12:
            case 13:
                player.vitalityMod = 1;
                break;
            case 14:
            case 15:
                player.vitalityMod = 2;
                break;
            case 16:
            case 17:
                player.vitalityMod = 3;
                break;
            case 18:
            case 19:
                player.vitalityMod = 4;
                break;
            case 20:
                player.vitalityMod = 5;
                break;
        }

        switch(player.playerKnowledge){
            case 1:
                player.knowledgeMod = -5;
                break;
            case 2:
            case 3:
                player.knowledgeMod = -4;
                break;
            case 4:
            case 5:
                player.knowledgeMod = -3;
                break;
            case 6:
            case 7:
                player.knowledgeMod = -2;
                break;
            case 8:
            case 9:
                player.knowledgeMod = -1;
                break;
            case 10:
            case 11:
                player.knowledgeMod = 0;
                break;
            case 12:
            case 13:
                player.knowledgeMod = 1;
                break;
            case 14:
            case 15:
                player.knowledgeMod = 2;
                break;
            case 16:
            case 17:
                player.knowledgeMod = 3;
                break;
            case 18:
            case 19:
                player.knowledgeMod = 4;
                break;
            case 20:
                player.knowledgeMod = 5;
                break;
        }

        switch(player.playerReason){
            case 1:
                player.reasonMod = -5;
                break;
            case 2:
            case 3:
                player.reasonMod = -4;
                break;
            case 4:
            case 5:
                player.reasonMod = -3;
                break;
            case 6:
            case 7:
                player.reasonMod = -2;
                break;
            case 8:
            case 9:
                player.reasonMod = -1;
                break;
            case 10:
            case 11:
                player.reasonMod = 0;
                break;
            case 12:
            case 13:
                player.reasonMod = 1;
                break;
            case 14:
            case 15:
                player.reasonMod = 2;
                break;
            case 16:
            case 17:
                player.reasonMod = 3;
                break;
            case 18:
            case 19:
                player.reasonMod = 4;
                break;
            case 20:
                player.reasonMod = 5;
                break;
        }

        switch(player.playerCharacter){
            case 1:
                player.characterMod = -5;
                break;
            case 2:
            case 3:
                player.characterMod = -4;
                break;
            case 4:
            case 5:
                player.characterMod = -3;
                break;
            case 6:
            case 7:
                player.characterMod = -2;
                break;
            case 8:
            case 9:
                player.characterMod = -1;
                break;
            case 10:
            case 11:
                player.characterMod = 0;
                break;
            case 12:
            case 13:
                player.characterMod = 1;
                break;
            case 14:
            case 15:
                player.characterMod = 2;
                break;
            case 16:
            case 17:
                player.characterMod = 3;
                break;
            case 18:
            case 19:
                player.characterMod = 4;
                break;
            case 20:
                player.characterMod = 5;
                break;
        }


//next, modifiers for saving throws
        if (player.powerSave){
            player.powerSaveMod = player.powerMod + player.playerProficiencyBonus;
        }
        else{
            player.powerSaveMod = player.powerMod;
        }
        cout << player.powerSaveMod;
        if (player.finesseSave){
            player.finesseSaveMod = player.finesseMod + player.playerProficiencyBonus;
        }
        else{
            player.finesseSaveMod = player.finesseMod;
        }

        if (player.vitalitySave){
            player.vitalitySaveMod = player.vitalityMod + player.playerProficiencyBonus;
        }
        else{
            player.vitalitySaveMod = player.vitalityMod;
        }

        if (player.knowledgeSave){
            player.knowledgeSaveMod = player.knowledgeMod + player.playerProficiencyBonus;
        }
        else{
            player.knowledgeSaveMod = player.knowledgeMod;
        }

        if (player.reasonSave){
            player.reasonSaveMod = player.reasonMod + player.playerProficiencyBonus;
        }
        else{
            player.reasonSaveMod = player.reasonMod;
        }

        if (player.characterSave){
            player.characterSaveMod = player.characterMod + player.playerProficiencyBonus;
        }
        else{
            player.characterSaveMod = player.characterMod;
        }

//after this, modifiers for each ability modifier

        //power abilities
        if (player.athleticsProf){
            player.athleticsMod = player.powerMod + player.playerProficiencyBonus;
        }
        else{
            player.athleticsMod = player.powerMod;
        }

        //finesse abilities
        if (player.acrobaticsProf){
            player.acrobaticsMod = player.finesseMod + player.playerProficiencyBonus;
        }
        else{
            player.acrobaticsMod = player.finesseMod;
        }

        if (player.escamotageProf){
            player.escamotageMod = player.finesseMod + player.playerProficiencyBonus;
        }
        else{
            player.escamotageMod = player.finesseMod;
        }

        if (player.stealthProf){
            player.stealthMod = player.finesseMod + player.playerProficiencyBonus;
        }
        else{
            player.stealthMod = player.finesseMod;
        }

        //vitality abilities
        if (player.willpowerProf){
            player.willpowerMod = player.vitalityMod + player.playerProficiencyBonus;
        }
        else{
            player.willpowerMod = player.vitalityMod;
        }

        //knowledge abilities
        if (player.historyProf){
            player.historyMod = player.knowledgeMod + player.playerProficiencyBonus;
        }
        else{
            player.historyMod = player.knowledgeMod;
        }

        if (player.investigationProf){
            player.investigationMod = player.knowledgeMod + player.playerProficiencyBonus;
        }
        else{
            player.investigationMod = player.knowledgeMod;
        }

        if (player.natureProf){
            player.natureMod = player.knowledgeMod + player.playerProficiencyBonus;
        }
        else{
            player.natureMod = player.knowledgeMod;
        }

        if (player.seafaringProf){
            player.seafaringMod = player.knowledgeMod + player.playerProficiencyBonus;
        }
        else{
            player.seafaringMod = player.knowledgeMod;
        }

        if (player.spiritProf){
            player.spiritMod = player.knowledgeMod + player.playerProficiencyBonus;
        }
        else{
            player.spiritMod = player.knowledgeMod;
        }   
        //reason abilities
        if (player.tamingProf){
            player.tamingMod = player.reasonMod + player.playerProficiencyBonus;
        }
        else{
            player.tamingMod = player.reasonMod;
        }

        if (player.huntingProf){
            player.huntingMod = player.reasonMod + player.playerProficiencyBonus;
        }
        else{
            player.huntingMod = player.reasonMod;
        }

        if (player.insightProf){
            player.insightMod = player.reasonMod + player.playerProficiencyBonus;
        }
        else{
            player.insightMod = player.reasonMod;
        }

        if (player.medicineProf){
            player.medicineMod = player.reasonMod + player.playerProficiencyBonus;
        }
        else{
            player.medicineMod = player.reasonMod;
        }

        if (player.perceptionProf){
            player.perceptionMod = player.reasonMod + player.playerProficiencyBonus;
        }
        else{
            player.perceptionMod = player.reasonMod;
        }

        //character abilities
        if (player.deceptionProf){
            player.deceptionMod = player.characterMod + player.playerProficiencyBonus;
        }
        else{
            player.deceptionMod = player.characterMod;
        }

        if (player.intimidationProf){
            player.intimidationMod = player.characterMod + player.playerProficiencyBonus;
        }
        else{
            player.intimidationMod = player.characterMod;
        }

        if (player.performanceProf){
            player.performanceMod = player.characterMod + player.playerProficiencyBonus;
        }
        else{
            player.performanceMod = player.characterMod;
        }

        if (player.persuasionProf){
            player.persuasionMod = player.characterMod + player.playerProficiencyBonus;
        }
        else{
            player.persuasionMod = player.characterMod;
        }

    //done generating all of the stat modifiers
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer: " << player.playerName << "    Style: " << player.playerStyle << "    Path: " << player.playerPath << "    Tier: " << player.playerTier << endl;   
        cout << "Outward: " << player.playerOutward << "    Inward: " << player.playerInward << "    Background: " << player.playerBackground << "    Role: " << player.playerRole << endl << endl;

        switch(player.playerSpiritBond){
            case 0:
                cout << "Spirit Bond: _ _ _\n\n";
                break;
            case 1:
                cout << "Spirit Bond: * _ _\n\n";
                break;
            case 2:
                cout << "Spirit Bond: * * _\n\n";
                break;
            case 3:
                cout << "Spirit Bond: * * *\n\n";
                break;
            default:
                cout << "Spirit Bond: ERROR, YOU SHOULD NOT BE SEEING THIS. PLEASE TALK TO NATHAN\n\n";
        }
        cout << "Proficiency Bonus: +" << player.playerProficiencyBonus << "\n\n--------------------------------------------------------------------------------\n\n";

        cout << "Max Health: " << player.playerHealthMax << "\nHealth: " << player.playerHealth << endl << endl;
        cout << "Max Stamina: " << player.playerStaminaMax << "\nStamina: " << player.playerStamina << endl << endl;
        cout << "Max Fortitude: " << player.playerFortitudeMax << "\nFortitude: " << player.playerFortitude << "\n\n--------------------------------------------------------------------------------\n\n";
        cout << "Power: " << player.playerPower;

        if(player.powerMod < 0){
            cout << " (" << player.powerMod << ")";
        }
        else if(player.powerMod >= 0){
            cout << " (+" << player.powerMod << ")";
        }

        if(player.powerSave){
            cout << "\n* Power Saving Throw:";
        }
        else{
            cout << "\n_ Power Saving Throw:";
        }

        if(player.powerSaveMod < 0){
            cout << " (" << player.powerSaveMod << ")";
        }
        else if(player.powerSaveMod >= 0){
            cout << " (+" << player.powerSaveMod << ")";
        }
        cout << "\n\n";


        cout << "Finesse: " << player.playerFinesse;

        if(player.finesseMod < 0){
            cout << " (" << player.finesseMod << ")";
        }
        else if(player.finesseMod >= 0){
            cout << " (+" << player.finesseMod << ")";
        }

        if(player.finesseSave){
            cout << "\n* Finesse Saving Throw:";
        }
        else{
            cout << "\n_ Finesse Saving Throw:";
        }

        if(player.finesseSaveMod < 0){
            cout << " (" << player.finesseSaveMod << ")";
        }
        else if(player.finesseSaveMod >= 0){
            cout << " (+" << player.finesseSaveMod << ")";
        }
        cout << "\n\n";


        cout << "Vitality: " << player.playerVitality;

        if(player.vitalityMod < 0){
            cout << " (" << player.vitalityMod << ")";
        }
        else if(player.vitalityMod >= 0){
            cout << " (+" << player.vitalityMod << ")";
        }

        if(player.vitalitySave){
            cout << "\n* Vitality Saving Throw:";
        }
        else{
            cout << "\n_ Vitality Saving Throw:";
        }

        if(player.vitalitySaveMod < 0){
            cout << " (" << player.vitalitySaveMod << ")";
        }
        else if(player.vitalitySaveMod >= 0){
            cout << " (+" << player.vitalitySaveMod << ")";
        }
        cout << "\n\n";


        cout << "Knowledge: " << player.playerKnowledge;

        if(player.knowledgeMod < 0){
            cout << " (" << player.knowledgeMod << ")";
        }
        else if(player.knowledgeMod >= 0){
            cout << " (+" << player.knowledgeMod << ")";
        }

        if(player.knowledgeSave){
            cout << "\n* Knowledge Saving Throw:";
        }
        else{
            cout << "\n_ Knowledge Saving Throw:";
        }

        if(player.knowledgeSaveMod < 0){
            cout << " (" << player.knowledgeSaveMod << ")";
        }
        else if(player.knowledgeSaveMod >= 0){
            cout << " (+" << player.knowledgeSaveMod << ")";
        }
        cout << "\n\n";


        cout << "Reason: " << player.playerReason;

        if(player.reasonMod < 0){
            cout << " (" << player.reasonMod << ")";
        }
        else if(player.reasonMod >= 0){
            cout << " (+" << player.reasonMod << ")";
        }

        if(player.reasonSave){
            cout << "\n* Reason Saving Throw:";
        }
        else{
            cout << "\n_ Reason Saving Throw:";
        }

        if(player.reasonSaveMod < 0){
            cout << " (" << player.reasonSaveMod << ")";
        }
        else if(player.reasonSaveMod >= 0){
            cout << " (+" << player.reasonSaveMod << ")";
        }
        cout << "\n\n";


        cout << "Character: " << player.playerCharacter;

        if(player.characterMod < 0){
            cout << " (" << player.characterMod << ")";
        }
        else if(player.characterMod >= 0){
            cout << " (+" << player.characterMod << ")";
        }

        if(player.characterSave){
            cout << "\n* Character Saving Throw:";
        }
        else{
            cout << "\n_ Character Saving Throw:";
        }

        if(player.characterSaveMod < 0){
            cout << " (" << player.characterSaveMod << ")";
        }
        else if(player.characterSaveMod >= 0){
            cout << " (+" << player.characterSaveMod << ")";
        }
        cout << "\n\n--------------------------------------------------------------------------------\n\n";

        cout << "Power:";

        if(player.athleticsProf){
            cout << "\n* Athletics";
        }
        else{
            cout << "\n_ Athletics";
        }
        
        if(player.athleticsMod < 0){
            cout << " (" << player.athleticsMod << ")";
        }
        else if(player.athleticsMod >= 0){
            cout << " (+" << player.athleticsMod << ")";
        }
        cout << "\n\n";


        cout << "Finesse:";

        if(player.acrobaticsProf){
            cout << "\n* Acrobatics";
        }
        else{
            cout << "\n_ Acrobatics";
        }
        
        if(player.acrobaticsMod < 0){
            cout << " (" << player.acrobaticsMod << ")";
        }
        else if(player.acrobaticsMod >= 0){
            cout << " (+" << player.acrobaticsMod << ")";
        }

        if(player.escamotageProf){
            cout << "\n* Escamotage";
        }
        else{
            cout << "\n_ Escamotage";
        }
        
        if(player.escamotageMod < 0){
            cout << " (" << player.escamotageMod << ")";
        }
        else if(player.escamotageMod >= 0){
            cout << " (+" << player.escamotageMod << ")";
        }

        if(player.stealthProf){
            cout << "\n* Stealth";
        }
        else{
            cout << "\n_ Stealth";
        }
        
        if(player.stealthMod < 0){
            cout << " (" << player.stealthMod << ")";
        }
        else if(player.stealthMod >= 0){
            cout << " (+" << player.stealthMod << ")";
        }
        cout << "\n\n";


        cout << "Vitality:";

        if(player.willpowerProf){
            cout << "\n* Willpower";
        }
        else{
            cout << "\n_ Willpower";
        }
        
        if(player.willpowerMod < 0){
            cout << " (" << player.willpowerMod << ")";
        }
        else if(player.willpowerMod >= 0){
            cout << " (+" << player.willpowerMod << ")";
        }
        cout << "\n\n";


        cout << "Knowledge:";

        if(player.historyProf){
            cout << "\n* History";
        }
        else{
            cout << "\n_ History";
        }
        
        if(player.historyMod < 0){
            cout << " (" << player.historyMod << ")";
        }
        else if(player.historyMod >= 0){
            cout << " (+" << player.historyMod << ")";
        }

        if(player.investigationProf){
            cout << "\n* Investigation";
        }
        else{
            cout << "\n_ Investigation";
        }
        
        if(player.investigationMod < 0){
            cout << " (" << player.investigationMod << ")";
        }
        else if(player.investigationMod >= 0){
            cout << " (+" << player.investigationMod << ")";
        }

        if(player.natureProf){
            cout << "\n* Nature";
        }
        else{
            cout << "\n_ Nature";
        }
        
        if(player.natureMod < 0){
            cout << " (" << player.natureMod << ")";
        }
        else if(player.natureMod >= 0){
            cout << " (+" << player.natureMod << ")";
        }

        if(player.seafaringProf){
            cout << "\n* Seafaring";
        }
        else{
            cout << "\n_ Seafaring";
        }
        
        if(player.seafaringMod < 0){
            cout << " (" << player.seafaringMod << ")";
        }
        else if(player.seafaringMod >= 0){
            cout << " (+" << player.seafaringMod << ")";
        }

        if(player.spiritProf){
            cout << "\n* Spirit";
        }
        else{
            cout << "\n_ Spirit";
        }
        
        if(player.spiritMod < 0){
            cout << " (" << player.spiritMod << ")";
        }
        else if(player.spiritMod >= 0){
            cout << " (+" << player.spiritMod << ")";
        }


        cout << "\n\nReason:";

        if(player.tamingProf){
            cout << "\n* Taming";
        }
        else{
            cout << "\n_ Taming";
        }
        
        if(player.tamingMod < 0){
            cout << " (" << player.tamingMod << ")";
        }
        else if(player.tamingMod >= 0){
            cout << " (+" << player.tamingMod << ")";
        }

        if(player.huntingProf){
            cout << "\n* Hunting";
        }
        else{
            cout << "\n_ Hunting";
        }
        
        if(player.huntingMod < 0){
            cout << " (" << player.huntingMod << ")";
        }
        else if(player.huntingMod >= 0){
            cout << " (+" << player.huntingMod << ")";
        }

        if(player.insightProf){
            cout << "\n* Insight";
        }
        else{
            cout << "\n_ Insight";
        }
        
        if(player.insightMod < 0){
            cout << " (" << player.insightMod << ")";
        }
        else if(player.insightMod >= 0){
            cout << " (+" << player.insightMod << ")";
        }

        if(player.medicineProf){
            cout << "\n* Medicine";
        }
        else{
            cout << "\n_ Medicine";
        }
        
        if(player.medicineMod < 0){
            cout << " (" << player.medicineMod << ")";
        }
        else if(player.medicineMod >= 0){
            cout << " (+" << player.medicineMod << ")";
        }

        if(player.perceptionProf){
            cout << "\n* Perception";
        }
        else{
            cout << "\n_ Perception";
        }
        
        if(player.perceptionMod < 0){
            cout << " (" << player.perceptionMod << ")";
        }
        else if(player.perceptionMod >= 0){
            cout << " (+" << player.perceptionMod << ")";
        }


        cout << "\n\nCharacter:";

        if(player.deceptionProf){
            cout << "\n* Deception";
        }
        else{
            cout << "\n_ Deception";
        }
        
        if(player.deceptionMod < 0){
            cout << " (" << player.deceptionMod << ")";
        }
        else if(player.deceptionMod >= 0){
            cout << " (+" << player.deceptionMod << ")";
        }

        if(player.intimidationProf){
            cout << "\n* Intimidation";
        }
        else{
            cout << "\n_ Intimidation";
        }
        
        if(player.intimidationMod < 0){
            cout << " (" << player.intimidationMod << ")";
        }
        else if(player.intimidationMod >= 0){
            cout << " (+" << player.intimidationMod << ")";
        }

        if(player.performanceProf){
            cout << "\n* Performance";
        }
        else{
            cout << "\n_ Performance";
        }
        
        if(player.performanceMod < 0){
            cout << " (" << player.performanceMod << ")";
        }
        else if(player.performanceMod >= 0){
            cout << " (+" << player.performanceMod << ")";
        }

        if(player.persuasionProf){
            cout << "\n* Persuasion";
        }
        else{
            cout << "\n_ Persuasion";
        }
        
        if(player.persuasionMod < 0){
            cout << " (" << player.persuasionMod << ")";
        }
        else if(player.persuasionMod >= 0){
            cout << " (+" << player.persuasionMod << ")";
        }
        cout << "\n\n--------------------------------------------------------------------------------\n\n";

        cout << "Features:\n";
        cout << "1. Filler feature\n    -This feature will remain here until Nathan gets his shit together and properly adds features to this barely functional program.\n\n";

        cout << "Party Members:\n";
        ifstream reading;
        int count = 0;
        for (int i = 0; i < player.partyCount; i++){
            cout << (i + 1) << ". " << player.playerParty[i] << endl;
        }

        cout << "\nAllies:\n";
        count = 0;
        for (int i = 0; i < player.alliesCount; i++){
            cout << (i + 1) << ". " << player.playerAllies[i] << endl;
        }

        cout << "\nImportant Notes:\n";
        cout << "1. I probably won't add support for notes, if I every do it will be after I figure out how to allow input with spaces first. For now just write it down yourself (lazy bums).";

        cout << "\n\nInventory:\n";
        count = 0;
        for (int i = 0; i < player.inventoryCount; i++){
            cout << (i + 1) << ". " << player.playerInventory[i] << endl;
        }

        cout << "\nCopper: " << player.playerCopper << "cp  Silver: " << player.playerSilver << "sp  Gold: " << player.playerGold << "gp";

        cout << "\n\n--------------------------------------------------------------------------------\n\n";
        for(int i = 0; i < player.scrollCount; i++){
            cout << (i + 1) << ". " << player.scrollName[i] << "\n  Tier: " << player.scrollTier[i] << "\n  -" << player.scrollDescription[i] << endl << endl;
        }

        cout << "\n1. Roll for Stat\n2. Roll for Scroll Attack\n3. Roll for Weapon Attack\n4. Edit Something\n5. Quit\n";
        cin >> userAnswer;
        switch(userAnswer){
            case 1:
                cout << "1. Power\n2. Power Save\n3. Finesse\n4. Finesse Save\n5. Vitality\n6. Vitality Save\n7. Knowledge\n8. Knowledge Save\n9. Reason\n10. Reason Save\n11. Character\n12. Character Save\n13. Athletics\n14. Acrobatics\n15. Escamotage\n16. Stealth\n17. Willpower\n18. History\n19. Investigation\n20. Nature\n21. Seafaring\n22. Spirit\n23. Taming\n24. Hunting\n25. Insight\n26. Medicine\n27. Perception\n28. Deception\n29. Intimidation\n30. Performance\n31. Persuasion\n32. Back\n";
                cin >> userAnswer;
                switch(userAnswer){
                    case 1:
                       statRoll(player.powerMod, "Power");
                       break;
                    case 2:
                       statRoll(player.powerSaveMod, "Power Save");
                       break;
                    case 3:
                       statRoll(player.finesseMod, "Finesse");
                       break;
                    case 4:
                       statRoll(player.finesseSaveMod, "Finesse Save");
                       break;
                    case 5:
                       statRoll(player.vitalityMod, "Vitality");
                       break;
                    case 6:
                       statRoll(player.vitalitySaveMod, "Vitality Save");
                       break;
                    case 7:
                       statRoll(player.knowledgeMod, "Knowledge");
                       break;
                    case 8:
                       statRoll(player.knowledgeSaveMod, "Knowledge Save");
                       break;
                    case 9:
                       statRoll(player.reasonMod, "Reason");
                       break;
                    case 10:
                       statRoll(player.reasonSaveMod, "Reason Save");
                       break;
                    case 11:
                       statRoll(player.characterMod, "Character");
                       break;
                    case 12:
                       statRoll(player.characterSaveMod, "Character Save");
                       break;
                    case 13:
                       statRoll(player.athleticsMod, "Athletics");
                       break;
                    case 14:
                       statRoll(player.acrobaticsMod, "Acrobatics");
                       break;
                    case 15:
                       statRoll(player.escamotageMod, "Escamotage");
                       break;
                    case 16:
                       statRoll(player.stealthMod, "Stealth");
                       break;
                    case 17:
                       statRoll(player.willpowerMod, "Willpower");
                       break;
                    case 18:
                       statRoll(player.historyMod, "History");
                       break;
                    case 19:
                       statRoll(player.investigationMod, "Investigation");
                       break;
                    case 20:
                       statRoll(player.natureMod, "Nature");
                       break;
                    case 21:
                       statRoll(player.seafaringMod, "Seafaring");
                       break;
                    case 22:
                       statRoll(player.spiritMod, "Spirit");
                       break;
                    case 23:
                       statRoll(player.tamingMod, "Taming");
                       break;
                    case 24:
                       statRoll(player.huntingMod, "Hunting");
                       break;
                    case 25:
                       statRoll(player.insightMod, "Insight");
                       break;
                    case 26:
                       statRoll(player.medicineMod, "Medicine");
                       break;
                    case 27:
                       statRoll(player.perceptionMod, "Perception");
                       break;
                    case 28:
                       statRoll(player.deceptionMod, "Deception");
                       break;
                    case 29:
                       statRoll(player.intimidationMod, "Intimidation");
                       break;
                    case 30:
                       statRoll(player.performanceMod, "Performance");
                       break;
                    case 31:
                       statRoll(player.persuasionMod, "Persuasion");
                       break;
                    default:
                        break;
                }
                cout << "Input anything to continue...";
                cin >> inputWait;
                break;
            case 2:
                cout << "Which scroll?\n";
                for(int i = 0; i < player.scrollCount; i++){
                    cout << (i + 1) << ". " << player.scrollName[i] << endl;
                }
                cin >> userAnswer;
                if( userAnswer > player.scrollCount ){
                    cout << "Invalid Option\n"; 
                } else{
                    if(player.playerStyle == "Water"){
                        scrollRoll(player.scrollDiceType[userAnswer - 1], player.scrollDiceCount[userAnswer - 1], player.finesseMod, player.scrollDescription[userAnswer - 1], player.scrollName[userAnswer - 1]);
                    }else if(player.playerStyle == "Earth"){
                        scrollRoll(player.scrollDiceType[userAnswer - 1], player.scrollDiceCount[userAnswer - 1], player.powerMod, player.scrollDescription[userAnswer - 1], player.scrollName[userAnswer - 1]);
                    }else if(player.playerStyle == "Fire"){
                        scrollRoll(player.scrollDiceType[userAnswer - 1], player.scrollDiceCount[userAnswer - 1], player.powerMod, player.scrollDescription[userAnswer - 1], player.scrollName[userAnswer - 1]);
                    }else if(player.playerStyle == "Air"){
                        scrollRoll(player.scrollDiceType[userAnswer - 1], player.scrollDiceCount[userAnswer - 1], player.powerMod, player.scrollDescription[userAnswer - 1], player.scrollName[userAnswer - 1]);
//mod for air and devoted are set as power by default, go back and change later after Luis or Josh tells me the correct stat
                    }else if(player.playerStyle == "Devoted"){
                        scrollRoll(player.scrollDiceType[userAnswer - 1], player.scrollDiceCount[userAnswer - 1], player.powerMod, player.scrollDescription[userAnswer - 1], player.scrollName[userAnswer - 1]);
                    }else{
                        cout << "Pretty large error, you don't appear to have a valid style. I honestly don't know how you could have done that.\n";
                        return 0;
                    }
                }
                cout << "Input anything to continue...";
                cin >> inputWait;
                break;
            case 3:
                cout << "I haven't implemented weapons yet, soon though.";
                break;
            case 4:
                cout << "1. Change Name\n2. Style\n3. Path\n4. Tier\n5. Outward\n6. Inward\n7. Background\n8. Role\n9. Spirit Bond\n10. Max Health\n11. Current Health\n12. Max Stamina\n13. Current Stamina\n14. Max Fortitude\n15. Current Fortitude\n16. Stats\n17. Proficiencies\n18. Party Members\n19. Allies\n20. Inventory\n21. Money\n22. Scrolls\n23. Back\n";
                cin >> userAnswer;
                switch(userAnswer){
                    case 1:
                        cout << "What would you like to change your name to?\n";
                        cin >> player.playerName;
                        data.open("Data/Other/name.txt", std::fstream::trunc);
                        data << player.playerName;
                        data.close();
                        break;
                    case 2:
                        condition = 0;
                        while( condition == 0 ) {
                            cout << "What is your character's new style?\n1. Water\n2. Earth\n3. Fire\n4. Air\n5. Devoted" << endl;
                            cin >> userAnswer;        
                            switch(userAnswer){
                                case 1:
                                    player.playerStyle = "Water";
                                    condition = 1;
                                    break;
                                case 2:
                                    player.playerStyle = "Earth";
                                    condition = 1;
                                    break;
                                case 3:
                                    player.playerStyle = "Fire";
                                    condition = 1;
                                    break;
                                case 4:
                                    player.playerStyle = "Air";
                                    condition = 1;
                                    break;
                                case 5:
                                    player.playerStyle = "Devoted";
                                    condition = 1;
                                    break;
                               default:
                                    cout << "Not a valid response, please try again.\n";
                                    break;
                                }    
                            }
                        condition = 0;
                        data.open("Data/Other/style.txt", std::fstream::trunc);
                        data << player.playerStyle;
                        data.close();
                        break;
                    case 3:
                        if( player.playerStyle == "Water" ){
                            while( condition == 0 ) {
                                cout << "What is your character's new path?\n1. Path of Restoration\n2. Path of the Stoic\n3. Path of Subjugation\n4. None" << endl;
                                cin >> userAnswer;        
                                switch(userAnswer){
                                    case 1:
                                        player.playerPath = "Path of Restoration";
                                        condition = 1;
                                        break;
                                    case 2:
                                        player.playerPath = "Path of the Stoic";
                                        condition = 1;
                                        break;
                                    case 3:
                                        player.playerPath = "Path of Subjugation";
                                        condition = 1;
                                        break;
                                    default:
                                        player.playerPath = "None";
                                        condition = 1;
                                        break;} 
                            }
                            condition = 0;
                        } else if( player.playerStyle == "Earth" ){
                            while( condition == 0 ) {
                                cout << "What is your character's new path?\n1. Path of the Peacekeeper\n2. Path of the Purist\n3. Path of the Ravager\n4. None" << endl;
                                cin >> userAnswer;        
                                switch(userAnswer){
                                    case 1:
                                        player.playerPath = "Path of the Peacekeeper";
                                        condition = 1;
                                        break;
                                    case 2:
                                        player.playerPath = "Path of the Purist";
                                        condition = 1;
                                        break;
                                    case 3:
                                        player.playerPath = "Path of the Ravager";
                                        condition = 1;
                                        break;
                                    default:
                                        player.playerPath = "None";
                                        condition = 1;
                                        break;}
                            }
                            condition = 0;
                        } else if( player.playerStyle == "Fire" ){
                            while( condition == 0 ) {
                                cout << "What is your character's new path?\n1. Path of the Elevated\n2. Path of the Zelous\n3. Path of the Fanatic\n4. None" << endl;
                                cin >> userAnswer;        
                                switch(userAnswer){
                                   case 1:
                                        player.playerPath = "Path of the Elevated";
                                        condition = 1;
                                        break;
                                    case 2:
                                        player.playerPath = "Path of the Zelous";
                                        condition = 1;
                                        break;
                                    case 3:
                                        player.playerPath = "Path of the Fanatic";
                                        condition = 1;
                                        break;
                                    default:
                                        player.playerPath = "None";
                                        condition = 1;
                                        break;}
                            }
                            condition = 0;
                        } else if( player.playerStyle == "Air" ){
                            while( condition == 0 ) {
                                cout << "What is your character's new path?\n1. Path of Peace\n2. Path of Indifference\n3. Path of Conflict\n4. None" << endl;
                                cin >> userAnswer;        
                                switch(userAnswer){
                                    case 1:
                                        player.playerPath = "Path of Peace";
                                        condition = 1;
                                        break;
                                    case 2:
                                        player.playerPath = "Path of Indifference";
                                        condition = 1;
                                        break;
                                    case 3:
                                        player.playerPath = "Path of Conflict";
                                        condition = 1;
                                        break;
                                    default:
                                        player.playerPath = "None";
                                        condition = 1;
                                        break;}
                            }
                                condition = 0;
                        } else if( player.playerStyle == "Devoted" ){
                            while( condition == 0 ) {
                                cout << "What is your character's new path?\n1. Spirit Blocker\n2. The Duelist\n3. The Assassin\n4. None" << endl;
                                cin >> userAnswer;        
                                switch(userAnswer){
                                    case 1:
                                        player.playerPath = "Spirit Blocker";
                                        condition = 1;
                                        break;
                                    case 2:
                                        player.playerPath = "The Duelist";
                                        condition = 1;
                                        break;
                                    case 3:
                                        player.playerPath = "The Assassin";
                                        condition = 1;
                                        break;
                                    default:
                                        player.playerPath = "None";
                                        condition = 1;
                                        break;}
                            }
                            condition = 0;
                    }
                        data.open("Data/Other/path.txt", std::fstream::trunc);
                        data << player.playerPath;
                        data.close();
                        break;
                    case 4:
                        cout << "What is your new tier?\n";
                        cin >> userAnswer;
                            switch(userAnswer){
                                case 2:
                                    player.playerTier = 2;
                                    break;
                                case 3:
                                    player.playerTier  = 3;
                                    break;
                                case 4:
                                    player.playerTier = 4;
                                    break;
                                default:
                                    player.playerTier = 1;
                                    break;
                        data.open("Data/Other/tier.txt", std::fstream::trunc);
                        data << player.playerTier;
                        data.close();
                            }
                        break;
                    case 5:
                        cout << "What is your character's new outward personality?" << endl << "1. Benevolent\n2. Ambivalent\n3. Malevolent\n";
                        cin >> userAnswer;        
                        switch(userAnswer){
                            case 1:
                                player.playerOutward = "Benevolent";
                                break;
                            case 3:
                                player.playerOutward = "Malevolent";
                                break;
                            default:
                                player.playerOutward = "Ambivalent";
                                break;
                        }
                        data.open("Data/Other/outward.txt", std::fstream::trunc);
                        data << player.playerOutward;
                        data.close();
                        break;
                    case 6:
                        cout << "What is your character's new inward personality?" << endl << "1. Benevolent\2. Ambivalent\n3. Malevolent\n";
                        cin >> userAnswer;        
                        switch(userAnswer){
                            case 1:
                                player.playerInward = "Benevolent";
                                break;
                            case 3:
                                player.playerInward = "Malevolent";
                                break;
                            default:
                                player.playerInward = "Ambivalent";
                                break;
                        }
                        data.open("Data/Other/inawrd.txt", std::fstream::trunc);
                        data << player.playerInward;
                        data.close();
                        break;
                    case 7:
                        cout << "What is your character's new background?\n";
                        cin >> player.playerBackground;
                        data.open("Data/Other/background.txt", std::fstream::trunc);
                        data << player.playerBackground;
                        data.close();
                        break;
                    case 8:
                        cout << "What is your character's new role?\n";
                        cin >> player.playerRole;
                        data.open("Data/Other/role.txt", std::fstream::trunc);
                        data << player.playerRole;
                        data.close();
                        break;
                    case 9:
                        cout << "How many spirit bonds do you have? 0, 1, 2, or 3.\n";
                        cin >> userAnswer;
                        switch(userAnswer){
                            case 1: 
                                player.playerSpiritBond = 1;
                                break;
                            case 2:
                                player.playerSpiritBond = 2;
                                break;
                            case 3:
                                player.playerSpiritBond = 3;
                                break;
                            default:
                                player.playerSpiritBond = 0;
                                break;
                        }
                        data.open("Data/Other/spiritBond.txt", std::fstream::trunc);
                        data << player.playerSpiritBond;    
                        data.close();
                        break;
                    case 10:
                        break;
                    case 11:
                        break;
                    case 12:
                        break;
                    case 13:
                        break;
                    case 14:
                        break;
                    case 15:
                        break;
                    case 16:
                        break;
                    case 17:
                        break;
                    case 18:
                        break;
                    case 19:
                        break;
                    case 20:
                        break;
                    case 21:
                        break;
                    case 22:
                        break;
                    default:
                        break;
                }
                break;
            default:
                return 0;
        }



    //get rid of this return statement in final version
        //return 0;

    }
    //cout << player.playerName << endl << player.playerAllies[0] << endl;
    return 0;
};

int diceRoll(int diceType, int diceCount, int diceMod){
    int roll;
    int rollNoMod;
    int rollSum = 0;
    int rollSumNoMod = 0;
    int absMod = abs (diceMod);
    for(int i = 0; i < diceCount; i++){
        rollNoMod = ((rand()%diceType) + 1);
        roll = rollNoMod + diceMod;
        if(diceMod == 0){
            cout << "Roll number " << (i + 1) << ": " << roll << endl;
        }
        else if(diceMod < 0){
            cout << "Roll number " << (i + 1) << ": " << roll << " (" << rollNoMod << " -" << absMod << ")" << endl;
        }
        else{
            cout << "Roll number " << (i + 1) << ": " << roll << " (" << rollNoMod << " +" << absMod << ")" << endl;
        }
        rollSum = rollSum + roll;
        rollSumNoMod = rollSumNoMod + rollNoMod;
    }
    cout << "\nSum of all rolls is " << rollSum << endl;
    cout << "Sum of all roll without modifiers is " << rollSumNoMod << endl;
    return 0;
};
int statRoll(int statMod, string stat){
    ifstream data;
    data.open("Data/Other/chat.txt", std::fstream::app);
    int roll1;
    int roll2;    
    roll1 = (rand()%20) + 1;
    roll2 = (rand()%20) + 1;
    cout << "\n" << stat << ":\n";
    if(statMod < 0){
        cout << "First roll: " << roll1 + statMod << " (" << roll1 << " -" << abs(statMod) << ")\n";
        //data >> "First roll: " << roll1 + statMod << " (" << roll1 << " -" << abs(statMod) << ")\n";
        cout << "Second roll: " << roll2 + statMod << " (" << roll2 << " -" << abs(statMod) << ")\n";
        //data >> "Second roll: " << roll2 + statMod << " (" << roll2 << " -" << abs(statMod) << ")\n";
    } else{
        cout << "First roll: " << roll1 + statMod << " (" << roll1 << " +" << statMod << ")\n";
        //data >> "First roll: " << roll1 + statMod << " (" << roll1 << " +" << statMod << ")\n";
        cout << "Second roll: " << roll2 + statMod << " (" << roll2 << " +" << statMod << ")\n";
        //data >> "Second roll: " << roll2 + statMod << " (" << roll2 << " +" << statMod << ")\n";
    }
    return 0;
};
int scrollRoll(int diceType, int diceCount, int diceMod, string description, string name){
    int roll;
    int rollSum = 0;
    if(diceCount == 0){
        cout << "\nThis is not an attacking move.\n";
        return 0;
    }
    cout << "(";
    for(int i = 0; i < diceCount; i++){
        roll = (rand()%diceType) + 1;
        cout << roll << ", ";
        rollSum = rollSum + roll;
    }
    //cout << ")\nYou rolled a " << rollSum + diceMod << "";
    if(diceMod < 0){
        cout << ")\nYou rolled a(n) " << rollSum + diceMod << " (" << rollSum << " -" << abs(diceMod) << ")\n";
        return 0;
    } else{
        cout << ")\nYou rolled a(n) " << rollSum + diceMod << " (" << rollSum << " +" << diceMod << ")\n";
        return 0;
    }
    return 0;
};
