#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <stdlib.h>
using namespace std;

int userAnswer;
int condition;
int partyMax = 100;
int alliesMax = 100;
int notesMax = 100;
int featureMax = 4;
int inventoryMax = 100;
int scrollMax = 14;

//if you ever update these Max values make sure to change the corresponding array lengths

string playerName;
string playerStyle;
string playerPath;
string playerTier;
string playerOutward;
string playerInward;
string playerBackground;
string playerRole;

float playerProficiencyBonus;

float playerStaminaMax;
float playerStamina;
float playerHealthMax;
float playerHealth;
float playerFortitudeMax;
float playerFortitude;

string playerSpiritBond;

float playerPower;
float playerFinesse;
float playerVitality;
float playerKnowledge;
float playerReason;
float playerCharacter;

bool powerSave;
bool finesseSave;
bool vitalitySave;
bool knowledgeSave;
bool reasonSave;
bool characterSave;

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

int playerCopper;
int playerSilver;
int playerGold;

string scrollName[14];
string scrollDescription[14];
int scrollCount;

bool athleticsProf;
bool acrobaticsProf;
bool escamotageProf;
bool stealthProf;
bool willpowerProf;
bool historyProf;
bool investigationProf;
bool natureProf;
bool seafaringProf;
bool spiritProf;
bool tamingProf;
bool huntingProf;
bool insightProf;
bool medicineProf;
bool perceptionProf;
bool deceptionProf;
bool intimidationProf;
bool performanceProf;
bool persuasionProf;


int createCharacter();
int loadCharacter();
int characterSheet();

