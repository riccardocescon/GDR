#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <time.h>
#include <Windows.h>
#include "map.h"

using namespace std;

class control{
	public:
		int pR;
		int pC;
		char button;
		void back();
		bool enemy(char arr[][100], int C, char e);
		void wall(char arr[][100], int C, char wall);
		void position(char lvl[][100], int& R, int& C, char entity, int& px, int& py);
	protected:

};

char get_button(){
	kbhit();
	char button = getch();
	if (button < 97){
		button=button+32;
	}
	return button;
}
		
void mov(int& pR, int& pC, char button){
	switch(button){
		case 'w':
			pR--;
			break;
		case 's':
			pR++;
			break;
		case 'a':
			pC--;
			break;
		case 'd':
			pC++;
			break;
	}
}

void control::back (){
	switch(button){
		case 'w':
			pR++;
			break;
		case 's':
			pR--;
			break;
		case 'a':
			pC++;
			break;
		case 'd':
			pC--;
			break;
	}
}

bool control::enemy (char arr[][100], int C, char enemy){
	bool hit = false;
   	if (arr[pR][pC] == enemy){
		back();
		hit = true;
	}
	return hit;
}

void control::wall (char arr[][100], int C, char wall){						   
	if (arr[pR][pC]==wall){
		back();
	}
}

void control::position (char lvl[][100], int& R, int& C, char entity, int& px, int& py){
	for (int r=0; r<R; r++){
		for (int c=0; c<C; c++){
			if (lvl[r][c]==entity){
				px = r;
				py = c;
			}
		}
	}
}

void shift_entity(int positionR, int positionC, char skin){								
	HANDLE handle = GetStdHandle ( STD_OUTPUT_HANDLE );
	COORD coordinate = {positionC, positionR};
	DWORD cose;
	FillConsoleOutputCharacter ( handle, skin ,1, coordinate, &cose);
}
		
void delate_entity(int positionR,int positionC){	
	HANDLE handle = GetStdHandle ( STD_OUTPUT_HANDLE );
	COORD coordinate = {positionC,positionR};
	DWORD cose;
	FillConsoleOutputCharacter ( handle,' ',1, coordinate, &cose);
}

void print_map(char map[][100], int R, int C){
	for (int r=0; r<R; r++){
		for (int c=0; c<C; c++){
			cout << map[r][c];
		}
		cout << endl;
	}
}

void shift_number(int height, char skin, int positionC){								
	HANDLE handle = GetStdHandle ( STD_OUTPUT_HANDLE );
	COORD coordinate = {positionC, (height + 2)};
	DWORD cose;
	FillConsoleOutputCharacter ( handle, skin ,1, coordinate, &cose);
}
		
void delate_number(int height, int positionC){	
	HANDLE handle = GetStdHandle ( STD_OUTPUT_HANDLE );
	COORD coordinate = {positionC, (height + 2)};
	DWORD cose;
	FillConsoleOutputCharacter ( handle,' ',1, coordinate, &cose);
}

struct weapon{
	string name;
	double damage;
	double durability;
	double priceIn;
	double priceOut;
	string description;
	int number;
};

struct armor{
	string name;
	double protection;
	double durability;
	int priceIn;
	int priceOut;
	string description;
};

struct food{
	string name;
	double regeneration;
	int priceIn;
	int priceOut;
};

