#pragma once

#include "Set.hpp"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

class GNUSet : public Set {
    tree<
            int,                             // Key type
            null_type,                       // Mapped policy (since it's a set)
            std::less<int>,                  // Comparator
            rb_tree_tag,                  // Tree type (splay_tree_tag, rb_tree_tag, etc.)
            tree_order_statistics_node_update // Node update policy
    > s;

    void insert(int x) {
        s.insert(x);
    }
    int lb(int x) {
        auto it = s.lower_bound(x);
        if (s.end() == it) return 1e9;
        return *it;
    }

    string getName() override{
        return "GNU set splay";
    }
};