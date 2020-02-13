//NEED TO ADD WEAPONS AT SOME POINT
//need to update background editor
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

int whichScroll;


int allScrollNumber = 98;
string allScrollNames[98];
string allScrollDescriptions[98];
int allScrollDiceTypes[98];
int allScrollDiceCounts[98];
string allScrollRanges[98];
string allScrollActions[98];
string allScrollTypes[98];
int allScrollTiers[98];
bool allscrollExtraDamages[98];
bool allScrollHaveExtraDamages[98];

//if you ever update these Max values make sure to change the corresponding array lengths

struct characterInfo{
    string playerName;
    string playerStyle;
    string playerPath;
    int playerTier;
    string playerOutward;
    string playerInward;
    string playerBackground;
    string playerSubBackground;
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
    string scrollDescriptionDamage[14];
    string scrollDescriptionActive[14];
    int scrollDiceType[14];
    int scrollDiceCount[14];
    string scrollRange[14];
    string scrollAction[14];
    string scrollStyle[14];
    int scrollTier[14];

    bool scrollExtraDamage[14];
    bool scrollHaveExtraDamage[14];

    bool scrollHalfAction[14];
    bool scrollHaveHalfAction[14];

    bool scrollExtraDie[14];
    bool scrollHaveExtraDie[14];

    bool scrollExtraRange[14];
    bool scrollHaveExtraRange[14];