weapon shop_get_weapon(int x, int y){
	if (x == 1){
		/*-----BASE WEAPONS-----*/
		if(y == 1){weapon spada_rotta={"Spada Rotta", 3, 30, 15, 5,"E' una spada rotta"};return spada_rotta;};
		if(y == 2){weapon bastone={"Bastone", 2, 20, 10, 3,"E' un bastone di legno"};return bastone;};
		if(y == 3){weapon frusta={"Frusta", 2, 40, 15, 5,"E' una frusta"};return frusta;};
		if(y == 4){weapon wahaika={"Wahaika", 2.5, 40, 20, 7,"Gli antichi Maori utilizzavano lo Wahaika come pugnale, sebbene assomigli e venga considerata una clava. E' intagliato nel legno, oppure raramente nelle ossa di balena. "};return wahaika;};
		if(y == 5){weapon manganello={"Manganello", 5, 50, 20, 8,"E' un'arma contundente"};return manganello;};
		if(y == 6){weapon macana={"Makana", 6.5, 60, 30, 10,"E' un'arma simile ad una spada, fatta in legno, ma sufficientemente affilata da essere pericolosa"};return macana;};
		if(y == 7){weapon kriss={"Kriss", 6, 50, 25, 8,"Il kriss e' un tipico coltello-pugnale malese,con lama a biscia "};return kriss;};
		if(y == 8){weapon cinquedea={"Cinquedea", 6, 60, 20, 9,"La Cinquedea e' un'arma bianca manesca del tipo spada corta originatasi nel XV secolo in area veneta"};return cinquedea;};
		if(y == 9){weapon tonfa={"Tonfa", 5, 50, 15, 7, "La tonfa e' un'arma tradizionale delle arti marziali, e' composto da una impugnatura lunga 12 cm, e da un corpo di lunghezza variabile dai 50 ai 60 cm circa."};return tonfa;};
		if(y == 10){weapon tirapugni={"Tirapugni", 8, 80, 40, 15, "Viene utilizzato sferrando pugni"};return tirapugni;};
	}
	if (x == 2){
		/*-----NORMAL WEAPONS-----*/
		if(y == 1){weapon spada={"Spada", 12, 100, 55, 20,"E' una spada intatta, fatta di accaio"};return spada;};
		if(y == 2){weapon ascia={"Ascia", 14, 110, 65, 25, "Ascia di ferro, ottime per sgozzare mostri"};return ascia;};
		if(y == 3){weapon tridente={"Tridente", 11, 90, 50, 15, "Tridente, arma consigliata per attaccare a distanze di sicurezza"};return tridente;};
		if(y == 4){weapon pugnale={"Pugnale", 9, 55, 20, 5,"Usalo per uccidere silenziosamente i nemici"};return pugnale;};
		if(y == 5){weapon picca={"Picca", 11, 150, 50, 15,"Fatta per durare"};return picca;};
		if(y == 6){weapon dagaarondelle={"Daga a rondelle", 10, 90, 20, 4,"Una daga a rondelle e' un pugnale originario dell'Europa del tardo medioevomolto diffuso e utilizzato da una gran varieta' di persone dai mercanti ai cavalieri."};return dagaarondelle;};
		if(y == 7){weapon lancia={"Lancia", 10, 100, 15, 3,"Una lancia in legno, non troppo resistente, ma meglio di niente"};return lancia;};
		if(y == 8){weapon ken={"Ken", 13, 120, 55, 50, "Ken e' il vocabolo giapponese che identifica la spada a lama diritta, affilata su ambo i lati"};return ken;};
		if(y == 9){weapon goloko={"Goloko", 11, 100, 45, 10, "Il golok e' un'arma da taglio simile ad un machete che puo' essere usato sia per lavori agricoli che come arma"};return goloko;};
		if(y == 10){weapon hakapik={"Hakapik", 12, 110, 40, 5, "L'hakapik e' un bastone di invenzione norvegese usato nella caccia alla foca"};return hakapik;};
	}
	if (x == 3){
		/*-----DAMAGE WEAPONS-----*/
		if(y == 1){weapon katana={"Katana", 17, 220, 80, 20, "La katana e' la spada giapponese per antonomasia"};return katana;};
		if(y == 2){weapon alabarda={"Alabarda", 18, 200, 80, 18, "L'alabarda e' l'arma inastata per antonomasia, a punta, tagliente da entrambi i lati."};return alabarda;};
		if(y == 3){weapon azza={"Azza", 20, 250, 90, 25,"L'azza e' un'arma inastata diffusasi in Europa al volgere del Medioevo normalmente utilizzata dai soldati di fanteria e particolarmente adatta al combattimento contro avversari in armatura."};return azza;};
		if(y == 4){weapon zweihander={"Zweihander", 21, 210, 90, 25, "La zweihander e' un tipo di spada a due mani sviluppatasi nel corso del Rinascimento in Italia e nelle terre gravitanti intorno al Sacro Romano Impero Germanico."};return zweihander;};
		if(y == 5){weapon martellodaguerra={"Martello da Guerra", 23, 150, 95, 20, "E' un martello molto pesante per sfondare crani"};return martellodaguerra;};
		if(y == 6){weapon tetsubo={"Tetsubo", 23, 230, 100, 25, "Il tetsubo e' un'arma solitamente di legno molto simile a una Mazza da baseball, con l'eccezione che nella parte finale della mazza sono incastonate punte di metallo che possono essere di ferro, di rame " };return tetsubo;};
		if(y == 7){weapon sarissa={"Sarissa", 17, 180, 70, 15, "La sarissa era la picca usata dai temuti guerrieri del regno di MacedoniaLunga fino a 6-7 metri, aveva corpo in legno di corniolo di grande diametro, una grossa punta di ferroe un tallone anch'essometallico."};return sarissa;};
		if(y == 8){weapon berdica={"Berdica", 18, 190, 85, 15, "La berdica era un'arma inastata in uso in Europa Orientale. Era una g di circa un metro e mezzo e lama di scure a mezzaluna" };return berdica;};
		if(y == 9){weapon falcione={"Falcione", 19, 190, 90, 14,"Il falcione e' una spada ad una mano con tagliente monofilare diffusasi in Europa durante il Medioevo."};return falcione;};
		if(y == 10){weapon corsesca={"Corsesca", 17, 230, 85, 14, "La corsesca e' un'arma inastata in uso negli eserciti europei durante il Medioevo, con asta di lunghezza compresa tra gli 1,8 ed i 2,5 metri e testa in metallo"};return corsesca;};
	}
	if (x == 4){
		/*-----DUNGEON WEAPONS-----*/
		if(y == 1){weapon mazzaferrata={"Mazza Ferrata", 25, 250, 100, 27, "E' una mazza fatta di ferro"};return mazzaferrata;};
		if(y == 2){weapon asciabipenne={"Ascia Bipenne", 23, 270, 105, 27, "Ascia a doppia lama"};return asciabipenne;};
		if(y == 3){weapon martello={"Martello", 27, 180, 110, 28, "Martello da lavoro, molto potente ma poco resistente"};return martello;};
		if(y == 4){weapon mazzafrusto={"Mazzafrusto", 24, 280, 100, 20, "Il mazzafrusto e' un'arma bianca di origine contadina." };return mazzafrusto;};
		if(y == 5){weapon claymore={"Claymore", 25, 300, 120, 35, "Il termine in lingua inglese Claymore, indicadi spada usate dai guerrieri della Scozia tra Medioevo ed Eta' Moderna: 1-Claidheamh dha lamh (spada a due mani). 2-Claidheamh mor (grande spada)"};return claymore;};
		if(y == 6){weapon dirk={"Dirk", 23, 250, 107, 24, "Il dirk e' un lungo pugnale di origine scozzese con la lama a un filo."};return dirk;};
		if(y == 7){weapon kusarigama={"Kusarigama", 26, 275, 110, 23, "Il kusarigama e' un'arma giapponese utilizzata sia nel combattimento a distanza che nel corpo a corpo"};return kusarigama;};
		if(y == 8){weapon sai={"Sai", 23, 200, 90, 19, " La sua forma e' essenzialmente composta da una sorta di bastone arrotondato e appuntito, con due lunghe proiezioni non affilate attaccate al manico"};return sai;};
		if(y == 9){weapon falce={"Falce", 21, 245, 100, 21, "Falce da guerra indica una qualsiasi tipologia di arma bianca, manesca o inastata, ottenuta partendo dalla lama di una falce o di un falcetto." };return falce;};
		if(y == 10){weapon mazzapesante={"Mazza Pesante", 25.5, 230, 110, 28, "Si tratta di una mazza molto pesante, il materiale di cui e' composta non e' noto."};return mazzapesante;};
	}
	if (x == 5){
		/*-----SPECIAL WEAPONS-----*/
		if(y == 1){weapon none={"No Weapon", 0, 0, 0, 0,"none"};return none;};
		if(y == 2){weapon sodegarami={"Sodegarami", 24, 350, 200, 100, "Il sodegarami e' un'arma giapponese utilizzata soprattutto dalle forze di polizia samurai e per auto-difesa nel Giappone feudale."};return sodegarami;};
		if(y == 3){weapon romfaia={"Romfaia", 35, 350, 300, 200, "E' costituita da una lama ricurva affilata sul lato interno e si poteva utilizzare sia con una impugnatura a una mano che con una a due mani. Il danno che procurava era inflitto con un movimento a strappo e poteva mutilare un arto e decapitare l'avversario anche con un solo colpo."};return romfaia;};
	}
}


