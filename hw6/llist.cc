#include "llist.hh"

LNode* find(LNode* head, data_t value)
{
  while (head) {
    if (value == head->data_) {
      return head;
    }
    head = head->next_;
  }
  return nullptr;
}

LNode* find_alt(LNode* head, data_t value)
{
  if (!head) {
    return nullptr;
  }

  if (value == head->data_) {
    return head;
  }
  else {
    return find(head->next_, value);
  }
}


void delete_list(LNode* head)
{
  while (head) {
    auto save = head->next_;
    delete head;
    head = save;
  }
}

void delete_list_alt(LNode* head)
{
  if (!head) {
    return;
  }
  delete_list(head->next_);
  delete head;
}

