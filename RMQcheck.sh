#!/bin/bash

make

begin_in='in/test'
end_in='.in'
begin_ref='out/test'
begin_out='out/testB'
end_out='.out'
score=0

for i in 0 1 2 3 4 5 6 7 8 9 10 11
do
    inFile=$begin_in$i$end_in
    outFile='lca.out'
    refFile=$begin_ref$i$end_out

    cp $inFile lca.in

    echo "Testul $i"
    command=$(/usr/bin/time -f "used memory=%M Kb elapsed time=%e seconds" ./LCA_using_RMQ)
    DIFF=$(diff "$outFile" "$refFile")
    if ["$DIFF" == ""]:
    then
        echo "CORECT !"
        $((score += 10))
    else
        echo "Gresit !"
    fi

    rm -rf lca.in lca.out
    
done

#make clean

echo "$score/120"

