#include "cmp.hpp"
//    cmp_test.cpp - Testsuite for comparison related operations
//
//    Copyright © 2014 Ben Longbons <b.r.longbons@gmail.com>
//
//    This file is part of The Mana World (Athena server)
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <gtest/gtest.h>

#include "../compat/cast.hpp"

#include "../poison.hpp"


namespace tmwa
{
#pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"

// Google Test is *really* slow to compile this file
#undef EXPECT_EQ
#define EXPECT_EQ(a, b) assert(a == b)

TEST(ints, sati8)
{
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int8_t>(  -0x80ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x7fULL), saturate<int8_t>(maybe_cast<int8_t>(  -0x7fULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x7eULL), saturate<int8_t>(maybe_cast<int8_t>(  -0x7eULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x01ULL), saturate<int8_t>(maybe_cast<int8_t>(  -0x01ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x00ULL), saturate<int8_t>(maybe_cast<int8_t>(  +0x00ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x01ULL), saturate<int8_t>(maybe_cast<int8_t>(  +0x01ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7eULL), saturate<int8_t>(maybe_cast<int8_t>(  +0x7eULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int8_t>(  +0x7fULL)));

    EXPECT_EQ(maybe_cast<int8_t>(+0x00ULL), saturate<int8_t>(maybe_cast<uint8_t>( +0x00ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x01ULL), saturate<int8_t>(maybe_cast<uint8_t>( +0x01ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7eULL), saturate<int8_t>(maybe_cast<uint8_t>( +0x7eULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint8_t>( +0x7fULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint8_t>( +0x80ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint8_t>( +0xfeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint8_t>( +0xffULL)));


    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int16_t>( -0x8000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int16_t>( -0x7fffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int16_t>( -0x0100ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int16_t>( -0x00ffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int16_t>( -0x00feULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int16_t>( -0x0081ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int16_t>( -0x0080ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x7fULL), saturate<int8_t>(maybe_cast<int16_t>( -0x007fULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x01ULL), saturate<int8_t>(maybe_cast<int16_t>( -0x0001ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x00ULL), saturate<int8_t>(maybe_cast<int16_t>( +0x0000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x01ULL), saturate<int8_t>(maybe_cast<int16_t>( +0x0001ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7eULL), saturate<int8_t>(maybe_cast<int16_t>( +0x007eULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int16_t>( +0x007fULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int16_t>( +0x0080ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int16_t>( +0x00feULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int16_t>( +0x00ffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int16_t>( +0x0100ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int16_t>( +0x7ffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int16_t>( +0x7fffULL)));

    EXPECT_EQ(maybe_cast<int8_t>(+0x00ULL), saturate<int8_t>(maybe_cast<uint16_t>(+0x0000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x01ULL), saturate<int8_t>(maybe_cast<uint16_t>(+0x0001ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7eULL), saturate<int8_t>(maybe_cast<uint16_t>(+0x007eULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint16_t>(+0x007fULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint16_t>(+0x0080ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint16_t>(+0x00feULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint16_t>(+0x00ffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint16_t>(+0x0100ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint16_t>(+0x7ffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint16_t>(+0x7fffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint16_t>(+0x8000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint16_t>(+0xfffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint16_t>(+0xffffULL)));


    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int32_t>( -0x80000000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int32_t>( -0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int32_t>( -0x00010000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int32_t>( -0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int32_t>( -0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int32_t>( -0x00008001ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int32_t>( -0x00008000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int32_t>( -0x00007fffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int32_t>( -0x00000100ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int32_t>( -0x000000ffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int32_t>( -0x000000feULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int32_t>( -0x00000081ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int32_t>( -0x00000080ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x7fULL), saturate<int8_t>(maybe_cast<int32_t>( -0x0000007fULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x01ULL), saturate<int8_t>(maybe_cast<int32_t>( -0x00000001ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x00ULL), saturate<int8_t>(maybe_cast<int32_t>( +0x00000000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x01ULL), saturate<int8_t>(maybe_cast<int32_t>( +0x00000001ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7eULL), saturate<int8_t>(maybe_cast<int32_t>( +0x0000007eULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int32_t>( +0x0000007fULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int32_t>( +0x00000080ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int32_t>( +0x000000feULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int32_t>( +0x000000ffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int32_t>( +0x00000100ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int32_t>( +0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int32_t>( +0x00007fffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int32_t>( +0x00008000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int32_t>( +0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int32_t>( +0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int32_t>( +0x00010000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int32_t>( +0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int32_t>( +0x7fffffffULL)));

    EXPECT_EQ(maybe_cast<int8_t>(+0x00ULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x00000000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x01ULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x00000001ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7eULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x0000007eULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x0000007fULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x00000080ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x000000feULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x000000ffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x00000100ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x00007fffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x00008000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x00010000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0x80000000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0xfffffffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint32_t>(+0xffffffffULL)));


    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x0000000080000001ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x0000000000008001ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x0000000000000081ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x80ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( -0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<int8_t>(-0x01ULL), saturate<int8_t>(maybe_cast<int64_t>( -0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x00ULL), saturate<int8_t>(maybe_cast<int64_t>( +0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x01ULL), saturate<int8_t>(maybe_cast<int64_t>( +0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7eULL), saturate<int8_t>(maybe_cast<int64_t>( +0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<int64_t>( +0x7fffffffffffffffULL)));

    EXPECT_EQ(maybe_cast<int8_t>(+0x00ULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x01ULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7eULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0xfffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<int8_t>(+0x7fULL), saturate<int8_t>(maybe_cast<uint64_t>(+0xffffffffffffffffULL)));
}

TEST(ints, satu8)
{
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int8_t>(  -0x80ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int8_t>(  -0x7fULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int8_t>(  -0x7eULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int8_t>(  -0x01ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int8_t>(  +0x00ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x01ULL), saturate<uint8_t>(maybe_cast<int8_t>(  +0x01ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7eULL), saturate<uint8_t>(maybe_cast<int8_t>(  +0x7eULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7fULL), saturate<uint8_t>(maybe_cast<int8_t>(  +0x7fULL)));

    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<uint8_t>( +0x00ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x01ULL), saturate<uint8_t>(maybe_cast<uint8_t>( +0x01ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7eULL), saturate<uint8_t>(maybe_cast<uint8_t>( +0x7eULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7fULL), saturate<uint8_t>(maybe_cast<uint8_t>( +0x7fULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x80ULL), saturate<uint8_t>(maybe_cast<uint8_t>( +0x80ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xfeULL), saturate<uint8_t>(maybe_cast<uint8_t>( +0xfeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint8_t>( +0xffULL)));


    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int16_t>( -0x8000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int16_t>( -0x7fffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int16_t>( -0x0100ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int16_t>( -0x00ffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int16_t>( -0x00feULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int16_t>( -0x0081ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int16_t>( -0x0080ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int16_t>( -0x007fULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int16_t>( -0x0001ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int16_t>( +0x0000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x01ULL), saturate<uint8_t>(maybe_cast<int16_t>( +0x0001ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7eULL), saturate<uint8_t>(maybe_cast<int16_t>( +0x007eULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7fULL), saturate<uint8_t>(maybe_cast<int16_t>( +0x007fULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x80ULL), saturate<uint8_t>(maybe_cast<int16_t>( +0x0080ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xfeULL), saturate<uint8_t>(maybe_cast<int16_t>( +0x00feULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int16_t>( +0x00ffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int16_t>( +0x0100ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int16_t>( +0x7ffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int16_t>( +0x7fffULL)));

    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<uint16_t>(+0x0000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x01ULL), saturate<uint8_t>(maybe_cast<uint16_t>(+0x0001ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7eULL), saturate<uint8_t>(maybe_cast<uint16_t>(+0x007eULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7fULL), saturate<uint8_t>(maybe_cast<uint16_t>(+0x007fULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x80ULL), saturate<uint8_t>(maybe_cast<uint16_t>(+0x0080ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xfeULL), saturate<uint8_t>(maybe_cast<uint16_t>(+0x00feULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint16_t>(+0x00ffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint16_t>(+0x0100ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint16_t>(+0x7ffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint16_t>(+0x7fffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint16_t>(+0x8000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint16_t>(+0xfffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint16_t>(+0xffffULL)));


    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x80000000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x00010000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x00008001ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x00008000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x00007fffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x00000100ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x000000ffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x000000feULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x00000081ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x00000080ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x0000007fULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( -0x00000001ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x00000000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x01ULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x00000001ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7eULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x0000007eULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7fULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x0000007fULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x80ULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x00000080ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xfeULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x000000feULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x000000ffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x00000100ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x00007fffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x00008000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x00010000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int32_t>( +0x7fffffffULL)));

    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x00000000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x01ULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x00000001ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7eULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x0000007eULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7fULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x0000007fULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x80ULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x00000080ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xfeULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x000000feULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x000000ffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x00000100ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x00007fffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x00008000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x00010000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0x80000000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0xfffffffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint32_t>(+0xffffffffULL)));


    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x0000000080000001ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x0000000000008001ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x0000000000000081ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( -0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x01ULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7eULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7fULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x80ULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xfeULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<int64_t>( +0x7fffffffffffffffULL)));

    EXPECT_EQ(maybe_cast<uint8_t>(+0x00ULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x01ULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7eULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x7fULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0x80ULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xfeULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0xfffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<uint8_t>(+0xffULL), saturate<uint8_t>(maybe_cast<uint64_t>(+0xffffffffffffffffULL)));
}

TEST(ints, sati16)
{
    EXPECT_EQ(maybe_cast<int16_t>(-0x80ULL), saturate<int16_t>(maybe_cast<int8_t>(  -0x80ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x7fULL), saturate<int16_t>(maybe_cast<int8_t>(  -0x7fULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x7eULL), saturate<int16_t>(maybe_cast<int8_t>(  -0x7eULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x01ULL), saturate<int16_t>(maybe_cast<int8_t>(  -0x01ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x00ULL), saturate<int16_t>(maybe_cast<int8_t>(  +0x00ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x01ULL), saturate<int16_t>(maybe_cast<int8_t>(  +0x01ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7eULL), saturate<int16_t>(maybe_cast<int8_t>(  +0x7eULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fULL), saturate<int16_t>(maybe_cast<int8_t>(  +0x7fULL)));

    EXPECT_EQ(maybe_cast<int16_t>(+0x00ULL), saturate<int16_t>(maybe_cast<uint8_t>( +0x00ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x01ULL), saturate<int16_t>(maybe_cast<uint8_t>( +0x01ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7eULL), saturate<int16_t>(maybe_cast<uint8_t>( +0x7eULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fULL), saturate<int16_t>(maybe_cast<uint8_t>( +0x7fULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x80ULL), saturate<int16_t>(maybe_cast<uint8_t>( +0x80ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0xfeULL), saturate<int16_t>(maybe_cast<uint8_t>( +0xfeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0xffULL), saturate<int16_t>(maybe_cast<uint8_t>( +0xffULL)));


    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int16_t>( -0x8000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x7fffULL), saturate<int16_t>(maybe_cast<int16_t>( -0x7fffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x0100ULL), saturate<int16_t>(maybe_cast<int16_t>( -0x0100ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x00ffULL), saturate<int16_t>(maybe_cast<int16_t>( -0x00ffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x00feULL), saturate<int16_t>(maybe_cast<int16_t>( -0x00feULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x0081ULL), saturate<int16_t>(maybe_cast<int16_t>( -0x0081ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x0080ULL), saturate<int16_t>(maybe_cast<int16_t>( -0x0080ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x007fULL), saturate<int16_t>(maybe_cast<int16_t>( -0x007fULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x0001ULL), saturate<int16_t>(maybe_cast<int16_t>( -0x0001ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0000ULL), saturate<int16_t>(maybe_cast<int16_t>( +0x0000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0001ULL), saturate<int16_t>(maybe_cast<int16_t>( +0x0001ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x007eULL), saturate<int16_t>(maybe_cast<int16_t>( +0x007eULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x007fULL), saturate<int16_t>(maybe_cast<int16_t>( +0x007fULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0080ULL), saturate<int16_t>(maybe_cast<int16_t>( +0x0080ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x00feULL), saturate<int16_t>(maybe_cast<int16_t>( +0x00feULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x00ffULL), saturate<int16_t>(maybe_cast<int16_t>( +0x00ffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0100ULL), saturate<int16_t>(maybe_cast<int16_t>( +0x0100ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7ffeULL), saturate<int16_t>(maybe_cast<int16_t>( +0x7ffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int16_t>( +0x7fffULL)));

    EXPECT_EQ(maybe_cast<int16_t>(+0x0000ULL), saturate<int16_t>(maybe_cast<uint16_t>(+0x0000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0001ULL), saturate<int16_t>(maybe_cast<uint16_t>(+0x0001ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x007eULL), saturate<int16_t>(maybe_cast<uint16_t>(+0x007eULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x007fULL), saturate<int16_t>(maybe_cast<uint16_t>(+0x007fULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0080ULL), saturate<int16_t>(maybe_cast<uint16_t>(+0x0080ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x00feULL), saturate<int16_t>(maybe_cast<uint16_t>(+0x00feULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x00ffULL), saturate<int16_t>(maybe_cast<uint16_t>(+0x00ffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0100ULL), saturate<int16_t>(maybe_cast<uint16_t>(+0x0100ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7ffeULL), saturate<int16_t>(maybe_cast<uint16_t>(+0x7ffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint16_t>(+0x7fffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint16_t>(+0x8000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint16_t>(+0xfffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint16_t>(+0xffffULL)));


    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int32_t>( -0x80000000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int32_t>( -0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int32_t>( -0x00010000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int32_t>( -0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int32_t>( -0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int32_t>( -0x00008001ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int32_t>( -0x00008000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x7fffULL), saturate<int16_t>(maybe_cast<int32_t>( -0x00007fffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x0100ULL), saturate<int16_t>(maybe_cast<int32_t>( -0x00000100ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x00ffULL), saturate<int16_t>(maybe_cast<int32_t>( -0x000000ffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x00feULL), saturate<int16_t>(maybe_cast<int32_t>( -0x000000feULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x0081ULL), saturate<int16_t>(maybe_cast<int32_t>( -0x00000081ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x0080ULL), saturate<int16_t>(maybe_cast<int32_t>( -0x00000080ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x007fULL), saturate<int16_t>(maybe_cast<int32_t>( -0x0000007fULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x0001ULL), saturate<int16_t>(maybe_cast<int32_t>( -0x00000001ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0000ULL), saturate<int16_t>(maybe_cast<int32_t>( +0x00000000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0001ULL), saturate<int16_t>(maybe_cast<int32_t>( +0x00000001ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x007eULL), saturate<int16_t>(maybe_cast<int32_t>( +0x0000007eULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x007fULL), saturate<int16_t>(maybe_cast<int32_t>( +0x0000007fULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0080ULL), saturate<int16_t>(maybe_cast<int32_t>( +0x00000080ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x00feULL), saturate<int16_t>(maybe_cast<int32_t>( +0x000000feULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x00ffULL), saturate<int16_t>(maybe_cast<int32_t>( +0x000000ffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0100ULL), saturate<int16_t>(maybe_cast<int32_t>( +0x00000100ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7ffeULL), saturate<int16_t>(maybe_cast<int32_t>( +0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int32_t>( +0x00007fffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int32_t>( +0x00008000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int32_t>( +0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int32_t>( +0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int32_t>( +0x00010000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int32_t>( +0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int32_t>( +0x7fffffffULL)));

    EXPECT_EQ(maybe_cast<int16_t>(+0x0000ULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x00000000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0001ULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x00000001ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x007eULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x0000007eULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x007fULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x0000007fULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0080ULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x00000080ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x00feULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x000000feULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x00ffULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x000000ffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0100ULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x00000100ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7ffeULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x00007fffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x00008000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x00010000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint32_t>(+0x80000000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint32_t>(+0xfffffffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint32_t>(+0xffffffffULL)));


    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x0000000080000001ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x0000000000008001ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x8000ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x7fffULL), saturate<int16_t>(maybe_cast<int64_t>( -0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x0100ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x00ffULL), saturate<int16_t>(maybe_cast<int64_t>( -0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x00feULL), saturate<int16_t>(maybe_cast<int64_t>( -0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x0081ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x0000000000000081ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x0080ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x007fULL), saturate<int16_t>(maybe_cast<int64_t>( -0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<int16_t>(-0x0001ULL), saturate<int16_t>(maybe_cast<int64_t>( -0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0000ULL), saturate<int16_t>(maybe_cast<int64_t>( +0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0001ULL), saturate<int16_t>(maybe_cast<int64_t>( +0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x007eULL), saturate<int16_t>(maybe_cast<int64_t>( +0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x007fULL), saturate<int16_t>(maybe_cast<int64_t>( +0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0080ULL), saturate<int16_t>(maybe_cast<int64_t>( +0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x00feULL), saturate<int16_t>(maybe_cast<int64_t>( +0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x00ffULL), saturate<int16_t>(maybe_cast<int64_t>( +0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0100ULL), saturate<int16_t>(maybe_cast<int64_t>( +0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7ffeULL), saturate<int16_t>(maybe_cast<int64_t>( +0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int64_t>( +0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int64_t>( +0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int64_t>( +0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int64_t>( +0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int64_t>( +0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int64_t>( +0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int64_t>( +0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int64_t>( +0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int64_t>( +0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int64_t>( +0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int64_t>( +0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int64_t>( +0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<int64_t>( +0x7fffffffffffffffULL)));

    EXPECT_EQ(maybe_cast<int16_t>(+0x0000ULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0001ULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x007eULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x007fULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0080ULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x00feULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x00ffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x0100ULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7ffeULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0xfffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<int16_t>(+0x7fffULL), saturate<int16_t>(maybe_cast<uint64_t>(+0xffffffffffffffffULL)));
}

TEST(ints, satu16)
{
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00ULL), saturate<uint16_t>(maybe_cast<int8_t>(  -0x80ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00ULL), saturate<uint16_t>(maybe_cast<int8_t>(  -0x7fULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00ULL), saturate<uint16_t>(maybe_cast<int8_t>(  -0x7eULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00ULL), saturate<uint16_t>(maybe_cast<int8_t>(  -0x01ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00ULL), saturate<uint16_t>(maybe_cast<int8_t>(  +0x00ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x01ULL), saturate<uint16_t>(maybe_cast<int8_t>(  +0x01ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7eULL), saturate<uint16_t>(maybe_cast<int8_t>(  +0x7eULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7fULL), saturate<uint16_t>(maybe_cast<int8_t>(  +0x7fULL)));

    EXPECT_EQ(maybe_cast<uint16_t>(+0x00ULL), saturate<uint16_t>(maybe_cast<uint8_t>( +0x00ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x01ULL), saturate<uint16_t>(maybe_cast<uint8_t>( +0x01ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7eULL), saturate<uint16_t>(maybe_cast<uint8_t>( +0x7eULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7fULL), saturate<uint16_t>(maybe_cast<uint8_t>( +0x7fULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x80ULL), saturate<uint16_t>(maybe_cast<uint8_t>( +0x80ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xfeULL), saturate<uint16_t>(maybe_cast<uint8_t>( +0xfeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffULL), saturate<uint16_t>(maybe_cast<uint8_t>( +0xffULL)));


    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int16_t>( -0x8000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int16_t>( -0x7fffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int16_t>( -0x0100ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int16_t>( -0x00ffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int16_t>( -0x00feULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int16_t>( -0x0081ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int16_t>( -0x0080ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int16_t>( -0x007fULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int16_t>( -0x0001ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int16_t>( +0x0000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0001ULL), saturate<uint16_t>(maybe_cast<int16_t>( +0x0001ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x007eULL), saturate<uint16_t>(maybe_cast<int16_t>( +0x007eULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x007fULL), saturate<uint16_t>(maybe_cast<int16_t>( +0x007fULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0080ULL), saturate<uint16_t>(maybe_cast<int16_t>( +0x0080ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00feULL), saturate<uint16_t>(maybe_cast<int16_t>( +0x00feULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00ffULL), saturate<uint16_t>(maybe_cast<int16_t>( +0x00ffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0100ULL), saturate<uint16_t>(maybe_cast<int16_t>( +0x0100ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7ffeULL), saturate<uint16_t>(maybe_cast<int16_t>( +0x7ffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7fffULL), saturate<uint16_t>(maybe_cast<int16_t>( +0x7fffULL)));

    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<uint16_t>(+0x0000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0001ULL), saturate<uint16_t>(maybe_cast<uint16_t>(+0x0001ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x007eULL), saturate<uint16_t>(maybe_cast<uint16_t>(+0x007eULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x007fULL), saturate<uint16_t>(maybe_cast<uint16_t>(+0x007fULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0080ULL), saturate<uint16_t>(maybe_cast<uint16_t>(+0x0080ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00feULL), saturate<uint16_t>(maybe_cast<uint16_t>(+0x00feULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00ffULL), saturate<uint16_t>(maybe_cast<uint16_t>(+0x00ffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0100ULL), saturate<uint16_t>(maybe_cast<uint16_t>(+0x0100ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7ffeULL), saturate<uint16_t>(maybe_cast<uint16_t>(+0x7ffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7fffULL), saturate<uint16_t>(maybe_cast<uint16_t>(+0x7fffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x8000ULL), saturate<uint16_t>(maybe_cast<uint16_t>(+0x8000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xfffeULL), saturate<uint16_t>(maybe_cast<uint16_t>(+0xfffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint16_t>(+0xffffULL)));


    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x80000000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x00010000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x00008001ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x00008000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x00007fffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x00000100ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x000000ffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x000000feULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x00000081ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x00000080ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x0000007fULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( -0x00000001ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x00000000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0001ULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x00000001ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x007eULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x0000007eULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x007fULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x0000007fULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0080ULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x00000080ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00feULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x000000feULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00ffULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x000000ffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0100ULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x00000100ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7ffeULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7fffULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x00007fffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x8000ULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x00008000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xfffeULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x00010000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<int32_t>( +0x7fffffffULL)));

    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x00000000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0001ULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x00000001ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x007eULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x0000007eULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x007fULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x0000007fULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0080ULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x00000080ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00feULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x000000feULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00ffULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x000000ffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0100ULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x00000100ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7ffeULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7fffULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x00007fffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x8000ULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x00008000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xfffeULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x00010000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0x80000000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0xfffffffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint32_t>(+0xffffffffULL)));


    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x0000000080000001ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x0000000000008001ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x0000000000000081ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( -0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0001ULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x007eULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x007fULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0080ULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00feULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00ffULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0100ULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7ffeULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7fffULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x8000ULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xfffeULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<int64_t>( +0x7fffffffffffffffULL)));

    EXPECT_EQ(maybe_cast<uint16_t>(+0x0000ULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0001ULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x007eULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x007fULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0080ULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00feULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x00ffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x0100ULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7ffeULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x7fffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0x8000ULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xfffeULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0xfffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<uint16_t>(+0xffffULL), saturate<uint16_t>(maybe_cast<uint64_t>(+0xffffffffffffffffULL)));
}

TEST(ints, sati32)
{
    EXPECT_EQ(maybe_cast<int32_t>(-0x80ULL), saturate<int32_t>(maybe_cast<int8_t>(  -0x80ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x7fULL), saturate<int32_t>(maybe_cast<int8_t>(  -0x7fULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x7eULL), saturate<int32_t>(maybe_cast<int8_t>(  -0x7eULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x01ULL), saturate<int32_t>(maybe_cast<int8_t>(  -0x01ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00ULL), saturate<int32_t>(maybe_cast<int8_t>(  +0x00ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x01ULL), saturate<int32_t>(maybe_cast<int8_t>(  +0x01ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7eULL), saturate<int32_t>(maybe_cast<int8_t>(  +0x7eULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fULL), saturate<int32_t>(maybe_cast<int8_t>(  +0x7fULL)));

    EXPECT_EQ(maybe_cast<int32_t>(+0x00ULL), saturate<int32_t>(maybe_cast<uint8_t>( +0x00ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x01ULL), saturate<int32_t>(maybe_cast<uint8_t>( +0x01ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7eULL), saturate<int32_t>(maybe_cast<uint8_t>( +0x7eULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fULL), saturate<int32_t>(maybe_cast<uint8_t>( +0x7fULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x80ULL), saturate<int32_t>(maybe_cast<uint8_t>( +0x80ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0xfeULL), saturate<int32_t>(maybe_cast<uint8_t>( +0xfeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0xffULL), saturate<int32_t>(maybe_cast<uint8_t>( +0xffULL)));


    EXPECT_EQ(maybe_cast<int32_t>(-0x8000ULL), saturate<int32_t>(maybe_cast<int16_t>( -0x8000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x7fffULL), saturate<int32_t>(maybe_cast<int16_t>( -0x7fffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x0100ULL), saturate<int32_t>(maybe_cast<int16_t>( -0x0100ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00ffULL), saturate<int32_t>(maybe_cast<int16_t>( -0x00ffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00feULL), saturate<int32_t>(maybe_cast<int16_t>( -0x00feULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x0081ULL), saturate<int32_t>(maybe_cast<int16_t>( -0x0081ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x0080ULL), saturate<int32_t>(maybe_cast<int16_t>( -0x0080ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x007fULL), saturate<int32_t>(maybe_cast<int16_t>( -0x007fULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x0001ULL), saturate<int32_t>(maybe_cast<int16_t>( -0x0001ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000ULL), saturate<int32_t>(maybe_cast<int16_t>( +0x0000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0001ULL), saturate<int32_t>(maybe_cast<int16_t>( +0x0001ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x007eULL), saturate<int32_t>(maybe_cast<int16_t>( +0x007eULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x007fULL), saturate<int32_t>(maybe_cast<int16_t>( +0x007fULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0080ULL), saturate<int32_t>(maybe_cast<int16_t>( +0x0080ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00feULL), saturate<int32_t>(maybe_cast<int16_t>( +0x00feULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00ffULL), saturate<int32_t>(maybe_cast<int16_t>( +0x00ffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0100ULL), saturate<int32_t>(maybe_cast<int16_t>( +0x0100ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7ffeULL), saturate<int32_t>(maybe_cast<int16_t>( +0x7ffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffULL), saturate<int32_t>(maybe_cast<int16_t>( +0x7fffULL)));

    EXPECT_EQ(maybe_cast<int32_t>(+0x0000ULL), saturate<int32_t>(maybe_cast<uint16_t>(+0x0000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0001ULL), saturate<int32_t>(maybe_cast<uint16_t>(+0x0001ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x007eULL), saturate<int32_t>(maybe_cast<uint16_t>(+0x007eULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x007fULL), saturate<int32_t>(maybe_cast<uint16_t>(+0x007fULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0080ULL), saturate<int32_t>(maybe_cast<uint16_t>(+0x0080ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00feULL), saturate<int32_t>(maybe_cast<uint16_t>(+0x00feULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00ffULL), saturate<int32_t>(maybe_cast<uint16_t>(+0x00ffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0100ULL), saturate<int32_t>(maybe_cast<uint16_t>(+0x0100ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7ffeULL), saturate<int32_t>(maybe_cast<uint16_t>(+0x7ffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffULL), saturate<int32_t>(maybe_cast<uint16_t>(+0x7fffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x8000ULL), saturate<int32_t>(maybe_cast<uint16_t>(+0x8000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0xfffeULL), saturate<int32_t>(maybe_cast<uint16_t>(+0xfffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0xffffULL), saturate<int32_t>(maybe_cast<uint16_t>(+0xffffULL)));


    EXPECT_EQ(maybe_cast<int32_t>(-0x80000000ULL), saturate<int32_t>(maybe_cast<int32_t>( -0x80000000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x7fffffffULL), saturate<int32_t>(maybe_cast<int32_t>( -0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00010000ULL), saturate<int32_t>(maybe_cast<int32_t>( -0x00010000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x0000ffffULL), saturate<int32_t>(maybe_cast<int32_t>( -0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x0000fffeULL), saturate<int32_t>(maybe_cast<int32_t>( -0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00008001ULL), saturate<int32_t>(maybe_cast<int32_t>( -0x00008001ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00008000ULL), saturate<int32_t>(maybe_cast<int32_t>( -0x00008000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00007fffULL), saturate<int32_t>(maybe_cast<int32_t>( -0x00007fffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00000100ULL), saturate<int32_t>(maybe_cast<int32_t>( -0x00000100ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x000000ffULL), saturate<int32_t>(maybe_cast<int32_t>( -0x000000ffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x000000feULL), saturate<int32_t>(maybe_cast<int32_t>( -0x000000feULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00000081ULL), saturate<int32_t>(maybe_cast<int32_t>( -0x00000081ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00000080ULL), saturate<int32_t>(maybe_cast<int32_t>( -0x00000080ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x0000007fULL), saturate<int32_t>(maybe_cast<int32_t>( -0x0000007fULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00000001ULL), saturate<int32_t>(maybe_cast<int32_t>( -0x00000001ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00000000ULL), saturate<int32_t>(maybe_cast<int32_t>( +0x00000000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00000001ULL), saturate<int32_t>(maybe_cast<int32_t>( +0x00000001ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000007eULL), saturate<int32_t>(maybe_cast<int32_t>( +0x0000007eULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000007fULL), saturate<int32_t>(maybe_cast<int32_t>( +0x0000007fULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00000080ULL), saturate<int32_t>(maybe_cast<int32_t>( +0x00000080ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x000000feULL), saturate<int32_t>(maybe_cast<int32_t>( +0x000000feULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x000000ffULL), saturate<int32_t>(maybe_cast<int32_t>( +0x000000ffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00000100ULL), saturate<int32_t>(maybe_cast<int32_t>( +0x00000100ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00007ffeULL), saturate<int32_t>(maybe_cast<int32_t>( +0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00007fffULL), saturate<int32_t>(maybe_cast<int32_t>( +0x00007fffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00008000ULL), saturate<int32_t>(maybe_cast<int32_t>( +0x00008000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000fffeULL), saturate<int32_t>(maybe_cast<int32_t>( +0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000ffffULL), saturate<int32_t>(maybe_cast<int32_t>( +0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00010000ULL), saturate<int32_t>(maybe_cast<int32_t>( +0x00010000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7ffffffeULL), saturate<int32_t>(maybe_cast<int32_t>( +0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<int32_t>( +0x7fffffffULL)));

    EXPECT_EQ(maybe_cast<int32_t>(+0x00000000ULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x00000000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00000001ULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x00000001ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000007eULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x0000007eULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000007fULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x0000007fULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00000080ULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x00000080ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x000000feULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x000000feULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x000000ffULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x000000ffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00000100ULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x00000100ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00007ffeULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00007fffULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x00007fffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00008000ULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x00008000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000fffeULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000ffffULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00010000ULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x00010000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7ffffffeULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<uint32_t>(+0x80000000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<uint32_t>(+0xfffffffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<uint32_t>(+0xffffffffULL)));


    EXPECT_EQ(maybe_cast<int32_t>(-0x80000000ULL), saturate<int32_t>(maybe_cast<int64_t>( -0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x80000000ULL), saturate<int32_t>(maybe_cast<int64_t>( -0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x80000000ULL), saturate<int32_t>(maybe_cast<int64_t>( -0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x80000000ULL), saturate<int32_t>(maybe_cast<int64_t>( -0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x80000000ULL), saturate<int32_t>(maybe_cast<int64_t>( -0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x80000000ULL), saturate<int32_t>(maybe_cast<int64_t>( -0x0000000080000001ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x80000000ULL), saturate<int32_t>(maybe_cast<int64_t>( -0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x7fffffffULL), saturate<int32_t>(maybe_cast<int64_t>( -0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00010000ULL), saturate<int32_t>(maybe_cast<int64_t>( -0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x0000ffffULL), saturate<int32_t>(maybe_cast<int64_t>( -0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x0000fffeULL), saturate<int32_t>(maybe_cast<int64_t>( -0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00008001ULL), saturate<int32_t>(maybe_cast<int64_t>( -0x0000000000008001ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00008000ULL), saturate<int32_t>(maybe_cast<int64_t>( -0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00007fffULL), saturate<int32_t>(maybe_cast<int64_t>( -0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00000100ULL), saturate<int32_t>(maybe_cast<int64_t>( -0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x000000ffULL), saturate<int32_t>(maybe_cast<int64_t>( -0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x000000feULL), saturate<int32_t>(maybe_cast<int64_t>( -0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00000081ULL), saturate<int32_t>(maybe_cast<int64_t>( -0x0000000000000081ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00000080ULL), saturate<int32_t>(maybe_cast<int64_t>( -0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x0000007fULL), saturate<int32_t>(maybe_cast<int64_t>( -0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<int32_t>(-0x00000001ULL), saturate<int32_t>(maybe_cast<int64_t>( -0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00000000ULL), saturate<int32_t>(maybe_cast<int64_t>( +0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00000001ULL), saturate<int32_t>(maybe_cast<int64_t>( +0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000007eULL), saturate<int32_t>(maybe_cast<int64_t>( +0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000007fULL), saturate<int32_t>(maybe_cast<int64_t>( +0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00000080ULL), saturate<int32_t>(maybe_cast<int64_t>( +0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x000000feULL), saturate<int32_t>(maybe_cast<int64_t>( +0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x000000ffULL), saturate<int32_t>(maybe_cast<int64_t>( +0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00000100ULL), saturate<int32_t>(maybe_cast<int64_t>( +0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00007ffeULL), saturate<int32_t>(maybe_cast<int64_t>( +0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00007fffULL), saturate<int32_t>(maybe_cast<int64_t>( +0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00008000ULL), saturate<int32_t>(maybe_cast<int64_t>( +0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000fffeULL), saturate<int32_t>(maybe_cast<int64_t>( +0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000ffffULL), saturate<int32_t>(maybe_cast<int64_t>( +0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00010000ULL), saturate<int32_t>(maybe_cast<int64_t>( +0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7ffffffeULL), saturate<int32_t>(maybe_cast<int64_t>( +0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<int64_t>( +0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<int64_t>( +0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<int64_t>( +0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<int64_t>( +0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<int64_t>( +0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<int64_t>( +0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<int64_t>( +0x7fffffffffffffffULL)));

    EXPECT_EQ(maybe_cast<int32_t>(+0x00000000ULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00000001ULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000007eULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000007fULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00000080ULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x000000feULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x000000ffULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00000100ULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00007ffeULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00007fffULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00008000ULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000fffeULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x0000ffffULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x00010000ULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7ffffffeULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<uint64_t>(+0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<uint64_t>(+0xfffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<int32_t>(+0x7fffffffULL), saturate<int32_t>(maybe_cast<uint64_t>(+0xffffffffffffffffULL)));
}

TEST(ints, satu32)
{
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00ULL), saturate<uint32_t>(maybe_cast<int8_t>(  -0x80ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00ULL), saturate<uint32_t>(maybe_cast<int8_t>(  -0x7fULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00ULL), saturate<uint32_t>(maybe_cast<int8_t>(  -0x7eULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00ULL), saturate<uint32_t>(maybe_cast<int8_t>(  -0x01ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00ULL), saturate<uint32_t>(maybe_cast<int8_t>(  +0x00ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x01ULL), saturate<uint32_t>(maybe_cast<int8_t>(  +0x01ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7eULL), saturate<uint32_t>(maybe_cast<int8_t>(  +0x7eULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7fULL), saturate<uint32_t>(maybe_cast<int8_t>(  +0x7fULL)));

    EXPECT_EQ(maybe_cast<uint32_t>(+0x00ULL), saturate<uint32_t>(maybe_cast<uint8_t>( +0x00ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x01ULL), saturate<uint32_t>(maybe_cast<uint8_t>( +0x01ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7eULL), saturate<uint32_t>(maybe_cast<uint8_t>( +0x7eULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7fULL), saturate<uint32_t>(maybe_cast<uint8_t>( +0x7fULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x80ULL), saturate<uint32_t>(maybe_cast<uint8_t>( +0x80ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xfeULL), saturate<uint32_t>(maybe_cast<uint8_t>( +0xfeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xffULL), saturate<uint32_t>(maybe_cast<uint8_t>( +0xffULL)));


    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ULL), saturate<uint32_t>(maybe_cast<int16_t>( -0x8000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ULL), saturate<uint32_t>(maybe_cast<int16_t>( -0x7fffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ULL), saturate<uint32_t>(maybe_cast<int16_t>( -0x0100ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ULL), saturate<uint32_t>(maybe_cast<int16_t>( -0x00ffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ULL), saturate<uint32_t>(maybe_cast<int16_t>( -0x00feULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ULL), saturate<uint32_t>(maybe_cast<int16_t>( -0x0081ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ULL), saturate<uint32_t>(maybe_cast<int16_t>( -0x0080ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ULL), saturate<uint32_t>(maybe_cast<int16_t>( -0x007fULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ULL), saturate<uint32_t>(maybe_cast<int16_t>( -0x0001ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ULL), saturate<uint32_t>(maybe_cast<int16_t>( +0x0000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0001ULL), saturate<uint32_t>(maybe_cast<int16_t>( +0x0001ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x007eULL), saturate<uint32_t>(maybe_cast<int16_t>( +0x007eULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x007fULL), saturate<uint32_t>(maybe_cast<int16_t>( +0x007fULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0080ULL), saturate<uint32_t>(maybe_cast<int16_t>( +0x0080ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00feULL), saturate<uint32_t>(maybe_cast<int16_t>( +0x00feULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00ffULL), saturate<uint32_t>(maybe_cast<int16_t>( +0x00ffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0100ULL), saturate<uint32_t>(maybe_cast<int16_t>( +0x0100ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7ffeULL), saturate<uint32_t>(maybe_cast<int16_t>( +0x7ffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7fffULL), saturate<uint32_t>(maybe_cast<int16_t>( +0x7fffULL)));

    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ULL), saturate<uint32_t>(maybe_cast<uint16_t>(+0x0000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0001ULL), saturate<uint32_t>(maybe_cast<uint16_t>(+0x0001ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x007eULL), saturate<uint32_t>(maybe_cast<uint16_t>(+0x007eULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x007fULL), saturate<uint32_t>(maybe_cast<uint16_t>(+0x007fULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0080ULL), saturate<uint32_t>(maybe_cast<uint16_t>(+0x0080ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00feULL), saturate<uint32_t>(maybe_cast<uint16_t>(+0x00feULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00ffULL), saturate<uint32_t>(maybe_cast<uint16_t>(+0x00ffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0100ULL), saturate<uint32_t>(maybe_cast<uint16_t>(+0x0100ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7ffeULL), saturate<uint32_t>(maybe_cast<uint16_t>(+0x7ffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7fffULL), saturate<uint32_t>(maybe_cast<uint16_t>(+0x7fffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x8000ULL), saturate<uint32_t>(maybe_cast<uint16_t>(+0x8000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xfffeULL), saturate<uint32_t>(maybe_cast<uint16_t>(+0xfffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xffffULL), saturate<uint32_t>(maybe_cast<uint16_t>(+0xffffULL)));


    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x80000000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x00010000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x00008001ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x00008000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x00007fffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x00000100ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x000000ffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x000000feULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x00000081ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x00000080ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x0000007fULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( -0x00000001ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x00000000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000001ULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x00000001ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000007eULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x0000007eULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000007fULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x0000007fULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000080ULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x00000080ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x000000feULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x000000feULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x000000ffULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x000000ffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000100ULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x00000100ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00007ffeULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00007fffULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x00007fffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00008000ULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x00008000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000fffeULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ffffULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00010000ULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x00010000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7ffffffeULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7fffffffULL), saturate<uint32_t>(maybe_cast<int32_t>( +0x7fffffffULL)));

    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x00000000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000001ULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x00000001ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000007eULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x0000007eULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000007fULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x0000007fULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000080ULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x00000080ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x000000feULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x000000feULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x000000ffULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x000000ffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000100ULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x00000100ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00007ffeULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00007fffULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x00007fffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00008000ULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x00008000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000fffeULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ffffULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00010000ULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x00010000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7ffffffeULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7fffffffULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x80000000ULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0x80000000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xfffffffeULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0xfffffffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xffffffffULL), saturate<uint32_t>(maybe_cast<uint32_t>(+0xffffffffULL)));


    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x0000000080000001ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x0000000000008001ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x0000000000000081ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( -0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000001ULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000007eULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000007fULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000080ULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x000000feULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x000000ffULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000100ULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00007ffeULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00007fffULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00008000ULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000fffeULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ffffULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00010000ULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7ffffffeULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7fffffffULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x80000000ULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xfffffffeULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xffffffffULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xffffffffULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xffffffffULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xffffffffULL), saturate<uint32_t>(maybe_cast<int64_t>( +0x7fffffffffffffffULL)));

    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000000ULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000001ULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000007eULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000007fULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000080ULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x000000feULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x000000ffULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00000100ULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00007ffeULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00007fffULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00008000ULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000fffeULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x0000ffffULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x00010000ULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7ffffffeULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x7fffffffULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0x80000000ULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xfffffffeULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xffffffffULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xffffffffULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xffffffffULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xffffffffULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xffffffffULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xffffffffULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0xfffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<uint32_t>(+0xffffffffULL), saturate<uint32_t>(maybe_cast<uint64_t>(+0xffffffffffffffffULL)));
}

TEST(ints, sati64)
{
    EXPECT_EQ(maybe_cast<int64_t>(-0x80ULL), saturate<int64_t>(maybe_cast<int8_t>(  -0x80ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x7fULL), saturate<int64_t>(maybe_cast<int8_t>(  -0x7fULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x7eULL), saturate<int64_t>(maybe_cast<int8_t>(  -0x7eULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x01ULL), saturate<int64_t>(maybe_cast<int8_t>(  -0x01ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00ULL), saturate<int64_t>(maybe_cast<int8_t>(  +0x00ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x01ULL), saturate<int64_t>(maybe_cast<int8_t>(  +0x01ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7eULL), saturate<int64_t>(maybe_cast<int8_t>(  +0x7eULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7fULL), saturate<int64_t>(maybe_cast<int8_t>(  +0x7fULL)));

    EXPECT_EQ(maybe_cast<int64_t>(+0x00ULL), saturate<int64_t>(maybe_cast<uint8_t>( +0x00ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x01ULL), saturate<int64_t>(maybe_cast<uint8_t>( +0x01ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7eULL), saturate<int64_t>(maybe_cast<uint8_t>( +0x7eULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7fULL), saturate<int64_t>(maybe_cast<uint8_t>( +0x7fULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x80ULL), saturate<int64_t>(maybe_cast<uint8_t>( +0x80ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0xfeULL), saturate<int64_t>(maybe_cast<uint8_t>( +0xfeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0xffULL), saturate<int64_t>(maybe_cast<uint8_t>( +0xffULL)));


    EXPECT_EQ(maybe_cast<int64_t>(-0x8000ULL), saturate<int64_t>(maybe_cast<int16_t>( -0x8000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x7fffULL), saturate<int64_t>(maybe_cast<int16_t>( -0x7fffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0100ULL), saturate<int64_t>(maybe_cast<int16_t>( -0x0100ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x00ffULL), saturate<int64_t>(maybe_cast<int16_t>( -0x00ffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x00feULL), saturate<int64_t>(maybe_cast<int16_t>( -0x00feULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0081ULL), saturate<int64_t>(maybe_cast<int16_t>( -0x0081ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0080ULL), saturate<int64_t>(maybe_cast<int16_t>( -0x0080ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x007fULL), saturate<int64_t>(maybe_cast<int16_t>( -0x007fULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0001ULL), saturate<int64_t>(maybe_cast<int16_t>( -0x0001ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000ULL), saturate<int64_t>(maybe_cast<int16_t>( +0x0000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0001ULL), saturate<int64_t>(maybe_cast<int16_t>( +0x0001ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x007eULL), saturate<int64_t>(maybe_cast<int16_t>( +0x007eULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x007fULL), saturate<int64_t>(maybe_cast<int16_t>( +0x007fULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0080ULL), saturate<int64_t>(maybe_cast<int16_t>( +0x0080ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00feULL), saturate<int64_t>(maybe_cast<int16_t>( +0x00feULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00ffULL), saturate<int64_t>(maybe_cast<int16_t>( +0x00ffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0100ULL), saturate<int64_t>(maybe_cast<int16_t>( +0x0100ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7ffeULL), saturate<int64_t>(maybe_cast<int16_t>( +0x7ffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7fffULL), saturate<int64_t>(maybe_cast<int16_t>( +0x7fffULL)));

    EXPECT_EQ(maybe_cast<int64_t>(+0x0000ULL), saturate<int64_t>(maybe_cast<uint16_t>(+0x0000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0001ULL), saturate<int64_t>(maybe_cast<uint16_t>(+0x0001ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x007eULL), saturate<int64_t>(maybe_cast<uint16_t>(+0x007eULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x007fULL), saturate<int64_t>(maybe_cast<uint16_t>(+0x007fULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0080ULL), saturate<int64_t>(maybe_cast<uint16_t>(+0x0080ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00feULL), saturate<int64_t>(maybe_cast<uint16_t>(+0x00feULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00ffULL), saturate<int64_t>(maybe_cast<uint16_t>(+0x00ffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0100ULL), saturate<int64_t>(maybe_cast<uint16_t>(+0x0100ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7ffeULL), saturate<int64_t>(maybe_cast<uint16_t>(+0x7ffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7fffULL), saturate<int64_t>(maybe_cast<uint16_t>(+0x7fffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x8000ULL), saturate<int64_t>(maybe_cast<uint16_t>(+0x8000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0xfffeULL), saturate<int64_t>(maybe_cast<uint16_t>(+0xfffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0xffffULL), saturate<int64_t>(maybe_cast<uint16_t>(+0xffffULL)));


    EXPECT_EQ(maybe_cast<int64_t>(-0x80000000ULL), saturate<int64_t>(maybe_cast<int32_t>( -0x80000000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x7fffffffULL), saturate<int64_t>(maybe_cast<int32_t>( -0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x00010000ULL), saturate<int64_t>(maybe_cast<int32_t>( -0x00010000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0000ffffULL), saturate<int64_t>(maybe_cast<int32_t>( -0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0000fffeULL), saturate<int64_t>(maybe_cast<int32_t>( -0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x00008001ULL), saturate<int64_t>(maybe_cast<int32_t>( -0x00008001ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x00008000ULL), saturate<int64_t>(maybe_cast<int32_t>( -0x00008000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x00007fffULL), saturate<int64_t>(maybe_cast<int32_t>( -0x00007fffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x00000100ULL), saturate<int64_t>(maybe_cast<int32_t>( -0x00000100ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x000000ffULL), saturate<int64_t>(maybe_cast<int32_t>( -0x000000ffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x000000feULL), saturate<int64_t>(maybe_cast<int32_t>( -0x000000feULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x00000081ULL), saturate<int64_t>(maybe_cast<int32_t>( -0x00000081ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x00000080ULL), saturate<int64_t>(maybe_cast<int32_t>( -0x00000080ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0000007fULL), saturate<int64_t>(maybe_cast<int32_t>( -0x0000007fULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x00000001ULL), saturate<int64_t>(maybe_cast<int32_t>( -0x00000001ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000000ULL), saturate<int64_t>(maybe_cast<int32_t>( +0x00000000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000001ULL), saturate<int64_t>(maybe_cast<int32_t>( +0x00000001ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000007eULL), saturate<int64_t>(maybe_cast<int32_t>( +0x0000007eULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000007fULL), saturate<int64_t>(maybe_cast<int32_t>( +0x0000007fULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000080ULL), saturate<int64_t>(maybe_cast<int32_t>( +0x00000080ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000feULL), saturate<int64_t>(maybe_cast<int32_t>( +0x000000feULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000ffULL), saturate<int64_t>(maybe_cast<int32_t>( +0x000000ffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000100ULL), saturate<int64_t>(maybe_cast<int32_t>( +0x00000100ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00007ffeULL), saturate<int64_t>(maybe_cast<int32_t>( +0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00007fffULL), saturate<int64_t>(maybe_cast<int32_t>( +0x00007fffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00008000ULL), saturate<int64_t>(maybe_cast<int32_t>( +0x00008000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000fffeULL), saturate<int64_t>(maybe_cast<int32_t>( +0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000ffffULL), saturate<int64_t>(maybe_cast<int32_t>( +0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00010000ULL), saturate<int64_t>(maybe_cast<int32_t>( +0x00010000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7ffffffeULL), saturate<int64_t>(maybe_cast<int32_t>( +0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7fffffffULL), saturate<int64_t>(maybe_cast<int32_t>( +0x7fffffffULL)));

    EXPECT_EQ(maybe_cast<int64_t>(+0x00000000ULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x00000000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000001ULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x00000001ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000007eULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x0000007eULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000007fULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x0000007fULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000080ULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x00000080ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000feULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x000000feULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000ffULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x000000ffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000100ULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x00000100ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00007ffeULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00007fffULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x00007fffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00008000ULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x00008000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000fffeULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000ffffULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00010000ULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x00010000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7ffffffeULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7fffffffULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x80000000ULL), saturate<int64_t>(maybe_cast<uint32_t>(+0x80000000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0xfffffffeULL), saturate<int64_t>(maybe_cast<uint32_t>(+0xfffffffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0xffffffffULL), saturate<int64_t>(maybe_cast<uint32_t>(+0xffffffffULL)));


    EXPECT_EQ(maybe_cast<int64_t>(-0x8000000000000000ULL), saturate<int64_t>(maybe_cast<int64_t>( -0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x7fffffffffffffffULL), saturate<int64_t>(maybe_cast<int64_t>( -0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0000000100000000ULL), saturate<int64_t>(maybe_cast<int64_t>( -0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x00000000ffffffffULL), saturate<int64_t>(maybe_cast<int64_t>( -0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x00000000fffffffeULL), saturate<int64_t>(maybe_cast<int64_t>( -0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0000000080000001ULL), saturate<int64_t>(maybe_cast<int64_t>( -0x0000000080000001ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0000000080000000ULL), saturate<int64_t>(maybe_cast<int64_t>( -0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x000000007fffffffULL), saturate<int64_t>(maybe_cast<int64_t>( -0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0000000000010000ULL), saturate<int64_t>(maybe_cast<int64_t>( -0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x000000000000ffffULL), saturate<int64_t>(maybe_cast<int64_t>( -0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x000000000000fffeULL), saturate<int64_t>(maybe_cast<int64_t>( -0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0000000000008001ULL), saturate<int64_t>(maybe_cast<int64_t>( -0x0000000000008001ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0000000000008000ULL), saturate<int64_t>(maybe_cast<int64_t>( -0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0000000000007fffULL), saturate<int64_t>(maybe_cast<int64_t>( -0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0000000000000100ULL), saturate<int64_t>(maybe_cast<int64_t>( -0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x00000000000000ffULL), saturate<int64_t>(maybe_cast<int64_t>( -0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x00000000000000feULL), saturate<int64_t>(maybe_cast<int64_t>( -0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0000000000000081ULL), saturate<int64_t>(maybe_cast<int64_t>( -0x0000000000000081ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0000000000000080ULL), saturate<int64_t>(maybe_cast<int64_t>( -0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x000000000000007fULL), saturate<int64_t>(maybe_cast<int64_t>( -0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<int64_t>(-0x0000000000000001ULL), saturate<int64_t>(maybe_cast<int64_t>( -0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000000000ULL), saturate<int64_t>(maybe_cast<int64_t>( +0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000000001ULL), saturate<int64_t>(maybe_cast<int64_t>( +0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000000000007eULL), saturate<int64_t>(maybe_cast<int64_t>( +0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000000000007fULL), saturate<int64_t>(maybe_cast<int64_t>( +0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000000080ULL), saturate<int64_t>(maybe_cast<int64_t>( +0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000000000000feULL), saturate<int64_t>(maybe_cast<int64_t>( +0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000000000000ffULL), saturate<int64_t>(maybe_cast<int64_t>( +0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000000100ULL), saturate<int64_t>(maybe_cast<int64_t>( +0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000007ffeULL), saturate<int64_t>(maybe_cast<int64_t>( +0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000007fffULL), saturate<int64_t>(maybe_cast<int64_t>( +0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000008000ULL), saturate<int64_t>(maybe_cast<int64_t>( +0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000000000fffeULL), saturate<int64_t>(maybe_cast<int64_t>( +0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000000000ffffULL), saturate<int64_t>(maybe_cast<int64_t>( +0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000010000ULL), saturate<int64_t>(maybe_cast<int64_t>( +0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000007ffffffeULL), saturate<int64_t>(maybe_cast<int64_t>( +0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000007fffffffULL), saturate<int64_t>(maybe_cast<int64_t>( +0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000080000000ULL), saturate<int64_t>(maybe_cast<int64_t>( +0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000000fffffffeULL), saturate<int64_t>(maybe_cast<int64_t>( +0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000000ffffffffULL), saturate<int64_t>(maybe_cast<int64_t>( +0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000100000000ULL), saturate<int64_t>(maybe_cast<int64_t>( +0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7ffffffffffffffeULL), saturate<int64_t>(maybe_cast<int64_t>( +0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7fffffffffffffffULL), saturate<int64_t>(maybe_cast<int64_t>( +0x7fffffffffffffffULL)));

    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000000000ULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000000001ULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000000000007eULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000000000007fULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000000080ULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000000000000feULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000000000000ffULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000000100ULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000007ffeULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000007fffULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000008000ULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000000000fffeULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000000000ffffULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000000010000ULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000007ffffffeULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x000000007fffffffULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000080000000ULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000000fffffffeULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x00000000ffffffffULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x0000000100000000ULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7ffffffffffffffeULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7fffffffffffffffULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7fffffffffffffffULL), saturate<int64_t>(maybe_cast<uint64_t>(+0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7fffffffffffffffULL), saturate<int64_t>(maybe_cast<uint64_t>(+0xfffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<int64_t>(+0x7fffffffffffffffULL), saturate<int64_t>(maybe_cast<uint64_t>(+0xffffffffffffffffULL)));
}

TEST(ints, satu64)
{
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00ULL), saturate<uint64_t>(maybe_cast<int8_t>(  -0x80ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00ULL), saturate<uint64_t>(maybe_cast<int8_t>(  -0x7fULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00ULL), saturate<uint64_t>(maybe_cast<int8_t>(  -0x7eULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00ULL), saturate<uint64_t>(maybe_cast<int8_t>(  -0x01ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00ULL), saturate<uint64_t>(maybe_cast<int8_t>(  +0x00ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x01ULL), saturate<uint64_t>(maybe_cast<int8_t>(  +0x01ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7eULL), saturate<uint64_t>(maybe_cast<int8_t>(  +0x7eULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7fULL), saturate<uint64_t>(maybe_cast<int8_t>(  +0x7fULL)));

    EXPECT_EQ(maybe_cast<uint64_t>(+0x00ULL), saturate<uint64_t>(maybe_cast<uint8_t>( +0x00ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x01ULL), saturate<uint64_t>(maybe_cast<uint8_t>( +0x01ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7eULL), saturate<uint64_t>(maybe_cast<uint8_t>( +0x7eULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7fULL), saturate<uint64_t>(maybe_cast<uint8_t>( +0x7fULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x80ULL), saturate<uint64_t>(maybe_cast<uint8_t>( +0x80ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0xfeULL), saturate<uint64_t>(maybe_cast<uint8_t>( +0xfeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0xffULL), saturate<uint64_t>(maybe_cast<uint8_t>( +0xffULL)));


    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000ULL), saturate<uint64_t>(maybe_cast<int16_t>( -0x8000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000ULL), saturate<uint64_t>(maybe_cast<int16_t>( -0x7fffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000ULL), saturate<uint64_t>(maybe_cast<int16_t>( -0x0100ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000ULL), saturate<uint64_t>(maybe_cast<int16_t>( -0x00ffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000ULL), saturate<uint64_t>(maybe_cast<int16_t>( -0x00feULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000ULL), saturate<uint64_t>(maybe_cast<int16_t>( -0x0081ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000ULL), saturate<uint64_t>(maybe_cast<int16_t>( -0x0080ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000ULL), saturate<uint64_t>(maybe_cast<int16_t>( -0x007fULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000ULL), saturate<uint64_t>(maybe_cast<int16_t>( -0x0001ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000ULL), saturate<uint64_t>(maybe_cast<int16_t>( +0x0000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0001ULL), saturate<uint64_t>(maybe_cast<int16_t>( +0x0001ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x007eULL), saturate<uint64_t>(maybe_cast<int16_t>( +0x007eULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x007fULL), saturate<uint64_t>(maybe_cast<int16_t>( +0x007fULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0080ULL), saturate<uint64_t>(maybe_cast<int16_t>( +0x0080ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00feULL), saturate<uint64_t>(maybe_cast<int16_t>( +0x00feULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00ffULL), saturate<uint64_t>(maybe_cast<int16_t>( +0x00ffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0100ULL), saturate<uint64_t>(maybe_cast<int16_t>( +0x0100ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7ffeULL), saturate<uint64_t>(maybe_cast<int16_t>( +0x7ffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7fffULL), saturate<uint64_t>(maybe_cast<int16_t>( +0x7fffULL)));

    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000ULL), saturate<uint64_t>(maybe_cast<uint16_t>(+0x0000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0001ULL), saturate<uint64_t>(maybe_cast<uint16_t>(+0x0001ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x007eULL), saturate<uint64_t>(maybe_cast<uint16_t>(+0x007eULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x007fULL), saturate<uint64_t>(maybe_cast<uint16_t>(+0x007fULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0080ULL), saturate<uint64_t>(maybe_cast<uint16_t>(+0x0080ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00feULL), saturate<uint64_t>(maybe_cast<uint16_t>(+0x00feULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00ffULL), saturate<uint64_t>(maybe_cast<uint16_t>(+0x00ffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0100ULL), saturate<uint64_t>(maybe_cast<uint16_t>(+0x0100ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7ffeULL), saturate<uint64_t>(maybe_cast<uint16_t>(+0x7ffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7fffULL), saturate<uint64_t>(maybe_cast<uint16_t>(+0x7fffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x8000ULL), saturate<uint64_t>(maybe_cast<uint16_t>(+0x8000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0xfffeULL), saturate<uint64_t>(maybe_cast<uint16_t>(+0xfffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0xffffULL), saturate<uint64_t>(maybe_cast<uint16_t>(+0xffffULL)));


    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x80000000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x00010000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x00008001ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x00008000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x00007fffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x00000100ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x000000ffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x000000feULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x00000081ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x00000080ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x0000007fULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( -0x00000001ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x00000000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000001ULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x00000001ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000007eULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x0000007eULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000007fULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x0000007fULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000080ULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x00000080ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000feULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x000000feULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000ffULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x000000ffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000100ULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x00000100ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00007ffeULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00007fffULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x00007fffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00008000ULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x00008000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000fffeULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000ffffULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00010000ULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x00010000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7ffffffeULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7fffffffULL), saturate<uint64_t>(maybe_cast<int32_t>( +0x7fffffffULL)));

    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x00000000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000001ULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x00000001ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000007eULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x0000007eULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000007fULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x0000007fULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000080ULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x00000080ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000feULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x000000feULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000ffULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x000000ffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000100ULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x00000100ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00007ffeULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x00007ffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00007fffULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x00007fffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00008000ULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x00008000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000fffeULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x0000fffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000ffffULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x0000ffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00010000ULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x00010000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7ffffffeULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x7ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7fffffffULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x7fffffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x80000000ULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0x80000000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0xfffffffeULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0xfffffffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0xffffffffULL), saturate<uint64_t>(maybe_cast<uint32_t>(+0xffffffffULL)));


    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x0000000080000001ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x0000000000008001ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x0000000000000081ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( -0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000001ULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000000000007eULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000000000007fULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000080ULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000000000feULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000000000ffULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000100ULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000007ffeULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000007fffULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000008000ULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000000000fffeULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000000000ffffULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000010000ULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000007ffffffeULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000007fffffffULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000080000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000fffffffeULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ffffffffULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000100000000ULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7ffffffffffffffeULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7fffffffffffffffULL), saturate<uint64_t>(maybe_cast<int64_t>( +0x7fffffffffffffffULL)));

    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000000ULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x0000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000001ULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x0000000000000001ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000000000007eULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x000000000000007eULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000000000007fULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x000000000000007fULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000080ULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x0000000000000080ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000000000feULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x00000000000000feULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000000000ffULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x00000000000000ffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000000100ULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x0000000000000100ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000007ffeULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x0000000000007ffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000007fffULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x0000000000007fffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000008000ULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x0000000000008000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000000000fffeULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x000000000000fffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000000000ffffULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x000000000000ffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000000010000ULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x0000000000010000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000007ffffffeULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x000000007ffffffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x000000007fffffffULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x000000007fffffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000080000000ULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x0000000080000000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000fffffffeULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x00000000fffffffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x00000000ffffffffULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x00000000ffffffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x0000000100000000ULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x0000000100000000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7ffffffffffffffeULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x7ffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x7fffffffffffffffULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x7fffffffffffffffULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0x8000000000000000ULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0x8000000000000000ULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0xfffffffffffffffeULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0xfffffffffffffffeULL)));
    EXPECT_EQ(maybe_cast<uint64_t>(+0xffffffffffffffffULL), saturate<uint64_t>(maybe_cast<uint64_t>(+0xffffffffffffffffULL)));
}
} // namespace tmwa
