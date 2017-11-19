/*  @Project: IFJ17
    @author: xgrofc00@stud.fit.vutbr.cz
    @author: xkrajc17@stud.fit.vutbr.cz
    @author: xfujac00@stud.fit.vutbr.cz
    @author: xpobis00@stud.fit.vutbr.cz
*/

#include<stdio.h>
#include<stdlib.h>
#include"str.h"
#include"error.h"

#define true 1
#define false 0

#define TYPE_INT (1012)
#define TYPE_DOUBLE (1005)
#define TYPE_STRING (1018)
#define ID (4)






/*typedef union{
		int type;
		char *value;
} tData;*/



typedef struct tSymbol TSymbol, *PSymbol;

typedef struct tSymtab TSymtab, *PSymtab;

/*  Typ symbol ( prvok tabulky symbolov ) */
struct tSymbol {	// prvok tabulky symbolov
	char name[256];	//nazov zaroven kluc
	int type;
	char *value;
	PSymbol LPtr;
	PSymbol RPtr;
};

/* Samotna tabulka symbolov, binarny strom */
struct tSymtab{
	PSymbol Root;	// tabulka symbolov, obsahuje len ukazatel na koren
};

PSymtab STcreate();
PSymbol STinsert_fun(PSymbol *, int, char *, char *);
int STinsert(PSymtab , int, char *, char *);
void STdestroy(PSymtab);
PSymbol STsearch(PSymbol, char *);
void destroy_symbols(PSymbol);


typedef struct listItem {
  PSymbol item;
  struct listItem *next;
} *tList_item;

typedef struct L_list {
  struct listItem *first;
  struct listItem *last;
  struct listItem *active;
} *tList;



typedef struct main_nod main_nod, *Pmain_nod;
typedef struct main_table main_table, *Pmain_table;

struct main_nod{
	char name[256];
	int type;
	tList list;
	PSymtab func_tree;
	Pmain_nod LPtr;
	Pmain_nod RPtr;
};
struct main_table{
	Pmain_nod Root;	// tabulka symbolov, obsahuje len ukazatel na koren
};



Pmain_table Table_create();
int insert_token(Pmain_table table, int type, char *name, char *value, char *fname, tList list);
Pmain_nod insert_token_recursive(Pmain_nod *parent, int type, char *name, char *value, char *fname);
Pmain_nod search_func(Pmain_nod root, char *name);
int search_PATO(Pmain_table table, char *name, char *fname);
int compare_whole_list(Pmain_table table, char *fname, tList list);
int printf_tree(Pmain_nod nod);

tList Listinit();
void Insert(tList L, int type, char *name);
void print_list(tList L);
int compare_2_lists(tList_item L_item, tList_item L2_item);
int compare_list_type(Pmain_table table, char *fname, tList list);

void destroy_all(Pmain_nod root);
void destroy(Pmain_table table);
int compare_2_lists_whole(tList_item L_item, tList_item L2_item);
int search_PEPO(Pmain_table table,char *name,char *fname);
int search_func_type(Pmain_table table, char *fname);
int search_prem_type(Pmain_table table, char* name,char *fname);