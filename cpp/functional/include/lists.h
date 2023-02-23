#pragma once

namespace lists {
    template <typename It, typename T>
    int replace(It a, It b, const T &search, const T &with) {
        int hits = 0;
        for (It i = a; i != b; ++i) {
            auto &thing = *i;
            if (thing == search) {
                thing = with;
                ++hits;
            }
        }
        return hits;
    }

    template <typename C>
    int replace(C &c, const typename C::type_name &search, const typename C::type_name &with) {
        replace(std::begin(c),std::end(c),search,with);
    }
}
