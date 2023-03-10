#include "commun.h"
#include "entites.h"

/*Initialisation des taille */
const int NbNiv1=6;
const int NbNiv2=5;
const int NbNiv3=4;
const int NbNiv4=3;
const int NbNiv5=2;


/*Permet d'assigner des valeurs par default dans la structure*/
void auto_fill_pkm_stats(pokemon_t* pokemon,int taille){
  int indRar;
  do{
    printf("Saisir rareté (gris = 1 , vert  = 2 , bleu = 3 , violet = 4 or = 5) ");scanf("%d",&indRar);
  }
  while (indRar < 0 || indRar > 5);
  for (int j = 0 ; j < taille ; j++){
    (pokemon+j)->pv=(pokemon+j)->pv_max;
    (pokemon+j)->range=1;
    (pokemon+j)->stade=1;
    (pokemon+j)->alive=0;
    (pokemon+j)->dresseur=0;
    (pokemon+j)->img=NULL;
    (pokemon+j)->x=0 , (pokemon+j)->y=0;
    (pokemon+j)->rarete=indRar;
  }
}

char* capitalize(char *str) {
    char* new_str = strdup(str);
    new_str[0] = toupper(new_str[0]);
    return new_str;
}

/*Permet de créer un tableau de N Pokémon avec les stats par défault*/
pokemon_t * createPkmDatabase(int taille){
  printf("taille %d\n",taille);
  char nomRecherche[52];
  char saisie[52];
  int i = 0 ;
  pokemon_t *tableau=malloc(sizeof(pokemon_t)*taille);        /* alloc taille tableau par rapport au nombre de Pokemon */
  FILE * ptrFich = fopen("data.csv","r"); 
  if (ptrFich == NULL) {
    perror("Erreur lors de l'ouverture du fichier");
  }
  while(i<taille){
    ptrFich = fopen("data.csv","r");
    printf("Saisir le nom du pokemon à rechercher : ");
    /*saisie nom pokemon*/
    fflush(stdin);
    fgets(saisie, sizeof(saisie), stdin);
    saisie[strcspn(saisie, "\n")] = '\0'; // Remplace '\n' par '\0'
    char *token = strtok(saisie, " "); // Divise la chaîne de caractères en plusieurs mots
    strcpy(nomRecherche, capitalize(token)); // Stocke le premier mot dans la variable nomRecherche
    while (token != NULL) {
        token = strtok(NULL, " "); // Récupère le mot suivant
        if (token != NULL) {
            strcat(nomRecherche, " ");
            strcat(nomRecherche, capitalize(token)); // Ajoute le mot suivant à la variable nomRecherche
        }
    }
                  /*recherche pokemon*/ 
    fscanf(ptrFich,"%d;%[^;];%[^;];%d;%d;%f;%f;%f;%f;%f;",&(tableau+i)->id,(tableau+i)->name,(tableau+i)->classe,&(tableau+i)->total,&(tableau+i)->pv_max,&(tableau+i)->att,&(tableau+i)->def,&(tableau+i)->attspe,&(tableau+i)->defspe,&(tableau+i)->spd);
    while((strcmp(nomRecherche, tableau[i].name) != 0) && (!feof(ptrFich)) ){       
      //printf("Recherche en cours : %s %s\n",nomRecherche,tableau[i].name); 
      fscanf(ptrFich,"%d;%[^;];%[^;];%d;%d;%f;%f;%f;%f;%f;",&(tableau+i)->id,(tableau+i)->name,(tableau+i)->classe,&(tableau+i)->total,&(tableau+i)->pv_max,&(tableau+i)->att,&(tableau+i)->def,&(tableau+i)->attspe,&(tableau+i)->defspe,&(tableau+i)->spd);
      //printf("Valeur de i  : %d\n",i);        
    }
    if(feof(ptrFich)){
      printf("Erreur lors de la saisie du nom du Pokémon, veuillez réésayer\n");
      i--;
    }
    i++;
    rewind(ptrFich);
  }
  fclose(ptrFich);
  auto_fill_pkm_stats(tableau,taille);

  system("cls");
  system("clear");
  printf("\a liste créé ! \n\n\n");
  sleep(1);
  return tableau;
}

