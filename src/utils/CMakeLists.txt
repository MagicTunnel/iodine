#
# Copyright (c) 2017 Vitaly Chipounov <vitaly@chipounov.fr>,
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#

add_library (utils base128.c base32.c base64.c md5.c base64u.c)

add_custom_command(
    OUTPUT base64u.h base64u.c
    DEPENDS base64.h
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/makeenc.sh ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(
    base64 ALL
    DEPENDS base64u.h base64u.c
)

target_include_directories (utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
