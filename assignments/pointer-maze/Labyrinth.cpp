#include "Labyrinth.h"

bool arr[3] = {0, 0, 0};
bool noMoreMoves = false;

bool isPathToFreedom(MazeCell* start, const std::string& moves)
{
  // if we have made an illegal move
  if (start == nullptr)
    return false;

  // checks if start has an item in it
  if (start->whatsHere == Item::SPELLBOOK)
    arr[0] = 1;
  else if (start->whatsHere == Item::POTION)
    arr[1] = 1;
  else if (start->whatsHere == Item::WAND)
    arr[2] = 1;

  // recursive case
  MazeCell* north = start->north;
  MazeCell* south = start->south;
  MazeCell* east = start->east;
  MazeCell* west = start->west;

  bool isGoodPath = false;
  // we don't need to check !isGoodPath
  // b/c we can still keep going after we found the 3 items
  if (moves[0] == 'N')
    isGoodPath = isPathToFreedom(north, moves.substr(1));
  if (moves[0] == 'S')
    isGoodPath = isPathToFreedom(south, moves.substr(1));
  if (moves[0] == 'E')
    isGoodPath = isPathToFreedom(east, moves.substr(1));
  if (moves[0] == 'W')
    isGoodPath = isPathToFreedom(west, moves.substr(1));

  // if we have no more moves
  // AND we have found all 3 items
  // this comes AFTER all the recursive calls, which makes sense
  if (moves == "" && arr[0] && arr[1] && arr[2])
    return true;
  // if we do have moves left:
  // 1) if they're illegal, the base case will return false
  // 2) if they're legal, then it'll skip the base case
  //    and enter the above if statement

  return isGoodPath;
}
