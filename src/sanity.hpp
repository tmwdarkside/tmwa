#pragma once
//    sanity.hpp - Keep spatulas out of the build environment.
//
//    Copyright © 2013 Ben Longbons <b.r.longbons@gmail.com>
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

// just mention "fwd.hpp" to make formatter happy


namespace tmwa
{
#ifndef __cplusplus
# error "Please compile in C++ mode"
#endif // __cplusplus

#if __GNUC__ < 4
# error "Your compiler is absolutely ancient. You have no chance ..."
#endif // __GNUC__ < 4

#if __GNUC__ == 4
// clang identifies as GCC 4.2, but is mostly okay.
// Until a bug-free release of it happens, though, I won't recommend it.
// clang 3.2 is the minimum that the CI builds are using
# if __GNUC_MINOR__ < 7 && !defined(__clang__)
#  error "Please upgrade to at least GCC 4.7"
# endif // __GNUC_MINOR__ < 7 && !defined(__clang__)
#endif // __GNUC__ == 4

#if not defined(__i386__) and not defined(__x86_64__)
// There are no longer any *known* platform-independent bits,
// but nothing has been tested yet. It compiles, though, so ship it!
# ifndef QUIET
#  warning "Unsupported platform, upstream uses x86 / amd64 only"
# endif
#endif // not __i386__
} // namespace tmwa
