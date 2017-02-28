#include "Dungeon.hh"

/*
 * Preconditions: 2 valid heros are provided
 * Postconditions: Returns true if hero x has less strength than hero y, false otherwise
 */
bool Dungeon::HeroHeroComp::lt(Hero x, Hero y)
{
    return x.strength < y.strength;
}
/*
 * Preconditions: 2 valid heros are provided
 * Postconditions: Returns true if hero x has more strength than hero y, false otherwise
 */
bool Dungeon::HeroHeroComp::gt(Hero x, Hero y)
{
    return x.strength > y.strength;
}
/*
 * Preconditions: 2 valid heros are provided
 * Postconditions: Returns true if hero x has equal strength than hero y, false otherwise
 */
bool Dungeon::HeroHeroComp::eq(Hero x, Hero y)
{
    return x.strength == y.strength;
}
