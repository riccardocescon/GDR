#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include "map.h"

using namespace std;

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
struct thing_to_use{
	string name;
	double food_regeneration;
	bool strenght;
	bool regeneration;
	bool luck;
	bool weak;
	bool poison;
	bool hunger;
	bool speed;
	int priceIn;
	int priceOut;
};
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
		bool strenght = false;
		bool regeneration = false;
		bool luck = false;
		bool weak = false;
		bool poison = false;
		bool hunger = false;
		bool speed = false;
		int pR = 0;
		int pC = 0;

	public:
		void setLife(double x){
			life = x;
		}
		double getLife(){
			return life;
		}
		
		
		void setDamage(double x){
			damage = x;
		}
		double getDamage(){
			return damage;
		}
		
		
		void setArmor(double x){
			armorbody = x;
		}
		double getArmor(){
			return armorbody;
		}
		
		void setCritic(double x){
			critic = x;
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
		
		
		void setpR(int x){
			pR = x;
		}
		int getpR(){
			return pR;
		}
		
		
		void setpC(int x){
			pC = x;
		}
		int getpC(){
			return pC;
		}
		
};
class player : public entity{
	protected:
		double exp;
		double hunger;
		int money;
		int level;
		double maxlife;
		double expcontroller;
		thing_to_use use;
	