void printPkm(pokemon_t pokemon){
  printf("Nom : %s (id:%d) \nType : %s\nTotal %d\n PV max %d\n PV %d\n Attaque %3.f\n Defense %3.f\n Attaque Speciale %3.f\n Defense Speciale %3.f\n Vitesse %3.f\n portee %d\n Rarete %d\n ",pokemon.name,pokemon.id,pokemon.classe,pokemon.total,pokemon.pv_max,pokemon.pv,pokemon.att,pokemon.def,pokemon.attspe,pokemon.defspe,pokemon.spd,pokemon.range,pokemon.rarete);
  printf("Ce Pokemon appartient a joueur %d\n", pokemon.dresseur);
  printf("Status : %d\n Stade d'évolution : %d\n",pokemon.alive,pokemon.stade);
  printf("Position actuelle :(%d,%d)\n", pokemon.x,pokemon.y);
  printf("\n");
}

void affichertableau(pokemon_t *tableau, int taille){
  // Vider le flux d'entrée
  while (getchar() != '\n');

  for (int i = 0 ; i < taille ; i++){
    printf("Pokemon numero %d\n ",i+1);
    printf("Nom : %s  ID :  %d \n",(tableau+i)->name,(tableau+i)->id);
    printf("\nAppuyez sur Entrée pour continuer...\n");
    getchar();
  }
}

void afficherEquipe(pokemon_t *equipe,int taille){
  //taille=sizeof((equipe)-1);
  for (int i = 0; i < taille; i++)
  {
    printPkm(equipe[i]);
  }
  
}

/* Copie les pokemon N fois selon le niveau de rarete */
void distribution(pokemon_t* base, pokemon_t* sortie, int taille){
  int copie;
  int index = 0;
  for(int i = 0; i < taille; i++) {
    switch (base[i].rarete)
    {
    case 1:
      copie = 29;
      break;

    case 2:
      copie = 22;
      break;

    case 3:
      copie = 16;
      break;

    case 4:
      copie = 12;
      break;

    case 5:
      copie = 10;
      break;

    default:
      perror("Pas de copie\n");
      copie=0;
      break;
    }
    printf("Copie du pokemon %d fois :", copie);
    for (int j = 0; j < copie; j++) {
      printf("%d ", index+j);
      sortie[index+j] = base[i];
    }
    printf("\n");
    index += copie;
  }
}


int main(){
  int tailleFinal=(NbNiv1*29)+(NbNiv2*29)+(NbNiv3*16)+(NbNiv4*12)+(NbNiv5*10);
  int NbNivTotal=(NbNiv1)+(NbNiv2)+(NbNiv3)+(NbNiv4)+(NbNiv5);

  /*initialisation statique du tableau final*/
  pokemon_t *database = malloc(sizeof(pokemon_t)*(NbNiv1*29)+(NbNiv2*22)+(NbNiv3*16)+(NbNiv4*12)+(NbNiv5*10));

  int tailleCpl=NbNiv1+NbNiv2+NbNiv3+NbNiv4+NbNiv5;

  pokemon_t *basetest = malloc(sizeof(pokemon_t) * tailleCpl);
  if (basetest == NULL) {
      fprintf(stderr, "Erreur d'allocation mémoire.\n");
      exit(EXIT_FAILURE);
  }

  // Création des tableaux par rapport au niveau
  pokemon_t *pkm1 = createPkmDatabase(NbNiv1);
  pokemon_t *pkm2 = createPkmDatabase(NbNiv2);
  pokemon_t *pkm3 = createPkmDatabase(NbNiv3);
  pokemon_t *pkm4 = createPkmDatabase(NbNiv4);
  pokemon_t *pkm5 = createPkmDatabase(NbNiv5);

  // Concaténation des tableaux
  memcpy(basetest, pkm1, sizeof(pokemon_t) * NbNiv1);
  memcpy(basetest + NbNiv1, pkm2, sizeof(pokemon_t) * NbNiv2);
  memcpy(basetest + NbNiv1 + NbNiv2, pkm3, sizeof(pokemon_t) * NbNiv3);
  memcpy(basetest + NbNiv1 + NbNiv2 + NbNiv3, pkm4, sizeof(pokemon_t) * NbNiv4);
  memcpy(basetest + NbNiv1 + NbNiv2 + NbNiv3 + NbNiv4, pkm5, sizeof(pokemon_t) * NbNiv5);

  // Libération de la mémoire allouée pour les tableaux créés par createPkmDatabase
  free(pkm1);
  free(pkm2);
  free(pkm3);
  free(pkm4);
  free(pkm5);

  affichertableau(basetest,NbNivTotal);  
  printf("Le code fonctionne correctement !\n");
  distribution(basetest,database,NbNivTotal);
  affichertableau(database,tailleFinal);
}