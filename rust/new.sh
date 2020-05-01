set -eu

URL=$1

if [ "`echo $URL | grep atcoder`" ]; then
    CONTEST=`echo $URL | sed -E 's/.+\/([^\/]+)\/tasks\/([^\/]+)$/\1/'`
    PROBLEM=`echo $URL | sed -E 's/.+\/([^\/]+)\/tasks\/([^\/]+)$/\2/'`

    mkdir -p atcoder/$CONTEST
    FILE=atcoder/$CONTEST/$PROBLEM.rs
    if [ -e $FILE ]; then
        echo "file exists"
    else
        cp snippets/tmp.rs $FILE
    fi
    code $FILE
fi

if [ "`echo $URL | grep yukicoder`" ]; then
    PROBLEM=`echo $URL | sed -E 's/.+\/([^\/]+)$/\1/'`

    FILE=yukicoder/$PROBLEM.rs
    if [ -e $FILE ]; then
        echo "file exists"
    else
        cp snippets/tmp.rs $FILE
    fi
    code $FILE
fi
