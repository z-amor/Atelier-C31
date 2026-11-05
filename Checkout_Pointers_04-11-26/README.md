# 🐉 Le RPG de la Mémoire (Pointeurs, Tableaux & Strings)

Ce dossier contient l'aventure codée lors du check-out. Refaites-la à votre rythme ! Chaque "Acte" illustre une mécanique fondamentale de la mémoire en C.

## Acte 1 : La Photocopie vs Les Clés (Passage par valeur vs adresse)
* **Le problème (`trap_illusion`) :** Quand on passe `player_hp` à la fonction, le C crée une **photocopie**. Le piège blesse la copie, mais le vrai joueur n'a rien.
* **La solution (`trap_real`) :** L'opérateur `&` (ex: `&player_hp`) donne **l'adresse mémoire** du joueur (les clés de la maison). La fonction utilise l'étoile `*` pour ouvrir la porte et modifier la vraie valeur.

## Acte 2 : Le Mensonge des Textes (Tableaux vs Pointeurs)
* Les chaînes de caractères n'existent pas : ce sont des tableaux de `char`.
* Un tableau est juste un pointeur "fixe" sur la première case. 
* Écrire `hero_name[2]` ou `*(ptr + 2)`, c'est la **même chose** : "Prends l'adresse de départ, avance de 2 cases, et donne-moi la valeur". C'est l'arithmétique de pointeur.

## Acte 3 : La Magie du `\0` et des Adresses (Le Palindrome)
Pour savoir où s'arrête un texte, le C utilise un agent secret : le Null Byte (`\0`).
Dans `unlock_door`, on utilise deux pointeurs (`gauche` et `droite`). 
* La condition magique `while (gauche < droite)` compare des **adresses physiques** : on boucle tant que l'adresse de gauche est stockée avant l'adresse de droite dans la barrette de RAM !

## Acte 4 : La Modification in-place et le piège du Segfault
* La fonction `purify_weapon` écrase les `'x'` directement dans la RAM.
* **Le Piège mortel :** Si dans le `main`, vous aviez déclaré l'épée avec `char *sword = "Excalibuxxx";` au lieu de `char sword[] = "..."`, le compilateur aurait stocké le mot dans la mémoire morte (Read-Only). Essayer de modifier une mémoire morte provoque immédiatement un **Segmentation Fault** (le crash). Les crochets `[]` vous garantissent une zone modifiable dans la RAM vivante.
