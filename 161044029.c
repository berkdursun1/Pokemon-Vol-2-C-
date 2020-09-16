/* Charmander için --> Char , Pikachu için --> Pik , Squirtle için --> Squ , Bulbasaur --> Bul , Pidgetto --> Pid , Ratata --> Rat , Mug -->Mug , Caterpie --> Cat ,, Zubat --> Zub , Krabby --> Kra 










definetion                                           */
enum pokemon{Charmander,Pikachu,Squirtle,Bulbasaur,Pidgeotto,Ratata,Mug,Caterpie,Zubat,Krabby,Empty}; // define a type
enum attack_type{linear,quadratic};
struct coordinat{
	int x;
	int y;
};
#include <stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

int find_smallest(int a,int b,int c,int d){
    if(a<b && a<c && a<d){
        return a;
    }
    else if(b<a && b<c && b<d){
        return b;
    }
    else if(c<b && c<a && c<d){
        return c;
    }
    else if(d<b && d<c && d<a){
        return d;
    }
}








int the_smallest(int a,int b,int c,int  d){
    if(a<b && a<c && a<d) return a;
    if(b<a && b<c && b<d) return b;
    if(c<b && c<a && c<d) return c;
    if(d<b && d<c && d<a) return d;
    else return 7;
}

int lenght_of_str(char *str){
    int i=0;
    for(i=0;str[i]!=0;i++){}
    return i;
}
int cmp_str(char *str,char *str1){
    int i;
    int result=1;
    if(lenght_of_str(str)==lenght_of_str(str1)){
        for(i=0;str[i]!=0;i++){
            if(str[i]!=str1[i]) return 0;
        } 
    }
    else{
        return 0;
    }
    return result ; 
}