	public:		
		void setExp(double x){
			exp += x;
		}
		double getExp(){
			return exp;
		}
		void setExpController(double x){
			expcontroller = x;
		}
		double getExpController(){
			return expcontroller;
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
		
		
		void setMaxLife(double x){
			maxlife = x;
		}
		double getMaxLife(){
			return maxlife;
		}
		
		
		void setUse(thing_to_use x){
			use = x;
		}
		thing_to_use getUse(){
			return use;
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
class object : public weapon, public armor, public thing_to_use{
};

char get_button();
void mov(int& pR, int& pC, char button);
void shift_entity(int positionR, int positionC, char skin);
void delate_entity(int positionR,int positionC);
int howmany(char lvl[][100], int rows, int cols, char entity, int R, int C);
void print_map(char map[][100], int R, int C);
void shift_number(int height, char skin, int positionC);
void delate_number(int height, int positionC);
bool wall_enemy (char lvl[][100], int pos_enemyR, int pos_enemyC, char w);
bool no_entity (char lvl[][100], int pos_enemyR, int pos_enemyC);
void rand_nem(int dx, int sx, int su, int giu, int &nemR, int& nemC, char arr[][100], char w);
void choose_where(int pR, int pC, int& position_mobR,  int& position_mobC, char arr[][100], char w, char mob, char pg);
void mov_enemy(char lvl[][100], int mobs[], int pR, int pC, int entitys, char wall, char pg);



weapon shop_get_weapon(int x, int y);
armor shop_get_armor(int x, int y);
thing_to_use shop_get_thing(int x, int y);
double total_damage(double damage,weapon hand_weapon);
double total_defense(double armorbody, armor wear_armor);
double getTotalDamage(entity x, weapon y);
double getTotalArmor(entity x, armor y);
void modify_exp_and_level(player &pg);
int shop_x(player pg, int x);
int shop_y(int y);
void open_shop(player &pg);
int critic_probability(entity pg);
double random_durability();
double enemy_lose_life(entity &entita_subire, player &entita_infliggere, int use_critic);
double player_lose_life(player &entita_subire, entity &entita_infliggere, int use_critic, int height);
void player_name(char nome[9]);
void use_inventory(string inventory[][10]);
void move_weapon_to_inventory(player &pg, weapon &x);
void move_armor_to_inventory(player &pg, armor &x);
void use_thing(player &pg, thing_to_use &x);
player pg_set(player &x);
entity bot_set(entity &x);
void level_up(player &pg, maps map_level, char lvl[][100]);
void control_exp(player &pg, maps map_level, char lvl[][100]);
bool test(char button, player pg, int map_rows, int map_cols, char lvl[][100]);
entity create_bot(int x);
void generate_name();


char get_button(){
	kbhit();
	char button = getch();
	if (button < 97){
		button=button+32;
	}
	return button;
}

char get_button2(){
	kbhit();
	char button = getch();
	return button;
}
		
void mov(player& pg, char button){
	int x;
	switch(button){
		case 'w':
			x=pg.getpR()-1;
			pg.setpR(x);
			break;
		case 's':
			x=pg.getpR()+1;
			pg.setpR(x);
			break;
		case 'a':
			x=pg.getpC()-1;
			pg.setpC(x);
			break;
		case 'd':
			x=pg.getpC()+1;
			pg.setpC(x);
			break;
	}
}

void back (char button, player& pg){
	int x;
	switch(button){
		case 'w':
			x=pg.getpR()+1;
			pg.setpR(x);
			break;
		case 's':
			x=pg.getpR()-1;
			pg.setpR(x);
			break;
		case 'a':
			x=pg.getpC()+1;
			pg.setpC(x);
			break;
		case 'd':
			x=pg.getpC()-1;
			pg.setpC(x);
			break;
	}
}

bool win(char button, char lvl[][100], int C, char s, player& pg){
	bool safe=false;
	if(lvl[pg.getpR()][pg.getpC()]==s){
		back(button, pg);
		safe=true;
	}
	return safe;
}



bool enemy (char button, char arr[][100], int C, char enemy, int& whrex, int& wherey, player& pg){
	bool hit = false;
   	if (arr[pg.getpR()][pg.getpC()] == enemy){
   		whrex = pg.getpR();
   		wherey = pg.getpC();
		back(button, pg);
		hit = true;
	}
	return hit;
}

bool walls (char arr[][100], int C, char wall, player& pg){	
	bool wal=false;					   
	if (arr[pg.getpR()][pg.getpC()]==wall){
		wal=true;
	}
	return wal;
}

void position (char lvl[][100], int& R, int& C, char entity, player& pg){
	for (int r=0; r<R; r++){
		for (int c=0; c<C; c++){
			if (lvl[r][c]==entity){
				pg.setpR(r);
				pg.setpC(c);
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

void position_enemy (char lvl[][100], int R, int C, char entit, entity mobs[], int number){
	int s=0;
	while(number!=0){
		for (int r=0; r<R; r++){
			for (int c=0; c<C; c++){
				if (lvl[r][c]==entit){
					mobs[s].setpR(r);
					mobs[s].setpC(c);
					number--;
					s++;
				}
			}
		}
	}
}

int howmany(char lvl[][100], int rows, int cols, char entity, int R, int C){
	int numbers=0;
	for (int r=0; r<R; r++){
		for (int c=0; c<C; c++){
			if (lvl[r][c]==entity){
				numbers ++;
			}
		}
	}
	return numbers;
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

bool wall_enemy (char lvl[][100], int pos_enemyR, int pos_enemyC, char w){
	bool wall=false;
	if(lvl[pos_enemyR][pos_enemyC]==w){
		wall=true;
	}
	return wall;
}

bool no_entity (char lvl[][100], int pos_enemyR, int pos_enemyC){
	bool space=false;
	if(lvl[pos_enemyR][pos_enemyC]==' '){
		space=true;
	}
	return space;
}

void rand_nem(int dx, int sx, int su, int giu, int &nemR, int& nemC, char arr[][100], char w){
	srand((unsigned)time(NULL));
	int z=nemR;
	int y=nemC;
	int rimuovi=0;
	int f;
	int x;
	int l = 0;
	int c;
	do{
		l++;
		c=0;
		nemR=z;
		nemC=y;
		x=rand()%(100-rimuovi-1)+1;
		if(rimuovi==dx){
			x=x+rimuovi;
		}else if(rimuovi==sx){
			int j = rand()%3;
			if(j==0){
			}else{
				x=x+rimuovi;
			}
		}else if(rimuovi==su){
			int j = rand()%3;
			if(j==2){
				x=x+rimuovi;
			}else{
			}
		}else if(rimuovi==giu){
		}
		if(dx!=rimuovi && x>=0 && x<=dx){
	    		nemC++;
	    		rimuovi= dx;
	   			c++;
	    }else if(sx!=rimuovi && x>dx && x<=(dx+sx)){
			  nemC--;
			  rimuovi =  sx;
			  c++;
	    }else if(su!=rimuovi && x>(dx+sx) && x<=(dx+sx+su)){
	    		nemR--;
	    		rimuovi =  su;
	    		c++;
		}else if(giu!=rimuovi && x>(dx+sx+su) && x<=(dx+sx+su+giu)){
	    		nemR++;
	    		rimuovi = giu;
	    		c++;
		}
		if (l>1000){
			nemR=z;
			nemC=y;
			break;
		}
	}while(wall_enemy(arr, nemR, nemC, w)==true || c==0 || no_entity(arr, nemR, nemC)==false);
}

void choose_where(int pR, int pC, int& position_mobR,  int& position_mobC, char arr[][100], char w, char mob, char pg){
	int y=pR-position_mobR;
	int x=pC-position_mobC;
	int rim=0;
	if (arr[position_mobR+1][position_mobC] == pg || arr[position_mobR-1][position_mobC] == pg || arr[position_mobR][position_mobC+1] == pg || arr[position_mobR][position_mobC-1] == pg){
		
	}else{
	    arr[position_mobR][position_mobC]=' ';
	    delate_entity(position_mobR, position_mobC);
		if (y==0 && x>0){
			rand_nem(94, 1, 2, 3, position_mobR, position_mobC, arr, w);
		}else if (y==0 && x<0){
			rand_nem(1, 94, 2, 3, position_mobR, position_mobC, arr, w);
		}else if (x==0 && y>0){
			rand_nem(1, 2, 3, 94, position_mobR, position_mobC, arr, w);
		}else if (x==0 && y<0){
			rand_nem(3, 2, 94, 1, position_mobR, position_mobC, arr, w);
		}else if (x>0 && y>0){
			rand_nem(49, 1, 2, 48, position_mobR, position_mobC, arr, w);
		}else if (x>0 && y<0){
			rand_nem(49, 2, 48, 1, position_mobR, position_mobC, arr, w);
		}else if (x<0 && y>0){
			rand_nem(2, 48, 1, 49, position_mobR, position_mobC, arr, w);
		}else if (x<0 && y<0){
			rand_nem(1, 48, 49, 2, position_mobR, position_mobC, arr, w);
		}
		arr[position_mobR][position_mobC]= mob;
		shift_entity(position_mobR, position_mobC, mob);
	}
}

void mov_enemy(char lvl[][100], entity mobs[], int pR, int pC, int entitys, char wall, char pg){
	int r = 0;
	while(entitys>0){
		int positionmob_r = mobs[r].getpR();
		int positionmob_c = mobs[r].getpC();
		choose_where(pR, pC, positionmob_r, positionmob_c, lvl, wall, lvl[positionmob_r][positionmob_c], pg);
		mobs[r].setpR(positionmob_r);
		mobs[r].setpC(positionmob_c);
		r++;
		entitys--;
	}
}

void remove_arr(int n, entity mobs[], int what_enemy){
	for(int i=what_enemy; i<n; i++){
		mobs[i] = mobs[i+1];
	}
}


/*-----------------------------  SHOP  ---------------------------------------*/

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

void open_shop(player &pg){
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
		armor test={"name", 2, 100, 10 , 10, "d"};
		return test;
}

thing_to_use shop_get_thing(int x, int y){
	
}


/*-----------------------------  ATTACK  ---------------------------------------*/

double getTotalDamage(entity x, weapon y){
	double totalDamage = x.getDamage() + y.damage;
	return totalDamage;
}

double getTotalArmor(entity x, armor y){
	double totalArmor = x.getArmor() + y.protection;
	return totalArmor;
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

double enemy_lose_life(entity &entita_subire, player &entita_infliggere, int use_critic, int lenght){
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
		entita_subire.setLife(life);
		if(life>0){
			char number = (int(life/100)+48);
			char number1 = (int(life/10)+48);
			char number2 = (int(life)%10+48);
			shift_number(0, ' ', (lenght+5));
			if(number1 == '0'){
				shift_number(0, ' ', (lenght+5));	
			}else{
				shift_number(0, number1, (lenght+5));
			}
			shift_number(0, number2, (lenght+5));
			entita_subire.setLife(life);
			return life;
		}else{
			shift_number(0, ' ', (lenght+5));
			shift_number(0, '0', (lenght+5));
			return life;
		}
	}else{
		return life;
	}
}

double player_lose_life(player &entita_subire, entity &entita_infliggere, int use_critic, int height){
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
				life -= (danno * entita_subire.getCritic()) - n;
				break;
			case 2:
				life -= danno * entita_infliggere.getCritic();
				break;
			default:
				cout << "ERRORE CALCOLO CRITICO CASE DEFAULT" << endl;
				system("pause");
		}
		
		if(life > 0){
			char number = (int(life / 100) + 48);
			char number1 = (int((int(life) % 100)/10) + 48);
			char number2 = (int(life) % 10 + 48);
			if(number == '0'){
				shift_number(height, ' ', 6);	
			}else{
				shift_number(height, number, 6);
			}
			if(number1 == '0'){
				shift_number(height, ' ', 7);	
			}else{
				shift_number(height, number1, 7);
			}
			if(life-(int(life))!=0.0){
				char number3 = int((life-(int(life)))*10)+48;
				shift_number(height, '.', 9);
				shift_number(height, number3, 10);
			}else{
				shift_number(height, ' ', 9);
				shift_number(height, ' ', 10);
			}
			shift_number(height, number2, 8);
			entita_subire.setLife(life);
			return life;
		}else{
			shift_number(height, ' ', 7);
			shift_number(height, '0', 8);
			entita_subire.setLife(life);
			return life;
		}
		
		
	}else{
		return life;
	}
}


/*-----------------------------  INVENTORY  ---------------------------------------*/

void use_inventory(object inventory[][4]){
	system("cls");
	cout << "		-------------------------------------------------" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout << "		-------------------------------------------------" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout << "		-------------------------------------------------" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout << "		-------------------------------------------------" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout <<	"		|           |           |           |           |" << endl;
	cout << "		-------------------------------------------------" << endl;
	char text[100];
	int i = 0;
	do{
		char z;
		z = get_button2();
		if(z == 13){
			break;
		}else{
			do{
				text[i] = z;
				cout << z;
				i++;
				z = get_button2();
				if(z == 13){
					cout << endl;
					break;
				}
				int first = 0, second = 0;
				player pg;
				for(int contatore = 0; contatore <= 16; contatore++){
					/////// SE TEXT[] = INVENTORY[0][0]{SCAMBIA(..,..)}   ....... BREAK;				
					second++;
					if(second = 10){
						second = 0;
						first++;
					}
				}
			}while(1<2);
			
		}
	}while(3<4);
}

void move_weapon_to_inventory(player &pg, weapon &x){
		weapon contenitore = pg.getWeapon();
		pg.setWeapon(x);
		x = contenitore;
}

void move_armor_to_inventory(player &pg, armor &x){
	armor contenitore = pg.getWearArmor();
	pg.setWearArmor(x);
	x = contenitore;
}

void use_thing(player &pg, thing_to_use &x){
	
}


/*-----------------------------  LEVEL  ---------------------------------------*/

void control_exp(player &pg, maps map_level, char lvl[][100]){
	double x = pg.getExp();
	double y = pg.getExpController();
	bool cont = false;
	if(y <= 49 && x > 49){
		cont = true;
	}
	if(y <= 89 && x > 89){
		cont = true;
	}
	if(y <= 149 && x > 149){
		cont = true;
	}
	if(y <= 199 & x >= 199){
		cont = true;
	}
	if(y <= 249 && x > 249){
		cont = true;
	}
	if(y <= 299 & x > 299){
		cont = true;
	}
	if(y <= 369 && x >= 369){
		cont = true;
	}
	if(y <= 439 && x > 439){
		cont = true;
	}
	if(cont == true){
		pg.setExpController(pg.getExp());
		level_up(pg, map_level, lvl);
	}
}

void level_up(player &pg, maps map_level, char lvl[][100]){
	system("cls");
	int lvlo = pg.getLevel();
	lvlo++;
	int x;
	switch(lvlo){
		case 2:
			x = 4;
			break;
		case 3:
			x = 6;
			break;
		case 4:
			x = 7;
			break;
		default:
			x = 8;
			break;
	}
	char l = 219;
	char s = ' ';
	char w = 219;
	cout << s, s, s, s, s, s, s, s, 
	cout << "Hai a disposizione " << x << " punti da spendere in: " << endl << "-Life (1)" << endl << "-Damage (2)" << endl << "-Armor (3)" << endl << "-Critic (4)" << endl;
	double life[20];
	life[0] = 120;
	for(int i=1; i <= 20; i++){
		life[i] = life[i - 1] + 10;	
	}
	double damage[20];
	damage[0] = 5.5;
	for(int i=1; i <= 20; i++){
		damage[i] = damage[i - 1] + 0.5;	
	}
	double armor[20];
	armor[0] = 5.5;
	for(int i=1; i <= 20; i++){
		armor[i] = armor[i - 1] + 0.6;	
	}
	double critic[20];
	critic[0] = 0.2;
	for(int i=1; i <= 20; i++){
		critic[i] = critic[i - 1] + 0.1;	
	}
	bool cia = true;
	string scelta;
	int contatore;
	while(x > 0){
		scelta = "x";
		cia = true;
		do{
			cin >> scelta;
			if(scelta == "life" || scelta == "damage" || scelta == "armor" || scelta == "critic" || scelta == "1" || scelta == "2" || scelta == "3" || scelta == "4"){
				cia = false;
			}
		}while(cia == true);
		contatore = 0;
		if(scelta == "life" || scelta == "1"){
			for(int i=0; pg.getMaxLife() >= life[i]; i++){
				contatore++;
			}
			pg.setLife(life[contatore]);
			pg.setMaxLife(life[contatore]);
		}
		if(scelta == "damage" || scelta == "2"){
			for(int i=0; pg.getDamage() >= damage[i]; i++){
				contatore++;	
			}
			pg.setDamage(damage[contatore]);
		}
		if(scelta == "armor" || scelta == "3"){
			for(int i=0; pg.getArmor() >= armor[i]; i++){
				contatore++;
			}
			pg.setArmor(armor[contatore]);
		}
		if(scelta == "critic" || scelta == "4"){
			for(int i=0; pg.getCritic() >= critic[i]; i++){
				contatore++;
			}
			pg.setCritic(critic[contatore]);
		}
		cout << pg.getLife() << endl;
		cout << pg.getArmor() << endl;
		cout << pg.getDamage() << endl;
		cout << pg.getCritic() << endl;
		x--;
	}
	system("cls");
	print_map(lvl, map_level.rows, map_level.cols);
	cout << endl << endl << "Vita: " << pg.getLife() << endl;
}


/*-----------------------------  SET  ---------------------------------------*/

void player_name(char nome[9]){
	cout << "Inserire un nome" << endl;
	cin >> nome[9];
}

player pg_set(player &x){
	weapon falce = shop_get_weapon(1,2);
	armor test = shop_get_armor(1,2);
	x.setArmor(5);
	x.setCritic(0.1);
	x.setDamage(5);
	x.setExp(0);
	x.setHunger(100);
	x.setLife(100);
	x.setMoney(0);
	x.setWeapon(falce);
	x.setWearArmor(test);
	x.setLevel(1);
	x.setMaxLife(100);
	x.setExpController(0);
	return x;	
}

entity bot_set(entity &x){
	weapon falce = shop_get_weapon(1,2);
	armor test = shop_get_armor(1,2);
	x.setArmor(3);
	x.setCritic(0.5);
	x.setDamage(5);
	x.setLife(10);
	x.setWeapon(shop_get_weapon(4,9));
	x.setWearArmor(test);
	return x;
}

void set_mobs(entity mobs[], int entitys){
	for(int i = 0; i < entitys; i++){
		bot_set(mobs[i]);
	}
}

bool test(char button, player pg, int map_rows, int map_cols, char lvl[][100]){
	object inventory[4][4];
	bool open = false;
	if(button == 'e'){
		use_inventory(inventory);
		system("cls");
		print_map(lvl, map_rows, map_cols);
		cout << endl << endl << "Vita: " << pg.getLife() << endl;
		open = true;
	}
	
	//cout << "La vita rimasta del bot e' " << enemy_lose_life(bot, pg, critic_probability(pg)) << endl;
	
	if(button == 'q'){
		open_shop(pg);
		system("cls");
		print_map(lvl, map_rows, map_cols);
		cout << endl << endl << "Vita: " << pg.getLife() << endl;
		open = true;
	}

	return open;
	
}






int main(int argc, char** argv) {
	
///////////screen color///////////
	
	system("color 04B");
	
//////////initzialize object////////
	 
	player pg;
	entity bot;
	pg_set(pg);
	bot_set(bot);
	maps map_level;
	
//////////initzialize variables////////
	
	bool wall=false;	
	int rows=0;
	int cols=0;
	int pc=0;
	int pr=0;
	int wherex = 0;
	int wherey = 0;
	int what_enemy = 0;
	bool hit = false;
	bool change = false;
	char lvl[50][100];
	char name[9];
	entity mobs[50];
	
//////////set player name///////////
	
	player_name(name);
	system("cls");

/////////set map level and dimension of it//////////////

	map_level.choose_map(lvl);
	map_level.size(lvl, map_level.c, rows, cols);
	map_level.cols=cols;
	map_level.rows=rows;
	
/////////set bots//////////////
	
	int entitys = howmany(lvl,  map_level.rows, map_level.cols, map_level.e, map_level.rows, map_level.cols);
	set_mobs(mobs, entitys);
	position_enemy(lvl, map_level.rows, map_level.cols, map_level.e, mobs, entitys);
	
////////set pg position///////////
	
	position(lvl, map_level.rows, map_level.cols, map_level.y, pg);
	
////////print///////////
	
	print_map(lvl, map_level.rows, map_level.cols);
	cout << endl << endl << "Vita: " << pg.getLife() << endl;
	
	do{
		char button=get_button();																									
		bool open = test(button, pg, map_level.rows, map_level.cols, lvl);													
		if (open == false){																													//if you didn't open nothing (so, if you are moving) do this
			lvl[pg.getpR()][pg.getpC()] = ' ';																						//delate you from the array
			mov(pg, button);																		//move you
			wall = walls(lvl, map_level.cols,map_level.w, pg);																		//controls if in the new position there is a wall
			if(wall == true){																												//if there is a wall do this
				back(button, pg);																											//put you back in the old position
			}else{
				back(button, pg);
				delate_entity(pg.getpR(), pg.getpC());	
				mov(pg, button);																			
				mov_enemy(lvl, mobs, pg.getpR(), pg.getpC(), entitys, map_level.e, map_level.y);
			}
			hit = enemy(button, lvl, map_level.cols, map_level.e, wherex, wherey, pg);
			change = win(button, lvl, map_level.cols,map_level.d, pg);
			lvl[pg.getpR()][pg.getpC()] = map_level.y;
			if(hit == true){
				int f = 0;
				for(int i=0; i<entitys; i++){
					if(wherex == mobs[f].getpR() && wherey == mobs[f].getpC()){
						what_enemy = i; 
						break;
					}else{
						f++;
					}
				}	
				enemy_lose_life(mobs[what_enemy], pg, critic_probability(pg), map_level.cols);	
				if(mobs[what_enemy].getLife()<=0){
					lvl[mobs[what_enemy].getpR()][mobs[what_enemy].getpC()]=' ';
					delate_entity(mobs[what_enemy].getpR(), mobs[what_enemy].getpC());
					entitys--;
					remove_arr(entitys, mobs, what_enemy);
					pg.setExp(60);
					control_exp(pg, map_level, lvl);
				}
				player_lose_life(pg, bot, critic_probability(bot), map_level.rows);
			}
		shift_entity(pg.getpR(), pg.getpC(), map_level.y);
		Sleep(100);
		if (pg.getLife()<=0){
			break;
		}
		if(change==true){
			system("cls");
			bot_set(bot);
			map_level.choose_map(lvl);
			map_level.size(lvl, map_level.c, rows, cols);
			map_level.cols=cols;
			map_level.rows=rows;
			int entitys = howmany(lvl,  map_level.rows, map_level.cols, map_level.e, map_level.rows, map_level.cols);
			set_mobs(mobs, entitys);
			position_enemy(lvl, map_level.rows, map_level.cols, map_level.e, mobs, entitys);
			position(lvl, map_level.rows, map_level.cols, map_level.y, pg);
			print_map(lvl, map_level.rows, map_level.cols);
			cout << endl << endl << "Vita: " << pg.getLife() << endl;
		}
	}
	cout << pg.getpR() << "  " << pg.getpC() << " | ";
	}while(3<4);
	return 0;
}