armor shop_get_armor(int x, int y){
		armor none={"No Armor", 0, 0, 0, 0,"none"};
		armor test={"name", 11, 100, 10 , 10, "d"};
		return test;
}

double total_damage(double damage,weapon hand_weapon){
	double total_damage = damage + hand_weapon.damage;
	cout << damage << " " << hand_weapon.damage << endl;
	cout << "here " << total_damage << endl;
	system("pause");
	return total_damage;
}

double total_defense(double armorbody, armor wear_armor){
	double total_armor = armorbody + wear_armor.protection;
	return total_armor;
}

class entity{
	protected:
		double life;
		double damage = 0;
		double armorbody = 0;
		double critic = 0;
		weapon hand_weapon;
		armor wear_armor;
		double totalDamage = 0;
		double totalArmor = 0;

	public:
		void setLife(double x){
			life = x;
		}
		double getLife(){
			return life;
		}
		
		
		void setDamage(double x){
			damage += x;
		}
		double getDamage(){
			return damage;
		}
		
		
		void setArmor(double x){
			armorbody += x;
		}
		double getArmor(){
			return armorbody;
		}
		
		void setCritic(double x){
			critic += x;
		}
		double getCritic(){
			return critic;
		}
		
		
		void setWeapon(weapon x){
			hand_weapon = x;
		}
		weapon getWeapon(){
			return hand_weapon;
		}

		
		void setWearArmor(armor x){
			wear_armor = x;
		}
		armor getWearArmor(){
			return wear_armor;
		}
};

