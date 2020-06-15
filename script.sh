#!bin/bash
ADDRESS=$1
BASE="\.s"
END="\.cor"
FINAL=$(echo $ADDRESS | sed "s/$BASE/$END/g")
echo -n "Our :\t" && ./our/asm $1 && mv $FINAL our/.
echo -n "Them :\t" && ./sujet/asm $1 && mv $FINAL sujet/.
FILE_NAME=$(echo $FINAL | rev | cut -d '/' -f -1 | rev)

if test -f "our/$FILE_NAME" && test -f "sujet/$FILE_NAME" ; then
	if diff "our/$FILE_NAME" "sujet/$FILE_NAME" > /dev/null ; then
	   echo "Everything is fine"
	else
	   cmp -b "our/$FILE_NAME" "sujet/$FILE_NAME"
	fi
fi
