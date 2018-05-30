#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED
namespace bl
{
enum type
{
air,
dirt,
grass,
stone,
plants,
sand,
sand_ruby,
sandstone,
woodenplank,
stonebricks,
clay,
wood,
leafs,
copper,
iron,
gold,
copperblock,
ironblock,
goldblock,
bricks,
snowblock,
iceblock,
rubbyblock,
platform,
workbench,
glass,
furnace,
painting,
sappling,
snow_gem,
ice_gem_block,
wodden_door,
bottle,
table,
wardrobe,
book_shelf,
ice_bricks,
ice_table,
ice_wardrobe,
ice_book_shelf,
ice_platform,
sand_table,
sand_wardrobe,
sand_book_shelf,
sand_platform,
chest,
ice_chest,
sand_chest,
dungeon_chest,
dungeon_block,
dungeon_table,
dungeon_wordrobe,
dungeon_bookshelf,
dungeon_platform,
dirt_wall,
stone_wall,
wodden_wall,
sandstone_wall,
brick_wall,
glass_wall,
copper_wall,
iron_wall,
gold_wall,
snow_wall,
sand_wall,
stonebricks_wall,
rubby_wall,
heroglyphics,
ice_gem_wall,
wodden_stone_wall,
ice_brick_wall,
dungeon_wall,
last_block
};

enum varation
{
fragile,
blocy,
nocollision,
platform_family,
door,
nonstackeble,
chestfamily

};
enum tree
{
normalwood,
woodrlleaves,
woodrleaves,
woodlleaves,
woodground,
woodupperleafs,
woodcut,
woodcutdown
};


}
namespace et
{
    enum {
slime,
green_slime,
speedy_green_slime,
blue_slime,
speedy_blue_slime,
sand_slime,
speedy_sand_slime,
ice_slime,
speedy_ice_slime,
small_blue_slime,
normal_zombie
    };

};
enum inventory_sprites
{
    blue,
    trash_sprtie,
    backpack,
    sword_hammer,
    grey,
    grey_border,
    arrow,
    equals,
    cross,
    furniture,
    weapons,
    blocks,
    wals,
    miscelanious
};


enum gamestates
{
game,
invent,
crafting_state,
chest_state,
mainmenu,

};

enum biome
{
field,
snow,
desert,
cave,
snowcave,
desertcave


};

#endif // ENUM_H_INCLUDED