    bool scrollHigherSave[14];
    bool scrollHaveHigherSave[14];

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
int scrollRoll(int diceType, int diceCount, int diceMod, string description, string name, string type);
int eraseScrolls();

int main(){
//setting up random number generator
    srand (time(NULL));

    ifstream extracting;
    extracting.open("Scrolls/name.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof()){
        getline(extracting, allScrollNames[count]);
        count = count + 1;
    }
    extracting.close();


    characterInfo characterData;
    while( condition == 0 ) {
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
    ifstream extracting;
    cout << "Welcome to the character creator! Just follow the instructions to create your character. Don't worry if you input something incorrectly. You can go back and change it later so just continue filling in everything else." << endl << endl;

    cout << "What is your character's name?" << endl;
    cin.ignore();
    cin.clear();
    getline(cin, player.playerName);
    data.open("Data/Other/name.txt", std::fstream::trunc);
    data << player.playerName;
    data.close();

    valid = false;
    while( condition == 0 ) {
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
    data.open("Data/Other/tier.txt", std::fstream::trunc);
    data << player.playerTier;
    data.close();


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
    data.open("Data/Other/inward.txt", std::fstream::trunc);
    data << player.playerInward;
    data.close();


    valid = false;
        while(!valid){
            cout << "\nWhat is your character's background?\n1. Seaman\n2. Townsfolk\n3. Official\n4. Traveler\n5. Urchin\n6. Warrior\n" << endl;
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
            player.playerBackground = "Seaman";
            break;
        case 2:
            player.playerBackground = "Townsfolk";
            break;
        case 3:
            player.playerBackground = "Official";
            break;
        case 4:
            player.playerBackground = "Traveler";
            break;
        case 5:
            player.playerBackground = "Urchin";
            break;
        case 6:
            player.playerBackground = "Warrior";
            break;
        default:
            player.playerBackground = "None";
            break;
    }


    valid = false;
        while(!valid){
            cout << "\nWhat is your character's secondary background?\n";
            if(player.playerBackground == "Seaman"){
                cout << "1. Fisherman\n2. Sailor\n";
            }else if(player.playerBackground == "Townsfolk"){
                cout << "1. Inkeep\n2. Merchant\n";
            }else if(player.playerBackground == "Official"){
                cout << "1. Councilman\n2. Peacekeeper\n";
            }else if(player.playerBackground == "Traveler"){
                cout << "1. Huntsman\n2. Guide\n";
            }else if(player.playerBackground == "Urchin"){
                cout << "1. Thief\n2. Pirate\n";
            }else if(player.playerBackground == "Warrior"){
                cout << "1. Mercenary\n2. Soldier\n";
            }else{
                userAnswer = -1;
                break;
            }
            valid = true;
            cin >> userAnswer;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "Please enter a number (especially you, Michael)\n";
                valid = false;
            }
        }
    int featureNumber = -1;
    player.featureCount = 1;
    if(player.playerBackground == "Seaman"){
        switch(userAnswer){
            case 1:
                player.playerSubBackground = "Fisherman";
                featureNumber = 1;
                break;
            case 2:
                player.playerSubBackground = "Sailor";
                featureNumber = 2;
                break;
            default:
                player.playerSubBackground = "None";
                break;
        }
    }else if(player.playerBackground == "Townsfolk"){
        switch(userAnswer){
            case 1:
                player.playerSubBackground = "Innkeep";
                featureNumber = 3;
                break;
            case 2:
                player.playerSubBackground = "Merchant";
                featureNumber = 4;
                break;
            default:
                player.playerSubBackground = "None";
                break;
        }
    }else if(player.playerBackground == "Official"){
        switch(userAnswer){
            case 1:
                player.playerSubBackground = "Councilman";
                featureNumber = 5;
                break;
            case 2:
                player.playerSubBackground = "Peacekeeper";
                featureNumber = 6;
                break;
            default:
                player.playerSubBackground = "None";
                break;
        }
    }else if(player.playerBackground == "Traveler"){
        switch(userAnswer){
            case 1:
                player.playerSubBackground = "Huntsman";
                featureNumber = 7;
                break;
            case 2:
                player.playerSubBackground = "Guide";
                featureNumber = 8;
                break;
            default:
                player.playerSubBackground = "None";
                break;
        }
    }else if(player.playerBackground == "Urchin"){
        switch(userAnswer){
            case 1:
                player.playerSubBackground = "Thief";
                featureNumber = 9;
                break;
            case 2:
                player.playerSubBackground = "Pirate";
                featureNumber = 10;
                break;
            default:
                player.playerSubBackground = "None";
                break;
        }
    }else if(player.playerBackground == "Warrior"){
        switch(userAnswer){
            case 1:
                player.playerSubBackground = "Mercenary";
                featureNumber = 11;
                break;
            case 2:
                player.playerSubBackground = "Soldier";
                featureNumber = 12;
                break;
            default:
                player.playerSubBackground = "None";
                break;
        }
    }else{
        player.playerSubBackground = "None";
    }
    cout << player.playerSubBackground << endl;
    data.open("Data/Other/background.txt", std::fstream::trunc);
    data << player.playerBackground;
    data.close();

    data.open("Data/Other/subBackground.txt", std::fstream::trunc);
    data << player.playerSubBackground;
    data.close();

//determine features
    if(featureNumber == -1){
        player.featureName[0] = "";
        player.featureDescription[0] = "";
    }else{
        count = 0;
        extracting.open("Features/featureName.txt", std::ifstream::in);
        while(!extracting.eof()){
            count++;
            if(count != featureNumber){
                getline(extracting, tempString);
            } else{
                getline(extracting, player.featureName[0]);
            }
        }
        extracting.close();
        count = 0;
        extracting.open("Features/featureDescription.txt", std::ifstream::in);
        while(!extracting.eof()){
            count++;
            if(count != featureNumber){
                getline(extracting, tempString);
            } else{
                getline(extracting, player.featureDescription[0]);
            }
        }
        extracting.close();
    }
    cout << "\n\n" << player.featureName[0] << "\n" << player.featureDescription[0] << "\n\n";

    data.open("Data/Features/featureNames.txt", std::fstream::trunc);
    data << player.featureName[0] << endl;
    data.close();

    data.open("Data/Features/featureDescriptions.txt", std::fstream::trunc);    
    data << player.featureDescription[0] << endl;
    data.close();

    data.open("Data/Features/featureCount.txt", std::fstream::trunc);
    data << player.featureCount;
    data.close();



//initialize saving throws and proficiencies
    player.powerSave = false;
    player.finesseSave = false;
    player.vitalitySave = false;
    player.knowledgeSave = false;
    player.reasonSave = false;
    player.characterSave = false;
    player.athleticsProf = false;
    player.acrobaticsProf = false;
    player.escamotageProf = false;
    player.stealthProf = false;
    player.willpowerProf = false;
    player.historyProf = false;
    player.investigationProf = false;
    player.natureProf = false;
    player.seafaringProf = false;
    player.spiritProf = false;
    player.tamingProf = false;
    player.huntingProf = false;
    player.insightProf = false;
    player.medicineProf = false;
    player.perceptionProf = false;
    player.deceptionProf = false;
    player.intimidationProf = false;
    player.performanceProf = false;
    player.persuasionProf = false;




cout << player.reasonSave << endl;

//generate specific saving throws and proficiencies
    if(player.playerSubBackground == "Fisherman"){
        player.finesseSave = true;
        player.knowledgeSave = true;
        player.performanceProf = true;
        player.seafaringProf = true;
        player.historyProf = true;
        player.huntingProf = true;
    }else if(player.playerSubBackground == "Sailor"){
        player.finesseSave = true;
        player.knowledgeSave = true;
        player.performanceProf = true;
        player.seafaringProf = true;
        player.athleticsProf = true;
        player.stealthProf = true;
    }else if(player.playerSubBackground == "Merchant"){
        player.characterSave = true;
        player.knowledgeSave = true;
        player.insightProf = true;
        player.investigationProf = true;
        player.performanceProf = true;
        player.persuasionProf = true;
    }else if(player.playerSubBackground == "Official"){
        player.characterSave = true;
        player.knowledgeSave = true;
        player.insightProf = true;
        player.investigationProf = true;
        player.historyProf = true;
        player.spiritProf = true;
    }else if(player.playerSubBackground == "Huntsman"){
        player.reasonSave = true;
        player.vitalitySave = true;
        player.natureProf = true;
        player.perceptionProf = true;
        player.huntingProf = true;
        player.investigationProf = true;
    }else if(player.playerSubBackground == "Guide"){
        player.reasonSave = true;
        player.vitalitySave = true;
        player.natureProf = true;
        player.perceptionProf = true;
        player.medicineProf = true;
        player.spiritProf = true;
    }else if(player.playerSubBackground == "Thief"){
        player.characterSave = true;
        player.finesseSave = true;
        player.escamotageProf = true;
        player.stealthProf = true;
        player.acrobaticsProf = true;
        player.deceptionProf = true;
    }else if(player.playerSubBackground == "Pirate"){
        player.characterSave = true;
        player.finesseSave = true;
        player.escamotageProf = true;
        player.stealthProf = true;
        player.perceptionProf = true;
        player.seafaringProf = true;
    }else if(player.playerSubBackground == "Mercenary"){
        player.powerSave = true;
        player.vitalitySave = true;
        player.athleticsProf = true;
        player.perceptionProf = true;
        player.intimidationProf = true;
        player.persuasionProf = true;
    }else if(player.playerSubBackground == "Soldier"){
        player.powerSave = true;
        player.vitalitySave = true;
        player.athleticsProf = true;
        player.perceptionProf = true;
        player.insightProf = true;
        player.medicineProf = true;
    }

    data.open("Data/Stats/powerSave.txt", std::fstream::trunc);
    data << player.powerSave;
    data.close();
    data.open("Data/Stats/finesseSave.txt", std::fstream::trunc);
    data << player.finesseSave;
    data.close();
    data.open("Data/Stats/vitalitySave.txt", std::fstream::trunc);
    data << player.vitalitySave;
    data.close();
    data.open("Data/Stats/knowledgeSave.txt", std::fstream::trunc);
    data << player.knowledgeSave;
    data.close();
    data.open("Data/Stats/reasonSave.txt", std::fstream::trunc);
    data << player.reasonSave;
    data.close();
    data.open("Data/Stats/characterSave.txt", std::fstream::trunc);
    data << player.characterSave;
    data.close();

    data.open("Data/Proficiencies/athletics.txt", std::fstream::trunc);
    data << player.athleticsProf;
    data.close();
    data.open("Data/Proficiencies/acrobatics.txt", std::fstream::trunc);
    data << player.acrobaticsProf;
    data.close();
    data.open("Data/Proficiencies/escamotage.txt", std::fstream::trunc);
    data << player.escamotageProf;
    data.close();
    data.open("Data/Proficiencies/stealth.txt", std::fstream::trunc);
    data << player.stealthProf;
    data.close();
    data.open("Data/Proficiencies/willpower.txt", std::fstream::trunc);
    data << player.willpowerProf;
    data.close();
    data.open("Data/Proficiencies/history.txt", std::fstream::trunc);
    data << player.historyProf;
    data.close();
    data.open("Data/Proficiencies/investigation.txt", std::fstream::trunc);
    data << player.investigationProf;
    data.close();
    data.open("Data/Proficiencies/nature.txt", std::fstream::trunc);
    data << player.natureProf;
    data.close();
    data.open("Data/Proficiencies/seafaring.txt", std::fstream::trunc);
    data << player.seafaringProf;
    data.close();
    data.open("Data/Proficiencies/spirit.txt", std::fstream::trunc);
    data << player.spiritProf;
    data.close();
    data.open("Data/Proficiencies/taming.txt", std::fstream::trunc);
    data << player.tamingProf;
    data.close();
    data.open("Data/Proficiencies/hunting.txt", std::fstream::trunc);
    data << player.huntingProf;
    data.close();
    data.open("Data/Proficiencies/insight.txt", std::fstream::trunc);
    data << player.insightProf;
    data.close();
    data.open("Data/Proficiencies/medicine.txt", std::fstream::trunc);
    data << player.medicineProf;
    data.close();
    data.open("Data/Proficiencies/perception.txt", std::fstream::trunc);
    data << player.perceptionProf;
    data.close();
    data.open("Data/Proficiencies/deception.txt", std::fstream::trunc);
    data << player.deceptionProf;
    data.close();
    data.open("Data/Proficiencies/intimidation.txt", std::fstream::trunc);
    data << player.intimidationProf;
    data.close();
    data.open("Data/Proficiencies/performance.txt", std::fstream::trunc);
    data << player.performanceProf;
    data.close();
    data.open("Data/Proficiencies/persuasion.txt", std::fstream::trunc);
    data << player.persuasionProf;
    data.close();



    cout << "\nWhat is your character's role?" << endl;
    cin.clear();
    cin.ignore();
    getline(cin, player.playerRole);
    //cin >> player.playerRole;
    data.open("Data/Other/role.txt", std::fstream::trunc);
    data << player.playerRole;
    data.close();

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

//power stat
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

//finesse stat
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

//vitality stat
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

//knowledge stat
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

//reason stat
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

//character stat
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
/*
//inventory support will come later
    condition = 0;
    while( condition == 0 ) {
        valid = false;
        while(!valid){
            cout << "\nHow many items do you have in your inventory?\n";
            valid = true;
            cin >> userAnswer;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "Please enter a number (especially you, Michael)\n";
                valid = false;
            }
        }
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
*/
//notes support will come later (probably not)
//features support will come later

//scrolls support will come later
    int condition = 0;
    while( condition == 0 ) {
        valid = false;
        while(!valid){
            cout << "\nHow many scrolls do you have? There is a maximum of 14.\n";
            valid = true;
            cin >> userAnswer;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "Please enter a number (especially you, Michael)\n";
                valid = false;
            }
        }
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

    eraseScrolls();

    for(int i = 0; i < player.scrollCount; i++){
        if(player.playerStyle == "Water"){
            valid = false;
            while(!valid){
                cout << "\n1. " << allScrollNames[0] << "\n2. " << allScrollNames[1] << "\n3. " << allScrollNames[2] << "\n4. " << allScrollNames[3] << "\n5. " << allScrollNames[4] << "\n6." << allScrollNames[5] << "\n7." << allScrollNames[6] << "\n8." << allScrollNames[7] << "\n9." << allScrollNames[8] << "\n10." << allScrollNames[9] << "\n11." << allScrollNames[10] << "\n12." << allScrollNames[11] << "\n13." << allScrollNames[12] << "\n14." << allScrollNames[13] << "\n15." << allScrollNames[14] << "\n16." << allScrollNames[15] << "\n17." << allScrollNames[16] << "\n18." << allScrollNames[17] << "\n19." << allScrollNames[18] << "\n20. " << allScrollNames[19] << "\n";
                valid = true;
                cin >> userAnswer;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout << "Please enter a number (especially you, Michael)\n";
                    valid = false;
                }
            }
            if(userAnswer <= 20 && userAnswer >= 1){
                player.scrollName[i] = allScrollNames[userAnswer - 1];
//description damages
                extracting.open("Scrolls/descriptionDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollDescriptionDamage[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//description actives
                extracting.open("Scrolls/descriptionActive.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollDescriptionActive[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//dice types
                extracting.open("Scrolls/diceType.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollDiceType[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//dice counts
                extracting.open("Scrolls/diceCount.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        
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
                        
                    } else{
                        extracting >> player.scrollTier[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//ranges
                extracting.open("Scrolls/range.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        getline(extracting, tempString);
                        
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
                        
                    } else{
                        getline(extracting, player.scrollAction[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//types
                //player.scrollStyle[i] = allScrollTypes[userAnswer - 1];
                extracting.open("Scrolls/style.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollStyle[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//extra damages
                //player.scrollExtraDamage[i] = allscrollExtraDamages[userAnswer - 1];
                extracting.open("Scrolls/extraDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraDamage[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra damages
                //player.scrollHaveExtraDamage[i] = allScrollHaveExtraDamages[userAnswer - 1];
                extracting.open("Scrolls/haveExtraDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraDamage[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//half actions
                extracting.open("Scrolls/halfAction.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHalfAction[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have half actions
                extracting.open("Scrolls/haveHalfAction.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveHalfAction[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//extra dies
                extracting.open("Scrolls/extraDie.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraDie[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra dies
                extracting.open("Scrolls/haveExtraDie.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraDie[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//extra ranges
                extracting.open("Scrolls/extraRange.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraRange[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra ranges
                extracting.open("Scrolls/haveExtraRange.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraRange[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//higher saves
                extracting.open("Scrolls/higherSave.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHigherSave[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have higher saves
                extracting.open("Scrolls/haveHigherSave.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer - 1){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveHigherSave[i];
                    }
                    count = count + 1;
                }
                extracting.close();
            } else{
                player.scrollName[i] = "";
                player.scrollDescriptionDamage[i] = "";
                player.scrollDescriptionActive[i] = "";
                player.scrollDiceType[i] = 0;
                player.scrollDiceCount[i] = 0;
                player.scrollTier[i] = 0;
                player.scrollRange[i] = "";
                player.scrollAction[i] = "";
                player.scrollStyle[i] = "";
                player.scrollExtraDamage[i] = false;
                player.scrollHaveExtraDamage[i] = false;
                player.scrollHalfAction[i] = false;
                player.scrollHaveHalfAction[i] = false;
                player.scrollExtraDie[i] = false;
                player.scrollHaveExtraDie[i] = false;
                player.scrollExtraRange[i] = false;
                player.scrollHaveExtraRange[i] = false;
                player.scrollHigherSave[i] = false;
                player.scrollHaveHigherSave[i] = false;
            }
            data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
            data << player.scrollName[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollDescriptionDamages.txt", std::fstream::app);
            data << player.scrollDescriptionDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollDescriptionActives.txt", std::fstream::app);
            data << player.scrollDescriptionActive[i] << endl;
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
            data.open("Data/Scrolls/scrollStyles.txt", std::fstream::app);
            data << player.scrollStyle[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraDamages.txt", std::fstream::app);
            data << player.scrollExtraDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraDamages.txt", std::fstream::app);
            data << player.scrollHaveExtraDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHalfActions.txt", std::fstream::app);
            data << player.scrollHalfAction[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveHalfActions.txt", std::fstream::app);
            data << player.scrollHaveHalfAction[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraDies.txt", std::fstream::app);
            data << player.scrollExtraDie[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraDies.txt", std::fstream::app);
            data << player.scrollHaveExtraDie[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraRanges.txt", std::fstream::app);
            data << player.scrollExtraRange[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraRanges.txt", std::fstream::app);
            data << player.scrollHaveExtraRange[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHigherSaves.txt", std::fstream::app);
            data << player.scrollHigherSave[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveHigherSaves.txt", std::fstream::app);
            data << player.scrollHaveHigherSave[i] << endl;
            data.close();
        } else if(player.playerStyle == "Earth"){
            valid = false;
            while(!valid){
                cout << "\n1. " << allScrollNames[20] << "\n2. " << allScrollNames[21] << "\n3. " << allScrollNames[22] << "\n4. " << allScrollNames[23] << "\n5. " << allScrollNames[24] << "\n6." << allScrollNames[25] << "\n7." << allScrollNames[26] << "\n8." << allScrollNames[27] << "\n9." << allScrollNames[28] << "\n10." << allScrollNames[29] << "\n11." << allScrollNames[30] << "\n12." << allScrollNames[31] << "\n13." << allScrollNames[32] << "\n14." << allScrollNames[33] << "\n15." << allScrollNames[34] << "\n16." << allScrollNames[35] << "\n17." << allScrollNames[36] << "\n18." << allScrollNames[37] << "\n19." << allScrollNames[38] << "\n20. " << allScrollNames[39] << "\n";
                valid = true;
                cin >> userAnswer;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout << "Please enter a number (especially you, Michael)\n";
                    valid = false;
                }
            }
            if(userAnswer <= 20 && userAnswer >= 1){
                player.scrollName[i] = allScrollNames[userAnswer + 19];
//description damages
                extracting.open("Scrolls/descriptionDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollDescriptionDamage[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//description actives
                extracting.open("Scrolls/descriptionActive.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollDescriptionActive[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//dice types
                extracting.open("Scrolls/diceType.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollDiceType[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//dice counts
                extracting.open("Scrolls/diceCount.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollDiceCount[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//tiers
                extracting.open("Scrolls/tier.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollTier[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//ranges
                extracting.open("Scrolls/range.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollRange[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//actions
                extracting.open("Scrolls/action.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollAction[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//types
                extracting.open("Scrolls/style.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollStyle[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//extra damages
                extracting.open("Scrolls/extraDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraDamage[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra damages
                extracting.open("Scrolls/haveExtraDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraDamage[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//half actions
                extracting.open("Scrolls/halfAction.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHalfAction[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have half actions
                extracting.open("Scrolls/haveHalfAction.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveHalfAction[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//extra dies
                extracting.open("Scrolls/extraDie.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraDie[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra dies
                extracting.open("Scrolls/haveExtraDie.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraDie[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//extra ranges
                extracting.open("Scrolls/extraRange.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraRange[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra ranges
                extracting.open("Scrolls/haveExtraRange.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraRange[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//higher saves
                extracting.open("Scrolls/higherSave.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHigherSave[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have higher saves
                extracting.open("Scrolls/haveHigherSave.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 19){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveHigherSave[i];
                    }
                    count = count + 1;
                }
                extracting.close();
            } else{
                player.scrollName[i] = "";
                player.scrollDescriptionDamage[i] = "";
                player.scrollDescriptionActive[i] = "";
                player.scrollDiceType[i] = 0;
                player.scrollDiceCount[i] = 0;
                player.scrollTier[i] = 0;
                player.scrollRange[i] = "";
                player.scrollAction[i] = "";
                player.scrollStyle[i] = "";
                player.scrollExtraDamage[i] = false;
                player.scrollHaveExtraDamage[i] = false;
                player.scrollHalfAction[i] = false;
                player.scrollHaveHalfAction[i] = false;
                player.scrollExtraDie[i] = false;
                player.scrollHaveExtraDie[i] = false;
                player.scrollExtraRange[i] = false;
                player.scrollHaveExtraRange[i] = false;
                player.scrollHigherSave[i] = false;
                player.scrollHaveHigherSave[i] = false;
            }
            data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
            data << player.scrollName[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollDescriptionDamages.txt", std::fstream::app);
            data << player.scrollDescriptionDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollDescriptionActives.txt", std::fstream::app);
            data << player.scrollDescriptionActive[i] << endl;
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
            data.open("Data/Scrolls/scrollStyles.txt", std::fstream::app);
            data << player.scrollStyle[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraDamages.txt", std::fstream::app);
            data << player.scrollExtraDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraDamages.txt", std::fstream::app);
            data << player.scrollHaveExtraDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHalfActions.txt", std::fstream::app);
            data << player.scrollHalfAction[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveHalfActions.txt", std::fstream::app);
            data << player.scrollHaveHalfAction[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraDies.txt", std::fstream::app);
            data << player.scrollExtraDie[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraDies.txt", std::fstream::app);
            data << player.scrollHaveExtraDie[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraRanges.txt", std::fstream::app);
            data << player.scrollExtraRange[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraRanges.txt", std::fstream::app);
            data << player.scrollHaveExtraRange[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHigherSaves.txt", std::fstream::app);
            data << player.scrollHigherSave[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveHigherSaves.txt", std::fstream::app);
            data << player.scrollHaveHigherSave[i] << endl;
            data.close();
        } else if(player.playerStyle == "Fire"){
            valid = false;
            while(!valid){
            cout << "\n1. " << allScrollNames[40] << "\n2. " << allScrollNames[41] << "\n3. " << allScrollNames[42] << "\n4. " << allScrollNames[43] << "\n5. " << allScrollNames[44] << "\n6." << allScrollNames[45] << "\n7." << allScrollNames[46] << "\n8." << allScrollNames[47] << "\n9." << allScrollNames[48] << "\n10." << allScrollNames[49] << "\n11." << allScrollNames[50] << "\n12." << allScrollNames[51] << "\n13." << allScrollNames[52] << "\n14." << allScrollNames[53] << "\n15." << allScrollNames[54] << "\n16." << allScrollNames[55] << "\n17." << allScrollNames[56] << "\n18." << allScrollNames[57] << "\n19." << allScrollNames[58] << "\n20. " << allScrollNames[59] << "\n";
                valid = true;
                cin >> userAnswer;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout << "Please enter a number (especially you, Michael)\n";
                    valid = false;
                }
            }
            if(userAnswer <= 20 && userAnswer >= 1){
                player.scrollName[i] = allScrollNames[userAnswer + 39];
//description damages
                extracting.open("Scrolls/descriptionDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollDescriptionDamage[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//description actives
                extracting.open("Scrolls/descriptionActive.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollDescriptionActive[i]);
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
                        
                    } else{
                        getline(extracting, player.scrollAction[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//types
                //player.scrollStyle[i] = allScrollTypes[userAnswer + 39];
                extracting.open("Scrolls/style.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollStyle[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//extra damages
                //player.scrollExtraDamage[i] = allscrollExtraDamages[userAnswer + 39];
                extracting.open("Scrolls/extraDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraDamage[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra damages
                //player.scrollHaveExtraDamage[i] = allScrollHaveExtraDamages[userAnswer + 39];
                extracting.open("Scrolls/haveExtraDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraDamage[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//half actions
                extracting.open("Scrolls/halfAction.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHalfAction[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have half actions
                extracting.open("Scrolls/haveHalfAction.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveHalfAction[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//extra dies
                extracting.open("Scrolls/extraDie.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraDie[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra dies
                extracting.open("Scrolls/haveExtraDie.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraDie[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//extra ranges
                extracting.open("Scrolls/extraRange.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraRange[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra ranges
                extracting.open("Scrolls/haveExtraRange.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraRange[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//higher saves
                extracting.open("Scrolls/higherSave.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHigherSave[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have higher saves
                extracting.open("Scrolls/haveHigherSave.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 39){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveHigherSave[i];
                    }
                    count = count + 1;
                }
                extracting.close();
            } else{
                player.scrollName[i] = "";
                player.scrollDescriptionDamage[i] = "";
                player.scrollDescriptionActive[i] = "";
                player.scrollDiceType[i] = 0;
                player.scrollDiceCount[i] = 0;
                player.scrollTier[i] = 0;
                player.scrollRange[i] = "";
                player.scrollAction[i] = "";
                player.scrollStyle[i] = "";
                player.scrollExtraDamage[i] = false;
                player.scrollHaveExtraDamage[i] = false;
                player.scrollHalfAction[i] = false;
                player.scrollHaveHalfAction[i] = false;
                player.scrollExtraDie[i] = false;
                player.scrollHaveExtraDie[i] = false;
                player.scrollExtraRange[i] = false;
                player.scrollHaveExtraRange[i] = false;
                player.scrollHigherSave[i] = false;
                player.scrollHaveHigherSave[i] = false;
            }
            data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
            data << player.scrollName[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollDescriptionDamages.txt", std::fstream::app);
            data << player.scrollDescriptionDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollDescriptionActives.txt", std::fstream::app);
            data << player.scrollDescriptionActive[i] << endl;
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
            data.open("Data/Scrolls/scrollStyles.txt", std::fstream::app);
            data << player.scrollStyle[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraDamages.txt", std::fstream::app);
            data << player.scrollExtraDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraDamages.txt", std::fstream::app);
            data << player.scrollHaveExtraDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHalfActions.txt", std::fstream::app);
            data << player.scrollHalfAction[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveHalfActions.txt", std::fstream::app);
            data << player.scrollHaveHalfAction[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraDies.txt", std::fstream::app);
            data << player.scrollExtraDie[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraDies.txt", std::fstream::app);
            data << player.scrollHaveExtraDie[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraRanges.txt", std::fstream::app);
            data << player.scrollExtraRange[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraRanges.txt", std::fstream::app);
            data << player.scrollHaveExtraRange[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHigherSaves.txt", std::fstream::app);
            data << player.scrollHigherSave[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveHigherSaves.txt", std::fstream::app);
            data << player.scrollHaveHigherSave[i] << endl;
            data.close();
        } else if(player.playerStyle == "Air"){
            valid = false;
            while(!valid){
            cout << "\n1. " << allScrollNames[60] << "\n2. " << allScrollNames[61] << "\n3. " << allScrollNames[62] << "\n4. " << allScrollNames[63] << "\n5. " << allScrollNames[64] << "\n6." << allScrollNames[65] << "\n7." << allScrollNames[66] << "\n8." << allScrollNames[67] << "\n9." << allScrollNames[68] << "\n10." << allScrollNames[69] << "\n11." << allScrollNames[70] << "\n12." << allScrollNames[71] << "\n13." << allScrollNames[72] << "\n14." << allScrollNames[73] << "\n15." << allScrollNames[74] << "\n16." << allScrollNames[75] << "\n17." << allScrollNames[76] << "\n18." << allScrollNames[77] << "\n19." << allScrollNames[78] << "\n20. " << allScrollNames[79] << "\n";
                valid = true;
                cin >> userAnswer;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout << "Please enter a number (especially you, Michael)\n";
                    valid = false;
                }
            }
            if(userAnswer <= 20 && userAnswer >= 1){
                player.scrollName[i] = allScrollNames[userAnswer + 59];
//description damages
                extracting.open("Scrolls/descriptionDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollDescriptionDamage[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//description actives
                extracting.open("Scrolls/descriptionActive.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollDescriptionActive[i]);
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
                        
                    } else{
                        getline(extracting, player.scrollAction[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//types
                //player.scrollStyle[i] = allScrollTypes[userAnswer + 59];
                extracting.open("Scrolls/style.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollStyle[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//extra damages
                //player.scrollExtraDamage[i] = allscrollExtraDamages[userAnswer + 59];
                extracting.open("Scrolls/extraDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraDamage[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra damages
                //player.scrollHaveExtraDamage[i] = allScrollHaveExtraDamages[userAnswer + 59];
                extracting.open("Scrolls/haveExtraDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraDamage[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//half actions
                extracting.open("Scrolls/halfAction.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHalfAction[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have half actions
                extracting.open("Scrolls/haveHalfAction.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveHalfAction[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//extra dies
                extracting.open("Scrolls/extraDie.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraDie[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra dies
                extracting.open("Scrolls/haveExtraDie.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraDie[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//extra ranges
                extracting.open("Scrolls/extraRange.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraRange[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra ranges
                extracting.open("Scrolls/haveExtraRange.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraRange[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//higher saves
                extracting.open("Scrolls/higherSave.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHigherSave[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have higher saves
                extracting.open("Scrolls/haveHigherSave.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 59){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveHigherSave[i];
                    }
                    count = count + 1;
                }
                extracting.close();
            } else{
                player.scrollName[i] = "";
                player.scrollDescriptionDamage[i] = "";
                player.scrollDescriptionActive[i] = "";
                player.scrollDiceType[i] = 0;
                player.scrollDiceCount[i] = 0;
                player.scrollTier[i] = 0;
                player.scrollRange[i] = "";
                player.scrollAction[i] = "";
                player.scrollStyle[i] = "";
                player.scrollExtraDamage[i] = false;
                player.scrollHaveExtraDamage[i] = false;
                player.scrollHalfAction[i] = false;
                player.scrollHaveHalfAction[i] = false;
                player.scrollExtraDie[i] = false;
                player.scrollHaveExtraDie[i] = false;
                player.scrollExtraRange[i] = false;
                player.scrollHaveExtraRange[i] = false;
                player.scrollHigherSave[i] = false;
                player.scrollHaveHigherSave[i] = false;
            }
            data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
            data << player.scrollName[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollDescriptionDamages.txt", std::fstream::app);
            data << player.scrollDescriptionDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollDescriptionActives.txt", std::fstream::app);
            data << player.scrollDescriptionActive[i] << endl;
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
            data.open("Data/Scrolls/scrollStyles.txt", std::fstream::app);
            data << player.scrollStyle[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraDamages.txt", std::fstream::app);
            data << player.scrollExtraDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraDamages.txt", std::fstream::app);
            data << player.scrollHaveExtraDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHalfActions.txt", std::fstream::app);
            data << player.scrollHalfAction[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveHalfActions.txt", std::fstream::app);
            data << player.scrollHaveHalfAction[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraDies.txt", std::fstream::app);
            data << player.scrollExtraDie[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraDies.txt", std::fstream::app);
            data << player.scrollHaveExtraDie[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraRanges.txt", std::fstream::app);
            data << player.scrollExtraRange[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraRanges.txt", std::fstream::app);
            data << player.scrollHaveExtraRange[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHigherSaves.txt", std::fstream::app);
            data << player.scrollHigherSave[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveHigherSaves.txt", std::fstream::app);
            data << player.scrollHaveHigherSave[i] << endl;
            data.close();
        } else if(player.playerStyle == "Devoted"){
            valid = false;
            while(!valid){
            cout << "\n1. " << allScrollNames[80] << "\n2. " << allScrollNames[81] << "\n3. " << allScrollNames[82] << "\n4. " << allScrollNames[83] << "\n5. " << allScrollNames[84] << "\n6." << allScrollNames[85] << "\n7." << allScrollNames[86] << "\n8." << allScrollNames[87] << "\n9." << allScrollNames[88] << "\n10." << allScrollNames[89] << "\n11." << allScrollNames[90] << "\n12." << allScrollNames[91] << "\n13." << allScrollNames[92] << "\n14." << allScrollNames[93] << "\n15." << allScrollNames[94] << "\n16." << allScrollNames[95] << "\n17." << allScrollNames[96] << "\n18." << allScrollNames[97] << "\n";
                valid = true;
                cin >> userAnswer;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout << "Please enter a number (especially you, Michael)\n";
                    valid = false;
                }
            }
            if(userAnswer <= 18 && userAnswer >= 1){
                player.scrollName[i] = allScrollNames[userAnswer + 79];
//description damages
                extracting.open("Scrolls/descriptionDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollDescriptionDamage[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//description actives
                extracting.open("Scrolls/descriptionActive.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollDescriptionActive[i]);
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
                        
                    } else{
                        getline(extracting, player.scrollAction[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//types
                //player.scrollStyle[i] = allScrollTypes[userAnswer + 79];
                extracting.open("Scrolls/style.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        getline(extracting, tempString);
                        
                    } else{
                        getline(extracting, player.scrollStyle[i]);
                    }
                    count = count + 1;
                }
                extracting.close();
//extra damages
                //player.scrollExtraDamage[i] = allscrollExtraDamages[userAnswer + 79];
                extracting.open("Scrolls/extraDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraDamage[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra damages
                //player.scrollHaveExtraDamage[i] = allScrollHaveExtraDamages[userAnswer + 79];
                extracting.open("Scrolls/haveExtraDamage.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraDamage[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//half actions
                extracting.open("Scrolls/halfAction.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHalfAction[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have half actions
                extracting.open("Scrolls/haveHalfAction.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveHalfAction[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//extra dies
                extracting.open("Scrolls/extraDie.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraDie[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra dies
                extracting.open("Scrolls/haveExtraDie.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraDie[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//extra ranges
                extracting.open("Scrolls/extraRange.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollExtraRange[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have extra ranges
                extracting.open("Scrolls/haveExtraRange.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveExtraRange[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//higher saves
                extracting.open("Scrolls/higherSave.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHigherSave[i];
                    }
                    count = count + 1;
                }
                extracting.close();
//have higher saves
                extracting.open("Scrolls/haveHigherSave.txt", std::ifstream::in);
                count = 0;
                while(!extracting.eof()){
                    if(count != userAnswer + 79){
                        extracting >> tempString;
                        
                    } else{
                        extracting >> player.scrollHaveHigherSave[i];
                    }
                    count = count + 1;
                }
                extracting.close();
            } else{
                player.scrollName[i] = "";
                player.scrollDescriptionDamage[i] = "";
                player.scrollDescriptionActive[i] = "";
                player.scrollDiceType[i] = 0;
                player.scrollDiceCount[i] = 0;
                player.scrollTier[i] = 0;
                player.scrollRange[i] = "";
                player.scrollAction[i] = "";
                player.scrollStyle[i] = "";
                player.scrollExtraDamage[i] = false;
                player.scrollHaveExtraDamage[i] = false;
                player.scrollHalfAction[i] = false;
                player.scrollHaveHalfAction[i] = false;
                player.scrollExtraDie[i] = false;
                player.scrollHaveExtraDie[i] = false;
                player.scrollExtraRange[i] = false;
                player.scrollHaveExtraRange[i] = false;
                player.scrollHigherSave[i] = false;
                player.scrollHaveHigherSave[i] = false;
            }
            data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
            data << player.scrollName[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollDescriptionDamages.txt", std::fstream::app);
            data << player.scrollDescriptionDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollDescriptionActives.txt", std::fstream::app);
            data << player.scrollDescriptionActive[i] << endl;
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
            data.open("Data/Scrolls/scrollStyles.txt", std::fstream::app);
            data << player.scrollStyle[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraDamages.txt", std::fstream::app);
            data << player.scrollExtraDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraDamages.txt", std::fstream::app);
            data << player.scrollHaveExtraDamage[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHalfActions.txt", std::fstream::app);
            data << player.scrollHalfAction[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveHalfActions.txt", std::fstream::app);
            data << player.scrollHaveHalfAction[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraDies.txt", std::fstream::app);
            data << player.scrollExtraDie[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraDies.txt", std::fstream::app);
            data << player.scrollHaveExtraDie[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollExtraRanges.txt", std::fstream::app);
            data << player.scrollExtraRange[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveExtraRanges.txt", std::fstream::app);
            data << player.scrollHaveExtraRange[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHigherSaves.txt", std::fstream::app);
            data << player.scrollHigherSave[i] << endl;
            data.close();
            data.open("Data/Scrolls/scrollHaveHigherSaves.txt", std::fstream::app);
            data << player.scrollHaveHigherSave[i] << endl;
            data.close();
        }
    }
    return player;
};

characterInfo loadCharacter(){
    characterInfo player;
    ifstream data;

    data.open("Data/Other/name.txt");
    getline(data, player.playerName);
    data.close();

    data.open("Data/Other/style.txt");
    data >> player.playerStyle;
    data.close();

    data.open("Data/Other/path.txt");
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
    data.close();

    data.open("Data/Other/subBackground.txt");
    data >> player.playerSubBackground;
    data.close();

    data.open("Data/Other/role.txt");
    getline(data, player.playerRole);
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

    extracting.open("Data/Scrolls/scrollDescriptionDamages.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        getline(extracting, player.scrollDescriptionDamage[count], '\n');
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollDescriptionActives.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        getline(extracting, player.scrollDescriptionActive[count], '\n');
        cout << player.scrollDescriptionActive[count] << endl;
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

    extracting.open("Data/Scrolls/scrollRanges.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        getline(extracting, player.scrollRange[count]);
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollActions.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        //extracting >> player.scrollAction[count];
        getline(extracting, player.scrollAction[count]);
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollStyles.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        extracting >> player.scrollStyle[count];
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollExtraDamages.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        extracting >> player.scrollExtraDamage[count];
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollHaveExtraDamages.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        extracting >> player.scrollHaveExtraDamage[count];
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollHalfActions.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        extracting >> player.scrollHalfAction[count];
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollHaveHalfActions.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        extracting >> player.scrollHaveHalfAction[count];
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollExtraDies.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        extracting >> player.scrollExtraDie[count];
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollHaveExtraDies.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        extracting >> player.scrollHaveExtraDie[count];
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollExtraRanges.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        extracting >> player.scrollExtraRange[count];
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollHaveExtraRanges.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        extracting >> player.scrollHaveExtraRange[count];
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollHigherSaves.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        extracting >> player.scrollHigherSave[count];
        count = count + 1;
    }
    extracting.close();

    extracting.open("Data/Scrolls/scrollHaveHigherSaves.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < player.scrollCount)
    {
        extracting >> player.scrollHaveHigherSave[count];
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
//will add party members *added*
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
        extracting.open("Data/Features/featureCount.txt", std::ifstream::in);
        extracting >> player.featureCount;
        extracting.close();

        extracting.open("Data/Features/featureNames.txt", std::ifstream::in);
        count = 0;
        while(!extracting.eof()){
            getline(extracting, player.featureName[count], '\n');
            count++;
        }
        extracting.close();

        extracting.open("Data/Features/featureDescriptions.txt", std::ifstream::in);
        count = 0;
        while(!extracting.eof()){
            getline(extracting, player.featureDescription[count], '\n');
            count++;
        }
        extracting.close();


//will add inventory *added*
        extracting.open("Data/Other/inventory.txt", std::ifstream::in);
        count = 0;
        while(!extracting.eof() && count < player.inventoryCount)
        {
            getline(extracting, player.playerInventory[count], '\n');
            //cout << count << ". " << player.playerInventory[count] << endl;
            count = count + 1;
        }
        extracting.close();
    
    //need to recalculate the ability modifiers and proficiency bonus each time the character sheet is displayed    because variables may have changed
    
    //proficiency bonus will be calculated here depending on what their tier is, need to talk to Josh and Luis to get specific values
        player.playerProficiencyBonus = 2 * player.playerTier;

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
        cout << "Outward: " << player.playerOutward << "    Inward: " << player.playerInward << "    Background: " << player.playerBackground << ", " << player.playerSubBackground << "    Role: " << player.playerRole << endl << endl;

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
        for(int i = 0; i < player.featureCount; i++){
            cout << (i + 1) << ". " << player.featureName[i] << "\n   " << player.featureDescription[i] << "\n\n";
        }

        cout << "Party Members:\n";
        ifstream reading;
        count = 0;
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
            //cout << (i + 1) << ". " << player.scrollName[i] << "\n  Style: " << player.scrollStyle[i] << "\n  Tier: " << player.scrollTier[i] << "\n  Extra Damage: " << player.scrollHaveExtraDamage[i] << "\n  Half Action: " << player.scrollHaveHalfAction[i] << "\n  Extra Die: " << player.scrollHaveExtraDie[i] << "\n  Extra Range: " << player.scrollHaveExtraRange[i] << "\n  Higher Save: " << player.scrollHaveHigherSave[i] << "\n  Damage: " << player.scrollDescriptionDamage[i] << "\n  Active: " << player.scrollDescriptionActive[i] << endl << endl;
            cout << (i + 1) << ". " << player.scrollName[i] << "\n  Style: " << player.scrollStyle[i] << "\n  Tier: ";
            switch(player.scrollTier[i]){
                case 1:
                    cout << "Novice";
                    break;
                case 2:
                    cout << "Intermediate";
                    break;
                case 3:
                    cout << "Advanced";
                    break;
                case 4:
                    cout << "Master";
                    break;
                default:
                    cout << "ERROR, INVALID OR NO TIER FOUND";
                    break;
            }

            cout << "\n  Action: ";
            if(player.scrollHalfAction[i] && player.scrollHaveHalfAction[i]){
                cout << "Full, Half[*]";
            } else if(player.scrollHalfAction[i]){
                cout << "Full, Half[]";
            }else{
                cout << player.scrollAction[i];
            }

            if(player.scrollExtraDamage[i] && player.scrollHaveExtraDamage[i]){
                cout << "\n  Damage +2[*]";
            }else if(player.scrollExtraDamage[i]){
                cout << "\n  Damage +2[]";
            }

            if(player.scrollExtraDie[i] && player.scrollHaveExtraDie[i]){
                cout << "\n  Extra Hit Die[*]";
            }else if(player.scrollExtraDie[i]){
                cout << "\n  Extra Hit Die[]";
            }

            if(player.scrollExtraRange[i] && player.scrollHaveExtraRange[i]){
                cout << "\n  Range increased by 10 feet[*]";
            }else if(player.scrollExtraRange[i]){
                cout << "\n  Range increased by 10 feet[]";
            }

            if(player.scrollHigherSave[i] && player.scrollHaveHigherSave[i]){
                cout << "\n  Target must make higher saving throw[*]";
            }else if(player.scrollHigherSave[i]){
                cout << "\n  Target must make higher saving throw[]";
            }

            cout << "\n  Type: HAVEN'T IMPLEMENTED TYPE YET";
            cout << "\n  Range: " << player.scrollRange[i];
            if(player.scrollDescriptionDamage[i] == "Placeholder" && player.scrollDescriptionActive[i] == "Placeholder"){
                cout << "\n\n  DESCRIPTION NOT FOUND FOR EITHER ACTIVE OR DAMAGE";

            }else if(player.scrollDescriptionDamage[i] == "Placeholder"){
                cout << "\n\n  Active: " << player.scrollDescriptionActive[i];
            }else if(player.scrollDescriptionActive[i] == "Placeholder"){
                cout << "\n\n  Damage: " << player.scrollDescriptionDamage[i];
            }else{
                cout << "\n\n  Damage: " << player.scrollDescriptionDamage[i] << "\n  Active: " << player.scrollDescriptionActive[i];
            }
            cout << "\n\n\n";
        }

        valid = false;
        while(!valid){
            cout << "\n1. Roll for Stat\n2. Roll for Scroll Attack\n3. Roll for Weapon Attack\n4. Edit Something\n5. Use Practice Points\n6. Quit\n";
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
                valid = false;
                while(!valid){
                    cout << "1. Power\n2. Power Save\n3. Finesse\n4. Finesse Save\n5. Vitality\n6. Vitality Save\n7. Knowledge\n8. Knowledge Save\n9. Reason\n10. Reason Save\n11. Character\n12. Character Save\n13. Athletics\n14. Acrobatics\n15. Escamotage\n16. Stealth\n17. Willpower\n18. History\n19. Investigation\n20. Nature\n21. Seafaring\n22. Spirit\n23. Taming\n24. Hunting\n25. Insight\n26. Medicine\n27. Perception\n28. Deception\n29. Intimidation\n30. Performance\n31. Persuasion\n32. Back\n";
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
                valid = false;
                while(!valid){
                    cout << "Which scroll?\n";
                    for(int i = 0; i < player.scrollCount; i++){
                        cout << (i + 1) << ". " << player.scrollName[i] << endl;
                    }
                    valid = true;
                    cin >> userAnswer;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore();
                        cout << "Please enter a number (especially you, Michael)\n";
                        valid = false;
                    }
                }
                if( userAnswer > player.scrollCount ){
                    cout << "Invalid Option\n"; 
                } else{
                    if(player.playerStyle == "Water"){
                        scrollRoll(player.scrollDiceType[userAnswer - 1], player.scrollDiceCount[userAnswer - 1], player.finesseMod, player.scrollDescriptionDamage[userAnswer - 1], player.scrollName[userAnswer - 1], player.scrollStyle[userAnswer  - 1]);
                    }else if(player.playerStyle == "Earth"){
                        scrollRoll(player.scrollDiceType[userAnswer - 1], player.scrollDiceCount[userAnswer - 1], player.powerMod, player.scrollDescriptionDamage[userAnswer - 1], player.scrollName[userAnswer - 1], player.scrollStyle[userAnswer  - 1]);
                    }else if(player.playerStyle == "Fire"){
                        scrollRoll(player.scrollDiceType[userAnswer - 1], player.scrollDiceCount[userAnswer - 1], player.powerMod, player.scrollDescriptionDamage[userAnswer - 1], player.scrollName[userAnswer - 1], player.scrollStyle[userAnswer  - 1]);
                    }else if(player.playerStyle == "Air"){
                        scrollRoll(player.scrollDiceType[userAnswer - 1], player.scrollDiceCount[userAnswer - 1], player.powerMod, player.scrollDescriptionDamage[userAnswer - 1], player.scrollName[userAnswer - 1], player.scrollStyle[userAnswer  - 1]);
//mod for air and devoted are set as power by default, go back and change later after Luis or Josh tells me the correct stat
                    }else if(player.playerStyle == "Devoted"){
                        scrollRoll(player.scrollDiceType[userAnswer - 1], player.scrollDiceCount[userAnswer - 1], player.powerMod, player.scrollDescriptionDamage[userAnswer - 1], player.scrollName[userAnswer - 1], player.scrollStyle[userAnswer  - 1]);
                    }else{
                        cout << "Pretty major error, you don't appear to have a valid style. Were you messing around in your files?\n";
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
                valid = false;
                while(!valid){
                    cout << "1. Change Name\n2. Style\n3. Path\n4. Tier\n5. Outward\n6. Inward\n7. Background\n8. Role\n9. Spirit Bond\n10. Max Health\n11. Current Health\n12. Max Stamina\n13. Current Stamina\n14. Max Fortitude\n15. Current Fortitude\n16. Stats\n17. Proficiencies\n18. Party Members\n19. Allies\n20. Inventory\n21. Money\n22. Scrolls\n23. Back\n";
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
                        cout << "What would you like to change your name to?\n";
                        cin >> player.playerName;
                        data.open("Data/Other/name.txt", std::fstream::trunc);
                        data << player.playerName;
                        data.close();
                        break;
                    case 2:
                        condition = 0;
                        while( condition == 0 ) {
                            valid = false;
                            while(!valid){
                                cout << "What is your character's new style?\n1. Water\n2. Earth\n3. Fire\n4. Air\n5. Devoted" << endl;
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
                        data.open("Data/Other/style.txt", std::fstream::trunc);
                        data << player.playerStyle;
                        data.close();
                        break;
                    case 3:
                        if( player.playerStyle == "Water" ){
                            while( condition == 0 ) {
                                valid = false;
                                while(!valid){
                                    cout << "What is your character's new path?\n1. Path of Restoration\n2. Path of the Stoic\n3. Path of Subjugation\n4. None\n";
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
                                        break;
                                }
                            }
                            condition = 0;
                        } else if( player.playerStyle == "Earth" ){
                            while( condition == 0 ) {
                                valid = false;
                                while(!valid){
                                    cout << "What is your character's new path?\n1. Path of the Peacekeeper\n2. Path of the Purist\n3. Path of the Ravager\n4. None\n";
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
                                        break;
                                }
                            }
                            condition = 0;
                        } else if( player.playerStyle == "Fire" ){
                            while( condition == 0 ) {
                                valid = false;
                                while(!valid){
                                    cout << "What is your character's new path?\n1. Path of the Elevated\n2. Path of the Zelous\n3. Path of the Fanatic\n4. None\n";
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
                                        break;
                                }
                            }
                            condition = 0;
                        } else if( player.playerStyle == "Air" ){
                            while( condition == 0 ) {
                                valid = false;
                                while(!valid){
                                    cout << "What is your character's new path?\n1. Path of Peace\n2. Path of Indifference\n3. Path of Conflict\n4. None\n";
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
                                        break;
                                }
                            }
                                condition = 0;
                        } else if( player.playerStyle == "Devoted" ){
                            while( condition == 0 ) {
                                valid = false;
                                while(!valid){
                                    cout << "What is your character's new path?\n1. Spirit Blocker\n2. The Duelist\n3. The Assassin\n4. None\n";
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
                        valid = false;
                        while(!valid){
                            cout << "What is your new tier?\n";
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
                                player.playerTier  = 3;
                                break;
                            case 4:
                                player.playerTier = 4;
                                break;
                            default:
                                player.playerTier = 1;
                                break;
                        }
                        data.open("Data/Other/tier.txt", std::fstream::trunc);
                        data << player.playerTier;
                        data.close();
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
                        valid = false;
                        while(!valid){
                            cout << "\nWhat is your character's new background?\n1. Seaman\n2. Townsfolk\n3. Traveler\n4. Urchin\n5. Warrior\n" << endl;
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
                                player.playerBackground = "Seaman";
                                break;
                            case 2:
                                player.playerBackground = "Townsfolk";
                                break;
                            case 3:
                                player.playerBackground = "Traveler";
                                break;
                            case 4:
                                player.playerBackground = "Urchin";
                                break;
                            case 5:
                                player.playerBackground = "Warrior";
                                break;
                            default:
                                player.playerBackground = "None";
                                break;
                        }

                        valid = false;
                            while(!valid){
                                cout << "\nWhat is your character's new secondary background?\n";
                                if(player.playerBackground == "Seaman"){
                                    cout << "1. Fisherman\n2. Sailor\n";
                                }else if(player.playerBackground == "Townsfolk"){
                                    cout << "1. Merchant\n2. Official\n";
                                }else if(player.playerBackground == "Traveler"){
                                    cout << "1. Huntsman\n2. Guide\n";
                                }else if(player.playerBackground == "Urchin"){
                                    cout << "1. Thief\n2. Pirate\n";
                                }else if(player.playerBackground == "Warrior"){
                                    cout << "1. Mercenary\n2. Soldier\n";
                                }else{
                                    userAnswer = -1;
                                    break;
                                }
                                    valid = true;
                                    cin >> userAnswer;
                                if(cin.fail()){
                                    cin.clear();
                                    cin.ignore();
                                    cout << "Please enter a number (especially you, Michael)\n";
                                    valid = false;
                                }
                            }

                        if(player.playerBackground == "Seaman"){
                            switch(userAnswer){
                                case 1:
                                    player.playerSubBackground = "Fisherman";
                                    break;
                                case 2:
                                    player.playerSubBackground = "Sailor";
                                    break;
                                default:
                                    player.playerSubBackground = "None";
                                    break;
                            }
                        }else if(player.playerBackground == "Townsfolk"){
                            switch(userAnswer){
                                case 1:
                                    player.playerSubBackground = "Innkeep";
                                    break;
                                case 2:
                                    player.playerSubBackground = "Merchant";
                                    break;
                                default:
                                    player.playerSubBackground = "None";
                                    break;
                            }
                        }else if(player.playerBackground == "Official"){
                            switch(userAnswer){
                                case 1:
                                    player.playerSubBackground = "Councilman";
                                    break;
                                case 2:
                                    player.playerSubBackground = "Peacekeeper";
                                    break;
                                default:
                                    player.playerSubBackground = "None";
                                    break;
                            }
                        }else if(player.playerBackground == "Traveler"){
                            switch(userAnswer){
                                case 1:
                                    player.playerSubBackground = "Huntsman";
                                    break;
                                case 2:
                                    player.playerSubBackground = "Guide";
                                    break;
                                default:
                                    player.playerSubBackground = "None";
                                    break;
                            }
                        }else if(player.playerBackground == "Urchin"){
                            switch(userAnswer){
                                case 1:
                                    player.playerSubBackground = "Thief";
                                    break;
                                case 2:
                                    player.playerSubBackground = "Pirate";
                                    break;
                                default:
                                    player.playerSubBackground = "None";
                                    break;
                            }
                        }else if(player.playerBackground == "Warrior"){
                            switch(userAnswer){
                                case 1:
                                    player.playerSubBackground = "Mercenary";
                                    break;
                                case 2:
                                    player.playerSubBackground = "Soldier";
                                    break;
                                default:
                                    player.playerSubBackground = "None";
                                    break;
                                }
                        }else{
                            player.playerSubBackground = "None";
                        }
                        cout << player.playerSubBackground << endl;
                        data.open("Data/Other/background.txt", std::fstream::trunc);
                        data << player.playerBackground;
                        data.close();

                        data.open("Data/Other/subBackground.txt", std::fstream::trunc);
                        data << player.playerSubBackground;
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
                        cout << "What is your new max health?\n";
                        cin >> player.playerHealthMax;
                        data.open("Data/Stats/healthMax.txt", std::fstream::trunc);
                        data << player.playerHealthMax;
                        data.close();
                        break;
                    case 11:
                        cout << "What is your current health?\n";
                        cin >> player.playerHealth;
                        data.open("Data/Stats/health.txt", std::fstream::trunc);
                        data << player.playerHealth;
                        data.close();
                        break;
                    case 12:
                        cout << "What is your new max stamina?\n";
                        cin >> player.playerStaminaMax;
                        data.open("Data/Stats/staminaMax.txt", std::fstream::trunc);
                        data << player.playerStaminaMax;
                        data.close();
                        break;
                    case 13:
                        cout << "What is your current stamina?\n";
                        cin >> player.playerStamina;
                        data.open("Data/Stats/stamina.txt", std::fstream::trunc);
                        data << player.playerStamina;
                        data.close();
                        break;
                    case 14:
                        cout << "What is your new max fortitude?\n";
                        cin >> player.playerFortitudeMax;
                        data.open("Data/Stats/fortitudeMax.txt", std::fstream::trunc);
                        data << player.playerFortitudeMax;
                        data.close();
                        break;
                    case 15:
                        cout << "What is your current fortitude?\n";
                        cin >> player.playerFortitude;
                        data.open("Data/Stats/foritude.txt", std::fstream::trunc);
                        data << player.playerFortitude;
                        data.close();
                        break;
                    case 16:
                        cout << "Which stat would you like to change?\n1. Power\n2. Finesse\n3. Vitality\n4. Knowledge\n5. Reason\n6. Character\n";
                        cin >> userAnswer;
                        switch(userAnswer){
                            case 1:
                                //cout << "What is your new power?\n";
                                valid = false;
                                while(!valid){
                                    cout << "What is your new power?\n";
                                    valid = true;
                                    cin >> userAnswer;
                                    if(cin.fail()){
                                        cin.clear();
                                        cin.ignore();
                                        cout << "Please enter a number (especially you, Michael)\n";
                                        valid = false;
                                    }
                                }
                                player.playerPower = userAnswer;
                                data.open("Data/Stats/power.txt", std::fstream::trunc);
                                data << player.playerPower;
                                data.close();
                                break;
                            case 2:
                                valid = false;
                                while(!valid){
                                    cout << "What is your new finesse?\n";
                                    valid = true;
                                    cin >> userAnswer;
                                    if(cin.fail()){
                                        cin.clear();
                                        cin.ignore();
                                        cout << "Please enter a number (especially you, Michael)\n";
                                        valid = false;
                                    }
                                }
                                player.playerFinesse = userAnswer;
                                data.open("Data/Stats/finesse.txt", std::fstream::trunc);
                                data << player.playerFinesse;
                                data.close();
                                break;
                            case 3:
                                valid = false;
                                while(!valid){
                                    cout << "What is your new vitality?\n";
                                    valid = true;
                                    cin >> userAnswer;
                                    if(cin.fail()){
                                        cin.clear();
                                        cin.ignore();
                                        cout << "Please enter a number (especially you, Michael)\n";
                                        valid = false;
                                    }
                                }
                                player.playerVitality = userAnswer;
                                data.open("Data/Stats/vitality.txt", std::fstream::trunc);
                                data << player.playerVitality;
                                data.close();
                                break;
                            case 4:
                                valid = false;
                                while(!valid){
                                    cout << "What is your new knowledge?\n";
                                    valid = true;
                                    cin >> userAnswer;
                                    if(cin.fail()){
                                        cin.clear();
                                        cin.ignore();
                                        cout << "Please enter a number (especially you, Michael)\n";
                                        valid = false;
                                    }
                                }
                                player.playerKnowledge = userAnswer;
                                data.open("Data/Stats/knowledge.txt", std::fstream::trunc);
                                data << player.playerKnowledge;
                                data.close();
                                break;
                            case 5:
                                valid = false;
                                while(!valid){
                                    cout << "What is your new reason?\n";
                                    valid = true;
                                    cin >> userAnswer;
                                    if(cin.fail()){
                                        cin.clear();
                                        cin.ignore();
                                        cout << "Please enter a number (especially you, Michael)\n";
                                        valid = false;
                                    }
                                }
                                player.playerReason = userAnswer;
                                data.open("Data/Stats/reason.txt", std::fstream::trunc);
                                data << player.playerReason;
                                data.close();
                                break;
                            case 6:
                                valid = false;
                                while(!valid){
                                    cout << "What is your new character?\n";
                                    valid = true;
                                    cin >> userAnswer;
                                    if(cin.fail()){
                                        cin.clear();
                                        cin.ignore();
                                        cout << "Please enter a number (especially you, Michael)\n";
                                        valid = false;
                                    }
                                }
                                player.playerCharacter = userAnswer;
                                data.open("Data/Stats/character.txt", std::fstream::trunc);
                                data << player.playerCharacter;
                                data.close();
                                break;
                            default:
                                break;
                        }
                        break;
                    case 17:
                        valid = false;
                        while(!valid){
                        cout << "Which proficiency would you like to change? Selecting an option will switch you from having a proficiency to not and vice versa.\n1. Power Save\n2. Finesse Save\n3. Vitality Save\n4. Knowledge Save\n5. Reason Save\n6. Character Save\n7. Athletics\n8. Acrobatics\n9. Escamotage\n10. Stealth\n11. Willpower\n12. History\n13. Investigation\n14. Nature\n15. Seafaring\n16. Spirit\n17. Taming\n18. Hunting\n19. Insight\n20. Medicine\n21. Perception\n22. Deception\n23. Intimidation\n24. Performance\n25. Persuasion\n";
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
                                player.powerSave = !player.powerSave;
                                data.open("Data/Stats/powerSave.txt", std::fstream::trunc);
                                data << player.powerSave;
                                data.close();
                                break;
                            case 2:
                                player.finesseSave = !player.finesseSave;
                                data.open("Data/Stats/finesseSave.txt", std::fstream::trunc);
                                data << player.finesseSave;
                                data.close();
                                break;
                            case 3:
                                player.vitalitySave = !player.vitalitySave;
                                data.open("Data/Stats/vitalitySave.txt", std::fstream::trunc);
                                data << player.vitalitySave;
                                data.close();
                                break;
                            case 4:
                                player.knowledgeSave = !player.knowledgeSave;
                                data.open("Data/Stats/knowledgeSave.txt", std::fstream::trunc);
                                data << player.knowledgeSave;
                                data.close();
                                break;
                            case 5:
                                player.reasonSave = !player.reasonSave;
                                data.open("Data/Stats/reasonSave.txt", std::fstream::trunc);
                                data << player.reasonSave;
                                data.close();
                                break;
                            case 6:
                                player.characterSave = !player.characterSave;
                                data.open("Data/Stats/characterSave.txt", std::fstream::trunc);
                                data << player.characterSave;
                                data.close();
                                break;
                            case 7:
                                player.athleticsProf = !player.athleticsProf;
                                data.open("Data/Proficiencies/athletics.txt", std::fstream::trunc);
                                data << player.athleticsProf;
                                data.close();
                                break;
                            case 8:
                                player.acrobaticsProf = !player.acrobaticsProf;
                                data.open("Data/Proficiencies/acrobatics.txt", std::fstream::trunc);
                                data << player.acrobaticsProf;
                                data.close();
                                break;
                            case 9:
                                player.escamotageProf = !player.escamotageProf;
                                data.open("Data/Proficiencies/escamotage.txt", std::fstream::trunc);
                                data << player.escamotageProf;
                                data.close();
                                break;
                            case 10:
                                player.stealthProf = !player.stealthProf;
                                data.open("Data/Proficiencies/stealth.txt", std::fstream::trunc);
                                data << player.stealthProf;
                                data.close();
                                break;
                            case 11:
                                player.willpowerProf = !player.willpowerProf;
                                data.open("Data/Proficiencies/willpower.txt", std::fstream::trunc);
                                data << player.willpowerProf;
                                data.close();
                                break;
                            case 12:
                                player.historyProf = !player.historyProf;
                                data.open("Data/Proficiencies/history.txt", std::fstream::trunc);
                                data << player.historyProf;
                                data.close();
                                break;
                            case 13:
                                player.investigationProf = !player.investigationProf;
                                data.open("Data/Proficiencies/investigation.txt", std::fstream::trunc);
                                data << player.investigationProf;
                                data.close();
                                break;
                            case 14:
                                player.natureProf = !player.natureProf;
                                data.open("Data/Proficiencies/nature.txt", std::fstream::trunc);
                                data << player.natureProf;
                                data.close();
                                break;
                            case 15:
                                player.seafaringProf = !player.seafaringProf;
                                data.open("Data/Proficiencies/seafaring.txt", std::fstream::trunc);
                                data << player.seafaringProf;
                                data.close();
                                break;
                            case 16:
                                player.spiritProf = !player.spiritProf;
                                data.open("Data/Proficiencies/spirit.txt", std::fstream::trunc);
                                data << player.spiritProf;
                                data.close();
                                break;
                            case 17:
                                player.tamingProf = !player.tamingProf;
                                data.open("Data/Proficiencies/taming.txt", std::fstream::trunc);
                                data << player.tamingProf;
                                data.close();
                                break;
                            case 18:
                                player.huntingProf = !player.huntingProf;
                                data.open("Data/Proficiencies/hunting.txt", std::fstream::trunc);
                                data << player.huntingProf;
                                data.close();
                                break;
                            case 19:
                                player.insightProf = !player.insightProf;
                                data.open("Data/Proficiencies/insight.txt", std::fstream::trunc);
                                data << player.insightProf;
                                data.close();
                                break;
                            case 20:
                                player.medicineProf = !player.medicineProf;
                                data.open("Data/Proficiencies/medicine.txt", std::fstream::trunc);
                                data << player.medicineProf;
                                data.close();
                                break;
                            case 21:
                                player.perceptionProf = !player.perceptionProf;
                                data.open("Data/Proficiencies/perception.txt", std::fstream::trunc);
                                data << player.perceptionProf;
                                data.close();
                                break;
                            case 22:
                                player.deceptionProf = !player.deceptionProf;
                                data.open("Data/Proficiencies/deception.txt", std::fstream::trunc);
                                data << player.deceptionProf;
                                data.close();
                                break;
                            case 23:
                                player.intimidationProf = !player.intimidationProf;
                                data.open("Data/Proficiencies/intimidation.txt", std::fstream::trunc);
                                data << player.intimidationProf;
                                data.close();
                                break;
                            case 24:
                                player.performanceProf = !player.performanceProf;
                                data.open("Data/Proficiencies/performance.txt", std::fstream::trunc);
                                data << player.performanceProf;
                                data.close();
                                break;
                            case 25:
                                player.persuasionProf = !player.persuasionProf;
                                data.open("Data/Proficiencies/persuasion.txt", std::fstream::trunc);
                                data << player.persuasionProf;
                                data.close();
                                break;
                        }
                        break;
                    case 18:
                        cout << "What would you like to do?\n1. Add Party Member\n2. Remove Party Member\n3. Edit Party Member\n";
                        cin >> userAnswer;
                        switch(userAnswer){
                            case 1:
                                cout << "Who is the new party member?\n";
                                player.partyCount++;
                                cin.clear();
                                cin.ignore();
                                getline(cin, player.playerParty[player.partyCount]);
                                data.open("Data/Other/partyCount.txt", std::fstream::trunc);
                                data << player.partyCount;
                                data.close();
                                data.open("Data/Other/party.txt", std::fstream::app);
                                data << player.playerParty[player.partyCount] << endl;
                                data.close();
                                break;
                            case 2:
                                if(player.partyCount == 0){
                                    break;
                                }
                                cout << "Which would you like to remove?\n";
                                player.partyCount = player.partyCount - 1;
                                cin >> userAnswer;
                                for(int i = 0; i < player.partyCount; i++){
                                    if(i >= userAnswer - 1){
                                        player.playerParty[i] = player.playerParty[i + 1];
                                    }
                                }
                                data.open("Data/Other/partyCount.txt", std::fstream::trunc);
                                data << player.partyCount;
                                data.close();
                                data.open("Data/Other/party.txt", std::fstream::trunc);
                                data << "";
                                data.close();
                                data.open("Data/Other/party.txt", std::fstream::app);
                                for(int i = 0; i < player.partyCount; i++){
                                    data << player.playerParty[i] << endl;
                                }
                                data.close();
                                break;
                            case 3:
                                if(player.partyCount == 0){
                                    break;
                                }
                                cout << "Which would you like to edit?\n";
                                cin >> userAnswer;
                                if(userAnswer < player.partyCount){
                                    cin.clear();
                                    cin.ignore();
                                    cout << "Who is the party member?\n";
                                    getline(cin, player.playerParty[userAnswer - 1]);
                                    data.open("Data/Other/party.txt", std::fstream::trunc);
                                    data << "";
                                    data.close();
                                    data.open("Data/Other/party.txt", std::fstream::app);
                                    for(int i = 0; i < player.partyCount; i++){
                                        data << player.playerParty[i] << endl;
                                    }
                                    data.close();
                                }
                                break;
                            default:
                                break;
                        }
                        break;
                    case 19:
                        cout << "What would you like to do?\n1. Add Ally\n2. Remove Ally\n3. Edit Ally\n";
                        cin >> userAnswer;
                        switch(userAnswer){
                            case 1:
                                cout << "Who is the new ally?\n";
                                player.alliesCount++;
                                cin.clear();
                                cin.ignore();
                                getline(cin, player.playerAllies[player.alliesCount]);
                                data.open("Data/Other/alliesCount.txt", std::fstream::trunc);
                                data << player.alliesCount;
                                data.close();
                                data.open("Data/Other/allies.txt", std::fstream::app);
                                data << player.playerAllies[player.alliesCount] << endl;
                                data.close();
                                break;
                            case 2:
                                if(player.alliesCount == 0){
                                    break;
                                }
                                cout << "Which would you like to remove?\n";
                                player.alliesCount = player.alliesCount - 1;
                                cin >> userAnswer;
                                for(int i = 0; i < player.alliesCount; i++){
                                    if(i >= userAnswer - 1){
                                        player.playerAllies[i] = player.playerAllies[i + 1];
                                    }
                                }
                                data.open("Data/Other/alliesCount.txt", std::fstream::trunc);
                                data << player.alliesCount;
                                data.close();
                                data.open("Data/Other/allies.txt", std::fstream::trunc);
                                data << "";
                                data.close();
                                data.open("Data/Other/allies.txt", std::fstream::app);
                                for(int i = 0; i < player.alliesCount; i++){
                                    data << player.playerAllies[i] << endl;
                                }
                                data.close();
                                break;
                            case 3:
                                if(player.alliesCount == 0){
                                    break;
                                }
                                cout << "Which would you like to edit?\n";
                                cin >> userAnswer;
                                if(userAnswer < player.alliesCount){
                                    cin.clear();
                                    cin.ignore();
                                    cout << "Who is the ally?\n";
                                    getline(cin, player.playerAllies[userAnswer - 1]);
                                    data.open("Data/Other/allies.txt", std::fstream::trunc);
                                    data << "";
                                    data.close();
                                    data.open("Data/Other/allies.txt", std::fstream::app);
                                    for(int i = 0; i < player.alliesCount; i++){
                                        data << player.playerAllies[i] << endl;
                                    }
                                    data.close();
                                }
                                break;
                            default:
                                break;
                        }
                        break;
                    case 20:
                        cout << "What would you like to do?\n1. Add Inventory Item\n2. Remove Inventory Item\n3. Edit Inventory Item\n";
                        cin >> userAnswer;
                        switch(userAnswer){
                            case 1:
                                cout << "What is the new inventory item?\n";
                                player.inventoryCount++;
                                cin.clear();
                                cin.ignore();
                                getline(cin, player.playerInventory[player.inventoryCount]);
                                data.open("Data/Other/inventoryCount.txt", std::fstream::trunc);
                                data << player.inventoryCount;
                                data.close();
                                data.open("Data/Other/inventory.txt", std::fstream::app);
                                data << player.playerInventory[player.inventoryCount] << endl;
                                data.close();
                                break;
                            case 2:
                                if(player.inventoryCount == 0){
                                    break;
                                }
                                cout << "Which item would you like to remove?\n";
                                player.inventoryCount = player.inventoryCount - 1;
                                cin >> userAnswer;
                                for(int i = 0; i < player.inventoryCount; i++){
                                    if(i >= userAnswer - 1){
                                        player.playerInventory[i] = player.playerInventory[i + 1];
                                    }
                                }
                                data.open("Data/Other/inventoryCount.txt", std::fstream::trunc);
                                data << player.inventoryCount;
                                data.close();
                                data.open("Data/Other/inventory.txt", std::fstream::trunc);
                                data << "";
                                data.close();
                                data.open("Data/Other/inventory.txt", std::fstream::app);
                                for(int i = 0; i < player.inventoryCount; i++){
                                    data << player.playerInventory[i] << endl;
                                }
                                data.close();
                                break;
                            case 3:
                                if(player.inventoryCount == 0){
                                    break;
                                }
                                cout << "Which would you like to edit?\n";
                                cin >> userAnswer;
                                if(userAnswer < player.inventoryCount){
                                    cin.clear();
                                    cin.ignore();
                                    cout << "Who is the inventory member?\n";
                                    getline(cin, player.playerInventory[userAnswer - 1]);
                                    data.open("Data/Other/inventory.txt", std::fstream::trunc);
                                    data << "";
                                    data.close();
                                    data.open("Data/Other/inventory.txt", std::fstream::app);
                                    for(int i = 0; i < player.inventoryCount; i++){
                                        data << player.playerInventory[i] << endl;
                                    }
                                    data.close();
                                }
                                break;
                            default:
                                break;
                        }
                        break;
                    case 21:
                        cout << "Which would you like to change?\n1. Gold\n2. Silver\n3. Copper\n";
                        cin >> userAnswer;
                        switch(userAnswer){
                            case 1:
                                cout << "How much gold do you have?\n";
                                cin >> player.playerGold;
                                data.open("Data/Money/gold.txt", std::fstream::trunc);
                                data << player.playerGold;
                                data.close();
                                break;
                            case 2:
                                cout << "How much silver do you have?\n";
                                cin >> player.playerSilver;
                                data.open("Data/Money/silver.txt", std::fstream::trunc);
                                data << player.playerSilver;
                                data.close();
                                break;
                            case 3:
                                cout << "How much copper do you have?\n";
                                cin >> player.playerCopper;
                                data.open("Data/Money/copper.txt", std::fstream::trunc);
                                data << player.playerCopper;
                                data.close();
                                break;
                            default:
                                break;
                        }
                        break;
                    case 22:
                        cout << "What would you like to do?\n1. Add Scroll\n2. Remove Scroll\n";
                        cin >> userAnswer;
                        switch(userAnswer){
                            case 1:
                                if(player.scrollCount >= scrollMax){
                                    break;
                                }
                                cout << "Which scroll are you adding?\n";
                                for(int i = 0; i < allScrollNumber; i++){
                                    if(i == 0){
                                        cout << "\nWater Scrolls\n";
                                    }else if(i == 20){
                                        cout << "\nEarth Scrolls\n";
                                    }else if(i == 40){
                                        cout << "\nFire Scrolls\n";
                                    }else if(i == 60){
                                        cout << "\nAir Scrolls\n";
                                    }else if(i == 80){
                                        cout << "\nDevoted Scrolls\n";
                                    }
                                    cout << i + 1 << ". " << allScrollNames[i] << endl;
                                }
                                cin >> userAnswer;
                                if(userAnswer <= 98 && userAnswer >=1){
                                    player.scrollName[player.scrollCount] = allScrollNames[userAnswer - 1];
                                    cout << player.scrollName[player.scrollCount] << endl;
//description damages
                                    extracting.open("Scrolls/descriptionDamage.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            getline(extracting, tempString);
                                            
                                        } else{
                                            getline(extracting, player.scrollDescriptionDamage[player.scrollCount]);
                                        }
                                        count++;
                                    }
                                    extracting.close();
//description actives
                                    extracting.open("Scrolls/descriptionActive.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            getline(extracting, tempString);
                                            
                                        } else{
                                            getline(extracting, player.scrollDescriptionActive[player.scrollCount]);
                                        }
                                        count++;
                                    }
                                    extracting.close();
//dice types
                                    extracting.open("Scrolls/diceType.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            extracting >> tempString;
                                            
                                        } else{
                                            extracting >> player.scrollDiceType[player.scrollCount];
                                        }
                                        count++;
                                    }
                                    extracting.close();
//dice counts
                                    extracting.open("Scrolls/diceCount.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            extracting >> tempString;
                                            
                                        } else{
                                            extracting >> player.scrollDiceCount[player.scrollCount];
                                        }
                                        count++;
                                    }
                                    extracting.close();
//tiers
                                    cout << "\n\n\n\nhopefully this shows up\n\n\n\n";
                                    extracting.open("Scrolls/tier.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            extracting >> tempString;
                                            
                                        } else{
                                            extracting >> player.scrollTier[player.scrollCount];
                                            cout << "added\n\n";
                                        }
                                        count++;
                                    }
                                    extracting.close();
//ranges
                                    extracting.open("Scrolls/range.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            getline(extracting, tempString);
                                            
                                        } else{
                                            getline(extracting, player.scrollRange[player.scrollCount]);
                                        }
                                        count++;
                                    }
                                    extracting.close();
//actions
                                    extracting.open("Scrolls/action.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            getline(extracting, tempString);
                                            
                                        } else{
                                            getline(extracting, player.scrollAction[player.scrollCount]);
                                        }
                                        count++;
                                    }
                                    extracting.close();
//types
                                    extracting.open("Scrolls/style.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            getline(extracting, tempString);
                                            
                                        } else{
                                            getline(extracting, player.scrollStyle[player.scrollCount]);
                                        }
                                        count++;
                                    }
                                    extracting.close();
//extra damages
                                    extracting.open("Scrolls/extraDamage.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            extracting >> tempString;
                                            
                                        } else{
                                            extracting >> player.scrollExtraDamage[player.scrollCount];
                                        }
                                        count++;
                                    }
                                    extracting.close();
//have extra damages
                                    extracting.open("Scrolls/haveExtraDamage.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            extracting >> tempString;
                                            
                                        } else{
                                            extracting >> player.scrollHaveExtraDamage[player.scrollCount];
                                        }
                                        count++;
                                    }
                                    extracting.close();
//half actions
                                    extracting.open("Scrolls/halfAction.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            extracting >> tempString;
                                            
                                        } else{
                                            extracting >> player.scrollHalfAction[player.scrollCount];
                                        }
                                        count++;
                                    }
                                    extracting.close();
//have half actions
                                    extracting.open("Scrolls/haveHalfAction.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            extracting >> tempString;
                                            
                                        } else{
                                            extracting >> player.scrollHaveHalfAction[player.scrollCount];
                                        }
                                        count++;
                                    }
                                    extracting.close();
//extra dies
                                    extracting.open("Scrolls/extraDie.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            extracting >> tempString;
                                            
                                        } else{
                                            extracting >> player.scrollExtraDie[player.scrollCount];
                                        }
                                        count++;
                                    }
                                    extracting.close();
//have extra dies
                                    extracting.open("Scrolls/haveExtraDie.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            extracting >> tempString;
                                            
                                        } else{
                                            extracting >> player.scrollHaveExtraDie[player.scrollCount];
                                        }
                                        count++;
                                    }
                                    extracting.close();
//extra ranges
                                    extracting.open("Scrolls/extraRange.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            extracting >> tempString;
                                            
                                        } else{
                                            extracting >> player.scrollExtraRange[player.scrollCount];
                                        }
                                        count++;
                                    }
                                    extracting.close();
//have extra ranges
                                    extracting.open("Scrolls/haveExtraRange.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            extracting >> tempString;
                                            
                                        } else{
                                            extracting >> player.scrollHaveExtraRange[player.scrollCount];
                                        }
                                        count++;
                                    }
                                    extracting.close();
//higher saves
                                    extracting.open("Scrolls/higherSave.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            extracting >> tempString;
                                            
                                        } else{
                                            extracting >> player.scrollHigherSave[player.scrollCount];
                                        }
                                        count++;
                                    }
                                    extracting.close();
//have higher saves
                                    extracting.open("Scrolls/haveHigherSave.txt", std::ifstream::in);
                                    count = 0;
                                    while(!extracting.eof()){
                                        if(count != userAnswer - 1){
                                            extracting >> tempString;
                                            
                                        } else{
                                            extracting >> player.scrollHaveHigherSave[player.scrollCount];
                                        }
                                        count++;
                                    }
                                    extracting.close();

                                    data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
                                    data << player.scrollName[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollDescriptionDamages.txt", std::fstream::app);
                                    data << player.scrollDescriptionDamage[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollDescriptionActives.txt", std::fstream::app);
                                    data << player.scrollDescriptionActive[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollDiceTypes.txt", std::fstream::app);
                                    data << player.scrollDiceType[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollDiceCounts.txt", std::fstream::app);
                                    data << player.scrollDiceCount[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollRanges.txt", std::fstream::app);
                                    data << player.scrollRange[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollActions.txt", std::fstream::app);
                                    data << player.scrollAction[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollStyles.txt", std::fstream::app);
                                    data << player.scrollStyle[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollTiers.txt", std::fstream::app);
                                    data << player.scrollTier[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollExtraDamages.txt", std::fstream::app);
                                    data << player.scrollExtraDamage[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollHaveExtraDamages.txt", std::fstream::app);
                                    data << player.scrollHaveExtraDamage[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollHalfActions.txt", std::fstream::app);
                                    data << player.scrollHalfAction[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollHaveHalfActions.txt", std::fstream::app);
                                    data << player.scrollHaveHalfAction[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollExtraDies.txt", std::fstream::app);
                                    data << player.scrollExtraDie[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollHaveExtraDies.txt", std::fstream::app);
                                    data << player.scrollHaveExtraDie[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollExtraRanges.txt", std::fstream::app);
                                    data << player.scrollExtraRange[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollHaveExtraRanges.txt", std::fstream::app);
                                    data << player.scrollHaveExtraRange[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollHigherSaves.txt", std::fstream::app);
                                    data << player.scrollHigherSave[player.scrollCount] << endl;
                                    data.close();
                                    data.open("Data/Scrolls/scrollHaveHigherSaves.txt", std::fstream::app);
                                    data << player.scrollHaveHigherSave[player.scrollCount] << endl;
                                    data.close();

                                    player.scrollCount++;
                                    data.open("Data/Scrolls/scrollCount.txt", std::fstream::trunc);
                                    data << player.scrollCount;
                                    data.close();



                                }
                                break;
                            case 2:
                                cout << "\nYour scrolls:\n";
                                for(int i = 0; i < player.scrollCount; i++){
                                    cout << i + 1 << ". " << player.scrollName[i] << "\n" << player.scrollDescriptionActive[i] << "\n\n";
                                }
                                if(player.scrollCount == 0){
                                    break;
                                }
                                cout << "Which scroll would you like to remove?\n";
                                cin >> userAnswer;
                                for(int i = 0; i < player.scrollCount - 1; i++){
                                    if(i >= userAnswer - 1){
                                        player.scrollName[i] = player.scrollName[i + 1];
                                        player.scrollDescriptionDamage[i] = player.scrollDescriptionDamage[i + 1];
                                        player.scrollDescriptionActive[i] = player.scrollDescriptionActive[i + 1];
                                        player.scrollDiceType[i] = player.scrollDiceType[i + 1];
                                        player.scrollDiceCount[i] = player.scrollDiceCount[i + 1];
                                        player.scrollRange[i] = player.scrollRange[i + 1];
                                        player.scrollAction[i] = player.scrollAction[i + 1];
                                        player.scrollStyle[i] = player.scrollStyle[i + 1];
                                        player.scrollTier[i] = player.scrollTier[i + 1];
                                        player.scrollExtraDamage[i] = player.scrollExtraDamage[i + 1];
                                        player.scrollHaveExtraDamage[i] = player.scrollHaveExtraDamage[i + 1];
                                        player.scrollHalfAction[i] = player.scrollHalfAction[i + 1];
                                        player.scrollHaveHalfAction[i] = player.scrollHaveHalfAction[i + 1];
                                        player.scrollExtraDie[i] = player.scrollExtraDie[i + 1];
                                        player.scrollHaveExtraDie[i] = player.scrollHaveExtraDie[i + 1];
                                        player.scrollExtraRange[i] = player.scrollExtraRange[i + 1];
                                        player.scrollHaveExtraRange[i] = player.scrollHaveExtraRange[i + 1];
                                        player.scrollHigherSave[i] = player.scrollHigherSave[i + 1];
                                        player.scrollHaveHigherSave[i] = player.scrollHaveHigherSave[i + 1];
                                    }
                                }
                                player.scrollCount = player.scrollCount - 1;
                                data.open("Data/Scrolls/scrollCount.txt", std::fstream::trunc);
                                data << player.scrollCount;
                                data.close();
                                eraseScrolls();

                                data.open("Data/Scrolls/scrollNames.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollName[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollDescriptionDamages.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollDescriptionDamage[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollDescriptionActives.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    cout << i << endl;
                                    data << player.scrollDescriptionActive[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollDiceTypes.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollDiceType[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollDiceCounts.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollDiceCount[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollTiers.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollTier[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollRanges.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollRange[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollActions.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollAction[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollStyles.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollStyle[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollExtraDamages.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollExtraDamage[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollHaveExtraDamages.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollHaveExtraDamage[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollHalfActions.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollHalfAction[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollHaveHalfActions.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollHaveHalfAction[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollExtraDies.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollExtraDie[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollHaveExtraDies.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollHaveExtraDie[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollExtraRanges.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollExtraRange[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollHaveExtraRanges.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollHaveExtraRange[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollHigherSaves.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollHigherSave[i] << endl;
                                }
                                data.close();
                                data.open("Data/Scrolls/scrollHaveHigherSaves.txt", std::fstream::app);
                                for(int i = 0; i < player.scrollCount; i++){
                                    data << player.scrollHaveHigherSave[i] << endl;
                                }
                                data.close();
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 5:

                valid = false;
                while(!valid){
                cout << "What type of practice point would you like to allocate?\n1. Extra Damage\n2. Half Action\n3. Extra Damage Die\n4. Increased Range\n5. Higher Saving Throws\n";
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
                        valid = false;
                        while(!valid){
                            count = 1;
                            cout << "Which would you like to change?\n";
                            valid = true;
                            for(int i = 0; i < player.scrollCount; i++){
                                if(player.scrollExtraDamage[i]){
                                    cout << count << ". " << player.scrollName[i] << endl;
                                    count++;
                                }
                            }
                            cin >> userAnswer;
                            if(cin.fail()){
                                cin.clear();
                                cin.ignore();
                                cout << "Please enter a number (especially you, Michael)\n";
                                valid = false;
                            }
                        }
                        if(userAnswer > count){
                            break;
                        }
                        count = 0;
                        for(int i = 0; i < player.scrollCount; i++){
                            if(player.scrollExtraDamage[i]){
                                count++;
                                if(count == userAnswer){
                                    player.scrollHaveExtraDamage[i] = !player.scrollHaveExtraDamage[i];
                                }
                            }
                        }
                        data.open("Data/Scrolls/scrollHaveExtraDamages.txt", std::fstream::trunc);
                        data << "" << endl;
                        data.close();
                        for(int i = 0; i < player.scrollCount; i++){
                            data.open("Data/Scrolls/scrollHaveExtraDamages.txt", std::fstream::app);
                            data << player.scrollHaveExtraDamage[i] << endl;
                            data.close();
                        }
                        break;
                    case 2:
                        valid = false;
                        while(!valid){
                            count = 1;
                            cout << "Which would you like to change?\n";
                            valid = true;
                            for(int i = 0; i < player.scrollCount; i++){
                                if(player.scrollHalfAction[i]){
                                    cout << count << ". " << player.scrollName[i] << endl;
                                    count++;
                                }
                            }
                            cin >> userAnswer;
                            if(cin.fail()){
                                cin.clear();
                                cin.ignore();
                                cout << "Please enter a number (especially you, Michael)\n";
                                valid = false;
                            }
                        }
                        if(userAnswer > count){
                            break;
                        }
                        count = 0;
                        for(int i = 0; i < player.scrollCount; i++){
                            if(player.scrollHalfAction[i]){
                                count++;
                                if(count == userAnswer){
                                    player.scrollHaveHalfAction[i] = !player.scrollHaveHalfAction[i];
                                }
                            }
                        }
                        data.open("Data/Scrolls/scrollHaveHalfActions.txt", std::fstream::trunc);
                        data << "" << endl;
                        data.close();
                        for(int i = 0; i < player.scrollCount; i++){
                            data.open("Data/Scrolls/scrollHaveHalfActions.txt", std::fstream::app);
                            data << player.scrollHaveHalfAction[i] << endl;
                            data.close();
                        }
                        break;
                    case 3:
                        valid = false;
                        while(!valid){
                            count = 1;
                            cout << "Which would you like to change?\n";
                            valid = true;
                            for(int i = 0; i < player.scrollCount; i++){
                                if(player.scrollExtraDie[i]){
                                    cout << count << ". " << player.scrollName[i] << endl;
                                    count++;
                                }
                            }
                            cin >> userAnswer;
                            if(cin.fail()){
                                cin.clear();
                                cin.ignore();
                                cout << "Please enter a number (especially you, Michael)\n";
                                valid = false;
                            }
                        }
                        if(userAnswer > count){
                            break;
                        }
                        count = 0;
                        for(int i = 0; i < player.scrollCount; i++){
                            if(player.scrollExtraDie[i]){
                                count++;
                                if(count == userAnswer){
                                    player.scrollHaveExtraDie[i] = !player.scrollHaveExtraDie[i];
                                }
                            }
                        }
                        data.open("Data/Scrolls/scrollHaveExtraDies.txt", std::fstream::trunc);
                        data << "" << endl;
                        data.close();
                        for(int i = 0; i < player.scrollCount; i++){
                            data.open("Data/Scrolls/scrollHaveExtraDies.txt", std::fstream::app);
                            data << player.scrollHaveExtraDie[i] << endl;
                            data.close();
                        }
                        break;
                    case 4:
                        valid = false;
                        while(!valid){
                            count = 1;
                            cout << "Which would you like to change?\n";
                            valid = true;
                            for(int i = 0; i < player.scrollCount; i++){
                                if(player.scrollExtraRange[i]){
                                    cout << count << ". " << player.scrollName[i] << endl;
                                    count++;
                                }
                            }
                            cin >> userAnswer;
                            if(cin.fail()){
                                cin.clear();
                                cin.ignore();
                                cout << "Please enter a number (especially you, Michael)\n";
                                valid = false;
                            }
                        }
                        if(userAnswer > count){
                            break;
                        }
                        count = 0;
                        for(int i = 0; i < player.scrollCount; i++){
                            if(player.scrollExtraRange[i]){
                                count++;
                                if(count == userAnswer){
                                    player.scrollHaveExtraRange[i] = !player.scrollHaveExtraRange[i];
                                }
                            }
                        }
                        data.open("Data/Scrolls/scrollHaveExtraRanges.txt", std::fstream::trunc);
                        data << "" << endl;
                        data.close();
                        for(int i = 0; i < player.scrollCount; i++){
                            data.open("Data/Scrolls/scrollHaveExtraRanges.txt", std::fstream::app);
                            data << player.scrollHaveExtraRange[i] << endl;
                            data.close();
                        }
                        break;
                    case 5:
                        valid = false;
                        while(!valid){
                            count = 1;
                            cout << "Which would you like to change?\n";
                            valid = true;
                            for(int i = 0; i < player.scrollCount; i++){
                                if(player.scrollHigherSave[i]){
                                    cout << count << ". " << player.scrollName[i] << endl;
                                    count++;
                                }
                            }
                            cin >> userAnswer;
                            if(cin.fail()){
                                cin.clear();
                                cin.ignore();
                                cout << "Please enter a number (especially you, Michael)\n";
                                valid = false;
                            }
                        }
                        if(userAnswer > count){
                            break;
                        }
                        count = 0;
                        for(int i = 0; i < player.scrollCount; i++){
                            if(player.scrollHigherSave[i]){
                                count++;
                                if(count == userAnswer){
                                    player.scrollHaveHigherSave[i] = !player.scrollHaveHigherSave[i];
                                }
                            }
                        }
                        data.open("Data/Scrolls/scrollHaveHigherSaves.txt", std::fstream::trunc);
                        data << "" << endl;
                        data.close();
                        for(int i = 0; i < player.scrollCount; i++){
                            data.open("Data/Scrolls/scrollHaveHigherSaves.txt", std::fstream::app);
                            data << player.scrollHaveHigherSave[i] << endl;
                            data.close();
                        }
                        break;
                    default:
                        break;

                }
                break;
            default:
                return 0;
        }

    }
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
    data.close();
    int roll1;
    int roll2;    
    roll1 = (rand()%20) + 1;
    roll2 = (rand()%20) + 1;
    cout << "\n" << stat << ":\n";
    if(statMod < 0){
        cout << "First roll: " << roll1 + statMod << " (" << roll1 << " -" << abs(statMod) << ")\n";
        cout << "Second roll: " << roll2 + statMod << " (" << roll2 << " -" << abs(statMod) << ")\n";
    } else{
        cout << "First roll: " << roll1 + statMod << " (" << roll1 << " +" << statMod << ")\n";
        cout << "Second roll: " << roll2 + statMod << " (" << roll2 << " +" << statMod << ")\n";
    }
    return 0;
};
int scrollRoll(int diceType, int diceCount, int diceMod, string description, string name, string style){
    int roll;
    int rollSum = 0;
    if(diceCount == 0){
        cout << "\nThis is not an attacking move.\n";
        return 0;
    }
    cout << "(";
    for(int i = 0; i < diceCount; i++){
        roll = (rand()%diceType) + 1;
        if(i != diceCount - 1){
            cout << roll << ", ";
        }else{
            cout << roll << ") (" << diceCount << "d" << diceType << ")";
        }
        rollSum = rollSum + roll;
    }
    if(diceMod < 0){
        cout << "\nYou did " << rollSum + diceMod << " (" << rollSum << " -" << abs(diceMod) << ") " << style << " damage.\n";
        return 0;
    } else{
        cout << "\nYou did " << rollSum + diceMod << " (" << rollSum << " +" << diceMod << ") " << style << " damage.\n";
        return 0;
    }
    return 0;
};
int eraseScrolls(){
    ofstream data;
    data.open("Data/Scrolls/scrollNames.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollDescriptionDamages.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollDescriptionActives.txt", std::fstream::trunc);
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
    data.open("Data/Scrolls/scrollRanges.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollActions.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollStyles.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollExtraDamages.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollHaveExtraDamages.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollHalfActions.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollHaveHalfActions.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollExtraDies.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollHaveExtraDies.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollExtraRanges.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollHaveExtraRanges.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollHigherSaves.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Scrolls/scrollHaveHigherSaves.txt", std::fstream::trunc);
    data << "";
    data.close();
    return 0;
};
