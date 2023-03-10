#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "entites.h"
#include "boutique.h"

//srand( time( NULL ) );

int rarete[9][5] = // stocke la probabilité de chaque tier de pokemon pour chaque niveau du joueur
{
  // {tier1, tier2, tier3, tier4, tier4, tier5}
  {100, 0, 0, 0, 0},    // lvl 1        indice => 0
  {100, 0, 0, 0, 0},    // lvl 2        indice => 1
  {70, 25, 5, 0, 0},    // lvl 3        indice => 2
  {50, 35, 15, 0, 0},   // lvl 4        indice => 3
  {35, 35, 25, 5, 0},   // lvl 5        indice => 4
  {25, 35, 30, 10, 0},  // lvl 6        indice => 5
  {20, 30, 33, 15, 2},  // lvl 7        indice => 6
  {15, 25, 35, 24, 6},  // lvl 8        indice => 7
  {10, 15, 30, 30, 15} // lvl 9         indice => 8
};



typedef struct boutique_s
{

  pokemon_t * deck[5];

} boutique_t;

/*pokemon_t * getRandomPokemon(int tier, pokemon_t * database)
{
  while(database)
  {
    pokemon_t * pokemon;

    pokemon_t = database;

    database++;
  }
}






  return NULL; // TODO
}
*/

void acheter(player_t * player, pokemon_t * pokemon)
{
  //player->team=player->team+pokemon;
  player->team++;
  player->team=pokemon;
}

void generate(player_t * player, pokemon_t * database)
{
  int level = (player->niveau); // recupere niveau du joueur
  int indice = level-1; // convertit le niveau du joueur en indice
  printf("indice : %i\n", indice);
  int drop = 0;

  for(int i = 0; i < 5; i++) // pour les 5 pokemons tiré dans la boutique
  {
    printf("\n  [[ POKEMON %i ]] \n", i+1);

    int tier = 4;

    while(tier > 0)
    {
      drop = rand() % 101; // on génére un nombre entre 0 et 100
      //printf("\ntier(%i) => %i% >= %i\n", tier+1, rarete[indice][tier], drop);
      if(rarete[indice][tier] > drop) //
      {
        //printf("     ^\n");
        break;
      }
      tier--;
    }

    printf("\n  ** TIER **  %i\n", tier+1);

    int pokeid = rand() % 1;

    //pokemon_t * poke = &(database[pokeid]);

    //printf("\n  || %s || \n", poke->name);




}



    /*while(drop >= rarete[indice][tier] && tier > 0)
    {generate
      if(!(drop >= rarete[indice][tier])) break;
      drop = rand() % 101;
      printf("Tier(%i): %i% | drop: %i \n", tier+1, rarete[indice][tier], drop);
      tier--;
    }
    printf("Tier(%i): %i% | drop: %i \n", tier+1, rarete[indice][tier], drop);


    printf("\n => drop tier(%i)\n", tier+1);*/
  }





  /*player_t player;
  player.level = 6;
  player.name = "sacha";

  // tier 1
  pokemon_t poke1_tier1;
  pokemon_t poke2_tier1;
  poke1_tier1.name = "poke1 tier1";
  poke1_tier1.rarete = 0;
  poke2_tier1.name = "poke2 tier1";
  poke2_tier1.rarete = 0;

  // tier 2
  pokemon_t poke1_tier2;
  pokemon_t poke2_tier2;
  poke1_tier2.name = "poke1 tier2";
  poke1_tier2.rarete = 1;
  poke2_tier2.name = "poke2 tier2";
  poke2_tier2.rarete = 1;

  // tier 3
  pokemon_t poke1_tier3;
  pokemon_t poke2_tier3;
  poke1_tier3.name = "poke1 tier3";
  poke1_tier3.rarete = 2;
  poke2_tier3.name = "poke2 tier3";
  poke2_tier3.rarete = 2;

  // tier 4
  pokemon_t poke1_tier4;
  pokemon_t poke2_tier4;
  poke1_tier4.name = "poke1 tier4";
  poke1_tier4.rarete = 3;
  poke2_tier4.name = "poke2 tier4";
  poke2_tier4.rarete = 3;

  // tier 5
  pokemon_t poke1_tier5;
  pokemon_t poke2_tier5;
  poke1_tier5.name = "poke1 tier5";
  poke1_tier5.rarete = 4;
  poke2_tier5.name = "poke2 tier5";
  poke2_tier5.rarete = 4;


  printf("Niveau joueur : %i\nNom joueur : %s\n", player.level, player.name);

  generate(&player);

}*/
