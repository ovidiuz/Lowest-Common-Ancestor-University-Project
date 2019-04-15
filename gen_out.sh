#!/bin/bash

begin_in='in/test'
end_in='.in'
begin_out='out/test'
end_out='.out'

for i in 0 1 2 3 4 5 6 7 8 9 10 11
do
    inFile=$begin_in$i$end_in
    outFile=$begin_out$i$end_out
    ./BruteForceLCA <"$inFile" > "$outFile"
    
done
