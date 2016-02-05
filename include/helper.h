#ifndef HELPER_H
#define HELPER_H

#include <assert.h>

template<typename I, I* I::*P, I* I::*N>
class LinkedItem {
    typedef I Item;
  public:
    LinkedItem(void): h_(NULL), t_(NULL), size_(0) { }

    /** Append an Item after the Item at pos */
    void append(Item *pos, Item *e) {
      assert ((size_ == 0 && pos == NULL) || (find_(pos) != NULL));

      e->*P = pos;
      if (pos == NULL) {
        h_ = e;
        t_ = e;
        e->*N = NULL;
      } else {
        e->*N = pos->*N;
        if (pos->*N == NULL)
          t_ = e;
        else
          pos->*N->*P = e;
        pos->*N = e;
      }

      ++size_;
    }

    /** Append an Item to last position */
    void append(Item *e) { append(t_, e); }

    /** Insert an Item before Item at pos */
    void prepend(Item *pos, Item *e) {
      assert ((size_ == 0 && pos == NULL) || (find_(pos) != NULL));

      e->*N = pos;
      if (pos == NULL) {
        h_ = e;
        t_ = e;
        e->*P = NULL;
      } else {
        e->*P = pos->*P;
        if (pos->*P == NULL)
          h_ = e;
        else
          pos->*P->*N = e;
        pos->*P = e;
      }

      ++size_;
    }

    /** Remove an Item from the list and return the following Item */
    Item *remove(Item *e) {
      assert(find_(e) != NULL);
      Item *next = e->*N;

      if (e->*N == NULL)
        t_ = e->*P;
      else
        e->*N->*P = e->*P;
      if (e->*P == NULL)
        h_ = e->*N;
      else
        e->*P->*N = e->*N;
      e->*N = NULL;
      e->*P = NULL;

      --size_;

      return next;
    }

    Item *prev(Item *i) const {
      assert (find_(i) != NULL);
      return i->*P;
    }

    const Item *prev(const Item *i) const {
      assert (find_(i) != NULL);
      return i->*P;
    }

    Item *next(Item *i) const {
      assert (find_(i) != NULL);
      return i->*N;
    }

    const Item *next(const Item *i) const {
      assert (find_(i) != NULL);
      return i->*N;
    }

    unsigned size(void) const { return size_; }

    Item *head(void) { return h_; }
    const Item *head(void) const { return h_; }
    Item *tail(void) { return t_; }
    const Item *tail(void) const { return t_; }

  private:
    Item *find_(const Item *e) const
    {
      Item *cur = h_;
      while ((cur != NULL) && (cur != e))
        cur = cur->*N;
      return cur;
    }

    Item *h_;
    Item *t_;
    unsigned size_;
};

#endif
