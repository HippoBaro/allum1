/*
** alum1.h for alum1 in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Sun Feb 15 23:41:09 2015 Hippolyte Barraud
** Last update Thu Feb 19 17:07:52 2015 Hippolyte Barraud
*/

#ifndef ALUM1_H_
# define ALUM1_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

# define RED	       		"\033[1;31m"
# define GREEN	       		"\033[1;32m"
# define CYAN	       		"\033[1;36m"
# define BLUE	       		"\033[1;34m"
# define YELLOW	       		"\033[1;33m"
# define BLANK	       		"\033[0m"

# define TRUE		       	1
# define FALSE		       	0
# define EQUAL		       	0
# define ERROR		       	-1
# define SUCCESS	       	0

# define DIF_EASY	       	10
# define DIF_MEDIUM	       	40
# define DIF_HARD      		70
# define ENABLE_THREADING	TRUE
# define THREAD_GRANULARITY	50
# define BUFF		       	512

# define ERROR_MALLOC		"Erreur lors d'une allocation mémoire.\n"
# define ERROR_SYSTEM_CALL	"Erreur lors d'un appel système.\n"
# define ERROR_INPUT		"Votre entrée n'est pas valide.\n"
# define ERROR_INVALID_LINE	"Merci d'indiquer un numéro de pile valide.\n"
# define ERROR_INVALID_COUNT	"Ce n'est pas possible.\n"
# define ERROR_FATAL		"Erreur critique.\n"
# define ERROR_HEAP_LIMIT	"Veuillez entrer une limite supérieure à 4.\n"
# define ERROR_HEAP_COUNT	"Veuillez entrer une taille supérieure à 2.\n"
# define ERROR_MAP_TYPE		"Veuillez entrer un type de plateau valide.\n"
# define ERROR_DIFICULTY	"Veuillez entrer une difficulté valide.\n"
# define ERROR_PLAYER_TYPE	"Veuillez entrer un type de joueur valide.\n"
# define ERROR_THREAD_JOIN	"Erreur critique lors du rappel de thread.\n"
# define ERROR_THREAD_CREATE	"Erreur critique lors de la création d'un \
thread.\n"

# define SPEEDUP_BATTLE		"\n\nVous allez voir s'affronter deux IA l'un\
e contre l'autre.\nDans le cas de bataille à grande échelle (plateau immense\
) il peut être avantageux de désactiver l'affichage du plateau et de ne pas \
attendre artificiellement l'IA à chaque tours.\n" YELLOW "Cela aura pour effe\
t de rendre l'affrontement plus rapide. Voulez-vous le faire ? (oui/non) : "\
 BLANK
# define STATS_IA	       	"\nSur" YELLOW " %d " BLANK "situations de j\
eu analysés par le moteur d'IA," YELLOW " %d " BLANK "options de jeu \
menant à une situation de victoire ont été résolus, soit en moyenne"\
YELLOW " %d " BLANK "par situation analysée.\n" SEPARATOR
# define NO_STATS_IA		"Aucune situation de jeu n'a été analysé par \
le moteur d'IA.\n"
# define AI_STATS	       	YELLOW "%s" BLANK " : Sur " YELLOW "%d" BLAN\
K " coup éxécutés, " YELLOW "%d" BLANK " étaient des coups parfaits, soit\
 environ " YELLOW "%d%%" BLANK ".\n"
# define GAME_STATS_TITLE	"Statistiques de la partie : \n\n" SEPARATOR
# define GAME_STATS	       	"La partie s'est déroulé sur" YELLOW \
" %d " BLANK "tours en tous et" YELLOW " %d " BLANK "allumettes ont \
été retirées.\n" BLANK "%s"
# define PLAYER_STATS		YELLOW "%s" BLANK " : à éxécuté " YELLOW \
"%d" BLANK " coup en tous.\n"
# define GAME_TIME		 "La partie a duré" YELLOW " %d "BLANK\
"secondes.\n\n"
# define CHEATER       		" [Tricheur !]"
# define END_GAME      		"Fin de la partie !"
# define GAME_WON      		"\n%s a gagné la partie !\n\n"
# define PROMPT_QUIT		"\nAppuyer sur ENTRER pour quitter..."
# define MOVE_OPTION		"Option de mouvement : pile %3d - enelver %3d\
 allumette(s).\n"
