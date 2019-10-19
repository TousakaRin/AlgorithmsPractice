#include "common.h"

template<typename Iterator>
void BubbleSort(Iterator begin, Iterator end) {
   for (auto top = begin + 1; top != end; ++top) {
       for (auto buttom = end - 1; buttom > top; --buttom) {
           typename Iterator::reference down = *buttom;
           typename Iterator::reference up = *(buttom - 1);
           if (down < up) {
               swap(down, up);
           }
       }
   }
}