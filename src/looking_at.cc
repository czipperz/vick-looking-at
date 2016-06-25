/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <algorithm>
#include <cstdio>
#include <cstring>

#include "../lib.hh"

namespace vick {
namespace looking_at {
bool is_at_n(const contents& contents, move_t y, move_t x,
             const char* query, size_t query_size) {
#define BOUNDS_CHECK()                                               \
    do {                                                             \
        if (contents.cont.size() <= y ||                             \
            contents.cont[y].size() <= x) {                          \
            /* out of bounds */                                      \
            return false;                                            \
        }                                                            \
    } while (0)

    BOUNDS_CHECK();

    const char* query_end = query + query_size;
    const char *start = query, *end;
    {
    start:
        end = std::find(start, query_end, '\n');
        if (std::strncmp(contents.cont[y].c_str() + x, start,
                         static_cast<size_t>(end - start)) != 0) {
            return false;
        }

        // found new line
        if (end != query_end) {
            start = end + 1;
            ++y;
            x = 0;
            BOUNDS_CHECK();
            goto start;
        }
    }

    return true;

#undef BOUNDS_CHECK
}
}
}