class player : public entity{
	protected:
		double exp;
		double hunger;
		int money;
		int level;
	
	public:		
		void setExp(double x){
			exp += x;
		}
		double getExp(){
			return exp;
		}
		
		
		void setHunger(double x){
			hunger += x;
		}
		double getHunger(){
			return hunger;
		}
		
		
		void setMoney(int x){
			money += x;
		}
		int getMoney(){
			return money;
		}
		
		
		void setLevel(int x){
			level = x;
		}
		int getLevel(){
			return level;
		}
		
		double totalDamage;
		double totalArmor;
};

class shop{
	private:
		char open;
	public:
		void setOpen(char x){
			open = x;
		}
		bool getOpen(){
			bool r;
			if (open == 'q'){
				return r = true; 
			}else{
				return r = false;
			}
		}
};

double getTotalDamage(entity x, weapon y){
	double totalDamage = x.getDamage() + y.damage;
	return totalDamage;
}

double getTotalArmor(entity x, armor y){
	double totalArmor = x.getArmor() + y.protection;
	return totalArmor;
}

class status{
	private:
		bool strenght = false;
		bool regeneration = false;
		bool luck = false;
		bool weak = false;
		bool poison = false;
		bool hunger = false;
		bool speed = false;
	public:
		
		void setStrenght(bool x){
			strenght = !strenght;
		}
		bool getStrenght(){
			return strenght;
		}
		
		
		void setRegeneration(bool x){
			regeneration = !regeneration;
		}
		bool getRegeneration(){
			return regeneration;
		}
		
		
		void setLuck(bool x){
			luck = !luck;
		}
		bool getLuck(){
			return luck;
		}
		
		
		void setWeak(bool x){
			weak = !weak;
		}
		bool getWeak(){
			return weak;
		}
		
		
		void setPoison(bool x){
			poison = !poison;
		}
		bool getPoison(){
			return poison;
		}
		
		
		void setHunger(bool x){
			hunger = !hunger;
		}
		bool getHunger(){
			return hunger;
		}
		
		
		void setSpeed(bool x){
			speed = !speed;
		}
		bool getSpeed(){
			return speed;
		}
};

