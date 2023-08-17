#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>


void red () {
  printf("\033[1;31m");
}

void green () {
  printf("\033[1;32m");
}

void yellow () {
  printf("\033[1;33m");
}

void blue () {
  printf("\033[1;34m");
}

void magenta () {
  printf("\033[1;35m");
}

void cyan () {
  printf("\033[1;36m");
}

void reset () {
  printf("\033[0m");
}


typedef struct entity{
	int hp;
	int mana;
	int maxmana;
	int def;
	int dot;
	int ailment;
}entity;



typedef struct card{
	char type;
	int cost;
	int atk;
	int def;
	int dot;
	int ailment;
}card;







int main(){


srand(time(NULL));

entity player;
	player.hp=100;
	player.mana=3;
	player.maxmana=3;
	player.def=0;
	player.dot=0;
	player.ailment=0;


card strike;
	strike.type='s';
	strike.cost=1;
	strike.atk=15;
	strike.def=0;
	strike.dot=0;
	strike.ailment=0;

card sstrike;
	sstrike.type='s';
	sstrike.cost=2;
	sstrike.atk=25;
	sstrike.def=5;
	sstrike.dot=0;
	sstrike.ailment=0;

card bash;
	bash.type='s';
	bash.cost=3;
	bash.atk=60;
	bash.def=0;
	bash.dot=0;
	bash.ailment=0;

	
card defend;
	defend.type='d';	
	defend.cost=1;
	defend.atk=0;
	defend.def=15;
	defend.dot=0;
	defend.ailment=0;
	
card sdefend;
	sdefend.type='d';
	sdefend.cost=2;
	sdefend.atk=5;
	sdefend.def=25;
	sdefend.dot=0;
	sdefend.ailment=0;

int handsize=4;
int nstr=5;
int ndef=5;
int nsstr=3;
int nbash=1;
int nsdef=3;
int decksize=nstr+ndef+nsstr+nsdef+nbash;

card deck[decksize];


//shuffle deck
{
	int str=0;
	int def=0;
	int sustr=0;
	int sudef=0;
	int sbash=0;
	int i=0;
	for (;;){
		if(i==decksize){break;};
		int rn= rand() % 10;
		if((str!=nstr)&&(rn%5==0)){deck[i]=strike;i++;str++;}
		if((def!=ndef)&&(rn%5==1)){deck[i]=defend;i++;def++;};
		if((sustr!=nsstr)&&(rn%5==2)){deck[i]=sstrike;i++;sustr++;};
		if((sudef!=nsdef)&&(rn%5==3)){deck[i]=sdefend;i++;sudef++;};
		if((sbash!=nbash)&&(rn%5==4)){deck[i]=bash;i++;sbash++;};
	};


}

system("clear");

green(); printf("T I T L E   P E N D I N G\n"); reset();
printf("A short combat *roleplaying* game made by ");
magenta(); printf("Prognar"); reset();
printf(".\n\n\n\n");


printf("Welcome to your "); 
red(); printf("D O O M");reset(); 
printf(" adventurer!\n" );
printf("Many venture into these danger infested caves for ");
green(); printf("G L O R Y"); reset();
printf(" or "); 
yellow(); printf("R I C H E S"); reset(); 
printf(", but few make it out alive.\n");
printf("You yourself decided to delve into the deep, and had a relatively uneventful journey to the dungeon's core.\n");	
printf("Here you found the sweetest ");
yellow(); printf("C A C H E   O F   L O O T"); reset();
printf(" you've seen in your career.\n");
printf("Now on your way back with ");
yellow(); printf("S P O I L S"); reset();
printf(" in your bag, you encounter the ");
green(); printf("G R E E N   T I D E"); reset();
printf(".\n");
printf("Let's hope the ");
green(); printf("G O B L I N   H O R D E"); reset();
printf(" doesn't ");
red(); printf("S P O I L"); reset();
printf(" your day.\n");
printf("Grit your teeth adventurer, and struggle to stay ");
cyan(); printf("A L I V E"); reset();
printf(".\n");
printf("Through combat, will you march towards ");
cyan(); printf("H A V E N"); reset();
printf(" or ");
red(); printf("D E A T H"); reset(); 
printf(" ?\n\n\n\n");




card hand[handsize];

int used[decksize];

int scalehp=0;
int scalepoison=0;
int scaleattack=0;
int scaledefence=0;

for (int i=0;i<decksize;i++){
	used[i]=-1;	
};



int gobdead=0;
int gobhp= rand() % 100 ;	

for(;;){
	
	if(gobdead==1){
	gobhp= rand() % 100 + scalehp*20;
	};
	
int gobpoison= rand() % 10 + scalepoison*2;

int gobattack= rand() % 20 + scaleattack*5;
//gobattack+=10;

int gobdefend= rand() % 20 + scaledefence*5;
//gobdefend+=10;


int gobrand= rand() % 100;
int gobtype;

char gobaction[25];
int gobvalue;


{
int i=0;
for(;;){
	
	if((gobhp<=0)||(player.hp<=0)){break;break;}else{gobdead=0;}
	
	if(i==handsize){break;};
	
	int unused=decksize;
	
	for(int j=0;j<decksize;j++){
		if(used[j]!=-1){unused--;};
	};
		
	if(unused==0){ 
	{
	int str=0;
	int def=0;
	int i=0;
	for (;;){
		if(i==decksize){break;};
		int rn= rand() % 10;
		if((str!=nstr)&&(rn%2==0)){deck[i]=strike;i++;str++;}
		else if((def!=ndef)&&(rn%2==1)){deck[i]=defend;i++;def++;};
	};


}
	
	};
	
	int rn= rand() % decksize ;
	int nobueno=0;
	
	for(int j=0;j<decksize;j++){
	if(used[i]==rn){nobueno++;}
	}
	
	if(nobueno==0){used[rn]=rn;hand[i]=deck[rn];i++;}
	
	
};

}

/*
if((gobrand%5)%2==0){strcpy(gobaction,"attack you");gobvalue=gobattack;gobtype=1;};
if((gobrand%5)%2==1){strcpy(gobaction,"defend itself");gobvalue=gobdefend;gobtype=2;};
if(gobrand%5==0){strcpy(gobaction,"poison you");gobvalue=gobpoison;gobtype=0;};
*/

if(gobrand%3==0){strcpy(gobaction,"poison you");gobvalue=gobpoison;gobtype=0;};
if((gobrand%3)==1){strcpy(gobaction,"attack you");gobvalue=gobattack;gobtype=1;};
if((gobrand%3)==2){strcpy(gobaction,"defend itself");gobvalue=gobdefend;gobtype=2;};


int input[handsize];
for (int i=0;i<handsize;i++){
	input[i]=-1;
};

int damagein=0;

if(gobtype==1){damagein=gobvalue;};

int asshat=0;

for(;;){



if(asshat==1){yellow(); printf("You can't do that asshat!\n\n"); reset(); asshat=0;}




printf("Your foe is a vicious gobbo with ");

red();
printf("%d health",gobhp);
reset();

printf(", it plans to"); 

/*	
if(gobrand%5==0){green();};
if((gobrand%5)%2==0){red();};
if((gobrand%5)%2==1){cyan();};
*/

if(gobrand%3==0){green();};
if((gobrand%3)==1){red();};
if((gobrand%3)==2){cyan();};
printf(" %s ",gobaction); 
reset();

printf("for"); 

if(gobrand%3==0){green();};
if((gobrand%3)==1){red();};
if((gobrand%3)==2){cyan();};
printf(" %d ",gobvalue); 
reset();

printf("this turn!\n\n");


printf("With your ");

red();
printf("%d health",player.hp); 
reset();


if(player.dot!=0){
	green();
	printf(" -%d per turn poison",player.dot);
	reset();
}

if(player.def!=0){
	cyan();
	printf(" and +%d shields",player.def);
	reset();
}

printf(" and ");

magenta();
printf("%d",player.mana);
reset();

printf(" energy left you decide to:\n");

for (int i=0;i<handsize;i++){
	if((hand[i].type=='s')&&(input[i]!=i)){printf("%d ",i+1); red(); printf("WAAAAAGH!!!");}
	if((hand[i].type=='d')&&(input[i]!=i)){printf("%d ",i+1); cyan(); printf("Cower in fear!");};
	
	if(input[i]!=i)printf("\ncost: %d\natk: %d\ndef: %d\n",hand[i].cost,hand[i].atk,hand[i].def);

reset();
};

int inp;
scanf("%d",&inp);
inp--;

if((inp==0)&&(input[inp]==-1)&&(hand[inp].cost<=player.mana)){

	input[inp]=inp;

	player.def+=hand[inp].def;
	
	if(gobtype!=2){gobhp-=hand[inp].atk;}
	if(gobtype==2){
		if((gobvalue>0)&&(gobvalue>hand[inp].atk)){gobvalue-=hand[inp].atk;}
		else{
			int temp=(hand[inp].atk-gobvalue);
			gobvalue=0;
			gobhp-=temp;
		}
	}
	player.mana-=hand[inp].cost;
}
else if((inp==1)&&(input[inp]==-1)&&(hand[inp].cost<=player.mana)){
	
	input[inp]=inp;

	player.def+=hand[inp].def;
	
	if(gobtype!=2){gobhp-=hand[inp].atk;}
	if(gobtype==2){
		if((gobvalue>0)&&(gobvalue>hand[inp].atk)){gobvalue-=hand[inp].atk;}
		else{
			int temp=(hand[inp].atk-gobvalue);
			gobvalue=0;
			gobhp-=temp;
		}
	}
	player.mana-=hand[inp].cost;
}
else if((inp==2)&&(input[inp]==-1)&&(hand[inp].cost<=player.mana)){

	input[inp]=inp;
	
	player.def+=hand[inp].def;
	
	if(gobtype!=2){gobhp-=hand[inp].atk;}
	if(gobtype==2){
		if((gobvalue>0)&&(gobvalue>hand[inp].atk)){gobvalue-=hand[inp].atk;}
		else{
			int temp=(hand[inp].atk-gobvalue);
			gobvalue=0;
			gobhp-=temp;
		}
	}
	player.mana-=hand[inp].cost;
}
else if((inp==3)&&(input[inp]==-1)&&(hand[inp].cost<=player.mana)){
	
	input[inp]=inp;
	
	player.def+=hand[inp].def;
	
	if(gobtype!=2){gobhp-=hand[inp].atk;}
	if(gobtype==2){
		if((gobvalue>0)&&(gobvalue>hand[inp].atk)){gobvalue-=hand[inp].atk;}
		else{
			int temp=(hand[inp].atk-gobvalue);
			gobvalue=0;
			gobhp-=temp;
		}
	}
	player.mana-=hand[inp].cost;
}else{asshat=1;}



if((gobhp<=0)||(player.hp<=0)){break;break;}else{gobdead=0;}

if(player.mana==0){
	if(gobtype==0){player.dot+=gobvalue;};
	player.hp-=player.dot;
	player.dot=player.dot/2;
	if((gobtype==1)&&(gobvalue>player.def)){player.hp=(player.hp+player.def)-gobvalue;};
	player.mana=player.maxmana;
	player.def=0;
	system("clear");
	break;
	}
system("clear");
}

if(player.hp<=0){system("clear");red();printf("Y O U   D I E D");reset();break;}

if(gobhp<=0){
	system("clear");
	green();
	printf("You vanquished your foe, but here comes another even worse one! The exit seems further and further away.\n\n");
	yellow(); 
	sleep(3);
	reset();
	gobdead=1;
	scaleattack++;
	scalepoison++;
	scaledefence++;
	scalehp++;
	player.mana=player.maxmana;
	player.def=0;
	}

}









return 0;
};


