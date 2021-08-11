#! /bin/bash

METRICS="RUNTIME L3 L2CACHE"

for metric in $METRICS ; do
    sed "s/METRIC/$metric/g" triangulariza.p > "$metric"_triangulariza.p
    sed "s/METRIC/$metric/g" geraCoef.p > "$metric"_geraCoef.p
    gnuplot "$metric"_triangulariza.p
    gnuplot "$metric"_geraCoef.p
    rm "$metric"_triangulariza.p
    rm "$metric"_geraCoef.p
done