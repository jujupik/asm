#!/bin/bash4

write_parameter()
{
	for ((i=0 ; $num - $i ; i++)) do
		if [ $i != 0 ]; then
			echo ", \c" >> $FILE_NAME
		fi
		echo "${TYPE[$i]}p_${CONTENT[$i]}\c" >> $FILE_NAME
	done
}

parse_variable()
{
	echo "Variable in struct : "
	while true
	do
		read VARIABLE
		if [ -z "$VARIABLE" ]; then
			break
		else
			CONTENT[num]=$(cut -d' ' -f2 <<< $VARIABLE | tr -d '*')
			TYPE[num]=${VARIABLE/${CONTENT[num]}/}
			num=num+1
			VARIABLES+="	$VARIABLE"
			VARIABLES+=";\n"
		fi
	done
}

parse_include()
{
	declare -i USED=0
	echo "Add include : "
	while true
	do
		read TO_ADD
		if [ -z "$TO_ADD" ]; then
			if [ "$USED" == 1 ];then
				echo "" >> $FILE_NAME
			fi
			break
		else
			USED=1
			echo "#include \"$TO_ADD.h\"" >> $FILE_NAME
		fi
	done
}

echo "Project name : "
read PROJECT
echo "Structure name : "
read NAME
VARIABLES=" "
declare -i num=0
declare -a CONTENT
declare -a TYPE
parse_variable;
FILE_NAME=$(echo "includes/${PROJECT}_$NAME.h")
rm -f $FILE_NAME
touch $FILE_NAME
STRUCT="t_$NAME"
MAJ_NAME="$NAME"
COMMAND=$(echo "${PROJECT}" | tr '[:lower:]' '[:upper:]')
COMMAND+="_"
COMMAND+=$(echo "${MAJ_NAME}" | tr '[:lower:]' '[:upper:]')
COMMAND+="_H"
echo "#ifndef $COMMAND" >> $FILE_NAME
echo "# define $COMMAND" >> $FILE_NAME
echo "" >> $FILE_NAME
parse_include;
echo "typedef struct		s_$NAME" >> $FILE_NAME
echo "{" >> $FILE_NAME
echo "$VARIABLES\c" >> $FILE_NAME
echo "}					$STRUCT;" >> $FILE_NAME
VARIABLES=$(echo "$VARIABLES" | tr -d '\t')
VARIABLES=$(echo "$VARIABLES" | tr ';' ',')
VARIABLES=$(echo "$VARIABLES" | tr '\n' ' ')
VARIABLES=$(echo "$VARIABLES" | cut -c2- | rev | cut -c3- | rev)
echo "" >> $FILE_NAME
echo "$STRUCT create_$NAME(\c" >> $FILE_NAME
write_parameter;
echo ");" >> $FILE_NAME
echo "$STRUCT *malloc_$NAME(\c" >> $FILE_NAME
write_parameter;
echo ");" >> $FILE_NAME
echo "void destroy_$NAME($STRUCT to_destroy);" >> $FILE_NAME
echo "void free_$NAME($STRUCT *to_free);" >> $FILE_NAME
echo "" >> $FILE_NAME
echo "#endif" >> $FILE_NAME
FILE_NAME=$(echo "srcs/t_$NAME.c")
rm -f $FILE_NAME
touch $FILE_NAME
echo "#include \"$PROJECT.h\"" >> $FILE_NAME
echo "" >> $FILE_NAME
echo "$STRUCT create_$NAME(\c" >> $FILE_NAME
write_parameter;
echo ")" >> $FILE_NAME
echo "{" >> $FILE_NAME
echo "	$STRUCT	result;" >> $FILE_NAME
echo "" >> $FILE_NAME
for ((i=0 ; $num - $i ; i++)) do
	echo "	result.${CONTENT[$i]} = p_${CONTENT[$i]};" >> $FILE_NAME
done
echo "	return (result);" >> $FILE_NAME
echo "}" >> $FILE_NAME
echo "" >> $FILE_NAME
echo "$STRUCT *malloc_$NAME(\c" >> $FILE_NAME
write_parameter;
echo ")" >> $FILE_NAME
echo "{" >> $FILE_NAME
echo "	$STRUCT	*result;" >> $FILE_NAME
echo "" >> $FILE_NAME
echo "	result = ($STRUCT	*)malloc(sizeof($STRUCT));" >> $FILE_NAME
echo "	if (result == NULL)" >> $FILE_NAME
echo "		return (NULL);" >> $FILE_NAME
echo "	*result = create_$NAME(\c" >> $FILE_NAME
for ((i=0 ; $num - $i ; i++)) do
	if [ $i != 0 ]; then
		echo ", \c" >> $FILE_NAME
	fi
	echo "p_${CONTENT[$i]}\c" >> $FILE_NAME
done
echo ");" >> $FILE_NAME
echo "	return (result);" >> $FILE_NAME
echo "}" >> $FILE_NAME
echo "" >> $FILE_NAME
echo "void destroy_$NAME($STRUCT to_destroy)" >> $FILE_NAME
echo "{" >> $FILE_NAME
echo "	(void)to_destroy;" >> $FILE_NAME
echo "	ft_printf(\"To do : destroy_$NAME\");" >> $FILE_NAME
echo "}" >> $FILE_NAME
echo "" >> $FILE_NAME
echo "void free_$NAME($STRUCT *to_free)" >> $FILE_NAME
echo "{" >> $FILE_NAME
echo "	destroy_$NAME(*to_free);" >> $FILE_NAME
echo "	free(to_free);" >> $FILE_NAME
echo "}" >> $FILE_NAME
