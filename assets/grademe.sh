#!/bin/bash

#step(file.rt, message, stop, extra)
step () {
  header $2
  echo "=== $1 ==="
  cat $1
  printf ""
  printf "====%${#1}s====\n" | tr " " "="
  debug "./miniRT $1 $4"
  if [ $3 = 1 ]
  then
    wait
  fi
}

debug () {
  (set -x; $1 2>&1) 2>&1
}

wait () {
  read -n 1 -s -r -p "Press any key to continue" 2>&1
}

header () {
  echo
  echo
  echo $1
}

make fclean >/dev/null
header "Make works"
debug "make --no-print-directory"
wait
header "Makefile does not relink"
debug "make --no-print-directory"
wait
header "Program name is 'miniRT'"
debug ls .
wait
#make fast >/dev/null

step scenes/grademe/empty.rt "Empty scene" 0
step scenes/grademe/small_window.rt "Small window" 0
step scenes/grademe/huge_window.rt "Huge window" 0
step scenes/grademe/objects.rt "Basic objects" 0
step scenes/grademe/lights.rt "Lights" 0
step scenes/errors/7.notrt "Error example 0" 0
step scenes/errors/8.rt "Error example 1" 0
step scenes/errors/18.rt "Error example 2" 0
step scenes/errors/42.rt "Error example 3" 1
rm -f frame.bmp && step "scenes/grademe/objects.rt" "BMP export" 0 "--save" && debug ls . && wait
step scenes/grademe/step3.rt "Step 3" 0
step scenes/grademe/step4.rt "Step 4" 0
step scenes/grademe/many_objs.rt "Multiple objects" 0
step scenes/grademe/cameras.rt "Cameras" 0
step scenes/grademe/shadow.rt "Simple shadow" 0
step scenes/grademe/shadows.rt "Complex shadows" 0
step scenes/grademe/bonus_objs.rt "BONUS - Objects" 0
step scenes/grademe/inside.rt "Inside" 0
step scenes/grademe/bonus_p_light.rt "BONUS - Parallel lights" 0
step scenes/grademe/bonus_disruptions.rt "BONUS - Disruptions" 0
step scenes/grademe/filter_none.rt "BONUS - Filter none" 0
step scenes/grademe/filter_red.rt "BONUS - Filter red" 0
step scenes/grademe/filter_green.rt "BONUS - Filter green" 0
step scenes/grademe/filter_blue.rt "BONUS - Filter blue" 0
step scenes/grademe/bonus_antialiasing.rt "BONUS - Antialiasing" 0
step scenes/grademe/bonus_specular.rt "BONUS - Specular reflection" 0
step scenes/grademe/bonus_mt.rt "BONUS - Multithreading" 0

echo
