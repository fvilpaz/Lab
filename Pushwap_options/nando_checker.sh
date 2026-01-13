#!/bin/bash

# Colores para que sea más bonito
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo "--- 🛠️  INICIANDO TEST DE FUEGO PUSH_SWAP ---"

# 1. PRUEBAS DE ERROR
echo -n "1. Test Duplicados: "
if [[ $(./push_swap 1 2 1 2>&1) == "Error" ]]; then echo -e "${GREEN}OK${NC}"; else echo -e "${RED}KO${NC}"; fi

echo -n "2. Test Letras: "
if [[ $(./push_swap 1 a 3 2>&1) == "Error" ]]; then echo -e "${GREEN}OK${NC}"; else echo -e "${RED}KO${NC}"; fi

echo -n "3. Test INT_MAX: "
if [[ $(./push_swap 2147483648 2>&1) == "Error" ]]; then echo -e "${GREEN}OK${NC}"; else echo -e "${RED}KO${NC}"; fi

# 2. PRUEBAS DE EFICIENCIA
echo -e "\n--- 📊 TEST DE EFICIENCIA ---"

echo -n "4. Test 3 números (Límite 3): "
MOVES=$(./push_swap 3 2 1 | wc -l)
if [ $MOVES -le 3 ]; then echo -e "${GREEN}$MOVES movs (OK)$NC"; else echo -e "${RED}$MOVES movs (KO)$NC"; fi

echo -n "5. Test 5 números (Límite 12): "
MOVES=$(./push_swap 5 1 4 2 3 | wc -l)
if [ $MOVES -le 12 ]; then echo -e "${GREEN}$MOVES movs (OK)$NC"; else echo -e "${RED}$MOVES movs (KO)$NC"; fi

echo -n "6. Test 100 números (Límite 1100 para 3pts): "
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' ')
MOVES=$(./push_swap $ARG | wc -l)
echo -e "${GREEN}$MOVES movs${NC}"

echo -n "7. Test 500 números (Radix promedio): "
ARG=$(shuf -i 0-2000 -n 500 | tr '\n' ' ')
MOVES=$(./push_swap $ARG | wc -l)
echo -e "${GREEN}$MOVES movs${NC}"

# 3. PRUEBA DE IDENTIDAD
echo -e "\n--- 😶 TEST DE IDENTIDAD (Nada en pantalla) ---"
echo -n "8. Test ya ordenado: "
OUT=$(./push_swap 1 2 3)
if [ -z "$OUT" ]; then echo -e "${GREEN}OK${NC}"; else echo -e "${RED}KO (Imprimió algo)$NC"; fi

echo -e "\n--- 🔥 ¡PRUEBAS COMPLETADAS! ---"