int main(){
    while( condition == 0 ) {
        cout << "What would you like to do?" << endl << "1. Create a new character\n2.Use the currently existing character\nn3. Quit" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                createCharacter();
                loadCharacter();
                characterSheet();
                condition = 1;
                break;
            case 2:
                loadCharacter();
                characterSheet();
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

int createCharacter(){
    ofstream data;
    cout << "Welcome to the character creator! Just follow the instructions to create your character. Don't worry if you input something incorrectly. You can go back and change it later so just continue filling in everything else." << endl << endl;

    cout << "What is your character's name?" << endl;
    cin >> playerName;
    data.open("Data/Other/name.txt", std::fstream::trunc);
    data << playerName;
    data.close();

    cout << "What is your character's style?" << endl;
    cin >> playerStyle;
    data.open("Data/Other/style.txt", std::fstream::trunc);
    data << playerStyle;
    data.close();

    cout << "What is your character's path?" << endl;
    cin >> playerPath;
    data.open("Data/Other/path.txt", std::fstream::trunc);
    data << playerPath;
    data.close();

    cout << "What is your character's tier?" << endl;
    cin >> playerTier;
    data.open("Data/Other/tier.txt", std::fstream::trunc);
    data << playerTier;
    data.close();

    cout << "What is your character's outward personality?" << endl;
    cin >> playerOutward;
    data.open("Data/Other/outward.txt", std::fstream::trunc);
    data << playerOutward;
    data.close();

    cout << "What is your character's inward personality?" << endl;
    cin >> playerInward;
    data.open("Data/Other/inward.txt", std::fstream::trunc);
    data << playerInward;
    data.close();

    cout << "What is your character's background?" << endl;
    cin >> playerBackground;
    data.open("Data/Other/background.txt", std::fstream::trunc);
    data << playerBackground;
    data.close();

    cout << "What is your character's role?" << endl;
    cin >> playerRole;
    data.open("Data/Other/role.txt", std::fstream::trunc);
    data << playerRole;
    data.close();

    /*proficiency bonus will be calculated here depending on what their tier is, need to talk to Josh and Luis to get specific values*/

    cout << "What is your character's maximum stamina?" << endl;
    cin >> playerStaminaMax;
    playerStamina = playerStaminaMax;
    data.open("Data/Stats/staminaMax.txt", std::fstream::trunc);
    data << playerStaminaMax;
    data.close();
    data.open("Data/Stats/stamina.txt", std::fstream::trunc);
    data << playerStamina;
    data.close();

    cout << "What is your character's maximum health?" << endl;
    cin >> playerHealthMax;
    playerHealth = playerHealthMax;
    data.open("Data/Stats/healthMax.txt", std::fstream::trunc);
    data << playerHealthMax;
    data.close();
    data.open("Data/Stats/health.txt", std::fstream::trunc);
    data << playerHealth;
    data.close();

    cout << "What is your character's maximum fortitude?" << endl;
    cin >> playerFortitudeMax;
    playerFortitude = playerFortitudeMax;
    data.open("Data/Stats/fortitudeMax.txt", std::fstream::trunc);
    data << playerFortitudeMax;
    data.close();
    data.open("Data/Stats/fortitude.txt", std::fstream::trunc);
    data << playerFortitude;
    data.close();

    condition = 0;
    while( condition == 0 ) {
        cout << "How many spirit bonds does your character have? 1, 2, or 3?" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 0:
                playerSpiritBond = "0";
                condition = 1;
                break;
            case 1:
                playerSpiritBond = "1";
                condition = 1;
                break;
            case 2:
                playerSpiritBond = "2";
                condition = 1;
                break;
            case 3:
                playerSpiritBond = "3";
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Other/spiritBond.txt", std::fstream::trunc);
    data << playerSpiritBond;
    data.close();
    condition = 0;

    /*playerSpiritBond = true;
    data.open("Data/Other/spiritBond.txt", std::fstream::trunc);
    data << playerSpiritBond;
    data.close();*/

    cout << "What is your character's power?" << endl;
    cin >> playerPower;
    data.open("Data/Stats/power.txt", std::fstream::trunc);
    data << playerPower;
    data.close();

    condition = 0;
    while( condition == 0 ) {
        cout << "Does your character have proficiency in power saving throws?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                powerSave = true;
                condition = 1;
                break;
            case 2:
                powerSave = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Stats/powerSave.txt", std::fstream::trunc);
    data << powerSave;
    data.close();
    condition = 0;


    cout << "What is your character's finesse?" << endl;
    cin >> playerFinesse;
    data.open("Data/Stats/finesse.txt", std::fstream::trunc);
    data << playerFinesse;
    data.close();

    while( condition == 0 ) {
        cout << "Does your character have proficiency in finesse saving throws?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                finesseSave = true;
                condition = 1;
                break;
            case 2:
                finesseSave = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Stats/finesseSave.txt", std::fstream::trunc);
    data << finesseSave;
    data.close();
    condition = 0;


    cout << "What is your character's vitality?" << endl;
    cin >> playerVitality;
    data.open("Data/Stats/vitality.txt", std::fstream::trunc);
    data << playerVitality;
    data.close();

    while( condition == 0 ) {
        cout << "Does your character have proficiency in vitality saving throws?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                vitalitySave = true;
                condition = 1;
                break;
            case 2:
                vitalitySave = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Stats/vitalitySave.txt", std::fstream::trunc);
    data << vitalitySave;
    data.close();
    condition = 0;


    cout << "What is your character's knowledge?" << endl;
    cin >> playerKnowledge;
    data.open("Data/Stats/knowledge.txt", std::fstream::trunc);
    data << playerKnowledge;
    data.close();

    while( condition == 0 ) {
        cout << "Does your character have proficiency in power saving throws?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                powerSave = true;
                condition = 1;
                break;
            case 2:
                powerSave = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Stats/powerSave.txt", std::fstream::trunc);
    data << powerSave;
    data.close();
    condition = 0;


    cout << "What is your character's reason?" << endl;
    cin >> playerReason;
    data.open("Data/Stats/reason.txt", std::fstream::trunc);
    data << playerReason;
    data.close();

    while( condition == 0 ) {
        cout << "Does your character have proficiency in reason saving throws?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                reasonSave = true;
                condition = 1;
                break;
            case 2:
                reasonSave = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Stats/reasonSave.txt", std::fstream::trunc);
    data << reasonSave;
    data.close();
    condition = 0;


    cout << "What is your character's character?" << endl;
    cin >> playerCharacter;
    data.open("Data/Stats/character.txt", std::fstream::trunc);
    data << playerCharacter;
    data.close();

    while( condition == 0 ) {
        cout << "Does your character have proficiency in character saving throws?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                characterSave = true;
                condition = 1;
                break;
            case 2:
                characterSave = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Stats/characterSave.txt", std::fstream::trunc);
    data << characterSave;
    data.close();
    condition = 0;


    cout << "How much gold does your character have?" << endl;
    cin >> playerGold;
    data.open("Data/Money/gold.txt", std::fstream::trunc);
    data << playerGold;
    data.close();


    cout << "How much silver does your character have?" << endl;
    cin >> playerSilver;
    data.open("Data/Money/silver.txt", std::fstream::trunc);
    data << playerSilver;
    data.close();

    cout << "How much copper does your character have?" << endl;
    cin >> playerCopper;
    data.open("Data/Money/copper.txt", std::fstream::trunc);
    data << playerCopper;
    data.close();

//inventory support will come later
    while( condition == 0 ) {
        cout << "How many items do you have in your inventory?" << endl;
        cin >> userAnswer;
        inventoryCount = userAnswer;    
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
    cout << "Enter the names of your items. DO NOT USE ANY SPACES. PLEASE FOR THE LOVE OF GOD, I HAVEN'T FIGURED OUT HOW TO NOT MAKE THINGS BREAK. Instead use an underscore (_) to represent spaces." << endl;
    for (int n = 0; n < userAnswer; n++) {
        cout << (n + 1) << ". ";
        cin >> playerInventory[n];
        data << playerInventory[n] << endl;
    }
    data.close();


//party member support will maybe come later
    while( condition == 0 ) {
        cout << "How many party members do you have?" << endl;
        cin >> userAnswer;
        partyCount = userAnswer;    
        data.open("Data/Other/partyCount.txt", std::fstream::trunc);
        data << userAnswer;
        data.close();
        if ( userAnswer <= partyMax ) {
            condition = 1;
        }
        else {
            cout << "Maximum number of party members is " << partyMax << endl;
        }   
    }
    condition = 0;
    data.open("Data/Other/party.txt", std::fstream::trunc);
    data << "";
    data.close();
    data.open("Data/Other/party.txt", std::fstream::app);
    cout << "Enter the names of your party members. DO NOT USE ANY SPACES. PLEASE FOR THE LOVE OF GOD, I HAVEN'T FIGURED OUT HOW TO NOT MAKE THINGS BREAK" << endl;
    for (int n = 0; n < userAnswer; n++) {
        cout << (n + 1) << ". ";
        cin >> playerParty[n];
        data << playerParty[n] << endl;
    }
    data.close();


//ally member support will come later
//notes support will come later
//features support will come later
//scrolls support will come later
    while( condition == 0 ) {
        cout << "Does your character have proficiency in athletics?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                athleticsProf = true;
                condition = 1;
                break;
            case 2:
                athleticsProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/athletics.txt", std::fstream::trunc);
    data << athleticsProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in scrobatics?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                acrobaticsProf = true;
                condition = 1;
                break;
            case 2:
                acrobaticsProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/acrobatics.txt", std::fstream::trunc);
    data << acrobaticsProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in escamotage?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                escamotageProf = true;
                condition = 1;
                break;
            case 2:
                escamotageProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/escamotage.txt", std::fstream::trunc);
    data << escamotageProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in stealth?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                stealthProf = true;
                condition = 1;
                break;
            case 2:
                stealthProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/stealth.txt", std::fstream::trunc);
    data << stealthProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in willpower?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                willpowerProf = true;
                condition = 1;
                break;
            case 2:
                willpowerProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/willpower.txt", std::fstream::trunc);
    data << willpowerProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in history?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                historyProf = true;
                condition = 1;
                break;
            case 2:
                historyProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/history.txt", std::fstream::trunc);
    data << historyProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in investigation?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                investigationProf = true;
                condition = 1;
                break;
            case 2:
                investigationProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/investigation.txt", std::fstream::trunc);
    data << investigationProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in nature?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                natureProf = true;
                condition = 1;
                break;
            case 2:
                natureProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/nature.txt", std::fstream::trunc);
    data << natureProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in seafaring?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                seafaringProf = true;
                condition = 1;
                break;
            case 2:
                seafaringProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/seafaring.txt", std::fstream::trunc);
    data << seafaringProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in spirit?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                spiritProf = true;
                condition = 1;
                break;
            case 2:
                spiritProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/spirit.txt", std::fstream::trunc);
    data << spiritProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in taming?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                tamingProf = true;
                condition = 1;
                break;
            case 2:
                tamingProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/taming.txt", std::fstream::trunc);
    data << tamingProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in hunting?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                huntingProf = true;
                condition = 1;
                break;
            case 2:
                huntingProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/hunting.txt", std::fstream::trunc);
    data << huntingProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in insight?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                insightProf = true;
                condition = 1;
                break;
            case 2:
                insightProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/insight.txt", std::fstream::trunc);
    data << insightProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in medicine?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                medicineProf = true;
                condition = 1;
                break;
            case 2:
                medicineProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/medicine.txt", std::fstream::trunc);
    data << medicineProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in perception?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                perceptionProf = true;
                condition = 1;
                break;
            case 2:
                perceptionProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/perception.txt", std::fstream::trunc);
    data << perceptionProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in deception?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                deceptionProf = true;
                condition = 1;
                break;
            case 2:
                deceptionProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/deception.txt", std::fstream::trunc);
    data << deceptionProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in intimidation?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                intimidationProf = true;
                condition = 1;
                break;
            case 2:
                intimidationProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/intimidation.txt", std::fstream::trunc);
    data << intimidationProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in performance?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                performanceProf = true;
                condition = 1;
                break;
            case 2:
                performanceProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/performance.txt", std::fstream::trunc);
    data << performanceProf;
    data.close();
    condition = 0;

    while( condition == 0 ) {
        cout << "Does your character have proficiency in persuasion?" << endl << "1. Yes" << endl << "2. No" << endl;
        cin >> userAnswer;        
        switch(userAnswer){
            case 1:
                persuasionProf = true;
                condition = 1;
                break;
            case 2:
                persuasionProf = false;
                condition = 1;
                break;
            default:
                cout << "Not a valid response, please try again.\n";
                break;
        }    
    }
    data.open("Data/Proficiencies/persuasion.txt", std::fstream::trunc);
    data << persuasionProf;
    data.close();
    condition = 0;

    return 0;
};

int loadCharacter(){
    ifstream data;

    data.open("Data/Other/name.txt");
    data >> playerName;
    data.close();

    data.open("Data/Other/style.txt");
    data >> playerStyle;
    data.close();

    data.open("Data/Other/path.txt");
    data >> playerPath;
    data.close();

    data.open("Data/Other/tier.txt");
    data >> playerTier;
    data.close();

    data.open("Data/Other/outward.txt");
    data >> playerOutward;
    data.close();

    data.open("Data/Other/inward.txt");
    data >> playerInward;
    data.close();

    data.open("Data/Other/background.txt");
    data >> playerBackground;
    data.close();

    data.open("Data/Other/role.txt");
    data >> playerRole;
    data.close();

//read the player proficiency bonus

    data.open("Data/Stats/staminaMax.txt");
    data >> playerStaminaMax;
    data.close();

    data.open("Data/Stats/stamina.txt");
    data >> playerStamina;
    data.close();

    data.open("Data/Stats/healthMax.txt");
    data >> playerHealthMax;
    data.close();

    data.open("Data/Stats/health.txt");
    data >> playerHealth;
    data.close();

    data.open("Data/Stats/fortitudeMax.txt");
    data >> playerFortitudeMax;
    data.close();

    data.open("Data/Stats/fortitude.txt");
    data >> playerFortitude;
    data.close();

    data.open("Data/Other/spiritBond.txt");
    data >> playerSpiritBond;
    data.close();

    data.open("Data/Stats/power.txt");
    data >> playerPower;
    data.close();

    data.open("Data/Stats/finesse.txt");
    data >> playerFinesse;
    data.close();

    data.open("Data/Stats/vitality.txt");
    data >> playerVitality;
    data.close();

    data.open("Data/Stats/knowledge.txt");
    data >> playerKnowledge;
    data.close();

    data.open("Data/Stats/reason.txt");
    data >> playerReason;
    data.close();

    data.open("Data/Stats/character.txt");
    data >> playerCharacter;
    data.close();

    data.open("Data/Stats/powerSave.txt");
    data >> powerSave;
    data.close();

    data.open("Data/Stats/finesseSave.txt");
    data >> finesseSave;
    data.close();

    data.open("Data/Stats/vitalitySave.txt");
    data >> vitalitySave;
    data.close();

    data.open("Data/Stats/knowledgeSave.txt");
    data >> knowledgeSave;
    data.close();

    data.open("Data/Stats/reasonSave.txt");
    data >> reasonSave;
    data.close();

    data.open("Data/Stats/characterSave.txt");
    data >> characterSave;
    data.close();

//will add party members *added*
    ifstream extracting;
    extracting.open("Data/Other/party.txt", std::ifstream::in);
    int count = 0;
    while(!extracting.eof() && count < partyCount)
    {
        getline(extracting, playerParty[count], '\n');
        //cout << count << ". " << playerParty[count] << endl;
        count = count + 1;
    }
    extracting.close();


//will add allies
//will add notes
//will add features


//will add inventory *added*
    extracting.open("Data/Other/inventory.txt", std::ifstream::in);
    count = 0;
    while(!extracting.eof() && count < inventoryCount)
    {
        getline(extracting, playerInventory[count], '\n');
        //cout << count << ". " << playerInventory[count] << endl;
        count = count + 1;
    }
    extracting.close();

    data.open("Data/Money/copper.txt");
    data >> playerCopper;
    data.close();

    data.open("Data/Money/silver.txt");
    data >> playerSilver;
    data.close();

    data.open("Data/Money/gold.txt");
    data >> playerGold;
    data.close();

//will add scrolls

    data.open("Data/Proficiencies/athletics.txt");
    data >> athleticsProf;
    data.close();

    data.open("Data/Proficiencies/acrobatics.txt");
    data >> acrobaticsProf;
    data.close();

    data.open("Data/Proficiencies/escamotage.txt");
    data >> escamotageProf;
    data.close();

    data.open("Data/Proficiencies/stealth.txt");
    data >> stealthProf;
    data.close();

    data.open("Data/Proficiencies/willpower.txt");
    data >> willpowerProf;
    data.close();

    data.open("Data/Proficiencies/history.txt");
    data >> historyProf;
    data.close();

    data.open("Data/Proficiencies/investigation.txt");
    data >> investigationProf;
    data.close();

    data.open("Data/Proficiencies/nature.txt");
    data >> natureProf;
    data.close();

    data.open("Data/Proficiencies/seafaring.txt");
    data >> seafaringProf;
    data.close();

    data.open("Data/Proficiencies/spirit.txt");
    data >> spiritProf;
    data.close();

    data.open("Data/Proficiencies/taming.txt");
    data >> tamingProf;
    data.close();

    data.open("Data/Proficiencies/hunting.txt");
    data >> huntingProf;
    data.close();

    data.open("Data/Proficiencies/insight.txt");
    data >> insightProf;
    data.close();

    data.open("Data/Proficiencies/medicine.txt");
    data >> medicineProf;
    data.close();

    data.open("Data/Proficiencies/perception.txt");
    data >> perceptionProf;
    data.close();

    data.open("Data/Proficiencies/deception.txt");
    data >> deceptionProf;
    data.close();

    data.open("Data/Proficiencies/intimidation.txt");
    data >> intimidationProf;
    data.close();

    data.open("Data/Proficiencies/performance.txt");
    data >> performanceProf;
    data.close();

    data.open("Data/Proficiencies/persuasion.txt");
    data >> persuasionProf;
    data.close();

    
    return 0;
};

int characterSheet(){
    return 0;
};
