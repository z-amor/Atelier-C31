#include <stdio.h>

/* 
 * ACTE 1 : Le piège du débutant (Passage par valeur)
 * Le C crée une photocopie de la variable 'hp'. 
 * On blesse la copie, mais le vrai joueur dans le main n'a rien senti.
 */
void trap_illusion(int hp) {
    hp = hp - 20;
    printf("Le piège se referme! HP du clone actuel = %d \n", hp);
}

/* 
 * ACTE 1 : Le vrai piège (Passage par adresse)
 * On reçoit l'adresse mémoire du joueur (int *hp_adresse).
 * Avec l'étoile (*), on va physiquement modifier la vraie case mémoire.
 */
void trap_real(int *hp_adresse) {
    *hp_adresse = *hp_adresse - 20;
    printf("Dégats réels infligés!\n");
}

/* 
 * ACTE 3 : La porte magique (Vérification de palindrome)
 * Utilisation de deux pointeurs qui avancent l'un vers l'autre.
 */
int unlock_door(char *password)
{
    char *gauche = password; /* Pointeur sur le début du mot */
    char *droite = password; /* Pointeur qui va chercher la fin du mot */

    /* Etape 1: trouver la fin du mot (l'agent secret '\0') */
    while (*droite != '\0')
    {
        droite++; /* On avance case par case */
    }
    droite--; /* On recule d'une case pour être sur la dernière lettre (avant le \0) */

    /* Etape 2: La vérification du palindrome par adresses croisées */
    while (gauche < droite) /* Magie : on compare les ADRESSES physiques ! */
    {
        if(*gauche != *droite) /* On compare les valeurs (les lettres) */
        {
            return (0); /* Ce n'est pas un palindrome */
        }
        gauche++; /* Le pointeur gauche avance vers la droite */
        droite--; /* Le pointeur droit recule vers la gauche */
    }
    return (1); /* Les pointeurs se sont croisés sans erreur */
}

/* 
 * ACTE 4 : La purification de l'épée (Modification in-place)
 * On remplace une lettre directement dans la mémoire vive.
 */
void purify_weapon(char *weapon)
{
    while (*weapon != '\0')
    {
        if (*weapon == 'x')
        {
            *weapon = '*'; /* Écrasement en direct dans la RAM */
        }
        weapon++; /* On passe à la lettre suivante */
    }
}

int main(void)
{
    int player_hp = 100; 
    
    /* ACTE 2 & 4 : Différence majeure !
     * hero_name[] et sword[] créent un tableau modifiable en mémoire vive.
     * Si on avait écrit char *sword = "...", l'épée serait en Read-Only -> Segfault !
     */
    char hero_name[] = "Arthur";
    char *ptr = hero_name; /* Un pointeur qui pointe sur la 1ère case de hero_name */
    
    char spell1[] = "fireball";
    char spell2[] = "kayak";
    char sword[] = "Excalibuxxxxxxx";

    printf("--- Acte 1: Le Piège ---\n");
    printf("Le héros entre dans le donjon avec %d HP.\n", player_hp);

    /* On donne juste la valeur (photocopie) */
    trap_illusion(player_hp);
    printf("Après le piège illusoire, le héros a %d HP.\n", player_hp);
    
    /* On donne l'adresse avec & (les clés de la maison) */
    trap_real(&player_hp);
    printf("Le héros regarde sa vraie blessure... HP = %d.\n\n", player_hp);

    printf("--- Acte 2: Le Prénom ---\n");
    /* Preuve que tableau et pointeur se manipulent pareil pour la lecture */
    printf("1. Troisième lettre (tableau) : %c\n", hero_name[2]);
    printf("2. Troisième lettre (pointeur) : %c\n\n", *(ptr + 2)); /* Arithmétique ! */

    printf("--- Acte 3: La porte magique ---\n");
    if (unlock_door(spell1))
        printf("Le sort '%s' ouvre la porte! \n", spell1);
    else
        printf("Le sort '%s' a échoué! \n", spell1);

    if (unlock_door(spell2))
        printf("Le sort '%s' ouvre la porte! \n\n", spell2);
    else
        printf("Le sort '%s' a échoué! \n\n", spell2);

    printf("--- Acte 4: La purification de l'épée ---\n");
    printf("Arme trouvée: '%s'\n", sword);
    /* On envoie l'adresse de la 1ère case de l'épée */
    purify_weapon(sword);
    printf("Arme purifiée: '%s'\n", sword);

    return (0);
}