void modify_exp_and_level(player &pg){
	int exp = pg.getExp();
	int lvl = pg.getLevel();
	if(exp >= 101 && exp <= 250){pg.setLevel(2);}
	if(exp >= 251 && exp <= 450){pg.setLevel(3);}
	if(exp >= 451 && exp <= 700){pg.setLevel(4);}
	if(exp >= 701 && exp <= 1000){pg.setLevel(5);}
	if(exp >= 1001 && exp <= 1300){pg.setLevel(6);}
	if(exp >= 1301 && exp <= 1550){pg.setLevel(7);}
	if(exp >= 1551 && exp <= 1800){pg.setLevel(8);}
	if(exp >= 1801 && exp <= 2000){pg.setLevel(9);}
}

int shop_x(player pg, int x){
	int lvl = pg.getLevel();
	srand(time(NULL));
	x = rand() % 12 + 1;
	if(lvl <= 2){
		if(x <= 8){
			x = 1;
		}else if(x >= 9 && x <= 11){
			x = 2;
		}else if(x == 12){
			x = 3;
		}
	}
	if(lvl >= 3 && lvl <= 4){
		if(x <= 6){
			x = 1;
		}else if(x >= 7 && x <= 9){
			x = 2;
		}else if(x >= 10 && x<= 11){
			x = 3;
		}else if(x = 12){
			x = 4;
		}
	}
	if( lvl >= 5 && x<= 7){
		if( x <= 3){
			x = 1;
		}else if(x >= 4 && x <= 6){
			x = 2;
		}else if(x >= 7 && x <= 9){
			x = 3;
		}else if(x >= 10 && x <= 12){
			x = 4;
		}
	}
	if(lvl >= 8 && lvl <=9){
		if(x == 1){
			x = 1;
		}else if(x >= 2 && x <= 3){
			x = 2;
		}else if(x >= 4 && x <= 7){
			x = 3;
		}else if(x >= 8 && x<= 12){
			x = 4;
		}
	}
	return x;
}

int shop_y(int y){
	srand((unsigned)time(NULL));
	y = rand() % 10 + 1;
	return y;	
}

