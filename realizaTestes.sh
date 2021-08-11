#!/bin/bash
#TAMANHOS="3000"
TAMANHOS="10 32 50 64 100 128"

TESTES="L3 L2CACHE FLOPS_DP"
TAM2="1 2 3"
CORE_ID=3

rm RUNTIME_*.txt &>/dev/null
for teste in $TESTES; do
    rm "$teste"_*.txt &>/dev/null
   
    for tam in $TAMANHOS; do
        #./perfctr $CORE_ID $teste ./matmult -n $tam > tmp.txt
        ./gera_entrada $tam > sample/"sample_$tam.in"
        likwid-perfctr -C $CORE_ID -g $teste -m ./matrixInv < sample/sample_$tam.in > tmp.txt
        if [ "$teste" = "L3" ]; then
            cat tmp.txt | grep "L3 bandwidth" | cut -d'|' -f3 >> "$teste"_"$tam".txt
            cat tmp.txt | grep "Runtime (RDTSC)" | cut -d'|' -f3 >> RUNTIME_"$tam".txt
            i=$((0))
            while read line; do
                if (( $i % 3 == 0 )); then
                    echo -n "$tam $line" >> RUNTIME_triangulariza.txt                
                elif (( $i % 3 == 1 )); then
                    echo " $line" >> RUNTIME_triangulariza.txt
                elif (( $i % 3 == 2 )); then
                    echo "$tam $line" >> RUNTIME_geraCoeficientes.txt
                fi
                i=$((i+1))
            done < RUNTIME_"$tam".txt
            rm RUNTIME_"$tam".txt

        elif [ "$teste" = "L2CACHE" ]; then
            cat tmp.txt | grep "miss ratio" | cut -d'|' -f3 >> "$teste"_"$tam".txt
        elif [ "$teste" = "FLOPS_DP" ]; then
            cat tmp.txt | grep "DP " | cut -d'|' -f3 >> "$teste"_"$tam"_dp.txt            
            cat tmp.txt | grep "AVX " | cut -d'|' -f3 >> "$teste"_"$tam"_avx.txt
            # retira linha por linha dos arquivos dp e avx
            for i in $TAM2; do
                DP=$(head -1 "$teste"_"$tam"_dp.txt)
                AVX=$(head -1 "$teste"_"$tam"_avx.txt)
                echo "$DP $AVX" >> "$teste"_"$tam".txt
                sed -i '1d' "$teste"_"$tam"_dp.txt
                sed -i '1d' "$teste"_"$tam"_avx.txt
            done
            rm "$teste"_"$tam"_dp.txt "$teste"_"$tam"_avx.txt
        fi
        i=$((0))
        while read line; do
            if (( $i % 3 == 0 )); then
                echo -n "$tam $line" >> "$teste"_triangulariza.txt                
            elif (( $i % 3 == 1 )); then
                echo " $line" >> "$teste"_triangulariza.txt
            elif (( $i % 3 == 2 )); then
                echo "$tam $line" >> "$teste"_geraCoeficientes.txt
            fi
            i=$((i+1))
        done < "$teste"_"$tam".txt
        
        rm "$teste"_"$tam".txt
        rm tmp.txt
    done
done