# define NO_MOVE       		"Aucun coup parfait possible ! Croisez les doi\
gts pour que votre adversaire face une erreur !\n"
# define GAME_SUMUP    		"Résumé de la partie : "
# define THINKING      		"Je réfléchis...\n"
# define MOVE_LINE	       	"De quelle pile enlever des allumettes ? : "
# define MOVE_COUNT	       	"Combien d'allumettes enlever ? : "
# define LAST_MOVE	       	"Dernière action du tour %d : %s a enlevé \
%d allumette(s) de la pile %d.\n\n"
# define TURN_PROMPT		"Tour numéro %d. C'est au tour de %s de jouer"
# define HEAP_LIMIT    		"Entrez une limite par pile : "
# define HEAP_COUNT	       	"Combien de piles voulez-vous ? : "
# define MAP_TYPE		"Type de plateau (Pyramidal/Aléatoire) : "
# define GAME_CONFIG		"Configuration du plateau de jeu : "
# define PROMPT_DIFICULTY	"Difficulté (easy/medium/hard/doom) : "
# define PROMPT_CHEAT		"Activer les indices ? (triche) (oui/non) : "
# define PLAYER_CONFIG		"Configuration des joueurs"
# define PLAYER_TYPE		"Type de joueur (Humain/IA) : "
# define PLAYER_NAME		"Nom du joueur : "
# define YES			"oui"
# define NO			"non"
# define PROMPT_COMFIRM 	"Cela vous convient-il ? (oui/non) : "
# define NOTE_DOOM		"\nNote : Toutes les IA autres que DOOM sont \
limités au calcul d'un seul mouvement parfait par tours. Seul DOOM est \
capable de toutes les évaluer pour choisir la plus agressive.\nCes statist\
iques sont donc à interpréter selon cette information.\n"
# define PROMPT_BEGIN		"Appuyez sur ENTRER pour lancer une \
nouvelle partie..."
# define THREAD_STATS 		"\n" SEPARATOR "Fils d'éxécution concurr\
ents : " YELLOW "%d" BLANK "\nTotal des fils créés : " YELLOW "%d" BLANK\
"\n" SEPARATOR

# define SEPARATOR		"-------------------------------------\
---\n"
# define HEADER_SEP		"*************************************\
*******************************************\n"

# define WELCOME_TITLE		"**************************************\
***********************************\n*****██╗███████╗██╗***██╗****██████╗*\
███████╗****███╗***██╗██╗███╗***███╗\n*****██║██╔════╝██║***██║****██╔\
══██╗██╔════╝****████╗**██║██║████╗*████║\n*****██║█████╗**██║***██║**\
**██║**██║█████╗******██╔██╗*██║██║██╔████╔██║\n██***██║██╔══╝**██║***\
██║****██║**██║██╔══╝******██║╚██╗██║██║██║╚██╔╝██║\n╚█████╔╝███████╗╚\
██████╔╝****██████╔╝███████╗****██║*╚████║██║██║*╚═╝*██║\n*╚════╝*╚═══\
═══╝*╚═════╝*****╚═════╝*╚══════╝****╚═╝**╚═══╝╚═╝╚═╝*****╚═╝\n*******\
******************************************************************\n\
Made by ArrenKae with love (barrau_h).\n\n"
# define WELCOME_MESSAGE	"Bienvenue dans le simulateur du Jeu \
de Nim.\n\n" HEADER_SEP "\nRègles :\n\n\t● Ce jeu se joue sur un platea\
u de n piles, contenant un nombre fini\n\t  d'éléments.\n\t● Le jeu se \
joue à deux au tour par tour.\n\t● A chaque tour, les joueurs enlèven\
t au moins un élément d'une seule\n\t  et même pile, sans limite.\n\t" \
RED "● Le joueur qui enlève le dernier élément du plateau perd la \
partie." BLANK "\n\n" HEADER_SEP "\nCe programme permet de jouer \
dans les configurations suivantes :\n\n\t● Humain VS Humain\n\t● \
Humain VS IA\n\t● IA     VS IA\n\n" HEADER_SEP "\nL'ordinateur \
possède quatre niveaux de difficulté :\n\n\t" GREEN "● \
Facile :    10 % de chance d'éxécuter un coup parfait." BLANK \
"\n\t" BLUE "● Normal :    40 % de chance d'éxécuter un coup \
parfait." BLANK "\n\t" YELLOW "● Difficile : 70 % de chance d'éxécuter \
un coup parfait." BLANK "\n\t" RED "● Doom :      «Je peux perdre, \
mais je gagne toujours...»" BLANK "\n\nNote : un coup parfait \
est un coup menant à une situation gagante.\n\n" HEADER_SEP

