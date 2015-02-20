# allum1
{EPITECH} Multi-threaded Marienbad based Nim game. Humain vs IA ; IA vs IA ; Humain vs Humain.

# L'essenciel
    * Jeu des allumettes en mode texte, joli mais sans extra graphique.
    * IA Marienbad (tactique du XOR = 0).
    * IA qui implemente un algorithme pour calculer TOUS les
    mouvements parfaits possible pour un état de jeu donné. (cf. note sur IA)
    * Un valgrind impeccable.
    * Code propre, clair et optimisé au maximum (de mes compétences).

# Les bonus implémentés :
    * 4 niveaux de difficulté d'IA.
    * Map a taille variables (min = 3 piles).
    * Map a configuration variable (pyramidale ou aléatoire).
    * Mode Humain vs Humain.
    * Mode IA vs IA.
    * Implementation dumulti-threading avec pthread pour tirer meilleur
    parti du hardware lors des calculs d'IA.
    * Des statistiques sur la partie en fin de jeu.
    * Un mode triche pour les joueurs humain (affiche tous les coups
    menant à une situations gagnantes possibles).

# Note sur les IA :
    * Doom est programmé pour jouer parfaitement. Il ne PEUT PAS PERDRE,
    sauf si son adversaire joue parfaitement lui aussi et a commencé
    la partie en premier dans le cas d'une map avec un état initial
    non-gagnant (XOR != 0), ou inversement dans le cas contraire.
    * Doom calcule à chaque tours TOUTES les possibilités de jeu menant à
    une situation de victoire et joue toujours le mouvement le plus
    agressif, c-a-d celle qui retire le plus d'allumettes.
    * Les autres IA exécutent un jet de dès et suivant le résultat,
    exécutent soit une action parfaite, soit une action "random". A
    l'inverse de Doom, dans le cas d'un coup parfait, il n'y a pas de
    selection, première déterminée, permière joué.

# Note au lecteur :

N'hésitez pas à y aller avec les chiffres ! Le prog devrait pouvoir manger
une map d'un million d'allumettes en moins de 5 minutes :)

With love,
barrau_h.
