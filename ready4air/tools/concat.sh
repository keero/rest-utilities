#!/opt/local/bin/bash


for var in "$@"
do
    cat $var | sed -E '/#include[ \t]+".*/d' | sed -E '/^[ \t]*$/d'
    echo
done