typedef unsigned char		bool;
typedef char			*string;

typedef enum { COMPUTER, HUMAN }		e_player_type;
typedef enum { PYRAMID, RANDOM }		e_map_type;
typedef enum { J1, J2 }				e_player_order;
typedef enum { NONE, EASY, MEDIUM, HARD, DOOM }	e_difficulty;
typedef enum { STARTED, FINISHED }		e_game_state;

typedef struct		s_moves
{
  int			line;
  int			count;
  struct s_moves	*next;
  struct s_moves	*prec;
}			t_moves;

typedef struct		s_player
{
  e_player_type		type;
  e_difficulty		difficulty;
  string		name;
  e_player_order	order;
  bool			hints;
  int			tot_moves;
  int			perfect_moves;
}			t_player;

typedef struct		s_ia_data
{
  int			cnthgh;
  float			cntone;
  int			k;
  int			l;
  int			m;
  int			sfck;
}			t_ia_data;

typedef struct		s_map_request
{
  e_map_type		type;
  int			heap_nb;
  int			max_per_heap;
}		       	t_map_request;

typedef struct		s_map
{
  int			levelcount;
  int			*levels;
  int			tot_elem;
  t_map_request		request;
  int			gauss_resolved;
  int			gaus_pass;
  bool			display_map;
  int			concurrent_job;
  int			total_thread;
}			t_map;

typedef struct		s_action
{
  int			target_line;
  int			minus_value;
}			t_action;

typedef struct		s_game
{
  t_map			*map;
  t_player		*p1;
  t_player		*p2;
  t_player		*winner;
  e_game_state		state;
  int			wait_ia;
  int			turn;
  char			last_move[BUFF];
  int			elem_removed;
  time_t		start_time;
}			t_game;

typedef struct		s_moves_query
{
  int			from_heap;
  int			to_heap;
  t_map			*map;
}			t_moves_query;

typedef struct		t_thread_query
{
  t_moves_query		*queries;
  pthread_t		*tids;
  void			**statuses;
  t_moves		*moves;
  int			threadcount;
  int			levelcount;
}		       	t_thread_query;

/*
** thread.c
*/
t_moves		*get_moves_threaded(t_map *map);

/*
 ** IA.c
 */
bool		do_perfect_move(t_player *player);
t_action	try_perfect_move (t_game *game, t_player *player);
t_action	random_action(t_game *game);
int		rand_MimMax(int Min, int Max);

/*
 ** list.c
 */
void		free_list(t_moves *list);
void		add_node(t_moves **list, int line, int count, t_map *map);
t_moves		*create_list(void);
void		display_list(t_moves *lst);
t_moves		*merge_list(t_moves **lst, int lstcount);

/*
 ** rules.c
 */
bool		is_valid_lign(int lign, t_game *game);
bool		is_valid_count(int lign, int count, t_game *game);
bool		test_game_winner(t_game *game);
int		test_lastmove(t_game *game);

/*
 ** gauss_resolve.c
 */
bool		is_map_safe(t_map *map);
void		*get_moves(void *req);
void		*get_moves2(void *req);
t_moves		*get_moves_threaded(t_map *map);

/*
 ** gameplay.c
 */
void		play(t_game *game);
void		init_action(t_action *action);

/*
 ** new_game.c
 */
t_game		*init_game(void);

/*
 ** player_utils.c
 */
string		get_player_name(t_player *player);
void		sumup_player(t_player *player);
string		get_player_stat(t_player *player);

/*
 ** new_player.c
 */
t_player	*new_player(e_player_order order);
void		set_players(t_game *game);

/*
 ** stroutput.c
 */
void		print_colored(const string str, const string color);
void		printtxt(const string str);

/*
 ** strinput.c
 */
string		prompt_input(const string prompt, const string color);

/*
 ** errors.c
 */
void		print_error(const string error, const bool isCritical);
void		*xmalloc(const size_t size);
void		free_game(t_game *game);
void		free_map(t_map *map);

/*
 ** map_generator.c
 */
t_map		*generate_map(const t_map_request *req);

/*
 ** map_prompt.c
 */
t_map		*new_map(void);

/*
 ** map_utils.c
 */
void		sumup_map(t_map *map);
void		display_map(const t_map *map, const bool line_count);

/*
 ** menu.c
 */
void		display_endscreen(const t_game *game);
void		clear_screen(const string title);
void		display_welcomescreen(void);

#endif /* ALUM1_H_ */
