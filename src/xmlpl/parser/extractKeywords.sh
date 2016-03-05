#!/bin/sh
LITERALS=$(grep literals XmlPLLexer.cpp |
           sed -e 's/[ \t]*literals\["\([a-z_:-]*\)"\] = [0-9]*;/\1/' |
	   grep -v "::" |
           sort)

COUNT=$(echo -n "$LITERALS" | wc -w)
echo "count = $COUNT"

C=0
J=0
for i in $LITERALS; do
    L=$[$(echo -n "$i"|wc -c) + 4]
    if [ $[$C + $L] -gt 60 ]; then
      echo -n -e "\n"
      C=$L
    else
      C=$[$C + $L]
    fi

    if [ $J -ne 0 ]; then
      echo -n "| "
    fi
    echo -n "\"$i\" "

    J=$[$J + 1]
done

echo " ;"