void pokedex(char *pokemon_name[11],int range[],enum attack_type type[],int attack_powe[],int stamina[]){
    //Charmander için --> Char , Pikachu için --> Pik , Squirtle için --> Squ , Bulbasaur --> Bul , Pidgetto --> Pid , Ratata --> Rat , Mug -->Mug , Caterpie --> Cat ,, Zubat --> Zub , Krabby --> Kra 

    int i,j;
    char searching[11];
    
    printf("input : ");
    scanf("%s",searching);
    for(i=0;i<10;i++){
        if(cmp_str(pokemon_name[i],searching)==1){
            printf("Name : %s\n",pokemon_name[i]);
            if(type[i]==linear) printf("A. Type : Linear\n");
            else printf("A. Type : Quadratic\n");
            printf("Range : %d block\nA. Power : %d\nStamina : %d",range[i],attack_powe[i],stamina[i]);
        }
        
    }

    printf("\n");
 

}
void show_Pokemons(char *Pokemon_name[11], enum pokemon Pokemons[], int
pokemon_count){
        int i=0;
            printf("0) %s\n",Pokemon_name[Pokemons[i]]);
        for(i=1;i<pokemon_count;i++){
            printf("%d) %s\n",i,Pokemon_name[Pokemons[i]]);
        }
}
void catch_a_pokemon(char *Pokemon_name[11],enum pokemon Pokemons[],enum pokemon
*my_pocket){
    int i=0;
    int j=0;
    int k=0;
    int l=0;
    int q=0;
    int choise;
    // dolu boş check
    for(i=0;i<4;i++){
        if(my_pocket[i]==Empty){
            q=1;
        }
    }
    if(q==0){
        show_Pokemons(Pokemon_name,my_pocket,10);
        printf("Cebiniz dolu");
    }
    else{

        show_Pokemons(Pokemon_name,Pokemons,10);
        printf("\nLutfen bir pokemon seciniz ->  ");
        scanf("%d",&choise);
        while(choise>9){
            printf("Warning p");
            scanf("%d",&choise);
        }
        //
        for(i=0;i<4;i++){
                if(my_pocket[i]==choise){
                   printf("Warning !");
                   k=1;
                }
            
        }
        for(i=0;i<4;i++){
            if(my_pocket[i]==Empty){
              j=i;
              l=1;
            } 
        }
        if(k==0 && l==1){
            my_pocket[j]=choise;
            
        }
        for(i=0;i<4;i++){
            printf("\n%d) %s\n",i,Pokemon_name[my_pocket[i]]);
        }
    }
}
void release_a_pokemon(char *Pokemon_name[11],enum pokemon Pokemons[],enum pokemon
*my_pocket){
    int temp=0;
    int i=0;
    int choise;
    for(i=0;i<4;i++){
        printf("%d) %s",i,Pokemon_name[my_pocket[i]]);
        printf("\n");
    }
    printf("Lutfen bir pokemon silin -> ");
    scanf("%d",&choise);
    if(my_pocket[choise]==Empty){
        printf("\nYanlıs tercih yaptıniz - > \n");
    }
    my_pocket[choise]=Empty;
    
    for(i=0;i<4;i++){
        printf("%d) %s",i,Pokemon_name[my_pocket[i]]);
        printf("\n");
    }
    
}
void oaks_laboratory(char *Pokemon_name[11],enum pokemon Pokemons[],enum pokemon
*my_Pokemons){
    
    int pokemon_count=10;
    
    
    int choise;
    do{
        printf("\n\n********\n\n");
        printf("1) Show_Pokemon\n2) Catch Pokemon\n3) Release Pokemon\n4) Show My Pocket\n5) Back\n");
        printf("Choise : ");
        scanf("%d",&choise);
        switch(choise){
            case 1 :
                show_Pokemons(Pokemon_name,Pokemons,pokemon_count);
            break;
            case 2 :
                catch_a_pokemon(Pokemon_name,Pokemons,my_Pokemons);
          
            break;
            case 3 :
                release_a_pokemon(Pokemon_name,Pokemons,my_Pokemons);
    
            break;
            case 4 :
                show_Pokemons(Pokemon_name,my_Pokemons,4);
            break;
            case 5 :
            break;
        }
            
        }while(choise!=5);
        
        
        
        
    
}
int find_empty(enum pokemon *my_pocket){ // find empty or not
	int i;
	int k=0;
	for(i=0;i<4;i++){
		if(my_pocket[i]!=Empty)	k=1;
	}
	return k;
}
void show_area (char *Pokemon_name[],int area[8][8],int pokemon_staminas[8][8]){
	int i=0;
	int k=0;
    int m=0;
    printf("\n");
	for(i=0;i<8;i++){
		for(k=0;k<8;k++){
			printf("|");
			if(area[i][k]==Empty) printf("\t\t");
		    else{
                printf("%s(%d)\t",Pokemon_name[area[i][k]],pokemon_staminas[i][k]);

               
            }	


            
		}
		printf("\n");
	}
    
}
int check(enum pokemon pok1[4]){ // pyunun bitip bitmedigini kontrol
    int i=0;
    int k=0;
    for(i=0;i<4;i++){
        if(pok1[i]!=Empty){
        	k=1;
        }  
    }
    return k; 
}
int check1(enum pokemon pok1[4]){ // cebinin dolu olup olmadıgını kontro
    int i=0;
    for(i=0;i<4;i++){
        if(pok1[i]==Empty)  return 1;
        
    }

    return 0; 
}




