#!/opt/local/bin/bash

echo "#ifndef READY4AIR_H"
echo "#define READY4AIR_H"

ready4air/tools/depends.sh $@

#for file in "$@"
#do
#    echo "#include \"${file##*/}\""
#done

echo "#endif //READY4AIR_H"
