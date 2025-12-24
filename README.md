# Push Swap

## Description

Push Swap est un projet algorithmique qui a pour objectif de trier une liste de nombres entiers en utilisant un ensemble restreint d’opérations sur des piles. Le but est de trouver le tri le plus efficace (utilisant le moins d’opérations possible) en respectant les contraintes imposées.

Ce projet a été réalisé dans le cadre de l’apprentissage de la gestion de mémoire, des algorithmes et de l’optimisation en C.

## Fonctionnalités

- Trie une pile d’entiers de manière optimisée.
- Prend en charge les opérations autorisées : `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.
- Gestion des erreurs et des entrées invalides.

## Installation

Clonez le dépôt :
```sh
git clone https://github.com/gchinaul/Push_Swap.git
cd Push_Swap
```

Compilez le projet :
```sh
make
```

## Utilisation

Exécutez le programme avec une liste d’entiers à trier :
```sh
./push_swap 4 67 3 87 23
```

Le programme affichera la liste des opérations à exécuter pour trier la pile.

./test.sh pour tester le projet

## Exemples

```sh
./push_swap 3 2 1
sa
rra
```

## Auteur

- [gchinaul](https://github.com/gchinaul)

## Licence

Ce projet est sous licence MIT. Vous pouvez consulter le fichier LICENSE pour plus d’informations.
