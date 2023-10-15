#!/bin/sh

trap "cat temp.txt && exit 1" INT

ligne=""
while read -r ligne && [ -n "$ligne" ]; do
  echo "$ligne" >> temp.txt
done

cat "temp.txt"
exit 0
