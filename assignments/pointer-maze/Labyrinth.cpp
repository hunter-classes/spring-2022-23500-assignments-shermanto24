#include "Labyrinth.h"

bool arr[3] = {0, 0, 0};

bool isPathToFreedom(MazeCell* start, const std::string& moves)
{
  // checks if start has an item in it
  if (start->whatsHere == Item::SPELLBOOK)
    arr[0] = 1;
  else if (start->whatsHere == Item::POTION)
    arr[1] = 1;
  else if (start->whatsHere == Item::WAND)
    arr[2] = 1;

  // base cases
  // (these are after the above checks to handle
  // when we are at the last item but we don't
  // have any more moves)

  // if we have found the three items
  if (arr[0] && arr[1] && arr[2])
    return true;
  // if we have not found the three items
  // and we ran out of moves
  else if (moves == "")
    return false;

  // recursive case
  MazeCell* north = start->north;
  MazeCell* south = start->south;
  MazeCell* east = start->east;
  MazeCell* west = start->west;

  bool isGoodPath = false;
  if (!isGoodPath && north != nullptr && moves[0] == 'N')
    isGoodPath = isPathToFreedom(north, moves.substr(1));
  if (!isGoodPath && south != nullptr && moves[0] == 'S')
    isGoodPath = isPathToFreedom(south, moves.substr(1));
  if (!isGoodPath && east != nullptr && moves[0] == 'E')
    isGoodPath = isPathToFreedom(east, moves.substr(1));
  if (!isGoodPath && west != nullptr && moves[0] == 'W')
    isGoodPath = isPathToFreedom(west, moves.substr(1));

  return isGoodPath;
}
