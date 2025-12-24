#!/bin/bash

# Script pour tester push_swap et vérifier les seuils d'instructions

echo "=== TEST VERSION INTERMÉDIAIRE (100 valeurs) ==="
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' ')
RESULT=$(./push_swap $ARG | ./checker $ARG)
COUNT=$(./push_swap $ARG | wc -l)

echo "Résultat checker: $RESULT"
echo "Nombre d'instructions: $COUNT"

if [ "$RESULT" = "OK" ]; then
    if [ $COUNT -lt 700 ]; then
        echo "✅ NOTE: 5/5 (< 700)"
    elif [ $COUNT -lt 900 ]; then
        echo "✅ NOTE: 4/5 (< 900)"
    elif [ $COUNT -lt 1100 ]; then
        echo "✅ NOTE: 3/5 (< 1100)"
    elif [ $COUNT -lt 1300 ]; then
        echo "✅ NOTE: 2/5 (< 1300)"
    elif [ $COUNT -lt 1500 ]; then
        echo "✅ NOTE: 1/5 (< 1500)"
    else
        echo "❌ NOTE: 0/5 (>= 1500)"
    fi
else
    echo "❌ ÉCHOUÉ"
fi

echo ""
echo "=== TEST VERSION AVANCÉE (500 valeurs) ==="
ARG=$(shuf -i 0-10000 -n 500 | tr '\n' ' ')
RESULT=$(./push_swap $ARG | ./checker $ARG)
COUNT=$(./push_swap $ARG | wc -l)

echo "Résultat checker: $RESULT"
echo "Nombre d'instructions: $COUNT"

if [ "$RESULT" = "OK" ]; then
    if [ $COUNT -lt 5500 ]; then
        echo "✅ NOTE: 5/5 (< 5500)"
    elif [ $COUNT -lt 7000 ]; then
        echo "✅ NOTE: 4/5 (< 7000)"
    elif [ $COUNT -lt 8500 ]; then
        echo "✅ NOTE: 3/5 (< 8500)"
    elif [ $COUNT -lt 10000 ]; then
        echo "✅ NOTE: 2/5 (< 10000)"
    elif [ $COUNT -lt 11500 ]; then
        echo "✅ NOTE: 1/5 (< 11500)"
    else
        echo "❌ NOTE: 0/5 (>= 11500)"
    fi
else
    echo "❌ ÉCHOUÉ"
fi
