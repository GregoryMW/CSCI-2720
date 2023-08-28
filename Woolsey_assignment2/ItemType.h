#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum Comparison {GREATER, LESS, EQUAL};

class ItemType
{
 public:
  ItemType();
  Comparison compareTo(ItemType item);
  int getValue() const;
  void initialize(int num);

 private:
  int value;
};

#endif