void open_shop(player pg){
	system("cls");
	int x,y,max=5;
	weapon arr[max];
		cout << "numero" << "   " << "nome" << "   " << "danno" << "   " << "durezza" << "   " << "costo" << "   " << "vendita" << "   " << "descizione" << endl << endl;
	for(int i = 0; i < max; i++){
		arr[i] = shop_get_weapon(shop_x(pg, x),shop_y(y));
		arr[i].number = i + 1;
		cout << arr[i].number << "   " << arr[i].name << "   " << arr[i].damage << "   " << arr[i].durability << "   " << arr[i].priceIn << "   " << arr[i].priceOut << "   " << arr[i].description << endl << endl;
		Sleep(1000);
	}
	cout << "Scrivi il numero dell'arma che vuoi comprare" << endl << "Scrivi '0' per uscire" << endl;
	bool cont = true;
	int n;
	do{
		cin >> n;
		if(n == 0){
			cont = false;
		}else{
			for(int i = 0; i < max; i++){
				int num = arr[i].number;
				if(num == n){
					if(pg.getMoney() >= arr[i].priceIn){
						cout << "Sei sicuro di voler comprare " << arr[i].name << " ? ( y or n)" << endl;
						char s;
						cin >> s;
						bool cont2 = true;
						while( cont2 == true){
							switch(s){
								case 'y':
									pg.setMoney(arr[i].priceIn);
									//AGGIUNGI ALL'INVENTARIO arr[i]
									cont = false;
									cont2 = false;
									break;
								case 'n':
									cont2 = false;
									break;
								default:
									cout << "Digitazione errata, riprovare" << endl;
									break;	
							}
						}
					}else{
						cout << "Non hai abbastanza soldi" << endl;
					}
				}
			}
		}
	}while(cont == true);
}

int critic_probability(entity pg){
	double critic = pg.getCritic();
	srand((unsigned)time(NULL));
	double n = rand() % 2;
	if( n == 0){
		n = rand() % 1001 / 10;
		if( critic >= n){
			return 1;
		}else{
			return 2;
		}
	}else{
		return 0;
	}
}

double random_durability(){
	double x;
	srand((unsigned)time(NULL));
	x = rand() % 2;
	if(x == 0){
		x = rand() % 2;
		if(x == 0){
			x = rand() % 10 + 1;
			return x/100;
		}else{
			return x/100;
		}
	}else{
		return 0;
	}
}

double enemy_lose_life(entity &entita_subire, player &entita_infliggere, int use_critic){
	double life = entita_subire.getLife();
	double danno = getTotalDamage(entita_infliggere, entita_infliggere.getWeapon()) - getTotalArmor(entita_subire, entita_subire.getWearArmor());
	if( danno > 0.0){
		life -= danno;
		double durability_lost = random_durability();
		weapon x = entita_infliggere.getWeapon();
		x.durability -= x.durability * durability_lost;
		entita_infliggere.setWeapon(x);
		int critic_base_damage = 100 - entita_infliggere.getCritic() ;
		srand((unsigned)time(NULL));
		double n = rand() % critic_base_damage + entita_infliggere.getCritic();
		switch (use_critic){
			case 0:
				break;
			case 1:
				life = life - (danno * entita_subire.getCritic()) - n;
				break;
			case 2:
				life = life - danno * entita_infliggere.getCritic();
				break;
			default:
				cout << "ERRORE CALCOLO CRITICO CASE DEFAULT" << endl;
				system("pause");
		}
		return life;
	}else{
		return life;
	}
}

double player_lose_life(player &entita_subire, entity &entita_infliggere, int use_critic, int height){
	double life = entita_subire.getLife();
	double danno = getTotalDamage(entita_infliggere, entita_infliggere.getWeapon()) - getTotalArmor(entita_subire, entita_subire.getWearArmor());
	if( danno > 0.0){
		life = life - danno;
		double durability_lost = random_durability();
		weapon x = entita_infliggere.getWeapon();
		x.durability -= x.durability * durability_lost;
		entita_infliggere.setWeapon(x);
		int critic_base_damage = 100 - entita_infliggere.getCritic() ;
		srand((unsigned)time(NULL));
		double n = rand() % critic_base_damage + entita_infliggere.getCritic();
		switch (use_critic){
			case 0:
				break;
			case 1:
				life = life - (danno * entita_subire.getCritic()) - n;
				break;
			case 2:
				life = life - danno * entita_infliggere.getCritic();
				break;
			default:
				cout << "ERRORE CALCOLO CRITICO CASE DEFAULT" << endl;
				system("pause");
		}
		char number = (int(life/100)+48);
		char number1 = (int(life/10)+48);
		char number2 = (int(life)%10+48);
		shift_number(height, number, 6);
		shift_number(height, number1, 7);
		shift_number(height, number2, 8);
		entita_subire.setLife(life);
		return life;
	}else{
		return life;
	}
}

