#!/bin/sh

if [ $# -ne 2 ]; then
  echo "Invalid args"
  exit 1
fi

encode()
{
  SRC="$1"
  DST="$2"

  echo Making $DST
  echo '/* No use in editing, produced by Makefile! */' > "$DST"
  sed -e 's/\([Bb][Aa][Ss][Ee]64\)/\1u/g ; s/0123456789+/0123456789_/' < "$SRC" >> "$DST"
}

SRC_DIR="$1"
DST_DIR="$2"

encode "$SRC_DIR/base64.c" "$DST_DIR/base64u.c"
encode "$SRC_DIR/base64.h" "$DST_DIR/base64u.h"
