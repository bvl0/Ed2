BASEDIR=$(dirname "$0")
for sortType in $BASEDIR/*Sort.c; do
        echo $sortType
        gcc client.c item.h $sortType -o sort -O4 &&
        for inputType in $BASEDIR/in/* ; do          
            echo ${inputType#./in/}
            echo "1000 inputs"
            for i in seq 10 ; do ./sort 1000  "in/${inputType#./in/}/1K${inputType#./in/}.txt"; done 
            echo "10000 inputs"
            for i in seq 10 ; do ./sort 10000 "in/${inputType#./in/}/10K${inputType#./in/}.txt"; done
            echo "100000 inputs"
            for i in seq 10 ; do ./sort 100000 "in/${inputType#./in/}/100K${inputType#./in/}.txt"; done 
            echo ""
        done;
    done;