void player_name(char nome[9]){
	
	cout << "Inserire un nome (max 9 caratteri)" << endl;
	cin >> nome;
}

void set_map(char map[][100]){
}

void use_inventory(string inventory[][10]){
	system("cls");
	inventory[0][0] = "Spada Lunga";
	cout << "				------------------------------------------------------------------------------------------------------------------------" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout << "				------------------------------------------------------------------------------------------------------------------------" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout << "				------------------------------------------------------------------------------------------------------------------------" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout << "				------------------------------------------------------------------------------------------------------------------------" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout << "				------------------------------------------------------------------------------------------------------------------------" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout << "				------------------------------------------------------------------------------------------------------------------------" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout << "				------------------------------------------------------------------------------------------------------------------------" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout << "				------------------------------------------------------------------------------------------------------------------------" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout <<	"				|           |           |           |           |           |           |           |           |           |           |" << endl;
	cout << "				------------------------------------------------------------------------------------------------------------------------" << endl;
	
}

player pg_set(player &x){
	weapon falce = shop_get_weapon(1,2);
	armor test = shop_get_armor(1,2);
	x.setArmor(5);
	x.setCritic(5);
	x.setDamage(5);
	x.setExp(5);
	x.setHunger(5);
	x.setLife(100);
	x.setMoney(5);
	x.setWeapon(falce);
	x.setWearArmor(test);
	x.setLevel(9);
	return x;	
}

entity bot_set(entity &x){
	weapon falce = shop_get_weapon(1,2);
	armor test = shop_get_armor(1,2);
	x.setArmor(3);
	x.setCritic(0.5);
	x.setDamage(5);
	x.setLife(5);
	x.setWeapon(shop_get_weapon(4,9));
	x.setWearArmor(test);
	return x;
}

void test(char button, player pg){
	string inventory[10][10];
	if(button == 'e'){
		use_inventory(inventory);
	}
	
	//cout << "La vita rimasta del bot e' " << enemy_lose_life(bot, pg, critic_probability(pg)) << endl;
	
	if(button == 'q' || button == 'Q'){
		open_shop(pg);
	}
	
	
	
	
}

int main(int argc, char** argv) {
	control control_you;
	system("color 0B");
	player pg;
	entity bot;
	pg_set(pg);
	bot_set(bot);
	maps map_level;	
	int rows=0;
	int cols=0;
	int pc=0;
	int pr=0;
	char lvl[50][100];
	char name[9];
	player_name(name);	
	system("cls");
	bool hit = false;
	map_level.choose_map(lvl);
	map_level.size(lvl, map_level.c, rows, cols);
	map_level.cols=cols;
	map_level.rows=rows;
	control_you.position(lvl, map_level.rows, map_level.cols, map_level.y, pr, pc);
	control_you.pR=pr;
	control_you.pC=pc;
	print_map(lvl, map_level.rows, map_level.cols);
	cout << endl << endl << "Vita: " << pg.getLife() << endl;
	do{
		control_you.button=get_button();
		test(control_you.button, pg);
		lvl[control_you.pR][control_you.pC] = ' ';
		delate_entity(control_you.pR, control_you.pC);
		mov(control_you.pR, control_you.pC, control_you.button);
		hit = control_you.enemy(lvl, map_level.cols, map_level.e);
		control_you.wall(lvl, map_level.cols,map_level.w);
		lvl[control_you.pR][control_you.pC] = map_level.y;
		if(hit == true){
			player_lose_life(pg, bot, critic_probability(bot), map_level.rows);
		}
		shift_entity(control_you.pR, control_you.pC, map_level.y);
		if (pg.getLife()<=0){
			break;
		}
	}while(3<4);
	return 0;
}
