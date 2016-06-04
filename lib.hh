/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef HEADER_GUARD_VICK_LOOKING_AT_H
#define HEADER_GUARD_VICK_LOOKING_AT_H

#include <cstring>

#include "contents.hh"

/*!
 * \file vick-looking-at/lib.hh
 * \brief Defines functions to test if we are looking at something.
 *
 * They are intended as utilities for programming plugins, rather than
 * interactive usage.
 */

namespace vick {
namespace looking_at {
/*!
 * \brief Returns whether the query matches the contents at the
 * current position.
 *
 * `query` is not a regular expression, it is a c-string.
 *
 * Equivalent to any of:
 *
 * \code{.cpp}
   is_looking_at_n(contents, query, std::strlen(query));
   is_at(contents, contents.y, contents.x, query);
   is_at_n(contents, contents.y, contents.x, query,
           std::strlen(query));
 * \endcode
 */
inline bool
is_looking_at(const contents& contents, const char* query);

/*!
 * \brief Returns whether the query matches the contents at the
 * current position.
 *
 * `query` is not a regular expression, it is a c-string of length
 * `query_size`.
 *
 * Equivalent to:
 *
 * \code{.cpp}
   is_at_n(contents, contents.y, contents.x, query, query_size);
 * \endcode
 */
inline bool is_looking_at_n(const contents& contents,
                            const char* query, size_t query_size);

/*!
 * \brief Returns whether the query matches the contents at the given
 * position.
 *
 * `query` is not a regular expression, it is a c-string.
 *
 * If y or x is outside the contents, this returns false.
 *
 * Equivalent to:
 *
 * \code{.cpp}
   is_at_n(contents, y, x, query, std::strlen(query));
 * \endcode
 */
inline bool is_at(const contents& contents, move_t y, move_t x,
                  const char* query);

/*!
 * \brief Returns whether the query matches the contents at the given
 * position.
 *
 * `query` is not a regular expression, it is a c-string of length
 * `query_size`.
 *
 * If y or x is outside the contents, this returns false.
 */
bool is_at_n(const contents& contents, move_t y, move_t x,
             const char* query, size_t query_size);

// implementation of inline methods requires is_at_n to be declared
inline bool
is_looking_at(const contents& contents, const char* query) {
    return is_at_n(contents, contents.y, contents.x, query,
                   std::strlen(query));
}

inline bool is_looking_at_n(const contents& contents,
                            const char* query, size_t query_size) {
    return is_at_n(contents, contents.y, contents.x, query,
                   query_size);
}

inline bool is_at(const contents& contents, move_t y, move_t x,
                  const char* query) {
    return is_at_n(contents, y, x, query, std::strlen(query));
}
}
}

#endif
