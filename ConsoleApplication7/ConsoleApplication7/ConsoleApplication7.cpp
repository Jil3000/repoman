// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <math.h>

using namespace std;
using std::cout;

class Enemy {
	std::string name;
	int health;
	int attack;		// to be replaced
	int attackLow;
	int attackHigh;

public:
	//static int monsterCount;	// should be renamed enemyCount since it isn't in the Monster subclass

	std::string getName() {
		return name;
	};

	int getHealth() {
		return health;
	};

	int getAttack() {	// deprecated
		return attack;
	};

	int getAttackLow() {
		return attackLow;
	};

	int getAttackHigh() {
		return attackHigh;
	};

	void setName(std::string givenName) {
		name = givenName;
	};

	void setHealth(int givenHealth) {
		health = givenHealth;
	};

	void setAttack(int givenAttack) {	// deprecated
		attack = givenAttack;
	};

	void setAttackLow(int givenAttackLow) {
		attackLow = givenAttackLow;
	};

	void setAttackHigh(int givenAttackHigh) {
		attackHigh = givenAttackHigh;
	};


	int attackStrength() {
		int low = attackLow;
		int high = attackHigh;
		int attack = rand() % (attackHigh - attackLow + 1) + attackLow;
		return attack;
	}

	Enemy(std::string, int, int, int);

	Enemy();

	//static int getMonsterCount() {
	//	return monsterCount;
	//}
};

static int enemyCount = 0;

//class Monster : public Enemy {
//	int numEyes;
//
//public:
//	int getEyes() {
//		return numEyes;
//	};
//
//	void setEyes(int givenEyes) {
//		numEyes = givenEyes;
//	};
//};

//int Enemy::monsterCount;

Enemy::Enemy(std::string givenName, int givenHealth, int givenAttackLow, int givenAttackHigh) {
	name = givenName;
	health = givenHealth;
	attackLow = givenAttackLow;
	attackHigh = givenAttackHigh;
	enemyCount++;
}

Enemy::Enemy() {
	name = "";
	health = 0;
	attackLow = 0;
	attackHigh = 0;
	enemyCount++;
}

int calcHealth(int initialHealth, int attackStrength) {
	int remainingHealth = initialHealth - attackStrength;
	return remainingHealth;
}

void printHealth(Enemy* Fighter1, Enemy* Fighter2) {
	cout << (*Fighter1).getName() << " health: " << (*Fighter1).getHealth() << "\n" 
		<< (*Fighter2).getName() << " health: " << (*Fighter2).getHealth() << "\n";
}

void printResult(int attackStrength, Enemy attacker, Enemy defender) {
	cout << attacker.getName() << " attacked " << defender.getName() << " for " << attackStrength << " points.\n";
}

void battleRound(Enemy* attacker, Enemy* defender) {
	int attack = (*attacker).attackStrength();
	(*defender).setHealth(calcHealth((*defender).getHealth(), attack));
	printResult(attack, (*attacker), (*defender));
}

string fightSequence(Enemy* ptrFighter1, Enemy* ptrFighter2) {
	int roundNum = 0;
	cout << "\nFight initiated!\n\n";
	while ((*ptrFighter1).getHealth() > 0 && (*ptrFighter2).getHealth() > 0)
	{
		cout << "\b\b\r" << endl;
		if (roundNum % 2)
			battleRound(ptrFighter1, ptrFighter2);
		else
			battleRound(ptrFighter2, ptrFighter1);
		roundNum++;
		printHealth(ptrFighter1, ptrFighter2);
		system("pause > null");
	};
	if ((*ptrFighter1).getHealth() > (*ptrFighter2).getHealth())
		return (*ptrFighter1).getName();
	else if ((*ptrFighter2).getHealth() > (*ptrFighter1).getHealth())
		return (*ptrFighter2).getName();
	else								// this will only come up if I add in some functionality about bounceback damage
		return "No one!  It's a tie";

	return 0;
}

void printEnemyIntro(Enemy* fighter) {
	cout << "Monster One is named " << (*fighter).getName() << ".  It has " << (*fighter).getHealth() << " health and does between "
		<< (*fighter).getAttackLow() << " and " << (*fighter).getAttackHigh() << " damage.\n";
}

// ******* UNDER CONSTRUCTION!!!!!   ended here last time *******
void newFighter() {
	cout << "What is your character's name: ";
	string name;
	cin >> name;
	// some error handling stuff
	cout << "What fighter type are you - Warrior, Archer, Wizard, or Spy?";
	char type;		// don't know if I should use "char" yet, we'll see
	cin >> type;
}

// ******* UNDER CONSTRUCTION!!!!!   ended here last time *******
char mainMenu() {
	cout << "Main Menu" << endl;
	cout << "---------" << endl;
	cout << "[C]   Create New Fighter" << endl;
	if (enemyCount >= 1) {
		cout << "[D]   Delete Fighter" << endl;
	}
	if (enemyCount >= 2) {
		cout << "[S]   Start Match" << endl;
	}
	cout << "[X]   Exit" << endl;
	cout << endl;
	char menuPick;
	cin >> menuPick;
	std::cin.ignore(120,'\n');
	//system("pause");
	//system("cls");
	return menuPick;
}

int main()
{
	srand(time(NULL));

	Enemy enemyOne("enemy1", 15, 1, 20);
	Enemy* ptrEnemyOne;
	ptrEnemyOne = &enemyOne;
	Enemy enemyTwo("enemy2", 20, 5, 15);
	Enemy* ptrEnemyTwo;
	ptrEnemyTwo = &enemyTwo;
	
	while (1) {
		switch (mainMenu()) {
		case 'c':
		case 'C':
			cout << "accessed case c" << endl;
			// createFighter();		// half built, see above
			break;
		case 'd':
		case 'D':
			cout << "accessed case D" << endl;
			// pickFighter();		// doesn't exist yet
			// delete that fighter
			break;
		case 's':
		case 'S':
			// fighter1 = pickFighter();		// doesn't exist yet
			// fighter2 = pickFighter();		// doesn't exist yet
			printEnemyIntro(&enemyOne);
			printEnemyIntro(&enemyTwo);
			cout << "\nAnd the winner is... " << fightSequence(&enemyOne, &enemyTwo) << "!!\n" << endl;
			break;
		case 'x':
		case 'X':
			return 0;		// exits the program
			break;
		default:
			cout << "input unacceptable.  Please try again." << endl;
			//cout << "Play Again?  (Y/N):  ";
			//char contInput;
			//cin >> contInput;
			//std::cin.ignore();
			//if (contInput == "Y")
			//	// loop again;
			//else if (contInput != "N")
			//	// tell them they have invalid input and try again
			//// else just continue to the Exit part\
				//	// exit;
			break;
		};
		system("pause > null");
		system("cls");
	};

    return 0;
}
	