void battle(char *Pokemon_name[], int range[],enum attack_type type[], int
attack_power[], int stamina[],enum pokemon user_Pokemons[]){
    int x1[11];
    int y1[11];
    int x2[11];
    int y2[11];
    int i = 0 ;
    int k=0;
    int control=0;
    int pokg;
    int kor;
    int yatay1=100;
    int yatay2=100;
    int dikey1=100;
    int dikey2=100;
    int uzaklik;
    int ync=0; // oyuncu
    int u1; // sag
    int u2; // sol
    int u3; // yukarı
    int u4; // aşagı
    int sald;
    enum pokemon artillegent[4]={Charmander,Pikachu,Mug,Caterpie};
    int area[8][8]={{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
                        {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
                            {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
                                {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
                                    {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
                                        {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
                                            {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
                                                {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty}};    
    int pokemon_staminas[8][8]={{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
                                    {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
                                        {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
                                            {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
                                                {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
                                                    {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
                                                        {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
                                                            {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty}};
    if(check1(user_Pokemons)==1){
        ync=101;
        printf("Error pls catch pokemon"); // cep dolu degil
    }
    for(i=0;i<4;i++){
        artillegent[i]=rand()%10;
        if(i==0){
            while(artillegent[i]==artillegent[i+1] || artillegent[i]==artillegent[i+2] || artillegent[i]==artillegent[i+3]){
                artillegent[i]=rand()%10;
            }
        }
        else if(i==1 || i==2){
            while(artillegent[i]==artillegent[i-1] || artillegent[i]==artillegent[i+1] || artillegent[i]==artillegent[i+2]){
                artillegent[i]=rand()%10;
            }   
        }
        else{
            while(artillegent[i]==artillegent[i-2] || artillegent[i]==artillegent[i-1] || artillegent[i]==artillegent[i-3]){
                artillegent[i]=rand()%10;
            }
        }
    }
    for(i=0;i<=3;i++){
    	while(artillegent[i]==user_Pokemons[0] || artillegent[i]==user_Pokemons[1] || artillegent[i]==user_Pokemons[2] || artillegent[i]==user_Pokemons[3]  )
    	{
    		artillegent[i]=rand()%10;
    	}
    }

    show_area(Pokemon_name,area,pokemon_staminas);	    
    for(i=0;i<4 && ync!=101;i++){
        printf("Coordinat x %s pokemonu icin: ",Pokemon_name[user_Pokemons[i]]);
        scanf("%d",&x1[user_Pokemons[i]]);

        printf("Coordinat y %s pokemonu icin: ",Pokemon_name[user_Pokemons[i]]);
        scanf("%d",&y1[user_Pokemons[i]]);
        while(y1[user_Pokemons[i]]>2){
            printf("Warning !! pls again");
            scanf("%d",&y1[user_Pokemons[i]]);
        }
        area[y1[user_Pokemons[i]]][x1[user_Pokemons[i]]]=user_Pokemons[i];
        pokemon_staminas[y1[user_Pokemons[i]]][x1[user_Pokemons[i]]]=stamina[user_Pokemons[i]];      
    }
    for(i=0;i<4;i++){
    //    artillegent[i]=rand()%10;
        for(k=1;k<4;k++){
            while(artillegent[i]==artillegent[k] && i!=k) artillegent[i]=rand()%10;
        }
       
    }
    i=0;
    for(i=0;i<4;i++){
        
        x2[artillegent[i]]=rand()%7;
       
    //    printf("%d",x2[artillegent[i]]);
     /*   for(k=0;k<4;k++)
        {
            while(x2[artillegent[i]]==x2[artillegent[k]] && y2[artillegent[i]]==y2[artillegent[k]]) x2[artillegent[i]]=rand()%7; 
        }
     */   y2[artillegent[i]]=5+rand()%2;
          for(k=0;k<4;k++){
            while(x2[artillegent[i]]==x2[artillegent[k]] && y2[artillegent[i]]==y2[artillegent[k]] && i!=k){
                x2[artillegent[i]]=rand()%7;
                y2[artillegent[i]]=5+rand()%2;
            }
          }
     //   printf("%d",y2[artillegent[i]]);
        area[y2[artillegent[i]]][x2[artillegent[i]]]=artillegent[i];   
        pokemon_staminas[y2[artillegent[i]]][x2[artillegent[i]]]=stamina[artillegent[i]];
    }
    show_area(Pokemon_name,area,pokemon_staminas);
    while(check(user_Pokemons)==1 && check(artillegent)==1 && ync!=101){
        
        for(i=0;i<4;i++) printf("%d -> %s\n",i,Pokemon_name[user_Pokemons[i]]);
            if(ync%2==0){
            printf("Choise : ");
            scanf("%d",&pokg);
            while(user_Pokemons[pokg]==Empty){
                printf("Warning pls select again -> ");
                scanf("%d",&pokg);

            }
            printf("2)Aşagı 22)Çift Aşagı\n");
            printf("6)Sag 66)Çift Sag\n");
            printf("8)Yukarı 88)Çift Yukarı\n");
            printf("4)Sol 44)Çift Sol\n");
            printf("ilerlemek istediginiz yönü seçiniz : ");
            scanf("%d",&kor);
            if(kor==2 && y1[user_Pokemons[pokg]]+1 < 8 && area[y1[user_Pokemons[pokg]]+1][x1[user_Pokemons[pokg]]]==Empty ){
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=Empty;
                pokemon_staminas[y1[user_Pokemons[pokg]]+1][x1[user_Pokemons[pokg]]]=pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]];
                pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=-1;
                y1[user_Pokemons[pokg]]++;
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=user_Pokemons[pokg];
                
            }
            else if(kor==4 && x1[user_Pokemons[pokg]]-1 >= 0 && area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-1]==Empty){
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=Empty;
                pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-1]=pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]];
                pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=-1;
                x1[user_Pokemons[pokg]]--;
                
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=user_Pokemons[pokg];
            }
            else if(kor==6 && x1[user_Pokemons[pokg]]+1 < 8 && area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+1]==Empty){
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=Empty;
                pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+1]=pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]];
                pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=-1;
                x1[user_Pokemons[pokg]]++;
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=user_Pokemons[pokg];
                
            }
            else if(kor==8 && y1[user_Pokemons[pokg]]-1 >= 0 && area[y1[user_Pokemons[pokg]]-1][x1[user_Pokemons[pokg]]]==Empty){
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=Empty;
                pokemon_staminas[y1[user_Pokemons[pokg]]-1][x1[user_Pokemons[pokg]]]=pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]];
                pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=-1;
                y1[user_Pokemons[pokg]]--;
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=user_Pokemons[pokg];
            }
            else if(kor==22 && y1[user_Pokemons[pokg]]+2 < 8 && area[y1[user_Pokemons[pokg]]+2][x1[user_Pokemons[pokg]]]==Empty){
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=Empty;
                pokemon_staminas[y1[user_Pokemons[pokg]]+2][x1[user_Pokemons[pokg]]]=pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]];
                pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=-1;
                y1[user_Pokemons[pokg]]=y1[user_Pokemons[pokg]]+2;
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=user_Pokemons[pokg];
                
            }
            else if(kor==44 && x1[user_Pokemons[pokg]]-2 >= 0 && area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-2]==Empty){
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=Empty;
                pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-2]=pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]];
                pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=-1;
                x1[user_Pokemons[pokg]]=x1[user_Pokemons[pokg]]-2;
               
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=user_Pokemons[pokg];
            }
            else if(kor==66 && x1[user_Pokemons[pokg]]+2 < 8 && area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+2]==Empty){
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=Empty;
                pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+2]=pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]];
                pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=-1;
                x1[user_Pokemons[pokg]]=x1[user_Pokemons[pokg]]+2;
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=user_Pokemons[pokg];
                
            }
            else if(kor==88 && y1[user_Pokemons[pokg]]-2 >= 0 && area[y1[user_Pokemons[pokg]]-2][x1[user_Pokemons[pokg]]]==Empty){
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=Empty;
                pokemon_staminas[y1[user_Pokemons[pokg]]-2][x1[user_Pokemons[pokg]]]=pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]];
                pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=-1;
                y1[user_Pokemons[pokg]]=y1[user_Pokemons[pokg]]-2;
                
                area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]]=user_Pokemons[pokg];
            }
	    else{
		printf("Error");
        }
        u1=0;
        u2=0;
        u3=0;
        u4=0;
        if(type[user_Pokemons[pokg]]==linear){
            for(i=1;i<=range[user_Pokemons[pokg]];i++){
                for(k=0;k<=3;k++){
                    if(u1==0 && area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+i]==artillegent[k] && artillegent[k]!=Empty && x1[user_Pokemons[pokg]]+i<=8){
                            u1=i;
                            pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+i]=pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+i]-attack_power[user_Pokemons[pokg]];
                            if(pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+i]<=0){
                                 area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+i]=Empty;
                                 pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+i]=-1;
                                 artillegent[k]=Empty;
                            }
                            u2=100;
                            u3=100;
                            u4=100;
                            k=4;
                            i=range[user_Pokemons[pokg]]+1;

                    }
                    if(u2==0 && area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-i]==artillegent[k] && artillegent[k]!=Empty && x1[user_Pokemons[pokg]]-i>=0){
                        u2=i;
                        pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-i]=pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-i]-attack_power[user_Pokemons[pokg]];
                            if(pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-i]<=0){
                                 area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-i]=Empty;
                                 pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-i]=-1;
                                 artillegent[k]=Empty;
                            }
                            u1=100;
                            u3=100;
                            u4=100;
                            k=4;
                            i=range[user_Pokemons[pokg]]+1;
                    }
                    if(u3==0 && area[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]]==artillegent[k] && artillegent[k]!=Empty && y1[user_Pokemons[pokg]]+i<=8){
                        u3=i;
                        pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]]=pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]]-attack_power[user_Pokemons[pokg]];
                            if(pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]]<=0){
                                 area[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]]=Empty;
                                 pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]]=-1;
                                 artillegent[k]=Empty;
                            }
                            u2=100;
                            u1=100;
                            u4=100;
                            k=4;
                            i=range[user_Pokemons[pokg]]+1;
                    }
                    if(u4==0 && area[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]]==artillegent[k] && artillegent[k]!=Empty && y1[user_Pokemons[pokg]]-i>=0){
                        u4=i;
                        pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]]=pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]]-attack_power[user_Pokemons[pokg]];
                            if(pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]]<=0){
                                 area[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]]=Empty;
                                 pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]]=-1;
                                 artillegent[k]=Empty;
                            }
                            u2=100;
                            u3=100;
                            u1=100;
                            k=4;
                            i=range[user_Pokemons[pokg]]+1;
                    }
                }
            }
            


        }
            
        sald=0;
        if(type[user_Pokemons[pokg]]==quadratic){
            for(i=1;i<=range[user_Pokemons[pokg]];i++){
                for(k=0;k<=3;k++){
                    if(area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+i]==artillegent[k] && artillegent[k]!=Empty && x1[user_Pokemons[pokg]]+i<=8){
                        
                        pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+i]=pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+i]-attack_power[user_Pokemons[pokg]];
                        if(pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+i]<=0){
                         area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+i]=Empty;
                         pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]+i]=-1;
                         artillegent[k]=Empty;
                         
                        }
                    }
                    if(area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-i]==artillegent[k] && artillegent[k]!=Empty && x1[user_Pokemons[pokg]]-i<=8){
                        
                        pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-i]=pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-i]-attack_power[user_Pokemons[pokg]];
                        if(pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-i]<=0){
                             area[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-i]=Empty;
                             pokemon_staminas[y1[user_Pokemons[pokg]]][x1[user_Pokemons[pokg]]-i]=-1;
                             artillegent[k]=Empty;
                         
                        }
                    }
                    if(area[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]]==artillegent[k] && artillegent[k]!=Empty && x1[user_Pokemons[pokg]]-i<=8){
                        
                        pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]]=pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]]-attack_power[user_Pokemons[pokg]];
                        if(pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]]<=0){
                             area[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]]=Empty;
                             artillegent[k]=Empty;
                             pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]]=-1;   
                        }
                    }
                    if(area[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]]==artillegent[k] && artillegent[k]!=Empty && y1[user_Pokemons[pokg]]-i>=0){
                       
                        pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]]=pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]]-attack_power[user_Pokemons[pokg]];
                        if(pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]]<=0){
                             area[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]]=Empty;
                             pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]]=-1;
                             artillegent[k]=Empty;
                        }
                    }
                    if(area[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]-i]==artillegent[k] && artillegent[k]!=Empty && x1[user_Pokemons[pokg]]-i>=0 && y1[user_Pokemons[pokg]]-i>=0){
                       
                        pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]-i]=pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]-i]-attack_power[user_Pokemons[pokg]];
                        if(pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]-i]<=0){
                             area[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]-i]=Empty;
                             pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]-i]=-1;
                             artillegent[k]=Empty;
                        }
                    }
                    if(area[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]+i]==artillegent[k] && artillegent[k]!=Empty && x1[user_Pokemons[pokg]]+i<8 && y1[user_Pokemons[pokg]]-i>=0){
                       
                        pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]+i]=pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]+i]-attack_power[user_Pokemons[pokg]];
                        if(pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]+i]<=0){
                             area[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]+i]=Empty;
                             pokemon_staminas[y1[user_Pokemons[pokg]]-i][x1[user_Pokemons[pokg]]+i]=-1;
                             artillegent[k]=Empty;
                        }
                    }
                    if(area[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]+i]==artillegent[k] && artillegent[k]!=Empty && x1[user_Pokemons[pokg]]+i<8 && y1[user_Pokemons[pokg]]+i<8){
                       
                        pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]+i]=pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]+i]-attack_power[user_Pokemons[pokg]];
                        if(pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]+i]<=0){
                             area[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]+i]=Empty;
                             pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]+i]=-1;
                             artillegent[k]=Empty;
                        }
                    }
                    if(area[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]-i]==artillegent[k] && artillegent[k]!=Empty && x1[user_Pokemons[pokg]]+i<8 && y1[user_Pokemons[pokg]]-i>=0){
                       
                        pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]-i]=pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]-i]-attack_power[user_Pokemons[pokg]];
                        if(pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]-i]<=0){
                             area[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]-i]=Empty;
                             pokemon_staminas[y1[user_Pokemons[pokg]]+i][x1[user_Pokemons[pokg]]-i]=-1;
                             artillegent[k]=Empty;
                        }
                    }
                }
            }
        }
        
           
            ync++;
            
            
        }
        show_area(Pokemon_name,area,pokemon_staminas);
        
        if(ync%2==1 && check(user_Pokemons)==1 && check(artillegent)==1){
            kor=rand()%8;
            pokg=rand()%3;
            while(artillegent[pokg]==Empty) pokg=rand()%3;
    
            if(kor==0 && y2[artillegent[pokg]]+1 < 8 && area[y2[artillegent[pokg]]+1][x2[artillegent[pokg]]]==Empty){
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=Empty;
                pokemon_staminas[y2[artillegent[pokg]]+1][x2[artillegent[pokg]]]=pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]];
                pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=-1;
                y2[artillegent[pokg]]++;
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=artillegent[pokg];
                
            }
            else if(kor==1 && x2[artillegent[pokg]]-1 >= 0 && area[y2[artillegent[pokg]]][x2[artillegent[pokg]]-1]==Empty){
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=Empty;
                pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]-1]=pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]];
                pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=-1;
                x2[artillegent[pokg]]--;
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=artillegent[pokg];
            }
            else if(kor==2 && x2[artillegent[pokg]]+1 < 8 && area[y2[artillegent[pokg]]][x2[artillegent[pokg]]+1]==Empty){
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=Empty;
                pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]+1]=pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]];
                pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=-1;
                x2[artillegent[pokg]]++;
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=artillegent[pokg];
                
            }
            else if(kor==3 && y2[artillegent[pokg]]-1 >= 0 && area[y2[artillegent[pokg]]-1][x2[artillegent[pokg]]]==Empty){
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=Empty;
                pokemon_staminas[y2[artillegent[pokg]]-1][x2[artillegent[pokg]]]=pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]];
                pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=-1;
                y2[artillegent[pokg]]--;
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=artillegent[pokg];
                
            }
            else if(kor==4 && y2[artillegent[pokg]]+2 < 8 && area[y2[artillegent[pokg]]+2][x2[artillegent[pokg]]]==Empty){
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=Empty;
                pokemon_staminas[y2[artillegent[pokg]]+2][x2[artillegent[pokg]]]=pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]];
                pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=-1;
                y2[artillegent[pokg]]=y2[artillegent[pokg]]+2;
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=artillegent[pokg];
            }
            else if(kor==5 && x2[artillegent[pokg]]-2 >= 0 && area[y2[artillegent[pokg]]][x2[artillegent[pokg]]-2]==Empty){
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=Empty;
                pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]-2]=pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]];
                pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=-1;
                x2[artillegent[pokg]]=x2[artillegent[pokg]]-2;
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=artillegent[pokg];
            }
            else if(kor==6 && x2[artillegent[pokg]]+2 < 8 && area[y2[artillegent[pokg]]][x2[artillegent[pokg]]+2]==Empty){
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=Empty;
                pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]+2]=pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]];
                pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=-1;
                x2[artillegent[pokg]]=x2[artillegent[pokg]]+2;
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=artillegent[pokg];
            }
            else if(kor==7 && y2[artillegent[pokg]]-2 >= 0 && area[y2[artillegent[pokg]]-2][x2[artillegent[pokg]]]==Empty){
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=Empty;
                pokemon_staminas[y2[artillegent[pokg]]-2][x2[artillegent[pokg]]]=pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]];
                pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=-1;
                y2[artillegent[pokg]]=y2[artillegent[pokg]]-2;
                area[y2[artillegent[pokg]]][x2[artillegent[pokg]]]=artillegent[pokg];
            }
            else{
                printf("x : %d y : %d\n",x2[artillegent[pokg]],y2[artillegent[pokg]]);
                printf("no move\n");
            }
           
            if(type[artillegent[pokg]]==linear){
                for(i=1;i<range[artillegent[pokg]];i++){
                    for(k=0;k<4;k++){
                        if(area[y2[artillegent[pokg]]][x2[artillegent[pokg]]+i]==user_Pokemons[k] && user_Pokemons[k]!=Empty && x2[artillegent[pokg]]+i<8){
                            u1=i;
                            pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]+i]=pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]+i]-attack_power[artillegent[pokg]];
                            if(pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]+i]<=0){
                         
                            area[y2[artillegent[pokg]]][x2[artillegent[pokg]]+i]=Empty;
                            pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]+i]=-1;
                            user_Pokemons[k]=Empty;
                            k=4;
                            }
                            u2=100;
                            u3=100;
                            u4=100;
                            i=100;
                        }
                        else if( area[y2[artillegent[pokg]]][x2[artillegent[pokg]]-i]==user_Pokemons[k] && user_Pokemons[k]!=Empty && x2[artillegent[pokg]]-i>=0){
                            u2=i;
                            pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]-i]=pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]-i]-attack_power[artillegent[pokg]];
                            if(pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]-i]<=0){
                         
                            area[y2[artillegent[pokg]]][x2[artillegent[pokg]]-i]=Empty;
                            pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]-i]=-1;
                            user_Pokemons[k]=Empty;
                            k=4;
                            }
                            u1=100;
                            u3=100;
                            u4=100;
                            i=100;
                        }
                        else if( area[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]]==user_Pokemons[k] && user_Pokemons[k]!=Empty && y2[artillegent[pokg]]+i<8){
                            u3=i;
                            pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]]=pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]]-attack_power[artillegent[pokg]];
                            if(pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]]<=0){
                         
                            area[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]]=Empty;
                            user_Pokemons[k]=Empty;
                            k=4;
                            }
                            u2=100;
                            u1=100;
                            u4=100;
                            i=100;
                        }
                        else if(area[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]]==user_Pokemons[k] && user_Pokemons[k]!=Empty && y2[artillegent[pokg]]-i>=0){
                            u4=i;
                            pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]]=pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]]-attack_power[artillegent[pokg]];
                            if(pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]]<=0){
                         
                            area[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]]=Empty;
                            pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]]=-1;
                            user_Pokemons[k]=Empty;
                            k=4;
                            }
                            u2=100;
                            u3=100;
                            u1=100;
                            i=100;

                        }
                        
                        
                           
                    }
                }
            }
            
   
            if(type[artillegent[pokg]]==quadratic){
            for(i=1;i<=range[artillegent[pokg]];i++){
                for(k=0;k<=3;k++){
                    if(area[y2[artillegent[pokg]]][x2[artillegent[pokg]]+i]==user_Pokemons[k] && user_Pokemons[k]!=Empty && x2[artillegent[pokg]]+i<8){
                        
                        pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]+i]=pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]+i]-attack_power[artillegent[pokg]];
                        if(pokemon_staminas[0][k]<=0){
                         
                         area[y2[artillegent[pokg]]][x2[artillegent[pokg]]+i]=Empty;
                         pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]+i]=-1; // 
                         user_Pokemons[k]=Empty;
                         k=4;
                        }
                    }
                    if(area[y2[artillegent[pokg]]][x2[artillegent[pokg]]-i]==user_Pokemons[k] && user_Pokemons[k]!=Empty && x2[artillegent[pokg]]-i>=0){
                        
                        pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]-i]=pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]-i]-attack_power[artillegent[pokg]];
                        if(pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]-i]<=0){
                         
                         area[y2[artillegent[pokg]]][x2[artillegent[pokg]]-i]=Empty;
                         pokemon_staminas[y2[artillegent[pokg]]][x2[artillegent[pokg]]-i]=-1;
                         user_Pokemons[k]=Empty;
                         k=4;
                         
                        }
                    }
                    if(area[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]]==user_Pokemons[k] && user_Pokemons[k]!=Empty && y2[artillegent[pokg]]+i<8){
                        
                        pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]]=pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]]-attack_power[artillegent[pokg]];
                        if(pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]]<=0){
                        
                         area[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]]=Empty;
                         pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]]=-1;
                         user_Pokemons[k]=Empty;
                         k=4;
                        }
                    }
                    if(area[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]]==user_Pokemons[k] && user_Pokemons[k]!=Empty && y2[artillegent[pokg]]-i>=0){
                           
                        pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]]=pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]]-attack_power[artillegent[pokg]];
                        if(pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]]<=0){
                         
                         area[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]]=Empty;
                         pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]]=-1;
                         user_Pokemons[k]=Empty;
                         k=4;
                        }
                    }
                    if(area[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]-i]==user_Pokemons[k] && user_Pokemons[k]!=Empty && y2[artillegent[pokg]]-i>=0 && x2[artillegent[pokg]]-i>=0){
                           
                        pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]-i]=pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]-i]-attack_power[artillegent[pokg]];
                        if(pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]-i]<=0){
                         
                         area[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]-i]=Empty;
                         pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]-i]=-1;
                         user_Pokemons[k]=Empty;
                         k=4;
                        }
                    }
                    if(area[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]-i]==user_Pokemons[k] && user_Pokemons[k]!=Empty && y2[artillegent[pokg]]+i<8 && x2[artillegent[pokg]]-i>=0){
                           
                        pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]-i]=pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]-i]-attack_power[artillegent[pokg]];
                        if(pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]-i]<=0){
                         
                         area[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]-i]=Empty;
                         pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]-i]=-1;
                         user_Pokemons[k]=Empty;
                         k=4;
                        }
                    }
                    if(area[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]+i]==user_Pokemons[k] && user_Pokemons[k]!=Empty && y2[artillegent[pokg]]+i<8 && x2[artillegent[pokg]]+i<8){
                           
                        pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]+i]=pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]+i]-attack_power[artillegent[pokg]];
                        if(pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]+i]<=0){
                         
                         area[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]+i]=Empty;
                         pokemon_staminas[y2[artillegent[pokg]]+i][x2[artillegent[pokg]]+i]=-1;
                         user_Pokemons[k]=Empty;
                         k=4;
                        }
                    }
                    if(area[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]+i]==user_Pokemons[k] && user_Pokemons[k]!=Empty && y2[artillegent[pokg]]-i>=0 && x2[artillegent[pokg]]+i<8){
                           
                        pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]+i]=pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]+i]-attack_power[artillegent[pokg]];
                        printf("d->%s pokemonu %s pokemonuna saldırdı yeni stamina -> %d\n",Pokemon_name[artillegent[pokg]],Pokemon_name[user_Pokemons[k]],pokemon_staminas[0][k]);
                        if(pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]+i]<=0){
                         
                         area[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]+i]=Empty;
                         pokemon_staminas[y2[artillegent[pokg]]-i][x2[artillegent[pokg]]+i]=-1;
                         user_Pokemons[k]=Empty;
                         k=4;
                        }
                    }
                 
                 
                    
                }
            }
            //printf("->stamina %d",pokemon_staminas[0][k]);
            show_area(Pokemon_name,area,pokemon_staminas);
        }













         	 for(i=0;i<4;i++){
        	printf("%d) %s     \n",i,Pokemon_name[artillegent[i]]);
        }
             ync++;
           
        }

        
       
    }
    if(check(user_Pokemons)==1){
        printf("user wins");
    }
    else{
        printf("computer wi");
    }
    printf("\n");
  
        


}
void the_main(){
    int choise=0;
    enum pokemon my_pocket[4]={Empty,Empty,Empty,Empty};
    char *pokemon_name[11]={"Char","Pik","Squ","Bul","Pid","Rat","Mug","Cat","Zub","Kra","Empty"};
    enum pokemon Pokemons[11]={Charmander,Pikachu,Squirtle,Bulbasaur,Pidgeotto,Ratata,Mug,Caterpie,Zubat,Krabby,Empty};
    int range[10]={1,3,4,3,2,2,1,2,3,2,};
    enum attack_type type[10]={quadratic,linear,linear,linear,quadratic,linear,quadratic,quadratic,linear,linear};
    int attack_powe[10]={500,350,300,400,250,250,350,200,350,300};
    int stamina[10]={2200,1500,1700,2500,1900,2500,3000,1200,1250,2600};
    srand(time(NULL));
    printf("1 ) Open Pokedex\n");
    printf("2 ) Go to Oak's Laboratory\n");
    printf("3 ) Enter the tournament\n");
    printf("4 ) Exit\n");
    printf("Choise : ");
    scanf("%d",&choise);
    while(choise!=4){
        switch(choise){
            case 1:
            pokedex(pokemon_name,range,type,attack_powe,stamina);
            break;
            case 2:
            oaks_laboratory(pokemon_name,Pokemons,my_pocket);
            break;
            case 3:
            battle(pokemon_name,range,type,attack_powe,stamina,my_pocket);
            break;
            case 4:
            break;
            default:
            printf("Error pls choise valid");
            break;
        }
        printf("1 ) Open Pokedex\n");
    printf("2 ) Go to Oak's Laboratory\n");
    printf("3 ) Enter the tournament\n");
    printf("4 ) Exit\n");
    printf("Choise : ");
    scanf("%d",&choise);
    }
}
int main()
{
    the_main();
    return 0;
}

