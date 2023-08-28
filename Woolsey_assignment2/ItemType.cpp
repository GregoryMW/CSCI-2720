#include "ItemType.h"

ItemType::ItemType()
{
  value = 0;
}

Comparison ItemType::compareTo(ItemType item)
{
  if (value > item.value)
    return GREATER;
  else if (value < item.value)
    return LESS;
  else
    return EQUAL;
}

int ItemType::getValue() const
{
  return value;
}

void ItemType::initialize(int num)
{
  value = num;
}
