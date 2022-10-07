#!/bin/zsh

echo "\e[35mCalculating output differences\e[0m"
mkdir diff 2> /dev/null
mkdir tmp 2> /dev/null
cat src/Main/main.cpp | sed -e "s/#if false/#if true/g" > tmp/main_true.cpp
cat src/Main/main.cpp | sed -e "s/#if true/#if false/g" > tmp/main_false.cpp

echo "\e[94mstl:\e[0m"
mv src/Main/main.cpp tmp/main_orig.cpp
mv tmp/main_true.cpp src/Main/main.cpp
make clean
make debug
echo "Executing..."
./bin/debug.out > diff/true.txt

echo "\e[94mft:\e[0m"
mv src/Main/main.cpp tmp/main_true.cpp
mv tmp/main_false.cpp src/Main/main.cpp
make clean
make debug
echo "Executing..."
./bin/debug.out > diff/false.txt
mv src/Main/main.cpp tmp/main_false.cpp

echo "- : std\n+ : ft" > diff/std_vs_ft.diff
diff -u diff/true.txt diff/false.txt >> diff/std_vs_ft.diff
rm diff/true.txt diff/false.txt
mv tmp/main_orig.cpp src/Main/main.cpp
rm -r tmp

if [ `cat diff/std_vs_ft.diff | wc -l` -eq 2 ]
then
	echo "\e[92mNo diff found\e[0m"
else
	echo "\e[91mDiffs found\e[0m, see diff/std_vs_ft.diff"
fi
