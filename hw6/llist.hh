#include <cstdint>

using data_t = uint32_t;

struct LNode {
  data_t data_;
  LNode* next_;
};


void append_node(LNode* n1, LNode* n2);

LNode* find(LNode* head, data_t value);

void delete_list(LNode* head);
