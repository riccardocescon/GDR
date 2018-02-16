#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <time.h>

using namespace std;

struct weapon{
	string name;
	double damage;
	double durability;
	int priceIn;
	int priceOut;
	string description;
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

weapon get_weapon(int x, int y){
		/*-----BASE WEAPONS-----*/
		weapon spada_rotta={"Spada Rotta", 3, 30, 15, 5,"E' una spada rotta"};
		weapon bastone={"Bastone", 2, 20, 10, 3,"E' un bastone di legno"};
		weapon frusta={"Frusta", 2, 40, 15, 5,"E' una frusta"};
		weapon wahaika={"Wahaika", 2.5, 40, 20, 7,"Gli antichi Maori utilizzavano lo Wahaika come pugnale, sebbene assomigli e venga considerata una clava. È intagliato nel legno, oppure raramente nelle ossa di balena. "};
		weapon manganello={"Manganello", 5, 50, 20, 8,"E' un'arma contundente"};
		weapon macana={"Makana", 6.5, 60, 30, 10,"E' un'arma simile ad una spada, fatta in legno, ma sufficientemente affilata da essere pericolosa"};
		weapon kriss={"Kriss", 6, 50, 25, 8,"Il kriss è un tipico coltello-pugnale malese,con lama a biscia "};
		weapon cinquedea={"Cinquedea", 6, 60, 20, 9,"La Cinquedea,è un'arma bianca manesca del tipo spada corta originatasi nel XV secolo in area veneta"};
		weapon tonfa={"Tonfa", 5, 50, 15, 7, "l tonfa è un'arma tradizionale delle arti marziali, È composto da una impugnatura lunga 12 cm, e da un corpo di lunghezza variabile dai 50 ai 60 cm circa."};
		weapon tirapugni={"Tirapugni", 8, 80, 40, 15, "Viene utilizzato sferrando pugni"};
		
		/*-----NORMAL WEAPONS-----*/
		weapon spada={"Spada", 12, 100, 55, 20,"E' una spada intatta, fatta di accaio"};
		weapon ascia={"Ascia", 14, 110, 65, 25, "Ascia di ferro, ottime per sgozzare mostri"};
		weapon tridente={"Tridente", 11, 90, 50, 15, "Tridente, arma consigliata per attaccare a distanze di sicurezza"};
		weapon pugnale={"Pugnale", 9, 55, 20, 5,"Usalo per uccidere silenziosamente i nemici"};
		weapon picca={"Picca", 11, 150, 50, 15,"Fatta per durare"};
		weapon dagaarondelle={"Daga a rondelle", 10, 90, 20, 4,"Una daga a rondelle è un pugnale originario dell'Europa del tardo medioevomolto diffuso e utilizzato da una gran varietà di persone dai mercanti ai cavalieri."};
		weapon lancia={"Lancia", 10, 100, 15, 3,"Una lancia in legno, non troppo resistente, ma meglio di niente"};
		weapon ken={"Ken", 13, 120, 55, 50, "Ken è il vocabologiapponese che identifica la spada a lama diritta, affilata su ambo i lati"};
		weapon goloko{"Goloko", 11, 100, 45, 10, "Il golok è un'arma da taglio simile ad un machete che può essere usato sia per lavori agricoli che come arma"};
		weapon hakapik={"Hakapik", 12, 110, 40, 5, "L'hakapik è un bastone di invenzione norvegese usato nella caccia alla foca"};
		
		/*-----DAMAGE WEAPONS-----*/
		weapon katana={"Katana", 17, 220, 80, 20, "La katana è la spada giapponese per antonomasia"};
		weapon alabarda={"Alabarda", 18, 200, 80, 18, "L'alabarda è l'arma inastata per antonomasia, a punta, tagliente da entrambi i lati."};
		weapon azza={"Azza", 20, 250, 90, 25,"L'azza è un'arma inastata diffusasi in Europa al volgere del Medioevo normalmente utilizzata dai soldati di fanteria e particolarmente adatta al combattimento contro avversari in armatura."};
		weapon zweihander={"Zweihander", 21, 210, 90, 25, "La zweihänder[ è un tipo di spada a due mani sviluppatasi nel corso del Rinascimento in Italia e nelle terre gravitanti intorno al Sacro Romano Impero Germanico."};
		weapon martellodaguerra={"Martello da Guerra", 23, 150, 95, 20, "E' un martello molto pesante per sfondare crani"};
		weapon tetsubo={"Tetsubo", 23, 230, 100, 25, "Il tetsubo è un'arma solitamente di legno molto simile a una Mazza da baseball, con l'eccezione che nella parte finale della mazza sono incastonate punte di metallo che possono essere di ferro, di rame " };
		weapon sarissa={"Sarissa", 17, 180, 70, 15, "La sarissa era la picca usata dai temuti guerrieri del regno di MacedoniaLunga fino a 6-7 metri, aveva corpo in legno di corniolo di grande diametro, una grossa punta di ferroe un tallone anch'essometallico."};
		weapon berdica={"Berdica", 18, 190, 85, 15, "La berdica era un'arma inastata in uso in Europa Orientale. Era una g di circa un metro e mezzo e lama di scure a mezzaluna" };
		weapon falcione={"Falcione", 19, 190, 90, 14,"Il falcione è una spada ad una mano con tagliente monofilare diffusasi in Europa durante il Medioevo."};
		weapon corsesca={"Corsesca", 17, 230, 85, 14, "La corsesca è un'arma inastata in uso negli eserciti europei durante il Medioevo, con asta di lunghezza compresa tra gli 1,8 ed i 2,5 metri e testa in metallo"};
		
		/*-----DUNGEON WEAPONS-----*/
		weapon mazzaferrata={"Mazza Ferrata", 25, 250, 100, 27, "E' una mazza fatta di ferro"};
		weapon asciabipenne={"Ascia Bipenne", 23, 270, 105, 27, "Ascia a doppia lama"};
		weapon martello={"Martello", 27, 180, 110, 28, "Martello da lavoro, molto potente ma poco resistente"};
		weapon mazzafrusto={"Mazzafrusto", 24, 280, 100, 20, "Il mazzafrusto è un'arma bianca di origine contadina." };
		weapon claymore={"Claymore", 25, 300, 120, 35, "Il termine in lingua inglese Claymore, indicadi spada usate dai guerrieri della Scozia tra Medioevo ed Età Moderna: 1-Claidheamh dha lamh (spada a due mani). 2-Claidheamh mòr (grande spada)"};
		weapon dirk={"Dirk", 23, 250, 107, 24, "Il dirk è un lungo pugnale di origine scozzese con la lama a un filo."};
		weapon kusarigama={"Kusarigama", 26, 275, 110, 23, "Il kusarigama è un'arma giapponeseutilizzata sia nel combattimento adistanza che nel corpo a corpo"};
		weapon sai={"Sai", 23, 200, 90, 19, " La sua forma è essenzialmente composta da una sorta di bastone arrotondato e appuntito, con due lunghe proiezioni non affilate attaccate al manico"};
		weapon falce={"Falce", 21, 245, 100, 21, "Falce da guerra indica una qualsiasi tipologia di arma bianca, manesca o inastata, ottenuta partendo dalla lama di una falce o di un falcetto." };
		weapon mazzapesante={"Mazza Pesante", 25.5, 230, 110, 28, "Si tratta di una mazza molto pesante, il materiale di cui è composta non è noto."};
		
		/*-----SPECIAL WEAPONS-----*/
		weapon none={"No Weapon", 0, 0, 0, 0,"none"};
		weapon sodegarami={"Sodegarami", 24, 350, 200, 100, "Il sodegarami è un'arma giapponese utilizzata soprattutto dalle forze di polizia samurai e per auto-difesa nel Giappone feudale."};
		weapon romfaia={"Romfaia", 35, 350, 300, 200, "È costituita da una lama ricurva affilata sul lato interno e si poteva utilizzare sia con una impugnatura a una mano che con una a due mani. Il danno che procurava era inflitto con un movimento a strappo e poteva mutilare un arto e decapitare l'avversario anche con un solo colpo."};

		return falce;
}

armor get_armor(int x, int y){
		armor none2={"No Armor", 0, 0, 0, 0,"none"};
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
		double damage;
		double armorbody;
		double critic;
		weapon hand_weapon;
		armor wear_armor;
		double totalDamage;
		double totalArmor;

	public:
		void setLife(double x){
			life += x;
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
		
		double totalDamage;
		double totalArmor;
};

double getTotalDamage(player x, weapon y){
	double totalDamage = x.getDamage() + y.damage;
	return totalDamage;
}

double getTotalArmor(entity x, armor y){
	double totalArmor = x.getArmor() + y.protection;
	return totalArmor;
}

/*class status{
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
};*/

bool use_critic(entity entita){
	double critic = entita.getCritic();
	bool critic_use;
	srand((unsigned)time(NULL));
	if(critic > 0.0){
		double n = rand() % 1000 / 10;
		if(critic >= n){
			return critic_use=true;
		}else{
			return critic_use=false;
		}
	}
	
}

double random_durability(){
	double x;
	srand((unsigned)time(NULL));
	x = rand() % 2;
	x = 0;
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

double lose_life(entity entita_subire, entity entita_infliggere, bool use_critic){
	double life = entita_subire.getLife();
	double danno = getTotalDamage(entita_infliggere, entita_infliggere.getWeapon()) - getTotalArmor(entita_subire, entita_subire.getWearArmor());
	if( danno > 0.0){
		life -= danno;
		double durability_lost = random_durability();
		weapon x = entita_infliggere.getWeapon();
		x.durability *= durability_lost;
		entita_infliggere.setWeapon(x);
		if(use_critic == true){
			return life -= danno * entita_infliggere.getCritic();
		}else{
			return life;
		}
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

void test(){
	player pg;
	char x;
	cin >> x;
	string inventory[10][10];
	if(x == 'e'){
		use_inventory(inventory);
	}
	weapon falce = get_weapon(1,2);
	pg.setWeapon(falce);
	pg.setDamage(3);
	pg.getDamage();
	entity bot;
	bot.setArmor(1);
	bot.getArmor();
	bot.setLife(5);
	bot.getLife();
	armor test = get_armor(1,2);
	bot.setWearArmor(test);
	cout << "durezza arma prima del colpo " << pg.getWeapon().durability << endl;
	cout << "pg total damage "<< getTotalDamage(pg,pg.getWeapon())<<endl;;
	cout << "bot total armor " << getTotalArmor(bot,bot.getWearArmor())<<endl;
	cout << "vita bot " << bot.getLife() << endl;
	cout << "vita rimasta "<<  lose_life(bot, pg, false) << endl;
	cout << "durezza arma dopo il colpo " << pg.getWeapon().durability << endl;
	system("pause");
	
	
}

int main(int argc, char** argv) {
	system("color 0B");
	char name[9];
	char map[100][100];
	player_name(name);
	test();
	system("cls");
	set_map(map);
	system("pause");
	return 0;
}

