# 🚀 Recap : Checkout - More Functions, More Nested Loops

Bienvenue dans le résumé de notre session de live-coding ! Ce dossier contient les 4 fichiers clés que nous avons décortiqués ensemble. 

L'objectif de cette étape de votre apprentissage est clair : on arrête de coder au hasard, on dessine la logique avant de taper sur le clavier, et on respecte les règles strictes de notre environnement de compilation.

Voici un rappel de ce que contient chaque fichier :

## 1. La Logique d'Exclusion : `fizzbuzz.c`
Le test d'entretien par excellence. L'erreur classique est de tester les multiples de 3 ou de 5 en premier. 
* **La leçon :** Dans une chaîne `if / else if`, l'ordinateur s'arrête à la *première* condition vraie. Il faut **toujours** tester la condition la plus complexe et restrictive en premier (`i % 3 == 0 && i % 5 == 0`). Si vous ne le faites pas, le nombre 15 affichera "FIZZ" au lieu de "FizzBuzz".

## 2. Le Dessin Vectoriel et les Coordonnées : `print_triangle.c`
Comment dessiner un triangle aligné à droite ? En découpant le problème mathématiquement en lignes (row) et en colonnes (col).
* **La leçon :** Une boucle externe gère les retours à la ligne. À l'intérieur, on utilise **deux boucles successives** :
  1. La première imprime les espaces de remplissage : `size - row`.
  2. La seconde imprime les symboles `#` : `row`.
Ne codez jamais un dessin géométrique sans l'avoir d'abord gribouillé sur un bout de papier avec une grille (X, Y) !

## 3. Le Piège du Standard C89 : `stdgnu.c`
Si vous compilez ce fichier avec nos drapeaux habituels (`gcc -Wall -Werror -Wextra -pedantic -std=gnu89`), il va crasher lamentablement. 
* **La leçon :** En C89, **toutes les déclarations de variables doivent se faire au tout début d'un bloc**, avant la moindre instruction. Dans ce fichier, déclarer `int j = 0;` *après* avoir exécuté `i++;` déclenche l'erreur fatale `ISO C90 forbids mixed declarations and code`. 
* *Bonus bug :* Avez-vous remarqué le `;` à la fin de `while (j < 10);` ? C'est une boucle infinie silencieuse ! Le point-virgule agit comme une instruction vide. 

## 4. L'Architecture et le Contrat : `main.h`
Fini le code monolithique. Vos fonctions sont désormais réparties dans plusieurs fichiers `.c`.
* **La leçon :** Le fichier `.h` (header) est le contrat qui permet à vos fichiers de se connaître entre eux grâce aux **prototypes** de fonctions. 
* N'oubliez jamais les **Include Guards** (`#ifndef MAIN_H`, `#define MAIN_H`, `#endif`) pour éviter que le compilateur n'inclue le fichier plusieurs fois et ne crée une boucle infinie lors de la compilation.

---
💡 **Rappel :** Passez toujours un coup de Betty avant de faire un `git push`, et utilisez Python Tutor si vos boucles imbriquées font des choses étranges !