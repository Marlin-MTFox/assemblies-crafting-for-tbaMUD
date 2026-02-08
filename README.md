# assemblies-crafting-for-tbaMUD
Added crafting stuff to the original assemblies (c) gdavis. plants, trees, mineshafts with ores, fishing

make a backup before trying to install this. then backup that backup.

if you have modified your mud already, it is probably best to hand patch, otherwise
drop in the tbaMud-master folder
type patch < assembliescraft.patch in the shell
should all be good.

Seeds will need the action description to show to room, say you have a birch seed, the action descrition should be birch tree, melon seed. melon crop
min level works on some of it, 1 - 100, it works on crafting level, not player level
fill in the 4 values

define some wood shavings in assemblies.h. I used shavings to make parchment for scrolls, set the item flag as item_wood to get shavings when carved.

ores just use the name, so like a lump of iron ore. lump of coal

any item named anvil or forge will work with smelt and smith

fish are defined as type, so cant be food. I thought one could add in cooking to make them into food

ores, seeds, and fish are added in through oedit. be sure to fill in the 4 values

setup some mineshafts, the exits will reset on a sector mineshaft room, so no neeed to make any. once you create some ores they should self populate.

oedit some tools to work with, add them in to the crafting syatem. tools wind up on a toolbelt, and any other values will not count, like trying to add hitroll to them.

create a craft/pawn shop, define a keeper for the craft shop in spec_assign.c    SPECIAL(objbank_buyer), prices will flucuate depending on supply and demand.

hope that covers it.. enjoy.




