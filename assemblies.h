/* ******************************************************************** *
 * FILE	: assemblies.h			Copyright (C) 1999 Geoff Davis	*
 * USAGE: Definitions, constants and prototypes for assembly engine.	*
 * -------------------------------------------------------------------- *
 * 1999 MAY 07	gdavis/azrael@laker.net	Initial implementation.		*
 * ******************************************************************** */

#if !defined( __ASSEMBLIES_H__ )
#define __ASSEMBLIES_H__

/* items that will need defined by vnum in game

   low number fish, and high number fish. Make sure you got
   all the fish inbetween these too, also must have at least 10
   of each kind, saltwater, freshwater fishes.  00-09 */
#define SHAVINGS 30419  /** I use shavings to craft paper **/


/* ******************************************************************** *
 * Type aliases.							*
 * ******************************************************************** */

typedef struct assembly_data	ASSEMBLY;
typedef struct component_data	COMPONENT;

/* ******************************************************************** *
 * Structure definitions.						*
 * ******************************************************************** */

/* Assembly structure definition. */
struct assembly_data {
  obj_vnum		lVnum;			/* Vnum of the object assembled. */
  obj_vnum		lNumComponents;		/* Number of components. */
  int		level_to_make;
  int		exp_given;
  int       how_many;
  int       tool_type;
  unsigned char	uchAssemblyType;	/* Type of assembly (ASSM_xxx). */
  struct component_data *pComponents;		/* Array of component info. */
};

/* Assembly component structure definition. */
struct component_data {
  bool		bExtract;		/* Extract the object after use. */
  bool		bInRoom;		/* Component in room, not inven. */
  obj_vnum		lVnum;			/* Vnum of the component object. */
  int       chow_many;  
};

/* ******************************************************************** *
 * Prototypes for assemblies.c.						*
 * ******************************************************************** */

void		assemblyBootAssemblies( void );
void		assemblySaveAssemblies( void );
void 		assemblyComponentList(obj_vnum lVnum, struct char_data *pCharacter);
void		assemblyListToChar( struct char_data *pCharacter );
void		assemblyListToMort(struct char_data *pCharacter, int type);
void        add_crafting_exp(struct char_data *ch, int exp, int type);

bool		assemblyAddComponent( obj_vnum lVnum, obj_vnum lComponentVnum,
		  bool bExtract, bool bInRoom, int how_many );
bool		assemblyCheckComponents( obj_vnum lVnum, struct char_data
		  *pCharacter );
bool		assemblyCheckLevel( obj_vnum lVnum, struct char_data
		  *pCharacter );
bool		assemblyCreate( obj_vnum lVnum, int iAssembledType, int lvl, int exp, int ihow_many, int tool_type );
bool		assemblyDestroy( obj_vnum lVnum );
bool		assemblyHasComponent( obj_vnum lVnum, obj_vnum lComponentVnum );
bool		assemblyRemoveComponent( obj_vnum lVnum, obj_vnum lComponentVnum );

int		assemblyGetType( obj_vnum lVnum );
int     assemblyGetExp( obj_vnum lVnum );

long 	assemblyCountComponents( obj_vnum lVnum );
long	assemblyFindAssembly( const char *pszAssemblyName, int subcmd);
long		assemblyGetAssemblyIndex( obj_vnum lVnum );
long		assemblyGetComponentIndex( ASSEMBLY *pAssembly,
		  obj_vnum lComponentVnum );
		  
int assemblyGetHowmany( obj_vnum lVnum );		  

ASSEMBLY*	assemblyGetAssemblyPtr( obj_vnum lVnum );

/* ******************************************************************** */

/* * do_assemble * These constants *must* corespond with
     const char *AssemblyTypes[] =  in constants.c  */
#define SCMD_CRAFT      0
#define SCMD_SCRIBE		1
#define SCMD_MIX		2
#define SCMD_CARVE		3
#define SCMD_SMITH		4
#define SCMD_SMELT		5
#define MAX_ASSM		6	// Number of assembly types.

/* Public Procedures from act.crafting.c */
void free_assemblies(void);
extern char *plant_name(int seednum);
extern int rf_harvest(int seednum, int val3);
extern void reset_mineshafts();
extern void update_actions(void);
extern void save_objbank();
extern void update_room_vals();
extern void load_room_vals();
extern void save_room_vals();
ACMD(do_smelt);
ACMD(do_plant);
ACMD(do_chop);
ACMD(do_harvest);
ACMD(do_mine);
ACMD(do_castout);
ACMD(do_reelin);
ACMD(do_rval);
#endif


